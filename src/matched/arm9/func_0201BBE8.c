/*
 * function: POKE_TOOL_GetIconPalette
 * address:  0x0201BBE8
 * packet:   pkt_0201BB5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * EXACT* note: the 84 byte body reproduces exactly; the inferred extent runs to
 * the next label because of 4-byte `movs r0, #0; bx lr` leaf with no prologue at 0x0201BC3C (unlabelled).
 *
 * symbols:
 *   POKE_TOOL_DecodeBoxParam   0x02017DBC  thumb
 *   func_02017E88   0x02017E88  thumb
 *   POKE_TOOL_EncodeBoxParam   0x02017DE4  thumb
 *   POKE_TOOL_CalcIconPalette   0x0201BB5C  thumb
 *
 * Five reads of the same save block, one flag read that is kept raw (no
 * truncation) and handed back to POKE_TOOL_EncodeBoxParam as the second argument, then
 * the four values are forwarded to POKE_TOOL_CalcIconPalette and its result returned.
 * Four arguments means the call cannot become a tail call, so it stays a
 * `bl` and the function keeps a real epilogue.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_GetIconPalette.c \
 *       --func POKE_TOOL_GetIconPalette --addr 0x0201BBE8 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);

int POKE_TOOL_GetIconPalette(void *a0)
{
    int f = POKE_TOOL_DecodeBoxParam(a0);
    u32 a = func_02017E88(a0, 5, 0);
    u32 b = func_02017E88(a0, 0x6F, 0);
    u32 c = func_02017E88(a0, 0x6E, 0);
    u32 d = func_02017E88(a0, 0x4C, 0);

    POKE_TOOL_EncodeBoxParam(a0, f);
    return POKE_TOOL_CalcIconPalette(a, b, c, d);
}
