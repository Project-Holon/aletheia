/*
 * function: func_021BAE00
 * address: 0x021BAE00
 * packet: pkt_ov223_021BAE00
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   table 0x021BC770 data a1
 *   func_02049B40 0x02049B40 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0203101C 0x0203101C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj00739.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct MsgBank;struct Tcbl;struct Descriptor;struct CharBuf;
typedef struct {u8 a,b,c,d,e,f,g,h,i;} Entry;
extern const Entry table[];
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern struct Tcbl *func_0203101C(u32,u16,u32,u32);
extern void func_0201DD78(u32,u32,u32);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_02045334(struct Descriptor *);
void func_021BAE00(char *p)
{
    u8 i=0;
    func_02049B40(23,5,0,448,32,((struct Obj00739 *)p)->f0);
    func_02049B40(23,5,4,32,32,((struct Obj00739 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00739 *)p)->f234=func_02045B38(0,3,430,((struct Obj00739 *)p)->f0);
    *(struct Tcbl * *)&((struct Obj00739 *)p)->f254=func_0203101C(((struct Obj00739 *)p)->f0,((struct Obj00739 *)p)->f0,1,0);
    func_0201DD78(15,2,0);
    for(;i<3;i++) {
        *(u32 *)(p+i*4+568)=func_020450F0(table[i].a,table[i].b,table[i].c,table[i].d,table[i].e,table[i].f,table[i].g);
        func_02043B5C(func_02045770(*(struct Descriptor **)(p+i*4+568)),0);
        func_02045334(*(struct Descriptor **)(p+i*4+568));
        *(u32 *)(p+i*4+580)=1;
    }
    ((struct Obj00739 *)p)->f250=0;((struct Obj00739 *)p)->f258=0;
}
