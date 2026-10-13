/*
 * file:     touchbar.c
 * unit:     yes
 * function: func_021B62E0, func_021B639C, func_021B63D0, func_021B6448, func_021B6470, func_021B6498, func_021B64A8, func_021B64D0, func_021B64F8, func_021B6520, func_021B6548, func_021B6558, func_021B6568, func_021B6578, func_021B6588, func_021B6598, func_021B65A8, func_021B65B4, func_021B65C8, func_021B6600, func_021B6608, func_021B66FC, func_021B6730, func_021B6738, func_021B67F8, func_021B691C, func_021B6934, func_021B69A4, func_021B69B8, func_021B69BC, func_021B69C8, func_021B69D0, func_021B69D4, func_021B69D8, func_021B69F8, func_021B6A10, func_021B6A1C, func_021B6A28, func_021B6A44, func_021B6A68, func_021B6A98, func_021B6AE4, func_021B6B2C, func_021B6C4C
 * address:  0x021B62E0
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_020307B0 0x020307B0 arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B878  0x0204B878  arm
 *   d_021B954C     0x021B954C  data  a1
 *   func_020275E4  0x020275E4  thumb
 *   func_02027624  0x02027624  thumb
 *   func_02049B68  0x02049B68  arm
 *   func_02027628  0x02027628  thumb
 *   func_02049740  0x02049740  arm
 *   func_0202762C  0x0202762C  thumb
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_0203FB44 0x0203FB44 arm
 *   func_0204A380  0x0204A380  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0204169C  0x0204169C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_020410D0  0x020410D0  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   d_021B942C     0x021B942C  data  ov067  a4
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_02035D20  0x02035D20  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045C04  0x02045C04  arm
 */

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

#include "touchbar_types.h"

struct BmpData;
struct StrObj;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec;

