/*
 * function: func_021D9A40
 * address:  0x021D9A40
 * packet:   pkt_021D9A40
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
struct U16Vec;
extern void func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern void func_020307B0(void *);

void func_021D9A40(u8 *p)
{
    func_020452E8(*(void **)(p + 0xc));
    func_02045808(*(void **)(p + 0x10));
    func_020307B0(p);
}
