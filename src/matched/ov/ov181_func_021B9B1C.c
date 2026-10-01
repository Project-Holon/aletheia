/*
 * function: func_021B9B1C
 * address: 0x021B9B1C
 * packet: pkt_ov181_021B9B1C
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Padding: two zero bytes at 0x021B9B6A, then the next function.
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201D7EC 0x0201D7EC thumb
 */
extern void *func_02045B38(int, int, int, int);
extern void *func_020457B0(int, int);
extern void *func_0201D7EC(int, int, int, int, int);
void func_021B9B1C(char *p)
{
    *(void **)(p + 0xB0) = func_02045B38(0, 2, 0xB1, 0x8E);
    *(void **)(p + 0xB4) = func_020457B0(0x80, 0x8E);
    *(void **)(p + 0xA8) = func_0201D7EC(0x17, 0, 1, 0, 0x8E);
    *(void **)(p + 0xAC) = func_0201D7EC(0x17, 2, 1, 0, 0x8E);
}
