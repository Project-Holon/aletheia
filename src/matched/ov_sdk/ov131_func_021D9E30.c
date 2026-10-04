/*
 * function: func_021D9E30
 * address:  0x021D9E30
 * packet:   pkt_021D9E30
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DA0B0  0x021DA0B0  thumb
 *   func_021DA3FC  0x021DA3FC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021DA0B0(u8 *, u8 *);
extern void func_021DA3FC(void *, int);

void func_021D9E30(void *a, int b)
{
    func_021DA0B0(a, (u8 *)b);
    func_021DA3FC(a, b);
}
