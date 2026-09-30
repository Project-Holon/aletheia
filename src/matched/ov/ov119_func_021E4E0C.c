/*
 * function: func_021E4E0C
 * address: 0x021E4E0C
 * packet: pkt_ov119_021E4E0C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E4DBC 0x021E4DBC thumb ov119
 */
extern int func_021E4DBC(char *);
int func_021E4E0C(char *p, int *out)
{
    int x, hi, n, t;
    x = func_021E4DBC(p);
    *out = x + 2;
    hi = x + 10;
    n = *(int *)(p + 0x634);
    if (*out >= n) *out -= n;
    n = *(int *)(p + 0x634);
    if (hi >= n) {
        t = *(int *)(p + 0xf74);
        if (t < 20) t = t + 1 + n;
        if (x <= t && t <= hi) return 1;
    } else {
        t = *(int *)(p + 0xf74);
        if (x <= t && t <= hi) return 1;
    }
    return 0;
}
