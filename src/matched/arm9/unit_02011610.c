/*
 * unit:     yes
 * function: func_02011610, func_02011638, func_02011660
 * address:  0x02011610
 * packet:   pkt_020113F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   -
 *
 * ica_anime.c, 0x02011610..0x02011688: three copies of one accessor on three
 * parallel field pairs, each of which copies a twelve-byte record out of a
 * table indexed by the current frame.
 *
 *   func_02011610   guard +0x28, table +0x1C
 *   func_02011638   guard +0x2C, table +0x20
 *   (0x02011660)    guard +0x30, table +0x24 - unlabelled in the listing
 *                   (no prologue: the function saves nothing), written here
 *                   as the third copy
 *
 * The index is `(f10 >> 12) - f14`, which is why the original does an asrs
 * by twelve and then a subtract before the multiply by twelve, and the copy
 * itself is one twelve-byte struct assignment (ldm/stm pair plus the third
 * word).  Returning 0 when the table pointer is null is what makes the two
 * epilogues.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011610.c \
 *       --addr 0x02011610 --thumb
 */

typedef unsigned char  u8;
typedef signed int     s32;
typedef unsigned int  u32;

struct Rec12 {
    s32 a;
    s32 b;
    s32 c;
};

struct IcaAnime {
    u8  pad00[0x0C];
    u32 f0c;        /* +0x0C */
    s32 f10;        /* +0x10 */
    s32 f14;        /* +0x14 */
    s32 f18;        /* +0x18 */
    s32 f1c;        /* +0x1C */
    s32 f20;        /* +0x20 */
    s32 f24;        /* +0x24 */
    s32 f28;        /* +0x28 */
    s32 f2c;        /* +0x2C */
    s32 f30;        /* +0x30 */
    s32 f34;        /* +0x34 */
};

u32 func_02011610(struct IcaAnime *p, struct Rec12 *dst)
{
    if (p->f28 != 0) {
        dst[0] = ((struct Rec12 *)p->f1c)[(p->f10 >> 12) - p->f14];
        return 1;
    }
    return 0;
}

u32 func_02011638(struct IcaAnime *p, struct Rec12 *dst)
{
    if (p->f2c != 0) {
        dst[0] = ((struct Rec12 *)p->f20)[(p->f10 >> 12) - p->f14];
        return 1;
    }
    return 0;
}

u32 func_02011660(struct IcaAnime *p, struct Rec12 *dst)
{
    if (p->f30 != 0) {
        dst[0] = ((struct Rec12 *)p->f24)[(p->f10 >> 12) - p->f14];
        return 1;
    }
    return 0;
}
