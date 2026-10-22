/*A teacher has 6 students and 4 subjects. Read the marks into marks[6][4]. Print each student’s
total and average, each subject’s class average, and the name of the subject (by number) where
the class performed best.*/
#include<stdio.h>
int main(){
	int marks[6][4],i,j;
	int std_total[6]={0};
	int sub_total[4]={0};
	float std_avg[6]={0};
	float sub_avg[4]={0};
	
	for(i=0;i<6;i++){
		printf("Enter 4 Subjects marks of student%d:\n",i+1);
		for(j=0;j<4;j++){
			scanf("%d", &marks[i][j]);
			std_total[i]=std_total[i]+marks[i][j];
			sub_total[j]=sub_total[j]+marks[i][j];
		}
	}
	for(i=0;i<6;i++){
		std_avg[i]=std_total[i]/4.0;
	}
	int best_sub=0;
	for(j=0;j<4;j++){
		sub_avg[j]=sub_total[j]/6.0;
		if(sub_avg[j]>sub_avg[best_sub]){
			best_sub=j;
		}
	}
	printf("\n======-Results-======\n");
	for(i=0;i<6;i++){
		printf("Student %d ->Total:%d | Average:%.2f\n",i+1,std_total[i],std_avg[i]);
	}
	for(j=0;j<4;j++){
		printf("Subject Average for Subject %d is:%.2f\n",j+1,sub_avg[j]);
	}
	printf("Best perfoming subject is %d and Its average is:%.2f",best_sub+1,sub_avg[best_sub]);
	return 0;
}
