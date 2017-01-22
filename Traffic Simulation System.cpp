#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define MAX_VERTEX_NUM 18
#define NULL 0
#define MAX_ARC_SIZE 100
#define MAX_ROUTE_NUM 5
#define False 0
#define True 1
#define INFINITY 10000
typedef struct  
{
	int number;//Number of Train
	float expenditure;//Expense of Train 
    int begintime[2];
    int arrivetime[2];
}Vehide; //Train 

typedef struct
{
	Vehide stata[MAX_ROUTE_NUM];
    int last;
}infolist;//Array of Train 

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
    infolist info;
}ArcNode;//Edge Node 

typedef struct VNode
{
	char cityname[10];
	ArcNode *planefirstarc,*trainfirstarc;
}VNode,AdjList[MAX_VERTEX_NUM];//Structure of City 

typedef struct
{
	AdjList vertices;
    int vexnum,planearcnum,trainarcnum;
}ALGraph;//Graph 

typedef struct Node
{
	int adjvex;//Adjacent Points 
    int route;//Line 
    struct Node *next; 
}Node;

typedef struct QNode
{
	int adjvex;//Adjacent Points 
    struct QNode *next;
}QNode;//Points in Graph 

typedef struct
{
	QNode *front;//Front of Queue 
    QNode *rear;//Rear of Queue
}LinkQueue;//Queue 

typedef struct TimeNode
{
	int adjvex;//Adjacent Points
    int route;//Line 
    int begintime[2];
    int arrivetime[2]; 
    struct TimeNode *child[MAX_ROUTE_NUM];
}TimeNode,*TimeTree;//Time Tree 
 
struct arc
{
	int co;
    char vt[10];//Begin Point 
    char vh[10];//End Piint 
    int bt[2];
    int at[2];
    float mo;
}a[MAX_ARC_SIZE];//Edge 
char city[MAX_VERTEX_NUM][10];
int TTime[2];
int time[2];
int time1[2];
int time2[2];
int c[MAX_VERTEX_NUM];
int d[MAX_VERTEX_NUM];
void Administer(ALGraph *G);
void cityedit(ALGraph *G);
void CopyTimeTree(TimeTree p,TimeTree q);
void createcityfile();
void CreateGraph(ALGraph *G);
void createplanefile();
void CreateTimeTree(TimeTree p,int i,int j,LinkQueue *Q,infolist (*arcs)[MAX_VERTEX_NUM]);
void createtrainfile();
int DeleteplaneArc(ALGraph *G);
void DeleteQueue(LinkQueue *Q,int *x);
int DeletetrainArc(ALGraph *G);
void DeleteVertex(ALGraph *G);
void DemandDispose(int n,ALGraph G);
void DestoryTimeTree(TimeTree p);
void EnterplaneArc(ALGraph *G);
void EnterQueue(LinkQueue *Q,int x);
void EntertrainArc(ALGraph *G);
void EnterVertex(ALGraph *G);
void ExpenditureDispose(int k,infolist (*arcs)[MAX_VERTEX_NUM],ALGraph G,int v0,int v1,float *M,int *final);
void flightedit(ALGraph *G);
void initgraph(ALGraph *G);
void InitQueue(LinkQueue *Q);
int IsEmpty(LinkQueue *Q);
int LocateVertex(ALGraph *G,char *v);
void MinExpenditure(infolist arcs,float *expenditure,int *route);
void MinTime(infolist arcs,int *time,int *route);
void PrintGraph(ALGraph *G);
int save(ALGraph *G);
void TimeDispose(int k,infolist (*arcs)[MAX_VERTEX_NUM],ALGraph G,int v0,int v1,int (*T)[2],int *final);
void TimeTreeDispose(Node *head,infolist (*arcs)[MAX_VERTEX_NUM]);
void trainedit(ALGraph *G);
void TransferDispose(int k,infolist (*arcs)[MAX_VERTEX_NUM],ALGraph G,int v0,int v1);
void UserDemand(ALGraph G);
void VisitTimeTree(TimeTree p);

