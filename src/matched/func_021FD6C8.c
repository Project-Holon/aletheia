/*
 * function: func_021FD6C8
 * address:  0x021FD6C8
 * packet:   pkt_021FD6C8
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FCEA8  0x021FCEA8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021FCEA8(void *, int, void *, int);

void func_021FD6C8(u8 *p)
{
    void *q = *(void **)(p + 0x140);
    func_021FCEA8(p, 4, *(void **)((u8 *)q + 0x20), 0xff);
}
