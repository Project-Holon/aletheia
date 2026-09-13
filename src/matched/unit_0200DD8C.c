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
 * function: func_0200DD8C, func_0200DDA8
 *
 * 68 bytes, 0x0200DD8C..0x0200DDD0, the two functions of the 0xB90-byte
 * block that follow the near miss at 0x0200DD28; see the header of
 * src/matched/unit_0200DD10.c for why the range is cut there.  Neither
 * carries a label in the generated listing.
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
 */

typedef unsigned char  u8;
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
