/*
 * file:     setting.c
 * unit:     yes
 * function: DWCi_SETTIGNlInit, DWCi_SETTIGNlEnd, DWCi_SETTIGNlGet, DWCi_SETTINGlSetIpAuto, DWCi_SETTINGlSetDnsAuto, DWCi_SETTINGlSetSsid, DWCi_SETTINGlSetWep, DWCi_SETTINGlSetIp, DWCi_SETTINGlSetNetMask, DWCi_SETTINGlSetGateway, DWCi_SETTINGlSetDnsP, DWCi_SETTINGlSetDnsS, DWCi_SETTINGlGetSsid, DWCi_SETTINGlGetIp, DWCi_SETTINGlGetNetMask, DWCi_SETTINGlGetGateway, DWCi_SETTINGlGetDnsP, DWCi_SETTINGlGetDnsS, DWCi_SETTINGlGetSetType, DWCi_SETTINGlSetSetting, DWCi_SETTINGlSet, DWCi_SETTINGlSetRaku, DWCi_SETTINGlSetAoss, DWCi_SETTINGlGetMemMap, DWCi_SETTINGlErasePage, DWCi_SETTINGlEraseAll, write, DWCi_SETTINGlConvAddress, ascii2hex
 * address:  0x021CF3B0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * The global pointer at 0x021DE644.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SETTINGlGetMemMap.c \
 *       --func DWCi_SETTINGlGetMemMap --addr 0x021CFBD4 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_AUTH_GetNewWiFiInfo         0x02058BC0  arm
 *   DWCi_BACKUPlConvMaskAddr         0x0205883C  arm
 *   DWCi_BACKUPlConvMaskCidr         0x020587F8  arm
 *   DWCi_BACKUPlConvWifiInfo         0x02058904  arm
 *   DWCi_BACKUPlRead                 0x02058770  arm
 *   DWCi_BACKUPlWritePage            0x02058784  arm
 *   DWCi_HEAPlAllocEx                0x021D6414  arm
 *   DWCi_HEAPlFree_                  0x021D6438  arm
 *   DWCi_STRlNLen                    0x021D7200  arm
 *   MATH_CalcCRC16                   0x02081B64  arm
 *   MATHi_CRC16InitTableRev          0x020819FC  arm
 *   MI_CpuCopy8                      0x02082D44  arm
 *   MI_CpuFill8                      0x02082BCC  arm
 *   MIi_CpuClear16                   0x02082A48  arm
 *   MemSet                           0x021DE644  data
 *   OS_SPrintf                       0x02084F40  arm
 *   SETTING_NONE                     0x021DA910  data
 *   ascii2hex                        0x021CFEA0  arm
 *   atoi                             0x020964E0  arm
 *   memcmp                           0x020923F0  arm
 *   setting_str_20971                0x021DB8C4  data
 */
typedef _Bool bool;

typedef struct NCFGApInfo {
    unsigned char  ispId[32];         /* 0x00 */
    unsigned char  ispPass[32];       /* 0x20 */
    unsigned char  ssid[2][32];       /* 0x40 */
    unsigned char  wep[4][16];        /* 0x80 */
    unsigned char  ip[4];             /* 0xC0 */
    unsigned char  gateway[4];        /* 0xC4 */
    unsigned char  dns[2][4];         /* 0xC8 */
    unsigned char  netmask;           /* 0xD0 */
    unsigned char  wep2[4][5];        /* 0xD1 */
    unsigned char  authType;          /* 0xE5 */
    unsigned char  wepMode : 2;       /* 0xE6 */
    unsigned char  wepNotation : 6;
    unsigned char  setType;           /* 0xE7 */
    unsigned char  ssidLength[2];     /* 0xE8 */
    unsigned short mtu;               /* 0xEA */
    unsigned char  rsv[2];            /* 0xEC */
    unsigned char  flags;             /* 0xEE */
    unsigned char  state;             /* 0xEF */
} NCFGApInfo;

typedef struct NCFGSlotInfo {
    NCFGApInfo     ap;                /* 0x00 */
    unsigned char  wifi[14];          /* 0xF0 */
    unsigned short crc;               /* 0xFE */
} NCFGSlotInfo;

typedef struct tagDWCMemMap { NCFGSlotInfo page[4]; } DWCMemMap;

typedef struct tagSETTINGINFO {
    NCFGApInfo     ap;                /* 0x00 */
    unsigned char  netmask[4];        /* 0xF0 */
    unsigned char  idx;               /* 0xF4 */
    bool           ipAuto;            /* 0xF5 */
    bool           dnsAuto;           /* 0xF6 */
} SETTINGINFO;

