/*
 * function: func_021D6530
 * address: 0x021D6530
 * packet: pkt_ov120_021D6530
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding follows.
 * symbols:
 *   func_0204A648 0x0204A648 arm
 *   func_02040618 0x02040618 arm
 */
#include "../include/Obj08078.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204A648(void);
extern void func_02040618(u32,u32,u32);
void func_021D6530(void *unused,u8 *p){func_0204A648();if(((struct Obj08078 *)p)->f100){func_02040618(4,3,((struct Obj08078 *)p)->f104+72);func_02040618(6,3,((struct Obj08078 *)p)->f104+72);((struct Obj08078 *)p)->f100=0;}}
