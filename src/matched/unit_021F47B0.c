/*
 * unit:     yes
 * function: func_021F47B0, func_021F47B4, func_021F47B8
 * address:  0x021F47B0
 * packet:   pkt_021F47B0
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * int getter, u16 getter, u8 getter.
 */

int func_021F47B0(void *p)
{
    return *(int *)((char *)p + 0x18);
}

int func_021F47B4(void *p)
{
    return *(unsigned short *)p;
}

int func_021F47B8(void *p)
{
    return *(unsigned char *)((char *)p + 0x2);
}
