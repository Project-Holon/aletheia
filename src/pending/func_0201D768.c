/*
 * function: func_0201D768
 * address:  0x0201D768
 * packet:   pkt_0201D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *
 * gf_font.c: appends `len` bytes to the wrap-around byte ring at +0x18 of the
 * string object, `n` bytes per iteration, wrapping the write cursor at +0x00
 * back to zero when it reaches the ring size at +0x04.  Returns the ring base
 * plus the cursor's value on entry.
 *
 * NOT byte-correct.  DIFF, 92 bytes against 92, 72 concrete bytes out.  It is
 * parked here rather than in src/matched because only EXACT belongs there, and
 * it is a source file rather than a note because the size is now exact and the
 * residue is a single localised fact: the two spilled values sit in each
 * other's frame slots.
 *
 *   ORIGINAL   len -> [sp]   total -> [sp,#4]   base -> [sp,#8]   start -> [sp,#0xc]
 *   COMPILED   len -> [sp]   start -> [sp,#4]   base -> [sp,#8]   total -> [sp,#0xc]
 *
 * Blocking class: none, this is not an evidence problem.  The single
 * relocation (MI_CpuCopy8 at +0x2C) resolves `label` with 529 witnesses.  What
 * is blocking is codegen: 72 concrete bytes, same instruction multiset, same
 * size, frame slots mirrored.
 *
 * `total` is volatile because the original SPILLS the byte counter and reloads
 * it from [sp,#4] every iteration; a plain u32 keeps it in a register and the
 * function comes out 90 bytes, two short.  `base` is assigned twice on purpose
 * (docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md), which
 * reproduces the original's two `str r0, [sp, #8]`.
 *
 * Fourteen further spellings are measured in docs/notes/func_0201D768.diff.c.txt,
 * including the permuter's hill run from this point; every size-exact one lands
 * on 72 and every one that reaches 64 costs size.
 *
 * Worth more than its own row: an EXACT here makes func_0201D6D8 EXACT, and
 * func_0201D6D8 is the only-branch-in-the-image site that caps sub_0201C758 in
 * src/pending/unit_0201C6FC.c through the `matched` class.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MI_CpuCopy8(void *dst, const void *src, u32 size);

u8 *func_0201D768(u16 *p, u8 *dst, u32 len, u32 n)
{
    volatile u32 total = 0;
    u8 *base;
    u16 start;
    base = (u8 *)p;
    base = base + 0x18;
    start = p[0];

    if (len > 0) {
        do {
            u16 head = p[0];
            MI_CpuCopy8(dst, base + head, n);
            head = (u16)(head + n);
            if (head >= p[2]) {
                head = 0;
            }
            p[0] = head;
            dst += n;
            total = (u16)(total + n);
        } while (total < len);
    }
    return base + start;
}
