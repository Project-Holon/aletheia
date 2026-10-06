/*
 * unit:     yes
 * function: func_021B6B5C, func_021B6B68
 * address:  0x021B6B5C
 * packet:   pkt_ov098_021B6B5C
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two unlabelled tail-call stubs (object + 4), filed as the blocker of
 * func_021B644C (lane S25). tu range is the 24 code bytes only; the listing
 * extent runs on into func_021B6B74.
 *
 * symbols:
 *   func_021B6C60  0x021B6C60  thumb  ov098
 *   func_021B6CDC  0x021B6CDC  thumb  ov098
 */

extern void func_021B6C60(char *p);
typedef unsigned char  u8;
extern int func_021B6CDC(u8 *p);

void func_021B6B5C(char *p)
{
    func_021B6C60(p + 4);
}

int func_021B6B68(char *p)
{
    return func_021B6CDC((u8 *)(p + 4));
}
