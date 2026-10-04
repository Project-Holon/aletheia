/*
 * function: ov208_func_021C0C14
 * address:  0x021C0C14
 * packet:   pkt_ov208_021C0C14
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov208_func_021BC3A4  0x021BC3A4  thumb  ov208
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02166C7C  0x02166C7C  thumb
 *   func_021BBB48  0x021BBB48  thumb  ov072
 */
#include "../include/Obj25500.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int  ov208_func_021BC3A4(int key);
struct SaveBlock;
extern void *func_020127A4(struct SaveBlock *p);
struct Rec44;
extern u16  func_02012AC8(const struct Rec44 *a);
extern u32  func_02166C7C(int a, u32 b);
extern int func_021BBB48(int a0, int a1);

u8 ov208_func_021C0C14(u16 *heap, u8 *p, int key)
{
    int a;
    u32 m;
    int v;
    u8 r;

    a = ov208_func_021BC3A4(key);
    m = func_02012AC8((const struct Rec44 *)func_020127A4((struct SaveBlock *)a));
    r = 0xff;
    v = func_021BBB48(((struct Obj25500 *)p)->f3C8, func_02166C7C(a, m));
    if (v != 0xffff)
        r = v;
    return r;
}
