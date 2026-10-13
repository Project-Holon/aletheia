/*
 * function: GIMMICK39_GetActiveCart
 * address:  0x021F36F0
 * packet:   pkt_ov039_021F36F0
 * region:   ov039
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  
 *
 * symbols:
 */

typedef unsigned char u8;

u8 GIMMICK39_GetActiveCart(u8 *p, int i)
{
    return *((u8 *)p + i + 0x21EC);
}
