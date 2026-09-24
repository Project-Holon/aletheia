/*
 * function: func_021F513C
 * address:  0x021F513C
 * packet:   pkt_021F513C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 * blocker:  the func_02012E08 BL at +0006 stays wildcarded (MATCH*): the site neither resolves by name nor when it is declared `thumb` in the symbols: block.  All 24 bytes, including the func_020120F4 and func_0200F7C0 calls, are right.
 *
 * symbols:
 *

 *
 * Walk into the sub-object at +0x40, run the two-step init and hand 0x29 to the next stage.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021F513C.c --func func_021F513C  *       --addr 0x021F513C --region ov135 --thumb --cc dsi/1.1p1 --diff
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020120F4(u32 v);
extern void func_02012E08(u32 v);
extern void func_0200F7C0(int v);

void func_021F513C(u8 *p)
{
    func_02012E08(func_020120F4(*(u32 *)(*(u32 *)p + 0x40)));
    func_0200F7C0(0x29);
}
