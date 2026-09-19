/*
 * function: func_0202B744
 * address:  0x0202B744
 * packet:   pkt_0202B6F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Promoted out of src/pending: both callees, func_0202B804 and func_0202BEDC,
 * now have EXACT manifest entries, so the two THM_CALL fields resolve through
 * the `matched` class and every byte is hard.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_0202B804(void *o);
extern void func_0202BEDC(u32 a, u32 b);

void func_0202B744(u8 *o)
{
    func_0202BEDC(*(u32 *)(o + 0x1c), func_0202B804(o));
}
