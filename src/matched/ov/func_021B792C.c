/*
 * function: func_021B792C
 * address:  0x021B792C
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Steps a u16 value towards a u16 limit by 4 or 8 (chosen from p->+0x20 == 1),
 * clamping at the limit.  Returns 1 when the value moved, 0 when it already sat
 * on the limit.
 *
 * symbols:
 *   (none)
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

int func_021B792C(void *p, u16 *value, u16 *limit)
{
    unsigned char step = (*(u32 *)((char *)p + 0x20) == 1) ? 4 : 8;
    u16 lim = *limit;
    u16 v = *value;

    if (v < lim) {
        if ((int)(v + step) < (int)lim)
            *value = v + step;
        else
            *value = lim;
        return 1;
    }
    if (v > lim) {
        if ((int)(v - step) > (int)lim)
            *value = v - step;
        else
            *value = lim;
        return 1;
    }
    return 0;
}
