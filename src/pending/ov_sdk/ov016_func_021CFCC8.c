/*
 * function: write
 * address:  0x021CFCC8
 * packet:   pkt_ov016_021CF3B0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * w10 lane1: also flat at 9 B: named DWCMemMap local in a block, (void *) cast on the work argument, (DWCMemMap *)MemSet spelling, work routed through a block-local temp, comma expression after the call.
 * blocker:  3 lines: the store of work (str r2, [sp]) is scheduled after the MemSet load in the
 *           recompile, before it in the image. Types, block scope, assignment in the argument, static
 *   MemSet and the permuter (seed 10701) all flat. Notes: docs/notes/pkt_ov016_021CF3B0.c.txt
 *
 * U27 (wave 8): a named `DWCMemMap *map = &MemSet->map` local (load hoisted into the
 *   assignment statement) is flat at the same 9 bytes; `extern MEMSET * const MemSet` collapses
 *   the function to 324 B / 211 diffs.  The store-definition/arg-load tie at +012C..+0134 stands.
 *
 * U26: `volatile void *work`, `void * volatile work`, a `void **wp = &work` local (assigning
 * through it, and passing `*wp`) and the volatile-pointer-cast store were all measured: each
 * moves `work` to a different slot (frame sp #0x14 -> #0x18) and is far worse (340 to 344 B,
 * 42 to 260 diffs).  The 9-byte residue stays the scheduler's store-definition/arg-load tie at
 * +012C..+0134; every declaration order, a mid-block initialiser, a map/array local pair and a
 * TSKlChangeFunc-style split leave it flat.
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
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(setting.o), symbol write (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ov_sdk/ov016_func_021CFCC8.c \
 *       --func write --addr 0x021CFCC8 --region ov016 --cc 1.1p1 --arm
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

/* setting.o .bss/.data */
extern MEMSET *MemSet;
extern const unsigned char SETTING_NONE[4];
extern const char setting_str_20971[];

extern int atoi(const char *s);
extern int memcmp(const void *a, const void *b, unsigned long n);
extern int DWCi_AUTH_GetNewWiFiInfo(DWCWiFiInfo *wifiinfo);
extern int DWCi_BACKUPlRead(DWCMemMap *mem);
extern int DWCi_BACKUPlWritePage(DWCMemMap *data, int *page, void *work);
extern int DWCi_STRlNLen(char *s, int maxlen);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int ascii2hex(unsigned char ascii);
static void write(int page);
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



static void write(int page)
{
    void *work;
    int type;
    int i;
    unsigned long bit;
    unsigned short crc;
    int w[4];
    bool use;

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
