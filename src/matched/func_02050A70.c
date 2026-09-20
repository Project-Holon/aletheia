/*
 * function: func_02050A70
 * address:  0x02050A70
 * packet:   pkt_02050A70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A84     0x02146A84  data
 *   func_02050B14  0x02050B14  arm
 *
 * blocker:  02050B14 (arm, from header) has no witness outside
 *           02050A70..02050B14 - BOTH unresolved sites are the `bl` to it,
 *           and this function holds the only two branches to 0x02050B14 in
 *           the whole image, so `label` has nothing to point at and no cut
 *           frees it.  It closes only when 0x02050B14 itself has a shard
 *           entry, and that body is the one-register allocator residue
 *           written up in docs/notes/pkt_02050A70.c.txt (44 differing bytes,
 *           no source reaches it).  Chain row.
 *
 *           All 164 concrete bytes reproduce, including the third site
 *           (g_02146A84, literal x5).  The counter is `int`, not `u32`: the
 *           loop's back edge is `blt`.
 *
 * Sweep the four 16-byte slots of the global bank at 0x02146A84 and retire
 * the ones whose state bits say so: a slot whose bit 0 of +0x0C is set has it
 * cleared, and if it is still busy (bits 11.. of +0x08) its teardown routine
 * runs and the "torn down" bit (bit 1) is set; a slot whose bit 2 is set has
 * it cleared and the teardown routine runs.  The bank pointer is re-read
 * after every store (`ldr r0, [r5]`), which is what the repeated reads say:
 * the store can alias the global itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02050A70.c \
 *       --func func_02050A70 --addr 0x02050A70 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef struct Slot {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 active : 1;             /* bit 0 of +0x0C */
    u32 torn   : 1;             /* bit 1 of +0x0C */
    u32 kill   : 1;             /* bit 2 of +0x0C */
    u32        : 29;
} Slot;

extern Slot *g_02146A84;
extern void func_02050B14(u32 i);

void func_02050A70(void)
{
    int i;

    if (g_02146A84 == 0)
        return;

    for (i = 0; i < 4; i++) {
        if (g_02146A84[i].active) {
            g_02146A84[i].active = 0;
            if (g_02146A84[i].unk08 >> 11) {
                func_02050B14(i);
                g_02146A84[i].torn = 1;
            }
        }
        if (g_02146A84[i].kill) {
            g_02146A84[i].kill = 0;
            func_02050B14(i);
        }
    }
}
