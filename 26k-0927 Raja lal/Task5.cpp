/*A hotel has 4 floors with 6 rooms each, stored in rooms[4][6]. Read 1 for occupied and 0 for
vacant. Find the floor with the most vacancies. Then check whether any floor has 3 or more
consecutive vacant rooms, and print the floor and the starting room number.*/
#include<stdio.h>
int main(){
	int rooms[4][6],i,j;
	int vacancy=0,booked=0;
	int floor_vac[4]={0};
	printf("======HOTEL SYSTEMA======\n");
	printf("Press 1 to book room \nPress 0 to not book a room\n");
	for(i=0;i<4;i++){
		printf("Room booking on %d floor:\n",i+1);
		for(j=0;j<6;j++){
			scanf("%d",&rooms[i][j]);
		}
	}
	int max_vac=-1,best_floor=0;
	for(i=0;i<4;i++){
		for(j=0;j<6;j++){
			if(rooms[i][j]==1){
				booked++;
			}else if(rooms[i][j]==0){
				floor_vac[i]++;
			}
			if(floor_vac[i]>best_floor){
				max_vac=floor_vac[i];
				best_floor=i+1;
			}
		}
	}
	printf("\n--- RESULTS ---\n");
	printf("The total No. of rooms Booked are: %d\n",booked);
    printf("Floor with the most vacancies: Floor %d (with %d vacant rooms)\n", best_floor, max_vac);
    printf("\nChecking for 3+ consecutive vacant rooms:\n");
    int found_consecutive = 0;
    
    for(i = 0; i < 4; i++) {
        int consecutive_count = 0;
        int start_room = -1;
        
        for(j = 0; j < 6; j++) {
            if(rooms[i][j] == 0) {
                if(consecutive_count == 0) {
                    start_room = j + 1;
                }
                consecutive_count++;
            } else {
                consecutive_count = 0;
            }            
			if(consecutive_count >= 3) {
                printf("Floor %d has %d consecutive vacant rooms starting from Room %d\n", 
                       i + 1, consecutive_count, start_room);
                found_consecutive = 1;
            }
        }
    }	
	return 0;
}
