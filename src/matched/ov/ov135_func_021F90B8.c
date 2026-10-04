/*
 * function: func_021F90B8
 * address: 0x021F90B8
 * packet: pkt_ov135_021F90B8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02202878 0x02202878 thumb ov135
 *   func_02202858 0x02202858 thumb ov135
 */
#include "../include/Obj02857.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_0201F73C(void *, int, int, int);
extern void func_02202878(void *a, unsigned b, unsigned c, int d, int e, u8 *p);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
void func_021F90B8(u8 *p, void *bank, u32 index, int unused1, int unused2, int slow)
{
    void *str;
    str = func_02045EC0(bank, index);
    func_0201F250(((struct Obj02857 *)p)->fB68, ((struct Obj02857 *)p)->fB88, str);
    func_02045808(str);
    func_02043B5C(func_02045770(((struct Obj02857 *)p)->fD40), 15);
    func_02045334(((struct Obj02857 *)p)->fD40);
    func_0201F73C(((struct Obj02857 *)p)->fD40, 0, 1, 14);
    if (slow)
        func_02202878(((struct Obj02857 *)p)->fD40, 0, (unsigned int)(((struct Obj02857 *)p)->fB88), 0, 0, p + 0xfa0);
    else
        func_02202858(((struct Obj02857 *)p)->fD40, 0, ((struct Obj02857 *)p)->fB88, 0, 0, p + 0xfa0);
    ((struct Obj02857 *)p)->fDFC = 0;
}