/* Window the touch bar labels are printed into. */
typedef struct {
    struct BmpData *bitmap;
    u8 redraw;
} TouchBarWindow;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *dst, u32 value, u32 size);
extern u32 func_020307B0(void *ptr);
extern void *func_020490F4(u32 arcId, u32 heapId);
extern s32 func_0204AC18(void *arc, u32 fileId, u32 screen, u32 offset, u16 count, u16 mode, u32 heapId);
extern s32 func_0204A6C8(void *arc, u32 fileId, u32 flags, u32 screen, u32 heapId);
extern s32 func_0204AF28(void *arc, u32 cellFile, u32 animFile, u32 heapId);
extern void func_02049238(void *arc);
extern void func_0204ADA4(unsigned int plttHandle);
extern void func_0204A8D4(unsigned int charHandle);
extern void func_0204AFD8(unsigned int animHandle);
extern struct Actor *func_0204B294(struct Unit *unit, unsigned int charIdx, unsigned int plttIdx, unsigned int cellIdx, const TouchBarActorInit *init, u16 space, u16 heapId);
extern void func_0204B878(struct Actor *actor, u16 animSeq);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern void func_02049B68(void *arc, u32 fileId, u32 bgLayer, u32 offset, u32 size, u32 heapId);
extern u32 func_02027628(void);
extern u32 func_02049740(void *arc, u32 fileId, u32 bgLayer, u32 offset, u32 size, u32 heapId);
extern u32 func_0202762C(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32 iconSet);
extern u32 func_02027620(u32 iconSet);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void *func_0204A380(void *arc, u32 fileId, u32 loadMode, u32 heapFlags);
extern int func_02062B30(void *file, void **out);
extern u8 func_0204169C(int bgLayer);
extern u32 func_0204162C(int bgLayer);
extern void func_020410D0(u8 bgLayer, u32 dstX, u32 dstY, u32 dstWidth, u8 dstHeight, u32 src, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight);
extern void func_020413B0(u8 bgLayer, u8 x, u8 y, u8 width, u8 height, u8 plttSlot);
extern void func_020409B4(u8 bgLayer);
extern void func_0204B92C(struct Actor *actor, u32 enable);
extern void func_0204B3B4(struct Actor *actor);
extern u32 func_0204B3F4(struct Actor *actor);
extern u32 func_02035D20(u32 *outX, u32 *outY);
extern void func_020355D8(u8 usedTouch);
extern u32 func_020362DC(void);
extern u32 func_0204B98C(struct Actor *actor);
extern void func_020061E4(u32 soundId);
extern void *func_02045770(struct BmpData *bitmap);
extern void func_0201C724(void *textCtx, u32 bitmapBuffer, u32 x, u32 y, u32 str, u32 fontId, u16 color);
extern void func_0204B3DC(struct Actor *actor, u32 enable);
extern void CLACT_SetActorDrawPriority(struct Actor *actor, u32 priority);
extern void func_0204B84C(struct Actor *actor, unsigned int bgPriority);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201EC64(u16 heapId);
extern void *func_020457B0(u32 size, u16 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *str, u32 fontId, u32 spacing);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *wordSet, u32 slot, u32 value, u32 digits, u32 padMode, u32 flags);
extern void func_0201F250(struct WordSet *wordSet, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *wordSet);
extern u32 func_02045C04(struct Rec *msgBank);
TouchBar *func_021B62E0(TouchBarParams *params, u16 heapId);
void func_021B639C(TouchBar *bar);
void func_021B63D0(TouchBar *bar);
int func_021B6448(TouchBar *bar);
int func_021B6470(TouchBar *bar);
int func_021B6498(TouchBar *bar);
void func_021B64A8(TouchBar *bar, u32 enabled);
void func_021B64D0(TouchBar *bar, u32 visible);
void func_021B64F8(TouchBar *bar, u32 bgPriority);
void func_021B6520(TouchBar *bar, u32 priority);
void func_021B6548(TouchBar *bar, unsigned int buttonId, int enabled);
void func_021B6558(TouchBar *bar, unsigned int buttonId, unsigned int visible);
void func_021B6568(TouchBar *bar, unsigned int buttonId, int soundId);
void func_021B6578(TouchBar *bar, unsigned int buttonId, int keyMask);
void func_021B6588(TouchBar *bar, unsigned int buttonId, unsigned int bgPriority);
void func_021B6598(TouchBar *bar, unsigned int buttonId, unsigned int toggled);
int func_021B65A8(TouchBar *bar, int buttonId);
void func_021B65B4(TouchBar *bar, unsigned int buttonId);
TouchBarButton *func_021B65C8(TouchBar *bar, u32 buttonId);
TouchBarButton *func_021B6600(TouchBar *bar, unsigned int buttonId);
void func_021B6608(TouchBarGfx *gfx, u8 bgLayer, u32 screen, u32 bgPlttTarget, u32 iconSet, u8 bgPlttSlot, u8 actorPlttSlot, u32 skipBgGfx, u32 heapId);
void func_021B66FC(TouchBarGfx *gfx);
int func_021B6730(const TouchBarGfx *gfx, int index);
void func_021B6738(void *arc, u32 fileId, u32 bgLayer, u32 tileOffset, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight, u8 dstX, u8 dstY, u8 dstWidth, u8 dstHeight, u8 plttSlot, u32 loadMode, u32 heapId);
void func_021B67F8(TouchBarButton *button, struct Unit *actorSys, const TouchBarGfx *gfx, const TouchBarButtonDef *def, u32 screen, u16 heapId);
void func_021B691C(TouchBarButton *button);
int func_021B6934(TouchBarButton *button);
int func_021B69A4(TouchBarButton *button);
int func_021B69B8(TouchBarButton *button);
void func_021B69BC(TouchBarButton *button, unsigned int visible);
void func_021B69C8(TouchBarButton *button, int enabled);
void func_021B69D0(TouchBarButton *button, int soundId);
void func_021B69D4(TouchBarButton *button, int keyMask);
void func_021B69D8(TouchBarButton *button, u32 down);
u32 func_021B69F8(TouchBarButton *button);
void func_021B6A10(TouchBarButton *button, unsigned int priority);
void func_021B6A1C(TouchBarButton *button, unsigned int bgPriority);
void func_021B6A28(TouchBarButton *button);
void func_021B6A44(TouchBarButton *button);
void func_021B6A68(TouchBarButton *button, u32 enabled);
void func_021B6A98(TouchBarButton *button, u32 enabled);
void func_021B6AE4(TouchBarWindow *window, void *textCtx, u16 x, u16 y, u32 str, u32 fontId, u16 color, u32 alignMode);
void func_021B6B2C(TouchBarWindow *window, void *textCtx, u32 fontId, u16 x, u16 y, u16 color, u32 firstNumber, u32 secondNumber, u16 heapId);
u16 func_021B6C4C(struct StrObj *str, u32 fontId, u32 alignMode);
extern const char d_021B954C[];
extern TouchBarButtonLook d_021B942C[];


