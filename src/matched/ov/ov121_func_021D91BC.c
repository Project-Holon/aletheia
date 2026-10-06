/*
 * function: func_021D91BC
 * address: 0x021D91BC
 * packet: pkt_ov121_021D91BC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021D6C58 0x021D6C58 thumb ov121
 *   func_0204B53C 0x0204B53C arm
 *   func_02005728 0x02005728 thumb
 */
#include "../include/Obj06447.h"
#include "../include/Obj13941.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_02082BCC(void *,int,int);
typedef unsigned int   u32;
extern void *func_021D6C58(u8 *p, int i);
struct Actor;
struct Pt;
extern void func_0204B53C(const struct Actor *actor, struct Pt *out);
extern u32 func_02005728(u32 range);
void func_021D91BC(u8 *p,void *q,u16 h)
{
    int i;
    u8 *r;
    s16 xy[2];
    func_02082BCC(p,0,296);
    ((struct Obj06447 *)p)->f10=-819;
    ((struct Obj06447 *)p)->f118=q;
    ((struct Obj06447 *)p)->f14=-819;
    ((struct Obj06447 *)p)->f124=h;
    for(i=0;i<32;i++) {
        func_0204B53C(func_021D6C58(((struct Obj06447 *)p)->f118,i+1),(struct Pt *)xy);
        r=p+i*4;
        ((struct Obj13941 *)r)->f18=xy[1]<<12;
        ((struct Obj13941 *)r)->f98=func_02005728(4096)+6554;
    }
}
