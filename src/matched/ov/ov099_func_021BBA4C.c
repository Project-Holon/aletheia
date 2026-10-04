/*
 * function: func_021BBA4C
 * address: 0x021BBA4C
 * packet: pkt_ov099_021BBA4C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: binding the window address before the gender-zero call preserves its separate hoist and call site; form/gender declaration order fixes their spills.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj01245.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *,int,u16,int);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020456F8(struct Descriptor *d);
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *,u32);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_02041B6C(u32);
void func_021BBA4C(char *p,void *party)
{
    void *s,*t,*mon;
    int n,i,off;
    u32 species,gender,name,form;
    void **w;
    void *win;
    if (((struct Obj01245 *)p)->f1A0==0)
        ((struct Obj01245 *)p)->f1A0=(void *)func_020450F0(2,1,5,30,6,15,1);
    func_0201F73C(((struct Obj01245 *)p)->f1A0,2,((struct Obj01245 *)p)->f1334,14);
    s=func_020457B0(0x40,0x21);
    t=func_020457B0(0x40,0x21);
    func_02043B5C(func_02045770(((struct Obj01245 *)p)->f1A0),255);
    func_020456F8(((struct Obj01245 *)p)->f1A0);
    n=func_0201AA18(party);
    for (i=0;i<n;i++) {
        mon=func_0201AB28(party,i);
        if (func_02017E1C(mon,0x4c,0)==0) {
            species=func_02017E1C(mon,0,0);
            form=func_02017E1C(mon,0xad,0);
            name=func_02017E1C(mon,0x9e,0);
            gender=func_02017E1C(mon,0x6e,0);
            func_02045CAC(((struct Obj01245 *)p)->fE0,0x74,t);
            func_0201EFA4(((struct Obj01245 *)p)->fDC,0,name,3,0,1);
            func_0201F250(((struct Obj01245 *)p)->fDC,s,t);
            off=i*40;
            func_0201C7A4(func_02045770(((struct Obj01245 *)p)->f1A0),off+1,32,s,((struct Obj01245 *)p)->fEC);
            if (gender!=2 && ((species!=0x1d && species!=0x20) || form!=0)) {
                if (gender==0) {
                    w=(void **)(p+0x1a0);
                    func_02045CAC(((struct Obj01245 *)p)->fE0,0x75,t);
                    win=*w;
                } else {
                    func_02045CAC(((struct Obj01245 *)p)->fE0,0x76,t);
                    win=((struct Obj01245 *)p)->f1A0;
                }
                func_0201C7A4(func_02045770(win),off+30,16,t,((struct Obj01245 *)p)->fE8);
            }
        }
    }
    func_02045808(s);
    func_02045808(t);
    func_02045374(((struct Obj01245 *)p)->f1A0);
    func_02045334(((struct Obj01245 *)p)->f1A0);
    func_02041B6C(2);
}