TouchBar *func_021B62E0(TouchBarParams *params, u16 heapId)
{
    int screen;
    TouchBar *bar;
    int bgPlttTarget;
    u32 size;
    u32 i;

    size = params->count * sizeof(TouchBarButton) + 0x20;
    bar = func_02030734(heapId, size, 0, d_021B954C, 0x123);
    screen = 0;
    func_02082BCC(bar, 0, size);
    bar->buttonCount = params->count;
    bar->state = screen;
    if (params->bgLayer >= 4) {
        screen = 1;
        bgPlttTarget = 4;
    } else {
        bgPlttTarget = screen;
    }
    func_021B6608(&bar->gfx, params->bgLayer, screen, bgPlttTarget, params->iconSet, params->bgPlttSlot, params->actorPlttSlot, params->skipBgGfx, heapId);
    for (i = 0; i < bar->buttonCount; i++) {
        func_021B67F8(&bar->buttons[i], params->actorSys, &bar->gfx, &params->defs[i], screen, heapId);
    }
    return bar;
}


void func_021B639C(TouchBar *bar)
{
    u32 i;
    for (i = 0; i < bar->buttonCount; i++)
        func_021B691C(&bar->buttons[i]);
    func_021B66FC(&bar->gfx);
    func_020307B0(bar);
}


void func_021B63D0(TouchBar *bar)
{
    u32 i;

    switch (bar->state) {
    case TOUCHBAR_STATE_IDLE:
        bar->pressedIndex = -1;
        for (i = 0; i < bar->buttonCount; i++) {
            if (func_021B6934(&bar->buttons[i])) {
                bar->pressedIndex = i;
                bar->state = TOUCHBAR_STATE_PRESSED;
                return;
            }
        }
        break;
    case TOUCHBAR_STATE_PRESSED:
        bar->state = TOUCHBAR_STATE_ANIMATING;
    case TOUCHBAR_STATE_ANIMATING:
        if (func_021B69A4(&bar->buttons[bar->pressedIndex])) {
            bar->state = TOUCHBAR_STATE_DONE;
        }
        break;
    case TOUCHBAR_STATE_DONE:
        bar->state = TOUCHBAR_STATE_IDLE;
        break;
    }
}


int func_021B6448(TouchBar *bar)
{
    if (bar->state == TOUCHBAR_STATE_DONE && bar->pressedIndex != TOUCHBAR_NO_BUTTON) {
        return func_021B69B8(&bar->buttons[bar->pressedIndex]);
    }
    return -1;
}


int func_021B6470(TouchBar *bar)
{
    if (bar->state == TOUCHBAR_STATE_PRESSED && bar->pressedIndex != TOUCHBAR_NO_BUTTON) {
        return func_021B69B8(&bar->buttons[bar->pressedIndex]);
    }
    return -1;
}


int func_021B6498(TouchBar *bar)
{
    if (bar->state)
        return 1;
    return 0;
}


void func_021B64A8(TouchBar *bar, u32 enabled)
{
    u32 i;

    for (i = 0; i < bar->buttonCount; i++) {
        func_021B69C8(&bar->buttons[i], enabled);
    }
}


