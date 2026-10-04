/*
 * function: func_021F4AFC
 * address: 0x021F4AFC
 * packet: pkt_ov112_021F4AFC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F4F54 0x021F4F54 thumb ov112
 *   func_021F4FF4 0x021F4FF4 thumb ov112
 */
#include "../include/Obj22519.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *func_021F4F54(u8 *,int);
extern int func_021F4FF4(u16 *,int);
int func_021F4AFC(u8 *p,int index,int mode) { return func_021F4FF4((u16 *)func_021F4F54(*(u8 * *)&((struct Obj22519 *)p)->fC,index),mode); }
