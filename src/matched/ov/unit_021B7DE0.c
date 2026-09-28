/*
 * unit:     yes
 * function: func_021B7DE0, func_021B7DE4, func_021B7DE8, func_021B7DEC
 * address:  0x021B7DE0
 * packet:   pkt_021B7DE0
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * four int getters at +0, +8, +4, +c.
 */

int func_021B7DE0(void *p)
{
    return *(int *)p;
}

int func_021B7DE4(void *p)
{
    return *(int *)((char *)p + 0x8);
}

int func_021B7DE8(void *p)
{
    return *(int *)((char *)p + 0x4);
}

int func_021B7DEC(void *p)
{
    return *(int *)((char *)p + 0xC);
}
