/*
 * function: NCFGi_CheckIp
 * address:  0x020603BC
 * packet:   pkt_020603BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NCFGi_CheckIp (libncfg.TWL.HYB.a check.o)
 *
 * symbols:
 *   NCFGi_CheckAddress 0x0206043C arm
 *   MI_CpuCopy8        0x02082D44 arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

extern int  NCFGi_CheckAddress(u8 *address);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);

int NCFGi_CheckIp(u8 *ip, u8 *mask)
{
    u32 ipa;
    u32 snm;

    if (!NCFGi_CheckAddress(ip))
        return 0;
    MI_CpuCopy8(ip, &ipa, sizeof(ipa));
    MI_CpuCopy8(mask, &snm, sizeof(snm));
    if ((ipa | snm) == 0xFFFFFFFE)
        return 0;
    return (ipa & ~snm) ? 1 : 0;
}
