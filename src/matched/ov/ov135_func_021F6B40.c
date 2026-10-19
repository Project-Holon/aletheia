/*
 * function: WORLDTRADE_BOX_GetPartyMon
 * address:  0x021F6B40
 * packet:   pkt_021F6B40
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
  *
  *
  *
 * symbols:
 *   WORLDTRADE_BOX_IsPartyBox  0x021F6B34  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern int WORLDTRADE_BOX_IsPartyBox(int v);
extern u32 POKEPARTY_GetCount(void *party);
struct Sub020079BCEntry;
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void *POKE_TOOL_GetBoxParam(void *a);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);

void *WORLDTRADE_BOX_GetPartyMon(void *party, void *save, int box, int slot)
{
    if (WORLDTRADE_BOX_IsPartyBox(box) != 0) {
        if (slot > (int)POKEPARTY_GetCount(party) - 1) {
            return 0;
        }
        return POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(party, slot));
    }
    return func_02007A18(save, box, slot);
}
