/*
 * function: ITEMMENU_SetupGraphics
 * address:  0x021B9280
 * packet:   pkt_ov070_021B9280
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note 2026-10-05 (wave D9r lane71): EXACT. The last 2 bytes (+0x15A movs vs copy of r4) closed with
 *   the real return type of ARC_UTIL_UploadBgPaletteAddFromHandle: void (u32 in the draft kept one more value in the IR between
 *   the 02008550 join and the 0x58 close). The contested data hints d_021BBBE0 and d_021BBAB0 resolve as
 *   "data a4" (no overlay token). Earlier wave notes (D3 to D9r) are in git history.
 * symbols:
 *   ITEMMENU_InitDisplayBanks  0x021B8F98  thumb  ov070
 *   ITEMMENU_LoadBagGraphics  0x021B9178  thumb  ov070
 *   ITEMMENU_LoadTabGraphics  0x021B91FC  thumb  ov070
 *   ITEMMENU_CreateSideButtonActors  0x021BA6F4  thumb  ov070
 *   ITEMMENU_UpdateInputGuardAnim  0x021BB5A4  thumb  ov070
 *   d_021BBBE0  0x021BBBE0  data a4
 *   d_021BBA8C  0x021BBA8C  data  ov070
 *   d_021BBAB0  0x021BBAB0  data a4
 *   GF_FONT_ResetTextColor  0x0201DD60  thumb  arm9
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm  arm9
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm  arm9
 *   BMP_WIN_Init  0x02045088  arm  arm9
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm  arm9
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm  arm9
 *   CLACT_InitSystem  0x0204A48C  arm  arm9
 *   CLACT_RegisterCharacter  0x0204A6C8  arm  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_RegisterCellAnim  0x0204AF28  arm  arm9
 *   CLACT_CreateUnit  0x0204B100  arm  arm9
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm  arm9
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *   BG_SYS_Create  0x0203F8F4  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u16 x, y, z; u8 a, b; } Rect;
typedef struct { u32 w[4]; } Tbl16;
extern u8 d_021BBBE0[];
extern u8 d_021BBA8C[];
extern const Tbl16 d_021BBAB0;
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void GF_FONT_ResetTextColor(void);
struct Bank;
struct Cfg;
struct DispConfig;
struct DispVram;
struct Obj;
struct Sub0200852CObj;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void ITEMMENU_InitDisplayBanks(void);
extern void GF_FONT_SetDefaultTextColor(void);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern u32 ITEMMENU_LoadBagGraphics(char *p, int bg);
extern void ITEMMENU_LoadTabGraphics(char *p, void *bg);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void func_020409B4(u32 index);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ITEMMENU_CreateSideButtonActors(char *p);
extern u32 func_020275E4(void);
extern u32 func_020275E8(void);
extern u32 func_020275FC(u32 a);
extern u32 func_02027600(u32 a);
extern u32 func_02027610(u32 a);
extern u32 func_020275F8(u32 a);
extern u8 func_02027604(u8 i);
extern u8 func_020275EC(int i);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void ITEMMENU_UpdateInputGuardAnim(char *p);

static inline void LoadIcons(u8 *p)
{
    void *a;
    u32 m;
    u32 i;

    a = func_020490F4(func_020275E4(), *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x5E0) = CLACT_RegisterPaletteEx(a, func_020275E8(), 1, 0x80, 0, 3, *(u16 *)(p + 0x544));
    m = func_020275FC(2);
    *(u32 *)(p + 0x5E4) = CLACT_RegisterCellAnim(a, m, func_02027600(2), *(u16 *)(p + 0x544));
    for (i = 0; i < 3; i++)
        *(u32 *)(p + i * 4 + 0x5E8) = CLACT_RegisterCharacter(a, func_02027610((u8)i), 0, 1, *(u16 *)(p + 0x544));
    for (i = 0; i < 17; i++)
        *(u32 *)(p + i * 4 + 0x59C) = CLACT_RegisterCharacter(a, func_020275F8((u8)i), 0, 1, *(u16 *)(p + 0x544));
    ARC_TOOL_DeleteHandle(a);
}

void ITEMMENU_SetupGraphics(u8 *p)
{
    Tbl16 t;
    Rect r2;
    Rect r1;
    Rect r0;
    void *h;
    u32 v;
    u32 i;

    *(volatile u16 *)0x04000050 = 0;
    BG_SYS_Create(*(u16 *)(p + 0x544));
    BMP_WIN_Init(*(u16 *)(p + 0x544));
    GF_FONT_ResetTextColor();
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BBBE0);
    CLACT_InitSystem((const struct Cfg *)d_021BBA8C, (u32)d_021BBBE0, *(u16 *)(p + 0x544));
    t = d_021BBAB0;
    func_0203FC28((struct DispConfig *)(&t));
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    ITEMMENU_InitDisplayBanks();
    GF_FONT_SetDefaultTextColor();
    *(u32 *)(p + 0x838) = (u32)func_0201F5DC((void *)3, 13, 0, *(u16 *)(p + 0x544));
    h = func_020490F4(0x58, *(u16 *)(p + 0x544));
    func_02049B68(h, 8, 4, 0, 0, *(u16 *)(p + 0x544));
    if (func_02008550((const struct Sub0200852CObj *)(*(u32 *)(p + 8))) == 0)
        ARC_UTIL_UploadPaletteFromHandle(h, 8, 4, 0x20, 0, 0x20, *(u16 *)(p + 0x544));
    v = func_02049740(h, 6, 4, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x7FC) = v;
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 7, 4, 0, (u16)v, 0, 0, *(u16 *)(p + 0x544));
    ITEMMENU_LoadBagGraphics((char *)p, (int)h);
    v = func_02049740(h, 0x11, 5, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x800) = v;
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 0x17, 5, 0, (u16)v, 0, 0, *(u16 *)(p + 0x544));
    ITEMMENU_LoadTabGraphics((char *)p, h);
    *(u32 *)(p + 0x808) = func_02049740(h, 0x21, 3, 0, 0, *(u16 *)(p + 0x544));
    func_02049B68(h, 0x22, 0, 0x60, 0x20, *(u16 *)(p + 0x544));
    ARC_TOOL_DeleteHandle(h);
    func_02049B40(0x17, 5, 0, 0x180, 0x20, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x69C) = (u32)CLACT_CreateUnit(0x34, 0, *(u16 *)(p + 0x544));
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    h = func_020490F4(0x53, *(u16 *)(p + 0x544));
    func_02049B68(h, 0x1B, 0, 0x100, 0x20, *(u16 *)(p + 0x544));
    v = func_02049740(h, 0x1C, 1, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x804) = v;
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 0x1D, 1, 0, (u16)v + 0x8000, 0, 0, *(u16 *)(p + 0x544));
    func_020409B4(1);
    *(u32 *)(p + 0x55C) = CLACT_RegisterPaletteEx(h, 0x13, 0, 0x140, 0, 3, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x564) = CLACT_RegisterCharacter(h, 0x14, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x570) = CLACT_RegisterCellAnim(h, 0x17, 0x1A, *(u16 *)(p + 0x544));
    ARC_TOOL_DeleteHandle(h);
    ITEMMENU_CreateSideButtonActors((char *)p);
    LoadIcons(p);
    r2.x = 0x50;
    r2.y = 0xB8;
    r2.a = 1;
    r2.b = 1;
    r2.z = 0;
    for (i = 0; i < 3; i++) {
        *(u32 *)(p + i * 4 + 0x6C0) = (u32)CLACT_CreateActor((void *)(*(u32 *)(p + 0x69C)), *(u32 *)(p + i * 4 + 0x5E8), *(u32 *)(p + 0x5E0), *(u32 *)(p + 0x5E4), &r2, 1, *(u16 *)(p + 0x544));
        CLACT_SetActorPaletteOffset((struct Obj *)(*(u32 *)(p + i * 4 + 0x6C0)), func_02027604((u8)i), 1);
        CLACT_SetActorDrawEnable((struct Obj *)(*(u32 *)(p + i * 4 + 0x6C0)), 0);
    }
    r1.x = 0x52;
    r1.y = 0xA5;
    r1.a = 1;
    r1.b = 1;
    r1.z = 0;
    for (i = 0; i < 17; i++) {
        *(u32 *)(p + i * 4 + 0x6CC) = (u32)CLACT_CreateActor((void *)(*(u32 *)(p + 0x69C)), *(u32 *)(p + i * 4 + 0x59C), *(u32 *)(p + 0x5E0), *(u32 *)(p + 0x5E4), &r1, 1, *(u16 *)(p + 0x544));
        CLACT_SetActorPaletteOffset((struct Obj *)(*(u32 *)(p + i * 4 + 0x6CC)), func_020275EC((u8)i), 1);
        CLACT_SetActorDrawEnable((struct Obj *)(*(u32 *)(p + i * 4 + 0x6CC)), 0);
    }
    h = func_020490F4(0x58, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x580) = CLACT_RegisterPaletteEx(h, 0x27, 0, 0x80, 0, 2, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x584) = CLACT_RegisterCharacter(h, 0x26, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x58C) = CLACT_RegisterCellAnim(h, 0x25, 0x24, *(u16 *)(p + 0x544));
    ARC_TOOL_DeleteHandle(h);
    r0.a = 10;
    r0.b = 1;
    r0.x = 0x92;
    r0.y = 0xB0;
    r0.z = 0;
    *(u32 *)(p + 0x72C) = (u32)CLACT_CreateActor((void *)(*(u32 *)(p + 0x69C)), *(u32 *)(p + 0x584), *(u32 *)(p + 0x580), *(u32 *)(p + 0x58C), &r0, 0, *(u16 *)(p + 0x544));
    CLACT_SetActorAutoAnim((struct Obj *)(*(u32 *)(p + 0x72C)), 1);
    CLACT_SetActorDrawEnable((struct Obj *)(*(u32 *)(p + 0x72C)), 1);
    ITEMMENU_UpdateInputGuardAnim((char *)p);
}
