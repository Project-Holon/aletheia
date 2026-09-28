/*
 * unit:     yes
 * address:  0x02012204
 * packet:   pkt_02011EC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02012204, func_02012210
 *
 * The getter and the clearer of bit 0 of the byte at +0x33 of the same
 * 0x34-byte context record src/matched/unit_020120F0.c describes.  The
 * `lsls #0x1f` / `lsrs #0x1f` pair is a one bit field, not a cast: 32 - 31 is
 * not an integer width, which is
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md, and the
 * clearer's `movs r1, #1` / `bics` is what `p->unk33_0 = 0;` compiles to
 * because Thumb has no immediate bic.  Neither function has a relocation.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012204.c  *       --addr 0x02012204 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Ctx {
    u8 unk00[0x33];
    u8 unk33_0 : 1;
    u8 unk33_1 : 7;
};

u32 func_02012204(const struct Ctx *p)
{
    return p->unk33_0;
}

void func_02012210(struct Ctx *p)
{
    p->unk33_0 = 0;
}
