/*
 * function: NCFGi_CheckApInfo
 * address:  0x020601D4
 * packet:   pkt_020601D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NCFGi_CheckApInfo (libncfg.TWL.HYB.a check.o)
 *
 * symbols:
 *   NCFGi_CheckSsid   0x02060394 arm
 *   NCFGi_CheckIpInfo 0x0206029C arm
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

extern int NCFGi_CheckSsid(u8 *ssid);
extern int NCFGi_CheckIpInfo(NCFGApInfo *info);

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
