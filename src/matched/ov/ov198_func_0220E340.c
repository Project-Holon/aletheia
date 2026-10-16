/*
 * function: B_PLIST_DRAW_RegisterRowCharacters
 * address:  0x0220E340
 * packet:   pkt_ov198_0220E340
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * pass 2 2026-10-06 P2L21: EXACT (was 9 bytes off, arc/arr r6/r7 swap). Closing form: the A6C8 call and the
 *   array store written in each if/else arm, with the store address as integer arithmetic
 *   `*(int *)((u32)p + 0x24A4 + i * 4)` (no named array pointer; LICM hoists p + 0x24A4, the ov097 021F6F88
 *   `icons + i * 4` style). Either part alone stays at 9 bytes (named arr in both arms, or the integer
 *   address with one join store). EXACT in --lang c99 and --lang c.
 * symbols:
 *   B_PLIST_DRAW_RegisterRowCharacters  0x0220E340  thumb  ov198
 *   func_020490F4  0x020490F4  arm
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   POKE_TOOL_GetGraphicIndex  0x0201BA68  thumb
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   POKE_TOOL_GetIconPaletteArcId  0x0201BC3C  thumb
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   POKE_TOOL_GetIconCellArcIdSub  0x0201BC78  thumb
 *   POKE_TOOL_GetIconCellEntryIdSub  0x0201BCEC  thumb
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void *POKE_TOOL_GetBoxParam(void *p);
extern u32 POKE_TOOL_GetGraphicIndex(void *mon);
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern int CLACT_RegisterPaletteCompressed(void *h, u32 a1, u32 a2, u32 a3, u16 a4);
extern int POKE_TOOL_GetIconCellArcIdSub(void);
extern int POKE_TOOL_GetIconCellEntryIdSub(void);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);

void B_PLIST_DRAW_RegisterRowCharacters(u8 *p)
{
    void *arc;
    u16 i;

    arc = func_020490F4(7, (u16)((*(u16 *)(*(u8 **)p + 0x10) & 0x7FFF) | 0x8000));
    for (i = 0; i < 6; i++) {
        u8 *e = p + i * 0x4C;
        if (*(u16 *)(e + 8) != 0) {
            *(int *)((u32)p + 0x24A4 + i * 4) = CLACT_RegisterCharacter(arc, POKE_TOOL_GetGraphicIndex(POKE_TOOL_GetBoxParam(*(void **)(e + 4))), 0, 1, *(u16 *)(*(u8 **)p + 0x10));
        } else {
            *(int *)((u32)p + 0x24A4 + i * 4) = CLACT_RegisterCharacter(arc, POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0), 0, 1, *(u16 *)(*(u8 **)p + 0x10));
        }
    }
    *(int *)(p + 0x250C) = CLACT_RegisterPaletteCompressed(arc, POKE_TOOL_GetIconPaletteArcId(), 1, 0, *(u16 *)(*(u8 **)p + 0x10));
    *(s32 *)(p + 0x2524) = CLACT_RegisterCellAnim(arc, POKE_TOOL_GetIconCellArcIdSub(), POKE_TOOL_GetIconCellEntryIdSub(), *(u16 *)(*(u8 **)p + 0x10));
    ARC_TOOL_DeleteHandle(arc);
}
