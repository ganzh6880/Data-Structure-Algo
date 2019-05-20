#include<stdio.h>
#define maxV 100

int V=7,E,x,y,i,j;
int a[maxV][maxV];
int visit[maxV];
int count,compo,temp,cycles = 0;
int comp[maxV][maxV];
int parent[maxV];
int bedge[maxV][maxV];
int tredge[maxV][maxV];

void read_graph(void);
void print_graph(void);
void dfs(int i);
void component(void);
void tree_edges(void);
void back_edges(void);
void cycle(void);


void main(){
  read_graph();
  print_graph();
   for(i=1;i<=V;i++){
        visit[i]=0;
   }
   for(i=1;i<=V;i++) {
        if(visit[i] == 0){
            compo+=1;
            dfs(i);
        }
     }
component();
tree_edges();
back_edges();
cycle();
}

void dfs(int i){
    count+=1;
    int k;
    visit[i]=1;
    comp[compo][i]=i;
    if (parent[i])
        printf("\n%d th = Vertices %d,\t[Parent = Vertices %d]", count, i,parent[i]);
    else
        printf("\n%d th = Vertices %d,\t[No parent]", count, i);
    for(k=1;k<=V;k++){
            if(a[i][k] == 1 && visit[k] == 0){
                parent[k]=i;
                tredge[i][k]=1;
                tredge[k][i]=1;
                dfs(k);
    }
  }
}


void read_graph(void){
    int edge, x;
    if(V>maxV)
        printf("Exceed the maximum number of vertices.\n");
    else{
        for(x=1;x<=V;x++)
            for(y=1;y<=V;y++)
                a[x][y]=0;
                tredge[x][y]=0;
        a[1][2]=a[1][3]=a[2][1]=a[2][3]=a[3][1]=a[3][2]=a[3][4]=a[4][3]=a[5][6]=a[5][7]=a[6][5]=a[6][7]=a[7][5]=a[7][6]=a[1][6]=a[3][7]=a[6][1]=a[7][3]=1;
        }
}

void print_graph(void){
    int x,y;
    for(x=1;x<=V;x++){
        printf("\n");
        printf("%d\t",x);
        for(y=1;y<=V;y++)
            printf("%d\t",a[x][y]);
    }
    printf("\n");

}

void component(void){
    int j,y;
for(j=1;j<=compo;j++){
   printf("\n\nComponent: %d\n",j);
   for(y=1;y<=V;y++){
        printf("Vertices %d\n",comp[j][y]);
    }
  }
}

void tree_edges(void){
int g,h;

for(g=1;g<=V;g++){
        printf("\n");
        printf("%d\t",g);
        for(h=1;h<=V;h++)
            printf("%d\t",tredge[g][h]);
    }
printf("\n");
}

void back_edges(void){
int k,l;
for(k=1;k<=V;k++){
        printf("\n");
        printf("%d\t",k);
        for(l=1;l<=V;l++){
            bedge[k][l]=a[k][l]-tredge[k][l];
            printf("%d\t",bedge[k][l]);
        }
    }
    printf("\n");
}

void cycle(void){
    int k,l;
for(k=1;k<=V;k++){
        for(l=1;l<=V;l++){
            if(bedge[k][l] == 1)
                cycles+=1;
        }
    }
   if(!cycle)
    printf("\nThere is no cycle in the graph\n");
   else
    printf("There is %d cycles in the graph.\n",cycles/2);
}

