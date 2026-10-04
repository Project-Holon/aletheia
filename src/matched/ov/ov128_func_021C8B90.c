/*
 * function: func_021C8B90
 * address: 0x021C8B90
 * packet: pkt_ov128_021C8B90
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   d_021CA6C8 0x021CA6C8 data a2
 */
#include "../include/Obj05382.h"
#include "../include/Obj14043.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {s16 x,y,z;u8 a,b;} Point;
extern const s16 d_021CA6C8[][5];
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
void func_021C8B90(char *p,char *q,int unused,int i,u16 h) {
 Point pt;
 pt.x=(((struct Obj14043 *)p)->f0+d_021CA6C8[i][0])*8+16;
 pt.y=(((struct Obj14043 *)p)->f2+d_021CA6C8[i][1])*8+16;
 pt.z=0;pt.a=8;pt.b=1;
 *(void **)(p+44+i*4)=func_0204B294((void *)((struct Obj05382 *)q)->f13C,((struct Obj05382 *)q)->f144,((struct Obj05382 *)q)->f14C,((struct Obj05382 *)q)->f154,&pt,0,h);
}
