/*
 * function: func_021D8FE4
 * address: 0x021D8FE4
 * packet: pkt_ov119_021D8FE4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_020173EC 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj10353.h"
typedef unsigned char u8;
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D1A4(int);
typedef unsigned int   u32;
extern u32 func_020173EC(void);
extern void func_02082D44(void *,void *,int);
void func_021D8FE4(int idx,int a,int b,void *p,int id) {
 if(id==(int)func_020399A8()) {
 int n=func_020173EC();
 func_02082D44(*(void **)((char *)p+idx*4+0x1064),*(void **)((char *)p+idx*4+0x5dc),n);
 if(idx!=func_0203D1A4((int)func_020399A8())) {
 ((struct Obj10353 *)p)->fF9C=idx+1;
 ((struct Obj10353 *)p)->f11FB=(((struct Obj10353 *)p)->f11FB&~0xf0)|0x10;
 }
 }
}
