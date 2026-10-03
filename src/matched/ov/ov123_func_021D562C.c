/*
 * function: func_021D562C
 * address:  0x021D562C
 * packet:   pkt_021D562C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020310C4  0x020310C4  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

struct PrintSys;
struct Tcbl;
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);

void func_021D562C(char *p)
{
    func_020310C4(*(void **)(p + 0x84));
    func_0201C4E4(*(void **)(p + 0x88));
}
