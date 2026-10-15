/*
 * function: DWC_BACKUPlCheckIp
 * address:  0x02058868
 * packet:   pkt_02058868
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_BACKUPlCheckIp (libdwcbm.TWL.HYB.a dwc_backup.o)
 *
 * symbols:
 *   DWC_BACKUPlCheckAddress 0x020588D0 arm
 *   MI_CpuCopy8             0x02082D44 arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

extern int  DWC_BACKUPlCheckAddress(u8 *address);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);

int DWC_BACKUPlCheckIp(u8 *ip, u8 *mask)
{
    u32 ipa;
    u32 snm;

    if (!DWC_BACKUPlCheckAddress(ip))
        return 0;
    MI_CpuCopy8(ip, &ipa, sizeof(ipa));
    MI_CpuCopy8(mask, &snm, sizeof(snm));
    return (ipa & ~snm) ? 1 : 0;
}
