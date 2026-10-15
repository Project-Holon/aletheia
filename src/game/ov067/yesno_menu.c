/*
 * file:     yesno_menu.c
 * unit:     yes
 * function: YESNO_MENU_Create, YESNO_MENU_Delete, YESNO_MENU_Start, YESNO_MENU_Close, YESNO_MENU_Update, YESNO_MENU_GetAnswer, YESNO_MENU_GetButtonPos, YESNO_MENU_CopyPalette
 * address:  0x021B6DC0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_020307B0 0x020307B0 arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   func_020355D8  0x020355D8  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   func_0201D304  0x0201D304  thumb
 *   d_021B9564     0x021B9564  data  a1
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02040588  0x02040588  arm
 *   func_02049B40  0x02049B40  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020355C4  0x020355C4  arm
 *   d_021B94C4     0x021B94C4  data  a1
 *   TOUCHPANEL_HitPoint  0x02035D40  arm
 *   d_021B94D0     0x021B94D0  data  a2
 *   d_021B94B8  0x021B94B8  data  a1
 *   d_021B94BC  0x021B94BC  data  a1
 *   func_02061CA4  0x02061CA4  arm
 *   UI_SCENE_LoadActorGfx  0x021B6208  thumb
 *   UI_SCENE_FreeActorGfx  0x021B6284  thumb
 *   UI_SCENE_CreateActor  0x021B629C  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;

#include "ui_scene_types.h"
#include "yesno_menu_types.h"

/* Size of YesNoMenu, allocated and cleared by YESNO_MENU_Create. */
#define YESNO_MENU_SIZE 0xcc

/* Number of button actors (two answers, each with a plain and a lit look). */
#define YESNO_MENU_BUTTON_COUNT 4

/* Number of steps in the flash table d_021B94D0. */
#define YESNO_MENU_FLASH_STEPS 10

/* Pad keys as KEY_GetTrg reports them. */
#define YESNO_MENU_KEY_A 0x1
#define YESNO_MENU_KEY_B 0x2
#define YESNO_MENU_KEY_UP 0x40
#define YESNO_MENU_KEY_DOWN 0x80

/* Input mode of func_020355C4 / func_020355D8. */
#define YESNO_MENU_INPUT_KEYS 0
#define YESNO_MENU_INPUT_TOUCH 1

/* Sound effect ids. */
#define YESNO_MENU_SE_CURSOR 0x548
#define YESNO_MENU_SE_DECIDE 0x54d
#define YESNO_MENU_SE_CANCEL 0x552

