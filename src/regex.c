    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<stdbool.h>
    #include"regex.h"
    #define BUFF_SIZE 1024
    #include<assert.h>
    #include "test.c"
    int matchdigit(char *regexp,FILE *text)
    {
        bool match=false;
        char ch[sizeof(*text)];
        bool matchdigit=false;
        while (fgets(ch,sizeof(ch),text)!=NULL)
        {
            for(int j=0;j<strlen(ch);j++)
            {
            if(ch[j]>='0' && ch[j]<='9')
            {
                match=true;
                printf("%s",ch);
                break;
            }
                printf("\n");
            }

        }
        fclose(text);
        if(match==false)
        {
            printf("No match found");
        }
       return 1;
    }
    int matchallexpr(char *regexp,FILE *text)
    {
        printf("%s","hello");
        bool match=false;
        char ch[sizeof(*text)];
        while (fgets(ch,sizeof(ch),text)!=NULL)
        {
            match=true;
            printf("%s",ch);
        }
        fclose(text);
        if(match==false)
        {
            printf("No match found");
        }
        return 1;
    }
    int matchchar(char *regexp,FILE *text)
    {
        char ch[sizeof(*text)];
        bool match=false;
        while (fgets(ch,sizeof(ch),text)!=NULL)
        {
            if(strstr(ch,regexp))
            {
                match=true;
                printf("%s",ch);
            }
        }
        fclose(text);
        if(match==false)
        {
            printf("No match found");
        }
        return 1;
    }
    int matchbeg(char *regexp,FILE *text)
    {
        char ch[sizeof(*text)];
        bool match=false;
        while (fgets(ch,sizeof(ch),text)!=NULL)
        {
            if(strstr(ch,regexp))
            {
                match=true;
                printf("%s",ch);
            }
        }
        fclose(text);
        if(match==false)
        {
            printf("No match found");
        }
        return 1;
    }
    void match(char *regexp,FILE *text)
    {

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

    void execute(char **tokens)
    {
       int last_index=0;
       while(tokens[last_index]!= NULL)
       {
           last_index++;
       }
       last_index--;
       if(strcmp(tokens[0],"grp")!=0)
       {
        printf("%s","No grp found");
        return;
       }

       else if(strstr(tokens[last_index],".txt"))
       {
        FILE *ptr;
        ptr=fopen(tokens[last_index],"r");
        if(!ptr)
        {
            perror("Problem executing file");
            printf("%s","No file found");
            return;
        }
        match(tokens[1],ptr);
       }
    }
    char** splitline(char *line)
    {
    char *tokens;
    char **tok;
    int pos=0;
    int bfsize=BUFF_SIZE;
    tok=malloc(sizeof(line)*bfsize);
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
            tok=realloc(tok,sizeof(line)*bfsize);
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
    tok[pos]='\0';
    return tok;
    }

    char* readline()
    {
    int position=0;
    char *line;
    int c;
    int bfsize=BUFF_SIZE;
    line=(char*)malloc(sizeof(char)* bfsize);
    if(!line)
    {
        printf("%s","Allocation unsuccesfull");
        return NULL;
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

    line[position]='\0';
    return line;
    }

    int main()
    {
    char *line;
    char **tokens;
    line=readline();
    tokens=splitline(line);
    execute(tokens);
    /*test_beg();
    test_digit();
    test_beg();
    test_char();*/
    return 0;
    }
