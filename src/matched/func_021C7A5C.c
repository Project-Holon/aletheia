/*
 * function: func_021C7A5C
 * address:  0x021C7A5C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BA448  0x021BA448  arm  ov114
 *
 *
 * ov114 tail-call thunk via `ldr ip,pool; bx ip`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BA448(void);

void func_021C7A5C(void)
{
    func_021BA448();
}
