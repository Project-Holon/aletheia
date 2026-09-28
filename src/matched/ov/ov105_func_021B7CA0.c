/*
 * unit:     yes
 * function: func_021B7CA0, func_021B7CA4, func_021B7CA8, func_021B7CAC
 * address:  0x021B7CA0
 * packet:   pkt_021B7CA0
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * four int getters at +0, +8, +4, +c.
 */

int func_021B7CA0(void *p)
{
    return *(int *)p;
}

int func_021B7CA4(void *p)
{
    return *(int *)((char *)p + 0x8);
}

int func_021B7CA8(void *p)
{
    return *(int *)((char *)p + 0x4);
}

int func_021B7CAC(void *p)
{
    return *(int *)((char *)p + 0xC);
}