struct CharBuf;
struct StrBuf;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern u32 func_020307B0(void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern void func_02049B68(void *arc, u32 plttId, u32 target, u32 offset, u32 size, u32 heapId);
extern u32 func_02049740(void *arc, u32 charId, u32 layer, u32 offset, u32 size, u32 heapId);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void BG_SYS_FillTileMap(u8 layer, u8 x, u8 y, u8 width, u8 height, u8 plttSlot);
extern void BG_SYS_PushTile(u8 layer);
extern void CLACT_SetActorAutoAnim(struct Actor *actor, u32 value);
extern void CLACT_DeleteActor(struct Actor *actor);
extern u32 TOUCHPANEL_GetPointTrg(u32 *touchX, u32 *touchY);
extern void func_020355D8(u8 inputMode);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern struct CharBuf *BMP_WIN_GetBmp(struct TextWindow *window);
extern void PRINTSYS_PrintQueColor(struct PrintSys *printer, struct CharBuf *chars, s16 x, s16 y, struct StrBuf *text, u32 fontId, u16 color);
extern void CLACT_SetActorDrawEnable(struct Actor *actor, u32 value);
extern void CLACT_SetActorBgPriority(struct Actor *actor, unsigned int priority);
extern u32 func_0201D304(struct StrBuf *text, u32 fontId, u32 spacing);
extern void BG_SYS_FreeSlot(u32 layer);
extern u32 ARC_TOOL_GetHandleMemberSize(void *arc, u32 member);
extern void ARC_TOOL_ReadHandleMember(void *arc, u32 member, void *dest);
extern s32 NNS_G2dGetUnpackedPaletteData(void *file, void **out);
extern void func_020498F4(void *arc, u32 mapId, u32 layer, u32 tileOffset, u32 size, u32 blockOffset, u16 heapId);
extern void func_02040588(unsigned char layer, unsigned char enable);
extern void func_02049B40(u32 arcId, u32 plttId, u32 target, u32 offset, u32 size, u16 heapId);
extern struct TextWindow *BMP_WIN_Create(u32 layer, u32 x, u32 y, u32 tiles, u8 height, u8 plttSlot, u8 flags);
extern void BMP_Clear(struct CharBuf *chars, u8 fill);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 BMP_WIN_Delete(struct TextWindow *window);
extern void CLACT_AddActorSurfacePos(struct Actor *actor, YesNoPoint *pos, u16 screen);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *printer, struct CharBuf *chars);
extern void BMP_WIN_TransferChars(struct TextWindow *window);
extern void BMP_WIN_MakeScreen(struct TextWindow *window);
extern u8 BMP_WIN_GetBgLayer(struct TextWindow *window);
extern void func_02041B6C(u32 bit);
extern u8 func_020355C4(void);
extern int TOUCHPANEL_HitPoint(YesNoTouchTable *table, u32 x, u32 y);
extern s32 func_02061CA4(u32 region, u32 offset, const void *src, s32 size);
void UI_SCENE_LoadActorGfx(ActorGfxSet *out, ActorGfxDesc *desc, void *actorSys, u16 heapId);
void UI_SCENE_FreeActorGfx(ActorGfxSet *gfx);
struct Actor *UI_SCENE_CreateActor(ActorGfxSet *gfx, void *actorSys, u16 x, u16 y, u8 animIndex, u16 heapId);
YesNoMenu *YESNO_MENU_Create(u16 heapId, u32 textBgLayer, u32 actorPriority, u32 plttSlot, u8 actorPlttSlot, void *actorSys, u32 fontId, struct PrintSys *printer);
void YESNO_MENU_Delete(YesNoMenu *menu);
void YESNO_MENU_Start(YesNoMenu *menu, struct StrBuf *upperText, struct StrBuf *lowerText);
void YESNO_MENU_Close(YesNoMenu *menu);
void YESNO_MENU_Update(YesNoMenu *menu);
int YESNO_MENU_GetAnswer(YesNoMenu *menu);
u8 YESNO_MENU_GetButtonPos(u32 cursorIndex, u32 buttonIndex, u32 axis);
void YESNO_MENU_CopyPalette(int target, u8 slot, void *colors);
extern const char d_021B9564[];
extern const YesNoTouchTable d_021B94C4;
extern const YesNoFlashStep d_021B94D0[YESNO_MENU_FLASH_STEPS];
extern const YesNoCursorOrigin d_021B94B8;
extern const YesNoButtonOffsets d_021B94BC;


