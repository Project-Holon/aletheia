/*
 * function: MBi_ClearSendStatus
 * address:  0x021F3FA4
 * packet:   pkt_ov107_021F3FA4
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_gameinfo.o).  decl_line 418.
 *
 * symbols:
 *   d_021F6EF4   0x021F6EF4  data
 */
extern char d_021F6EF4[];

void MBi_ClearSendStatus(void)
{
    d_021F6EF4[0x25] = 0;
    d_021F6EF4[0x26] = 0;
    d_021F6EF4[0x27] = 0;
    d_021F6EF4[0x28] = 0;
    d_021F6EF4[0x29] = 0;
}
