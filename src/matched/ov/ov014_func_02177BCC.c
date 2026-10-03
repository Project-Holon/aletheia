/*
 * function: func_02177BCC
 * address: 0x02177BCC
 * packet: pkt_ov014_02177BCC
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Unlabelled overlay leaf blocking ov010 func_02157760.
 * symbols:
 *   d_021797A4 0x021797A4 data ov014 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *d_021797A4;
void func_02177BCC(void)
{
    u8 *p;
    int i;
    p = d_021797A4;
    if (p != 0) {
        for (i = 0; i < 16; i++)
            *(u16 *)(p + 0xC40 + i * 2) = 0;
    }
}
