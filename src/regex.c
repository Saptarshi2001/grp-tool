#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
#include"regex.h"
#define BUFF_SIZE 1024

int matchdigit(char *regexp,FILE *text)
{
    char ch[sizeof(*text)];
    while (fgets(ch,sizeof(ch),text)!=NULL)
    {
        size_t len=strlen(ch);
        if(len>0 && ch[len-1]=='\n')
        {
            ch[--len]='\0';
        }
        for(int j=0;j<strlen(ch);j++)
        {
        if(ch[j]>='0' && ch[j]<='9')
        {
            printf("%s \n",ch);
            break;
        }
        }
    }
   return 1; 
}
int matchallexpr(char *regexp,FILE *text)
{
    printf("%s","hello");
    char ch[sizeof(*text)];
    while (fgets(ch,sizeof(ch),text)!=NULL)
    {
        printf("%s",ch);
    }
    return 1;
}
int matchchar(char *regexp,FILE *text)
{
    char ch[sizeof(*text)];
    while (fgets(ch,sizeof(ch),text)!=NULL)
    {
        if(strstr(ch,regexp))
        {
            printf("%s",ch);
        }
    }
    fclose(text);
    return 1;
}
int matchbeg(char *regexp,FILE *text)
{
    char ch[sizeof(*text)];
    while (fgets(ch,sizeof(ch),text)!=NULL)
    {
        if(ch[0]==regexp[0])
        {
            printf("%s",ch);
        }
    }
    fclose(text);
    return 1;
}
void match(char *regexp,FILE *text)
{
    char *empty="";
        if(regexp[0]=='^')
    {
        matchbeg(regexp+1,text);
    }
    if(regexp[0]>='A'&&regexp[0]<='Z' || regexp[0]>='a'&&regexp[0]<='z')
    {
        matchchar(regexp,text);
    }
    if(regexp[0]=='/' && regexp[1]=='/')
    {
        matchallexpr(regexp,text);
    }
    if(regexp[0]==':'&& regexp[1]=='d')
    {
        matchdigit(regexp,text);
    }   
}

bool contains(char *tokens)
{
    char symbol[]="^";
    char symbol1[]="\0";
    char symbol2[]=":d";
  return (strstr(tokens,symbol) ||strstr(tokens,symbol1) || strstr(tokens,symbol2));  
}
void execute(char **tokens)
{
    char extension[]=".txt";
    char *str="grp";
    char *symbol="^";
   if(strcmp(tokens[0],str)==1)
   {
    printf("%s","No grp found");
   } 
   
   else if(strstr(tokens[strlen(*tokens)-1],extension)&& contains(tokens[1]) )
   {
    FILE *ptr;
    ptr=fopen(tokens[2],"r");
    match(tokens[1],ptr);
   }
}
char** splitline(char *line)
{
char *tokens;
char **tok;
int pos=0;
int bfsize=BUFF_SIZE;
tok=malloc(sizeof(char*)*bfsize);
if(tok==NULL)
{
    printf("%s","Allocation unsuccesfull");
}
tokens=strtok(line," ");
tok[pos]=tokens;

while (tokens!=NULL)
{  
    if(pos>=bfsize)
    {
        bfsize+=BUFF_SIZE;
        tok=realloc(tok,sizeof(char*)*bfsize);
        if(tok==NULL)
        {
            printf("Reallocation unsuccessfull");
            return 0;
        }
    }
    else
    {
        tok[pos]=tokens;
        pos++;
    }
    tokens=strtok(NULL," ");
}
tok[pos]=NULL;
return tok;
}

char* readline()
{
int position=0;
char *line;
int c;
int bfsize=BUFF_SIZE;
line=(char*)malloc(sizeof(char)* bfsize);
if(line==NULL)
{
    printf("%s","Allocation unsuccesfull");
}
printf("%s","Enter the command:");
while(1)
{
c=getchar();
if(c=='\n'||c==EOF)
{
    line[position]='\0';
    break;
}
else if(position>=bfsize)
{
    bfsize+=BUFF_SIZE;
    line=realloc(line,sizeof(char)*bfsize);
    if(!line)
    {
    printf("%s","Reallocation unsuccesful");
    }
}
else
{
    line[position]=c;
    position++;
}
}
return line;
}

int main()
{
char *line;
char **tokens;
line=readline();
tokens=splitline(line);
execute(tokens);
return 0;
}