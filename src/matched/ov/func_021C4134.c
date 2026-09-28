/*
 * function: func_021C4134
 * address:  0x021C4134
 * packet:   pkt_021C4134
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02045808(void *);
extern void func_020307B0(void *);

void func_021C4134(u8 *p)
{
    if (*(void **)(p + 0xc))
        func_02045808(*(void **)(p + 0xc));
    func_020307B0(p);
}
