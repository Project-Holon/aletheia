/*
 * function: DUP_FITTING_ITEM_DeleteElem
 * address: 0x021BA1D8
 * packet: pkt_ov133_021BA1D8
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_FreeElem 0x021F4D40 thumb ov112
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj23329.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MUSICAL_MCSS_FreeElem(u8*,u8*);
extern u32 func_020307B0(void *p);
void DUP_FITTING_ITEM_DeleteElem(u8*p,u8*q){MUSICAL_MCSS_FreeElem(q,*(u8* *)&((struct Obj23329 *)p)->fC);func_020307B0(p);}
