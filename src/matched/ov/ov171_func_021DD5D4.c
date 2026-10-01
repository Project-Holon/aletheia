/*
 * function: func_021DD5D4
 * address: 0x021DD5D4
 * packet: pkt_ov171_021DD5D4
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed byte step avoids an extra entry truncation.
 */
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
u8 func_021DD5D4(char *p, s8 i, int target, s8 step)
{
    u8 count;
    count = 1;
    do {
        i += step;
        if (i < 0)
            i = *(u16 *)(p + *(s8 *)(p + 0xc5e) * 0xbc + 0xc4) - 1;
        else if (i >= *(u16 *)(p + *(s8 *)(p + 0xc5e) * 0xbc + 0xc4))
            i = 0;
        if (i == target)
            break;
        count++;
    } while (count < 6);
    return count;
}