typedef struct MATHCRC16Table { unsigned short table[256]; } MATHCRC16Table;

typedef struct tagMEMSET {
    DWCMemMap      map;               /* 0x000 */
    SETTINGINFO    temp;              /* 0x400 */
    MATHCRC16Table tbl;               /* 0x4F8 */
} MEMSET;

typedef struct _ATERMApConfigParam {
    char ssid[32];                    /* 0x00 */
    int  auth_mode;                   /* 0x20 */
    int  wepkeyid;                    /* 0x24 */
    char wepkey[4][32];               /* 0x28 */
    char wpakey[64];                  /* 0xA8 */
} ATERMApConfigParam;

typedef struct aoss_secure_info {
    unsigned char WEP40Key1[6];
    unsigned char WEP40Key2[6];
    unsigned char WEP40Key3[6];
    unsigned char WEP40Key4[6];
    unsigned char WEP40_SSID[33];
    unsigned char WEP104Key1[14];
    unsigned char WEP104Key2[14];
    unsigned char WEP104Key3[14];
    unsigned char WEP104Key4[14];
    unsigned char WEP104_SSID[33];
    unsigned char WPA_PSK_TKIP[64];
    unsigned char WPA_PSK_TKIP_SSID[33];
    unsigned char WPA_PSK_AES[64];
    unsigned char WPA_PSK_AES_SSID[33];
} aoss_secure_info;

typedef struct tagDWCWiFiInfo {
    unsigned long long attestedUserId;
    unsigned long long notAttestedId;
    unsigned short     pass;
    unsigned short     randomHistory;
} DWCWiFiInfo;

extern int atoi(const char *s);
extern int memcmp(unsigned char *s1, unsigned char *s2, unsigned int n);
extern int DWCi_AUTH_GetNewWiFiInfo(DWCWiFiInfo *wifiinfo);
extern int DWCi_BACKUPlRead(void *mem);
extern int DWCi_BACKUPlWritePage(DWCMemMap *data, int *page, void *work);
extern int DWCi_STRlNLen(unsigned char *s, int maxlen);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern unsigned char *DWCi_BACKUPlConvWifiInfo(DWCWiFiInfo *info);
extern unsigned char DWCi_BACKUPlConvMaskCidr(unsigned char *mask);
extern unsigned short MATH_CalcCRC16(MATHCRC16Table *table, void *data, unsigned long dataLength);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_BACKUPlConvMaskAddr(int mask, unsigned char *buf);
extern void DWCi_HEAPlFree_(void **mem);
extern void MATHi_CRC16InitTableRev(MATHCRC16Table *table, unsigned short poly);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MIi_CpuClear16(unsigned short data, void *destp, unsigned long size);
void DWCi_SETTIGNlInit(void);
void DWCi_SETTIGNlEnd(void);
char *DWCi_SETTIGNlGet(void);
void DWCi_SETTINGlSetIpAuto(unsigned char v);
void DWCi_SETTINGlSetDnsAuto(unsigned char v);
void DWCi_SETTINGlSetSsid(char *ssid);
void DWCi_SETTINGlSetWep(unsigned char *wep);
void DWCi_SETTINGlSetIp(char *ip);
void DWCi_SETTINGlSetNetMask(char *netmask);
void DWCi_SETTINGlSetGateway(char *gateway);
void DWCi_SETTINGlSetDnsP(char *dns);
void DWCi_SETTINGlSetDnsS(char *dns);
void DWCi_SETTINGlGetSsid(unsigned char *buf);
void DWCi_SETTINGlGetIp(char *buf);
void DWCi_SETTINGlGetNetMask(char *buf);
void DWCi_SETTINGlGetGateway(char *buf);
void DWCi_SETTINGlGetDnsP(char *buf);
void DWCi_SETTINGlGetDnsS(char *buf);
unsigned char DWCi_SETTINGlGetSetType(unsigned int i);
void DWCi_SETTINGlSetSetting(int idx);
void DWCi_SETTINGlSet(void);
void DWCi_SETTINGlSetRaku(void *param);
void DWCi_SETTINGlSetAoss(void *param);
char *DWCi_SETTINGlGetMemMap(void);
void DWCi_SETTINGlErasePage(int page);
void DWCi_SETTINGlEraseAll(void);
void DWCi_SETTINGlConvAddress(char *adr, unsigned char *buf);
extern const unsigned char SETTING_NONE[4];
static MEMSET *MemSet = 0;
extern const char setting_str_20971[];

