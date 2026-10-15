/*
 * function: checkConfigEx
 * address:  0x0205FDAC
 * packet:   pkt_0205FDAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      checkConfigEx (libncfg.TWL.HYB.a info.o)
 *
 * symbols:
 *   checkConfig         0x0205FB8C arm
 *   MI_CpuFill8         0x02082BCC arm
 *   MATH_CalcCRC16      0x02081B64 arm
 *   NCFGi_CheckApInfoEx 0x02060224 arm
 *   initPageEx          0x0205FF98 arm
 *   writeAllExSlots     0x02060140 arm
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

typedef struct MATHCRC16Table {
    u16 table[256];
} MATHCRC16Table;

extern s32  checkConfig(NCFGConfig *config, MATHCRC16Table *tbl);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern u16  MATH_CalcCRC16(MATHCRC16Table *table, void *data, u32 dataLength);
extern int  NCFGi_CheckApInfoEx(NCFGApInfo *info, NCFGApInfoEx *infoEx);
extern void initPageEx(NCFGConfigEx *configEx, int page);
extern int  writeAllExSlots(NCFGConfigEx *configEx, MATHCRC16Table *tbl);

s32 checkConfigEx(NCFGConfigEx *configEx, MATHCRC16Table *tbl)
{
    u8  state;
    u8  prevState;
    int clear;
    int c[3];
    int result;
    int i;

    result = checkConfig(&configEx->compat, tbl);
    MI_CpuFill8(c, 0, sizeof(c));
    for (i = 0; i < 3; i++) {
        u16 hash = MATH_CalcCRC16(tbl, &configEx->slotEx[i], 0xFE);
        u16 hashEx = MATH_CalcCRC16(tbl, &configEx->slotEx[i].apEx, 0xFE);
        if (hash == configEx->slotEx[i].crc && hashEx == configEx->slotEx[i].crcEx
            && NCFGi_CheckApInfoEx(&configEx->slotEx[i].ap, &configEx->slotEx[i].apEx))
            c[i] = 1;
    }

    if (c[0] && c[1] && c[2])
        return result;

    prevState = configEx->slotEx[0].ap.state;
    if (!c[0]) {
        initPageEx(configEx, 0);
        if (c[1])
            prevState = configEx->slotEx[1].ap.state;
        else
            prevState = 7;
    }
    if (!c[1])
        initPageEx(configEx, 1);
    if (!c[2])
        initPageEx(configEx, 2);

    clear = 0;
    state = 0;
    for (i = 0; i < 3; i++) {
        if (configEx->slotEx[i].ap.setType != 0xFF)
            state |= (u8)(1 << i);
        else if (prevState & (1 << i))
            clear = 1;
    }
    configEx->slotEx[0].ap.state = state;
    configEx->slotEx[1].ap.state = state;

    if (!writeAllExSlots(configEx, tbl))
        return -10000;
    if (!c[0] && !c[1] && !c[2])
        clear = 0;
    if (result != 0)
        return result;
    return clear ? -10002 : 0;
}
