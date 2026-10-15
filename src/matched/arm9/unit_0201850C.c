/*
 * unit:     yes
 * address:  0x0201850C
 * packet:   pkt_02017FB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_CalcLevelFromExp
 *
 * Experience to level.  This is the callee of id 0x9E of POKE_TOOL_GetBoxValueRaw
 * (src/pending/POKE_TOOL_GetBoxValueRaw.c), which passes it a species id, the five bit
 * form field of substruct B +0x18 and the experience word of substruct A +8.
 * It reads field 0x17 of the species' record, which is the growth-rate
 * selector, fills the shared word buffer at 0x02146398 with that curve through
 * POKE_TOOL_LoadExpTable, and then walks entries 1 to 0x64 for the first one that
 * exceeds the experience, returning the index before it.
 *
 * The loop is a `for` whose bound test the compiler rotates to the bottom, so
 * the first table read happens before any comparison with 0x65; the counter is
 * u16, which is what the `lsls #0x10` / `lsrs #0x10` pair after each increment
 * is, and writing it `u32` drops that pair and the function is four bytes
 * short.
 *
 * The range stops at 0x02018544, where an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk forwards to
 * POKE_TOOL_GetBoxLevelMinExp.  That thunk's pool word is the only reference to
 * POKE_TOOL_GetBoxLevelMinExp in the image, so including it caps the file at MATCH; it is
 * left out and this function is clean.
 *
 * 0x02146398 is the same scratch buffer POKE_TOOL_GetExpValue fills in
 * src/matched/unit_02019B58.c, which is what attests it here and what this
 * file's pool word attests there: the pairwise case of docs/MATCHING.md.
 *
 * Nothing here is version specific; 0x17 is a field selector and 0x65 is the
 * level table's length.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0201850C.c \
 *       --addr 0x0201850C --thumb
 *
 * symbols:
 *   gExpTableBuf  0x02146398  data
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_TOOL_LoadExpTable  0x02019B94  thumb
 *   POKE_TOOL_GetPersonalData  0x02019C54  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Personal;
extern void *POKE_TOOL_GetPersonalData(u32 a, u32 b);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void  POKE_TOOL_LoadExpTable(u32 a, void *b);

extern u32 gExpTableBuf[];

u32 POKE_TOOL_CalcLevelFromExp(u16 species, u16 form, u32 exp)
{
    u16 i;

    POKE_TOOL_LoadExpTable((u16)POKE_PERSONAL_GetParam(POKE_TOOL_GetPersonalData(species, form), 0x17),
                  gExpTableBuf);
    for (i = 1; i < 0x65; i = (u16)(i + 1)) {
        if (gExpTableBuf[i] > exp) {
            break;
        }
    }
    return i - 1;
}
