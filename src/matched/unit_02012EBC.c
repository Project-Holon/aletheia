/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: sub_02012EBC, sub_02012EC0, sub_02012EC4, sub_02012ED0,
 *           sub_02012ED8
 * address:  0x02012EBC
 * packet:   pkt_02012E4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Five leaf accessors on one large record.  Offsets 0x5ec and 0x688 are out
 * of Thumb immediate reach so each costs a pool word, while 0x680 is
 * 0x1a << 6 and is rematerialised with `movs`/`lsls` instead.  Two of the
 * five read the same word at +0, which the compiler keeps as two separate
 * sections rather than folding.  None saves lr, so none is labelled.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012EBC.c \
 *       --addr 0x02012EBC --thumb
 */

typedef unsigned char u8;

struct Big {
    void *unk_00;
    u8   pad_04[0x5e8];
    u8   unk_5ec;
    u8   pad_5ed[0x93];
    u8   unk_680;
    u8   pad_681[7];
    void *unk_688;
};

void *sub_02012EBC(struct Big *p)
{
    return p->unk_00;
}

void *sub_02012EC0(struct Big *p)
{
    return p->unk_00;
}

u8 *sub_02012EC4(struct Big *p)
{
    return &p->unk_5ec;
}

u8 *sub_02012ED0(struct Big *p)
{
    return &p->unk_680;
}

void *sub_02012ED8(struct Big *p)
{
    return p->unk_688;
}
