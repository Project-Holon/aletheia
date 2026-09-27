/*
 * function: MBi_calc_cksum
 * address:  0x021F3CB8
 * packet:   pkt_ov107_021F3CB8
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_common.o).  decl_line 94, locals nwords and
 * sum.
 */
typedef unsigned short u16;
typedef unsigned long u32;

u16 MBi_calc_cksum(const u16 *buf, int length)
{
    u32 sum = 0;
    u16 low;
    int nwords;

    for (nwords = length >> 1; nwords > 0; nwords--)
        sum += *buf++;

    low = sum;
    sum = low + (sum >> 16);
    sum += sum >> 16;
    return (u16)(sum ^ 0xFFFF);
}
