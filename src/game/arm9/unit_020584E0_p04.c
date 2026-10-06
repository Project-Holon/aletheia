/*
 * file:     unit_020584E0_p04.c
 * unit:     yes
 * function: func_02058770, func_02058784, func_020587E0, func_020587F8, func_0205883C, func_02058868, func_020588D0
 * address:  0x02058770
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
 *   WriteSlotInfo 0x02058634 arm
 *   writeDisable  0x020588FC arm
 *   Wifi  0x02146A94  data  a4
 *   MI_CpuCopy8             0x02082D44 arm
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

typedef struct NCFGSlotInfo {
    NCFGApInfo ap;
    u8  wifi[14];
    u16 crc;
} NCFGSlotInfo;

typedef struct NCFGApInfoEx {
    u8  security[0x82];
    u8  proxyMode;
    u8  proxyAuthType;
    u8  proxyHost[100];
    u16 proxyPort;
    u8  rsvEx[6];
} NCFGApInfoEx;

typedef struct NCFGSlotInfoEx {
    NCFGApInfo   ap;
    u8           wifi[14];
    u16          crc;
    NCFGApInfoEx apEx;
    u8           rsv[14];
    u16          crcEx;
} NCFGSlotInfoEx;

typedef struct NCFGConfig {
    NCFGSlotInfo slot[3];
    NCFGSlotInfo rsv;
} NCFGConfig;

typedef struct NCFGConfigEx {
    NCFGSlotInfoEx slotEx[3];
    union {
        NCFGConfig compat;
        struct {
            NCFGSlotInfo slot[3];
            NCFGSlotInfo rsv;
        };
    };
} NCFGConfigEx;

typedef struct tagDWCMemMap {
    NCFGSlotInfo page[4];
} DWCMemMap;

extern int ReadSlotInfo(void *buf, int offset, unsigned long num);
extern int WriteSlotInfo(NCFGSlotInfo *buf, int index, void *work);
extern int writeDisable(void);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned long size);
int DWCi_BACKUPlRead(void *mem);
int func_02058784(DWCMemMap *data, int *page, void *work);
void DWCi_BACKUPlSetWiFi(unsigned char *wifi);
u8 func_020587F8(u8 *mask);
void DWCi_BACKUPlConvMaskAddr(int mask, unsigned char *buf);
int func_02058868(u8 *ip, u8 *mask);
int DWC_BACKUPlCheckAddress(unsigned char *address);


int DWCi_BACKUPlRead(void *mem)
{
    return ReadSlotInfo(mem, 0, 4);
}


/*
 * sdk:      DWCi_BACKUPlWritePage (libdwcbm.TWL.HYB.a dwc_backup.o)
 */
int func_02058784(DWCMemMap *data, int *page, void *work)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (page[i]) {
            while (!WriteSlotInfo(&data->page[i], i, work))
                ;
        }
    }
    return writeDisable() ? 1 : 0;
}


static unsigned char Wifi[14];


void DWCi_BACKUPlSetWiFi(unsigned char *wifi)
{
    MI_CpuCopy8(wifi, Wifi, 14);
}


/*
 * sdk:      DWCi_BACKUPlConvMaskCidr (libdwcbm.TWL.HYB.a dwc_backup.o)
 */
u8 func_020587F8(u8 *mask)
{
    int snm;
    int i;
    int j;

    i = 0;
    snm = 0;
    for (; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            if ((mask[i] >> j) & 1)
                snm++;
        }
    }
    return (u8)snm;
}

void DWCi_BACKUPlConvMaskAddr(int mask, unsigned char *buf)
{
    int i;
    unsigned long snm = 0xffffffff ^ (0xffffffff >> mask);
    for (i = 0; i < 4; i++)
        buf[i] = (unsigned char)(snm >> (24 - i * 8));
}


/*
 * sdk:      DWC_BACKUPlCheckIp (libdwcbm.TWL.HYB.a dwc_backup.o)
 */
int func_02058868(u8 *ip, u8 *mask)
{
    u32 ipa;
    u32 snm;

    if (!DWC_BACKUPlCheckAddress(ip))
        return 0;
    MI_CpuCopy8(ip, &ipa, sizeof(ipa));
    MI_CpuCopy8(mask, &snm, sizeof(snm));
    return (ipa & ~snm) ? 1 : 0;
}

int DWC_BACKUPlCheckAddress(unsigned char *address)
{
    unsigned char v = *address;
    if (v == 127)
        return 0;
    if (v < 1)
        return 0;
    return v <= 223;
}
