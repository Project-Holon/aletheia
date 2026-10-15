/*
 * function: writeAllExSlots
 * address:  0x02060140
 * packet:   pkt_02060140
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      writeAllExSlots (libncfg.TWL.HYB.a info.o)
 *
 * symbols:
 *   MATH_CalcCRC16         0x02081B64 arm
 *   NCFG_WriteBackupMemory 0x0205F7C8 arm
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

extern u16 MATH_CalcCRC16(MATHCRC16Table *table, void *data, u32 dataLength);
extern s32 NCFG_WriteBackupMemory(s32 index, void *buf, u32 size);

int writeAllExSlots(NCFGConfigEx *configEx, MATHCRC16Table *tbl)
{
    int result = 1;
    int i;

    for (i = 0; i < 3; i++) {
        configEx->slotEx[i].crc = MATH_CalcCRC16(tbl, &configEx->slotEx[i], 0xFE);
        configEx->slotEx[i].crcEx = MATH_CalcCRC16(tbl, &configEx->slotEx[i].apEx, 0xFE);
        result = result && NCFG_WriteBackupMemory(i + 0x11, &configEx->slotEx[i], sizeof(NCFGSlotInfoEx)) >= 0;
    }
    return result;
}
