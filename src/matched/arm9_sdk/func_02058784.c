/*
 * function: DWCi_BACKUPlWritePage
 * address:  0x02058784
 * packet:   pkt_02058784
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_BACKUPlWritePage (libdwcbm.TWL.HYB.a dwc_backup.o)
 *
 * symbols:
 *   WriteSlotInfo 0x02058634 arm
 *   writeDisable  0x020588FC arm
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

extern int WriteSlotInfo(NCFGSlotInfo *buf, int index, void *work);
extern int writeDisable(void);

int DWCi_BACKUPlWritePage(DWCMemMap *data, int *page, void *work)
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
