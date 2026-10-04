/*
 * function: func_021FED6C
 * address: 0x021FED6C
 * packet: pkt_ov135_021FED6C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F99F0 0x021F99F0 thumb ov135
 *   func_021FF570 0x021FF570 thumb ov135
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021F8098 0x021F8098 thumb ov135
 */
#include "../include/Obj02861.h"
typedef unsigned short u16;
extern int func_021F99F0(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void func_021FF570(u32 v);
extern void func_0201F7A8(void *, unsigned);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021F8098(void *, void *, int, int, unsigned, int, u16, void *);
int func_021FED6C(char *p)
{
    unsigned r;
    void *w;
    r = func_021F99F0(((struct Obj02861 *)p)->fDE4);
    switch (r) {
    case -2:
        func_021FF570(0);
        func_0201F7A8(((struct Obj02861 *)p)->fD40, 0);
        w = ((struct Obj02861 *)p)->fD40;
        func_02045334(w);
        func_02045374(w);
        func_020409B4(func_02045730(w));
        ((struct Obj02861 *)p)->f28 = 0;
        break;
    case 0:
    case 1:
    case 2:
        func_021FF570(0);
        ((struct Obj02861 *)p)->fB58 = r + 1;
        ((struct Obj02861 *)p)->f28 = 0;
        func_02043B5C(func_02045770(((struct Obj02861 *)p)->fD9C), 0);
        func_021F8098(((struct Obj02861 *)p)->fD9C, ((struct Obj02861 *)p)->fB6C, ((struct Obj02861 *)p)->fB58, 1, 0, 0, 0x3c40, p + 0xfa0);
        break;
    }
    return 2;
}
