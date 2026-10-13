/*
 * function: func_021F6CC0
 * address: 0x021F6CC0
 * packet: pkt_ov215_021F6CC0
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: sole overlay blocker of 021F67E0; tail-call pool ends at 021F6CCC.
 * symbols:
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 */
#include "../include/Obj25761.h"
extern void MCSS_SetVanishFlag(void *);
void func_021F6CC0(char *p){MCSS_SetVanishFlag(((struct Obj25761 *)p)->f34);}
