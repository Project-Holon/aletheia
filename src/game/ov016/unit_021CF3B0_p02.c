/*
 * file:     unit_021CF3B0_p02.c
 * unit:     yes
 * function: func_021CF46C, func_021CF5EC
 * address:  0x021CF46C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   DWCi_SETTINGlConvAddress         0x021CFE18  arm
 *   DWCi_SETTINGlSet                 0x021CF8D8  arm
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
 *   write                            0x021CFCC8  arm
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
extern int memcmp(const void *a, const void *b, unsigned long n);
extern int DWCi_AUTH_GetNewWiFiInfo(DWCWiFiInfo *wifiinfo);
extern int DWCi_BACKUPlRead(DWCMemMap *mem);
extern int DWCi_BACKUPlWritePage(DWCMemMap *data, int *page, void *work);
extern int DWCi_STRlNLen(char *s, int maxlen);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int ascii2hex(unsigned char ascii);
extern unsigned char *DWCi_BACKUPlConvWifiInfo(DWCWiFiInfo *info);
extern unsigned char DWCi_BACKUPlConvMaskCidr(unsigned char *mask);
extern unsigned short MATH_CalcCRC16(MATHCRC16Table *table, void *data, unsigned long dataLength);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_BACKUPlConvMaskAddr(int mask, unsigned char *buf);
extern void DWCi_HEAPlFree_(void **mem);
extern void DWCi_SETTINGlConvAddress(char *adr, unsigned char *buf);
extern void DWCi_SETTINGlSet(void);
extern void MATHi_CRC16InitTableRev(MATHCRC16Table *table, unsigned short poly);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MIi_CpuClear16(unsigned short data, void *destp, unsigned long size);
extern void write(int page);
void DWCi_SETTINGlSetWep(unsigned char *wep);
void DWCi_SETTINGlSetIp(char *ip);
/* setting.o .bss/.data */
extern MEMSET *MemSet;
extern const unsigned char SETTING_NONE[4];
extern const char setting_str_20971[];

static void write(int page);




void DWCi_SETTINGlSetWep(unsigned char *wep)
{
    unsigned char *adr;
    int i;
    int len;

    MI_CpuFill8(MemSet->temp.ap.wep[0], 0, 16);
    len = DWCi_STRlNLen((char *)wep, 32);
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
