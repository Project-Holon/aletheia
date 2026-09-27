/*
 * function: MBi_calc_cksum
 * address:  0x021F3CB8
 * packet:   pkt_ov107_021F3CB8
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_common.o).  Rebuilt from the Rom object's
 * DWARF (MBi_calc_cksum decl_line 94, params buf/length, locals sum/nwords)
 * and the ROM disassembly.
 */

typedef unsigned long u32;
typedef unsigned short u16;

u16 MBi_calc_cksum(u16 *buf, int length)
{
    u32 sum;
    int nwords;

    sum = 0;
    nwords = length >> 1;
    while (nwords > 0) {
        sum += *buf++;
        nwords--;
    }
    sum = (sum >> 16) + (u16)sum;
    sum = sum + (sum >> 16);
    return (u16)(sum ^ 0xffff);
}
