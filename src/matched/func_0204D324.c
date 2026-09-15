/*
 * unit:     no
 * function: func_0204D324
 * address:  0x0204D324
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUnk_020A1394  0x020A1394  data
 *
 * Dispatch on the object's kind word, passing the object and one forwarded
 * argument.
 *
 * The second parameter is real, not a leftover: the original steps over r1
 * entirely (kind in r3, table base in r2) where the one-parameter spelling
 * uses r2 and r1.  A register that the body never touches and never
 * reallocates is a live argument being forwarded.
 *
 * This file was previously parked at MATCH on the theory that the pool word
 * 0x020A13B8 named a table object of its own, which left the ABS32 site
 * with no witness: 0x020A13B8 appears in exactly one pool image-wide, this
 * function's own, and self-reference is refused.  It is not a table of its
 * own.  The words from 0x020A1394 onward are one two-dimensional array of
 * at least eleven rows of three handlers, indexed [operation][kind], and
 * the functions of this family each pin a different row:
 *
 *   row 0  0x020A1394   pooled at 0x0204D490
 *   row 1  0x020A13A0   pooled at 0x0204D45C
 *   row 3  0x020A13B8   pooled here
 *   row 5  0x020A13D0   pooled at 0x0204D130  (sub_0204D104)
 *   row 6  0x020A13DC   pooled at 0x0204D100
 *   row 7  0x020A13E8   pooled at 0x0204D428  (sub_0204D410)
 *   row 10 0x020A140C   pooled at 0x0204D3C4  (unit_0204D3C4.c)
 *
 * Declared that way the relocation names the array's base, 0x020A1394, and
 * the +0x24 is the row index coming from the C rather than from the bytes
 * under test; the base is attested `literal` by the pool word at 0x0204D490,
 * well outside this range.  Same bytes, same pool word, an honest witness.
 * See docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D324.c \
 *       --func func_0204D324 --addr 0x0204D324 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj0204D324 {
    u32 kind;
};

extern void (*const gUnk_020A1394[][3])(struct Obj0204D324 *obj, u32 arg);

void func_0204D324(struct Obj0204D324 *obj, u32 arg)
{
    gUnk_020A1394[3][obj->kind](obj, arg);
}
