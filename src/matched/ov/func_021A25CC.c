/*
 * function: WEATHER_TASK_StopSe
 * address:  0x021A25CC
 * packet:   pkt_021A25CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with the object displaced by 0x40 and the word at +0xc.
 *
 * symbols:
 *   WEATHER_TASK_StopSound  0x021A2C6C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18003.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void WEATHER_TASK_StopSound(u8 *p, u32 v);

void WEATHER_TASK_StopSe(u8 *p)
{
    WEATHER_TASK_StopSound(p + 0x40, ((struct Obj18003 *)p)->fC);
}
