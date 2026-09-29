/*
 * function: func_02205768
 * address:  0x02205768
 * packet:   pkt_ov094_02205768
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 */
int func_02205768(int a, int b)
{
    if (a == 0) {
        return 0x1d00;
    }
    if (b == a) {
        return 0x440;
    }
    if (b <= 2) {
        if (a == 1) {
            return 0x14c0;
        }
    } else if (b <= 7) {
        switch (a) {
        case 1:
            return 0x14c0;
        case 2:
            return 0xc80;
        }
    } else {
        if (a <= b / 4) {
            return 0x14c0;
        }
        if (a <= b / 2) {
            return 0xc80;
        }
    }
    return 0x440;
}