YesNoMenu *YESNO_MENU_Create(u16 heapId, u32 textBgLayer, u32 actorPriority, u32 plttSlot, u8 actorPlttSlot, void *actorSys, u32 fontId, struct PrintSys *printer)
{
    ActorGfxDesc desc;
    PlttFile *plttFile;
    u16 *colors;
    void *arc;
    void *file;
    u32 plttTarget;
    YesNoMenu *menu;
    u8 i;
    u8 j;
    u32 isSubScreen;

    menu = func_02030734(heapId, YESNO_MENU_SIZE, 0, d_021B9564, 0xd3);
    plttTarget = 0;
    MI_CpuFill8(menu, 0, YESNO_MENU_SIZE);
    menu->heapId = heapId;
    menu->actorSys = actorSys;
    menu->fontId = fontId;
    menu->printer = printer;
    if (textBgLayer > 3)
        plttTarget = 4;
    menu->plttTarget = plttTarget;
    menu->buttonBgLayer = textBgLayer + 1;
    menu->textBgLayer = textBgLayer;
    menu->buttonPriority = actorPriority + 1;
    menu->actorPriority = actorPriority;
    menu->yesPlttSlot = plttSlot;
    menu->noPlttSlot = plttSlot + 1;
    menu->textPlttSlot = plttSlot + 2;
    isSubScreen = 0;
    if (textBgLayer > 3)
        isSubScreen = 1;
    menu->isSubScreen = isSubScreen;
    menu->actorPlttSlot = actorPlttSlot;
    BG_SYS_FreeSlot(menu->buttonBgLayer);
    BG_SYS_FreeSlot(menu->textBgLayer);
    menu->state = YESNO_MENU_STATE_IDLE;
    menu->answer = YESNO_MENU_ANSWER_PENDING;
    menu->cursorIndex = 0;
    arc = func_020490F4(0x53, menu->heapId);
    file = func_02030734(menu->heapId, ARC_TOOL_GetHandleMemberSize(arc, 0xa3), 0, d_021B9564, 0x10d);
    ARC_TOOL_ReadHandleMember(arc, 0xa3, file);
    NNS_G2dGetUnpackedPaletteData(file, (void **)(&plttFile));
    colors = plttFile->colors[0];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 16; j++) {
            menu->palette[i][j] = colors[(i + 1) * 16 + j];
        }
    }
    func_020307B0(file);
    func_02049B68(arc, 0xa3, menu->plttTarget, menu->yesPlttSlot << 5, 0x40, menu->heapId);
    menu->buttonTileAlloc = func_02049740(arc, 0xa4, menu->buttonBgLayer, 0x1a0, 0, menu->heapId);
    func_020498F4(arc, 0xa5, menu->buttonBgLayer, (u16)menu->buttonTileAlloc, 0x600, 0, menu->heapId);
    BG_SYS_FillTileMap(menu->buttonBgLayer, 0, 0, 0x20, 0xb, menu->yesPlttSlot);
    BG_SYS_FillTileMap(menu->buttonBgLayer, 0, 0xb, 0x20, 0xd, menu->noPlttSlot);
    BG_SYS_PushTile(menu->buttonBgLayer);
    ARC_TOOL_DeleteHandle(arc);
    YESNO_MENU_CopyPalette(menu->plttTarget, menu->yesPlttSlot, menu->palette);
    YESNO_MENU_CopyPalette(menu->plttTarget, menu->noPlttSlot, menu->palette);
    func_02040588(menu->buttonBgLayer, 0);
    func_02049B40(0x17, 5, menu->plttTarget, menu->textPlttSlot << 5, 0x20, menu->heapId);
    menu->windowUpper = BMP_WIN_Create(menu->textBgLayer, 0, 5, 0x20, 6, menu->textPlttSlot, 1);
    BMP_Clear(BMP_WIN_GetBmp(menu->windowUpper), 0);
    menu->windowLower = BMP_WIN_Create(menu->textBgLayer, 0, 0xb, 0x20, 6, menu->textPlttSlot, 1);
    BMP_Clear(BMP_WIN_GetBmp(menu->windowLower), 0);
    func_02040588(menu->textBgLayer, 0);
    desc.screen = menu->isSubScreen;
    desc.flags = 0;
    desc.arcId = 0xb;
    desc.charId = 0x74;
    desc.plttId = 0x77;
    desc.cellId = 0x78;
    desc.animId = 0x79;
    desc.plttSlot = menu->actorPlttSlot;
    desc.charBase = 0;
    desc.charSize = 5;
    UI_SCENE_LoadActorGfx(&menu->gfx, &desc, menu->actorSys, menu->heapId);
    for (i = 0; i < YESNO_MENU_BUTTON_COUNT; i++) {
        menu->buttonActors[i] = UI_SCENE_CreateActor(&menu->gfx, menu->actorSys, YESNO_MENU_GetButtonPos(menu->cursorIndex, i, 0),
                                              YESNO_MENU_GetButtonPos(menu->cursorIndex, i, 1), i, menu->heapId);
        CLACT_SetActorBgPriority(menu->buttonActors[i], menu->actorPriority);
        CLACT_SetActorDrawEnable(menu->buttonActors[i], 0);
        CLACT_SetActorAutoAnim(menu->buttonActors[i], 0);
    }
    if (menu->isSubScreen == 0)
        BG_SYS_SetMainPlaneVisible(0x10, 1);
    else
        BG_SYS_SetSubPlaneVisible(0x10, 1);
    return menu;
}


