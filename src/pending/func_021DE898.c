/*
 * function: func_021DE898
 * address:  0x021DE898
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_02012F98  0x02012F98  thumb
 *
 * Free the node unless the state word at 0x24 is 4 or 5.
 *
 * Blocked: 26 of 28 bytes, body byte-for-byte identical to the image.
 * The one residue is the THM_CALL at +0x0E to 0x02012F98, which
 * match.py reports as "no witness outside 021DE898..021DE8B2" -- the
 * same missing-callee class as 0x02021540 / 0x020257C4 / 0x02025D14.
 * The second call, 0x02007C34, resolves.  The image's instruction is a
 * plain Thumb bl (0xF634FB77), so the target is Thumb code; no symbols:
 * spelling (thumb or arm, or no declaration at all) changes the verdict.
 */

extern int func_02012F98(int);
extern void func_02007C34(int, int);

void func_021DE898(int *p)
{
    int *q = (int *)*p;
    if ((unsigned)(q[9] - 4) > 1)
        func_02007C34(func_02012F98(q[0]), q[2]);
}
