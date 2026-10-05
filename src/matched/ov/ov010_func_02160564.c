/*
 * function: func_02160564
 * address:  0x02160564
 * packet:   pkt_ov010_02160564
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled (inside func_0216025C's listing extent): translates a
 * connection state into a menu index; *err is set for unknown states.
 */

typedef unsigned int u32;

int func_02160564(u32 state, u32 *out, u32 *err)
{
    *err = 0;
    switch (state) {
    case 0:
        *out = 0;
        return 1;
    case 1:
        *out = 1;
        return 1;
    case 2:
        *out = 6;
        return 1;
    case 3:
        *out = 2;
        return 1;
    case 4:
        *out = 5;
        return 1;
    case 5:
        *out = 9;
        return 1;
    case 6:
        return 0;
    }
    *err = 1;
    return 0;
}
