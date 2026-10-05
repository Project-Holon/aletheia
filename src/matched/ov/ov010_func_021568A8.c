/*
 * function: func_021568A8
 * address:  0x021568A8
 * packet:   pkt_ov010_021568A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Counts the slots below n that are occupied: without a link object every
 * slot but 0, otherwise the slots for which func_021FCE28 returns 0.
 * Byte-correct (MATCH*: the listing extent runs over the unlabelled leaf
 * at 0x021568E0). Blocker: 0x021FCE28 has no func_ label in any overlay
 * listing (ov186 has it mid-function, ov094/ov132/ov135 do not start code
 * there), so the call cannot be attested until the co-resident overlay
 * that holds it is labelled.
 *
 * symbols:
 *   func_021FCE28  0x021FCE28  thumb
 */

typedef unsigned char u8;

typedef struct Work {
    u8 pad[0x28];
    void *f28;
} Work;

extern int func_021FCE28(void *p, u8 i);

u8 func_021568A8(Work *w, u8 n)
{
    u8 i;
    u8 cnt;

    cnt = 0;
    for (i = 0; i < n; i++) {
        if (w->f28 == 0) {
            if (i == 0)
                continue;
        } else if (func_021FCE28(w->f28, i) != 0) {
            continue;
        }
        cnt++;
    }
    return cnt;
}
