/*
 * function: BTL_POKEPARAM_ReloadFromMon
 * address:  0x021D4EFC
 * packet:   pkt_ov093_021D4EFC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   BTL_POKEPARAM_LoadStats  0x021D52B4  thumb ov093
 *   POKE_TOOL_GetPersonalParam  0x02019C90  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad00[8];
    u32 f08;
    u16 f0c;
    u16 f0e;
    u16 f10;
    u8 pad12[0x13c - 0x12];
    u16 f13c;
    u16 f13e;
    u8 pad140;
    u8 f141;
};

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 buf);
extern void BTL_POKEPARAM_LoadStats(u8 *p, void *h, u32 flag);
extern u32 POKE_TOOL_GetPersonalParam(u16 a, u16 b, u32 k);

void BTL_POKEPARAM_ReloadFromMon(struct S *a, void *mon, u32 c, u32 d)
{
    if (c != 0) {
        a->f10 = POKE_TOOL_GetPartyValue(mon, 0xa0, 0);
        a->f0e = POKE_TOOL_GetPartyValue(mon, 0xa1, 0);
    }
    a->f08 = POKE_TOOL_GetPartyValue(mon, 8, 0);
    BTL_POKEPARAM_LoadStats((u8 *)a, mon, d);
    if (d != 0) {
        a->f13c = POKE_TOOL_GetPartyValue(mon, 0xa, 0);
    }
    a->f141 = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
    a->f13e = POKE_TOOL_GetPersonalParam(a->f0c, a->f141, 0x26);
    if (a->f13e < 1) {
        a->f13e = 1;
    }
}
