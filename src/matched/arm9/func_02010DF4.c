/*
 * function: func_02010DF4
 * address:  0x02010DF4
 * packet:   pkt_02010DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02010F50  0x02010F50  thumb
 *   g_02146228     0x02146228  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010DF4.c \
 *       --func func_02010DF4 --addr 0x02010DF4 --cc 1.1p1 --thumb
 *
 * net_save.c: clear all thirteen counter slots, then deselect (+0x1c = 0xd,
 * the "none" slot).  Wave 14 closed the residue of
 * docs/notes/pkt_02010DCC.c.txt (unfolded pre-loop guard plus a plain
 * increment, "no C type gives both"): the counter is an ENUM.  With
 * -enum int an enum counter keeps the `cmp r4, #0xd; bge` entry guard
 * (mwcc does not fold the first test for an enum-typed induction variable)
 * and increments without a truncation pair.  The slot count is an enum
 * constant; 13 is a content constant (docs/families/net_save.h).
 */

typedef unsigned char u8;
typedef enum { SLOT_0 = 0, SLOT_MAX = 13 } Slot;

extern void func_02010F50(Slot idx);
extern u8   g_02146228[];

void func_02010DF4(void)
{
    Slot i;

    for (i = 0; i < SLOT_MAX; i++) {
        func_02010F50(i);
    }
    g_02146228[0x1c] = SLOT_MAX;
}
