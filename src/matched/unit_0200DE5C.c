/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200DE5C
 * packet:   pkt_0200DDD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200DE5C, func_0200DE64, func_0200DE6C, func_0200DE94,
 *           func_0200DEA0
 *
 * 76 bytes, 0x0200DE5C..0x0200DEA8, 5 functions, four of which carry no label
 * in the generated listing.
 *
 * One slot of a record that holds a 0x690-byte payload at +0x104 behind a
 * present flag at +0xFE and two byte tags at +0x100 and +0x101.
 * func_0200DE6C fills all four in one go, and the three constants it needs
 * are one constant in the compiled code: 0x104 is materialised once in r7 and
 * the two stores reach +0x101 and +0x100 as `subs r0, r7, #3` and
 * `subs r0, r7, #4`.  That is the compiler reusing a live value and not three
 * offsets in the source.
 *
 * The two getters are the same function at two neighbouring offsets and they
 * do not compile alike: +0x100 is `movs r1, #1` / `lsls r1, #8` and +0x101
 * needs a literal pool word, because the first is a shifted eight-bit
 * immediate and the second is not.  Neither offset fits a `ldrb` immediate,
 * whose reach is 31, so both are register-offset loads; see
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 */

typedef unsigned char  u8;

extern void MI_CpuCopy8(const void *src, void *dest, unsigned int size);

struct RecSlot {
    u8 unk000[0xFE];
    u8 unkFE;
    u8 unkFF;
    u8 unk100;
    u8 unk101;
    u8 unk102;
    u8 unk103;
    u8 unk104[0x690];
};

u8 func_0200DE5C(struct RecSlot *p)
{
    return p->unkFE;
}

u8 func_0200DE64(struct RecSlot *p)
{
    return p->unkFF;
}

void func_0200DE6C(struct RecSlot *p, const void *src, u8 a, u8 b)
{
    MI_CpuCopy8(src, p->unk104, sizeof(p->unk104));
    p->unk101 = a;
    p->unk100 = b;
    p->unkFE = 1;
}

u8 func_0200DE94(struct RecSlot *p)
{
    return p->unk101;
}

u8 func_0200DEA0(struct RecSlot *p)
{
    return p->unk100;
}
