/*
 * function: func_0202B7BC
 * address:  0x0202B7BC
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Parked: the only site, the ABS32 at +0008, names 0x0202AB5C, which is a
 * four-byte Thumb linker veneer (`ldr r3, [pc, #0]; bx r3` followed by the word
 * 0x0202AC61 - measured at 0x0202AB5C..0x0202AB60) sitting in the word run
 * before 0x0202AB64.  veneer_at() admits only the two ARM encodings, so the
 * `veneer` class refuses a Thumb stub; `label` has no label (disasm.py prints
 * it as data), `literal` has no pool word outside this range, and no C spelling
 * produces the stub, so it can never be a manifest entry.  Permanent.
 *
 * symbols:
 *   func_0202AB5C  0x0202AB5C  thumb
 */

typedef unsigned int u32;

struct Obj;

extern u32 func_0202AB5C(u32 v);

u32 func_0202B7BC(struct Obj *o)
{
    return func_0202AB5C(*(u32 *)((char *)o + 0x10));
}
