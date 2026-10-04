/*
 * function: func_021DB258
 * address: 0x021DB258
 * packet: pkt_ov175_021DB258
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj14338.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
extern void func_02082D44(const void *,void *,int);
void func_021DB258(int index,int unused,const void *src,u8 *p,int owner) { if(owner==(int)func_020399A8() && index!=func_0203D1A4((struct Link *)((int)func_020399A8()))) { func_02082D44(src,*(u8 * *)&((struct Obj14338 *)p)->f1464+0x6c,0x68); ((struct Obj14338 *)p)->f138=1; } }
