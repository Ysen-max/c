#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void mycolor(short x);
void xg (char *e);
char change_2[100],change_3[100];


void daochu (char b[]){//------------------导出
	FILE *p;
	char a[30],c;
	printf ("请输入您需要导出到哪个文档\n");
	scanf ("%s",a);
	c=getchar();
	p=fopen(a,"w+");
	fputs(b,p);
	fclose(p);
	printf ("导出完毕请查看%s\n",a);
}

int daoru(char a[]){//-------------------导入
	FILE *p;
	char nn[30],c;
	char aa[1000];
	printf ("请输入您需要导入的文档\n");
	scanf("%s",nn);
	c=getchar();
	p=fopen(nn,"r");
	if(p!=NULL){
	fgets(aa,1000,p);
	}
	else{
	mycolor(12);
	printf("您输入的地址错误，请从新输入...\n");
	mycolor(11);
	return -1;
	}
	fclose(p);
	strcpy(a,aa);

	return 0;
}

void xxg (char p[],char *e)//-----------------------消去多余
{
	int a=0,b=0;
	for (a=0;p[a]!='\0';a++)
	{
		if (p[a]!=' ')//--------------------------------判断出来不是空格的赋值，非空格的值传给e数组
		{
	    	e[b]=p[a];
			b++;
		}
		else if (b-1>=0&&e[b-1]!=' ')//-----------------不是空格，在判断我们要存人的那个前面那个有没有空格
		{
				e[b]=p[a];
			    b++;
		}
	}
	e[b-1]='\0';//--------------------------------------去掉最后一个空格（前面那个残留的）和回车符号位'\0'
	if (e[b-2]==' ')
		e[b-2]='\0';
	printf("这是给去掉多余的句子：\n");
	printf("%s\n",e);
}

void mycolor(short x)	//自定义函根据参数改变颜色 
{
    if(x>=0 && x<=15)//参数在0-15的范围颜色
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色 
    else//默认的颜色白色
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}



void jishu(char a[])//-----------------------------------(2)统计个数
{
	int ii, i=0,j=0,k=0,e=0,n=0,m=0,l=0,add=1,kkk=0;
	int c[1000],b[1000];
	
	for (i=0;a[i]!='\0';i++)
	{
		if (i==0||a[i-1]==' '&&a[i]!=' ')//----------------存单词首字母的脚标
		{
			c[n]=i;
			n++;
		}
		if (a[i+1]==' '&&a[i]!=' '||a[i+1]=='\0')//--------尾字母的脚标
		{
			b[m]=i;
			
		
		m++;
		}
	}
	for (ii=0;ii<m;ii++){//-------------------------------for循环的使用实现各个单词的导入，为后面的比较提供基础
		if (c[ii]==-1)
			continue;
		for (l=0;l<100;l++)//-----------------------------清空1
			change_2[l]='\0';
		for (e=0,j=c[ii];j<=b[ii];j++,e++)//--------------当前单词的存入
		{
			change_2[e]=a[j];
		}
		for (k=ii+1;k<m;k++)//----------------------------后面单词的存入
		{
			e=0;
			for (j=c[k];j<=b[k];j++)
			{
				change_3[e]=a[j];
				e++;
			}
			if (strcmp(change_2,change_3)==0)//-----------调用库函数比较字符串是否相等
			{
				add++;//计数器
				b[k]=c[k]=-1;//清空脚标
			}
			for (l=0;l<100;l++)//-------------------------清空2
				change_3[l]='\0';
		}
		printf("%s:%d个\n",change_2,add);
		add=1;
		
	}

}

