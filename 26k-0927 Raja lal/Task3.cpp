/*A weather station records the temperature at 4 times of day (morning, noon, evening, night) for 7
days in temp[7][4]. Find the hottest and coldest readings with their day and time slot, and list
the days where the noon temperature was above the weekly noon average.*/
#include <stdio.h>

int main() {
    int temp[7][4], i, j, noon_total = 0;
    int hot, cold; // Declare them first
    char *time[4] = {"Morning", "Noon", "Evening", "Night"};
    int max_day = 0, max_time = 0, min_day = 0, min_time = 0;
    float noon_avg;
    for(i = 0; i < 7; i++) {
    	printf("Enter values of temp for day:%d\n",i+1);
        for(j = 0; j < 4; j++) {
            scanf("%d", &temp[i][j]);
        }
    }
      hot = temp[0][0];
    cold = temp[0][0];
      for(i = 0; i < 7; i++) {
        noon_total = noon_total + temp[i][1];
        for(j = 0; j < 4; j++) {
            if(temp[i][j] > hot) {
                hot = temp[i][j];
                max_day = i;
                max_time = j;
            }
            if(temp[i][j] < cold) {
                cold = temp[i][j];
                min_day = i;
                min_time = j;
            }
        }
    } 
    noon_avg = noon_total / 7.0;
     printf("\n================ RESULTS ================\n");
    printf("Hottest Reading : %d (Day %d, %c)\n", hot, max_day + 1, time[max_time]);
    printf("Coldest Reading : %d (Day %d, %c)\n", cold, min_day + 1, time[min_time]);
    printf("Weekly Noon Avg : %.2f\n", noon_avg);   
    printf("\nDays where Noon Temperature was above Weekly Noon Average:\n");
    int found = 0;
    for(i = 0; i < 7; i++) {
        if(temp[i][1] > noon_avg) {
            printf(" - Day %d (Noon Temp: %d)\n", i + 1, temp[i][1]);
            found = 1;
        }
    }   
    if(!found) {
        printf(" - None\n");
    }   
    return 0;
}

