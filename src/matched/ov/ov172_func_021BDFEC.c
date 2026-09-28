/*
 * function: func_021BDFEC
 * address:  0x021BDFEC
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_021B9F98, second argument the field at +0x1e8.
 *
 * symbols:
 *   func_021B9F98  0x021B9F98  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021B9F98(void *p, u32 v);

void func_021BDFEC(void *p)
{
    func_021B9F98(p, *(u32 *)((char *)p + 0x1e8));
}
