/*
 * function: REPORT_InitActors
 * address:  0x021F0724
 * packet:   pkt_ov034_021F0724
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   REPORT_InitActors 0x021F0724 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0201AB28 0x0201AB28 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   sReportActorPositions    0x021F0A60 data a2
 */
#include "../include/Obj00166.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct {
    s16 x;
    s16 y;
    u16 c;
    u16 d;
} Rect;

struct Bank;
struct Ctx;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef signed int     s32;
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern unsigned int func_0201AA18(void *);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_0201AB28(void *list, u32 i);
extern void *POKE_TOOL_GetBoxParam(void *a);
extern u32 func_0201BA68(void *mon);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int func_0201BC3C(void);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern int POKE_TOOL_GetIconPalette(void *a0);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern const Rect sReportActorPositions[2];

void REPORT_InitActors(int *p)
{
    void *list;
    unsigned int n;
    unsigned int i;
    void *h;
    u32 t;
    void *e;
    Rect r;

    list = GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData((const struct Ctx *)p[0]));
    n = func_0201AA18(list);
    p[0x14] = (int)CLACT_CreateUnit(0x10, 0, ((struct Obj00166 *)p)->f12C);
    h = func_020490F4(7, ((struct Obj00166 *)p)->f12C);
    for (i = 0; i < n; i++)
        p[0x25 + i] = CLACT_RegisterCharacter(h, func_0201BA68(POKE_TOOL_GetBoxParam(func_0201AB28(list, i))), 0, 1,
                                    ((struct Obj00166 *)p)->f12C);
    p[0x34] = CLACT_RegisterPaletteCompressed(h, func_0201BC3C(), 1, 0, ((struct Obj00166 *)p)->f12C);
    t = func_0201BC40();
    p[0x41] = CLACT_RegisterCellAnim(h, t, func_0201BCB4(), ((struct Obj00166 *)p)->f12C);
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(0xC4, ((struct Obj00166 *)p)->f12C);
    p[0x2B] = CLACT_RegisterCharacter(h, 3, 1, 1, ((struct Obj00166 *)p)->f12C);
    p[0x35] = CLACT_RegisterPaletteEx(h, 4, 1, 0x60, 0, 1, ((struct Obj00166 *)p)->f12C);
    p[0x42] = CLACT_RegisterCellAnim(h, 5, 6, ((struct Obj00166 *)p)->f12C);
    ARC_TOOL_DeleteHandle(h);
    r = sReportActorPositions[0];
    for (i = 0; i < n; i++) {
        e = func_0201AB28(list, i);
        p[0x15 + i] = (int)CLACT_CreateActor((void *)p[0x14], p[0x25 + i], p[0x34], p[0x41], &r, 1,
                                    ((struct Obj00166 *)p)->f12C);
        func_0204B3DC((struct Obj *)p[0x15 + i], 0);
        r.x += 0x20;
        func_0204B6F4((struct Obj *)p[0x15 + i], POKE_TOOL_GetIconPalette(POKE_TOOL_GetBoxParam(e)), 1);
    }
    r = sReportActorPositions[1];
    for (i = 6; i <= 15; i++) {
        p[0x15 + i] = (int)CLACT_CreateActor((void *)p[0x14], p[0x2B], p[0x35], p[0x42], &r, 1,
                                    ((struct Obj00166 *)p)->f12C);
        func_0204B3DC((struct Obj *)p[0x15 + i], 0);
        r.x += 0xC;
    }
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
