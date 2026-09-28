/*
 * function: func_021673C4
 * address:  0x021673C4
 * packet:   pkt_ov010_021673C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the byte at +0x849 of the shared state under its lock
 * (func_0200E06C / func_0200E024).
 *
 * symbols:
 *   func_0200E06C  0x0200E06C  thumb
 *   func_0200E024  0x0200E024  thumb
 */

typedef unsigned char u8;

extern void func_0200E06C(void *p);
extern void func_0200E024(void *p);

u8 func_021673C4(u8 *p)
{
    u8 v;

    func_0200E06C(p);
    v = p[0x849];
    func_0200E024(p);
    return v;
}
