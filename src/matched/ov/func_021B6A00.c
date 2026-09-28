/*
 * function: func_021B6A00
 * address:  0x021B6A00
 * packet:   pkt_021B6A00
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Half-length packer: runs func_021B6A30 over a1>>1 halfwords of a0 into a2, returns the rounded-up byte count.
 *
 * symbols:
 *   func_021B6A30  0x021B6A30  thumb  ov172
 *   g_021C88E8     0x021C88E8  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021B6A30(short *src, unsigned char *dst, int n, int ctx);
extern u32 g_021C88E8[];

int func_021B6A00(void *a0, unsigned a1, void *a2)
{
    func_021B6A30((short *)a0, (unsigned char *)a2, (int)(a1 >> 1), (int)g_021C88E8);
    return (int)((a1 + 3) >> 2);
}
