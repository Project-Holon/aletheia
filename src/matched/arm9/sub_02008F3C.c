/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * function: MAIL_Copy
 * address:  0x02008F3C
 * packet:   pkt_02008A34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *
 * Original (6 bytes plus a literal pool, leaf):
 *   ldr  r3, [pc, #4]
 *   movs r2, #0x38
 *   bx   r3
 *
 * A whole-object copy of the 0x38-byte object described in
 * src/matched/unit_02008F80.c.  Both pointer arguments are already in the
 * registers MI_CpuCopy8 wants, so the only work is the size and the tail call;
 * the `bx r3` rather than a `blx` is what a tail call to an ARM function
 * through a pool word looks like, and the pool word carries the Thumb bit
 * clear because the callee is ARM.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub02008F80Obj {
    u8 unk00[0x38];
};

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

void MAIL_Copy(const struct Sub02008F80Obj *src, struct Sub02008F80Obj *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Sub02008F80Obj));
}
