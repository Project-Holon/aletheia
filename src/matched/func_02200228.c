/*
 * function: func_02200228
 * address:  0x02200228
 * packet:   pkt_02200228
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A298   0x0204A298  arm
 *
 * Read a 16-bit value from an SDK parameter block (id 0x62, index 5), store
 * its half through *out, and return the SDK call's own result.
 */

extern int func_0204A298(int, int, int, void *, int *);

int func_02200228(void *a, unsigned *out)
{
    int local;
    int r;
    r = func_0204A298(0x62, 5, 0, a, &local);
    *out = (unsigned)local >> 1;
    return r;
}