void func_021B64D0(TouchBar *bar, u32 visible)
{
    u32 i;

    for (i = 0; i < bar->buttonCount; i++) {
        func_021B69BC(&bar->buttons[i], visible);
    }
}


void func_021B64F8(TouchBar *bar, u32 bgPriority)
{
    u32 i;

    for (i = 0; i < bar->buttonCount; i++) {
        func_021B6A1C(&bar->buttons[i], bgPriority);
    }
}


void func_021B6520(TouchBar *bar, u32 priority)
{
    u32 i;

    for (i = 0; i < bar->buttonCount; i++) {
        func_021B6A10(&bar->buttons[i], priority);
    }
}


void func_021B6548(TouchBar *bar, unsigned int buttonId, int enabled)
{
    func_021B69C8(func_021B65C8(bar, buttonId), enabled);
}


void func_021B6558(TouchBar *bar, unsigned int buttonId, unsigned int visible)
{
    func_021B69BC(func_021B65C8(bar, buttonId), visible);
}


void func_021B6568(TouchBar *bar, unsigned int buttonId, int soundId)
{
    func_021B69D0(func_021B65C8(bar, buttonId), soundId);
}


void func_021B6578(TouchBar *bar, unsigned int buttonId, int keyMask)
{
    func_021B69D4(func_021B65C8(bar, buttonId), keyMask);
}


void func_021B6588(TouchBar *bar, unsigned int buttonId, unsigned int bgPriority)
{
    func_021B6A1C(func_021B65C8(bar, buttonId), bgPriority);
}


void func_021B6598(TouchBar *bar, unsigned int buttonId, unsigned int toggled)
{
    func_021B69D8(func_021B65C8(bar, buttonId), toggled);
}


/*
 * Extent includes the unlabelled tail-call follower at 0x021B65B4.
 */
int func_021B65A8(TouchBar *bar, int buttonId)
{
    return func_021B69F8(func_021B6600(bar, buttonId));
}


void func_021B65B4(TouchBar *bar, unsigned int buttonId)
{
    bar->state = TOUCHBAR_STATE_IDLE;
    bar->pressedIndex = TOUCHBAR_NO_BUTTON;
    func_021B6548(bar, buttonId, 1);
}


TouchBarButton *func_021B65C8(TouchBar *bar, u32 buttonId)
{
    u32 i;

    for (i = 0; i < bar->buttonCount; i++) {
        if (func_021B69B8(&bar->buttons[i]) == buttonId) {
            return (TouchBarButton *)((u8 *)bar->buttons + i * sizeof(TouchBarButton));  /* stand-in: &bar->buttons[i] CSEs with the call argument and is 2 bytes short */
        }
    }
    return 0;
}


/*
 * Tail call to func_021B65C8.
 */
TouchBarButton *func_021B6600(TouchBar *bar, unsigned int buttonId)
{
    return func_021B65C8(bar, buttonId);
}


void func_021B6608(TouchBarGfx *gfx, u8 bgLayer, u32 screen, u32 bgPlttTarget, u32 iconSet, u8 bgPlttSlot, u8 actorPlttSlot, u32 skipBgGfx, u32 heapId)
{
    void *arc;
    u32 cellFile;

    func_02082BCC(gfx, 0, sizeof(TouchBarGfx));
    gfx->bgLayer = bgLayer;
    arc = func_020490F4(func_020275E4(), heapId);
    if (skipBgGfx == 0) {
        func_02049B68(arc, func_02027624(), bgPlttTarget, bgPlttSlot << 5, 0x20, heapId);
        gfx->tileAlloc = func_02049740(arc, func_02027628(), gfx->bgLayer, 0x800, 0, heapId);
        func_021B6738(arc, func_0202762C(), gfx->bgLayer, (u16)gfx->tileAlloc,
                      0, 0x15, 0x20, 0x18, 0, 0x15, 0x20, 3, bgPlttSlot, 0, heapId);
    }
    gfx->plttHandle = func_0204AC18(arc, func_02027614(), screen, (u16)(actorPlttSlot << 5), 0, 3, heapId);
    gfx->charHandle = func_0204A6C8(arc, func_02027618(), 0, screen, heapId);
    cellFile = func_0202761C(iconSet);
    gfx->animHandle = func_0204AF28(arc, cellFile, func_02027620(iconSet), heapId);
    func_02049238(arc);
}


