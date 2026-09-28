/*
 * function: func_02156A3C
 * address:  0x02156A3C
 * packet:   pkt_ov009_02156A3C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf after func_02156888's pool (no lr save, so disasm.py
 * never labels it).
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 */

typedef struct {
    char pad[0x770];
    int aid;            /* 0x770 */
} G;

extern G *d_021A8264;

int func_02156A3C(void)
{
    if (d_021A8264 != 0)
        return d_021A8264->aid;
    return -1;
}
