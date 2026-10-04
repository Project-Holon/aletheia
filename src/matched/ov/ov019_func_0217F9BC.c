/*
 * function: func_0217F9BC
 * address: 0x0217F9BC
 * packet: pkt_ov019_0217F9BC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020470D0 0x020470D0 arm
 *   func_02046EFC 0x02046EFC arm
 */
#include "../include/Obj05958.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Tagged;
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
void func_0217F9BC(char *p) { func_020470D0(((struct Obj05958 *)p)->f14); func_02046EFC(((struct Obj05958 *)p)->f18); ((struct Obj05958 *)p)->f18=0; func_02046EFC(((struct Obj05958 *)p)->f14); ((struct Obj05958 *)p)->f14=0; }
