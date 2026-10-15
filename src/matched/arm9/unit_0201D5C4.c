/*
 * unit:     yes
 * address:  0x0201D5C4
 * packet:   pkt_0201CEE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GF_FONT_GetTagChar, GF_FONT_CheckD5CC, GF_FONT_GetTagGroup, GF_FONT_AppendTag,
 *           GF_FONT_GetTagKind, GF_FONT_GetTagParam, GF_FONT_SkipTag
 *
 * The message-tag primitives of the text stack, seven functions and 216 bytes.
 * A tag is a run of halfwords opening with 0xF000: the halfword at +2 packs a
 * group in its high byte and a kind in its low byte, +4 is the parameter count,
 * and the parameters follow at +6.  GF_FONT_SkipTag steps a cursor over one tag
 * and is what every walker in this region loops on.
 *
 * Three of the seven carry no label in the generated listing, because a
 * two-instruction leaf saves nothing and disasm.py's prologue sweep never fires
 * on it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md);
 * GF_FONT_GetTagGroup, GF_FONT_GetTagKind and GF_FONT_GetTagParam were read out of the `.word`
 * run the listing prints.
 *
 * Three details cost time and each is in an existing idiom:
 *
 *   - `k == 1 || k == 2` compiles to a `subs` / `cmp` / `bhi` range check and is
 *     two bytes short.  The original compares twice, which is what a `switch`
 *     with two empty falling case labels gives.
 *   - the group byte is `(u8)(p[1] >> 8)` and the shift is an `asrs`, because
 *     the u16 promotes to a signed int before the shift; writing the field as
 *     u32 gives `lsrs` and one wrong byte.
 *   - GF_FONT_GetTagParam indexes with `*(p + i + 3)`, not `p[3 + i]`.  The subscript
 *     form folds the addition into the index and scales once, the pointer form
 *     scales `i` and leaves the +3 as the load's immediate, which is
 *     docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * GF_FONT_AppendTag's parameter count is `u16`, not `u32`: it is passed straight to
 * STRBUF_AppendChar with no truncation, and a `u32` parameter costs the `lsls` /
 * `lsrs` pair there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201D5C4.c \
 *       --addr 0x0201D5C4 --thumb
 *
 * symbols:
 *   STRBUF_AppendChar  0x02045AFC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct U16Vec;
extern void STRBUF_AppendChar(struct U16Vec *vec, u16 value);

u32 GF_FONT_GetTagChar(void)
{
    return 0xF000;
}

u32 GF_FONT_CheckD5CC(const u16 *p)
{
    u32 k;

    if (p[0] == 0xF000) {
        k = (u8)(p[1] >> 8);
    } else {
        k = 0xFF;
    }
    switch (k) {
    case 1:
    case 2:
        return 1;
    }
    return 0;
}

u32 GF_FONT_GetTagGroup(const u16 *p)
{
    if (p[0] == 0xF000) {
        return (u8)(p[1] >> 8);
    }
    return 0xFF;
}

void GF_FONT_AppendTag(void *s, u32 b, u32 c, u16 n, const u16 *arr)
{
    u32 i;

    STRBUF_AppendChar(s, 0xF000);
    STRBUF_AppendChar(s, (u16)((u16)(b << 8) | c));
    STRBUF_AppendChar(s, n);
    for (i = 0; i < n; i = (u8)(i + 1)) {
        STRBUF_AppendChar(s, arr[i]);
    }
}

u32 GF_FONT_GetTagKind(const u16 *p)
{
    if (p[0] == 0xF000) {
        return (u8)p[1];
    }
    return 0xFF;
}

u32 GF_FONT_GetTagParam(const u16 *p, u32 i)
{
    if (p[0] == 0xF000) {
        return *(p + i + 3);
    }
    return 0;
}

u16 *GF_FONT_SkipTag(u16 *p)
{
    if (p[0] == 0xF000) {
        return p + 3 + p[2];
    }
    return p;
}