void YESNO_MENU_Delete(YesNoMenu *menu)
{
    u8 i;
    u32 tileAlloc;

    for (i = 0; i < YESNO_MENU_BUTTON_COUNT; i++) {
        CLACT_DeleteActor(menu->buttonActors[i]);
    }
    UI_SCENE_FreeActorGfx(&menu->gfx);
    BMP_WIN_Delete(menu->windowUpper);
    BMP_WIN_Delete(menu->windowLower);
    tileAlloc = menu->buttonTileAlloc;
    BG_SYS_DeleteHalf(menu->buttonBgLayer, (u16)tileAlloc, (u16)(tileAlloc >> 16));
    func_020307B0(menu);
}


/* Shows the menu: places the buttons, prints the two texts centered in their windows and resets the answer. */
void YESNO_MENU_Start(YesNoMenu *menu, struct StrBuf *upperText, struct StrBuf *lowerText)
{
    YesNoPoint pos;
    u8 i;
    u32 textWidth;
    struct TextWindow *window;

    menu->state = YESNO_MENU_STATE_OPENING;
    menu->answer = YESNO_MENU_ANSWER_PENDING;
    menu->cursorIndex = 0;
    for (i = 0; i < YESNO_MENU_BUTTON_COUNT; i++) {
        pos.x = YESNO_MENU_GetButtonPos(menu->cursorIndex, i, 0);
        pos.y = YESNO_MENU_GetButtonPos(menu->cursorIndex, i, 1);
        CLACT_AddActorSurfacePos(menu->buttonActors[i], &pos, menu->isSubScreen);
    }
    YESNO_MENU_CopyPalette(menu->plttTarget, menu->yesPlttSlot, menu->palette);
    YESNO_MENU_CopyPalette(menu->plttTarget, menu->noPlttSlot, menu->palette);
    func_02040588(menu->buttonBgLayer, 1);
    BMP_Clear(BMP_WIN_GetBmp(menu->windowUpper), 0);
    BMP_Clear(BMP_WIN_GetBmp(menu->windowLower), 0);
    textWidth = func_0201D304(upperText, menu->fontId, 0);
    PRINTSYS_PrintQueColor(menu->printer, BMP_WIN_GetBmp(menu->windowUpper), (u16)((0x100 - textWidth) / 2), 0x10, upperText, menu->fontId, 0x3c40);
    textWidth = func_0201D304(lowerText, menu->fontId, 0);
    PRINTSYS_PrintQueColor(menu->printer, BMP_WIN_GetBmp(menu->windowLower), (u16)((0x100 - textWidth) / 2), 0x10, lowerText, menu->fontId, 0x3c40);
    menu->upperDone = 0;
    menu->lowerDone = 0;
    func_02040588(menu->textBgLayer, 1);
    if (menu->upperDone == 0 && PRINTSYS_QUE_IsExistTarget(menu->printer, BMP_WIN_GetBmp(menu->windowUpper)) == 0) {
        window = menu->windowUpper;
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        func_02041B6C(BMP_WIN_GetBgLayer(window));
        menu->upperDone = 1;
    }
    if (menu->lowerDone == 0 && PRINTSYS_QUE_IsExistTarget(menu->printer, BMP_WIN_GetBmp(menu->windowLower)) == 0) {
        window = menu->windowLower;
        BMP_WIN_TransferChars(window);
        BMP_WIN_MakeScreen(window);
        func_02041B6C(BMP_WIN_GetBgLayer(window));
        menu->lowerDone = 1;
    }
    if (func_020355C4() == YESNO_MENU_INPUT_KEYS) {
        for (i = 0; i < YESNO_MENU_BUTTON_COUNT; i++) {
            CLACT_SetActorDrawEnable(menu->buttonActors[i], 1);
            CLACT_SetActorAutoAnim(menu->buttonActors[i], 1);
        }
    }
}


