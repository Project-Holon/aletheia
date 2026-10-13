/*
 * file:     townmap_grh.c
 * unit:     yes
 * function: func_021BB3E8, func_021BB42C, func_021BB448, func_021BB49C, func_021BB4B4, func_021BB534, func_021BB548, func_021BB5AC, func_021BB5B4, func_021BB5D4, func_021BB5E0, func_021BB5EC, func_021BB6AC, func_021BB6DC, func_021BB6E4, func_021BB6E8, func_021BB738, func_021BB758, func_021BB764, func_021BB778, func_021BB784, func_021BB790, func_021BB7BC, func_021BB80C, func_021BB820, func_021BB968, func_021BB9B0, func_021BB9B8, func_021BBAB4, func_021BBAFC, func_021BBB04, func_021BBB0C, func_021BBB14, func_021BBB1C, func_021BBB24, func_021BBB34, func_021BBB3C, func_021BBB48
 * address:  0x021BB3E8
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   CLACT_StopActorAnim  0x0204B974  arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02035D20  0x02035D20  arm
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B878  0x0204B878  arm
 *   CLACT_StartActorAnim  0x0204B95C  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B84C  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0 0x020307B0 arm
 *   func_020450F0  0x020450F0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020456F8 0x020456F8 arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   d_021BBD6C     0x021BBD6C  data  ov072  a1
 *   d_021BBBDC     0x021BBBDC  data  ov072
 *   d_021BBC28 0x021BBC28 data a4
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02040C14  0x02040C14  arm
 *   d_021BBBCC     0x021BBBCC  data  a4
 *   func_02040DA8  0x02040DA8  arm
 *   func_020414AC  0x020414AC  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020419E4  0x020419E4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   d_021BBC0C     0x021BBC0C  data  a4
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0204A600  0x0204A600  arm
 *   func_0204A648 0x0204A648 arm
 *   func_0204A1BC 0x0204A1BC arm
 *   func_021BA774  0x021BA774  thumb
 */
#include "townmap_grh_types.h"

#define REG_BLDCNT      (*(volatile u16 *)0x04000050)
#define REG_DB_BLDCNT   (*(volatile u16 *)0x04001050)
#define REG_DISPCNT     (*(volatile u32 *)0x04000000)
#define REG_DB_DISPCNT  (*(volatile u32 *)0x04001000)
#define DISPCNT_WINDOW_BITS 0xE000

#define TOWNMAP_GRH_BG_COUNT 7

