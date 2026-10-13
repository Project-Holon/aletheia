/*
 * unit:     yes
 * address:  0x0201BB5C
 * note:     224 bytes, two functions
 * packet:   pkt_0201BB5C
 * function: POKE_TOOL_CalcIconPalette, POKE_TOOL_GetIconPalette
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The nibble-table twin of src/matched/unit_0201BA68.c: the same egg and
 * alternate-form index arithmetic, indexing a packed table of two four bit
 * values per entry instead of an archive.  POKE_TOOL_GetIconPalette unpacks the four
 * inputs out of a Pokemon record, bracketed by the POKE_TOOL_DecodeBoxParam /
 * POKE_TOOL_EncodeBoxParam pair, and hands them over.
 *
 * The index is the same logical number unit_0201BA68.c computes, one step
 * short of it: there the answer is `n * 2 + 7`, a member of archive 7, here it
 * is `n` itself, and the alternate-form case reaches it as `first + form +
 * 651` where the other reaches `(first + form - 1) * 2 + 1311`.  1311 is
 * 652 * 2 + 7, so the two agree.
 *
 * ---------------------------------------------------------------------------
 * WHY IT WAS CAPPED (HISTORY)
 * ---------------------------------------------------------------------------
 * NO LONGER CAPPED (re-verified 2026-09-22).  The pool word at 0x0201BBE4 is
 * still the only word in the image that holds 0x0209E474, so the `literal`
 * class does discard its only witness.  What closed it is the sole-ref
 * widening of 2026-09-21: 0x0209E474 is 4-aligned and starts a recognised
 * data object, so the site now resolves as `sole-ref` and the unit is EXACT.
 * The old "WHY IT IS CAPPED" reading below is kept only as history.
 *
 * The cut between this pair and POKE_TOOL_GetGraphicIndex/POKE_TOOL_CalcGraphicIndex is what let those
 * two land EXACT.  POKE_TOOL_CalcIconPalette is reached only from 0x0201BC34, inside this
 * range, so that call is the `local` class and needs no evidence.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 *   490    the species whose egg has an entry of its own.
 *   650    the ordinary egg's index, so 651 is that species' egg; 651 again is
 *          the base the alternate-form block is counted from.
 *   0x1F, 0x20, 0x23   the three personal-record attributes func_02019C90
 *          answers: the form block's first index, the form count, and the
 *          "not drawn separately" flag.
 *   0x0209E474  the table itself, one packed byte per index.  Its contents are
 *          content and are not reproduced here.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The two returns are unequal shift pairs, not bitfields: `lsls #0x14` /
 * `lsrs #0x18` is `(u8)(x >> 4)`, because 32 - 24 is the width and 20 - 24 is
 * the shift, and the low half's equal pair is a plain `(u8)`
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * The mask has to be written out as well as the cast; `x >> 4` on its own
 * loses the `ands`.
 *
 * symbols:
 *   _IconPaletteTable  0x0209E474  data
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_0201BB5C.c \
 *       --addr 0x0201BB5C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern u32  func_02017E88(void *mon, u32 id, u32 v);
extern u32 func_02019C90(u16 a, u16 b, u32 k);

extern const u8 _IconPaletteTable[];

u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg)
{
    u32 first;
    u32 hidden;
    u32 count;
    u32 idx;

    idx = species;
    if (isEgg != 0) {
        idx = (species == 490 ? 1 : 0) + 650;
    } else if (form != 0) {
        first = func_02019C90((u16)species, 0, 0x1F);
        hidden = func_02019C90((u16)species, 0, 0x23);
        count = func_02019C90((u16)species, 0, 0x20);
        if (form >= count) {
            form = 0;
        }
        if (hidden == 0 && form != 0) {
            idx = first + form + 651;
        }
    }
    if (half != 0) {
        return (u8)((_IconPaletteTable[idx] & 0xF0) >> 4);
    }
    return (u8)(_IconPaletteTable[idx] & 0xF);
}

u32 POKE_TOOL_GetIconPalette(void *mon)
{
    u32 save;
    u32 species;
    u32 form;
    u32 gender;
    u32 isEgg;

    save = POKE_TOOL_DecodeBoxParam(mon);
    species = func_02017E88(mon, 5, 0);
    form = func_02017E88(mon, 0x6F, 0);
    gender = func_02017E88(mon, 0x6E, 0);
    isEgg = func_02017E88(mon, 0x4C, 0);
    POKE_TOOL_EncodeBoxParam(mon, save);
    return POKE_TOOL_CalcIconPalette(species, form, gender, isEgg);
}
