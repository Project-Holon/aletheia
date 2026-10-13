/*
 * function: func_021FB5B8
 * address: 0x021FB5B8
 * packet: pkt_ov186_021FB5B8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorBgPriority 0x0204B864 arm
 */
#include "../include/Obj24827.h"
extern unsigned CLACT_GetActorBgPriority(unsigned char *);
unsigned func_021FB5B8(char *p) { return CLACT_GetActorBgPriority(*(unsigned char * *)&((struct Obj24827 *)p)->f0); }
