/*
 * function: WEATHER_TASK_IsFogIdle
 * address:  0x021A23B0
 * packet:   pkt_021A23B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_FOG_FADE_IsFade  0x021A0244  thumb  ov021
 *   WEATHER_TASK_HasFogChange  0x021A2CF8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18002.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FIELD_FOG_FADE_IsFade(u8 *p);
extern u8 WEATHER_TASK_HasFogChange(char *p);

int WEATHER_TASK_IsFogIdle(u32 a)
{
if (FIELD_FOG_FADE_IsFade((u8 *)(((struct Obj18002 *)((u8 *)(a)))->f4)) != 0) {
    return 0;
}
if (WEATHER_TASK_HasFogChange((char *)a) == 0) {
    return 1;
}
return 0;
}

