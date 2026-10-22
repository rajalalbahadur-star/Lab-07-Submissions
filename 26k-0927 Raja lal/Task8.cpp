/*A warehouse has 3 buildings, 4 shelves per building, and 5 slots per shelf, stored in
stock[3][4][5]. Each element is the number of items in that slot. Print the total stock per
building, find the single fullest shelf and report its building and shelf number, and list every slot
with fewer than 5 items as “needs restock” along with its [building][shelf][slot] position.*/
#include<stdio.h>
int main(){
	int stock[3][4][5];
	int total=0;
		for(int i=0;i<3;i++){
		printf("Building No:%d\n",i+1);
		for(int j=0;j<4;j++){
			printf("Shelf No:%d \n",j+1);
			for(int k=0;k<5;k++){
				scanf("%d",&stock[i][j][k]);
			}
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<5;k++){
				printf("%d ",stock[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	int total_stock=0;
	for(int i=0;i<3;i++){
		int building_total=0;
		for(int j=0;j<4;j++){
			for(int k=0;k<5;k++){
				building_total+=stock[i][j][k];
			}
			building_total+=total_stock;
			printf("Buildinng %d total:%d\n",i+1,building_total);
		}
	}
	int fullest_building=0;
	int fullest_shelf=0;
	int max_item=-1;
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			int shelf_sum=0;
			for(int k=0;k<5;k++){
				shelf_sum+=stock[i][j][k];
				
			}
			if(shelf_sum>max_item){
				max_item=shelf_sum;
				fullest_shelf=j;
				fullest_building=i;
			}
		}
	}
	printf("Building %d, Shelf %d (Total Items: %d)\n", fullest_building+1, fullest_shelf+1, max_item);
	printf("======Needs Restock======\n");
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<5;k++){
				if(stock[i][j][k]<5){
					printf("Building %d Shelf %d Slot %d Needs Restock (%d items)",i+1,j+1,k+1,stock[i][j][k]);
				}
			}
		}
	}

	return 0;
}
