/*
 * function: func_021BBF28
 * address:  0x021BBF28
 * packet:   pkt_021BBF28
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BBF04  0x021BBF04  thumb  ov217
 *   func_02041648  0x02041648  arm
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int func_021BBF04(unsigned int p, unsigned int slot);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02041648(u8 channel);

int func_021BBF28(unsigned char *p, unsigned int slot)
{
    int t = func_021BBF04((unsigned int)p, slot) << 3;
    return t - func_02041648(2);
}
