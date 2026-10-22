/*A cinema hall has 5 rows and 8 seats per row. Seats are stored in seats[5][8] (0 = empty, 1 =
booked). Read the booking status of every seat, then print the seating map using . for empty and
X for booked. Also report how many seats are free in each row and in total.*/
#include<stdio.h>
int main(){
	int seats[5][8],free=0,booked=0;
	int i,j;
	int free_row=0;
	printf("======Cinema Seat Booking System======\n");
	printf("Press 1 to book a seat or Press 0 to not book:\n");
	for(i=0;i<5;i++){
		for(j=0;j<8;j++){
			scanf("%d",&seats[i][j]);
		}	
	}
	for( i=0;i<5;i++){
		for( j=0;j<8;j++){
			if(seats[i][j]==1){
				printf("X ");
				booked++;
			}else if(seats[i][j]==0){ 
				printf(". ");
				free++;
				free_row++;}
		}
		printf("\n");

	}
	printf(" |Seats Free in Row %d: %d\n", i + 1, free_row);
	printf("The total booked Seats are:%d\n",booked);
	printf("The Avilable Seats are:%d",free);
	
	return 0;
}
