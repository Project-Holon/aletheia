/*
 * function: MBi_SetMaxScanTime
 * address:  0x021F6148
 * packet:   pkt_ov107_021F6148
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).  decl_line 1548.
 *
 * symbols:
 *   mbiScanParam   0x021F6FC0  data
 */
typedef unsigned short u16;

extern char mbiScanParam[];

void MBi_SetMaxScanTime(u16 time)
{
    *(u16 *)(mbiScanParam + 8) = time;
}
