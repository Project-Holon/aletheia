/*
 * function: func_021B98D8
 * address:  0x021B98D8
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * Appends `n` bytes at the write cursor and advances it.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_02082D44(int, int, int);

void func_021B98D8(u8 *p, int a, int n)
{
    if (p == 0)
        return;
    func_02082D44(a, *(u32 *)p + *(u32 *)(p + 4), n);
    *(u32 *)(p + 4) += n;
}
