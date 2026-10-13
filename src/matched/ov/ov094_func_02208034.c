/*
 * function: BTLV_GAUGE_CalcTileFill
 * address:  0x02208034
 * packet:   pkt_ov094_02208034
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Levers: n is a u8 stack parameter (ldrb [sp,#0x1c]); the return value is a
 * separate copy `ret` of the running count (declared before the loop index j
 * so ret takes r2 and j r3).
 *
 * symbols:
 *   _u32_div_f     0x0209C2B0  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

u8 BTLV_GAUGE_CalcTileFill(u32 a, int b, int c, u32 *pp, u8 *out, u8 n)
{
    int lim;
    int i;
    u32 total;
    u32 v;
    u32 ret;
    int j;

    lim = b - c;
    if (lim < 0) {
        lim = 0;
    } else if (lim > (int)a) {
        lim = a;
    }
    total = n * 8;
    for (i = 0; i < n; i++) {
        out[i] = 0;
    }
    if (a < total) {
        v = (*pp * total) / a >> 8;
    } else {
        v = (*pp * total) / a;
    }
    ret = v;
    if (v == 0 && lim > 0) {
        ret = 1;
        out[0] = 1;
    } else {
        for (j = 0; j < n; j++) {
            if (v >= 8) {
                out[j] = 8;
                v -= 8;
            } else {
                out[j] = v;
                break;
            }
        }
    }
    return ret;
}
