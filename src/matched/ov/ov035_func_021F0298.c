/*
 * function: func_021F0298
 * address:  0x021F0298
 * packet:   pkt_ov035_021F0298
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045790 0x02045790 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045374 0x02045374 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F79C 0x0201F79C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj09808.h"

typedef signed short   s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045790(struct Descriptor *p, u8 v);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201F79C(void *desc, u32 kind, u32 base, u32 pal);
extern void func_02045334(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);

void func_021F0298(char *p, int a1, int a2, int a3)
{
    int r7 = (int)func_02045EC0((struct MsgBank *)(((struct Obj09808 *)p)->f38), a2);

    func_02045790((struct Descriptor *)a1, a3);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)a1)), 15);
    func_0201F7A8((void *)a1, 2);
    func_02045374((struct Cfg *)a1);
    func_0201C7A4((void *)((int)func_02045770((struct Descriptor *)a1)), 0, 0, (void *)r7, (void *)(((struct Obj09808 *)p)->f34));
    func_0201F79C((void *)a1, 0, ((struct Obj09808 *)p)->f14, 2);
    func_02045334((struct Descriptor *)a1);
    func_02045808((struct U16Vec *)r7);
}
