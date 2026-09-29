/*
 * function: func_021B980C
 * address:  0x021B980C
 * packet:   pkt_ov068_021B980C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BB120  0x021BB120  thumb
 *   func_021B9930  0x021B9930  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020310C4  0x020310C4  arm
 *   func_021BA644  0x021BA644  thumb
 *   func_021BB134  0x021BB134  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021BB120(void *p);
extern void func_021B9930(void *p);
extern u32 func_0201C4E4(void *p);
extern void func_020310C4(void *p);
extern void func_021BA644(u8 *p);
extern int func_021BB134(void *p);

int func_021B980C(u32 a, u32 b, u32 c, u8 *w)
{
    func_021BB120(w + 0xd4);
    func_021B9930(w);
    func_0201C4E4(*(void **)(w + 0x258));
    func_020310C4(*(void **)(w + 0x268));
    func_021BA644(w + 0x104);
    if (func_021BB134(w + 0xd4) != 0)
        return 1;
    return 0;
}
