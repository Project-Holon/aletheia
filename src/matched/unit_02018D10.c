/*
 * unit:     yes
 * address:  0x02018D10
 * packet:   pkt_0201854C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02018D10, func_02018D34, func_02018D6C, func_02018D8C
 *
 * The four lock/unlock helpers every accessor wrapper in this region opens and
 * closes with.  The object is the same record as src/matched/unit_02017D30.c:
 * a seed word at +0x00, three flag bits at +0x04, a halfword checksum at
 * +0x06, an 0x80 byte area at +0x08 and a 0x54 byte area at +0x88, each
 * area XOR masked in place by func_02019A50.  Bit 2 of +0x04 is the sticky
 * "checksum did not match" flag func_02018D34 sets.
 *
 * The three flag tests are `lsls`/`lsrs` pairs of width one, which is the
 * bitfield shape of docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md;
 * spelling them as masks gives movs/ands instead.
 *
 * symbols:
 *   func_02019A50  0x02019A50  thumb
 *   func_02019A9C  0x02019A9C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02019A50(void *p, u32 size, u32 seed);
extern u16  func_02019A9C(const void *p, u32 size);

struct Sav {
    u32 unk00;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 13;
    u16 unk06;
    u8  unk08[0x80];
    u8  unk88[0x54];
};

u32 func_02018D34(struct Sav *p);
void func_02018D8C(struct Sav *p);

u32 func_02018D10(struct Sav *p)
{
    u32 r = 1;

    if (p->b0 == 0) {
        func_02019A50(p->unk88, 0x54, p->unk00);
        r = func_02018D34(p);
    }
    return r;
}

u32 func_02018D34(struct Sav *p)
{
    u32 r = 1;
    u16 sum;

    if (p->b1 == 0) {
        func_02019A50(p->unk08, 0x80, p->unk06);
        sum = func_02019A9C(p->unk08, 0x80);
        if (sum != p->unk06) {
            r = 0;
            p->b2 = 1;
        }
    }
    return r;
}

void func_02018D6C(struct Sav *p)
{
    if (p->b0 == 0) {
        func_02019A50(p->unk88, 0x54, p->unk00);
        func_02018D8C(p);
    }
}

void func_02018D8C(struct Sav *p)
{
    if (p->b1 == 0) {
        p->unk06 = func_02019A9C(p->unk08, 0x80);
        func_02019A50(p->unk08, 0x80, p->unk06);
    }
}
