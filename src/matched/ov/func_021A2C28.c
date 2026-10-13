/*
 * function: WEATHER_TASK_GetParticleActorPtr
 * address:  0x021A2C28
 * packet:   pkt_021A2C28
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x4 of the object.
 */
#include "../include/Obj18005.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 WEATHER_TASK_GetParticleActorPtr(u8 *p)
{
    return ((struct Obj18005 *)p)->f4;
}

