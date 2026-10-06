/*
 * function: func_021D4EF0
 * address: 0x021D4EF0
 * packet: pkt_ov123_021D4EF0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj02473.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
typedef signed short   s16;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *, int, int, void *, void *, void *, void *, int, u16, int);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D4EF0(char *p, int n, int flag)
{
    void *obj;
    if (((struct Obj02473 *)p)->f224 == 0)
        ((struct Obj02473 *)p)->f224 = (void *)func_020450F0(5, 1, 3, 30, (u8)n, 13, 1);
    obj = ((struct Obj02473 *)p)->f224;
    func_02043B5C(func_02045770(obj), 15);
    func_0201DD78(1, 2, 15);
    if (flag) {
        void *value;
        value = (void *)func_02012FFC();
        ((struct Obj02473 *)p)->f228 = func_0201CCE4(obj, 0, 0, ((struct Obj02473 *)p)->f38, ((struct Obj02473 *)p)->f30, value, ((struct Obj02473 *)p)->f230, 2, ((struct Obj02473 *)p)->fC, 15);
    } else {
        func_0201C7A4(func_02045770(obj), 0, 0, ((struct Obj02473 *)p)->f38, ((struct Obj02473 *)p)->f30);
    }
    func_0201F73C(obj, 1, (u16)(((struct Obj02473 *)p)->f3C), 12);
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(5);
}
