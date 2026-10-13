/*
 * function: PALANM_CheckBit
 * address:  0x02021930
 * packet:   pkt_0202173E
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u8 PALANM_CheckBit(u32 val, int bit)
{
    u8 ret;

    if (val & (1 << bit)) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}
