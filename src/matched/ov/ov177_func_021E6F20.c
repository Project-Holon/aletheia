/*
 * function: WIFIBATTLEMATCH_VIEW_CreatePokeActors
 * address: 0x021E6F20
 * packet: pkt_ov177_021E6F20
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   REGULATION_Party_GetValue 0x0200B214 thumb
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb  arm9
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   CLACT_RegisterCharacter  0x0204A6C8  arm  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm  arm9
 *   CLACT_RegisterCellAnim  0x0204AF28  arm  arm9
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   POKE_TOOL_CalcIconPalette  0x0201BB5C  thumb  arm9
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   APP_ICON_GetArchiveId  0x020275E4  thumb  arm9
 *   APP_ICON_GetItemCellFileId  0x02027694  thumb  arm9
 *   APP_ICON_GetItemPaletteFileId  0x02027698  thumb  arm9
 *   APP_ICON_GetItemAnimFileId  0x0202769C  thumb  arm9
 *   APP_ICON_GetItemFrameFileId  0x020276A0  thumb  arm9
 *   POKE_TOOL_GetIconPaletteArcId  0x0201BC3C  thumb  arm9
 *   POKE_TOOL_GetIconCellArcId  0x0201BC40  thumb  arm9
 *   POKE_TOOL_GetIconCellEntryId  0x0201BCB4  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x, y; u16 id; u8 a, flag; } Request;
typedef struct {
    char pad0[0x16c];
    void *objs[22];      /* 0x16c */
    void *chr[6];        /* 0x1c4 */
    char pad1dc[4];
    void *cell;          /* 0x1e0 */
    void *pal;           /* 0x1e4 */
    char pad1e8[0x1f4 - 0x1e8];
    void *pal2;          /* 0x1f4 */
    void *chr2;          /* 0x1f8 */
    void *cell2;         /* 0x1fc */
    char pad200[0x232 - 0x200];
    u8 palSlot;          /* 0x232 */
    u8 pad233;
    u32 layer;           /* 0x234 */
} Work;
extern void *func_020490F4(u32 id, u32 heap);
struct Obj;
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern int POKE_TOOL_GetIconCellArcId(void);
extern int POKE_TOOL_GetIconCellEntryId(void);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
typedef signed int     s32;
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
struct Rec1E;
extern s32 REGULATION_Party_GetValue(struct Rec1E *p, u32 id, u8 n);
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetItemCellFileId(void);
extern u32 APP_ICON_GetItemPaletteFileId(void);
extern u32 APP_ICON_GetItemAnimFileId(u32);
extern u32 APP_ICON_GetItemFrameFileId(u32);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void MI_CpuFill8(void *, u32, u32);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern u32 POKE_TOOL_CalcIconPalette(u32, u32, u32, u32);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
void WIFIBATTLEMATCH_VIEW_CreatePokeActors(Work *w, void *owner, void *rec, u16 heap)
{
    u8 form;
    u8 shown;
    void *h;
    u16 species;
    u8 gender;
    int i;
    Request req, sub;
    h = func_020490F4(7, heap);
    w->pal = (void *)CLACT_RegisterPaletteCompressed(h, POKE_TOOL_GetIconPaletteArcId(), w->layer, (u16)(w->palSlot << 5), (heap & 0x7fff) | 0x8000);
    w->cell = (void *)CLACT_RegisterCellAnim(h, POKE_TOOL_GetIconCellArcId(), POKE_TOOL_GetIconCellEntryId(), heap);
    for (i = 0; i < 6; i++) {
        species = REGULATION_Party_GetValue(rec, 0, i);
        form = REGULATION_Party_GetValue(rec, 1, i);
        gender = REGULATION_Party_GetValue(rec, 3, i);
        w->chr[i] = (void *)CLACT_RegisterCharacter(h, POKE_TOOL_CalcGraphicIndex((u16)(species != 0 ? species : 1), form, gender, 0), 0, w->layer, (heap & 0x7fff) | 0x8000);
    }
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(APP_ICON_GetArchiveId(), heap);
    w->pal2 = (void *)CLACT_RegisterPaletteEx(h, APP_ICON_GetItemCellFileId(), w->layer, (u16)((w->palSlot + 3) << 5), (u32)0, (u32)1, (heap & 0x7fff) | 0x8000);
    w->chr2 = (void *)CLACT_RegisterCharacter(h, APP_ICON_GetItemPaletteFileId(), 0, w->layer, (heap & 0x7fff) | 0x8000);
    w->cell2 = (void *)CLACT_RegisterCellAnim(h, APP_ICON_GetItemAnimFileId(2), APP_ICON_GetItemFrameFileId(2), heap);
    ARC_TOOL_DeleteHandle(h);
    MI_CpuFill8(&req, 0, 8);
    req.y = 0xa8;
    req.id = 1;
    req.flag = 1;
    req.a = 1;
    for (i = 0; i < 6; i++) {
        species = REGULATION_Party_GetValue(rec, 0, i);
        form = REGULATION_Party_GetValue(rec, 1, i);
        gender = REGULATION_Party_GetValue(rec, 3, i);
        shown = REGULATION_Party_GetValue(rec, 2, i);
        if (species != 0) {
            req.x = (i << 5) + 0x120;
            w->objs[i] = CLACT_CreateActor(owner, (unsigned int)w->chr[i], (unsigned int)w->pal, (unsigned int)w->cell, &req, w->layer, heap);
            CLACT_SetActorPaletteOffset(w->objs[i], POKE_TOOL_CalcIconPalette(species, form, gender, 0), 0);
            if (shown != 0) {
                sub = req;
                sub.x += 12;
                sub.y += 8;
                sub.a = 0;
                sub.id = 0;
                w->objs[i + 15] = CLACT_CreateActor(owner, (unsigned int)w->chr2, (unsigned int)w->pal2, (unsigned int)w->cell2, &sub, w->layer, heap);
            } else {
                w->objs[i + 15] = 0;
            }
        } else {
            w->objs[i] = 0;
            w->objs[i + 15] = 0;
        }
    }
}
