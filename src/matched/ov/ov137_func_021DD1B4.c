/*
 * function: func_021DD1B4
 * address:  0x021DD1B4
 * packet:   pkt_021DD1B4
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020310C4  0x020310C4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct PrintSys;
struct Tcbl;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);

void func_021DD1B4(u8 *p)
{
    if (*(void **)(p + 0xec))
        func_0201C4E4(*(void **)(p + 0xec));
    func_020310C4(*(void **)(p + 0xf4));
}
