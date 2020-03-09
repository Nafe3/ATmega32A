#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SWITCH_INTERFACE.h"
#include "SWITCH_PRIVATE.h"
#include "SWITCH_CONFIG.h"


u8 getSwitchState  (void)
{
	u8 result = getPinValue(SWITCH_PORT, SWITCH_PIN);
	
	#if RELEASE_STATE == 0
		return result;
	#else
		return result^1;
	#endif
}