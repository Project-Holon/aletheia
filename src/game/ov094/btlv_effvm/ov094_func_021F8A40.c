/*
 * function: func_021F8A40
 * address:  0x021F8A40
 * packet:   pkt_ov094_021F8A40
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets the mode at 0x238 of the global work block; resets 0x23c/0x240 unless mode 2, and mode 3 calls func_02200608.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_02200608 0x02200608 thumb ov094
 */
extern char *d_0220AF20;
extern void func_02200608(void *);

void func_021F8A40(int a)
{
    *(int *)(d_0220AF20 + 0x238) = a;
    if (*(int *)(d_0220AF20 + 0x238) != 2) {
        *(int *)(d_0220AF20 + 0x23c) = 0;
        *(int *)(d_0220AF20 + 0x240) = 0;
    }
    if (a == 3)
        func_02200608(*(void **)(d_0220AF20 + 0x190));
}
