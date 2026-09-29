/*
 * function: func_021840C8
 * address:  0x021840C8
 * packet:   pkt_ov022_021840C8
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (prints as a .word run in asm/overlays/ov022.s); the
 * sole blocker of ov012 func_0217325C's MATCH. Of the five overlays whose
 * window holds 0x021840C8 only ov022 has a function start there.
 */

typedef unsigned char u8;

int func_021840C8(u8 *p)
{
    if (p == 0)
        return 0;
    switch (p[9]) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        if (p[10] >= p[11])
            return 1;
        return 0;
    }
    return 0;
}
