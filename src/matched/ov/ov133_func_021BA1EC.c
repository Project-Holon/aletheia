/*
 * function: DUP_FITTING_ITEM_FreeElemImage
 * address: 0x021BA1EC
 * packet: pkt_ov133_021BA1EC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MUSICAL_MCSS_FreeElemImage 0x021F4D74 thumb ov112
 */
#include "../include/Obj14158.h"
#include "../include/Obj14159.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MUSICAL_MCSS_FreeElemImage(u8*,u8*,int,u16);
void DUP_FITTING_ITEM_FreeElemImage(u8*p,u8*q,u8*r){*(u8* *)&((struct Obj14158 *)p)->f4=r;MUSICAL_MCSS_FreeElemImage(q,*(u8* *)&((struct Obj14158 *)p)->fC,((struct Obj14159 *)r)->f0,((struct Obj14159 *)r)->f4);}
