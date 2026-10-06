/*
 * function: func_021C05B0
 * address: 0x021C05B0
 * packet: pkt_ov110_021C05B0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 90-byte function followed by two zero alignment bytes.
 * lever: inline Clear returns its stored zero, preserving r4 across calls.
 * prototype: own 020355D8 takes u8; the stored zero and returned flag
 *   retain that width through the inline helper and caller local.
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_021B6284 0x021B6284 thumb ov067
 *   func_021C0AB4 0x021C0AB4 thumb ov110
 *   func_021C0C18 0x021C0C18 thumb ov110
 *   func_021C07E8 0x021C07E8 thumb ov110
 *   func_021C16B0 0x021C16B0 thumb ov110
 *   func_020355D8 0x020355D8 arm
 */
#include "../include/Obj06395.h"
struct PrintSys;
struct TaskMenuState;
extern void func_0201C6EC(struct PrintSys *p);
typedef unsigned char u8;
extern void func_021B6284(unsigned int *);
extern void func_021C0AB4(u8 *);
typedef unsigned int   u32;
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_021C0C18(u8 *);
extern void func_021C07E8(u8 *);
extern void func_021C16B0(u8 *);
extern void func_020355D8(u8);
static inline u8 Clear(char *p, u8 i) {
    u8 zero;
    zero = i;
    for (; i < 4; i++) *(int *)(p + 0x7c + i * 4) = zero;
    return zero;
}
void func_021C05B0(char *p) {
    u8 z;
    func_0201C6EC(((struct Obj06395 *)p)->f5C);
    z=Clear(p, 0);
    ((struct Obj06395 *)p)->f4C=z;
    func_021B6284((unsigned int *)(p+0xc));
    func_021C0AB4((u8 *)p);
    func_02027FD8(((struct Obj06395 *)p)->f64);
    func_021C0C18((u8 *)p);
    func_021C07E8((u8 *)(p+0x24));
    func_021C16B0(((struct Obj06395 *)p)->f50);
    if (((struct Obj06395 *)p)->fA8) z=1;
    func_020355D8(z);
}
