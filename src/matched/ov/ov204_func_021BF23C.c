/*
 * function: func_021BF23C
 * address: 0x021BF23C
 * packet: pkt_ov204_021BF23C
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller consumes 0201CCE4's live r0 result; return declared pointer despite callee's void source.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj02540.h"

extern signed char func_02012FFC(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(unsigned int, unsigned int, unsigned int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_0201CCE4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short, unsigned short);
extern void func_0201F73C(void *, int, int, int);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void func_021BF23C(char *p, void *a, int flag)
{
    unsigned int value = func_02012FFC();
    void *desc = ((struct Obj02540 *)p)->f1C;
    func_02043B5C(func_02045770(desc), 15);
    func_0201DD78(1, 2, 15);
    func_02045CAC(((struct Obj02540 *)p)->fC, (unsigned int)a, ((struct Obj02540 *)p)->f3C);
    func_0201F250(((struct Obj02540 *)p)->f8, ((struct Obj02540 *)p)->f40, ((struct Obj02540 *)p)->f3C);
    ((struct Obj02540 *)p)->f14 = func_0201CCE4((unsigned int)desc, 4, 0, *(unsigned int *)&((struct Obj02540 *)p)->f40, ((struct Obj02540 *)p)->f10, value, ((struct Obj02540 *)p)->f18, 0xFFFF, ((struct Obj02540 *)p)->f0, 15);
    if (flag == 0)
        func_0201F73C(desc, 1, 7, 9);
    else
        func_0201F73C(desc, 1, 16, 8);
    func_02045334(desc);
    func_02045374(desc);
    func_02041B6C(func_02045730(desc));
}
