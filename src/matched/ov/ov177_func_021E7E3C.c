/*
 * function: WIFIBATTLEMATCH_VIEW_CreatePartyWindow
 * address: 0x021E7E3C
 * packet: pkt_ov177_021E7E3C
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   d_021E8DBC 0x021E8DBC data a1
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb  arm9
 *   POKE_TOOL_GetIconPalette  0x0201BBE8  thumb  arm9
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 *   BMP_WIN_Create  0x020450F0  arm  arm9
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 *   BMP_WIN_MakeScreen  0x02045374  arm  arm9
 *   STRBUF_Create  0x020457B0  arm  arm9
 *   STRBUF_Delete  0x02045808  arm  arm9
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   CLACT_RegisterCharacter  0x0204A6C8  arm  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm  arm9
 *   CLACT_RegisterCellAnim  0x0204AF28  arm  arm9
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   CLACT_GetActorSurfacePos  0x0204B454  arm  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 *   POKE_TOOL_GetGraphicIndex  0x0201BA68  thumb  arm9
 *   BMP_WIN_GetBgLayer  0x02045730  arm  arm9
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9
 *   CLACT_AddActorSurfacePos  0x0204B404  arm  arm9
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm  arm9
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 *   APP_ICON_GetArchiveId  0x020275E4  thumb  arm9
 *   APP_ICON_GetItemCellFileId  0x02027694  thumb  arm9
 *   APP_ICON_GetItemPaletteFileId  0x02027698  thumb  arm9
 *   APP_ICON_GetItemAnimFileId  0x0202769C  thumb  arm9
 *   APP_ICON_GetItemFrameFileId  0x020276A0  thumb  arm9
 *   BG_SYS_FillScrollArea  0x02040618  arm  arm9
 *   BG_SYS_PushTile  0x020409B4  arm  arm9
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 *   POKE_TOOL_GetIconPaletteArcId  0x0201BC3C  thumb  arm9
 *   POKE_TOOL_GetIconCellArcId  0x0201BC40  thumb  arm9
 *   POKE_TOOL_GetIconCellEntryId  0x0201BCB4  thumb  arm9
 *
 * The temporary heap id is formed twice: once through an inline that
 * rewrites its own parameter (the image copies heap before the and), held
 * in r7 for the first block; then as a plain expression, which the
 * compiler CSEs into a temporary slot below the loop pointers. One shared
 * expression or one shared local CSEs both blocks together.
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x, y; } Pos;
typedef struct { short x, y; u16 id; u8 a, flag; } Request;
typedef struct { void *win; u8 shown; } Entry;
typedef struct {
    void *pal;
    void *chr[7];
    void *cell;
    void *chrB;
    void *palB;
    void *cellB;
    void *spr[14];
    void *win[6];
    Entry ent[6];
    unsigned count;
    short base[14];
} Work;
static inline unsigned HeapTemp(unsigned heap)
{
    heap &= 0x7FFF;
    heap |= 0x8000;
    return heap;
}
extern const char d_021E8DBC[];
extern void *func_02030734(unsigned heap, unsigned size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, unsigned, unsigned);
struct Cfg;
struct Descriptor;
struct U16Vec;
struct WordSet;
extern void *func_0200BAF4(int a0, int a1);
extern void func_0204989C(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, u16 flags);
extern void *func_020490F4(unsigned int id, unsigned heap);
extern int POKE_TOOL_GetIconPaletteArcId(void);
typedef signed int     s32;
typedef unsigned int   u32;
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int POKE_TOOL_GetIconCellArcId(void);
extern int POKE_TOOL_GetIconCellEntryId(void);
struct MsgBank;
struct Obj;
struct StrObj;
struct Vec2;
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern unsigned POKEPARTY_GetCount(void *party);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern unsigned POKE_TOOL_GetPartyValue(void *p, unsigned id, unsigned v);
extern void *POKE_TOOL_GetBoxParam(void *);
extern unsigned POKE_TOOL_GetGraphicIndex(void *);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *);
extern unsigned APP_ICON_GetArchiveId(void);
extern unsigned APP_ICON_GetItemCellFileId(void);
extern u32 APP_ICON_GetItemAnimFileId(u32 i);
extern u32 APP_ICON_GetItemFrameFileId(u32 i);
extern unsigned APP_ICON_GetItemPaletteFileId(void);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void *CLACT_CreateActor(void *, void *, void *, void *, const Request *, unsigned short, unsigned);
extern int POKE_TOOL_GetIconPalette(void *a0);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void *WORDSET_CreateDefault(u16);
extern void *STRBUF_Create(unsigned capacity, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *win);
extern void PRINTSYS_PrintQueColor(unsigned print, void *bmp, short x, short y, void *str, unsigned font, u16 color);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
struct Actor; struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern u32 func_020307B0(void *p);
extern void func_0207D63C(int, int, int, int, int);
Work *WIFIBATTLEMATCH_VIEW_CreatePartyWindow(void *src, void *owner, int unused, unsigned font, unsigned print, void *msg, unsigned heap)
{
    Work *work;
    void *party;
    void *handle;
    void *mon;
    u8 x;
    void *fmt;
    void *buf;
    void *sLevel;
    void *sMale;
    void *sFemale;
    void *win;
    u8 level;
    int i;
    unsigned h;
    Request req;
    Request req2;
    Pos pos;
    work = func_02030734(heap, sizeof(Work), 0, d_021E8DBC, 0xC8A);
    MI_CpuFill8(work, 0, sizeof(Work));
    h = HeapTemp(heap);
    party = func_0200BAF4((int)src, (u16)h);
    func_0204989C((int)0x85, (int)7, (int)2, (int)0, (int)0, (int)0, h);
    handle = func_020490F4(7, (unsigned)heap);
    work->pal = (void *)CLACT_RegisterPaletteCompressed(handle, POKE_TOOL_GetIconPaletteArcId(), 0, 0xA0, h);
    work->cell = (void *)CLACT_RegisterCellAnim(handle, POKE_TOOL_GetIconCellArcId(), POKE_TOOL_GetIconCellEntryId(), (u16)h);
    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        mon = POKEPARTY_GetMember(party, (int)i);
        if (POKE_TOOL_GetPartyValue(mon, 0xA9, 0) != 0) {
            work->chr[i] = (void *)CLACT_RegisterCharacter(handle, POKE_TOOL_GetGraphicIndex(POKE_TOOL_GetBoxParam(mon)), 0, 0, h);
        }
    }
    ARC_TOOL_DeleteHandle(handle);
    handle = func_020490F4(APP_ICON_GetArchiveId(), (unsigned)heap);
    work->chrB = (void *)CLACT_RegisterPaletteEx(handle, APP_ICON_GetItemCellFileId(), 0, 0x100, 0, 1, (heap & 0x7FFF) | 0x8000);
    work->cellB = (void *)CLACT_RegisterCellAnim(handle, APP_ICON_GetItemAnimFileId((int)2), APP_ICON_GetItemFrameFileId((int)2), (u16)((heap & 0x7FFF) | 0x8000));
    work->palB = (void *)CLACT_RegisterCharacter(handle, APP_ICON_GetItemPaletteFileId(), 0, 0, (heap & 0x7FFF) | 0x8000);
    ARC_TOOL_DeleteHandle(handle);
    MI_CpuFill8(&req, 0, 8);
    req.x = 0x18;
    req.y = 0x2C;
    req.id = 1;
    req.a = 1;
    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        mon = POKEPARTY_GetMember(party, (int)i);
        if (POKE_TOOL_GetPartyValue(mon, 0xA9, 0) != 0) {
            req.x = i * 0x28 + 0x18;
            work->spr[i] = CLACT_CreateActor(owner, work->chr[i], work->pal, work->cell, &req, 0, heap);
            CLACT_SetActorPaletteOffset(work->spr[i], POKE_TOOL_GetIconPalette(POKE_TOOL_GetBoxParam(mon)), 0);
            if (POKE_TOOL_GetPartyValue(mon, 6, 0) != 0) {
                req2 = req;
                req2.x += 12;
                req2.y += 8;
                req2.a = 0;
                req2.id = 0;
                work->spr[i + 7] = CLACT_CreateActor(owner, work->palB, work->chrB, work->cellB, &req2, 0, heap);
            }
        }
    }
    fmt = WORDSET_CreateDefault((u16)((heap & 0x7FFF) | 0x8000));
    buf = STRBUF_Create(0x80, (u16)((heap & 0x7FFF) | 0x8000));
    sLevel = func_02045EC0(msg, 0x63);
    sMale = func_02045EC0(msg, 0x64);
    sFemale = func_02045EC0(msg, 0x65);
    for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
        mon = POKEPARTY_GetMember(party, (int)i);
        if (POKE_TOOL_GetPartyValue(mon, 0xA9, 0) != 0) {
            work->win[i] = (void *)BMP_WIN_Create((unsigned char)1, (unsigned char)(i * 5 + 1), (unsigned char)4, (unsigned char)5, 6, 15, 1);
            win = work->win[i];
            BMP_WIN_TransferChars(win);
            BMP_WIN_MakeScreen(win);
            BG_SYS_PushTile((int)BMP_WIN_GetBgLayer(win));
            work->ent[i].win = work->win[i];
            work->ent[i].shown = 0;
            if (POKE_TOOL_GetPartyValue(mon, 0x6E, 0) == 0) {
                PRINTSYS_PrintQueColor(print, BMP_WIN_GetBmp(work->ent[i].win), 0x20, 0, sMale, font, 0x14C0);
                work->ent[i].shown = 1;
            } else if (POKE_TOOL_GetPartyValue(mon, 0x6E, 0) == 1) {
                PRINTSYS_PrintQueColor(print, BMP_WIN_GetBmp(work->ent[i].win), 0x20, 0, sFemale, font, 0xC80);
                work->ent[i].shown = 1;
            }
            level = POKE_TOOL_GetPartyValue(mon, 0x9E, 0);
            WORDSET_SetSlotNumber(fmt, 0, level, 3, 1, 1);
            WORDSET_CopyTaggedText(fmt, buf, sLevel);
            x = 20 - func_0201D304(buf, font, 0) / 2;
            PRINTSYS_PrintQueColor(print, BMP_WIN_GetBmp(work->ent[i].win), x, 0x24, buf, font, 0x440);
            work->ent[i].shown = 1;
        }
    }
    STRBUF_Delete(sFemale);
    STRBUF_Delete(sMale);
    STRBUF_Delete(sLevel);
    STRBUF_Delete(buf);
    WORDSET_DeleteStrbufED04(fmt);
    for (i = 0; i < 14; i++) {
        if (work->spr[i] != 0) {
            CLACT_GetActorSurfacePos(work->spr[i], (struct PtS *)&pos, 0);
            pos.x += 0x100;
            CLACT_AddActorSurfacePos(work->spr[i], (const struct Vec2 *)(&pos), 0);
        }
    }
    BG_SYS_FillScrollArea((int)2, (int)0, (int)(-0x100));
    BG_SYS_FillScrollArea((int)1, (int)0, (int)(-0x100));
    func_020307B0(party);
    func_0207D63C(0x04000050, 4, 8, 15, 3);
    return work;
}