void func_021B66FC(TouchBarGfx *gfx)
{
    func_0204AFD8(gfx->animHandle);
    func_0204A8D4(gfx->charHandle);
    func_0204ADA4(gfx->plttHandle);
    func_0203FB44(gfx->bgLayer, (u16)gfx->tileAlloc, (u16)(gfx->tileAlloc >> 16));
    func_02082BCC(gfx, 0, sizeof(TouchBarGfx));
}


/*
 * Reads word `index` of the resource handle block (0 palette, 1 character,
 * 2 cell animation); the struct is indexed as a word array.
 */
int func_021B6730(const TouchBarGfx *gfx, int index)
{
    return ((int *)gfx)[index];
}


/*
 * Loads a character-data resource, optionally adds tileOffset to each of its
 * srcWidth * srcHeight u16 cells, then (when func_0204162C(bgLayer) allows)
 * copies it into background bgLayer and loads its palette, and frees the
 * resource.
 * The u8 stack arguments are re-read with ldrb before each call because the
 * callees take them as u8 (widths from func_020410D0.c and
 * func_020413B0.c); with u32 callee parameters dstX..dstWidth stayed in
 * registers and the frame grew (200 bytes against 192). The loop bound is the
 * expression srcWidth * srcHeight and the add is `+=` with the uncast
 * tileOffset: a total local, srcHeight * srcWidth and `cells[i] + (u16)tileOffset`
 * each cost a copy or swapped the loads.
 * The caller passes tileOffset narrowed (cast at the call) and the last
 * argument as a full word, so both are u32 in the prototype; the body reads
 * the low half of the last stack word with ldrh (`*(u16 *)&heapId`).
 */
void func_021B6738(void *arc, u32 fileId, u32 bgLayer, u32 tileOffset,
                   u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight,
                   u8 dstX, u8 dstY, u8 dstWidth, u8 dstHeight,
                   u8 plttSlot, u32 loadMode, u32 heapId)
{
    void *file;
    u8 *data;
    int i;
    u16 *cells;

    file = func_0204A380(arc, fileId, loadMode, (u16)((*(u16 *)&heapId & 0x7fff) | 0x8000));
    func_02062B30(file, (void **)(&data));
    if (tileOffset != 0) {
        if (func_0204169C((u8)bgLayer) == 0) {
            cells = (u16 *)(data + 0xc);
            for (i = 0; i < srcWidth * srcHeight; i++) {
                cells[i] += tileOffset;
            }
        }
    }
    if ((int)func_0204162C((u8)bgLayer)) {
        func_020410D0(bgLayer, dstX, dstY, dstWidth, dstHeight, (u32)(data + 0xc), srcX, srcY, srcWidth, srcHeight);
        func_020413B0(bgLayer, dstX, dstY, dstWidth, dstHeight, plttSlot);
        func_020409B4(bgLayer);
    }
    func_020307B0(file);
}


