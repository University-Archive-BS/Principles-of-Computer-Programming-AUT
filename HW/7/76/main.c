#include <stdio.h>
#include<stdlib.h>
#include<time.h>

FILE *doc;
int cnt = 0;
int str[100];

struct time
{
    int sec;
    int min;
    int hour;
}p, *data;

int cmp (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
    data = (struct time *)calloc(100, sizeof(struct time));
    doc = fopen("input address", "rb");

    int i = 0, j=0;
    while (1)
    {
        fread(&p.sec, sizeof(int), 1, doc);
        fread(&p.min, sizeof(int), 1, doc);
        fread(&p.hour, sizeof(int), 1, doc);

        if (feof(doc)) break;

        data[i].sec = p.sec;
        data[i].min = p.min;
        data[i].hour = p.hour;

        str[i] = data[i].sec + data[i].min * 60 + data[i].hour * 3600  ;

        i++;
        cnt++;
    }

    qsort(str, cnt, sizeof(int), cmp);

    fclose(doc);
    doc = fopen("input address", "wb");

    i=0;
    while(j<cnt)
    {
        while(i<cnt)
        {
            if (str[j] == data[i].sec + data[i].min * 60 + data[i].hour * 3600 )
            {
                fwrite(&data[i].sec, sizeof(int), 1, doc);
                fwrite(&data[i].min, sizeof(int), 1, doc);
                fwrite(&data[i].hour, sizeof(int), 1, doc);
            }
            i++;
        }
        j++;
    }

    fclose(doc);
    return 0;
}
