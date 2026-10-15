/*
 * function: MUSICAL_MCSS_TickAnim
 * address:  0x021F51E8
 * packet:   pkt_ov112_021F51E8
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MUSICAL_MCSS_TickMCAnim  0x021F5678  thumb  ov112
 */
#include "../include/Obj22534.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void MUSICAL_MCSS_TickMCAnim(char *p);
void MUSICAL_MCSS_TickAnim(u8 *p) { MUSICAL_MCSS_TickMCAnim((char *)(((struct Obj22534 *)p)->f4)); }
