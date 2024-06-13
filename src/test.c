#include<assert.h>
#include"test.h"
#include"regex.h"
void test_beg()
{
    char *regexp1="^N";
    char *regexp2="^Nir";
    char *regexp3="^House";
    char *regexp4="^Guns";
    char *regexp5="^Babylon A.D.";
    FILE *ptr=fopen("rockbands.txt","r");
    assert(matchbeg(regexp1,ptr)==1);
    assert(matchbeg(regexp2,ptr)==1);
    assert(matchbeg(regexp3,ptr)==1);
    assert(matchbeg(regexp4,ptr)==1);
    assert(matchbeg(regexp5,ptr)==1);
    printf("test passed for beginning sequence \n");
    fclose(ptr);
}

void test_char()
{
    char *regexp1="a";
    char *regexp2="d";
    char *regexp3="e";
    char *regexp4="f";
    char *regexp5="s";
    char *regexp6="Guns";
    char *regexp7="House of lords";
    FILE *ptr=fopen("rockbands.txt","r");
    assert(matchchar(regexp1,ptr)==1);
    assert(matchchar(regexp2,ptr)==1);
    assert(matchchar(regexp3,ptr)==1);
    assert(matchchar(regexp4,ptr)==1);
    assert(matchchar(regexp5,ptr)==1);
    assert(matchchar(regexp6,ptr)==1);
    assert(matchchar(regexp7,ptr)==1);
    printf("test passed for matching characters \n");
    fclose(ptr);
}

void test_digit()
{
    char *regexp=":d";
    FILE *ptr=fopen("rockbands.txt","r");
    assert(matchdigit(regexp,ptr)==1);
    printf("test passed for digits \n");
    fclose(ptr);
}
