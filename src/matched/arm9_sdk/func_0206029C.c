/*
 * function: NCFGi_CheckIpInfo
 * address:  0x0206029C
 * packet:   pkt_0206029C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NCFGi_CheckIpInfo (libncfg.TWL.HYB.a check.o)
 *
 * symbols:
 *   NCFGi_CheckAddress 0x0206043C arm
 *   NCFGi_ConvMaskAddr 0x02060368 arm
 *   NCFGi_CheckIp      0x020603BC arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed long    s32;

typedef struct NCFGApInfo {
    u8  ispId[32];
    u8  ispPass[32];
    u8  ssid[2][32];
    u8  wep[4][16];
    u8  ip[4];
    u8  gateway[4];
    u8  dns[2][4];
    u8  netmask;
    u8  wep2[4][5];
    u8  authType;
    u8  wepMode : 2;
    u8  wepNotation : 6;
    u8  setType;
    u8  ssidLength[2];
    u16 mtu;
    u8  rsv[2];
    u8  flags;
    u8  state;
} NCFGApInfo;

extern int  NCFGi_CheckAddress(u8 *address);
extern void NCFGi_ConvMaskAddr(int mask, u8 *buf);
extern int  NCFGi_CheckIp(u8 *ip, u8 *mask);

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
