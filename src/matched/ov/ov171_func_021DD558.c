/*
 * function: func_021DD558
 * address: 0x021DD558
 * packet: pkt_ov171_021DD558
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed byte step avoids an extra truncation before the addition.
 */
typedef signed char s8;
typedef unsigned short u16;
int func_021DD558(char *p, s8 step)
{
    int old;
    old = *(s8 *)(p + 0xc5c);
    *(s8 *)(p + 0xc5c) += step;
    if (*(s8 *)(p + 0xc5c) < 0)
        *(s8 *)(p + 0xc5c) = *(u16 *)(p + *(s8 *)(p + 0xc5e) * 0xbc + 0xc4) - 1;
    else if (*(s8 *)(p + 0xc5c) >= *(u16 *)(p + *(s8 *)(p + 0xc5e) * 0xbc + 0xc4))
        *(s8 *)(p + 0xc5c) = 0;
    if (*(s8 *)(p + 0xc5c) != old)
        return 1;
    return 0;
}