extern void func_02082BCC(void *dst, int value, int size);
extern u32 func_020056A0(void (*task)(void *, void *), void *arg, int priority);
extern void func_02030EAC(u32 task);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_0204A6C8(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern u32 func_0204AF28(void *arc, u32 first, u32 second, u32 mode);
extern void func_02049238(void *arc);
extern struct ClactActor *func_0204B294(struct ClactUnit *unit, u32 chr, u32 pal, u32 cell, const SpriteInit *init, u16 drawArea, u16 heap);
extern void func_0204B92C(struct ClactActor *actor, u32 value);
extern void CLACT_StopActorAnim(struct ClactActor *actor);
extern void func_0204B3B4(struct ClactActor *actor);
extern void func_0204AFD8(u32 cellId);
extern void func_0204A8D4(u32 charId);
extern void func_0204ADA4(u32 palId);
extern u32 func_02035D20(u32 *outX, u32 *outY);
extern u32 func_0204B98C(struct ClactActor *actor);
extern void func_0204B878(struct ClactActor *actor, u16 animSeq);
extern void CLACT_StartActorAnim(struct ClactActor *actor);
extern void func_0204B404(struct ClactActor *actor, const ScreenPos *pos, u32 which);
extern void func_0204B3DC(struct ClactActor *actor, u32 enable);
extern void func_0204B84C(struct ClactActor *actor, int value);
extern void CLACT_SetActorDrawPriority(struct ClactActor *actor, u32 priority);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 func_020307B0(void *p);
extern struct BmpWin *func_020450F0(u32 bgId, u32 x, u32 y, u32 width, u8 height, u8 palette, u8 baseTile);
extern struct StrBuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct StrBuf *text);
extern u32 func_020452E8(struct BmpWin *win);
extern struct Bitmap *func_02045770(struct BmpWin *win);
extern void func_02043B5C(struct Bitmap *bitmap, u8 value);
extern u32 func_02013E4C(u32 townId);
extern void func_02045CAC(struct MsgBank *msg, u32 index, struct StrBuf *dest);
extern void func_0201C7A4(struct Bitmap *bitmap, s16 x, s16 y, struct StrBuf *text, void *font);
extern void func_02045334(struct BmpWin *win);
extern void func_02045374(struct BmpWin *win);
extern u8 func_02045730(struct BmpWin *win);
extern void func_02041B6C(u32 bgBit);
extern void func_020456F8(struct BmpWin *win);
extern u32 TOUCHPANEL_GetPointCont(u32 *outX, u32 *outY);
extern void func_0207CA00(const TownMapVec *a, const TownMapVec *b, TownMapVec *out);
extern int func_0207CBD0(const TownMapVec *v);
extern void BG_SYS_ClearGraphicsMemory(u32 a);
extern void func_020433E0(const struct DispVram *banks);
extern void func_0204363C(u32 a);
extern void func_0204361C(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void func_0201DD60(void);
extern void func_0203F8F4(u16 heap);
extern void func_02045088(u16 heap);
extern void func_0203FC28(struct DispConfig *config);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *templ, u32 type);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02049B68(void *arc, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern u32 func_02049658(void *arc, u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern void func_020498F4(void *arc, u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_020414AC(u8 a);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const TownMapClactInit *init, const struct DispVram *banks, u32 heapId);
extern struct ClactUnit *func_0204B100(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct ClactUnit *unit);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204ABF0(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern u32 func_0204B1CC(struct ClactUnit *unit);
extern void func_0204A5AC(void);
extern void func_0204A600(int arg);
extern void func_0204A648(void);
extern TownMapInfoRow *func_0204A1BC(int, int, int, int);

/* Siblings in townmap.c. */
extern int func_021BA774(TownMapTown *town, int field);

extern char d_021BBD6C[];
extern struct DispVram d_021BBBDC;
extern struct DispConfig d_021BBBCC;
extern TownMapBgEntry d_021BBC28[];
extern const TownMapClactInit d_021BBC0C;

void func_021BB3E8(TownMapTextBox *box, int bgId, void *font, void *msg, u8 x, u8 y, u8 width, u8 height, u16 heapId);
void func_021BB42C(TownMapTextBox *box);
void func_021BB448(TownMapTextBox *box, u32 msgId, int x, int y);
void func_021BB49C(TownMapTextBox *box);
void func_021BB7BC(void);
void func_021BB80C(void *task, void *gfx);
void func_021BB820(TownMapGfx *gfx, u16 heapId);
void func_021BB968(TownMapGfx *gfx);
void func_021BB9B0(TownMapGfx *gfx);
void func_021BB9B8(TownMapSprites *sprites, const struct DispVram *banks, u16 heapId);
void func_021BBAB4(TownMapSprites *sprites);
void func_021BBAFC(int arg);
void func_021BBB04(TownMapSprites *sprites);
struct ClactActor *func_021BBB0C(TownMapSprites *sprites, int n);
unsigned int func_021BBB14(TownMapSprites *sprites, int n);
int func_021BBB1C(TownMapSprites *sprites, int i);

/* Text box. */
void func_021BB3E8(TownMapTextBox *box, int bgId, void *font, void *msg, u8 x, u8 y, u8 width, u8 height, u16 heapId)
{
    func_02082BCC(box, 0, sizeof(TownMapTextBox));
    box->font = font;
    box->msg = msg;
    box->win = func_020450F0(bgId, x, y, width, height, 0xe, 0);
    box->text = func_020457B0(0xff, heapId);
}

void func_021BB42C(TownMapTextBox *box)
{
    func_02045808(box->text);
    func_020452E8(box->win);
    func_02082BCC(box, 0, sizeof(TownMapTextBox));
}

void func_021BB448(TownMapTextBox *box, u32 msgId, int x, int y)
{
    struct BmpWin *win;

    func_02043B5C(func_02045770(box->win), 0);
    func_02045CAC(box->msg, msgId, box->text);
    func_0201C7A4(func_02045770(box->win), x, y, box->text, box->font);
    win = box->win;
    func_02045334(win);
    func_02045374(win);
    func_02041B6C(func_02045730(win));
}

void func_021BB49C(TownMapTextBox *box)
{
    struct BmpWin *win = box->win;

    func_020456F8(win);
    func_02041B6C(func_02045730(win));
}

/* Hover label. */
void func_021BB4B4(TownMapLabel *label, int bgId, void *font, void *msg, struct ClactActor *marker, u16 heapId)
{
    ScreenPos pos;

    func_02082BCC(label, 0, sizeof(TownMapLabel));
    label->marker = marker;
    func_021BB3E8(&label->box, bgId, font, msg, 0, 0, 0x18, 3, heapId);
    pos.x = 0x80;
    pos.y = 0x60;
    func_0204B404(label->marker, &pos, 0);
    func_0204B84C(label->marker, 1);
    CLACT_SetActorDrawPriority(label->marker, 1);
    func_0204B3DC(label->marker, 1);
    func_0204B878(label->marker, 0);
    func_0204B92C(label->marker, 1);
    CLACT_StopActorAnim(label->marker);
}

void func_021BB534(TownMapLabel *label)
{
    func_021BB42C(&label->box);
    func_02082BCC(label, 0, sizeof(TownMapLabel));
}

void func_021BB548(TownMapLabel *label)
{
    if (label->requested != 0) {
        label->requested = 0;
        func_0204B878(label->marker, 0);
        CLACT_StartActorAnim(label->marker);
        func_0204B3DC(label->marker, 1);
        func_021BB49C(&label->box);
        label->animating = 1;
    }
    if (label->animating != 0 && func_0204B98C(label->marker) == 0) {
        func_021BB448(&label->box, func_02013E4C((u16)func_021BA774(label->town, 0)), 0x10, 2);
        CLACT_StopActorAnim(label->marker);
        label->animating = 0;
    }
}

void func_021BB5AC(TownMapLabel *label, TownMapTown *town)
{
    label->requested = 1;
    label->town = town;
}

void func_021BB5B4(TownMapLabel *label, u32 visible)
{
    func_0204B3DC(label->marker, visible);
    if (visible == 0) {
        label->requested = 0;
        label->animating = 0;
        func_021BB49C(&label->box);
    }
}

/* Touch drag tracking. */
void func_021BB5D4(TownMapTouch *touch, int heapId)
{
    func_02082BCC(touch, 0, sizeof(TownMapTouch));
}

void func_021BB5E0(TownMapTouch *touch)
{
    func_02082BCC(touch, 0, sizeof(TownMapTouch));
}

void func_021BB5EC(TownMapTouch *touch)
{
    u32 touchX;
    u32 touchY;

    touch->dragged = 0;
    if (func_02035D20(&touchX, &touchY)) {
        if (touchY <= 0xA8) {
            touch->prev.x = touchX << 12;
            touch->prev.y = touchY << 12;
            touch->prev.z = 0;
            touch->cur.x = touchX << 12;
            touch->cur.y = touchY << 12;
            touch->cur.z = 0;
        }
        return;
    }
    if (TOUCHPANEL_GetPointCont(&touchX, &touchY)) {
        if (touchY <= 0xA8) {
            if (touch->reanchor != 0) {
                touch->prev = touch->cur;
                touch->reanchor = 0;
            }
            touch->cur.x = touchX << 12;
            touch->cur.y = touchY << 12;
            touch->cur.z = 0;
            func_0207CA00(&touch->cur, &touch->prev, &touch->delta);
            if (func_0207CBD0(&touch->delta) >= 0x1000) {
                touch->dragged = 1;
            }
        } else {
            touch->prev.x = touchX << 12;
            touch->prev.y = touchY << 12;
            touch->prev.z = 0;
            touch->cur.x = touchX << 12;
            touch->cur.y = touchY << 12;
            touch->cur.z = 0;
        }
    }
}

int func_021BB6AC(TownMapTouch *touch, TownMapVec *delta, u32 *dragState)
{
    if (touch->dragged != 0) {
        if (delta != 0)
            *delta = touch->delta;
        if (dragState != 0)
            *dragState = touch->dragState;
        return 1;
    }
    return 0;
}

void func_021BB6DC(TownMapTouch *touch)
{
    touch->reanchor = 1;
}

/* Empty per frame task. */
void func_021BB6E4(void *task, void *arg)
{
}

/* Graphics set. */
TownMapGfx *func_021BB6E8(u16 heapId)
{
    TownMapGfx *gfx;

    gfx = func_02030734(heapId, sizeof(TownMapGfx), 0, d_021BBD6C, 0xEC);
    func_02082BCC(gfx, 0, sizeof(TownMapGfx));
    func_021BB7BC();
    func_021BB820(gfx, heapId);
    func_021BB9B8(&gfx->sprites, &d_021BBBDC, heapId);
    gfx->task = func_020056A0(func_021BB80C, gfx, 1);
    return gfx;
}

void func_021BB738(TownMapGfx *gfx)
{
    func_02030EAC(gfx->task);
    func_021BBAB4(&gfx->sprites);
    func_021BB968(gfx);
    func_020307B0(gfx);
}

void func_021BB758(TownMapGfx *gfx)
{
    func_021BBAFC((int)&gfx->sprites);
}

u8 func_021BB764(TownMapGfx *gfx, u32 i)
{
    return d_021BBC28[i].bgId;
}

unsigned int func_021BB778(TownMapGfx *gfx, int n)
{
    return func_021BBB14(&gfx->sprites, n);
}

struct ClactActor *func_021BB784(TownMapGfx *gfx, int n)
{
    return func_021BBB0C(&gfx->sprites, n);
}

void func_021BB790(TownMapGfx *gfx, int *charId, int *cellId, int *palId)
{
    *charId = func_021BBB1C(&gfx->sprites, 0);
    *cellId = func_021BBB1C(&gfx->sprites, 1);
    *palId = func_021BBB1C(&gfx->sprites, 2);
}

void func_021BB7BC(void)
{
    REG_BLDCNT = 0;
    REG_DB_BLDCNT = 0;
    REG_DISPCNT &= ~DISPCNT_WINDOW_BITS;
    REG_DB_DISPCNT &= ~DISPCNT_WINDOW_BITS;
    BG_SYS_ClearGraphicsMemory(0);
    func_020433E0(&d_021BBBDC);
    func_0204363C(0);
    func_0204361C();
    BG_SYS_ClearMainPlanes();
    func_0201DD60();
}

void func_021BB80C(void *task, void *gfx)
{
    func_021BBB04(&((TownMapGfx *)gfx)->sprites);
    func_021BB9B0(gfx);
}

/* Sets up the display layers and uploads the town map graphics. */
void func_021BB820(TownMapGfx *gfx, u16 heapId)
{
    int i;
    u32 bgId;
    void *arc;

    i = 0;
    func_02082BCC(&gfx->bgReady, 0, sizeof(gfx->bgReady));
    func_0203F8F4(heapId);
    func_02045088(heapId);
    func_0203FC28(&d_021BBBCC);
    for (; i < TOWNMAP_GRH_BG_COUNT; i++) {
        bgId = d_021BBC28[i].bgId;
        func_0203FCA0((u8)bgId, (const struct BgTemplate *)&d_021BBC28[i].templ, (u8)d_021BBC28[i].mode);
        func_02040588(bgId, 1);
    }
    arc = func_020490F4(0x55, heapId);
    func_02049B68(arc, 0, 2, 0x6000, 0x2000, heapId);
    func_02049B68(arc, 0, 2, 0x4000, 0x2000, heapId);
    func_02049658(arc, 5, 2, 0, 0x10000, 0, heapId);
    func_02049658(arc, 7, 3, 0, 0x10000, 0, heapId);
    func_020498F4(arc, 0x11, 2, 0, 0x800, 0, heapId);
    func_020498F4(arc, 0x10, 3, 0, 0x800, 0, heapId);
    func_02049B68(arc, 1, 4, 0, 0, heapId);
    func_02049658(arc, 6, 5, 0, 0, 0, heapId);
    func_020498F4(arc, 0xf, 5, 0, 0, 0, heapId);
    func_02049B40(0x17, 5, 0, 0x1c0, 0x20, heapId);
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, heapId);
    func_02040C14(1, 0, 1, 0);
    func_02049238(arc);
}

void func_021BB968(TownMapGfx *gfx)
{
    int i;
    u32 bgId;

    func_02040DA8(1, 1, 0);
    for (i = 0; i < TOWNMAP_GRH_BG_COUNT; i++) {
        bgId = d_021BBC28[i].bgId;
        func_020414AC(bgId);
        func_020403F4((u8)bgId);
    }
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(&gfx->bgReady, 0, sizeof(gfx->bgReady));
}

void func_021BB9B0(TownMapGfx *gfx)
{
    func_020419E4();
}

void func_021BB9B8(TownMapSprites *sprites, const struct DispVram *banks, u16 heapId)
{
    int i;
    void *arc;
    TownMapClactInit init;
    SpriteInit actorInit;

    i = 0;
    func_02082BCC(sprites, 0, sizeof(TownMapSprites));
    init = d_021BBC0C;
    func_0204A48C(&init, banks, heapId);
    sprites->unit = func_0204B100(0x80, 0, heapId);
    CLACT_SetUnitDefaultRenderer(sprites->unit);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    arc = func_020490F4(0x55, heapId);
    sprites->palId = func_0204ABF0(arc, 2, 0, 0, heapId);
    sprites->charId = func_0204A6C8(arc, 8, 0, 0, heapId);
    sprites->cellId = func_0204AF28(arc, 0xc, 0x13, heapId);
    func_02049238(arc);
    func_02082BCC(&actorInit, 0, sizeof(SpriteInit));
    for (; i < 4; i++) {
        sprites->actor[i] = func_0204B294(sprites->unit, sprites->charId, sprites->palId, sprites->cellId, &actorInit, 1, heapId);
    }
    func_0204B878(sprites->actor[0], 0);
    func_0204B878(sprites->actor[1], 4);
    func_0204B878(sprites->actor[2], 5);
    func_0204B878(sprites->actor[3], 6);
    for (i = 0; i < 4; i++) {
        func_0204B3DC(sprites->actor[i], 0);
    }
}

void func_021BBAB4(TownMapSprites *sprites)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (sprites->actor[i] != 0) {
            func_0204B3B4(sprites->actor[i]);
        }
    }
    func_0204AFD8(sprites->cellId);
    func_0204A8D4(sprites->charId);
    func_0204ADA4(sprites->palId);
    if (sprites->unit != 0) {
        func_0204B1CC(sprites->unit);
    }
    func_0204A5AC();
    func_02082BCC(sprites, 0, sizeof(TownMapSprites));
}

