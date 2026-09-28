/*
 * unit:     yes
 * function: func_021B7CBC, func_021B7CC0, func_021B7CC4
 * address:  0x021B7CBC
 * packet:   pkt_021B7CBC
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * three int getters at +0, +8, +4.
 */

int func_021B7CBC(void *p)
{
    return *(int *)p;
}

int func_021B7CC0(void *p)
{
    return *(int *)((char *)p + 0x8);
}

int func_021B7CC4(void *p)
{
    return *(int *)((char *)p + 0x4);
}
