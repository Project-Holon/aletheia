/*
 * function: func_020127C4
 * address:  0x020127C4
 * packet:   pkt_020127B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_020127D0  0x020127D0  thumb
 *
 * Promoted from src/pending/func_020127C4.c (was MATCH, blocker 0x020127D0,
 * declared by the naming convention, i.e. ARM).  Two things had to happen:
 * the pool word is 0x020127D1 so the target is Thumb, and
 * src/matched/sub_020127D0.c has to exist as an EXACT entry for the
 * `matched` class to reach it - both done, and the C never changed.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020127C4.c \
 *       --func func_020127C4 --addr 0x020127C4 --cc 1.1p1 --thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 *sub_020127D0(u8 *o, u32 idx);

void func_020127C4(void *p)
{
    sub_020127D0(p, 1);
}