/* Hides the menu again and clears the state. */
void YESNO_MENU_Close(YesNoMenu *menu)
{
    struct TextWindow *window;
    u8 i;

    func_02040588(menu->buttonBgLayer, 0);
    func_02040588(menu->textBgLayer, 0);
    BMP_Clear(BMP_WIN_GetBmp(menu->windowUpper), 0);
    BMP_Clear(BMP_WIN_GetBmp(menu->windowLower), 0);
    window = menu->windowUpper;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(BMP_WIN_GetBgLayer(window));
    window = menu->windowLower;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(BMP_WIN_GetBgLayer(window));
    for (i = 0; i < YESNO_MENU_BUTTON_COUNT; i++) {
        CLACT_SetActorDrawEnable(menu->buttonActors[i], 0);
        CLACT_SetActorAutoAnim(menu->buttonActors[i], 0);
    }
    menu->state = YESNO_MENU_STATE_IDLE;
}


/* Runs one frame: reads keys and touch, picks the answer and plays the flash of the pressed button. */
void YESNO_MENU_Update(YesNoMenu *menu)
{
    YesNoTouchTable hitTable;
    u32 touchX;
    u32 touchY;
    YesNoPoint pos;
    int redrawPalette;
    int touched;
    int handled;
    u32 keys;
    int cursorMoved;
    u8 i;
    struct TextWindow *window;

    redrawPalette = 0;
    keys = KEY_GetTrg();
    touched = TOUCHPANEL_GetPointTrg(&touchX, &touchY);
    switch (menu->state) {
    case YESNO_MENU_STATE_IDLE:
        break;
    case YESNO_MENU_STATE_OPENING:
        menu->state = YESNO_MENU_STATE_WAIT_INPUT;
        break;
    case YESNO_MENU_STATE_WAIT_INPUT:
        handled = 0;
        if (keys & YESNO_MENU_KEY_B) {
            GFL_USE_PlaySeDefaultVolume(YESNO_MENU_SE_CANCEL);
            menu->answer = YESNO_MENU_ANSWER_NO;
            handled = 1;
            func_020355D8(YESNO_MENU_INPUT_KEYS);
        }
        if (!handled && func_020355C4() == YESNO_MENU_INPUT_KEYS && keys != 0) {
            cursorMoved = 0;
            if (keys & YESNO_MENU_KEY_A) {
                if (menu->cursorIndex == 0) {
                    GFL_USE_PlaySeDefaultVolume(YESNO_MENU_SE_DECIDE);
                    menu->answer = YESNO_MENU_ANSWER_YES;
                } else {
                    GFL_USE_PlaySeDefaultVolume(YESNO_MENU_SE_CANCEL);
                    menu->answer = YESNO_MENU_ANSWER_NO;
                }
                handled = 1;
            } else if (keys & YESNO_MENU_KEY_UP) {
                if (menu->cursorIndex != 0) {
                    menu->cursorIndex = 0;
                    cursorMoved = 1;
                }
            } else if (keys & YESNO_MENU_KEY_DOWN) {
                if (menu->cursorIndex != 1) {
                    menu->cursorIndex = 1;
                    cursorMoved = 1;
                }
            }
            if (cursorMoved) {
                for (i = 0; i < YESNO_MENU_BUTTON_COUNT; i++) {
                    pos.x = YESNO_MENU_GetButtonPos(menu->cursorIndex, i, 0);
                    pos.y = YESNO_MENU_GetButtonPos(menu->cursorIndex, i, 1);
                    CLACT_AddActorSurfacePos(menu->buttonActors[i], &pos, menu->isSubScreen);
                }
                GFL_USE_PlaySeDefaultVolume(YESNO_MENU_SE_CURSOR);
            }
        }
        if (!handled && touched != 0) {
            int hit;
            hitTable = d_021B94C4;
            hit = TOUCHPANEL_HitPoint(&hitTable, touchX, touchY);
            if (hit != -1) {
                if (hit == 0) {
                    GFL_USE_PlaySeDefaultVolume(YESNO_MENU_SE_DECIDE);
                    menu->answer = YESNO_MENU_ANSWER_YES;
                } else if (hit == 1) {
                    GFL_USE_PlaySeDefaultVolume(YESNO_MENU_SE_CANCEL);
                    menu->answer = YESNO_MENU_ANSWER_NO;
                }
                handled = 1;
                func_020355D8(YESNO_MENU_INPUT_TOUCH);
            }
        }
        if (!handled && func_020355C4() == YESNO_MENU_INPUT_TOUCH && keys != 0) {
            for (i = 0; i < YESNO_MENU_BUTTON_COUNT; i++) {
                CLACT_SetActorDrawEnable(menu->buttonActors[i], 1);
                CLACT_SetActorAutoAnim(menu->buttonActors[i], 1);
            }
            GFL_USE_PlaySeDefaultVolume(YESNO_MENU_SE_CURSOR);
            func_020355D8(YESNO_MENU_INPUT_KEYS);
        }
        if (handled) {
            for (i = 0; i < YESNO_MENU_BUTTON_COUNT; i++) {
                CLACT_SetActorDrawEnable(menu->buttonActors[i], 0);
                CLACT_SetActorAutoAnim(menu->buttonActors[i], 0);
            }
            menu->state = YESNO_MENU_STATE_FLASH;
            menu->palAnimIndex = 0;
            menu->palAnimFrame = 1;
            menu->palAnimStep = 1;
        }
        break;
    case YESNO_MENU_STATE_FLASH:
        if (menu->palAnimStep < YESNO_MENU_FLASH_STEPS) {
            if (menu->palAnimFrame == d_021B94D0[menu->palAnimStep].frame) {
                menu->palAnimIndex = d_021B94D0[menu->palAnimStep].palIndex;
                redrawPalette = 1;
                menu->palAnimStep++;
            }
            menu->palAnimFrame++;
        } else {
            menu->state = YESNO_MENU_STATE_DONE;
        }
        break;
    case YESNO_MENU_STATE_DONE:
        break;
    }
    if (menu->state != YESNO_MENU_STATE_IDLE) {
        if (menu->upperDone == 0 && PRINTSYS_QUE_IsExistTarget(menu->printer, BMP_WIN_GetBmp(menu->windowUpper)) == 0) {
            window = menu->windowUpper;
            BMP_WIN_TransferChars(window);
            BMP_WIN_MakeScreen(window);
            func_02041B6C(BMP_WIN_GetBgLayer(window));
            menu->upperDone = 1;
        }
        if (menu->lowerDone == 0 && PRINTSYS_QUE_IsExistTarget(menu->printer, BMP_WIN_GetBmp(menu->windowLower)) == 0) {
            window = menu->windowLower;
            BMP_WIN_TransferChars(window);
            BMP_WIN_MakeScreen(window);
            func_02041B6C(BMP_WIN_GetBgLayer(window));
            menu->lowerDone = 1;
        }
    }
    if (redrawPalette) {
        YESNO_MENU_CopyPalette(menu->plttTarget, menu->answer == YESNO_MENU_ANSWER_YES ? menu->yesPlttSlot : menu->noPlttSlot, menu->palette[menu->palAnimIndex]);
    }
}


