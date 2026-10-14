/*
 * function: DENDOU_VIEW_SwitchRowActors
 * address: 0x021DE388
 * packet: pkt_ov171_021DE388
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wave D4 lane08: EXACT. The slot pointer is assigned in each if/else arm (two definitions, so it is not
 *   forwarded to its single use; the shared arm tails merge), and slot is declared before v (slots 0x1c/0x18).
 * symbols:
 *   DENDOU_VIEW_SetActorVisible 0x021DE064 thumb ov171
 *   DENDOU_VIEW_CreateActor 0x021DE290 thumb ov171
 *   DENDOU_VIEW_PlaceActorOnEllipse 0x021DE608 thumb ov171
 *   DENDOU_VIEW_DeleteActor 0x021DE34C thumb ov171
 *   DENDOU_VIEW_ReleaseCharacter 0x021DE1F8 thumb ov171
 *   DENDOU_VIEW_ReleasePalette 0x021DE218 thumb ov171
 *   DENDOU_VIEW_ReleaseCellAnim 0x021DE238 thumb ov171
 *   DENDOU_VIEW_SortActorPriorities 0x021DE684 thumb ov171
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKEGRA_RegisterCgr 0x0202D81C thumb
 *   POKEGRA_RegisterPalette 0x0202D7D8 thumb
 *   POKEGRA_RegisterCellAnim 0x0202D898 thumb
 *   POKE_TOOL_CheckShiny 0x02017ED8 thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   sMemberActorTemplates 0x021DEC04 data a4
 *   sMemberSlotsByCount 0x021DEC94 data a4
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct E { u32 w[6]; };
struct Ent { u32 f0; u32 f4; u32 f8; u32 fc; u16 f10; u8 f12; u8 a : 6; u8 b : 2; };
extern const struct E sMemberActorTemplates[];
extern const struct E sMemberSlotsByCount[];
struct PalAnmSlot;
extern void DENDOU_VIEW_SetActorVisible(int *p, int i, int a);
struct Obj;
extern struct Obj *DENDOU_VIEW_CreateActor(char *p, const char *q);
extern void DENDOU_VIEW_PlaceActorOnEllipse(char *, int, int);
extern void DENDOU_VIEW_DeleteActor(char *, int);
extern void DENDOU_VIEW_ReleaseCharacter(char *, int);
extern void DENDOU_VIEW_ReleasePalette(char *, int);
extern void DENDOU_VIEW_ReleaseCellAnim(char *, int);
extern void DENDOU_VIEW_SortActorPriorities(u8 *p);
extern int POKEGRA_OpenHandle(int a0);
extern u32 POKEGRA_RegisterCgr(u32, u32, u32, u32, u32, u32, u32, u32, u32, u16);
extern u32 POKEGRA_RegisterPalette(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern u32 POKEGRA_RegisterCellAnim(u32, u32, u32, u32, u32, u32, u32, u32, u16);
extern u32 POKE_TOOL_CheckShiny(u32, u32);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void ARC_TOOL_DeleteHandle(u32);
void DENDOU_VIEW_SwitchRowActors(char *p) {
    u32 i;
    u32 h;
    char *rec;
    u32 *slot;
    u32 v;
    struct Ent *r;
    u32 x;
    struct E e;
    for (i = 0; i <= 11; i++) DENDOU_VIEW_SetActorVisible((int *)p, i, 0);
    rec = p + 0xc + (s8)p[0xC5E] * 0xbc;
    h = POKEGRA_OpenHandle(0x808C);
    {
        for (i = 0; i < *(u16 *)(rec + 0xb8); i++) {
            e = sMemberActorTemplates[i];
            r = (struct Ent *)(rec + i * 0x1c);
            x = POKE_TOOL_CheckShiny(r->fc, r->f8);
            if (*(u8 *)(p + 0xC60) == 1) {
                e.w[2] += 6;
                e.w[3] += 6;
                e.w[4] += 6;
                v = (u16)(i + 6);
                slot = (u32 *)(p + 0xB74 + v * 4);
            } else {
                v = (u16)i;
                slot = (u32 *)(p + 0xB74 + v * 4);
            }
            *(u32 *)(p + e.w[2] * 4 + 0xBB4) = POKEGRA_RegisterCgr(h, r->f10, r->a, r->b, x, 0, 0, r->f8, 0, 0x8c);
            *(u32 *)(p + e.w[3] * 4 + 0xBE8) = POKEGRA_RegisterPalette(h, r->f10, r->a, r->b, x, 0, 0, 0, (u16)(v << 5), 0x8c);
            *(u32 *)(p + e.w[4] * 4 + 0xC1C) = POKEGRA_RegisterCellAnim(r->f10, r->a, r->b, x, 0, 0, 2, 0, 0x8c);
            *slot = (u32)DENDOU_VIEW_CreateActor(p, (const char *)(&e));
            DENDOU_VIEW_PlaceActorOnEllipse(p, v, *(u16 *)((char *)sMemberSlotsByCount + *(u16 *)(rec + 0xb8) * 0x18 + i * 4 - 0x18));
            *(u16 *)(p + i * 2 + 0xB10) = *(u16 *)((char *)sMemberSlotsByCount + *(u16 *)(rec + 0xb8) * 0x18 + i * 4 - 0x18);
        }
    }
    PALANM_CopyHwPaletteToSlot(*(void **)(p + 0xB30), 2, 0, 0x200);
    ARC_TOOL_DeleteHandle(h);
    if (*(u8 *)(p + 0xC60) == 1) {
        for (i = 0; i <= 5; i++) DENDOU_VIEW_DeleteActor(p, i);
        for (i = 0; i <= 5; i++) DENDOU_VIEW_ReleaseCharacter(p, i);
        for (i = 0; i <= 5; i++) DENDOU_VIEW_ReleasePalette(p, i);
        for (i = 0; i <= 5; i++) DENDOU_VIEW_ReleaseCellAnim(p, i);
    } else {
        for (i = 6; i <= 11; i++) DENDOU_VIEW_DeleteActor(p, i);
        for (i = 6; i <= 11; i++) DENDOU_VIEW_ReleaseCharacter(p, i);
        for (i = 6; i <= 11; i++) DENDOU_VIEW_ReleasePalette(p, i);
        for (i = 6; i <= 11; i++) DENDOU_VIEW_ReleaseCellAnim(p, i);
    }
    *(u8 *)(p + 0xC60) ^= 1;
    DENDOU_VIEW_SortActorPriorities((u8 *)p);
}
