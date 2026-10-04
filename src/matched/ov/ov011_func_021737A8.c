/*
 * function: func_021737A8
 * address: 0x021737A8
 * packet: pkt_ov011_021737A8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 * Return-valued externs reflect r0 consumed after both forwarding calls.
 */
extern int func_021736D8(void);
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
int func_021737A8(void)
{
    if (func_021736D8() == 0)
        return 0;
    return func_0203D3A8((struct Entry *)((unsigned int)func_020399A8()), 0x202, 0, 0);
}
