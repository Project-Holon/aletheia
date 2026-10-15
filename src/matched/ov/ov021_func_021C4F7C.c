/*
 * function: SHORTCUT_MENU_Create
 * address:  0x021C4F7C
 * packet:   pkt_ov021_021C4F7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The heap id is a u16 stack parameter, and the callees it feeds take a u16
 * heap too (docs/idioms/narrow-stack-parameters-and-callee-prototype-free-
 * the-narrow-home-store.md): only then does the u16 a3's home store
 * `str r3, [sp, #0x18]` lead the prologue. With u32 heap it sank below
 * `ldr r7, [sp, #0x40]; str r0, [sp, #0x10]` (6 bytes). pos.y = 0x60 is
 * written once before the loop, and the element address is spelled
 * p + i * 4 + 0x58 (r6 = p + i*4 shared with the table index).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   func_02045B38  0x02045B38  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   RECENT_ID_LIST_SAVEDATA_GetBlock  0x0200C40C  thumb
 *   SHORTCUT_MENU_InitList  0x021C53A0  thumb  ov021
 *   func_02041B6C  0x02041B6C  arm
 *   func_0207D63C  0x0207D63C  arm
 *   BG_SYS_FillScrollArea  0x02040618  arm
 *   func_02040588  0x02040588  arm
 *   gShortcutMenuFileName     0x021DE498  data  ov021  a1
 *   gShortcutMenuBgTemplate     0x021DAA60  data  a4
 *   gShortcutMenuActorX     0x021DAA54  data  a4
 */
#include "../include/Obj00960.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 x; u16 y; u16 z; u8 a; u8 b; } Pos;

extern char gShortcutMenuFileName[];
extern const u32 gShortcutMenuBgTemplate[];
extern const u32 gShortcutMenuActorX[];

typedef signed int     s32;
struct Big;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *p, int v, int n);
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(int);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
struct Bank;
struct GfFont;
struct MsgBank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void ARC_TOOL_DeleteHandle(void *);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *obj, unsigned int v);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void *PRINTSYS_QUE_CreateEx(u16 n, u32 heap);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *RECENT_ID_LIST_SAVEDATA_GetBlock(void *sys);
extern void SHORTCUT_MENU_InitList(int *a, const u16 *b, u32 c, u32 d, u32 e, u32 f, int *g, u16 h);
extern void func_02041B6C(u32 bit);
extern void func_0207D63C(int, int, int, int, int);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void func_02040588(unsigned char which, unsigned char enable);

char *SHORTCUT_MENU_Create(void *a0, int mode, const u16 *a2, u16 a3, u16 heap)
{
    Pos pos;
    int x;
    char *p;
    void *arc;
    int i;

    i = 0;
    p = func_02030734(heap, 0x88, 0, gShortcutMenuFileName, 0xFC);
    MI_CpuFill8(p, 0, 0x88);
    ((struct Obj00960 *)p)->f74 = 0;
    ((struct Obj00960 *)p)->f78 = 25;
    *(const u16 * *)&((struct Obj00960 *)p)->f7C = a2;
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)gShortcutMenuBgTemplate, 0);
    BG_SYS_FreeSlot(1);
    BG_SYS_Init(1, 0, 1, 0);
    ((struct Obj00960 *)p)->f4C = (u32)CLACT_CreateUnit(8, 0, heap);
    x = 0x80;
    arc = func_020490F4(0x80, heap);
    func_02049B68(arc, 0, 0, x + 0xE0, 0x40, heap);
    ((struct Obj00960 *)p)->f50 = CLACT_RegisterPalette(arc, 4, 0, 0x40, heap);
    ((struct Obj00960 *)p)->f52 = CLACT_RegisterCharacter(arc, 3, 0, 0, heap);
    ((struct Obj00960 *)p)->f54 = CLACT_RegisterCellAnim(arc, 2, 1, heap);
    x += 0xC0;
    func_02049B68(arc, 6, 0, x, 0x20, heap);
    func_02049658(arc, 5, 1, 0, 0, 0, heap);
    func_020498F4(arc, 7, 1, 0, 0, 0, heap);
    BG_SYS_FillTileMap(1, 0, 11, 32, 1, 10);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(&pos, 0, 8);
    pos.y = 0x60;
    for (i = 0; i < 3; i++) {
        pos.z = i;
        pos.x = gShortcutMenuActorX[i];
        *(u32 *)(p + i * 4 + 0x58) = (u32)CLACT_CreateActor((void *)((struct Obj00960 *)p)->f4C, ((struct Obj00960 *)p)->f52,
            ((struct Obj00960 *)p)->f50, ((struct Obj00960 *)p)->f54, &pos, 0, heap);
        CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p + i * 4 + 0x58), 0);
        CLACT_SetActorAutoAnim((struct Obj *)*(u32 *)(p + i * 4 + 0x58), 1);
    }
    ((struct Obj00960 *)p)->f64 = (u32)func_02045B38(0, 2, 0xAD, heap);
    ((struct Obj00960 *)p)->f68 = (u32)GF_FONT_Create(0x17, 0, 0, 0, a3);
    ((struct Obj00960 *)p)->f6C = (u32)PRINTSYS_QUE_CreateEx(0x1000, heap);
    SHORTCUT_MENU_InitList((int *)p, *(const u16 * *)&((struct Obj00960 *)p)->f7C, ((struct Obj00960 *)p)->f64, ((struct Obj00960 *)p)->f68,
        ((struct Obj00960 *)p)->f6C, (u32)RECENT_ID_LIST_SAVEDATA_GetBlock(GAME_DATA_GetSaveControl(a0)), (int *)(p + 0x58), a3);
    func_02041B6C(1);
    func_0207D63C(0x04000050, 2, 1, 12, 4);
    switch (mode) {
    case 0:
        BG_SYS_FillScrollArea(1, 3, -0xC0);
        func_02040588(1, 0);
        ((struct Obj00960 *)p)->f70 = 0;
        break;
    case 1:
        BG_SYS_FillScrollArea(1, 3, 0);
        func_02040588(1, 1);
        ((struct Obj00960 *)p)->f70 = 3;
        break;
    }
    return p;
}
