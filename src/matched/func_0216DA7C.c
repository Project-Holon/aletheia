/*
 * function: func_0216DA7C
 * address:  0x0216DA7C
 * packet:   pkt_0216DA7C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thin wrapper: clear bit 6 of the word at +4 (tail call to func_0216D570).
 *
 * symbols:
 *   func_0216D570  0x0216D570  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0216D570(u8 *, u32);

void func_0216DA7C(u8 *p)
{
func_0216D570(p, 0x40);
}
