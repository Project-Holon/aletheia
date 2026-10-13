/*
 * function: BTL_POKEPARAM_LoadMoves
 * address: 0x021D4F84
 * packet: pkt_ov093_021D4F84
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_DecodePartyParam 0x02017D30 thumb
 *   POKE_TOOL_EncodePartyParam 0x02017D70 thumb
 *   BTL_POKEPARAM_LoadMoveInfo 0x021D5244 thumb ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
struct Ent {u16 h[6]; u8 fC,fD;};
struct Bits {u8 lo:4,hi:4;};
struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern int BTL_POKEPARAM_LoadMoveInfo(struct Ent *,void *,u8);
int BTL_POKEPARAM_LoadMoves(u8 *p, void *h, int reset)
{
    u8 t = POKE_TOOL_DecodePartyParam(h);
    u32 count = 0;
    u32 i;
    if (reset) {
        for (i = 0; i < 4; i++) {
            ((struct Bits *)(p + 0x109 + i * 14))->lo = 0;
            ((struct Bits *)(p + 0x109 + i * 14))->hi = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (BTL_POKEPARAM_LoadMoveInfo(&((struct Ent *)(p + 0x104))[i],h,i)) count++;
    }
    if (reset) {
        for (i = 0; i < 4; i++) {
            *(u16 *)(p + i * 14 + 0x10a) = *(u16 *)(p + i * 14 + 0x104);
            *(u16 *)(p + i * 14 + 0x10c) = *(u16 *)(p + i * 14 + 0x106);
            *(u16 *)(p + i * 14 + 0x10e) = *(u16 *)(p + i * 14 + 0x108);
            (p + i * 14)[0x110] = 1;
        }
    }
    POKE_TOOL_EncodePartyParam(h,t);
    return count;
}
