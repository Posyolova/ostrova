#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char *name;
	char *opens;
	char *closes;
	struct island *next;
}island;

void display(island *start){
	for (island *i = start; i != NULL; i = i->next){
		printf("Имя: %s\topen: %s - %s\n", i->name, i->opens, i->closes);
	}
}
/*
void release(island *start){
	island *i = start;
	island *next = NULL;
	for(; i != NULL; i = next){
		next = i->next;
		free(i->name);
		free(i);
	}
}*/

island * create(char* name){
	island* i = malloc(sizeof(island));
	i->name = strdup(name);
	i->opens = "09:00";
	i->closes = "17:00";
	i->next = NULL;
	return i;
}
int main(){
	/*island amity = {"Остров Дружбы", "09:00", "17:00", NULL};
	island craggy = {"Остров Скалистый", "09:00", "17:00", NULL};
	island isla_nublar = {"Остров Туманный", "09:00", "17:00", NULL};
	island shutter = {"Остров Проклятых", "09:00", "17:00", NULL};
	island skull = {"Остров Черепа", "09:00", "17:00", NULL};

	amity.next = &craggy;
	craggy.next = &isla_nublar;
	isla_nublar.next = &skull;
	skull.next = &shutter;*/
	
	island *start = NULL;
	island *i = NULL;
	island *next = NULL;
	char name[80];
	for(; fgets(name, 80, stdin) != NULL; i =next){
		next = create(name);
		if (start == NULL)
			start = next;
		if(i != NULL)
			i->next = next;
	}

	display(start);
	/*release(start);*/
	return 0;
}
