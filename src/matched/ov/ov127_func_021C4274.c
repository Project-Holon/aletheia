/*
 * function: WIFI_2DCHAR_SetActorAnimIndex
 * address: 0x021C4274
 * packet: pkt_ov127_021C4274
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 */
#include "../include/Obj23020.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
/* Callee and its forwarding target read only r0/r1; legacy r2/r3 inputs are unused. */
extern void CLACT_SetActorAnimIndex(int a0, int a1);
void WIFI_2DCHAR_SetActorAnimIndex(char *p,u32 a) { CLACT_SetActorAnimIndex(((struct Obj23020 *)p)->f4,a); }
