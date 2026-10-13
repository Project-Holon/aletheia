/*
 * function: UNION_SUBDISP_PageScrollByButtons
 * address:  0x021F0FE0
 * packet:   pkt_021F0FE0
 * region:   ov031
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0203633C  0x0203633C  arm
 */

typedef struct {
    char _pad[0x351C];
    int f351c;
    int f3520;
} T_021F0FE0;

extern unsigned int func_0203633C(void);

void UNION_SUBDISP_PageScrollByButtons(int a0, T_021F0FE0 *p)
{
    int lo;
    int v;
    int t;

    if (!p)
        return;
    v = p->f351c;
    if (v < 3)
        return;
    t = p->f3520;
    lo = v - 0x1D;
    if (lo < 2)
        lo = 2;
    if (func_0203633C() & 0x200) {
        t -= 3;
        if (t < lo)
            t = lo;
    } else if (func_0203633C() & 0x100) {
        t += 3;
        if (t > v)
            t = v;
    }
    p->f3520 = t;
}
