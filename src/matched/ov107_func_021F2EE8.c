/*
 * function: IsChildAidValid
 * address:  0x021F2EE8
 * packet:   pkt_ov107_021F2EE8
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_parent.o).  decl_line 1256.
 */
typedef unsigned short u16;
typedef int BOOL;

BOOL IsChildAidValid(u16 child_aid)
{
    if (child_aid >= 1 && child_aid <= 15)
        return 1;
    return 0;
}
