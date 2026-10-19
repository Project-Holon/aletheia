/*
 * file:     ncfg_check.c
 * unit:     yes
 * function: NCFGi_CheckApInfo, NCFGi_CheckApInfoEx, NCFGi_CheckIpInfo, NCFGi_ConvMaskAddr, NCFGi_CheckSsid, NCFGi_CheckIp, NCFGi_CheckAddress
 * address:  0x020601D4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NCFGi_CheckSsid   0x02060394 arm
 *   NCFGi_CheckIpInfo 0x0206029C arm
 *   NCFGi_CheckApInfo 0x020601D4 arm
 *   NCFGi_CheckAddress 0x0206043C arm
 *   NCFGi_ConvMaskAddr 0x02060368 arm
 *   NCFGi_CheckIp      0x020603BC arm
 *   MI_CpuCopy8        0x02082D44 arm
 */
#include "../types.h"

#include "../sdk_ncfg.h"

extern int NCFGi_CheckSsid(u8 *ssid);
extern int NCFGi_CheckIpInfo(NCFGApInfo *info);
extern int NCFGi_CheckApInfo(NCFGApInfo *info);
extern int  NCFGi_CheckAddress(u8 *address);
extern void NCFGi_ConvMaskAddr(int mask, u8 *buf);
extern int  NCFGi_CheckIp(u8 *ip, u8 *mask);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
int NCFGi_CheckApInfoEx(NCFGApInfo *info, NCFGApInfoEx *infoEx);

/*
 * sdk:      NCFGi_CheckApInfo (libncfg.TWL.HYB.a check.o)
 */
int NCFGi_CheckApInfo(NCFGApInfo *info)
{
    if (info->setType == 0xFF)
        return 1;
    if (info->setType > 2)
        return 0;
    if (!NCFGi_CheckSsid(info->ssid[0]))
        return 0;
    if (!NCFGi_CheckIpInfo(info))
        return 0;
    return 1;
}

/*
 * sdk:      NCFGi_CheckApInfoEx (libncfg.TWL.HYB.a check.o)
 */
int NCFGi_CheckApInfoEx(NCFGApInfo *info, NCFGApInfoEx *infoEx)
{
    if (info->setType == 0xFF)
        return 1;
    if (info->setType <= 2)
        return NCFGi_CheckApInfo(info);
    if (!NCFGi_CheckSsid(info->ssid[0]))
        return 0;
    if (!NCFGi_CheckIpInfo(info))
        return 0;
    if (infoEx->proxyMode > 1)
        return 0;
    if (infoEx->proxyAuthType > 1)
        return 0;
    return 1;
}

/*
 * sdk:      NCFGi_CheckIpInfo (libncfg.TWL.HYB.a check.o)
 */
int NCFGi_CheckIpInfo(NCFGApInfo *info)
{
    u8 snm[4];

    if (info->ip[0] != 0 || info->ip[1] != 0 || info->ip[2] != 0 || info->ip[3] != 0) {
        if (!NCFGi_CheckAddress(info->gateway))
            return 0;
        if (info->netmask > 32)
            return 0;
        NCFGi_ConvMaskAddr(info->netmask, snm);
        if (!NCFGi_CheckIp(info->ip, snm))
            return 0;
    }
    if (info->dns[0][0] != 0 || info->dns[0][1] != 0 || info->dns[0][2] != 0 || info->dns[0][3] != 0) {
        if (!NCFGi_CheckAddress(info->dns[0]) && !NCFGi_CheckAddress(info->dns[1]))
            return 0;
    }
    return 1;
}

/*
 * sdk:      NCFGi_ConvMaskAddr (check.o)
 */
void NCFGi_ConvMaskAddr(int mask, unsigned char *buf)
{
    int i;
    unsigned long snm;

    snm = 0xFFFFFFFF ^ (0xFFFFFFFF >> mask);
    for (i = 0; i < 4; i++) {
        buf[i] = (unsigned char)(snm >> (24 - i * 8));
    }
}

/*
 * sdk:      NCFGi_CheckSsid (check.o)
 */
int NCFGi_CheckSsid(unsigned char *ssid)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (ssid[i] != 0) {
            return 1;
        }
    }
    return 0;
}

/*
 * sdk:      NCFGi_CheckIp (libncfg.TWL.HYB.a check.o)
 */
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

/*
 * sdk:      NCFGi_CheckAddress (check.o)
 */
int NCFGi_CheckAddress(unsigned char *address)
{
    if (address[0] == 127) {
        return 0;
    }
    if (address[0] < 1) {
        return 0;
    }
    if (address[0] <= 223) {
        return 1;
    }
    return 0;
}
