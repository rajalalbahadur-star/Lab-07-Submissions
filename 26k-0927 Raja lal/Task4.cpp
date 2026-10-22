/*A shop sells 5 products across 3 branches. Read monthly sales into sales[3][5]. Print the total
sales per branch, total sales per product, the best-selling branch, and the product with the lowest
sales overall.*/
#include<stdio.h>
int main(){
	int sales[3][5];
	int branch_total[3]={0},product_total[5]={0};
	int i,j;
	printf("====Welcome to shop.====\n");
	for(i=0;i<3;i++){
		printf("Sales on Branch %d:\n",i+1);
		for(j=0;j<5;j++){
			scanf("%d",&sales[i][j]);
			branch_total[i]=branch_total[i]+sales[i][j];
			product_total[j]=product_total[j]+sales[i][j];
		}
	}
	int best_branch=0;
	for(i=0;i<3;i++){
		if(branch_total[i]>branch_total[best_branch]){
			best_branch=i+1;
		}
	}
	int lowest_sales=0;
	for(j=0;j<5;j++){
		if(product_total[j]<product_total[lowest_sales]){
			lowest_sales=j+1;
		}
	}
	printf("\n--- Total Sales Per Branch ---\n");
    for(i = 0; i < 3; i++) {
        printf("Branch %d: %d\n", i + 1, branch_total[i]);
    }
    printf("\n--- Total Sales Per Product ---\n");
    for(j = 0; j < 5; j++) {
        printf("Product %d: %d\n", j + 1, product_total[j]);
    }
    printf("\n-----------------------------------------\n");
    printf("Best-selling Branch: Branch %d (Total: %d)\n", best_branch + 1, branch_total[best_branch]);
    printf("Lowest-selling Product: Product %d (Total: %d)\n", lowest_sales + 1, product_total[lowest_sales]);
	
	return 0;
}
