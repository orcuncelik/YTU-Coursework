#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 3
#define L 4

//Struct Tan�m�.
typedef struct node{
	char *val;			//String de�erini tutar.
	int counter;		//Sayac de�erini tutar.
	struct node *next;
	struct node *prev;
}node;
//Fonksiyon prototipleri.
node *newNode();	//Yeni node i�in dinamik yer a�ar.
node *find(char*);	//Aran�lan de�eri bulur
void popEnd();	   //En sondaki node'u siler.
int size();		  // Stack boyutunu d�nd�r�r.
void list();	  // Listeleme g�revi yapar.
void push(char*); // Stack'e pushlar.

node *head; //global de�i�ken tan�mlamas�.

node *newNode(){ //Yeni node i�in dinamik yer a��p, de�eri geri d�nd�r�r.
	node *tmp = (node*)calloc(1,sizeof(node));
	tmp -> next = NULL;
	tmp -> prev = NULL;
	return tmp;
}
node *find(char *data){ //Verilen de�erin stackte olup olmad���n� g�sterir.
	node *tmp = head;
	while(tmp){
		if(strcmp((tmp->val),data) == 0){ //E�er 0 ise de�er bulunup geri d�nd�r�l�r.
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

void popEnd(){ //Sondan ��karma i�lemi yap�l�r.
	node *tmp = head;
	node *prv;
	while(tmp->next != NULL){
		tmp	= tmp -> next;
	}
	tmp -> prev -> next = NULL;
	free(tmp); //De�er freelenir.
}

int size(){ //Boyutu d�nd�r�r.
	node *tmp = head;
	int n = 0;
	while(tmp){
		n++;
		tmp = tmp->next;
	}
	return n;
}

void list(){ //Listeleme i�i yap�l�r.
	node *tmp = head;
	while(tmp!=NULL){
		printf("%s\t%d\t",tmp->val, tmp->counter);
		tmp = tmp -> next;
	}
	printf("\n");

}


void push(char *data){
	node *tmp = newNode(); //tmp i�in dinamik yer a��l�r.
	node *tmp2;

	if(head == NULL){ //Eger head daha �nce tan�mlanmad��ysa.
		tmp->val = data;
		tmp->counter = 1;
		head = tmp;
	}else{
		if(find(data)==NULL){ //Eger head daha �nce varsa ve aktar�lan veri yoksa.
			head->prev = tmp;
			tmp -> val = data;
			tmp ->next = head;
			tmp -> counter = 1;
			head = tmp;
			if(size()>L) //Boyut e�er a��ld�ysa sondaki de�er silinir.
				popEnd();				
		}else{ //Eger veri bulunduysa, counter� artt�r�l�r.
			tmp2 = find(data);
			tmp2->counter ++;
			if(tmp2->counter > T){ //EGER Limit a��ld�ysa
				node *nxt, *prv;
				nxt = tmp2 ->next;
				prv = tmp2 ->prev;
				if(nxt)				//Null hatas� i�in
					nxt -> prev = prv;
				if(prv)				//Null hatas� i�in
					prv -> next = nxt;
				head -> prev = tmp2;
				tmp2 -> next = head;
				head = tmp2;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	push("A");
	list();
	push("B");
	list();
	push("A");
	list();
	push("AA");
	list();
	push("BBB");
	list();
	push("B");
	list();
	push("A");
	list();
	push("AB");
	list();
	push("A");
	list();
	push("B");
	list();
	push("A");
	list();
	push("BB");
	list();


	return 0;  
}
