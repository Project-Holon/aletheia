/*
 * function: func_021BEA54
 * address:  0x021BEA54
 * packet:   pkt_ov210_021BEA54
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045770  0x02045770  arm
 *   func_021BCF00  0x021BCF00  thumb ov210
 *   func_021BE44C  0x021BE44C  thumb ov210
 *   func_021BE49C  0x021BE49C  thumb ov210
 */
#include "../include/Obj00222.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern u32 func_021BCF00(void *, u32);
typedef unsigned short u16;
extern void func_021BE44C(u8 *p, int slot, u32 message, int x, int y, u16 color, u32 mode);
extern void func_021BE49C(u8 *p);

void func_021BEA54(u8 *p)
{
    u8 c;

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj00222 *)p)->f1B4)), 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f1BC)), 0);
    c = ((u8 *)*(u32 *)(*(u32 *)&((struct Obj00222 *)p)->f0 + 8))[3];
    if (c != 0xFF)
        func_021BE44C(p, 0xD, func_021BCF00(p, c), 0x30, 0, 0x3C40, 2);
    else
        func_021BE44C(p, 0xD, 0x30, 0x30, 0, 0x3C40, 2);
    c = ((u8 *)*(u32 *)(*(u32 *)&((struct Obj00222 *)p)->f0 + 8))[4];
    if (c != 0xFF)
        func_021BE44C(p, 0xE, func_021BCF00(p, c), 0x30, 0, 0x3C40, 2);
    else
        func_021BE44C(p, 0xE, 0x30, 0x30, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1B4);
    func_021BE49C(p + 0x1BC);
}
