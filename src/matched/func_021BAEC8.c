/*
 * function: func_021BAEC8
 * address:  0x021BAEC8
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BABF4  0x021BABF4  arm  ov114
 *
 *
 * ov114 tail-call thunk via `ldr ip,pool; bx ip`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BABF4(void);

void func_021BAEC8(void)
{
    func_021BABF4();
}
