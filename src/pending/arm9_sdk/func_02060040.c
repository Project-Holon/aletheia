/*
 * function: func_02060040
 * address:  0x02060040
 * packet:   pkt_0205F7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Symbol at this offset is readAllExSlots (libncfg info.o, ncfg_info.c:517).
 * DWARF: formal (NCFGConfigEx *configEx), locals (int i at r7, int result).
 *
 * symbols:
 *   readAllExSlots 0x02060040 arm
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

typedef struct NCFGApInfoEx
{
    union {
        struct {
            u8  wpaKey[0x20];
            u8  wpaPassphrase[0x40];
            u8  rsv[0x21];
            u8  wpaMode;
        } wpa;
        struct {
            u8  wpaKey[2][0x20];
            u8  ssid[2][0x20];
            u8  ssidLength[2];
        } aossEx;
    };
    u8  proxyMode;
    u8  proxyAuthType;
    u8  proxyHost[0x64];
    u16 proxyPort;
    u8  rsvEx[0x06];
} NCFGApInfoEx;

typedef struct NCFGSlotInfoEx
{
    NCFGApInfo   ap;
    u8           wifi[0x0E];
    u16          crc;
    NCFGApInfoEx apEx;
    u8           rsvEx[0x0E];
    u16          crcEx;
} NCFGSlotInfoEx;

typedef struct NCFGConfigEx
{
    NCFGSlotInfoEx slotEx[3];
    union {
        struct {
            u8 slot[0x300];
            u8 rsv[0x100];
        };
    };
} NCFGConfigEx;

extern int NCFG_ReadBackupMemory(void *buf, u32 size, int index);

int func_02060040(NCFGConfigEx *configEx)
{
    int i;
    int result = 1;

    for (i = 0; i < 3; i++) {
        if (result)
            result = (NCFG_ReadBackupMemory(&configEx->slotEx[i], sizeof(NCFGSlotInfoEx), i + 0x11) >= 0);
    }
    return result;
}