void func_021B67F8(TouchBarButton *button, struct Unit *actorSys, const TouchBarGfx *gfx, const TouchBarButtonDef *def, u32 screen, u16 heapId)
{
    TouchBarActorInit init;
    u32 charRes;
    u32 plttRes;
    u32 animRes;
    int i;

    func_02082BCC(button, 0, sizeof(TouchBarButton));
    button->def = *def;
    button->enabled = 1;
    func_02082BCC(&init, 0, sizeof(TouchBarActorInit));
    init.x = def->x;
    init.y = def->y;
    if (def->kind >= TOUCHBAR_KIND_CUSTOM) {
        charRes = def->charRes;
        plttRes = def->plttRes;
        animRes = def->animRes;
        button->style = 0;
    } else {
        charRes = func_021B6730(gfx, 1);
        plttRes = func_021B6730(gfx, 0);
        animRes = func_021B6730(gfx, 2);
        i = def->kind;
        button->def.animIdle = d_021B942C[i].animIdle;
        button->def.animDisabled = d_021B942C[i].animDisabled;
        button->def.animDown = d_021B942C[i].animDown;
        button->def.animDownAlt = d_021B942C[i].animDownAlt;
        button->def.keyMask = d_021B942C[i].keyMask;
        button->def.soundId = d_021B942C[i].soundId;
        button->style = d_021B942C[i].style;
    }
    button->anim = button->def.animIdle;
    init.animSeq = button->anim;
    button->actor = func_0204B294(actorSys, charRes, plttRes, animRes, &init, screen, heapId);
    func_0204B92C(button->actor, 1);
    switch (button->style) {
    case 0:
        button->onPress = func_021B6A28;
        button->setEnabled = func_021B6A68;
        break;
    case 1:
        button->onPress = func_021B6A44;
        button->setEnabled = func_021B6A98;
        break;
    }
}


/*
 * extent: trailing two-byte alignment padding at 0x021B6932.
 */
void func_021B691C(TouchBarButton *button)
{
    func_0204B3B4(button->actor);
    func_02082BCC(button, 0, sizeof(TouchBarButton));
}


int func_021B6934(TouchBarButton *button)
{
    u32 touchX;
    u32 touchY;
    int hit = 0;

    if (func_0204B3F4(button->actor) & button->enabled) {
        if (func_02035D20(&touchX, &touchY)) {
            if (touchX - button->def.x <= 0x18 && touchY - button->def.y <= 0x18) {
                hit = 1;
                func_020355D8(1);
            }
        }
        if (button->def.keyMask != 0 && (func_020362DC() & button->def.keyMask)) {
            func_020355D8(0);
            hit = 1;
        }
        if (hit) {
            button->onPress(button);
            return 1;
        }
    }
    return 0;
}


int func_021B69A4(TouchBarButton *button)
{
    if (func_0204B98C(button->actor) == 0) return 1;
    return 0;
}


/*
 * Getter, ARM9 tail call, indirect call, and two setters.  0x021B69BC is also
 * resident in ov172, so the packet id is region-qualified.
 */
int func_021B69B8(TouchBarButton *button)
{
    return button->def.kind;
}


void func_021B69BC(TouchBarButton *button, unsigned int visible)
{
    func_0204B3DC(button->actor, visible);
}


void func_021B69C8(TouchBarButton *button, int enabled)
{
    button->setEnabled(button, enabled);
}


void func_021B69D0(TouchBarButton *button, int soundId)
{
    button->def.soundId = soundId;
}


void func_021B69D4(TouchBarButton *button, int keyMask)
{
    button->def.keyMask = keyMask;
}


void func_021B69D8(TouchBarButton *button, u32 down)
{
    if (down != 0)
        button->anim = button->def.animDown;
    else
        button->anim = button->def.animIdle;
    func_0204B878(button->actor, (u16)button->anim);
}


u32 func_021B69F8(TouchBarButton *button)
{
    int result = 1;
    if (button->anim != button->def.animDown && button->anim != button->def.animDownAlt) result = 0;
    return result;
}


void func_021B6A10(TouchBarButton *button, unsigned int priority)
{
    CLACT_SetActorDrawPriority(button->actor, priority);
}


/*
 * Tail call on the actor pointer loaded from offset 0.
 */
void func_021B6A1C(TouchBarButton *button, unsigned int bgPriority)
{
    func_0204B84C(button->actor, bgPriority);
}


/*
 * extent: trailing two-byte alignment padding at 0x021B6A42.
 */
void func_021B6A28(TouchBarButton *button)
{
    button->anim = button->def.animDown;
    func_0204B878(button->actor, button->anim);
    if (button->def.soundId) func_020061E4(button->def.soundId);
}


