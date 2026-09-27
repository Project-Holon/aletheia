/*
 * function: MBi_CheckMBParent
 * address:  0x021F4538
 * packet:   pkt_ov107_021F4538
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_gameinfo.o).  decl_line 727, param bssDescp.
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

BOOL MBi_CheckMBParent(void *bssDescp)
{
    if (*(u16 *)((char *)bssDescp + 0x40) != 1)
        return 0;
    else if (*(u8 *)((char *)bssDescp + 0x4B) & 2)
        return 1;
    else
        return 0;
}
