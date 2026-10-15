/*
 * function: CPS_SocUse
 * address:  0x0215AB10
 * packet:   pkt_ov009_0215AB10
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_SocUse (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   gMslRefToken  0x02150FEC  data
 *   MI_CpuFill8  0x02082BCC  arm
 */

extern char gMslRefToken[];
extern void MI_CpuFill8(void *dst, unsigned char data, unsigned long size);

void CPS_SocUse(void)
{
    char *cur = *(char **)(gMslRefToken + 4);
    char *soc = *(char **)(cur + 0xa4);

    if (soc == 0)
        return;
    *(char **)soc = cur;
    *(unsigned char *)(soc + 8) = 0;
    *(unsigned long *)(soc + 0x50) = 0;
    MI_CpuFill8(soc + 0x70, 0, 0x30);
    *(unsigned long *)(soc + 0x6c) = 0;
    *(unsigned long *)(soc + 0x44) = 0;
    *(unsigned char *)(soc + 0x33) = 0;
}