void func_021B6A44(TouchBarButton *button)
{
    u32 isDown = func_021B69F8(button);
    int down = 1;

    if (isDown != 0) {
        down = 0;
    }
    func_021B69D8(button, down);
    if (button->def.soundId != 0) {
        func_020061E4(button->def.soundId);
    }
}


/*
 * extent: trailing two-byte alignment padding at 0x021B6A96.
 */
void func_021B6A68(TouchBarButton *button, u32 enabled)
{
    button->enabled = enabled;
    if (enabled) {
        if (button->anim == button->def.animDown) button->anim = button->def.animIdle;
        func_0204B878(button->actor, button->anim);
    } else {
        func_0204B878(button->actor, button->def.animDisabled);
    }
}


void func_021B6A98(TouchBarButton *button, u32 enabled)
{
    button->enabled = enabled;
    if (enabled) {
        if (button->anim == button->def.animDown) {
            button->anim = button->def.animDownAlt;
        } else if (button->anim == button->def.animDisabled) {
            button->anim = button->def.animIdle;
        }
        func_0204B878(button->actor, button->anim);
    } else {
        if (button->anim == button->def.animDownAlt) {
            button->anim = button->def.animDown;
        } else if (button->anim == button->def.animIdle) {
            button->anim = button->def.animDisabled;
        }
        func_0204B878(button->actor, button->def.animDisabled);
    }
}


/*
 * note:     y and x are u16 as the matched caller ov067_func_021B6B2C passes
 *           them; the difference is written back into the parameter
 *           (`x = x - f()`): a separate u16 local swapped window and x
 *           between r4/r5, and `x -= f()` truncates the call result first
 *           (worse).
 */
void func_021B6AE4(TouchBarWindow *window, void *textCtx, u16 x, u16 y, u32 str, u32 fontId, u16 color, u32 alignMode)
{
    x = x - func_021B6C4C((struct StrObj *)str, fontId, alignMode);
    func_0201C724(textCtx, (u32)func_02045770(window->bitmap), (short)x, (short)y, str, fontId, color);
    window->redraw = 1;
}


/*
 * note:     the heap id, y and color are reloaded from their stack slots
 *           before every call because the callees take them as u16 (with
 *           u32 callee parameters they stay in registers: 300 bytes);
 *           `x = x - f()` (`-=` truncates the call result first).
 */
void func_021B6B2C(TouchBarWindow *window, void *textCtx, u32 fontId, u16 x, u16 y, u16 color, u32 firstNumber, u32 secondNumber, u16 heapId)
{
    void *msgBank;
    void *wordSet;
    void *buf;
    void *str;
    u16 strWidth;

    msgBank = func_02045B38(0, 2, 0xa3, heapId);
    wordSet = func_0201EC64(heapId);
    buf = func_020457B0(0xa, heapId);
    str = func_02045EC0(msgBank, 0);
    strWidth = func_0201D304(str, fontId, 0);
    func_021B6AE4(window, textCtx, x, y, (u32)str, fontId, color, 2);
    x = x - func_021B6C4C(str, fontId, 2);
    func_02045808(str);
    str = func_02045EC0(msgBank, 1);
    func_0201EFA4(wordSet, 0, firstNumber, 8, 0, 1);
    func_0201F250(wordSet, buf, str);
    func_021B6AE4(window, textCtx, x, y, (u32)buf, fontId, color, 1);
    func_02045808(str);
    str = func_02045EC0(msgBank, 2);
    func_0201EFA4(wordSet, 0, secondNumber, 8, 0, 1);
    func_0201F250(wordSet, buf, str);
    func_021B6AE4(window, textCtx, x + strWidth, y, (u32)buf, fontId, color, 0);
    func_02045808(str);
    func_02045808(buf);
    func_0201ED04(wordSet);
    func_02045C04(msgBank);
}


u16 func_021B6C4C(struct StrObj *str, u32 fontId, u32 alignMode)
{
    if (alignMode == 1) return func_0201D304(str, fontId, 0);
    if (alignMode == 2) return func_0201D304(str, fontId, 0) >> 1;
    return 0;
}