/* Returns the answer once the flash is over (or the menu is idle), else YESNO_MENU_ANSWER_PENDING. */
int YESNO_MENU_GetAnswer(YesNoMenu *menu)
{
    if (menu->state != YESNO_MENU_STATE_IDLE && menu->state != YESNO_MENU_STATE_DONE)
        return YESNO_MENU_ANSWER_PENDING;
    return menu->answer;
}


/* Button position on screen: origin of the cursor position plus the offset of the button. axis 0 is x, 1 is y. */
u8 YESNO_MENU_GetButtonPos(u32 cursorIndex, u32 buttonIndex, u32 axis)
{
    YesNoCursorOrigin origin = d_021B94B8;
    YesNoButtonOffsets offsets = d_021B94BC;
    return origin.v[cursorIndex][axis] + offsets.v[buttonIndex][axis];
}


/* Copies one 16-color row into the palette slot of the target (main/sub, background/actor). */
void YESNO_MENU_CopyPalette(int target, u8 slot, void *colors)
{
    int region;

    switch (target) {
    case 0:
        region = 0xf;
        break;
    case 1:
        region = 0xe;
        break;
    case 4:
        region = 0x1f;
        break;
    case 5:
        region = 0x1e;
        break;
    case 2:
    case 3:
        return;
    default:
        return;
    }
    func_02061CA4(region, slot << 5, colors, 0x20);
}
