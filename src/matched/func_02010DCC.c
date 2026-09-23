/*
 * function: func_02010DCC
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
 *   sub_02010FAC   0x02010FAC  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010DCC.c \
 *       --func func_02010DCC --addr 0x02010DCC --cc 1.1p1 --thumb
 *
 * net_save.c: decrement every counter above 1, then tail-call the empty
 * placeholder sub_02010FAC (pool word 0x02010FAD, `matched`).  The counter
 * is an enum, which keeps the unfolded pre-loop guard with a plain
 * increment; see func_02010DF4.c and docs/notes/pkt_02010DCC.c.txt.
 */

typedef unsigned int u32;
typedef enum { SLOT_0 = 0, SLOT_MAX = 13 } Slot;

extern u32  g_021461E8[];
extern void sub_02010FAC(void);

void func_02010DCC(void)
{
    Slot i;

    for (i = 0; i < SLOT_MAX; i++) {
        if (g_021461E8[i] > 1) {
            g_021461E8[i]--;
        }
    }
    sub_02010FAC();
}
