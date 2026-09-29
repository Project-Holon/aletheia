/*
 * function: func_02207D78
 * address:  0x02207D78
 * packet:   pkt_ov094_02207D78
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lane S13 leaf of func_0220680C
 */
typedef struct {
    unsigned int b0 : 27;
    unsigned int b27 : 1;
    unsigned int b28 : 4;
} Bits;

int func_02207D78(char *p, int i)
{
    int r = 0;

    if (*(int *)(p + i * 128 + 0x40) != 0) {
        Bits *q = (Bits *)(p + 0xb0 + i * 128);

        r = q->b27;
        q->b27 = 0;
    }
    return r;
}
