/*
 * function: func_021C428C
 * address: 0x021C428C
 * packet: pkt_ov127_021C428C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   func_0204B528 0x0204B528 arm
 */
#include "../include/Obj14016.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Pt { u16 x,y; } Pt;
struct Actor;
extern void func_0204B528(struct Actor *actor, const struct Pt *src);
void func_021C428C(char *p,int x,int y) { Pt pt; if(((struct Obj14016 *)p)->f8) { pt.x=x+8; pt.y=y+14; func_0204B528(((struct Obj14016 *)p)->f8,&pt); } }
