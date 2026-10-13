/*
 * function: ghiFreeTempBuffer
 * address:  0x021C4E68
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Null-guarded release through the ov009 helper at 0x0217EAE0.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0217EAE0(int);

void ghiFreeTempBuffer(int a)
{
    if (a == 0)
        return;
    func_0217EAE0(a);
}
