/*
 * function: func_021D652C
 * address:  0x021D652C
 * packet:   pkt_021D652C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);

void func_021D652C(char *p)
{
    func_0204B878(*(void **)(p + 0xa8), 1);
    func_0204B92C(*(void **)(p + 0xa8), 1);
}
