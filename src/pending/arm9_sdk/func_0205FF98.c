/*
 * function: func_0205FF98
 * address:  0x0205FF98
 * packet:   pkt_0205F7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Symbol at this offset is initPageEx (libncfg info.o, ncfg_info.c:491).
 * DWARF: formals (NCFGConfigEx *configEx, int page), no locals.
 *
 * symbols:
 *   initPageEx 0x0205FF98 arm
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

typedef struct NCFGSlotInfo
{
    NCFGApInfo ap;
    u8         wifi[0x0E];
    u16        crc;
} NCFGSlotInfo;

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
            NCFGSlotInfo slot[3];
            NCFGSlotInfo rsv;
        };
    };
} NCFGConfigEx;

extern void MIi_CpuClear16(u16 data, void *destp, u32 size);

void func_0205FF98(NCFGConfigEx *configEx, int page)
{
    MIi_CpuClear16(0, &configEx->slotEx[page], sizeof(NCFGSlotInfoEx));
    configEx->slotEx[page].ap.setType = 0xff;
}
