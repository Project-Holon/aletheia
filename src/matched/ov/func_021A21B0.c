/*
 * function: WEATHER_TASK_GetPhase
 * address:  0x021A21B0
 * packet:   pkt_021A21B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to WEATHER_TASK_GetStagePhase with no argument change.
 *
 * symbols:
 *   WEATHER_TASK_GetStagePhase  0x021A273C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 WEATHER_TASK_GetStagePhase(u8 *p);

int WEATHER_TASK_GetPhase(u8 *a0)
{
    return WEATHER_TASK_GetStagePhase(a0);
}
