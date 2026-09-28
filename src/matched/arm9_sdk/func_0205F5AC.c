/*
 * function: func_0205F5AC
 * address:  0x0205F5AC
 * packet:   pkt_0205F5AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CheckSetDNS (libdwcac.TWL.HYB.a(test.o))
 *
 * symbols:
 *   DWCi_ConvConnectAPType           0x0205c4c8 arm
 *   ConvAddress                      0x0205f504 arm
 *   SOC_SetResolver                  0x0215f7e8 arm
 */

typedef struct SOCInAddr {
    unsigned long addr;
} SOCInAddr;

typedef struct NCFGApInfo {
    unsigned char ispId[32];
    unsigned char ispPass[32];
    unsigned char ssid[2][32];
    unsigned char wep[4][16];
    unsigned char ip[4];
    unsigned char gateway[4];
    unsigned char dns[2][4];
    unsigned char netmask;
    unsigned char wep2[4][5];
    unsigned char authType;
    unsigned char wepMode;
    unsigned char setType;
    unsigned char ssidLength[2];
    unsigned short mtu;
    unsigned char rsv[2];
    unsigned char flags;
    unsigned char state;
} NCFGApInfo;

typedef struct NCFGSlotInfo {
    NCFGApInfo ap;
    unsigned char rest[0x10];
} NCFGSlotInfo;

typedef struct NCFGSlotInfoEx {
    NCFGApInfo ap;
    unsigned char rest[0x110];
} NCFGSlotInfoEx;

typedef struct tagACWORK {
    NCFGSlotInfo userInfo[3];
    NCFGSlotInfoEx userInfoEx[3];
    unsigned char pad0[0x14bd - 0x900];
    unsigned char connectApType;
} tagACWORK;

extern unsigned char DWCi_ConvConnectAPType(unsigned char type);
extern unsigned long ConvAddress(unsigned char *add);
extern int SOC_SetResolver(SOCInAddr *dns1, SOCInAddr *dns2);

void func_0205F5AC(tagACWORK *wk)
{
    NCFGApInfo *info;
    int dns;
    unsigned char type;
    SOCInAddr dns1;
    SOCInAddr dns2;

    if (wk->connectApType >= 0x12) {
        return;
    }
    type = DWCi_ConvConnectAPType(wk->connectApType);
    if (type <= 2) {
        info = &wk->userInfo[type].ap;
    } else {
        info = &wk->userInfoEx[type - 10].ap;
    }
    dns = info->dns[0][0] + info->dns[0][1] + info->dns[0][2] + info->dns[0][3];
    if (info->ip[0] != 0) {
        return;
    }
    if (dns == 0) {
        return;
    }
    dns1.addr = ConvAddress(info->dns[0]);
    dns2.addr = ConvAddress(info->dns[1]);
    SOC_SetResolver(&dns1, &dns2);
}
