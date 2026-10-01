/*
 * function: func_021A4664
 * address:  0x021A4664
 * packet:   pkt_ov021_021A4664
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A4544  0x021A4544  thumb  ov021
 *   func_021A4598  0x021A4598  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

int func_0216D3CC(int b);
int func_021A4544(int a, int b, u8 *c);
int func_021A4598(int a, int b, u8 *c);

int func_021A4664(int a, int b, u8 *c)
{
    if (func_0216D3CC(b) == 0)
        return 0;
    if (*(u16 *)(c + 8) == 9)
        return func_021A4544(a, b, c);
    return func_021A4598(a, b, c);
}
