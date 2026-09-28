/*
 * function: MBi_CheckMBParent
 * address:  0x021F4538
 * packet:   pkt_ov107_021F4538
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_gameinfo.o).  decl_line 727, param bssDescp.
 * Closed 2026-09-28: the two guards must share their exits through explicit
 * goto ret0/ret1 labels; the plain `if (..) return k;` chain is if-converted by
 * 1.1p1 into `movne/moveq` predicated returns (36 bytes). See
 * docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

BOOL MBi_CheckMBParent(void *bssDescp)
{
    if (*(u16 *)((char *)bssDescp + 0x40) != 1)
        goto ret0;
    if (*(u8 *)((char *)bssDescp + 0x4B) & 2)
        goto ret1;
ret0:
    return 0;
ret1:
    return 1;
}