int main() 
{ALGraph G;
 int i;

 printf("                    **Welcome to Traffic Simulation System****");
 printf("\n");
   printf("\n");
    printf("\n");
 printf("                    ***************Jinshuo Bai****************\n");
 printf("\n");
  printf("\n");
   printf("\n");
    printf("\n");
     printf("\n");
 printf("                              Press Any Key to Continue");
 getchar();
 system("cls");
 printf("\n\n\n\n\n\n\n                     Choose one to Continue:\n");
 printf("                     *************************************\n");
 printf("                     **          1=Administrate        **\n");
 printf("                     **          2=Inquiry             **\n");
 printf("                     **          3=Show                **\n");
 printf("                     **          4=Exit                 **\n");
 printf("                     *************************************\n");
 printf("                                   Choose?");
 scanf("%d",&i);
 getchar();
 while(i!=4)
 {
	 switch(i)
	 {
	 case 1:Administer(&G);//Administrator Interface
		 break;
	 case 2:UserDemand(G);//User Interface 
		 break;
	 case 3:PrintGraph(&G);//Show the traffic system 
		 break;
	 }
	 system("cls"); 
	 printf("\n\n\n\n\n\n\n                     Choose one to Continue:\n");
	 printf("                     *************************************\n");
	 printf("                     **          1=Administrate        **\n");
	 printf("                     **          2=Inquiry             **\n");
	 printf("                     **          3=Show                **\n");
	 printf("                     **          4=Exit                 **\n");
	 printf("                     *************************************\n");
	 printf("                                   Choose?");
	 scanf("%d",&i);
	 getchar();
 }
 return 1;
} 
void Administer(ALGraph *G)//Administor 
{
	int i;
	system("cls");
	printf("\n\n\n\n\n\n\n                     Choose one to Continue:\n");
    printf("                     *************************************\n");
    printf("                     **          1=Initialize          **\n");
    printf("                     **          2=Edit City           **\n");
    printf("                     **          3=Edit Flight         **\n");
    printf("                     **          4=Edit Train          **\n");
    printf("                     **          5=Back       **\n");    
    printf("                     *************************************\n");
    printf("                                     Choose?");
    scanf("%d",&i);
    getchar();
	while(i!=5)
	{
		switch(i)
		{
		case 1:initgraph(G);    //Initialize the System
			break;
        case 2:cityedit(G);     //Edit City
            break;
        case 3:flightedit(G);   //Edit Flight
            break; 
        case 4:trainedit(G);    //Edit Train
            break;
		}
		system("cls");
		printf("\n\n\n\n\n\n\n                     Choose one to Continue:\n");
		printf("                     *************************************\n");
		printf("                     **          1=Initialize          **\n");
		printf("                     **          2=Edit City           **\n");
		printf("                     **          3=Edit Flight         **\n");
		printf("                     **          4=Edit Train          **\n");
		printf("                     **          5=Back       **\n");
		printf("                     *************************************\n");
		printf("                                     Choose?");
        scanf("%d",&i);
        getchar();
	}
}
void initgraph(ALGraph *G)     //Initialize
{
	int i;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n       Please Choose a way to Initialize:\n");
    printf("                     **************************************\n");
    printf("                     **               1=Input            **\n");
    printf("                     **               2=File             **\n");
    printf("                     **************************************\n");
    printf("                                        CHoose?");
    scanf("%d",&i);
    getchar();
    switch(i)
	{
	case 1:createcityfile();  
         createplanefile();
         createtrainfile();
         CreateGraph(G);
         break;
	case 2:CreateGraph(G);
         break;
	}
}
void createcityfile()  //Edit City
{
	int i=0;
    int j;
    char flag='y';
    FILE *fp;
    printf("\nPlease Input City Name:\n");
    while(flag=='y'||flag=='Y')
	{
		printf("City Name:");
		gets(city[i]);
		i++;
		printf("Cotinue to Input?(Y/N)");
		scanf("%c",&flag);
        getchar();
	}
	printf("\n");
    if((fp=fopen("city.txt","wb"))==NULL)
	{
		printf("Can't Open the File!\n");
		return;
	}
	for(j=0;j<i;j++)
		fprintf(fp,"%10s",city[j]);
    fclose(fp);
}
void createplanefile() //Edit Flight 
{
	int code,bt[2],at[2];//Flihgt Number, Begin Time and End Time 
    float money;//Price 
    int i;
    int count;
    char vt[10],vh[10],flag; 
    FILE *fp;
    flag='y';
    count=0;
    while(flag=='Y'||flag=='y')     
	{
		printf("Please Input Flight Information:\n"); 
		printf("Flight Number:");  
		scanf("%d",&code);
        getchar();
        printf("Begin City:");   
        gets(vt);
        printf("End City:");  
        gets(vh);
        printf("Expenses:");  
        scanf("%f",&money);
        getchar();
        printf("Begin Time:");  
        scanf("%d:%d",&bt[0],&bt[1]);
        getchar();
		while(bt[0]<0||bt[0]>=24||bt[1]<0||bt[1]>=60)
		{
			printf("\nError Input! Please try again\n");
            scanf("%d:%d",&bt[0],&bt[1]);
            getchar();
		}
		printf("End Time:");  
        scanf("%d:%d",&at[0],&at[1]);
        getchar();
        while(at[0]<0||at[0]>=24||at[1]<0||at[1]>=60)
		{
			printf("\nError Input! Please try again\n");
            scanf("%d:%d",&at[0],&at[1]);
            getchar();
		}
		a[count].co=code; 
        strcpy(a[count].vt,vt);
        strcpy(a[count].vh,vh);
        a[count].bt[0]=bt[0];
        a[count].bt[1]=bt[1];
        a[count].at[0]=at[0];
        a[count].at[1]=at[1];
        a[count].mo=money;
        count++;  
        printf("Continue to Input?(Y/N)");  
        scanf("%c",&flag);
        getchar();
        printf("\n");
	}
	if((fp=fopen("plane.txt","wb"))==NULL) 
		printf("\nCan't Open the File!\n");  
	fprintf(fp,"%d",count);    
	for(i=0;i<count;i++)
		if(fwrite(&a[i],sizeof(struct arc),1,fp)!=1) 
			printf("\nReading Error!\n");  
		fclose(fp);    
}
void createtrainfile()//Edit Train
{
	int code,bt[2],at[2];
    float money;
    int i;
    int count;
    char vt[10],vh[10],flag; 
    FILE *fp;
    flag='y';
    count=0;
    while(flag=='y'||flag=='Y')    
	{
		printf("Please Input Flight Information:\n");
        printf("Train Number:");
        scanf("%d",&code);
        getchar();
        printf("Begin City:");
        gets(vt);
        printf("End City:");
        gets(vh);
        printf("Expenses:");
        scanf("%f",&money);
        getchar();
        printf("Begin Time:");  
        scanf("%d:%d",&bt[0],&bt[1]);
        getchar();
        while(bt[0]<0||bt[0]>=24||bt[1]<0||bt[1]>=60)   //发车时间有误 
		{
			printf("\nError Input! Please try again\n");
            scanf("%d:%d",&bt[0],&bt[1]);
            getchar();
		}
		printf("End Time:");
        scanf("%d:%d",&at[0],&at[1]);
        getchar();
        while(at[0]<0||at[0]>=24||at[1]<0||at[1]>=60)//到达时间有误 
		{
			printf("\nError Input! Please try again\n");
            scanf("%d:%d",&at[0],&at[1]);
            getchar();
		}
		a[count].co=code;    
        strcpy(a[count].vt,vt);
        strcpy(a[count].vh,vh);
        a[count].bt[0]=bt[0];
        a[count].bt[1]=bt[1];
        a[count].at[0]=at[0];
        a[count].at[1]=at[1];
        a[count].mo=money;
        count++;
        printf("Continue to Input?(Y/N)");
        scanf("%c",&flag);
        getchar();
        printf("\n");
	}
	if((fp=fopen("train.txt","wb"))==NULL)
    printf("\nCan't Open the File!\n");
    fprintf(fp,"%d",count);
    for(i=0;i<count;i++)
		if(fwrite(&a[i],sizeof(struct arc),1,fp)!=1)
			printf("\nReading Error!\n");
		fclose(fp);
}
int LocateVertex(ALGraph *G,char *v) //Add Node
{
	int j,k;
    j=-1;
    for(k=0;k<G->vexnum;k++)
    if(strcmp(G->vertices[k].cityname,v)==0) 
	{
		j=k;    
        break;
	}
	return(j);
}
void CreateGraph(ALGraph *G)//Create Graph 
{
	int i,j,k;
    int arc_num;
    int count1,count2;
    int m,t;
    ArcNode *p,*q; 
    FILE *fp;
    i=0;
    if((fp=fopen("city.txt","rb"))==NULL)  
	{
		printf("\nCan't Open the File!\n");
        return;
	}
	while(!feof(fp))  
	{
		fscanf(fp,"%10s",city[i]);
        i++;
	}
	fclose(fp);  
    j=0;
    while(j<i)
	{
		strcpy(G->vertices[j].cityname,city[j]);
        G->vertices[j].planefirstarc=NULL; 
        G->vertices[j].trainfirstarc=NULL;
        j++;
	}
	G->vexnum=i;
    if((fp=fopen("plane.txt","rb"))==NULL)
		printf("\nCan't Open the File!\n");
	k=0;
    fscanf(fp,"%d",&count1);   
    while(k<count1)
	{
		if(fread(&a[k],sizeof(struct arc),1,fp)!=1)
			printf("\nReading Error!\n");
        k++;
	}
	fclose(fp);  
    k=0;         
    arc_num=0;  
	while(k<count1)
	{
		i=LocateVertex(G,a[k].vt);  
        j=LocateVertex(G,a[k].vh); 
        q=G->vertices[i].planefirstarc;
        m=0;
		while(q!=NULL)          
		{
			if(q->adjvex==j) 
			{
				t=q->info.last+1;  
                q->info.stata[t].number=a[k].co;
                q->info.stata[t].expenditure=a[k].mo;
                q->info.stata[t].begintime[0]=a[k].bt[0];
                q->info.stata[t].begintime[1]=a[k].bt[1];
                q->info.stata[t].arrivetime[0]=a[k].at[0];
                q->info.stata[t].arrivetime[1]=a[k].at[1];
                q->info.last=t;
                m=1;
                break;
			}
			q=q->nextarc;
		}
		if(m==0)
		{
			p=(ArcNode*)malloc(sizeof(ArcNode));      
            p->adjvex=j;   
            p->info.stata[0].number=a[k].co;
            p->info.stata[0].expenditure=a[k].mo;
            p->info.stata[0].begintime[0]=a[k].bt[0];
            p->info.stata[0].begintime[1]=a[k].bt[1];
            p->info.stata[0].arrivetime[0]=a[k].at[0];
            p->info.stata[0].arrivetime[1]=a[k].at[1];
            p->info.last=0;
            p->nextarc=G->vertices[i].planefirstarc;
            G->vertices[i].planefirstarc=p;  
            arc_num++;
		}
		k++;
	}
	G->planearcnum=arc_num;
    if((fp=fopen("train.txt","rb"))==NULL)
	{
		printf("\nCan't Open the File!\n");
        return;
	}
	k=0;
    fscanf(fp,"%d",&count2); 
    while(k<count2)
	{
		if(fread(&a[k],sizeof(struct arc),1,fp)!=1)
			printf("\nReading Error!\n");
        k++;
	}
	fclose(fp);  
    k=0;       
    arc_num=0;  
    while(k<count2)
	{
		i=LocateVertex(G,a[k].vt);   
        j=LocateVertex(G,a[k].vh); 
        q=G->vertices[i].trainfirstarc; 
        m=0;
        while(q!=NULL)   
		{
			if(q->adjvex==j)  
			{
				t=q->info.last+1;  
                q->info.stata[t].number=a[k].co;
                q->info.stata[t].expenditure=a[k].mo;
                q->info.stata[t].begintime[0]=a[k].bt[0];
                q->info.stata[t].begintime[1]=a[k].bt[1];
                q->info.stata[t].arrivetime[0]=a[k].at[0];
                q->info.stata[t].arrivetime[1]=a[k].at[1];
                q->info.last=t;
                m=1;
                break;
			}
			q=q->nextarc;
		}
		if(m==0)
		{
			p=(ArcNode*)malloc(sizeof(ArcNode));  
            p->adjvex=j;  
            p->info.stata[0].number=a[k].co;
            p->info.stata[0].expenditure=a[k].mo;
            p->info.stata[0].begintime[0]=a[k].bt[0];
            p->info.stata[0].begintime[1]=a[k].bt[1];
            p->info.stata[0].arrivetime[0]=a[k].at[0];
            p->info.stata[0].arrivetime[1]=a[k].at[1];
            p->info.last=0;
            p->nextarc=G->vertices[i].trainfirstarc;
            G->vertices[i].trainfirstarc=p;  
            arc_num++;
		}
		k++;
	}
	G->trainarcnum=arc_num;
}
int save(ALGraph *G)  //Save Graph
{
	int i,j,k,t;
    ArcNode *q;
    FILE *fp;
    j=0;
    while(j<G->vexnum)
	{
		strcpy(city[j],G->vertices[j].cityname); 
        j++;
	}
	i=0;
	if((fp=fopen("city.txt","wb"))==NULL)
		printf("\nCan't Open the File!\n");
	while(i<G->vexnum)//
	{
		fprintf(fp,"%10s",city[i]);
        i++;
	}
	fclose(fp);
    k=0;
    for(i=0;i<G->vexnum;i++)
	{
		q=G->vertices[i].planefirstarc;
        while(q!=NULL)
		{
			for(t=0;t<=q->info.last;t++)
			{
				strcpy(a[k].vt,G->vertices[i].cityname);
                strcpy(a[k].vh,G->vertices[q->adjvex].cityname);
                a[k].co=q->info.stata[t].number;
                a[k].mo=q->info.stata[t].expenditure;
                a[k].bt[0]=q->info.stata[t].begintime[0];
                a[k].bt[1]=q->info.stata[t].begintime[1];
                a[k].at[0]=q->info.stata[t].arrivetime[0];
                a[k].at[1]=q->info.stata[t].arrivetime[1];
                k++;
			}
			q=q->nextarc;
		}
	}
	if((fp=fopen("plane.txt","wb"))==NULL)
	{
		printf("\nCan't Open the File!\n");
        return 0;
	}
	i=0;
    fprintf(fp,"%d",k);
    while(i<k)
	{
		if(fwrite(&a[i],sizeof(struct arc),1,fp)!=1)
			printf("\nReading Error!\n");
		i++;
	} 
	fclose(fp);
    k=0;
    for(i=0;i<G->vexnum;i++)
	{
		q=G->vertices[i].trainfirstarc;
		while(q!=NULL)
		{
			for(t=0;t<=q->info.last;t++)
			{
				strcpy(a[k].vt,G->vertices[i].cityname);
                strcpy(a[k].vh,G->vertices[q->adjvex].cityname);
                a[k].co=q->info.stata[t].number;
                a[k].mo=q->info.stata[t].expenditure;
                a[k].bt[0]=q->info.stata[t].begintime[0];
                a[k].bt[1]=q->info.stata[t].begintime[1];
                a[k].at[0]=q->info.stata[t].arrivetime[0];
                a[k].at[1]=q->info.stata[t].arrivetime[1];
                k++;    
			}
			q=q->nextarc;
		}
	}
	if((fp=fopen("train.txt","wb"))==NULL)
	{
		printf("\nCan't Open the File!\n");
		return 0;
	}
	i=0;
    fprintf(fp,"%d",k);
    while(i<k)
	{
		if(fwrite(&a[i],sizeof(struct arc),1,fp)!=1)
			printf("\nReading Error!\n");
		i++;
	}
	fclose(fp); 
    return 1;
}
void cityedit(ALGraph *G)   //Edit City
{
	int i;
	printf("\nPlease choose option for city:\n");
    printf("1=Add City\n2=Delete City\n");
    printf("Choose?");
    scanf("%d",&i);
    getchar();
    if(i==1)
		EnterVertex(G);//Add City 
	if(i==2)
		DeleteVertex(G);//Delete City
}
void EnterVertex(ALGraph *G) //Add City 
{
	char v[10],c;
    int i;
    printf("\nPlease Input City Name:");
    gets(v);
    i=LocateVertex(G,v);
    if(i>=0&&i<G->vexnum)   
	{
		printf("\nThis name has been existed\n");
        return;
	}
	else   
	{
		printf("\nConfirm?(Y/N)");
        c=getchar();
        getchar();
        if(c=='Y'||c=='y')
		{
			i=G->vexnum;
            strcpy(G->vertices[i].cityname,v);
            G->vertices[i].planefirstarc=NULL;
            G->vertices[i].trainfirstarc=NULL;
            G->vexnum=i+1;
            save(G);
		}
		else
			return;
	}
}
void DeleteVertex(ALGraph *G) //Delete City 
{
	int i,j,k,n;
    char v[10],c;
    ArcNode *p,*q,*m;
    printf("\n请输入删除的城市:"); 
    gets(v);
    printf("\n确认?(Y/N)"); 
    c=getchar();
    getchar();
    if(c=='Y'||c=='y') 
	{
		n=0;           
        while(n<G->vexnum&&strcmp(G->vertices[n].cityname,v)!=0) 
			n++; 
		if(n==G->vexnum)  
			printf("\nCan't Find the City!\n"); 
		else
		{
			i=LocateVertex(G,v);  
            p=G->vertices[i].planefirstarc;
            while(p!=NULL) 
			{
				q=p;
                p=p->nextarc;
                free(q);  
			}
			p=G->vertices[i].trainfirstarc;
            while(p!=NULL)  
			{
				q=p;
                p=p->nextarc;
                free(q);    
			}
			for(j=i;j<G->vexnum-1;j++)
			{
				strcpy(G->vertices[j].cityname,G->vertices[j+1].cityname); 
                G->vertices[j].planefirstarc=G->vertices[j+1].planefirstarc;
                G->vertices[j].trainfirstarc=G->vertices[j+1].trainfirstarc;
			}
			G->vertices[j].planefirstarc=NULL;  
            G->vertices[j].trainfirstarc=NULL;
            for(k=0;k<G->vexnum-1;k++)     
			{
				p=G->vertices[k].planefirstarc;
                while(p!=NULL)
				{
					if(p->adjvex>i)
					{
						p->adjvex=p->adjvex-1;
                        q=p;
                        p=p->nextarc;
					}
					else if(p->adjvex==i) 
					{
						if(p==G->vertices[k].planefirstarc) 
						{
							m=p;
                            G->vertices[k].planefirstarc=p->nextarc; 
                            p=p->nextarc; 
                            free(m);  
						}
						else
						{
							q->nextarc=p->nextarc;  
                            m=p;
                            p=p->nextarc;  
                            free(q);  
						}
					}
					else
					{
						q=p;
                        p=p->nextarc;  
					}
				}
			}
			for(k=0;k<G->vexnum-1;k++)  //Train 
			{
				p=G->vertices[k].trainfirstarc; 
                while(p!=NULL)
				{
					if(p->adjvex>i)  
					{
						p->adjvex=p->adjvex-1; 
                        q=p;
                        p=p->nextarc;  
					}
					else if(p->adjvex==i)  
					{
						if(p==G->vertices[k].trainfirstarc)
						{
							m=p;
                            G->vertices[k].trainfirstarc=p->nextarc;  
                            p=p->nextarc;
                            free(m);
						}
						else
						{
							q->nextarc=p->nextarc;
                            m=p;
                            p=p->nextarc;
                            free(q);
						}
					}
					else
					{
						q=p;
                        p=p->nextarc;
					}
				}
			}
		}
		G->vexnum--;
		save(G);
}
else
return;
}

