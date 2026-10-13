/*
 * function: GPOWER_CountDownTimers
 * address:  0x02010DCC
 * packet:   pkt_02010DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021461E8     0x021461E8  data
 *   GPOWER_NotifyTimerUpdate   0x02010FAC  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_CountDownTimers.c \
 *       --func GPOWER_CountDownTimers --addr 0x02010DCC --cc 1.1p1 --thumb
 *
 * net_save.c: decrement every counter above 1, then tail-call the empty
 * placeholder GPOWER_NotifyTimerUpdate (pool word 0x02010FAD, `matched`).  The counter
 * is an enum, which keeps the unfolded pre-loop guard with a plain
 * increment; see GPOWER_ClearAll.c and docs/notes/pkt_02010DCC.c.txt.
 */

typedef unsigned int u32;
typedef enum { SLOT_0 = 0, SLOT_MAX = 13 } Slot;

extern u32  g_021461E8[];
extern void GPOWER_NotifyTimerUpdate(void);

void GPOWER_CountDownTimers(void)
{
    Slot i;

    for (i = 0; i < SLOT_MAX; i++) {
        if (g_021461E8[i] > 1) {
            g_021461E8[i]--;
        }
    }
    GPOWER_NotifyTimerUpdate();
}
