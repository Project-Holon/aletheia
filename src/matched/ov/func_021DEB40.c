/*
 * function: func_021DEB40
 * address:  0x021DEB40
 * packet:   pkt_021DEB40
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049DB4  0x02049DB4  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj12153.h"
typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char  u8;
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern u32 func_020307B0(void *p);

void func_021DEB40(u32 a, int b, void *c)
{
    void *out;
    void *r;

    r = func_02049DB4(0x74, b + 0xe, 1, (u32)(&out), 0x4c);
    func_02040B1C(3, (const void *)(((struct Obj12153 *)out)->f14), ((struct Obj12153 *)out)->f10, (u32)c);
    func_020307B0(r);
}