/***************************************1**************************************************/
void flightedit(ALGraph *G)
{
	int i;
    printf("\nPlease choose option for flight:\n");
    printf("1=Add Flight\n2=Delete Flight\n");
    printf("Choose?");
    scanf("%d",&i);
    getchar();
    if(i==1)
		EnterplaneArc(G); 
    if(i==2)
		DeleteplaneArc(G);
}
void trainedit(ALGraph *G)
{
	int i;
    printf("\nPlease choose option for train:\n");
    printf("1=Add Train\n2=Delete Train\n");
    printf("Choose?");
    scanf("%d",&i);
    getchar();
    if(i==1)
		EntertrainArc(G);
    if(i==2)
		DeletetrainArc(G);
}
void EnterplaneArc(ALGraph *G)
{
	int i,j,bt[2],at[2];
    int code;
    float money;
    int m,t;
    char vt[10],vh[10],c;
    ArcNode *p,*q;
    printf("\nPlease Input New FLight:\n");//Input Flight Information 
    printf("Flight Number:");
    scanf("%d",&code);
    getchar();
    printf("Begin City:");
    gets(vt);
    printf("End City:");
    gets(vh);
    printf("Expenses:");
    scanf("%f",&money);
    getchar();
    printf("Begin Time:");
    scanf("%d:%d",&bt[0],&bt[1]);
    getchar();
    while(bt[0]<0||bt[0]>=24||bt[1]<0||bt[1]>=60)
	{
		printf("\nTime Error, Please Try Again\n");
        scanf("%d:%d",&bt[0],&bt[1]);
        getchar();
	}
	printf("End Time:");
    scanf("%d:%d",&at[0],&at[1]);
    getchar();
    while(at[0]<0||at[0]>=24||at[1]<0||at[1]>=60)//判断时间，同上 
	{
		printf("\nTime Error, Please Try Again\n");
        scanf("%d:%d",&at[0],&at[1]);
        getchar();
	}
	printf("\nConfirm?(Y/N)");
    c=getchar();
    getchar();
    if(c=='Y'||c=='y')
	{
		i=LocateVertex(G,vt); 
        j=LocateVertex(G,vh);
        if(i==-1)
		{
			printf("\nError! Can't find the begin city\n"); 
            return;
		} 
		if(j==-1)
		{
			printf("\nError! Can't find the end city\n");
            return;
		}
		q=G->vertices[i].planefirstarc;
        m=0;
        while(q!=NULL)
		{
			if(q->adjvex==j)
			{                   
				t=q->info.last+1;
                q->info.stata[t].number=code;
                q->info.stata[t].expenditure=money;
                q->info.stata[t].begintime[0]=bt[0];
                q->info.stata[t].begintime[1]=bt[1];
                q->info.stata[t].arrivetime[0]=at[0];
                q->info.stata[t].arrivetime[1]=at[1];
                q->info.last=t;
                m=1;
                break;
			} 
			q=q->nextarc;
		}
		if(m==0)
		{                                        
			p=(ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex=j;
            p->info.stata[0].number=code;
            p->info.stata[0].expenditure=money;
            p->info.stata[0].begintime[0]=bt[0];
            p->info.stata[0].begintime[1]=bt[1];
            p->info.stata[0].arrivetime[0]=at[0];
            p->info.stata[0].arrivetime[1]=at[1];
            p->info.last=0;
            p->nextarc=G->vertices[i].planefirstarc;
            G->vertices[i].planefirstarc=p;
            G->planearcnum++;
		}
		save(G);
	}
	else
		return;
}
void EntertrainArc(ALGraph *G)
{
	int i,j,bt[2],at[2];
    int code;
    float money;
    int m,t;
    char vt[10],vh[10],c;
    ArcNode *p,*q;
    printf("\nPlease Inpuu New Train:\n");
    printf("Train Number:");
    scanf("%d",&code);
    getchar();
    printf("Begin City:");
    gets(vt);
    printf("End City:");
    gets(vh);
    printf("Expenses:");
    scanf("%f",&money);
    getchar();
    printf("Begin Time:");
    scanf("%d:%d",&bt[0],&bt[1]);
    getchar();
    while(bt[0]<0||bt[0]>=24||bt[1]<0||bt[1]>=60)
	{
		printf("\nTime Error, Please try again\n");
        scanf("%d:%d",&bt[0],&bt[1]);
        getchar();
	}
	printf("End Time:");
    scanf("%d:%d",&at[0],&at[1]);
    getchar();
    while(at[0]<0||at[0]>=24||at[1]<0||at[1]>=60)
	{
		printf("\nTime Error, Please try again\n");
        scanf("%d:%d",&at[0],&at[1]);
        getchar();
	}
	printf("\nConfirm?(Y/N)");
    c=getchar();
    getchar();
    if(c=='Y'||c=='y')
	{
		i=LocateVertex(G,vt);
        j=LocateVertex(G,vh);
        if(i==-1)
		{
			printf("\nError! Can't find the begin city\n");
            return;
		}
		if(j==-1)
		{
			printf("\nError! Can't find the end city\n");
            return;
		}
		q=G->vertices[i].trainfirstarc;
        m=0;
        while(q!=NULL)
		{
			if(q->adjvex==j)
			{
				t=q->info.last+1;
                q->info.stata[t].number=code;
                q->info.stata[t].expenditure=money;
                q->info.stata[t].begintime[0]=bt[0];
                q->info.stata[t].begintime[1]=bt[1];
                q->info.stata[t].arrivetime[0]=at[0];
                q->info.stata[t].arrivetime[1]=at[1];
                q->info.last=t;
                m=1;
                break;
			}
			q=q->nextarc;
		}
		if(m==0)
		{
			p=(ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex=j;
            p->info.stata[0].number=code;
            p->info.stata[0].expenditure=money;
            p->info.stata[0].begintime[0]=bt[0];
            p->info.stata[0].begintime[1]=bt[1];
            p->info.stata[0].arrivetime[0]=at[0];
            p->info.stata[0].arrivetime[1]=at[1];
            p->info.last=0;
            p->nextarc=G->vertices[i].trainfirstarc;
            G->vertices[i].trainfirstarc=p;
            G->trainarcnum++;
		}
		save(G);
	}
	else
		return;
}
int DeleteplaneArc(ALGraph *G) 
{
	int i,j;
    int code;
    char vt[10],vh[10],c;
    int n;
    int k;
    ArcNode *p,*q;
    printf("\nPlease Input Flight Informaiton:\n");
    printf("Flight Number:");
    scanf("%d",&code);
    getchar();
    printf("Begin City:");
    gets(vt);
    printf("End City:");
    gets(vh);
    printf("\nConfirm?(Y/N)");
    c=getchar();
    getchar();
    if(c=='Y'||c=='y')
	{
		i=LocateVertex(G,vt);
        j=LocateVertex(G,vh);
        if(i==-1)
		{
			printf("\nError! Can't find the begin city\n");
            return 0;
		}
		if(j==-1)
		{
			printf("\nError! Can't find the end city\n");
            return 0;
		}
		p=G->vertices[i].planefirstarc;
        q=p;
        while(p!=NULL) 
		{
			if(p->adjvex==j)//Search Flight 
			{
				n=-1;
                for(k=0;k<=p->info.last;k++)
				{
					if(p->info.stata[k].number==code)
					{
						n=k; 
                        break;
					}
				}
				if(n!=-1) 
					if(p->info.last==0)
					{                                
						if(q==p)
							G->vertices[i].planefirstarc=p->nextarc;
						else
							q->nextarc=p->nextarc;
						free(p);
					}
					else
					{
						for(k=n;k<p->info.last;k++)
						{
							p->info.stata[k].number=p->info.stata[k+1].number;
                            p->info.stata[k].expenditure=p->info.stata[k+1].expenditure;
                            p->info.stata[k].begintime[0]=p->info.stata[k+1].begintime[0];
                            p->info.stata[k].begintime[1]=p->info.stata[k+1].begintime[1];
                            p->info.stata[k].arrivetime[0]=p->info.stata[k+1].arrivetime[0];
                            p->info.stata[k].arrivetime[1]=p->info.stata[k+1].arrivetime[1];
						}
						p->info.last=p->info.last-1;
					}
					else
						printf("\nCan't find No.%d\n",code);
					save(G);
                    return 0;
			}
			q=p;
            p=p->nextarc;
		}
		if(p==NULL)
			printf("\nCan't find the flight\n");
	}
	else
		return 1;
	return 1;
}
int DeletetrainArc(ALGraph *G)
{
	int i,j;
    int code;
    char vt[10],vh[10],c;
    int n;
    int k;
    ArcNode *p,*q;
    printf("\nPlease Input Train Information:\n");
    printf("Train Number:");
    scanf("%d",&code);
    getchar();
    printf("Begin City:");
    gets(vt);
    printf("End City:");
    gets(vh);
    printf("\nConfirm?(Y/N)");
    c=getchar();
    getchar();
    if(c=='Y'||c=='y')
	{
		i=LocateVertex(G,vt);
        j=LocateVertex(G,vh);
        if(i==-1)
		{
			printf("\nError! Can't find the begin city\n");
            return 0;
		}
		if(j==-1)
		{
			printf("\nError! Can't find the end city\n");
            return 0;
		}
		p=G->vertices[i].trainfirstarc;
        q=p;
        while(p!=NULL)
		{
			if(p->adjvex==j)
			{
				n=-1;
                for(k=0;k<=p->info.last;k++)
				{
					if(p->info.stata[k].number==code)
					{
						n=k;
                        break;
					}
				}
				if (n != -1)
					if (p->info.last == 0)
					{
						if (q == p)
							G->vertices[i].trainfirstarc = p->nextarc;
						else
							q->nextarc = p->nextarc;
						free(p);
					}
					else
					{
						for (k = n; k < p->info.last; k++)
						{
							p->info.stata[k].number = p->info.stata[k + 1].number;
							p->info.stata[k].expenditure = p->info.stata[k + 1].expenditure;
							p->info.stata[k].begintime[0] = p->info.stata[k + 1].begintime[0];
							p->info.stata[k].begintime[1] = p->info.stata[k + 1].begintime[1];
							p->info.stata[k].arrivetime[0] = p->info.stata[k + 1].arrivetime[0];
							p->info.stata[k].arrivetime[1] = p->info.stata[k + 1].arrivetime[1];
						}
						p->info.last = p->info.last - 1;
					}
				else
					printf("\nCan't find No.%d\n", code);
					save(G);
					return 0;
			}
			q=p;
			p=p->nextarc;
		}
		if(p==NULL)
			printf("\nCnan't find the train\n");
	}
	else
		return 0;
	return 1;
}
void UserDemand(ALGraph G)
{
	int i;
    char q;
    system("cls");
    printf("\n\n\n\n\n\n\n                                Please Choose:\n");
    printf("                     *************************************\n");
    printf("                     **          1=Minimum Expenses      **\n");
    printf("                     **          2=Minimum Time          **\n");
    printf("                     **          3=Minimum Transfers     **\n");
    printf("                     **          4=Previous Menu          **\n");
    printf("                     *************************************\n");
    printf("                                   Choose?");
    scanf("%d",&i);
    getchar();
    while(i!=4)
	{
		switch(i)
		{
		case 1:DemandDispose(1,G); 
			break; 
        case 2:DemandDispose(2,G);
			break;   
        case 3:DemandDispose(3,G); 
			break;   
		}
		printf("Press Enter to Continue\n");
        scanf("%c",&q);
        scanf("%c",&q);
        system("cls");
		printf("\n\n\n\n\n\n\n                                Please Choose:\n");
		printf("                     *************************************\n");
		printf("                     **          1=Minimum Expenses      **\n");
		printf("                     **          2=Minimum Time          **\n");
		printf("                     **          3=Minimum Transfers     **\n");
		printf("                     **          4=Previous Menu          **\n");
		printf("                     *************************************\n");
		printf("                                   Choose?");
        scanf("%d",&i);
        getchar();
	}
	return ;
}
void DemandDispose(int n,ALGraph G)
{
	char q;
    ArcNode *plane,*train;
    infolist planearcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM],trainarcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int i,j,k,final[MAX_VERTEX_NUM],T[MAX_VERTEX_NUM][2];
    float M[MAX_VERTEX_NUM];
    for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			for(k=0;k<MAX_ROUTE_NUM;k++)
			{           
				planearcs[i][j].stata[k].expenditure=INFINITY;
                planearcs[i][j].stata[k].begintime[0]=0;
                planearcs[i][j].stata[k].begintime[1]=0;
                planearcs[i][j].stata[k].arrivetime[0]=INFINITY;
                planearcs[i][j].stata[k].arrivetime[1]=INFINITY;
                planearcs[i][j].last=-1;
                trainarcs[i][j].stata[k].expenditure=INFINITY;
                trainarcs[i][j].stata[k].begintime[0]=0;
                trainarcs[i][j].stata[k].begintime[1]=0;
                trainarcs[i][j].stata[k].arrivetime[0]=INFINITY;
                trainarcs[i][j].stata[k].arrivetime[1]=INFINITY;
                trainarcs[i][j].last=-1;
			}
			for(i=0;i<G.vexnum;i++)
			{
				plane=G.vertices[i].planefirstarc;
                train=G.vertices[i].trainfirstarc;
                while(plane!=NULL)
				{
					planearcs[i][plane->adjvex]=plane->info;
                    plane=plane->nextarc;
				}
				while(train!=NULL) 
				{
					trainarcs[i][train->adjvex]=train->info;
                    train=train->nextarc;
				}
			}
			printf("\nPlease Choose Begin City:\n"); 
            for(k=0;k<G.vexnum;k++)
				printf("%d=%s\n",k,G.vertices[k].cityname);
			printf("Choose?");
            scanf("%d",&i);
            printf("\nPlease Choose End City:\n");
            for(k=0;k<G.vexnum;k++)
				printf("%d=%s\n",k,G.vertices[k].cityname);
            printf("Choose?");
            scanf("%d",&j);
            printf("\nPlease Choose Transporation:\n");
            printf("1=Train\n2=Flight\n");
            printf("Choose?");
            scanf("%d",&k);
            printf("\nConfirm? (Y/N)");
            scanf("%c",&q);
            scanf("%c",&q);
            if(q=='Y'||q=='y')
			{
				if(k==1&&n==1)
					ExpenditureDispose(1,trainarcs,G,i,j,M,final); 
				else if(k==1&&n==2)
					TimeDispose(1,trainarcs,G,i,j,T,final);   
				else if(k==1&&n==3)
					TransferDispose(1,trainarcs,G,i,j);  
				else if(k==2&&n==1)
					ExpenditureDispose(2,planearcs,G,i,j,M,final);  
				else if(k==2&&n==2)
					TimeDispose(2,planearcs,G,i,j,T,final); 
				else if(k==2&&n==3)
					TransferDispose(2,planearcs,G,i,j);  
			}
			else if(q=='N'||q=='n')
				UserDemand(G);
			else
			{
				printf("\nError\n\n");
                DemandDispose(k,G);
			}
			return ;
}
void InitQueue(LinkQueue *Q) 
{
	Q->front=(QNode *)malloc(sizeof(QNode)); 
    Q->rear=Q->front; 
    Q->front->next=NULL;
}
void EnterQueue(LinkQueue *Q,int x) 
{
	QNode *newnode;
    newnode=(QNode *)malloc(sizeof(QNode));
    newnode->adjvex=x; 
    newnode->next=NULL;
    Q->rear->next=newnode;
    Q->rear=newnode;
}
void DeleteQueue(LinkQueue *Q,int *x)
{
	QNode *p;
    p=Q->front->next; 
    Q->front->next=p->next;
    if(Q->rear==p)
		Q->rear=Q->front;
	*x=p->adjvex;
    free(p);
}
int IsEmpty(LinkQueue *Q)
{
	if(Q->front==Q->rear)
		return(1);
	else
		return(0);
}
void TransferDispose(int k,infolist (*arcs)[MAX_VERTEX_NUM],ALGraph G,int v0,int v1) 
{
	int visited[MAX_VERTEX_NUM],v,w,n=1;
    LinkQueue Q;
    ArcNode *t;
    Node *p,*q,*r,*s;
    p=(Node *)malloc(G.vexnum*sizeof(Node));
    for(v=0;v<G.vexnum;v++)
	{
		visited[v]=0;
        p[v].next=NULL;
	}
	InitQueue(&Q);
    visited[v0]=1;
    q=(Node *)malloc(sizeof(Node));
    q->adjvex=v0; 
    q->next=NULL;
    p[v0].next=q;
    EnterQueue(&Q,v0);
    while(!IsEmpty(&Q))     
	{
		DeleteQueue(&Q,&v);
		if(k==1)
			t=G.vertices[v].trainfirstarc;
		else
			t=G.vertices[v].planefirstarc;
		while(t!=NULL)
		{
			w=t->adjvex;   
            if(!visited[w])  
			{
				visited[w]=1; 
                q=&p[w];
                s=p[v].next;
                while(s!=NULL)
				{                 
					r=(Node *)malloc(sizeof(Node));
                    r->adjvex=s->adjvex;
                    q->next=r;
                    q=r;
                    s=s->next;
				}
				r=(Node *)malloc(sizeof(Node));
                r->adjvex=w;  
                r->next=NULL; 
                q->next=r;   
                if(w==v1)     
				{             
					q=p[w].next;
                    r=q->next;
                    printf("\nTHe Routine is:\n");
                    while(r!=NULL)
					{
						if(k==1) 
							printf("Take Train No.%d at %d:%d from %s to %s\n",(*(*(arcs+q->adjvex)+r->adjvex)).stata[0].number,(*(*(arcs+q->adjvex)+r->adjvex)).stata[0].begintime[0],(*(*(arcs+q->adjvex)+r->adjvex)).stata[0].begintime[1],G.vertices[q->adjvex].cityname,G.vertices[r->adjvex].cityname);
                        else
                            printf("Take Flight No.%d at %d:%d from %s to %s\n",(*(*(arcs+q->adjvex)+r->adjvex)).stata[0].number,(*(*(arcs+q->adjvex)+r->adjvex)).stata[0].begintime[0],(*(*(arcs+q->adjvex)+r->adjvex)).stata[0].begintime[1],G.vertices[q->adjvex].cityname,G.vertices[r->adjvex].cityname);
						q=r;
                        r=r->next;
                        n++;
					}
					printf("Transporate %d times\n\n",n-2);
                    for(v=0;v<G.vexnum;v++) 
					{
						q=p[v].next;
                        while(q!=NULL)
						{
							s=q;
                            q=q->next;
                            free(s);
						}
						p[v].next=NULL;
					}
					free(p);
					return;
				}
				EnterQueue(&Q,w);  
			}
			t=t->nextarc;  
		}
	}
	for(v=0;v<G.vexnum;v++)
	{
		q=p[v].next;
        while(q!=NULL)
		{
			s=q;
            q=q->next;
            free(s);
		}
        p[v].next=NULL;
	}
	free(p);
    if(k==1)
		printf("\nCan't find train from %s to %s\n\n",G.vertices[v0].cityname,G.vertices[v1].cityname);
    else
        printf("\nCan't find flight from %s to %s\n\n",G.vertices[v0].cityname,G.vertices[v1].cityname);
}

/***************************2***********************************************************************/
void MinExpenditure(infolist arcs,float *expenditure,int *route) 
{
	int i;
    *expenditure=arcs.stata[0].expenditure;
    if(*expenditure<INFINITY)
		*route=0;
    else
        *route=-1;
    for(i=1;i<=arcs.last;i++)
		if(arcs.stata[i].expenditure<*expenditure)
		{
			*expenditure=arcs.stata[i].expenditure;
            *route=i;

		}
}
void ExpenditureDispose(int k,infolist (*arcs)[MAX_VERTEX_NUM],ALGraph G,int v0,int v1,float *M,int *final)
{
	int v=-1,w,i,route;
    float m,expenditure;
    Node *p,*q,*r,*s;
    p=(Node *)malloc(G.vexnum*sizeof(Node));
    for(v=0;v<G.vexnum;v++)
	{
		*(final+v)=False; 
        MinExpenditure(*(*(arcs+v0)+v),M+v,&route); 
        p[v].next=NULL;     
        if(*(M+v)<INFINITY)
		{
			q=(Node *)malloc(sizeof(Node)); 
            s=(Node *)malloc(sizeof(Node));
            q->adjvex=v0;
            s->adjvex=v;
            s->route=route;
            p[v].next=q;
            q->next=s;
            s->next=NULL;
		}                           
	}
	*(M+v0)=0;        
    *(final+v0)=True; 
    for(i=1;i<G.vexnum;i++)
	{
		m=INFINITY;
        v=-1;
        for(w=0;w<G.vexnum;w++)
			if(*(final+w)==False) 
				if(*(M+w)<m)
				{
					v=w;
                    m=*(M+w);
				}
				if(v==v1)      
				{
					q=p[v].next;
                    r=q->next;
                    printf("\nThe routine is:\n");
                    while(r!=NULL)
					{
						if(k==1)
							printf("Take train No.%d at %d:%d from %s to %s\n",(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].number,(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[0],(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[1],G.vertices[q->adjvex].cityname,G.vertices[r->adjvex].cityname);
                        else
                            printf("Take flight No.%d at %d:%d from %s to %s\n",(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].number,(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[0],(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[1],G.vertices[q->adjvex].cityname,G.vertices[r->adjvex].cityname);
                        q=r;
                        r=r->next;
					}
					printf("Expenses is %f\n\n",m);
                    for(v=0;v<G.vexnum;v++)
					{
						q=p[v].next;
                        while(q!=NULL)
						{
							s=q;
                            q=q->next;
                            free(s);
						}
                        p[v].next=NULL;
					}
					free(p);
                    return;
				}
                else if(v!=-1)
				{
					*(final+v)=True;   
                    for(w=0;w<G.vexnum;w++)
						if(*(final+w)==False&&(*(*(arcs+v)+w)).last>-1)
						{
							MinExpenditure(*(*(arcs+v)+w),&expenditure,&route);
                            if(*(M+w)>m+expenditure)
							{
								*(M+w)=m+expenditure;
                                q=p[w].next;
                                while(q!=NULL)
								{
									s=q;
                                    q=q->next;
                                    free(s);
								}
								q=&p[w];
                                s=p[v].next;
                                while(s!=NULL)
								{
									r=(Node *)malloc(sizeof(Node));
                                    r->adjvex=s->adjvex;
                                    r->route=s->route;
                                    q->next=r;
                                    q=r;
                                    s=s->next;
								} 
                                r=(Node *)malloc(sizeof(Node));
                                r->adjvex=w;
                                r->route=route;
                                r->next=NULL;
                                q->next=r;
							}
						}
				}
	}
    for(v=0;v<G.vexnum;v++)
	{
		q=p[v].next;
        while(q!=NULL)
		{
			s=q;
            q=q->next;
            free(s);
		}
        p[v].next=NULL;
	}
    free(p);
	if (k == 1)
		printf("\nCan't find train from %s to %s\n\n", G.vertices[v0].cityname, G.vertices[v1].cityname);
    else
        printf("\nCan't find flight from %s to %s\n\n",G.vertices[v0].cityname,G.vertices[v1].cityname);
}
void MinTime(infolist arcs,int *time,int *route)
{
	int i,t[2];
    time[0]=arcs.stata[0].arrivetime[0]-arcs.stata[0].begintime[0];
    time[1]=arcs.stata[0].arrivetime[1]-arcs.stata[0].begintime[1];
    if(time[0]<0)
		time[0]=time[0]+24;
    if(time[1]<0)
	{
		time[0]--;
        time[1]=time[1]+60;
	}
    *route=0;
    for(i=1;i<=arcs.last;i++)
	{
		t[0]=arcs.stata[i].arrivetime[0]-arcs.stata[i].begintime[0];  
        t[1]=arcs.stata[i].arrivetime[1]-arcs.stata[i].begintime[1];  
        if(t[0]<0)
			t[0]=t[0]+24;
        if(t[1]<0)
		{
			t[0]--;
            t[1]=t[1]+60;
		}
        if(t[0]<time[0]||(t[0]==time[0]&&t[1]<time[1]))
		{
			time[0]=t[0];
            time[1]=t[1];
            *route=i;
		}
	}
}
void TimeTreeDispose(Node *head,infolist (*arcs)[MAX_VERTEX_NUM])
{
	int n,i,j;
	Node *p;
    LinkQueue Q;
    TimeTree root;
    root=(TimeNode *)malloc(sizeof(TimeNode));
    InitQueue(&Q);
    TTime[0]=INFINITY;
    TTime[1]=INFINITY;
    p=head->next;
    while(p!=NULL)
	{
		EnterQueue(&Q,p->adjvex);
        p=p->next;
	}
    DeleteQueue(&Q,&i);
    root->adjvex=i;
    DeleteQueue(&Q,&j);
    CreateTimeTree(root,i,j,&Q,arcs);
    for(n=0;n<=(*(*(arcs+i)+j)).last;n++)
	{
		time1[0]=0;
        time1[1]=0;
        time2[0]=root->child[n]->begintime[0];
        time2[1]=root->child[n]->begintime[1];
        time[0]=INFINITY;
        time[1]=INFINITY;
        VisitTimeTree(root->child[n]);
        if(time[0]<TTime[0]||(time[0]==TTime[0]&&time[1]<TTime[1]))
		{
			TTime[0]=time[0];
            TTime[1]=time[1];
            p=head->next;
            while(p!=NULL)
			{
				p->route=d[p->adjvex];
                p=p->next;
			}
		}
	}
    DestoryTimeTree(root);
}
void CreateTimeTree(TimeTree p,int i,int j,LinkQueue *Q,infolist (*arcs)[MAX_VERTEX_NUM])
{
	int n,x,y;
    TimeTree q;
    q=(TimeNode *)malloc(sizeof(TimeNode));
    q->adjvex=j;
    q->begintime[0]=(*(*(arcs+i)+j)).stata[0].begintime[0];
    q->begintime[1]=(*(*(arcs+i)+j)).stata[0].begintime[1];
    q->arrivetime[0]=(*(*(arcs+i)+j)).stata[0].arrivetime[0];
    q->arrivetime[1]=(*(*(arcs+i)+j)).stata[0].arrivetime[1];
    q->route=0;
    p->child[0]=q;
    for(n=1;n<=(*(*(arcs+i)+j)).last;n++)
	{
		q=(TimeNode *)malloc(sizeof(TimeNode));
        q->adjvex=j;
        q->begintime[0]=(*(*(arcs+i)+j)).stata[n].begintime[0];
        q->begintime[1]=(*(*(arcs+i)+j)).stata[n].begintime[1];
        q->arrivetime[0]=(*(*(arcs+i)+j)).stata[n].arrivetime[0];
        q->arrivetime[1]=(*(*(arcs+i)+j)).stata[n].arrivetime[1];
        q->route=n;
        p->child[n]=q;
	} 
    while(n<MAX_ROUTE_NUM)
	{
		p->child[n]=NULL;
        n++;
	}
    x=j;
    if(!IsEmpty(Q))
	{
		DeleteQueue(Q,&y);
        CreateTimeTree(p->child[0],x,y,Q,arcs);
        for(n=1;n<=(*(*(arcs+i)+j)).last;n++)
			CopyTimeTree(p->child[n],p->child[0]);
	}
    else
	{
		for(n=0;n<MAX_ROUTE_NUM;n++)
			p->child[0]->child[n]=NULL;
        for(n=1;n<=(*(*(arcs+i)+j)).last;n++)
            CopyTimeTree(p->child[n],p->child[0]);
	}
    return ;
}
void CopyTimeTree(TimeTree p,TimeTree q)
{
	TimeTree r;
    int n=0;
    while(q->child[n]!=NULL) 
	{
		r=(TimeNode *)malloc(sizeof(TimeNode));
        r->adjvex=q->child[n]->adjvex;
        r->begintime[0]=q->child[n]->begintime[0];
        r->begintime[1]=q->child[n]->begintime[1];
        r->arrivetime[0]=q->child[n]->arrivetime[0];
        r->arrivetime[1]=q->child[n]->arrivetime[1];
        r->route=q->child[n]->route;
        p->child[n]=r;
        CopyTimeTree(p->child[n],q->child[n]);
        n++;
	}
    while(n<MAX_ROUTE_NUM)
	{
		p->child[n]=NULL;
        n++;
	}
	return ;
}
void VisitTimeTree(TimeTree p)
{
	int n,x[2],y[2];
    x[0]=time1[0];
    x[1]=time1[1];
    y[0]=time2[0];
    y[1]=time2[1];
    if(p->begintime[0]>time2[0]||(p->begintime[0]==time2[0]&&p->begintime[1]>=time2[1]))
	{
		time1[0]=time1[0]+p->begintime[0]-time2[0];
        time1[1]=time1[1]+p->begintime[1]-time2[1];
        if(time1[1]<0)
		{
			time1[1]=time1[1]+60;
            time1[0]--;
		} 
        if(time1[1]>=60)
		{
			time1[1]=time1[1]-60;
            time1[0]++;
		} 
	} 
    else if(p->begintime[0]<time2[0]||(p->begintime[0]==time2[0]&&p->begintime[1]<time2[1]))
	{
		time1[0]=time1[0]+p->begintime[0]-time2[0]+24;
        time1[1]=time1[1]+p->begintime[1]-time2[1];
        if(time1[1]<0)
		{
			time1[1]=time1[1]+60;
            time1[0]--;
		} 
        if(time1[1]>=60)
		{
			time1[1]=time1[1]-60;
            time1[0]++;
		} 
	} 
if(p->arrivetime[0]>p->begintime[0]||(p->arrivetime[0]==p->begintime[0]&&p->arrivetime[1]>=p->begintime[1]))
	{
		time1[0]=time1[0]+p->arrivetime[0]-p->begintime[0];
        time1[1]=time1[1]+p->arrivetime[1]-p->begintime[1];
        if(time1[1]<0)
		{
			time1[1]=time1[1]+60;
            time1[0]--;
		} 
        if(time1[1]>=60)
		{
			time1[1]=time1[1]-60;
            time1[0]++;
		}
	}
    else if(p->arrivetime[0]<p->begintime[0]||(p->arrivetime[0]==p->begintime[0]&&p->arrivetime[1]<p->begintime[1]))
	{
		time1[0]=time1[0]+p->arrivetime[0]-p->begintime[0]+24;
        time1[1]=time1[1]+p->arrivetime[1]-p->begintime[1];
        if(time1[1]<0)
		{
			time1[1]=time1[1]+60;
            time1[0]--;
		}
        if(time1[1]>=60)
		{
			time1[1]=time1[1]-60;
            time1[0]++;
		}
	}
    time2[0]=p->arrivetime[0];
    time2[1]=p->arrivetime[1];
    c[p->adjvex]=p->route;
    if(p->child[0]==NULL)
	{
		if(time1[0]<time[0]||(time1[0]==time[0]&&time1[1]<time[1]))
		{
			time[0]=time1[0];
            time[1]=time1[1];
            for(n=0;n<MAX_VERTEX_NUM;n++)
				d[n]=c[n];
		}
	}
    else
	{
		n=0;
        while(p->child[n]!=NULL)
		{
			VisitTimeTree(p->child[n]);
            n++;
		}
	}
    time1[0]=x[0];
    time1[1]=x[1];
    time2[0]=y[0];
    time2[1]=y[1];
}
void DestoryTimeTree(TimeTree p)
{
	if(p!=NULL)
	{
		DestoryTimeTree(p->child[0]);
        DestoryTimeTree(p->child[1]);
        DestoryTimeTree(p->child[2]);
        DestoryTimeTree(p->child[3]);
        DestoryTimeTree(p->child[4]);
        p->child[0]=NULL;
        p->child[1]=NULL;
        p->child[2]=NULL;
        p->child[3]=NULL;
        p->child[4]=NULL;
        free(p);
	}
    return ;
}
void TimeDispose(int k,infolist (*arcs)[MAX_VERTEX_NUM],ALGraph G,int v0,int v1,int (*T)[2],int *final)
{
	int v,w,i,route,m[2];
    Node *p,*q,*r,*s,*t;
    p=(Node *)malloc(G.vexnum*sizeof(Node));
    for(v=0;v<G.vexnum;v++)
	{
		*(final+v)=False;  
        MinTime(*(*(arcs+v0)+v),*(T+v),&route);  
        p[v].next=NULL;    
        if(*(*(T+v)+0)<INFINITY&&*(*(T+v)+1)<INFINITY)
		{
			q=(Node *)malloc(sizeof(Node));
            s=(Node *)malloc(sizeof(Node));
            q->adjvex=v0;
            s->adjvex=v;
            s->route=route;
            p[v].next=q;
            q->next=s;
            s->next=NULL;
		}
	}
    *(*(T+v0)+0)=0;  
    *(*(T+v0)+1)=0;
    *(final+v0)=True;  
    for(i=1;i<G.vexnum;i++)
	{
		m[0]=INFINITY;
        m[1]=INFINITY;
        v=-1;
        for(w=0;w<G.vexnum;w++)
			if(*(final+w)==False)   
				if(*(*(T+w)+0)<m[0]||(*(*(T+w)+0)==m[0]&&*(*(T+w)+1)<m[1]))
				{
					v=w;
                    m[0]=*(*(T+w)+0);
                    m[1]=*(*(T+w)+1);
				}
                if(v==v1)
				{
					q=p[v].next;
                    r=q->next;
                    printf("\nThe routine is \n");
                    while(r!=NULL)
					{
						if(k==1)
							printf("Take Train No.%d at %d:%d from %s to %s\n",(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].number,(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[0],(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[1],G.vertices[q->adjvex].cityname,G.vertices[r->adjvex].cityname);
                        else
                            printf("Take Flight No.%d at %d:%d from %s to %s\n",(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].number,(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[0],(*(*(arcs+q->adjvex)+r->adjvex)).stata[r->route].begintime[1],G.vertices[q->adjvex].cityname,G.vertices[r->adjvex].cityname);
                        q=r;
                        r=r->next;
					} 
                    printf("Time %d:%d\n\n",m[0],m[1]);
                    for(v=0;v<G.vexnum;v++)
					{
						q=p[v].next;
                        while(q!=NULL)
						{
							s=q;
                            q=q->next;
                            free(s);
						} 
                        p[v].next=NULL;
					}
                    free(p);
                    return ;
				} 
                else if(v!=-1)
				{
					*(final+v)=True;
                    for(w=0;w<G.vexnum;w++)
						if(*(final+w)==False&&(*(*(arcs+v)+w)).last>-1)
						{
							t=p[w].next;
                            q=&p[w];
                            s=p[v].next;
                            while(s!=NULL)
							{
								r=(Node *)malloc(sizeof(Node));
                                r->adjvex=s->adjvex;
                                r->route=s->route;
                                q->next=r;
                                q=r;
                                s=s->next;
							}
                            r=(Node *)malloc(sizeof(Node));
                            r->adjvex=w;
                            r->route=route;
                            r->next=NULL;
                            q->next=r;
                            TimeTreeDispose(&p[w],arcs);                        if(*(*(T+w)+0)>TTime[0]||(*(*(T+w)+0)==TTime[0]&&*(*(T+w)+1)>TTime[1]))
							{
								*(*(T+w)+0)=TTime[0];
                                *(*(T+w)+1)=TTime[1];
                                while(t!=NULL)
								{
									q=t;
                                    t=t->next;
                                    free(q);
								}
							}
                            else
							{
								q=p[w].next;
                                while(q!=NULL)
								{
									r=q;
                                    q=q->next;
                                    free(r);
								}
                                p[w].next=t;
							} 
						} 
				} 
	} 
    for(v=0;v<G.vexnum;v++)
	{
		q=p[v].next;
        while(q!=NULL)
		{
			s=q;
            q=q->next;
            free(s);
		}
        p[v].next=NULL;
	}
    free(p);
    if(k==1)
		printf("\nCan't find train from %s to %s\n\n",G.vertices[v0].cityname,G.vertices[v1].cityname);
    else
        printf("\nCan't find flight from %s to %s\n\n",G.vertices[v0].cityname,G.vertices[v1].cityname);
}
void PrintGraph(ALGraph *G)
{
	int i,j,k;
    ArcNode *q;
    system("cls"); 
    printf("\n\n\n\n\n\n\n\n                     Please choose option:\n");
    printf("                     *************************************\n");
    printf("                     **          0=Show City            **\n");
    printf("                     **          1=Show Flight          **\n");
    printf("                     **          2=Show Train           **\n");
    printf("                     **          3=Previous Menu        **\n");
    printf("                     *************************************\n");
    printf("                                  Choose?");
    scanf("%d",&i);
    getchar();
    while(i!=3)
	{
		switch(i)
		{
		case 0:system("cls");
			printf("\nCity:\n");
			for(j=0;j<G->vexnum;j++)
            printf("%s  ",G->vertices[j].cityname);
            printf("\n");
            break;
        case 1:system("cls");
            printf("\nFlight:\n");
            for(j=0;j<G->vexnum;j++)
			{
				q=G->vertices[j].planefirstarc;
                while(q!=NULL)
				{
					printf("%s---->%s\n",G->vertices[j].cityname,G->vertices[q->adjvex].cityname);
                    for(k=0;k<=q->info.last;k++)
						printf("     number:%d  expenditure:%5.2f begintime:%d:%d  arrivetime:%d:%d\n",q->info.stata[k].number,q->info.stata[k].expenditure,q->info.stata[k].begintime[0],q->info.stata[k].begintime[1],q->info.stata[k].arrivetime[0],q->info.stata[k].arrivetime[1]);
                    q=q->nextarc;
				} 
			}
			break;
        case 2:system("cls");
            printf("\nTrain:\n");
            for(j=0;j<G->vexnum;j++)
			{
				q=G->vertices[j].trainfirstarc;
                while(q!=NULL)
				{
					printf("%s---->%s\n",G->vertices[j].cityname,G->vertices[q->adjvex].cityname);
                    for(k=0;k<=q->info.last;k++)
						printf("     number:%d  expenditure:%5.2f begintime:%d:%d  arrivetime:%d:%d\n",q->info.stata[k].number,q->info.stata[k].expenditure,q->info.stata[k].begintime[0],q->info.stata[k].begintime[1],q->info.stata[k].arrivetime[0],q->info.stata[k].arrivetime[1]);
                    q=q->nextarc;
				}
			} 
            break;
		}
        printf("Press any key to continue……");
        getch();
        system("cls"); 
		printf("\n\n\n\n\n\n\n\n                     Please choose option:\n");
		printf("                     *************************************\n");
		printf("                     **          0=Show City            **\n");
		printf("                     **          1=Show Flight          **\n");
		printf("                     **          2=Show Train           **\n");
		printf("                     **          3=Previous Menu        **\n");
		printf("                     *************************************\n");
       scanf("%d",&i);
       getchar();
	}
}

