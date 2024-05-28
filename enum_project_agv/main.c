/*
 */

#include <avr/io.h>
#define start_knop
#define stop_knop
#define volg_knop
#define relay_knop
#define infralinks
#define infrarechts
#define ultrasoonvoor
#define infravoor
#define Lswitch
#define Rswitch
enum AGV {start,rechtdoorbeide,rechtdoorlinks,rechtdoorrechts,links,rechts,noodstop,volgen,stopknop,boomstop,reset};
//hey

 int init(void)
    {
	int LOM = 0;
	int ROM = 0;
	static int LMOTOR = tel waarde**
	static int RMOTOR = tel waarde**
	int UltraL = 0;
	int UltraR = 0;
    int acties;
    }
void init_input(void)

    {
    DDR &=~(1<<Lswitch);
    DDR &=~(1<<Rswitch);
    DDR &=~(1<<Start_knop);
    DDR &=~(1<<Stop_knop);

    }
int main(void)
{

// Insert code
   init_input();
   init();
    while(1)
    {

    if (PIN&(1<<relay_knop))
    {
        acties= noodstop;
    }
    if (PIN&(1<<stop_knop))
    {
        acties=reset;
    }
    switch (acties)
    {
    case start:
        if (PIN &(1<<start_knop))
        {
            if (PIN &(1<<volg_knop))
            {
                acties= volgen;
            }
            else
            {
                acties= rechtdoor;
            }
        }
        break;
    case rechtdoorbeide:
        // motor aan
         if ((1<<infralinks)==0)
         {
             MotorR(70);
         }
         else
         {
            MotorR(100);
         }
         if ((1<<infrarechts)==0)
         {
             MotorL(70);
         }
         else
         {
             MotorL(100);
         }
         if (((1<<infralinks)==0)&&((1<<infrarechts)==0))
         {
             // check waarde
             if (baan==0)
             {
                  baan+=1; //???
                 acties= links;
             }
             if (baan==1)
             {
                 baan+=1; //!!!!
                 acties= rechts;
             }
             else
             {
                 //alle ints op 0
                 acties=start;
             }

         }

         if (gemeten_tijd_ultraL<=20000)
         {
             UltraL++;
         }

         if (gemeten_tijd_ultraR<=20000)
         {
             UltraR++;
         }

         if(UltraL>=300)//???
         {
             MotorR(0);
             MotorL(0);
             UltraR=0;
             UltraL=0;
             acties=boomstop;
         }
         if (UltraR>=300)//???
         {
             MotorR(0);
             MotorL(0);
             UltraR=0;
             UltraL=0;
             acties=boomstop;
         }

        break;
    case rechtdoorlinks:
        if((1<<Lswitch) !=0)
   {

	if((1<<Lswitch) ==0)

	  {
		LOM++;
	  }
   }

if((1<<Rswitch) !=0)

   {
	if((1<<Rswitch) ==0)

	  {
		ROM++;
	  }

   }

if (LOM == (LMOTOR) && ROM ==(RMOTOR))
{

  if((infralinks=1) && (infraRechts=1)
   {
		MotorR(100);
		MotorL(100);
		LOM = 0;
		ROM = 0;
		acties = rechtdoor;
   }
  }
        break;
    case rechtdoorrechts:
         //code rechtdoorbeide repeat - ultra links
         break;
    case links:
        // bocht maken naar links
          if ((infralinks==1)&&(infrarechts==1))
          {
              acties= rechtdoor;
          }
        // naar links
        break;
    case rechts:
        //bocht maken naar rechts
        if ((infralinks==1)&&(infrarechts==1))
          {
              acties= rechtdoor;
          }
        // naar rechts
        break;

    case noodstop:
        //sta stil
        if((PIN&(1<<relay_knop))&&(PIN&(1<<startknop)))
        {
        acties=rechtdoor;
        }
        break;
    case volgen:
        if (ultrasoonvoor=/*bepaalde waarde*/)
        {
            //motor rij
            if(infravoor==1)
            {
                //motor stop
            }
            if (ultrasoonvoor=/*bepaalde waarde*/)
            {
                //motor stop
            }
        }
        break;
    case boomstop:

        break;
    case reset:
        // motoren uit
        acties= start
    }

    ;

    return 0;
}
