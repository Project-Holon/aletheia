/*
 * function: func_021AF18C
 * address:  0x021AF18C
 * packet:   pkt_ov013_021AF18C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021B3C80     0x021B3C80  data  ov013
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *d_021B3C80;

void func_021AF18C(void (*cb)(void))
{
    *(void (**)(void))(d_021B3C80 + 0x1984) = cb;
}
