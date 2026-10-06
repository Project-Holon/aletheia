/*
 * function: func_021D8EC4
 * address: 0x021D8EC4
 * packet: pkt_ov123_021D8EC4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02009294 0x02009294 thumb
 *   func_020092F8 0x020092F8 thumb
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8E98 0x021D8E98 thumb ov123
 */
#include "../include/Obj01545.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int   u32;
struct Mon;
struct Sub020079BCEntry;
struct Sub02009210Obj;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern void func_020307B0(void *);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void func_02009294(struct Sub02009210Obj *obj, const void *src);
extern void func_02007664(void *save, u32 box, u32 slot);
extern void func_020092F8(struct Sub02009210Obj *obj, u8 value);
extern void func_021D62B4(u8 *p, unsigned int i);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D8E98(char *p);
void func_021D8EC4(char *p)
{
    void *v;
    void *q;
    void *t;
    v=func_02009448(((struct Obj01545 *)p)->f28);
    if (((struct Obj01545 *)p)->fC) {
        func_020307B0(((struct Obj01545 *)p)->fC);
        ((struct Obj01545 *)p)->fC=0;
    }
    t=func_02007A18(((struct Obj01545 *)p)->f24,((struct Obj01545 *)p)->f48,((struct Obj01545 *)p)->f4C);
    if (t) {
        q=func_0201747C(t,((struct Obj01545 *)p)->f0);
        func_02009294(v,q);
        ((struct Obj01545 *)p)->fC=q;
        func_02007664(((struct Obj01545 *)p)->f24,((struct Obj01545 *)p)->f48,((struct Obj01545 *)p)->f4C);
        func_020092F8(v,1);
        ((struct Obj01545 *)p)->fAA=1;
    }
    func_021D62B4(((struct Obj01545 *)p)->f14,0);
    func_021D62B4(((struct Obj01545 *)p)->f14,12);
    func_021D6EE0((u8 *)p,(int)func_021D8E98,0xa2a);
}
