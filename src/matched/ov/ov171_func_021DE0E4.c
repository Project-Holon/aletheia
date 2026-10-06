/*
 * function: func_021DE0E4
 * address:  0x021DE0E4
 * packet:   pkt_ov171_021DE0E4
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: unresolved dep named by the parked func_021DE960
 * (func_021DE0E4(obj, i, &win[1], &win[0])).  Reads the 0xb74-indexed word and
 * expands it through the arm9 helper at 0x0204B454 into the two signed shorts.
 *
 * symbols:
 *   func_0204B454  0x0204B454  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef signed short s16;

struct Actor;
struct PtS;
typedef unsigned short u16;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);

void func_021DE0E4(u8 *obj, int i, s16 *out1, s16 *out2)
{
    int v = *(int *)(obj + i * 4 + 0xb74);
    s16 tmp[2];

    func_0204B454((struct Actor *)v, (struct PtS *)tmp, 0);
    *out1 = tmp[0];
    *out2 = tmp[1];
}
