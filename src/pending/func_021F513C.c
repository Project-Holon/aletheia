/*
 * function: func_021F513C
 * address:  0x021F513C
 * packet:   pkt_021F513C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *

 * The 12 concrete bytes of code plus the two BL pairs are reproduced; wave 2
 * found the same wall and this lane re-measured it: the BL at +0006 to
 * func_02012E08 stays wildcarded because that address is an EXACT* entry in
 * src/matched and so has no witness outside this range.  The first BL to
 * func_020120F4 resolves as a plain arm9 label, so only the second is open.
 *
 * Shape: mode query pair, then the 0x29 command byte.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020120F4(u32 v);
extern u32 func_02012E08(u32 v);
extern void func_0200F7C0(u32 c);

void func_021F513C(u8 *p)
{
    func_02012E08(func_020120F4(*(u32 *)(*(u32 *)p + 0x40)));
    func_0200F7C0(0x29);
}
