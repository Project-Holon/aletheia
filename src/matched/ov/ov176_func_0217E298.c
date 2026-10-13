/*
 * function: func_0217E298
 * address: 0x0217E298
 * packet: pkt_ov176_0217E298
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj14369.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int POKE_REGULATION_GetDataSize(void);
extern void func_02082D44(void *,const void *,u32);
int func_0217E298(u8 *p,const void *q) {int v;v=((struct Obj14369 *)p)->f100C;if(v) {((struct Obj14369 *)p)->f100C=0;func_02082D44(p+6,q,POKE_REGULATION_GetDataSize());}return v;}
