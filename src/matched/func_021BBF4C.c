/*
 * function: func_021BBF4C
 * address:  0x021BBF4C
 * packet:   pkt_021BBF4C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BBF1C  0x021BBF1C  thumb  ov217
 *   func_021BC3AC  0x021BC3AC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern int func_021BBF1C(void);
extern int func_021BC3AC(void);

int func_021BBF4C(void)
{
    int t = (func_021BBF1C() << 3) + 0x17;
    return t - func_021BC3AC();
}
