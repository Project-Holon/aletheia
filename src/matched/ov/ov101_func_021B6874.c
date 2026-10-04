/*
 * function: func_021B6874
 * address: 0x021B6874
 * packet: pkt_ov101_021B6874
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj22106.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u16 func_02039338(void);
extern void func_02082D44(void *,const void *,u32);
void func_021B6874(u32 a,int b,void *c,u8 *d,void *e) {
 if(e==func_020399A8()) { if(a!=func_02039338()) { func_02082D44(c,d+8,8); ((struct Obj22106 *)d)->f18=1; } }
}
