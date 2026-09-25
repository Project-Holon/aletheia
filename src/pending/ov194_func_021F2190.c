/*
 * function: func_021F2190
 * address:  0x021F2190
 * packet:   pkt_021F2190
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

int func_021F2190(char *p, unsigned short v)
{
    if (*(unsigned short *)(p + 0x1e) < *(unsigned short *)(p + 0x22))
    {
        *(unsigned short *)(p + (*(unsigned short *)(p + 0x1e) << 1)) = v;
        *(unsigned short *)(p + 0x1e) += 1;
        *(unsigned short *)(p + (*(unsigned short *)(p + 0x1e) << 1)) = GX_GetBankForLCDC();
        *(unsigned int *)(p + 0x28) = 1;
        return 1;
    }
    return 0;
}
