#include <stdio.h>
void printAge(int);
void printHeight(double);
int main(){
	char name[20] = "채채";
	int age = 23;
	double height = 167.8;

	printf("성명 : %s\n", name);
	printAge(age);
	printHeight(height);

	return 0;
}
void printAge(int age){
	printf("나이 : %d\n", age);
	return;
}
void printHeight(double height){
	printf("키 : %lf\n", height);
	return;
}
