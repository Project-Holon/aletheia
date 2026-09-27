/*
 * function: func_021D54C0
 * address:  0x021D54C0
 * packet:   pkt_ov093_021D54C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Recursive MATCH unblocker attempt: unresolved leaf named by the parked
 * ov096_func_02188D5C (func_021D54C0(b->fbc, i)).  Record accessor at stride
 * 0xe, returning the halfword at +0xa.  The image materialises 0xe in r2,
 * keeps it for the `muls`, and derives the +0xa as `adds r2,#0xfc`; every
 * spelling of the constant folds to a 10-byte leaf with a `ldrh #0xa`
 * immediate against the image's 12-byte body plus alignment, so this is a
 * constant-CSE/layout tie in the front end, not a logic error.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;

u16 func_021D54C0(u8 *p, int idx)
{
    return *(u16 *)(p + idx * 0xe + 0xa);
}