static void writeSettingPage(int page);
static int ascii2hex(unsigned int c);


void DWCi_SETTIGNlInit(void)
{
    MemSet = DWCi_HEAPlAllocEx(sizeof(MEMSET), 32);
    MATHi_CRC16InitTableRev(&MemSet->tbl, 0xa001);
    DWCi_BACKUPlRead(&MemSet->map);
}


/*
 * Tail-call DWCi_HEAPlFree_ with the address of 0x021DE644.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SETTIGNlEnd.c \
 *       --func DWCi_SETTIGNlEnd --addr 0x021CF3F0 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SETTIGNlEnd(void)
{
    DWCi_HEAPlFree_((void *)0x021DE644);
}


/*
 * Address of the object behind the global pointer, +0x400.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SETTIGNlGet.c \
 *       --func DWCi_SETTIGNlGet --addr 0x021CF404 --region ov016 --cc dsi/1.1p1 --arm
 */
char *DWCi_SETTIGNlGet(void)
{
    return *(char **)0x021DE644 + 0x400;
}


/*
 * Store a byte at +0x4f5 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SETTINGlSetIpAuto.c \
 *       --func DWCi_SETTINGlSetIpAuto --addr 0x021CF418 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SETTINGlSetIpAuto(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE644 + 0x4f5) = v;
}


/*
 * Store a byte at +0x4f6 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SETTINGlSetDnsAuto.c \
 *       --func DWCi_SETTINGlSetDnsAuto --addr 0x021CF42C --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SETTINGlSetDnsAuto(unsigned char v)
{
    *(unsigned char *)(*(char **)0x021DE644 + 0x4f6) = v;
}


void DWCi_SETTINGlSetSsid(char *ssid)
{
    MI_CpuCopy8(ssid, MemSet->temp.ap.ssid[0], 32);
    MemSet->temp.ap.setType = 0;
}


void DWCi_SETTINGlSetWep(unsigned char *wep)
{
    unsigned char *adr;
    int i;
    int len;

    MI_CpuFill8(MemSet->temp.ap.wep[0], 0, 16);
    len = DWCi_STRlNLen((unsigned char *)wep, 32);
    switch (len) {
    case 0:
    case 10:
    case 26:
    case 32:
        MemSet->temp.ap.wepNotation = 0;
        adr = MemSet->temp.ap.wep[0];
        for (i = 0; i < len; i += 2)
            *adr++ = ascii2hex(wep[i]) * 16 + ascii2hex(wep[i + 1]);
        break;
    default:
        MemSet->temp.ap.wepNotation = 1;
        MI_CpuCopy8(wep, MemSet->temp.ap.wep[0], 16);
        break;
    }
    switch (len) {
    case 0:
        MemSet->temp.ap.wepMode = 0;
        break;
    case 5:
    case 10:
        MemSet->temp.ap.wepMode = 1;
        break;
    case 13:
    case 26:
        MemSet->temp.ap.wepMode = 2;
        break;
    default:
        MemSet->temp.ap.wepMode = 3;
        break;
    }
}


void DWCi_SETTINGlSetIp(char *ip)
{
    DWCi_SETTINGlConvAddress(ip, MemSet->temp.ap.ip);
}


void DWCi_SETTINGlSetNetMask(char *netmask)
{
    DWCi_SETTINGlConvAddress(netmask, MemSet->temp.netmask);
}


void DWCi_SETTINGlSetGateway(char *gateway)
{
    DWCi_SETTINGlConvAddress(gateway, MemSet->temp.ap.gateway);
}


void DWCi_SETTINGlSetDnsP(char *dns)
{
    DWCi_SETTINGlConvAddress(dns, MemSet->temp.ap.dns[0]);
}


void DWCi_SETTINGlSetDnsS(char *dns)
{
    DWCi_SETTINGlConvAddress(dns, MemSet->temp.ap.dns[1]);
}


/*
 * Tail-call MI_CpuCopy8 with the global object +0x440, v and 0x20.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SETTINGlGetSsid.c \
 *       --func DWCi_SETTINGlGetSsid --addr 0x021CF684 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SETTINGlGetSsid(unsigned char *buf)
{
    MI_CpuCopy8(*(char **)0x021DE644 + 0x440, buf, 0x20);
}


void DWCi_SETTINGlGetIp(char *buf)
{
    unsigned char *p = MemSet->temp.ap.ip;

    OS_SPrintf(buf, setting_str_20971, p[0], p[1], p[2], p[3]);
}


void DWCi_SETTINGlGetNetMask(char *buf)
{
    unsigned char *p = MemSet->temp.netmask;

    OS_SPrintf(buf, setting_str_20971, p[0], p[1], p[2], p[3]);
}


void DWCi_SETTINGlGetGateway(char *buf)
{
    unsigned char *p = MemSet->temp.ap.gateway;

    OS_SPrintf(buf, setting_str_20971, p[0], p[1], p[2], p[3]);
}


void DWCi_SETTINGlGetDnsP(char *buf)
{
    unsigned char *p = MemSet->temp.ap.dns[0];

    OS_SPrintf(buf, setting_str_20971, p[0], p[1], p[2], p[3]);
}


void DWCi_SETTINGlGetDnsS(char *buf)
{
    unsigned char *p = MemSet->temp.ap.dns[1];

    OS_SPrintf(buf, setting_str_20971, p[0], p[1], p[2], p[3]);
}


/*
 * Byte at +0xe7 of the i-th 0x100-byte record behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SETTINGlGetSetType.c \
 *       --func DWCi_SETTINGlGetSetType --addr 0x021CF7F4 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned char DWCi_SETTINGlGetSetType(unsigned int i)
{
    return *(unsigned char *)(*(char **)0x021DE644 + (i << 8) + 0xe7);
}


void DWCi_SETTINGlSetSetting(int idx)
{
    NCFGApInfo *info;

    info = &MemSet->map.page[idx].ap;
    MemSet->temp.ap = *info;
    MemSet->temp.idx = idx;
    if (memcmp((unsigned char *)info->ip, (unsigned char *)SETTING_NONE, 4))
        MemSet->temp.ipAuto = 0;
    else
        MemSet->temp.ipAuto = 1;
    if (memcmp((unsigned char *)info->dns[0], (unsigned char *)SETTING_NONE, 4) != 0 || memcmp((unsigned char *)info->dns[1], (unsigned char *)SETTING_NONE, 4) != 0)
        MemSet->temp.dnsAuto = 0;
    else
        MemSet->temp.dnsAuto = 1;
    DWCi_BACKUPlConvMaskAddr(info->netmask, MemSet->temp.netmask);
}


void DWCi_SETTINGlSet(void)
{
    SETTINGINFO *temp;
    NCFGApInfo *info;

    temp = &MemSet->temp;
    info = &MemSet->map.page[temp->idx].ap;
    *info = temp->ap;
    if (temp->ipAuto) {
        MI_CpuFill8(info->ip, 0, 4);
        MI_CpuFill8(info->gateway, 0, 4);
        info->netmask = 0;
    } else {
        MI_CpuCopy8(temp->ap.ip, info->ip, 4);
        MI_CpuCopy8(temp->ap.gateway, info->gateway, 4);
        info->netmask = DWCi_BACKUPlConvMaskCidr(temp->netmask);
    }
    if (temp->dnsAuto)
        MI_CpuFill8(info->dns, 0, 8);
    else
        MI_CpuCopy8(temp->ap.dns, info->dns, 8);
    writeSettingPage(temp->idx);
}


void DWCi_SETTINGlSetRaku(void *param)
{
    ATERMApConfigParam *prm;
    SETTINGINFO *info;
    int i;
    unsigned long n;

    prm = (ATERMApConfigParam *)param;
    info = &MemSet->temp;
    n = 0;
    MI_CpuFill8(&info->ap, 0, 0xef);
    MI_CpuCopy8(prm->ssid, info->ap.ssid[0], 32);
    switch (prm->auth_mode) {
    case 1:
        info->ap.wepMode = 1;
        n = 5;
        break;
    case 2:
        info->ap.wepMode = 2;
        n = 13;
        break;
    case 3:
        info->ap.wepMode = 3;
        n = 16;
        break;
    default:
        info->ap.wepMode = 0;
        break;
    }
    info->ap.wepNotation = 0;
    for (i = 0; i < 4; i++)
        MI_CpuCopy8(prm->wepkey[i], info->ap.wep[i], n);
    info->ap.setType = 2;
    MI_CpuFill8(info->netmask, 0, 4);
    info->ipAuto = 1;
    info->dnsAuto = 1;
    DWCi_SETTINGlSet();
}


void DWCi_SETTINGlSetAoss(void *param)
{
    aoss_secure_info *prm;
    SETTINGINFO *info;

    prm = (aoss_secure_info *)param;
    info = &MemSet->temp;
    MI_CpuFill8(&info->ap, 0, 0xef);
    MI_CpuCopy8(prm->WEP40Key1, info->ap.wep2[0], 5);
    MI_CpuCopy8(prm->WEP40Key2, info->ap.wep2[1], 5);
    MI_CpuCopy8(prm->WEP40Key3, info->ap.wep2[2], 5);
    MI_CpuCopy8(prm->WEP40Key4, info->ap.wep2[3], 5);
    MI_CpuCopy8(prm->WEP40_SSID, info->ap.ssid[1], 32);
    MI_CpuCopy8(prm->WEP104Key1, info->ap.wep[0], 13);
    MI_CpuCopy8(prm->WEP104Key2, info->ap.wep[1], 13);
    MI_CpuCopy8(prm->WEP104Key3, info->ap.wep[2], 13);
    MI_CpuCopy8(prm->WEP104Key4, info->ap.wep[3], 13);
    MI_CpuCopy8(prm->WEP104_SSID, info->ap.ssid[0], 32);
    info->ap.wepMode = 2;
    info->ap.wepNotation = 0;
    info->ap.setType = 1;
    MI_CpuFill8(info->netmask, 0, 4);
    info->ipAuto = 1;
    info->dnsAuto = 1;
    DWCi_SETTINGlSet();
}

char *DWCi_SETTINGlGetMemMap(void)
{
    return *(char **)0x021DE644;
}


void DWCi_SETTINGlErasePage(int page)
{
    NCFGApInfo *ap;

    ap = &MemSet->map.page[page].ap;
    MI_CpuFill8(ap, 0, 0xef);
    ap->setType = 0xff;
    writeSettingPage(page);
}


void DWCi_SETTINGlEraseAll(void)
{
    unsigned char *adr;
    DWCWiFiInfo info;
    int i;

    MIi_CpuClear16(0, &MemSet->map, sizeof(DWCMemMap));
    for (i = 0; i < 3; i++)
        MemSet->map.page[i].ap.setType = 0xff;
    DWCi_AUTH_GetNewWiFiInfo(&info);
    adr = DWCi_BACKUPlConvWifiInfo(&info);
    for (i = 0; i < 2; i++)
        MI_CpuCopy8(adr, MemSet->map.page[i].wifi, 14);
    for (i = 0; i < 4; i++)
        writeSettingPage(i);
}


static void writeSettingPage(int page)
{
    void *work;
    int type;
    int i;
    unsigned long bit;
    unsigned short crc;
    int w[4];
    unsigned char use;

    type = MemSet->map.page[page].ap.setType;
    use = 0;
    bit = 1 << page;
    MI_CpuFill8(w, 0, sizeof(w));
    w[page] = 1;
    if (page <= 2) {
        if (MemSet->map.page[0].ap.state & bit)
            use = 1;
        if (type == 0xff && use) {
            MemSet->map.page[0].ap.state &= ~bit;
            MemSet->map.page[1].ap.state &= ~bit;
            w[0] = w[1] = 1;
        } else if (type != 0xff && !use) {
            MemSet->map.page[0].ap.state |= bit;
            MemSet->map.page[1].ap.state |= bit;
            w[0] = w[1] = 1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (w[i]) {
            crc = MATH_CalcCRC16(&MemSet->tbl, &MemSet->map.page[i], 0xfe);
            MemSet->map.page[i].crc = crc;
        }
    }
    work = DWCi_HEAPlAllocEx(0x100, 32);
    DWCi_BACKUPlWritePage(&MemSet->map, w, work);
    DWCi_HEAPlFree_(&work);
}


void DWCi_SETTINGlConvAddress(char *adr, unsigned char *buf)
{
    unsigned char chr[4];
    int j;
    int i;

    MI_CpuFill8(chr, 0, 4);
    for (i = 0; i < 4; i++) {
        MI_CpuCopy8(adr + i * 3, chr, 3);
        for (j = 0; j < 3; j++) {
            if (chr[j] != 0)
                break;
            chr[j] = ' ';
        }
        buf[i] = atoi((char *)chr);
    }
}


static int ascii2hex(unsigned int c)
{
    if (c <= 0x39)
        return c - 0x30;
    if (c <= 0x46)
        return c - 0x37;
    return c - 0x57;
}
