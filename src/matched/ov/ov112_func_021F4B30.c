/*
 * function: MUSICAL_MCSS_GetFlagB
 * address:  0x021F4B30
 * packet:   pkt_ov112_021F4B30
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MUSICAL_MCSS_GetStateB  0x021F50E0  thumb  ov112
 */
#include "../include/Obj22522.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int MUSICAL_MCSS_GetStateB(const unsigned char *p);
int MUSICAL_MCSS_GetFlagB(u8 *p) { return MUSICAL_MCSS_GetStateB((const unsigned char *)(((struct Obj22522 *)p)->f20)); }
