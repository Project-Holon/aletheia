/*
 * function: checkConfig
 * address:  0x0205FB8C
 * packet:   pkt_0205FB8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      checkConfig (libncfg.TWL.HYB.a info.o)
 *
 * symbols:
 *   MI_CpuFill8       0x02082BCC arm
 *   MATH_CalcCRC16    0x02081B64 arm
 *   NCFGi_CheckApInfo 0x020601D4 arm
 *   initPage          0x0205FF6C arm
 *   MI_CpuCopy8       0x02082D44 arm
 *   MIi_CpuClear16    0x02082A48 arm
 *   writeAllSlots     0x02060094 arm
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

extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern u16  MATH_CalcCRC16(MATHCRC16Table *table, void *data, u32 dataLength);
extern int  NCFGi_CheckApInfo(NCFGApInfo *info);
extern void initPage(NCFGConfig *config, int page);
extern int  writeAllSlots(NCFGConfig *config, MATHCRC16Table *tbl);

s32 checkConfig(NCFGConfig *config, MATHCRC16Table *tbl)
{
    int c[4];
    int i;
    int clear = 1;
    u8  prevState;
    u8  state;

    MI_CpuFill8(c, 0, sizeof(c));
    for (i = 0; i < 3; i++) {
        u16 hash = MATH_CalcCRC16(tbl, &config->slot[i], 0xFE);
        if (hash == config->slot[i].crc && NCFGi_CheckApInfo(&config->slot[i].ap))
            c[i] = 1;
    }
    {
        u16 hash = MATH_CalcCRC16(tbl, &config->rsv, 0xFE);
        if (hash == config->rsv.crc)
            c[3] = 1;
    }

    if (c[0] && c[1] && c[2] && c[3])
        return 0;

    prevState = config->slot[0].ap.state;
    if (!c[0]) {
        prevState = 0;
        initPage(config, 0);
        if (c[1]) {
            prevState = config->slot[1].ap.state;
            MI_CpuCopy8(config->slot[1].wifi, config->slot[0].wifi, sizeof(config->slot[0].wifi));
        }
    }
    if (!c[1]) {
        initPage(config, 1);
        if (c[0])
            MI_CpuCopy8(config->slot[0].wifi, config->slot[1].wifi, sizeof(config->slot[0].wifi));
    }
    if (!c[2])
        initPage(config, 2);
    if (!c[3])
        MIi_CpuClear16(0, &config->rsv, sizeof(NCFGSlotInfo));

    clear = 0;
    state = 0;
    for (i = 0; i < 3; i++) {
        if (config->slot[i].ap.setType != 0xFF)
            state |= (u8)(1 << i);
        else if (prevState & (1 << i))
            clear = 1;
    }
    config->slot[0].ap.state = state;
    config->slot[1].ap.state = state;

    if (!writeAllSlots(config, tbl))
        return -10000;
    if (!c[0] && !c[1] && !c[2])
        return 0;
    if (!c[0] && !c[1])
        return -10003;
    return clear ? -10002 : 0;
}
