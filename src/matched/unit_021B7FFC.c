/*
 * unit:     yes
 * function: func_021B7FFC, func_021B8000, func_021B8004, func_021B8008
 * address:  0x021B7FFC
 * packet:   pkt_021B7FFC
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * four int getters at +0, +8, +4, +c.
 */

int func_021B7FFC(void *p)
{
    return *(int *)p;
}

int func_021B8000(void *p)
{
    return *(int *)((char *)p + 0x8);
}

int func_021B8004(void *p)
{
    return *(int *)((char *)p + 0x4);
}

int func_021B8008(void *p)
{
    return *(int *)((char *)p + 0xC);
}
