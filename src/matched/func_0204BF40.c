/*
 * function: func_0204BF40
 * address:  0x0204BF40
 * packet:   pkt_0204BF40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02063294  0x02063294  arm
 *
 * Push one OAM entry through the window at `win`, rewriting its palette field
 * on the way.  The caller's 8-byte entry is copied onto the stack first
 * (MI_CpuCopy8, not a struct assignment: the source is only 2-aligned), then
 * the 4-bit palette in bits 12..15 of the attribute halfword at +4 is either
 * BIASED by `pal` (mode 0) or REPLACED with it (mode 1); any other mode leaves
 * the entry alone.  The rewritten copy, not the caller's, is what reaches
 * func_02063294.
 *
 * The bias arm is written as a store through a pointer to the halfword's word
 * (`add r2, sp, #4` then `ldr`/`str` through r2), which is what makes the
 * image reload the base instead of re-using sp; the replace arm is small
 * enough that 1.1p1 predicates it whole
 * (`ldreq`/`lsleq`/`biceq`/`orreq`/`streq`) and needs no such pointer.
 *
 * Signature pinned from src/matched/func_0204BFC4.c, the one filed caller.
 *
 * BYTE-CORRECT, PARKED, NOT FILED.  132 bytes, 0 concrete mismatches; the sole
 * unresolved site is the PC24 to func_02063294 at +0x78.  Blocking evidence
 * class: `label` -- 0x02063294 has no branch anywhere in the image outside
 * 0x0204BF40..0x0204BFC4, and there is no `matched` entry for it
 * (docs/notes/pkt_02063078.c.txt records it as a DIFF, 228 bytes).  Filing
 * func_02063294 unblocks this file with no change to the C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BF40.c \
 *       --func func_0204BF40 --addr 0x0204BF40 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Win;

struct OamEntry {
    u16 attr[4];
};

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32  func_02063294(struct Win *win, struct OamEntry *entry, u32 mode);

void func_0204BF40(struct Win *win, struct OamEntry *src, u32 mode, u32 pal,
                   u32 op)
{
    struct OamEntry ent;
    u32 *attr2;

    MI_CpuCopy8(src, &ent, sizeof(ent));

    if (op == 0) {
        attr2 = (u32 *)&ent.attr[2];
        *attr2 = (*attr2 & ~0xf000) |
                 ((((u32)(u16)*attr2 >> 12) + pal) << 28 >> 16);
    } else if (op == 1) {
        *(u32 *)&ent.attr[2] = (*(u32 *)&ent.attr[2] & ~0xf000) |
                               (pal << 28 >> 16);
    }

    func_02063294(win, &ent, mode);
}
