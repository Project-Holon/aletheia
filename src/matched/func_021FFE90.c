/*
 * function: func_021FFE90
 * address:  0x021FFE90
 * packet:   pkt_021FFE90
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FFE90   0x021FFE90  thumb ov186
 *
 * Unlabelled ov186 leaf: if the +0x20 field is zero return 0; otherwise, when
 * the +0x08 field is 2, publish the +0x10 halfword through the out pointer and
 * return the +0x08 field.  Matched to supply the `matched` witness for the
 * pending ov185 caller func_021F86A4.
 */

int func_021FFE90(int *p, unsigned short *out)
{
    if (p[8] != 0) {
        if (p[2] == 2)
            *out = (unsigned short)p[4];
        return p[2];
    }
    return 0;
}
