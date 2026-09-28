/*
 * unit:     yes
 * function: func_021B613C, func_021B6140, func_021B6144
 * address:  0x021B613C
 * packet:   pkt_021B613C
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * three int getters at +0, +4, +8.
 */

int func_021B613C(void *p)
{
    return *(int *)p;
}

int func_021B6140(void *p)
{
    return *(int *)((char *)p + 0x4);
}

int func_021B6144(void *p)
{
    return *(int *)((char *)p + 0x8);
}
