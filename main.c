/*
 */

#include <avr/io.h>
#define knop1 PF2
int main(void)
{
if(knop1==0)
{
    int teller=1;
    PORTB|=(1<<PB7);
}
    // Insert code

    while(1)
    ;

    return 0;
}
