/*
 * function: DWC_GetGHTTPDataEx
 * address:  0x021BF6C4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_GHTTPGetEx  0x021BF6EC  arm  ov114
 *
 *
 * Forwards six arguments with a zero in the fourth slot.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void DWCi_GHTTPGetEx(int, int, int, int, int, int, int);

void DWC_GetGHTTPDataEx(int a, int b, int c, int d, int e, int f)
{
    DWCi_GHTTPGetEx(a, b, c, 0, d, e, f);
}
