/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02045730
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02045730, sub_02045738, sub_02045740, sub_02045748,
 *           sub_02045750, sub_02045758, sub_02045760, sub_02045768,
 *           sub_02045770, sub_02045778, sub_02045780, sub_02045788,
 *           sub_02045790, sub_02045798
 *
 * The leaf accessor bank of the allocator family's descriptor object.
 * Fourteen relocation-free 8-byte functions in a row, each one load or
 * store of a single field, which is why they can be folded into one unit
 * with no witnesses required at all.
 *
 * The descriptor they read is the argument block the surrounding
 * constructors carry around (sub_02045334, at the head of this packet,
 * uses the same offsets: +2, +5, +6, +0xa, +0xc). The fields this bank
 * exposes:
 *
 *   +0x02  u8   sub_02045730 get
 *   +0x03  u8   sub_02045758 get / sub_02045780 set
 *   +0x04  u8   sub_02045760 get / sub_02045788 set
 *   +0x05  u8   sub_02045738 get
 *   +0x06  u8   sub_02045740 get
 *   +0x07  u8   sub_02045748 get
 *   +0x08  u8   sub_02045750 get / sub_02045790 set
 *   +0x09  u8   sub_02045778 get / sub_02045798 set
 *   +0x0a  u16  sub_02045768 get
 *   +0x0c  void *  sub_02045770 get
 *
 * sub_02045770 is the heap-handle getter of this family: the pointer it
 * returns at +0xc is what sub_02045334 feeds to sub_020437D4 before the
 * allocation call at 0x02040B1C, so +0xc is the descriptor's heap /
 * owning-context handle rather than a payload pointer. It carries the
 * largest fan-in of the whole bank (1149 branch references image-wide),
 * which is consistent with every user of a descriptor reaching for its
 * heap handle.
 *
 * Only sub_02045730, sub_02045738, sub_02045740, sub_02045748,
 * sub_02045750, sub_02045758, sub_02045760, sub_02045768, sub_02045770,
 * sub_02045778 and sub_02045798 carry labels in the listing.
 * sub_02045780, sub_02045788 and sub_02045790 are unlabelled followers:
 * they save no lr, so disasm.py folds them into sub_02045778's extent
 * (see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md). They
 * should be seeded into layout/function_starts.txt by the integrator.
 *
 * Field names are left descriptive rather than semantic: this whole
 * family is scheduled for a semantic rename once the allocator's argument
 * shapes settle.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02045730.c \
 *       --addr 0x02045730 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct Descriptor {
    u8    unk0;
    u8    unk1;
    u8    unk2;
    u8    unk3;
    u8    unk4;
    u8    unk5;
    u8    unk6;
    u8    unk7;
    u8    unk8;
    u8    unk9;
    u16   unkA;
    void *heap;
};

u8 sub_02045730(struct Descriptor *p)
{
    return p->unk2;
}

u8 sub_02045738(struct Descriptor *p)
{
    return p->unk5;
}

u8 sub_02045740(struct Descriptor *p)
{
    return p->unk6;
}

u8 sub_02045748(struct Descriptor *p)
{
    return p->unk7;
}

u8 sub_02045750(struct Descriptor *p)
{
    return p->unk8;
}

u8 sub_02045758(struct Descriptor *p)
{
    return p->unk3;
}

u8 sub_02045760(struct Descriptor *p)
{
    return p->unk4;
}

u16 sub_02045768(struct Descriptor *p)
{
    return p->unkA;
}

void *sub_02045770(struct Descriptor *p)
{
    return p->heap;
}

u8 sub_02045778(struct Descriptor *p)
{
    return p->unk9;
}

void sub_02045780(struct Descriptor *p, u8 v)
{
    p->unk3 = v;
}

void sub_02045788(struct Descriptor *p, u8 v)
{
    p->unk4 = v;
}

void sub_02045790(struct Descriptor *p, u8 v)
{
    p->unk8 = v;
}

void sub_02045798(struct Descriptor *p, u8 v)
{
    p->unk9 = v;
}
