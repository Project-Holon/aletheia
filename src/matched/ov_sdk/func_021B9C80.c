/*
 * function: func_021B9C80
 * address:  0x021B9C80
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021CF964  0x021CF964  data
 *
 *
 * Overlay init hook: open then size the 0x021CF964 work block.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02088168(void *);
extern void func_02162248(void *, int);
extern u8 g_021CF964[];

void func_021B9C80(void)
{
    func_02088168(g_021CF964);
    func_02162248(g_021CF964, 0x20);
}
