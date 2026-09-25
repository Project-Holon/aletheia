/*
 * unit:     yes
 * function: func_021BB134, func_021BB138, func_021BB140
 * address:  0x021BB134
 * packet:   pkt_ov068_021BB134
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter and two small setters.
 */

int func_021BB134(void *p)
{
    return *(int *)((char *)p + 0x4);
}

void func_021BB138(void *p, int v)
{
    *(int *)p = v;
    *(int *)((char *)p + 8) = 0;
}

void func_021BB140(void *p)
{
    *(int *)((char *)p + 0x4) = 1;
}
