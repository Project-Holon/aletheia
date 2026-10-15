/*
 * function: func_021BFF18
 * address:  0x021BFF18
 * packet:   pkt_ov210_021BFF18
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CURSOR_MOVE_Delete 0x02025D14 thumb
 * Addresses are Black-image addresses.
 */

extern void CURSOR_MOVE_Delete(void);

void func_021BFF18(int p)
{
    int *q = (int *)p;

    if (q[0xac] != 0) {
        CURSOR_MOVE_Delete();
        q[0xac] = 0;
    }
}
