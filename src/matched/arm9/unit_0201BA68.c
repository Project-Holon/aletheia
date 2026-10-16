/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201BA68
 * packet:   pkt_0201B038
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_GetGraphicIndex, POKE_TOOL_CalcGraphicIndex
 *
 * The graphics index of a Pokemon: POKE_TOOL_GetGraphicIndex unpacks the four values that
 * decide it out of the record and POKE_TOOL_CalcGraphicIndex turns them into a member number
 * of archive 7.  The pair that follows them, POKE_TOOL_CalcIconPalette and POKE_TOOL_GetIconPalette, is
 * the same index arithmetic over a different table and is parked in
 * src/pending/unit_0201BB5C.c because that table has no witness; the cut
 * between the two pairs is what lets this half land
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * POKE_TOOL_GetGraphicIndex brackets its four reads with POKE_TOOL_DecodeBoxParam and POKE_TOOL_EncodeBoxParam,
 * which is the pair the region uses around a run of raw field reads; that is
 * why the reads here are POKE_TOOL_GetBoxValue and not the POKE_TOOL_GetPartyValue of
 * src/matched/POKE_TOOL_CalcParam.c.  The fourth read is written inline as the call's
 * fourth argument rather than bound to a local, which is what puts it in r3
 * with the other three already in place.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Four content constants, and the index arithmetic that ties them together is
 * itself a statement about how the sprite archive is packed:
 *
 *   490    the species whose egg has a graphic of its own.  Every other
 *          species shares one egg graphic.
 *   650    the index the ordinary egg occupies, so 651 is that species' egg;
 *          the same 650/651 pair src/matched/unit_0201AFD4.c rejects as
 *          species ids.
 *   7      the first member of archive 7 that belongs to a species, and the
 *          stride is two members per index.
 *   1311   the member the alternate forms start at, which is 652 * 2 + 7, i.e.
 *          immediately after the two egg indices.  A White build with a
 *          different species count would move this number and only this one.
 *   0x1F, 0x20, 0x23   the three personal-record attributes POKE_TOOL_GetPersonalParam
 *          answers: the form block's first index, the form count, and the flag
 *          that says the forms are not drawn separately.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The `case 1` arm binds the archive query to a local before assigning the
 * gender.  Written inline, `gender = 1;` is hoisted in front of the `blx` and
 * six bytes come out in the wrong order; the named local is what pins the
 * order, the same way
 * docs/idioms/cmp-operand-order-names-the-temporary.md pins a comparison.
 *
 * `case 2`'s `gender = 0;` and `case 1`'s failure arm are one block, reached
 * by a `b` whose displacement is zero: the source writes the statement out in
 * both arms and the compiler cross-jumps the two copies
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).  The switch
 * is a `cmp`/`beq` chain rather than a table, because three labels are too few
 * for mwccarm to build one
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md, the other side of
 * the density rule).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201BA68.c \
 *       --addr 0x0201BA68 --thumb
 *
 * symbols:
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   POKE_TOOL_GetPersonalParam  0x02019C90  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern u32  POKE_TOOL_GetBoxValue(void *mon, u32 id, u32 v);
extern u32 POKE_TOOL_GetPersonalParam(u16 a, u16 b, u32 k);
extern u32  ARC_TOOL_GetMemberSize(u32 kind, u32 member);

u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);

u32 POKE_TOOL_GetGraphicIndex(void *mon)
{
    u32 save;
    u32 species;
    u32 form;
    u32 gender;
    u32 r;

    save = POKE_TOOL_DecodeBoxParam(mon);
    species = POKE_TOOL_GetBoxValue(mon, 5, 0);
    form = POKE_TOOL_GetBoxValue(mon, 0x6F, 0);
    gender = POKE_TOOL_GetBoxValue(mon, 0x6E, 0);
    r = POKE_TOOL_CalcGraphicIndex(species, form, gender, POKE_TOOL_GetBoxValue(mon, 0x4C, 0));
    POKE_TOOL_EncodeBoxParam(mon, save);
    return r;
}

u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg)
{
    u32 first;
    u32 hidden;
    u32 count;
    u32 idx;
    u32 ok;

    idx = species * 2 + 7;
    if (isEgg != 0) {
        idx = (u32)((species == 490 ? 1 : 0) + 650) * 2 + 7;
    } else if (form != 0) {
        first = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x1F);
        hidden = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x23);
        count = POKE_TOOL_GetPersonalParam((u16)species, 0, 0x20);
        if (form >= count) {
            form = 0;
        }
        if (hidden == 0 && form != 0) {
            idx = (first + form - 1) * 2 + 1311;
        }
    }
    switch (gender) {
    case 0:
        break;
    case 1:
        ok = ARC_TOOL_GetMemberSize(7, idx + 1);
        gender = 1;
        if (ok == 0) {
            gender = 0;
        }
        break;
    case 2:
        gender = 0;
        break;
    }
    return idx + gender;
}