void ChangeText(char a[]){//--------------------------（3）替换
	int c[1000],b[1000],n=0,m=0,i,k=0,j;
	char OneChar[100][1000]={{'\0'},{'\0 '}},TwoChar[100]={'\0'};//---------------------------------初始化，TWo来存要替换的值，md输入进来替换的
	char md[100]={'\0'},cc='\0';
	printf ("\n请输入您需要被修改的单词：\n");
			scanf("%s",TwoChar);
			cc=getchar();
	printf ("\n请输入您要修改的单词：\n");
			scanf("%s",md);
			cc=getchar();
	for (i=0;a[i]!='\0';i++)
	{
		if (i==0||a[i-1]==' '&&a[i]!=' ')//-------------------------------------存前坐标
		{
			c[n]=i;	
		
			n++;
		}
		if (a[i+1]==' '&&a[i]!=' '||a[i+1]=='\0')//-----------------------------存后面坐标
		{
			b[m]=i;
			m++;
		}
		
	}

	for(i=0;i<n;i++){
		k=0;
		for (j=c[i];j<=b[i];j++){//--------------------------------------------for循环遍历存进数组里面
			OneChar[i][k]=a[j];
			k++;
		}
	}
	for (i=0;i<n;i++){

		if(strcmp(TwoChar,OneChar[i])==0){//-----------------------------------比较是否相等，并复制新的
			strcpy(OneChar[i],md);
			
		}
	}
	for(i=1;i<n;i++){//-------------------------------------------------------调用库函数，链接成串
		strcat(OneChar[0]," ");
		strcat(OneChar[0],OneChar[i]);
	}
	strcpy(a,OneChar[0]);//---------------------------------------复制到change串里面
	printf ("\n这是您替换后的句子：\n%s\n",a);//------------------------------------------输出
}
void biejing(){
	printf("|----------------------------------------------------------------------------------------------------------------------|\n");
	printf("|                                            欢迎使用小句子调整修饰程序                                                |\n");
	mycolor(4);
	printf("|注意：输出对应数字执行操作                                                                                            |\n");
	mycolor(11);
	printf("|                                           （1） 开始程序,并去掉多余                                                  |\n");
	printf("|                                           （2） 统计个数                                                             |\n");
	printf("|                                           （3） 查找替换，并输出                                                     |\n");
	printf("|                                           （4） 退出程序                                                             |\n");
	printf("|                                           （5） 导入                                                                 |\n");
	printf("|                                           （6） 导出                                                                 |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("请开始你的表演：...\n");
}
int main ()
{
	char change[1000]={'\0'},shuju[1000]={'\0'};
	int tw=0,num2=0,num4;
	char a,num='0';
	mycolor(11);
	biejing();
	while(1){
	num=getchar();
	a=getchar();
	system("cls");
		num2=0;
		num4=-1;
	if(num>='0'&&num<='6'){
		if (num=='4'){
			mycolor(7);
			printf("\n\n\n\n|---------------------------------------谢谢您的使用再见 --------------------------------------------------------------|\n");
			mycolor(11);
			printf("|----------------------------------------------------------------------------------------------------------------------|\n");
			break;
		}
		if(num=='1'){
			printf("您已开启程序请输入你所要修饰的值：\n");
		
			tw=1;
			xg(change);
			
		printf("------------请继续您的操作:(1)开始新程序，(2)查个数，(3)修改替换，(4)退出,(5)导入，(6)导出--------------------\n"); 
		}else if (tw==0&&num!='5'){
			mycolor(12);
			printf("您还没选择开始，输入错误，请从新选这序号“1”启动该程序或者“5”，谢谢:...\n");
			mycolor(11);
		}
		else if(num=='2'&&tw==1){
			printf("\n这是您这个句子单词个数的统计：\n");
			jishu(change);
			
			printf("------------请继续您的操作:(1)开始新程序，(2)查个数，(3)修改替换，(4)退出,(5)导入，(6)导出--------------------\n"); 
		}else if (num=='3'&&tw==1){
			printf("%s",change);
			ChangeText(change);
	
			printf("------------请继续您的操作:(1)开始新程序，(2)查个数，(3)修改替换，(4)退出,(5)导入，(6)导出--------------------\n"); 
		}else if (num=='5'){
			while(1){
				num4=daoru(shuju);
				if (num4==0)
					break;
				}
			xxg(shuju,change);
			tw=1;
	
			printf("------------请继续您的操作:(1)开始新程序，(2)查个数，(3)修改替换，(4)退出,(5)导入，(6)导出--------------------\n"); 
			
		}else if (num=='6'){
			daochu(change);	
	
			printf("------------请继续您的操作:(1)开始新程序，(2)查个数，(3)修改替换，(4)退出,(5)导入，(6)导出--------------------\n"); 
		}
	}else {
				mycolor(12);
				printf("对不起，您输出的序号无效，请从新输入：....\n");
				mycolor(11);
		}
	}

	return 0;
}
void xg (char *e)
{
	int n=0,a,b=0;
	char p[1000];
	while (	scanf ("%c",&p[n])){
		if(p[n]=='\n')
			break;
		n++;
	}
	for (a=0;a<=n;a++)
	{
		if (p[a]!=' ')
		{
	    	e[b]=p[a];
			b++;
		}
		else if (b-1>=0&&e[b-1]!=' ')
		{
				e[b]=p[a];
			    b++;
		}
	}
	e[b-1]='\0';
	if (e[b-2]==' ')
		e[b-2]='\0';
	printf("这是给去掉多余的句子：\n");
	printf("%s\n",e);
}