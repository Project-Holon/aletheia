/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200DD8C
 * packet:   pkt_0200D6D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200DD8C, func_0200DDA8, func_0200DDD0
 *
 * 208 bytes, 0x0200DD8C..0x0200DE5C.  This file is the merge the wave 4A
 * report asked for: func_0200DD8C and func_0200DDA8 are each called from
 * exactly one instruction in the image, both inside func_0200DDD0, so as
 * separate files the caller could never attest them.  In one unit both
 * call sites are local and the whole range is EXACT.  See the header of
 * src/matched/unit_0200DD10.c for why the range starts at 0x0200DD8C.
 *
 * func_0200DD8C clears the 250-byte bitmap and then the four-byte stamp, in
 * that order and as two separate calls: the second one's size is four, not
 * the 254 a single call would have used, so the two fields are cleared
 * independently even though they are adjacent.
 *
 * func_0200DDA8 compares the first three words of two stamps and answers
 * whether the first is greater, with an early return per word rather than a
 * combined expression.  The fourth word is not compared, which is what makes
 * the stamp's last field a tag rather than part of the ordering.
 *
 * func_0200DDD0 is the query half of the 0xB90-byte block: it answers
 * whether the (a, b) pair has already been recorded and whether the stamp it
 * is asked about is newer than the stored one.  Four things pin the source:
 *  - the result local is initialised to 1 before the guard, and the bit
 *    mask is built off the register holding that 1 (see
 *    docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md);
 *  - the guard is one ||, not two statements (see
 *    docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md);
 *  - the stamp is unpacked into a local struct Stamp a byte at a time, big
 *    endian, stores in source order;
 *  - idx % 8 is the signed-modulo shift sequence with the shift amount
 *    truncated to u8 before the shift and the mask cast to u8 at the use
 *    (the sub_0200A6BC shape), and the byte index is (u8)(idx / 8).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MI_CpuFill8(void *dest, u8 value, u32 size);

struct Stamp {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
};

struct BlkB90 {
    u32 unk00;
    u8  unk04[250];
    u8  unkFE[0xA92];
};

void func_0200DD8C(struct BlkB90 *p)
{
    MI_CpuFill8(p->unk04, 0, sizeof(p->unk04));
    MI_CpuFill8(p, 0, sizeof(p->unk00));
}

u32 func_0200DDA8(const struct Stamp *a, const struct Stamp *b)
{
    if (a->unk00 > b->unk00) {
        return 1;
    }
    if (a->unk04 > b->unk04) {
        return 1;
    }
    if (a->unk08 > b->unk08) {
        return 1;
    }
    return 0;
}

int func_0200DDD0(struct BlkB90 *p, u8 a, u8 b, const struct Stamp *q)
{
    struct Stamp s;
    u16 idx;
    u8  sh;
    u32 r = 1;

    if (b > 200 || a > 10) {
        return 0;
    }
    s.unk00 = (u8)(p->unk00 >> 24);
    s.unk04 = (u8)(p->unk00 >> 16);
    s.unk08 = (u8)(p->unk00 >> 8);
    s.unk0C = (u8)p->unk00;
    if (func_0200DDA8(q, &s) != 0) {
        func_0200DD8C(p);
        return 0;
    }
    idx = (a - 1) * 200 + (b - 1);
    sh = idx % 8;
    if (!(p->unk04[(u8)(idx / 8)] & (u8)(1 << sh))) {
        r = 0;
    }
    return r;
}
