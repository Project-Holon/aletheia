/*
 * function: func_021C7648
 * address:  0x021C7648
 * packet:   pkt_ov136_021C7648
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035C08  0x02035C08  arm
 *   d_021C7E2C 0x021C7E2C data a4
 */

typedef unsigned char u8;
extern const u8 d_021C7E2C[];
extern int func_02035C08(const void *);
int func_021C7648(u8 *p)
{
    return func_02035C08(d_021C7E2C);
}
