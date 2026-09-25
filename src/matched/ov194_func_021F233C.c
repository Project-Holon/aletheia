/*
 * function: func_021F233C
 * address:  0x021F233C
 * packet:   pkt_021F233C
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GX_GetBankForLCDC 0x02045A98 arm
 */

extern unsigned int GX_GetBankForLCDC(void);

void func_021F233C(char *p)
{
    if (*(unsigned short *)(p + 0x20) != 0)
    {
        unsigned int v;
        *(unsigned short *)(p + 0x20) = 0;
        v = GX_GetBankForLCDC();
        *(unsigned short *)(p + 0x16 + (*(unsigned short *)(p + 0x20) << 1)) = v;
        *(unsigned int *)(p + 0x28) = 1;
    }
}
