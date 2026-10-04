/*
 * function: func_021D91D8
 * address: 0x021D91D8
 * packet: pkt_ov119_021D91D8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 */
#include "../include/Obj08051.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
struct Link;
extern u32 func_0203D1A4(struct Link *p);
void func_021D91D8(int a,int b,const u8 *c,u8 *p,int e) {
 if(e==(int)func_020399A8()) {
  if(a!=func_0203D1A4((struct Link *)((int)func_020399A8()))) {
   p[0x11f2]=c[0]; p[0x11f4]=c[1];
   ((struct Obj08051 *)p)->f107E=p[0x11f2]*160+16;
  }
 }
}
