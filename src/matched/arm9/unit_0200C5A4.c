/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200C5A4
 * packet:   pkt_0200C52C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200C5A4, func_0200C5C8
 *
 * 84 bytes, 0x0200C5A4..0x0200C5F8, 2 functions, both of which carry a label
 * in the generated listing.
 *
 * alias: inside "musical_dist_save.c"; see src/matched/unit_0200C6D8.c for
 * how the file name at 0x020A71D4 is attested.  The record the file works on
 * is 0x2C bytes: a heap id at +0x00, a flag at +0x04, a state counter at
 * +0x08, a 0x10-byte header at +0x0C, the working buffer at +0x1C, the
 * buffer's base again at +0x20, the payload at base + 0x10 in +0x24, and the
 * system pointer at +0x28.  Every field is pinned by the constructor at
 * 0x0200C52C and by func_0200C5F8, neither of which is in this range; see the
 * two near misses below.
 *
 * func_0200C5A4 is the destructor.  The guard around the buffer free is
 * written as a plain `if`, and the fall-through arm is the free, so the test
 * in the source is `p->unk1C != 0` and not the inverse; see
 * docs/idioms/the-fall-through-arm-is-the-source-order.md.
 *
 * Two near misses bracket this range, and they are of different kinds.
 *
 *  - func_0200C52C, 118 bytes, the constructor.  It is a codegen miss and not
 *    an evidence one: 0x0200C52C is attested by one branch from an overlay,
 *    so it resolves here as `label`.  The original spends one instruction
 *    this source cannot buy, `movs r7, #6` at 0x0200C56C, which parks the
 *    save-block id in a callee-saved register so that the second use of it
 *    (the func_020073D8 call at 0x0200C560) is a register copy rather than a
 *    second `movs`.  Doing so costs the original a register, and the visible
 *    consequence is that the first parameter is homed to the stack at entry
 *    (`str r0, [sp, #4]`) while the func_02012EBC result keeps r6; every
 *    source shape tried here does the reverse and is 116 bytes against the
 *    original's 118.  Thirty-six shapes were compiled and ranked by diff
 *    count: six permutations of the three field stores crossed with four
 *    positions for the func_020072CC call, the result as a named local
 *    against the call written inline in the `if`, the id 6 as a literal
 *    against a local, five declaration orders for the locals, and a six
 *    argument reading of func_020072CC.  The ranking is flat at 57 to 80
 *    concrete bytes and every one of them is 116 bytes, so the missing
 *    instruction is not reachable by statement order.  All nine front ends
 *    agree, at every optimisation level.  Same class as the near misses at
 *    0x0200B2A4 and 0x0200B37C: a register the original spends and the source
 *    does not.
 *  - func_0200C5F8, 224 bytes, the state machine.  Every concrete byte of it
 *    reproduces; it is capped at MATCH because 0x0200A7F8 is branched to from
 *    exactly one instruction in the whole image, its own call at 0x0200C680,
 *    so the `label` class has no witness left once that call is inside the
 *    compared range and no cut helps.  The source is parked in
 *    src/matched/unit_0200C5F8.c.
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);
struct Big;
struct Sub020072A4Ctrl;
extern void *func_02012EBC(struct Big *p);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern u32 func_020307B0(void *p);

struct DistHdr {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
};

struct MusicalDist {
    u16 unk00;
    u32 unk04;
    u32 unk08;
    struct DistHdr unk0C;
    void *unk1C;
    void *unk20;
    u8   *unk24;
    void *unk28;
};

extern struct MusicalDist *func_0200C52C(void *sys, u32 heap);

void func_0200C5A4(struct MusicalDist *p)
{
    func_020072A4(func_02012EBC(p->unk28), 6);
    if (p->unk1C != 0) {
        func_020307B0(p->unk1C);
    }
    func_020307B0(p);
}

struct MusicalDist *func_0200C5C8(void *sys, const void *src, u32 size,
                                  u32 heap)
{
    struct MusicalDist *p = func_0200C52C(sys, heap);

    if (p->unk1C != 0) {
        p->unk0C.unk00 = size;
        MI_CpuCopy8(&p->unk0C, p->unk1C, sizeof(p->unk0C));
        MI_CpuCopy8(src, p->unk24, size);
    }
    return p;
}
