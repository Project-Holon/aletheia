/*
 * unit:     yes
 * function: func_02047348, func_02047388, func_020473B8
 * address:  0x02047348
 * packet:   pkt_02047260
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0206E964   0x0206E964  arm
 *
 * Three consecutive accessors on the object a layer record points at
 * through +4, 64 + 48 + 32 bytes with no padding between them.  The object
 * carries three "ready" bits, one per halfword at +0x10, +0x20 and +0x32,
 * and each bit guards the word at +8, +0x18 and +0x2c respectively.
 *
 * func_02047348 asks whether any of the three is set: the first two tests
 * are early `return 1`s, which is why they branch forward to a shared
 * one-exit and the third is written as the inverted guard (`if (!bit)
 * return 0;`) whose fall-through carries the `return 1`.
 *
 * func_02047388 and func_020473B8 return the guarded word itself, so their
 * arms are single instructions and the compiler if-converts them into
 * predicated `ldrne` / `moveq` on the entry compare; the third test in
 * func_02047388 is the one that stays a real branch pair.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02047348.c \
 *       --addr 0x02047348 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Layer {
    u8    pad_00[4];
    void *unk_04;
};

struct Ctl {
    u8  pad_00[8];
    u32 unk_08;
    u8  pad_0c[4];
    u16 unk_10;
    u8  pad_12[6];
    u32 unk_18;
    u8  pad_1c[4];
    u16 unk_20;
    u8  pad_22[0xa];
    u32 unk_2c;
    u8  pad_30[2];
    u16 unk_32;
};

extern unsigned char *func_0206E964(unsigned char *p);

int func_02047348(struct Layer *layer)
{
    struct Ctl *p = (struct Ctl *)func_0206E964(layer->unk_04);

    if ((p->unk_10 & 1) || (p->unk_20 & 1) || (p->unk_32 & 1))
        return 1;
    return 0;
}

u32 func_02047388(struct Layer *layer)
{
    struct Ctl *p = (struct Ctl *)func_0206E964(layer->unk_04);

    if (p->unk_10 & 1)
        return p->unk_08;
    if (p->unk_20 & 1)
        return p->unk_18;
    return 0;
}

u32 func_020473B8(struct Layer *layer)
{
    struct Ctl *p = (struct Ctl *)func_0206E964(layer->unk_04);

    if (p->unk_32 & 1)
        return p->unk_2c;
    return 0;
}
