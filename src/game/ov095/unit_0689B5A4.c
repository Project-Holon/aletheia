/*
 * file:     unit_0689B5A4.c
 * function: func_0689B5A4
 * address: 0x0689B5A4
 * packet: pkt_ov095_0689B5A4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220270C  0x0220270C  thumb
 */
#include "../../matched/include/Obj13637.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0220270C(u32, int, int);
void func_0689B5A4(u8 *s, int value)
{
    func_0220270C(((struct Obj13637 *)s)->fB0, 4, value);
    s[0x93] = 0;
}
