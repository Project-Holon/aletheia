/*
 * function: func_021B68C0
 * address: 0x021B68C0
 * packet: pkt_ov101_021B68C0
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 */
#include "../include/Obj22108.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u16 func_02039338(void);
void func_021B68C0(u32 a,int b,int c,u8 *d,void *e) {
 if(e==func_020399A8()) { if(a!=func_02039338()) ((struct Obj22108 *)d)->f20=1; }
}
