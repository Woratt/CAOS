#include <stdio.h>
#include <unistd.h>

enum {
    PERCENT = 5,
    LEN = 100 / PERCENT,
};

void print(unsigned p)
{
    int p_ = p / PERCENT;
    
    printf("\r[");
 
    for(int i = 0; i < p_; ++i){
        printf("-");
    }

    printf(">");

    for(int i = p_; i < LEN; ++i){
        printf(" ");
    }

    printf("]%4u%%", p);

    fflush(stdout);
}


int main()
{
    for(int i = 0; i <= LEN; ++i){
        print(i*PERCENT);
        sleep(1);
    }
    return 0;
}

