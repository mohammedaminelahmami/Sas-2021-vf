#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	char nom[30];
	char prenom[30];
	char cin[30];
	float montant;
	float montretrait;
	float montdepot;
}acountType;
	
//-------------------------------------------------------------------------------------------

int main(int argc, char *argv[]) {
		// Declaration les variables : 
	int i,j,m,a,b,d,r;
	char cherCIN[30];
	int count = 0;
	int nbr = 0;
	int s;
	//----------------------------
	acountType user[100];
	acountType tmp;// ( nhtajo f  -Afichage )
	
// recherche par cin #1 (kataficher cin nta3 kamlin les comptes li de5elt.);
	void Fcin(){
		for(i = 0; i < count; i++){
			printf("\t%d)-  %s  %s \n",i+1 ,user[i].nom ,user[i].cin);
		}
	}	
// ascendant & descendant (hasab l printf wech mn lkbir lsghir aw l3aks);
	void ascendant_descendant(){
		// tri
			for(i = 0; i < count-1; i++){
				for(j = 0; j < count-i-1; j++){
					if(user[j].montant < user[j+1].montant){
		
						strcpy(tmp.nom,user[j].nom);//
						strcpy(tmp.prenom,user[j].prenom);//
						
						strcpy(tmp.cin,user[j].cin);
						tmp.montant = user[j].montant;
						
						strcpy(user[j].nom,user[j+1].nom);//
						strcpy(user[j].prenom,user[j+1].prenom);//
						
						strcpy(user[j].cin,user[j+1].cin);
						user[j].montant = user[j+1].montant;
						
						strcpy(user[j+1].nom,tmp.nom);//
						strcpy(user[j+1].prenom,tmp.prenom);//
						
						strcpy(user[j+1].cin,tmp.cin);
						user[j+1].montant = tmp.montant;
	                 
     					}
					}
				}
	}

//------------------------------------------------------------------------------------------------------
	printf("\t\t***|| Gestion Bancaire ||*** (SAS 2021) \n");
	
	Menu:
	printf("\n1)- Introduire un compte bancaire\n\n2)- Introduire plusieurs comptes bancaires\n\n3)- Operations \n\t1)- Retrait\n\t2)- Depot\n\n");
	printf("4)- Affichage\n\t1)- Par Ordre Ascendant\n\t2)- Par Ordre Descendant\n\t3)- Par Ordre Ascendant (les montants superieurs a un chiffre)\n\t4)- Par Ordre Descendant (les montants superieurs a un chiffre) \n");
	printf("5)- Recherche par CIN\n\n6)- Fidelisation\n\n7)- Quitter l'application\n -------------------------\n  ===>  ");
	scanf("%d", &a);
	
	switch(a){
		case 1:{
			//-Introduire un compte bancaire (CIN, Nom et Prénom, Montant)
			system("cls");
			printf("Introduire un compte bancaire \n");
				
				printf(")- Entrer CIN : ");
				scanf("%s", &user[count].cin);
		
				printf(")- Entrer le nom : ");
				scanf("%s", &user[count].nom);
				
				printf(")- Entrer le prenom : ");
				scanf("%s", &user[count].prenom);
				
				printf(")- Entrer Montant : ");
				scanf("%f", &user[count].montant);
				printf("\n");
				count++;
		
			system("cls");
			goto Menu;
			
			break;
		}
		case 2:{
//		-	Introduire plusieurs comptes bancaires (CIN, Nom et Prénom, Montant)
			
			system("cls");
			printf("Introduire plusieurs comptes bancaires \n");
			printf("Entrer nombre comptes que veut introduit : ");
			scanf("%d", &nbr);
			
			for(i = count; i < count+nbr; i++){
				
				printf(")- Entrer CIN : ");
				scanf("%s", &user[i].cin);
				
				printf(")- Entrer le nom : ");
				scanf("%s", &user[i].nom);
				
				printf(")- Entrer le prenom : ");
				scanf("%s", &user[i].prenom);
				
				printf(")- Entrer Montant : ");
				scanf("%f", &user[i].montant);
				printf("\n");
			
				}
			count += nbr; 
			
			system("cls");
			goto Menu;	
				
			break;
		}
		case 3:{
//			-	Opérations :
//					- Retrait (-) ; 
//					- Dépôt (+) ;
			printf("\n1)- Retrait\n2)- Depot\n ==> ");
			scanf("%d", &b);
			
			if(b == 1){
			//---------retrait :
				Fcin(); 
		
				printf("Entrer CIN :  ");
				scanf("%s", cherCIN);
		
				for(i = 0; i < count; i++){
					
					if(strcmp(user[i].cin, cherCIN) == 0){
						printf("Enter retrait :  ");
						scanf("%f", &user[i].montretrait);
						printf("-%.2f $", user[i].montretrait);
			
					user[i].montant = user[i].montant - user[i].montretrait;
					printf("\t#%s %s | CIN : %s | Montant ==> %.2f$\n", user[i].nom, user[i].prenom, user[i].cin, user[i].montant);
						break;
					}else if(i == count-1){
						printf("CIN INCORRECT\n");
					}
				}
			//---------
			printf("Tapez 1 pour Menu : ==> ");
			scanf("%d", &m);
			
			if(m == 1){
				system("cls");
				goto Menu;	
				}
				}else if(b == 2){
			//----------depot :
				Fcin(); 
		
				printf("Entrer CIN :  ");
				scanf("%s", cherCIN);
		
				for(i = 0; i < count; i++){
					
					if(strcmp(user[i].cin, cherCIN) == 0){
						printf("Enter depot :  ");
						scanf("%f", &user[i].montretrait);
						printf("+%.2f $", user[i].montretrait);
			
					user[i].montant = user[i].montant + user[i].montretrait;
					printf("\t#%s %s | CIN : %s | Montant ==> %.2f$\n", user[i].nom, user[i].prenom, user[i].cin, user[i].montant);
						break;
					}else if(i == count-1){
						printf("CIN INCORRECT\n");
					}
		
				}
			}
			//----------
					printf("Tapez 1 pour Menu : ==> ");
					scanf("%d", &m);
					if(m == 1){
						system("cls");
					goto Menu;
				}else{
					system("cls");
						goto Menu; 
				}
	}
		case 4:{
//			-	Affichage
//				-	Par Ordre Ascendant
//				-	Par Ordre Descendant
//				-   Par Asd mont <
//				-   Par Dsd mont >
			printf("\n1)- Ascendant & Descendant\n2)- Par Ordre Ascendant(...)   Par Ordre Descendant(...)\n ====>  ");
			scanf("%d", &r);

			switch(r){
				case 1:{
					printf("\n1)- Ascendant\n2)- Descendant\n ====>  ");
					scanf("%d", &d);
					
					if(d == 1){ 
						ascendant_descendant();
						for(i = count-1; i >= 0; i--){
							printf("\t#%s %s | CIN : %s | Montant ==> %.2f$\n", user[i].nom, user[i].prenom, user[i].cin, user[i].montant);
					}
						printf("Tapez 1 pour Menu : ==> ");
						scanf("%d", &m);
						
						if(m == 1){
							system("cls");
							goto Menu;}
					
					}else if(d == 2){
						ascendant_descendant();
						for(i = 0; i < count; i++){
							printf("\t#%s %s | CIN : %s | Montant ==> %.2f$\n", user[i].nom, user[i].prenom, user[i].cin, user[i].montant);
						
					}
						printf("Tapez 1 pour Menu : ==> ");
						scanf("%d", &m);
						
						if(m == 1){
							system("cls");
							goto Menu;}
				}
					break;
				}
				case 2:{
					printf("\n1)- Par Ordre Ascendant(x >)\n2)- Par Ordre Descendant(x <)\n ====>  ");
					scanf("%d", &d);
					
					switch(d){
						case 1:{
							printf("\nEntre nombre : ");
							scanf("%d", &s);
							
							ascendant_descendant();
								for(i = 0; i < count; i++){
									if(s < user[i].montant){
										printf("\t#%s %s | CIN : %s | Montant ==> %.2f$\n", user[i].nom, user[i].prenom, user[i].cin, user[i].montant);
									}
								}
							printf("Tapez 1 pour Menu : ==> ");
							scanf("%d", &m);
						
							if(m == 1){
								system("cls");
								goto Menu;}
							break;
						}
						case 2:{ 
							printf("\nEntre nombre : ");
							scanf("%d", &s);
							
							ascendant_descendant();
								for(i = count-1; i >= 0; i--){
									if(s > user[i].montant){
										printf("\t#%s %s | CIN : %s | Montant ==> %.2f$\n", user[i].nom, user[i].prenom, user[i].cin, user[i].montant);
									}
								}
							printf("Tapez 1 pour Menu : ==> ");
							scanf("%d", &m);
						
							if(m == 1){
								system("cls");
								goto Menu;}
							break;
							}
						}
				}
			}
			break;
	}
		case 5:{
//		-	Recherche par CIN 
			
			system("cls");
			printf("\t\tRecherche par CIN\n");
			Fcin();  // function : recherche par cin #1 (kataficher cin nta3 kamlin les comptes li de5elt. ); 
			printf("Entrer CIN :  ");
			scanf("%s", cherCIN);
			
			for(i = 0; i < count; i++){
			
				if(strcmp(user[i].cin, cherCIN) == 0){
					printf("\t#%s %s | CIN : %s | Montant ==> %.2f$\n", user[i].nom, user[i].prenom, user[i].cin, user[i].montant);
					break;
				}else if(i == count-1){
					printf("CIN INCORRECT\n");
				}
			}
			printf("Tapez 1 pour Menu : ==> ");
			scanf("%d", &m);
			if(m == 1){
				system("cls");
				goto Menu;
			} 
			break;
		}
		case 6:{
//			-	Fidélisation Ajouter 1.3% aux comptes ayant les 3 premiers montants supérieurs

			ascendant_descendant();
			for(i = 0; i < 3; i++){
				user[i].montant = user[i].montant + (user[i].montant)*0.013;
			}

			printf("+1.3 %% aux comptes ayant les 3 premiers montants superieurs\n");
			//---------
			printf("Tapez 1 pour Menu : ==> ");
			scanf("%d", &m);
						
			if(m == 1){
				system("cls");
				goto Menu;}	
			break;
		}
		case 7:{
//			-	Quitter l'application
		}
		default :{
			system("cls");
			goto Menu;
			break;
		}
	}
return 0;
}
