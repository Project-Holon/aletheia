/*
 * function: FIELD_MENU_LoadGraphics
 * address:  0x021A8874
 * packet:   pkt_ov021_021A8874
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D534  0x0207D534  arm
 *   gFieldMenuBgTemplate5     0x021D8BBC  data  a4
 *   gFieldMenuBgTemplate6     0x021D8B5C  data  a4
 *   gFieldMenuBgTemplate7     0x021D8B7C  data  a4
 *   gFieldMenuScreenIds     0x021D8B44  data  a4
 *   gFieldMenuSurfaceRect     0x021D8C1C  data  a4
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040618  0x02040618  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020409B4  0x020409B4  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   func_0204B92C  0x0204B92C  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Obj {
    u16 f00;
    u16 f02;
    u8 pad04[0x104 - 0x04];
    u32 f104;
    u32 f108;
    u32 f10C;
    u32 f110;
    u32 f114;
    u32 f118;
    u32 f11C;
    u32 f120;
    u32 f124;
    u32 f128;
} Obj;

typedef struct Pos {
    s16 x;
    s16 y;
    s16 z;
    u8 a;
    u8 b;
} Pos;

typedef struct Bank {
    u32 w[4];
} Bank;

extern const u8 gFieldMenuBgTemplate5[];
extern const u8 gFieldMenuBgTemplate6[];
extern const u8 gFieldMenuBgTemplate7[];
extern const u32 gFieldMenuScreenIds[];
extern const Bank gFieldMenuSurfaceRect;

struct Actor;
extern void func_0207D534(volatile u16 *reg, int brightness);
struct BgTemplate;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
typedef signed int     s32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020414EC(u32 i);
extern void func_02040618(u32 bgId, u32 which, u32 value);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_020275E4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void func_020409B4(u32 layer);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct Obj *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
extern void func_0204B92C(struct Obj *, u32);
extern void CLACT_SetActorBgPriority(u32, int);
extern void func_0204B3DC(struct Obj *, unsigned int);

void FIELD_MENU_LoadGraphics(Obj *p, void *q, int r, u32 unused)
{
    void *h;
    u32 t;
    Pos pos;
    Bank bank;

    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_0203FCA0(5, (const struct BgTemplate *)gFieldMenuBgTemplate5, 0);
    func_02040588(5, 1);
    func_020414EC(5);
    func_0203FCA0(6, (const struct BgTemplate *)gFieldMenuBgTemplate6, 0);
    func_02040588(6, 1);
    func_020414EC(6);
    func_0203FCA0(7, (const struct BgTemplate *)gFieldMenuBgTemplate7, 0);
    func_02040588(7, 1);
    func_020414EC(7);
    func_02040618(6, 3, -5);
    func_02049B68(q, 0, 4, 0, 0, p->f02);
    func_02049658(q, 2, 5, 0, 0, 0, p->f02);
    func_020498F4(q, gFieldMenuScreenIds[r], 5, 0, 0, 0, p->f02);
    func_020498F4(q, 0xE, 7, 0, 0, 0, p->f02);
    p->f104 = CLACT_RegisterPaletteEx(q, 1, 1, 0, 0, 0xB, p->f00);
    p->f108 = CLACT_RegisterCharacter(q, 0xD, 0, 1, p->f00);
    p->f10C = CLACT_RegisterCellAnim(q, 0x1C, 0x26, p->f00);
    h = func_020490F4(func_020275E4(), p->f02);
    p->f110 = CLACT_RegisterPaletteEx(h, func_02027614(), 1, 0x160, 0, 2, p->f00);
    p->f114 = CLACT_RegisterCharacter(h, func_02027618(), 0, 1, p->f00);
    t = func_0202761C(0);
    p->f118 = CLACT_RegisterCellAnim(h, t, func_02027620(0), p->f00);
    ARC_TOOL_DeleteHandle(h);
    func_020409B4(5);
    p->f11C = (u32)CLACT_CreateUnit(8, 0, p->f00);
    bank = gFieldMenuSurfaceRect;
    p->f120 = (u32)CLACT_CreateRenderer((u8 *)(&bank), 1, p->f00);
    func_0204B258((struct Bank *)p->f11C, (void *)p->f120);
    pos.x = 0x40;
    pos.y = 0x2C;
    pos.z = 0;
    pos.a = 0;
    pos.b = 0;
    p->f124 = (u32)CLACT_CreateActor((void *)p->f11C, p->f108, p->f104, p->f10C, &pos, 0, p->f00);
    CLACT_SetActorAutoAnimSpeed((struct Actor *)p->f124, 0x1000);
    func_0204B92C((struct Obj *)p->f124, 1);
    CLACT_SetActorBgPriority(p->f124, 2);
    pos.x = 0xE0;
    pos.y = 0xA8;
    p->f128 = (u32)CLACT_CreateActor((void *)p->f11C, p->f114, p->f110, p->f118, &pos, 0, p->f00);
    CLACT_SetActorAutoAnimSpeed((struct Actor *)p->f128, 0x1000);
    func_0204B92C((struct Obj *)p->f128, 1);
    func_0204B3DC((struct Obj *)p->f128, 1);
    CLACT_SetActorAutoAnimSpeed((struct Actor *)p->f128, 0x2000);
}
