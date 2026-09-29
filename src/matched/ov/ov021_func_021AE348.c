/*
 * unit:     yes
 * function: func_021AE348, func_021AE360, func_021AE394, func_021AE3C8, func_021AE3FC
 * address:  0x021AE348
 * packet:   pkt_ov021_021AE348
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D9338  0x021D9338  data  a4
 * Addresses are Black-image addresses.
 * func_021AE348 dispatches through the four-entry table at 0x021D9338,
 * whose entries are the four unlabelled leaves that follow it; the unit
 * covers the whole 232-byte run.
 */

typedef short s16;

typedef int (*CmpFn)(int, const s16 *, const s16 *);

extern CmpFn d_021D9338[];

int func_021AE348(int idx, int a, const s16 *p, const s16 *q)
{
    return d_021D9338[idx](a, p, q);
}

int func_021AE360(int a, const s16 *p, const s16 *q)
{
    if (p[0] == q[0] && p[1] == q[1] && q[2] < p[2] && q[2] >= p[2] - a)
        return p[2] - q[2];
    return -1;
}

int func_021AE394(int a, const s16 *p, const s16 *q)
{
    if (p[0] == q[0] && p[1] == q[1] && q[2] > p[2] && q[2] <= p[2] + a)
        return q[2] - p[2];
    return -1;
}

int func_021AE3C8(int a, const s16 *p, const s16 *q)
{
    if (p[2] == q[2] && p[1] == q[1] && q[0] < p[0] && q[0] >= p[0] - a)
        return p[0] - q[0];
    return -1;
}

int func_021AE3FC(int a, const s16 *p, const s16 *q)
{
    if (p[2] == q[2] && p[1] == q[1] && q[0] > p[0] && q[0] <= p[0] + a)
        return q[0] - p[0];
    return -1;
}
