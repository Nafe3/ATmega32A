// libs
#include "STD_TYPES.h"
#include "BIT_MAN.h"
//MCAL
#include "DIO_interface.h"
// own
#include "Switch_interface.h"
#include "Switch_private.h"
#include "Switch_config.h"

u8 getSWstate(u8 sw)
{
   #if SW_MODE == 1 /* output = 1 */
    if (sw == 1)
    {
  	  return getPinVal(SW1_PORT, SW1_PIN);
    }
    else if (sw == 2)
    {
  	  return getPinVal(SW2_PORT, SW2_PIN);
    }
    else
    {
    	return 0;
    }
   #else
      if (sw == 1)
      {
    	  return !getPinVal(SW1_PORT, SW1_PIN);
      }
      else if (sw == 2)
      {
    	  return !getPinVal(SW2_PORT, SW2_PIN);
      }
      else
      {
      	return 0;
      }
   #endif
}
