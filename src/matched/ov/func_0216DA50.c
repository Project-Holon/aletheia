/*
 * function: func_0216DA50
 * address:  0x0216DA50
 * packet:   pkt_0216DA50
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thin wrapper: clear bit 4 of the word at +4 (tail call to func_0216D570).
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
extern char *func_0216D570(char *p, u32 v);

void func_0216DA50(u8 *p)
{
func_0216D570((char *)p, 0x10);
}
