/*
 * function: func_021B9838
 * address:  0x021B9838
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B99B8  0x021B99B8  thumb  ov114
 *
 *
 * Frees the record's buffer, then the record itself.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021B99B8(u8 *);
extern u32 func_020307B0(void *p);

void func_021B9838(u8 *p)
{
    if (p == 0)
        return;
    func_021B99B8(p);
    func_020307B0(p);
}
