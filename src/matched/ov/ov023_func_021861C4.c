/*
 * function: func_021861C4
 * address:  0x021861C4
 * packet:   pkt_ov023_021861C4
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */
#include "../include/Obj00525.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u16 a8, u32 a9);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 layer);

void func_021861C4(u8 *w, u32 msg, int mode)
{
    void *str;
    void *t;
    void *p;

    str = func_020457B0(0x50, 0x28);
    func_02045CAC(((struct Obj00525 *)w)->f14, msg, str);
    func_0201F250(((struct Obj00525 *)w)->f10, ((struct Obj00525 *)w)->f30, str);
    func_02045808(str);
    func_02043B5C(func_02045770(((struct Obj00525 *)w)->f11C), 15);
    func_0201F73C(((struct Obj00525 *)w)->f11C, 0, 1, 10);
    if (((struct Obj00525 *)w)->f16C != 0) {
        func_0201CE48(((struct Obj00525 *)w)->f16C);
        ((struct Obj00525 *)w)->f16C = 0;
    }
    if (mode == 0) {
        t = ((struct Obj00525 *)w)->f168;
        func_0201C724(t, (u32)func_02045770(((struct Obj00525 *)w)->f15C), 0, 0, (u32)(((struct Obj00525 *)w)->f30), ((struct Obj00525 *)w)->fC, 0x44F);
        ((struct Obj00525 *)w)->f160 = 1;
    } else {
        ((struct Obj00525 *)w)->f16C = func_0201CCE4(((struct Obj00525 *)w)->f11C, 0, 0, ((struct Obj00525 *)w)->f30,
                                              ((struct Obj00525 *)w)->fC, func_02012FFC(),
                                              ((struct Obj00525 *)w)->f170, 1, 0x28, 0xF0F);
    }
    p = ((struct Obj00525 *)w)->f11C;
    func_02045334(p);
    func_02045374(p);
    func_020409B4(func_02045730(p));
}
