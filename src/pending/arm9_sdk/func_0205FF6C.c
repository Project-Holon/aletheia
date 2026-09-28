/*
 * function: func_0205FF6C
 * address:  0x0205FF6C
 * packet:   pkt_0205F7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Symbol at this offset is initPage (libncfg info.o, ncfg_info.c:479).
 * DWARF: formals (NCFGConfig *config, int page), no locals.
 *
 * symbols:
 *   initPage 0x0205FF6C arm
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

extern void MIi_CpuClear16(u16 data, void *destp, u32 size);

void func_0205FF6C(NCFGConfig *config, int page)
{
    MIi_CpuClear16(0, &config->slot[page], sizeof(NCFGSlotInfo));
    config->slot[page].ap.setType = 0xff;
}
