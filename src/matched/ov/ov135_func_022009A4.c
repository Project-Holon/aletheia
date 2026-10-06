/*
 * function: func_022009A4
 * address: 0x022009A4
 * packet: pkt_ov135_022009A4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02202858 0x02202858 thumb ov135
 */
#include "../include/Obj02863.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
void func_022009A4(u8 *p, u32 n, int a2, int a3, int a4)
{
    u32 w;
    func_02045CAC((struct MsgBank *)(((struct Obj02863 *)p)->fB6C), n, ((struct Obj02863 *)p)->fB88);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj02863 *)p)->fD40)), 0xf);
    w = ((struct Obj02863 *)p)->fD40;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    func_0201F73C((void *)(((struct Obj02863 *)p)->fD40), 0, 1, 0xe);
    func_02202858((void *)(((struct Obj02863 *)p)->fD40), 0, ((struct Obj02863 *)p)->fB88, 0, 0, p + 0xfa0);
}
