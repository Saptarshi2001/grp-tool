#include<stdio.h>
#include<assert.h>
#include "regex.h"
#include "test.h"
void tstbeg()
{
FILE *text="rockbands.txt";
char ch[sizeof(*text)]="^N";
assert(matchbeg(ch,text)==1);
printf("test has passed");
}

void tstchr()
{
FILE *text="rockbands.txt";
char ch[sizeof(*text)]="G";
assert(matchchar(ch,text)==1);
printf("test has passed");
}