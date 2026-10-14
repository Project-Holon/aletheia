/*
 * function: func_021E24C4
 * address: 0x021E24C4
 * packet: pkt_ov183_021E24C4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are alignment padding.
 * symbols:
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj24668.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void BR_UTIL_Delete(u8 *p);
extern void BR_RES_ApplyBgSet(int,unsigned);
extern void func_020409B4(u32 index);
void func_021E24C4(char *p,char *q){int i;for(i=0;i<2;i++){if(*(void **)(p+i*4+12)){BR_UTIL_Delete(*(void **)(p+i*4+12));*(void **)(p+i*4+12)=0;}}func_020409B4(4);BR_RES_ApplyBgSet(((struct Obj24668 *)q)->fC,30);}
