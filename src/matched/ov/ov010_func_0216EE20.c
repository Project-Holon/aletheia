/*
 * function: EVENT_BATTLE_DispatchBattleKindNotify
 * address:  0x0216EE20
 * packet:   pkt_ov010_0216EE20
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Dispatches through the two-column handler table d_021725C0, row chosen
 * by EVENT_BATTLE_GetBattleKindClass's classification of `id`.
 *
 * symbols:
 *   EVENT_BATTLE_GetBattleKindClass  0x0216EDFC  thumb  ov010
 *   d_021725C0     0x021725C0  data
 */

typedef unsigned short u16;

typedef void (*IdHandler)(u16 id);

extern int EVENT_BATTLE_GetBattleKindClass(void *a0);
extern const IdHandler d_021725C0[][2];

void EVENT_BATTLE_DispatchBattleKindNotify(u16 id, int col)
{
    d_021725C0[EVENT_BATTLE_GetBattleKindClass((void *)id)][col](id);
}
