/*
 * function: func_021D5B98
 * address:  0x021D5B98
 * packet:   pkt_ov118_021D5B98
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_NEGO_PlaySeByKeyA  0x021DFA60  thumb  ov119
 *   func_021D5BB8  0x021D5BB8  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22679.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_NEGO_PlaySeByKeyA(u32 key);
extern void func_021D5BB8(u8 *p);

void func_021D5B98(u8 *p)
{
    POKETRADE_NEGO_PlaySeByKeyA(((struct Obj22679 *)p)->fF2C);
    POKETRADE_PROC_SetStep(p, (int)func_021D5BB8);
}
