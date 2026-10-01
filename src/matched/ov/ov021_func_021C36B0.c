/*
 * function: func_021C36B0
 * address:  0x021C36B0
 * packet:   pkt_ov021_021C36B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Compacts the two day-care slots so occupied ones come first.
 *
 * symbols:
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_0200BCEC  0x0200BCEC  thumb
 */

extern int func_0200BCA8(void *e, int i);
extern void func_0200BCEC(void *e, int i, int j);

void func_021C36B0(void *e)
{
    int i, j;

    for (i = 0; i < 2; i++) {
        if (func_0200BCA8(e, i) == 1)
            continue;
        for (j = i + 1; j < 2; j++) {
            if (func_0200BCA8(e, j) == 1)
                func_0200BCEC(e, j, j - 1);
        }
    }
}
