/*
 * function: WORLDTRADE_BOX_GetMonTradeState
 * address:  0x021F6C48
 * packet:   pkt_021F6C48
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
  *
 * symbols:
 *   WORLDTRADE_BOX_GetPartyMon  0x021F6B40  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void *WORLDTRADE_BOX_GetPartyMon(void *party, void *save, int box, int slot);
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);

int WORLDTRADE_BOX_GetMonTradeState(void *party, void *save, int box, int slot)
{
    void *mon = WORLDTRADE_BOX_GetPartyMon(party, save, box, slot);

    if (mon == 0) {
        return 0;
    }
    if (POKE_TOOL_GetBoxValue(mon, 0xA9, 0) == 0) {
        return 0;
    }
    if (POKE_TOOL_GetBoxValue(mon, 0xAA, 0) != 0) {
        return 2;
    }
    return 1;
}
