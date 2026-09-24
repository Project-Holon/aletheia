/*
 * function: func_02155294
 * address:  0x02155294
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * False when the word call returns -1.
 *
 * symbols:
 *   func_021562EC  0x021562EC  thumb  ov009
 */

extern int func_021562EC(void);

int func_02155294(void)
{
    if (func_021562EC() != -1) {
        return 1;
    }

    return 0;
}

