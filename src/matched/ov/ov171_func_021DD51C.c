/*
 * function: func_021DD51C
 * address: 0x021DD51C
 * packet: pkt_ov171_021DD51C
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed byte step avoids an extra truncation before the addition.
 */
typedef signed char s8;
typedef unsigned char u8;
int func_021DD51C(char *p, s8 step)
{
    int old;
    old = *(s8 *)(p + 0xc5e);
    *(s8 *)(p + 0xc5e) += step;
    if (*(s8 *)(p + 0xc5e) < 0)
        *(s8 *)(p + 0xc5e) = *(u8 *)(p + 0xc5f) - 1;
    else if (*(s8 *)(p + 0xc5e) >= *(u8 *)(p + 0xc5f))
        *(s8 *)(p + 0xc5e) = 0;
    if (*(s8 *)(p + 0xc5e) != old)
        return 1;
    return 0;
}
