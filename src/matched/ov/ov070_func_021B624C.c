/*
 * function: func_021B624C
 * address: 0x021B624C
 * packet: pkt_ov070_021B624C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B621C 0x021B621C thumb ov070
 */
typedef unsigned char  u8;
extern void func_021B621C(u8 *p, int a, int b);
void func_021B624C(void *p, int a, int b)
{
    if (a == b) return;
    if (a < b) {
        for (; a < b; a++) func_021B621C(p, a, a + 1);
    } else {
        for (; a > b; a--) func_021B621C(p, a, a - 1);
    }
}
