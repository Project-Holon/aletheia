/*
 * unit:     no
 * function: sub_0204D478
 * address:  0x0204D478
 * packet:   pkt_0204D478
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   gUnk_020A1394  0x020A1394  data
 *
 * Row 0 of the eight-by-three handler table at 0x020A1394, the same shape as
 * src/matched/unit_0204D410.c (row 7), src/matched/unit_0204D444.c (row 1)
 * and src/matched/func_0204D324.c (row 3, and the row map).  Every concrete
 * byte is reproduced; the single unresolved site is the ABS32 in the pool.
 *
 * Blocked on: evidence class `literal`, and it can never be satisfied.  For
 * rows 1, 3, 5, 6 and 7 the pool word is base+0x0c..base+0x54, so some other
 * row's thunk holds a different word and the base is witnessed from outside.
 * Row 0's pool word *is* the array base, 0x020A1394, and `--suggest-split`
 * reports exactly one witness image-wide: this function's own relocation site
 * at 0x0204D490.  Self-reference is refused, so no cut can free it.  It would
 * become EXACT only if some future matched entry defines the table data at
 * 0x020A1394, or if a caller elsewhere is found that pools the bare base.
 *
 * The arity comes from the register pair, not from the call: the original
 * takes the kind in r3 and the table base in r2, which is the two-parameter
 * allocation (compare src/matched/func_0204D324.c).  The one-parameter
 * spelling allocates r2 then r1 and is a four-instruction diff.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204D478.c \
 *       --func sub_0204D478 --addr 0x0204D478 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj0204D478 {
    u32 kind;
};

typedef void *(*DispatchFn)(struct Obj0204D478 *o, u32 arg);

extern DispatchFn const gUnk_020A1394[][3];

void *sub_0204D478(struct Obj0204D478 *o, u32 arg)
{
    return gUnk_020A1394[0][o->kind](o, arg);
}
