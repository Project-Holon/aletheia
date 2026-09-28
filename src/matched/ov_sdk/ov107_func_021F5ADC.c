/*
 * function: MBi_IsCommSizeValid
 * address:  0x021F5ADC
 * packet:   pkt_ov107_021F5ADC
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).
 */
typedef unsigned short u16;

static int MBi_IsCommSizeValid(u16 sendSize, u16 recvSize, u16 entry_num)
{
    if (sendSize > 0x1FE || sendSize < 0xE4)
        return 0;
    if (recvSize > 0x10 || recvSize < 8)
        return 0;
    if ((sendSize + 0x26) * 4 + 0x4A + 0x100 +
            entry_num * ((recvSize + 0x20) * 4 + 0x70) < 0x15E0)
        return 1;
    return 0;
}
