/*
 * function: MCSS_SetCellCallback
 * address:  0x02015F40
 * packet:   pkt_02015F40
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   NNSi_G2dMCEnumAnimBank  0x02064D70  arm
 */
extern void NNSi_G2dMCEnumAnimBank(void *, void *, unsigned);

void MCSS_SetCellCallback(char *p, unsigned flags, void *callback)
{
    NNSi_G2dMCEnumAnimBank(p + 0x68, callback, flags);
}
