/*
 * function: func_021DBEE4
 * address: 0x021DBEE4
 * packet: pkt_ov121_021DBEE4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020437AC 0x020437AC arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj13958.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj020437AC; extern void func_020437AC(struct Obj020437AC *);
extern void func_02082BCC(void *,int,int);
void func_021DBEE4(u32 p) { if (((struct Obj13958 *)p)->f0) { func_020437AC(*(struct Obj020437AC * *)&((struct Obj13958 *)p)->fD0); func_02082BCC((void *)p,0,220); } }
