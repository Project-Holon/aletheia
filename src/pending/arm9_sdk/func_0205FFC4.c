/*
 * function: func_0205FFC4
 * address:  0x0205FFC4
 * packet:   pkt_0205F7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Symbol at this offset is readAllSlots (libncfg info.o, ncfg_info.c:502).
 * DWARF: formal (NCFGConfig *config), locals (int i at r7, int result).
 *
 * symbols:
 *   readAllSlots 0x0205FFC4 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct NCFGApInfo
{
    u8  ispId[0x20];
    u8  ispPass[0x20];
    u8  ssid[2][0x20];
    u8  wep[4][0x10];
    u8  ip[0x04];
    u8  gateway[0x04];
    u8  dns[2][0x04];
    u8  netmask;
    u8  wep2[4][0x05];
    u8  authType;
    u8  wepMode : 2;
    u8  wepNotation : 6;
    u8  setType;
    u8  ssidLength[2];
    u16 mtu;
    u8  rsv[0x02];
    u8  flags;
    u8  state;
} NCFGApInfo;

typedef struct NCFGSlotInfo
{
    NCFGApInfo ap;
    u8         wifi[0x0E];
    u16        crc;
} NCFGSlotInfo;

typedef struct NCFGConfig
{
    NCFGSlotInfo slot[3];
    NCFGSlotInfo rsv;
} NCFGConfig;

extern int NCFG_ReadBackupMemory(void *buf, u32 size, int index);

int func_0205FFC4(NCFGConfig *config)
{
    int i;
    int result = 1;

    for (i = 0; i < 3; i++) {
        if (result)
            result = (NCFG_ReadBackupMemory(&config->slot[i], sizeof(NCFGSlotInfo), i) >= 0);
    }
    if (result)
        result = (NCFG_ReadBackupMemory(&config->rsv, sizeof(NCFGSlotInfo), 3) >= 0);
    return result;
}
