/*
 * function: WORLDTRADE_BOX_CanRemoveMon
 * address:  0x021F6BA4
 * packet:   pkt_021F6BA4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
 * symbols:
 *   WORLDTRADE_BOX_IsPartyBox  0x021F6B34  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern int WORLDTRADE_BOX_IsPartyBox(int v);
extern u32 POKEPARTY_GetCount(void *party);

int WORLDTRADE_BOX_CanRemoveMon(void *party, void *save, int box, int slot)
{
    if (WORLDTRADE_BOX_IsPartyBox(box) != 0 && (int)POKEPARTY_GetCount(party) < 2) {
        return 0;
    }
    return 1;
}
