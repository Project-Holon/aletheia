/*
 * function: func_021B7A4C
 * address: 0x021B7A4C
 * packet: pkt_ov067_021B7A4C
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding at 0x021B7A62.
 * symbols:
 *   func_0202E9AC 0x0202E9AC thumb
 */
#include "../include/Obj20621.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct CodeIn;
extern void func_0202E9AC(struct CodeIn *, u8 *, u32, u32, u32);
void func_021B7A4C(u8 *p, u8 *a, u32 b, u32 c, u32 d)
{
    func_0202E9AC(*(struct CodeIn * *)&((struct Obj20621 *)p)->f30, a, b, c << 4, d << 4);
}
