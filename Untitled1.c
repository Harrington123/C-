#include <stdio.h>
#include <string.h>

struct Stu{
	char name[10];
	int age[10];
};
//比较函数 
int sort_int(int*x,int*y){
	return *x-*y;
}
int sort_float(float*x,float*y){
	if(*x>*y)return 1;
	else if(*x<*y)return -1;
	else return 0;
}
int sort_Stu_name(struct Stu*x,struct Stu*y){
	return strcmp(x->name,y->name);
}
int sort_Stu_age(struct Stu*x,struct Stu*y){
	return *(x->age) - *(y->age);
}
//实例演示 
void text1(){
	int i;
	int a[]={1,3,5,7,9,2,4,6,8};
	int size=sizeof(a)/sizeof(a[0]);
	my_sort(a,size,sizeof(a[0]),sort_int);
	for(i=0;i<size;i++)printf("%d\t",a[i]);
	printf("\n");
}
void text2(){
	int i;
	float a[]={1,3,5,7,9,2,4,6,8};
	int size=sizeof(a)/sizeof(a[0]);
	my_sort(a,size,sizeof(a[0]),sort_float);
	for(i=0;i<size;i++)printf("%.1f\t",a[i]);
	printf("\n");
}
void text3(){
	int i;
	struct Stu a[]={{"A 23",23},{"C 21",21},{"B 25",25}};
	int size=sizeof(a)/sizeof(a[0]);
	my_sort(a,size,sizeof(a[0]),sort_Stu_name);
	for(i=0;i<size;i++)printf("%s\t",a[i]);
	printf("\n");
}
void text4(){
	int i;
	struct Stu a[]={{"A 23",23},{"C 21",21},{"B 25",25}};
	int size=sizeof(a)/sizeof(a[0]);
	my_sort(a,size,sizeof(a[0]),sort_Stu_age);
	for(i=0;i<size;i++)printf("%s\t",a[i]);
	printf("\n");
}
//函数实现 
void change(char*x,char*y,int m){
	int i=0;
	for(;i<m;i++){
		char t=*x;
		*x=*y;
		*y=t;
		x++;
		y++;
	}
}
void my_sort(void*bass,int size,int width,int (*cmp)(void*x,void*y)){
	int i,j;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-1-i;j++){
			if(cmp((char*)bass+j*width,(char*)bass+(j+1)*width)>0){		//比较函数 
				change((char*)bass+j*width,(char*)bass+(j+1)*width,width);		//交换函数 
			}
		}
	}
}


int main(){
	text1();
	text2();
	text3();
	text4();
	return 0;
} 
