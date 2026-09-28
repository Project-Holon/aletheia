/*
 * function: func_021C291C
 * address:  0x021C291C
 * packet:   pkt_ov217_021C291C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * This address is also matched as func_021C291C in ov016; the ov217 copy is a
 * distinct function and gets its own shard.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned char u8;

void func_021C291C(char *p, u16 v)
{
    int i;
    *(u16 *)p = v;
    *(u8 *)(p + 2) = 0;
    *(int *)(p + 0xc) = 0;
    for (i = 0; i < 4; i++)
        *(int *)(p + 0x10 + i * 4) = 0;
}
