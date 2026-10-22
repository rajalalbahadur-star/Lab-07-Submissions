/* A university has 3 departments, 4 students per department, and 5 subjects each, stored in
marks[3][4][5]. Print every student’s average, the topper of each department, and the
department with the highest overall average. Mark any student with a subject below 40 as
“FAIL”.*/
#include<stdio.h>
int main(){
	int marks[3][4][5];
	float dept_total[3]={0};
	float high_dept_avg=0;
	int best_dept=0;
	for(int i=0;i<3;i++){
		printf("Marks of Department:%d\n",i+1);
		for(int j=0;j<4;j++){
			printf("Student %d Marks Of 5 Subjects:\n",j+1);
			for(int k=0;k<5;k++){
				scanf("%d",&marks[i][j][k]);
			}
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<5;k++){
				printf("%d ",marks[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	for(int i=0;i<3;i++){
		printf("Department %d Results.\n\n",i+1);
		float high_stu_avg=-1.0;
		int dept_topper=0;
		for(int j=0;j<4;j++){
			int total=0;
			int failed=0;
			for(int k=0;k<5;k++){
				total=total+marks[i][j][k];
				if(marks[i][j][k]<40){
					failed=1;
				}
			}
			float stu_avg=total/5.0;
			dept_total[i]=dept_total[i]+total;
			if(failed){
				printf("Student %d with Avg=%.2f [FAILL]\n",j+1,stu_avg);
			}else{
				printf("Student %d with Avg=%.2f [PASS!!]\n",j+1,stu_avg);
			}
			if(stu_avg>high_stu_avg){
				high_stu_avg=stu_avg;
				dept_topper=j+1;
			}
		}
		printf("\nTopper of Department %d is Student %d Having Average:%.2f\n",i+1,dept_topper,high_stu_avg);
		float current_dept_avg=dept_total[i]/20.0;
		if (current_dept_avg > high_dept_avg) {
            high_dept_avg = current_dept_avg;
            best_dept = i + 1;
        }
    }
    printf("Overall Best Department: Department %d (Average: %.2f)\n", best_dept, high_dept_avg);
	return 0;
}
