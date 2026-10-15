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
 * function: POKE_TOOL_DecodeCalcBlock, POKE_TOOL_DecodeBoxBlock, POKE_TOOL_EncodeCalcBlock, POKE_TOOL_EncodeBoxBlock
 *
 * The four lock/unlock helpers every accessor wrapper in this region opens and
 * closes with.  The object is the same record as src/matched/unit_02017D30.c:
 * a seed word at +0x00, three flag bits at +0x04, a halfword checksum at
 * +0x06, an 0x80 byte area at +0x08 and a 0x54 byte area at +0x88, each
 * area XOR masked in place by POKE_CRYPTO_XorBlock.  Bit 2 of +0x04 is the sticky
 * "checksum did not match" flag POKE_TOOL_DecodeBoxBlock sets.
 *
 * The three flag tests are `lsls`/`lsrs` pairs of width one, which is the
 * bitfield shape of docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md;
 * spelling them as masks gives movs/ands instead.
 *
 * symbols:
 *   POKE_CRYPTO_XorBlock  0x02019A50  thumb
 *   POKE_CRYPTO_Checksum  0x02019A9C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void POKE_CRYPTO_XorBlock(u16 *p, u32 size, u32 seed);
extern u16 POKE_CRYPTO_Checksum(const u16 *p, u32 size);

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

u32 POKE_TOOL_DecodeBoxBlock(struct Sav *p);
void POKE_TOOL_EncodeBoxBlock(struct Sav *p);

u32 POKE_TOOL_DecodeCalcBlock(struct Sav *p)
{
    u32 r = 1;

    if (p->b0 == 0) {
        POKE_CRYPTO_XorBlock((u16 *)p->unk88, 0x54, p->unk00);
        r = POKE_TOOL_DecodeBoxBlock(p);
    }
    return r;
}

u32 POKE_TOOL_DecodeBoxBlock(struct Sav *p)
{
    u32 r = 1;
    u16 sum;

    if (p->b1 == 0) {
        POKE_CRYPTO_XorBlock((u16 *)p->unk08, 0x80, p->unk06);
        sum = POKE_CRYPTO_Checksum((const u16 *)p->unk08, 0x80);
        if (sum != p->unk06) {
            r = 0;
            p->b2 = 1;
        }
    }
    return r;
}

void POKE_TOOL_EncodeCalcBlock(struct Sav *p)
{
    if (p->b0 == 0) {
        POKE_CRYPTO_XorBlock((u16 *)p->unk88, 0x54, p->unk00);
        POKE_TOOL_EncodeBoxBlock(p);
    }
}

void POKE_TOOL_EncodeBoxBlock(struct Sav *p)
{
    if (p->b1 == 0) {
        p->unk06 = POKE_CRYPTO_Checksum((const u16 *)p->unk08, 0x80);
        POKE_CRYPTO_XorBlock((u16 *)p->unk08, 0x80, p->unk06);
    }
}
