/*
 * function: func_021BD9D4
 * address: 0x021BD9D4
 * packet: pkt_ov093_021BD9D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 42-byte function followed by 2-byte zero alignment padding.
 * symbols:
 *   func_021BD8F0 0x021BD8F0 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BD8F0(u8 *, u8, u8, u8);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
void func_021BD9D4(u8 *p, u8 i, u8 a, u8 b, int c)
{
    func_021BD8F0(p, i, a, b);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 61, i, a, b, (u8)c);
}