/* Thumb long-branch veneer to func_0204A600, declared as an ordinary call. */
void func_021BBAFC(int arg)
{
    func_0204A600(arg);
}

void func_021BBB04(TownMapSprites *sprites)
{
    func_0204A648();
}

struct ClactActor *func_021BBB0C(TownMapSprites *sprites, int n)
{
    return sprites->actor[n];
}

unsigned int func_021BBB14(TownMapSprites *sprites, int n)
{
    return sprites->handle[n];
}

int func_021BBB1C(TownMapSprites *sprites, int i)
{
    return sprites->resourceId[i];
}

TownMapInfoRow *func_021BBB24(int heapId)
{
    return func_0204A1BC(0x56, 0, 0, heapId);
}

void func_021BBB34(TownMapInfoRow *info)
{
    func_020307B0(info);
}

unsigned short func_021BBB3C(TownMapInfoRow *info, u16 row, int col)
{
    return info[row].value[col];
}

/* Linear search of the town info table for the row whose first value is id; 0xffff when none. */
int func_021BBB48(TownMapInfoRow *info, int id)
{
    int rowIndex;
    int firstColumn = 0;

    for (rowIndex = 0; rowIndex < 0x3d; rowIndex++) {
        if (func_021BBB3C(info, rowIndex, firstColumn) == id)
            return (u16)rowIndex;
    }
    return 0xffff;
}
