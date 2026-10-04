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

typedef unsigned int   u32;
extern void sub_020113D0(char *p, int val);
extern int func_021B2874(u32 a, u32 b, u32 c, u32 d);

int func_021B2AA0(void *p)
{
    sub_020113D0(p, (int)func_021B2874);
    return 1;
}
