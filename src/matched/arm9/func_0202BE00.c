/*
 * function: func_0202BE00
 * address:  0x0202BE00
 * packet:   pkt_0202BE00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Signals one record's +0x3c halfword to func_02005EE0 with the +0x224
 * context pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BE00.c \
 *       --func func_0202BE00 --addr 0x0202BE00 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02005EE0(u32 a, u32 b, u32 c, u32 d);

void func_0202BE00(u8 *p, u32 i)
{
    func_02005EE0(*(u16 *)(p + i * 0x1c + 0x3c), 0x100, 0,
                  *(u32 *)(p + i * 4 + 0x224));
}
