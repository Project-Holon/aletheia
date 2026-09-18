/*
 * function: func_0203A70C
 * address:  0x0203A70C
 * packet:   pkt_0203A574
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * isa:      arm
 * status:   DIFF
 * blocker:  four instructions: the original loads *q into r1 and uses a scaled index as the load offset, this build loads *q into r0 first
 *
 * symbols:
 *   func_0203A67C  0x0203A67C  arm
 *
 * Indexes the eight-byte records behind func_0203A67C's pointer and returns
 * the first word of the record, or 0 when the pointer is null.  The scale of
 * eight is the `lsl #24` / `lsr #21` pair: the index is narrowed to a byte and
 * shifted up three, which is the source's `idx` times `sizeof` a two-word
 * record, spelled by the compiler as two shifts instead of a mask and a shift.
 * src/matched/func_0203A748.c is the same accessor for the second word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A70C.c \
 *       --func func_0203A70C --addr 0x0203A70C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Pair {
    u32 a;
    u32 b;
};

extern void *func_0203A67C(void);

u32 func_0203A70C(u32 idx)
{
    struct Pair **q;

    q = (struct Pair **)func_0203A67C();
    if (q == 0)
        return 0;
    return (*q)[idx].a;
}
