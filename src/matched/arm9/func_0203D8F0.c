/*
 * function: GFL_NET_IRC_WIRELESS_Create
 * address:  0x0203D8F0
 * packet:   pkt_0203D8F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * net_irc_wireless.c.  Wraps a caller's 0x70-byte task header: allocates a
 * 0x10C-byte record low on the header's own heap (id | 0x8000, __FILE__
 * 0x020A7D34, line 0x72), copies the header in, saves the header's three
 * callbacks (+0x2C, +0x18, +0x1C) at +0x80/+0x78/+0x7C, installs the
 * wireless callbacks GFL_NET_IRC_WIRELESS_OnConnectEnd, GFL_NET_IRC_WIRELESS_GetBeaconData, GFL_NET_IRC_WIRELESS_GetBeaconCompare in their
 * place, publishes the record at 0x021469F0 and returns it.  With a live
 * record whose +0x101 is 1 it returns the header untouched.
 *
 * The lever (docs/notes/pkt_0203D8F0.c.txt had 63 bytes out, 40 after
 * the permuter): the header parameter is `const Base *`.  Without const
 * the stores into the new record may alias the header, so the compiler
 * keeps the header loads behind them and schedules the allocator's stack
 * argument differently; with const both regions reproduce.
 * symbols:
 *   gNetIrcWirelessLink     0x021469F0  data
 *   d_020A7D34     0x020A7D34  data
 *   func_02030734  0x02030734  arm
 *   func_02034F84  0x02034F84  arm
 *   GFL_NET_IRC_WIRELESS_OnConnectEnd  0x0203DC4C  arm
 *   GFL_NET_IRC_WIRELESS_GetBeaconData  0x0203E420  arm
 *   GFL_NET_IRC_WIRELESS_GetBeaconCompare  0x0203E458  arm
 */


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Base {
    u8   pad_00[0x18];
    void *fn_18;
    void *fn_1c;
    u8   pad_20[0x2c - 0x20];
    void *fn_2c;
    u8   pad_30[0x54 - 0x30];
    u16  heap;
    u8   pad_56[0x60 - 0x56];
    u8   f60;
    u8   pad_61[3];
    u8   f64;
    u8   f65;
    u8   pad_66[0x70 - 0x66];
} Base;

typedef struct Wrap {
    Base  base;
    u32   arg;
    u32   pad_74;
    void *fn_18;
    void *fn_1c;
    void *fn_2c;
    u8    pad_84[0x101 - 0x84];
    u8    f101;
    u8    pad_102[2];
    u8    f104;
    u8    pad_105[2];
    u8    f107;
    u8    pad_108[0x10C - 0x108];
} Wrap;

extern Wrap *gNetIrcWirelessLink;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034F84(u32 v);
extern void GFL_NET_IRC_WIRELESS_OnConnectEnd(void);
extern void *GFL_NET_IRC_WIRELESS_GetBeaconData(void *arg);
extern void *GFL_NET_IRC_WIRELESS_GetBeaconCompare(void *arg);
extern u8 d_020A7D34[];

Base *GFL_NET_IRC_WIRELESS_Create(const Base *src, u32 a1)
{
    Wrap *obj;

    if (gNetIrcWirelessLink != 0 && gNetIrcWirelessLink->f101 == 1)
        return (Base *)src;

    obj = func_02030734((u16)((src->heap & 0x7FFF) | 0x8000), sizeof(Wrap), 1, (const char *)d_020A7D34, 0x72);
    obj->base = *src;
    obj->arg = a1;
    obj->fn_2c = src->fn_2c;
    obj->fn_18 = src->fn_18;
    obj->fn_1c = src->fn_1c;
    obj->base.f65 = 3;
    obj->base.fn_2c = GFL_NET_IRC_WIRELESS_OnConnectEnd;
    obj->base.fn_18 = GFL_NET_IRC_WIRELESS_GetBeaconData;
    obj->base.fn_1c = GFL_NET_IRC_WIRELESS_GetBeaconCompare;
    obj->f104 = obj->base.f64;
    obj->base.f64 = 0;
    obj->f107 = obj->base.f60;

    gNetIrcWirelessLink = obj;
    func_02034F84(0x20);
    return &gNetIrcWirelessLink->base;
}
