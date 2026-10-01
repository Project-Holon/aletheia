/*
 * function: func_021F8934
 * address:  0x021F8934
 * packet:   pkt_ov094_021F8934
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs func_0220055C with a (enum counter keeps the entry guard) on each of the first 8 active slots of the handle at 0x190.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_021FFD9C 0x021FFD9C thumb ov094
 *   func_0220055C 0x0220055C thumb ov094
 */
typedef enum { SLOT_ZERO } Slot;

extern char *d_0220AF20;
extern int func_021FFD9C(void *, int);
extern void func_0220055C(void *, int, int);

void func_021F8934(int a)
{
    Slot i;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C(*(void **)(d_0220AF20 + 0x190), i) != 0)
            func_0220055C(*(void **)(d_0220AF20 + 0x190), i, a);
    }
}
