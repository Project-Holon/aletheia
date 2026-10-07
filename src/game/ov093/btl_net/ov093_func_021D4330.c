/*
 * unit:     yes
 * function: func_021D4330, func_021D4348, func_021D4360, func_021D4378
 * address:  0x021D4330
 * packet:   pkt_ov093_021D4330
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F3B88  0x021F3B88  data  ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *d_021F3B88;

u8 func_021D4330(int i)
{
    return (d_021F3B88 + i * 2)[0x3b21];
}

int func_021D4348(void)
{
    if (d_021F3B88[7] != 0x28)
        return 1;
    return 0;
}

int func_021D4360(void)
{
    if (d_021F3B88[7] == d_021F3B88[6])
        return 1;
    return 0;
}

u8 func_021D4378(void)
{
    u8 *p = d_021F3B88;

    if (p != 0)
        return p[0x3b29];
    return 100;
}
