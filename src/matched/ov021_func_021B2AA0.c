/*
 * function: func_021B2AA0
 * address:  0x021B2AA0
 * packet:   pkt_021B2AA0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021B2874  0x021B2874  thumb
 *   sub_020113D0   0x020113D0  thumb
 */

extern void sub_020113D0(void *p, void (*cb)(void));
extern void func_021B2874(void);

int func_021B2AA0(void *p)
{
    sub_020113D0(p, func_021B2874);
    return 1;
}
