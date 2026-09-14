/*
 * unit:     no
 * function: sub_0204D410
 * address:  0x0204D410
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH*
 *
 * symbols:
 *   g_VTable_020A13E8  0x020A13E8  data
 *
 * One of the five index-dispatch thunks that close out this packet: the
 * object's first word is a small type index, the pool word is the base of a
 * per-operation function table, and the call is
 * `table[o->type](o)`.  `blx` rather than `bx` plus the `push {r3, lr}`
 * is the ordinary non-tail form: the result is returned unchanged, which
 * is what lets sub_0204D3A0 write through it directly.
 *
 * The register pair the load uses names the arity: this one allocates
 * r2 then r1, leaving r1 free, so the thunk forwards only r0.  Its
 * neighbour sub_0204D3C4 allocates r3 then r2 instead, because r1 is
 * already spoken for by a second forwarded argument
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * Byte-correct, capped at MATCH*: the ABS32 pool word naming the table
 * 0x020A13E8 is the only appearance of that address anywhere in the image,
 * so `literal` has no second pool to read it from and the table is plain
 * data, which rules out `label` and `veneer` too.  This is the same wall
 * every dispatch thunk in this family hits: see src/pending/func_0204D324.c
 * (table 0x020A13B8) and the same shape at 0x0204D3C4 (0x020A140C),
 * 0x0204D444 (0x020A13A0) and 0x0204D478 (0x020A1394).  The `*` is the
 * unlabelled follower: the three `add r0,r0,#0xc; bx lr` adjustor leaves at
 * 0x0204D42C, 0x0204D434 and 0x0204D43C save nothing, so disasm.py folds
 * them into this function's extent.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204D410.c \
 *       --func sub_0204D410 --addr 0x0204D410 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj {
    u32 type;
};

typedef void *(*DispatchFn)(struct Obj *o);

extern DispatchFn g_VTable_020A13E8[];

void *sub_0204D410(struct Obj *o)
{
    return g_VTable_020A13E8[o->type](o);
}
