/*
 * file:     zknd_tbar.c
 * unit:     yes
 * function: ZKND_TBAR_CreateButtonList, ZKND_TBAR_DeleteButtonList, ZKND_TBAR_UpdateButtons, ZKND_TBAR_GetPressedKey, ZKND_TBAR_GetHeldKey, ZKND_TBAR_SetButtonDrawEnable, ZKND_TBAR_SetTouchEnable, ZKND_TBAR_GetTouchEnable, ZKND_TBAR_ClearButtonState, ZKND_TBAR_SetButtonAnimSeq, ZKND_TBAR_SetButtonVisible, ZKND_TBAR_GetButtonVisible, ZKND_TBAR_SetButtonAnimSeqLoop, ZKND_TBAR_SetButtonAnimSeqOnce, ZKND_TBAR_IsButtonAnimActive, ZKND_TBAR_GetButtonActor, ZKND_TBAR_AddButtonPos, ZKND_TBAR_GetButtonActorRaw, ZKND_TBAR_FindButtonActor, ZKND_TBAR_IsKeyAnimActive, ZKND_TBAR_LoadButtonResources, ZKND_TBAR_ReleaseButtonResources, ZKND_TBAR_GetResourceSlot, ZKND_TBAR_LoadCellArchive, ZKND_TBAR_CreateButton, ZKND_TBAR_DeleteButton, ZKND_TBAR_UpdateButtonTouch, ZKND_TBAR_IsButtonAnimating, ZKND_TBAR_GetButtonActorBase, ZKND_TBAR_SetActorDrawEnable, ZKND_TBAR_GetActorDrawEnable, ZKND_TBAR_SetActorAnimSeq, ZKND_TBAR_SetPressedAnim, ZKND_TBAR_SetAnimByState, ZKND_TBAR_GetButtonSound, ZKND_TBAR_GetButtonCount, ZKND_TBAR_PlayCancelAnim, ZKND_TBAR_PlayButtonAnim
 * address:  0x021BD148
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan_detail_common.c, zukan_detail_graphic.c, zukan_detail_form.c, ZUKAN_DETAIL_FORM_CopyModelPosition.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_RegisterObjCharFromHandle  0x02049740  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   ZKND_TBAR_CreateButton        0x021BD634  thumb
 *   data_021C8DD8        0x021C8DD8  data
 *   CLACT_AddActorSurfacePos        0x0204B404  arm
 *   APP_ICON_GetArchiveId        0x020275E4  thumb
 *   APP_ICON_GetStatusAnimFileId        0x02027624  thumb
 *   ARC_UTIL_UploadPaletteFromHandleWhole        0x02049B68  arm
 *   APP_ICON_GetStatusFrameFileId        0x02027628  thumb
 *   APP_ICON_GetStatusDataFileId        0x0202762C  thumb
 *   APP_ICON_GetMoveKindPaletteFileId        0x02027614  thumb
 *   CLACT_RegisterPaletteEx        0x0204AC18  arm
 *   APP_ICON_GetMoveKindAnimFileId        0x02027618  thumb
 *   CLACT_RegisterCharacter        0x0204A6C8  arm
 *   APP_ICON_GetStatusCellFileId        0x0202761C  thumb
 *   APP_ICON_GetStatusPaletteFileId        0x02027620  thumb
 *   CLACT_RegisterCellAnim        0x0204AF28  arm
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   BG_SYS_GetColorMode  0x0204169C  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BG_SYS_GetPriority  0x020416D4  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   data_021C8314  0x021C8314  data
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../types.h"
#include "../arm9/clact.h"
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/ui.h"
#include "zukan_detail_types.h"
#include "zukan_detail_shared_types.h"

#include "../arm9/gfl_heap_wrap.h"


extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);


extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);

struct Ov208Scrn {
    u8  pad0[0xc];
    u16 tiles[1];
};

struct Ov208ActKind {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u32 e;
    u32 f;
};

struct Ov208Pos {
    short x;
    short y;
    u16 animSeq;
    u8  pad6;
    u8  layer;
};


#include "../arm9/mi_memory.h"


#include "../arm9/app_icon.h"

















#include "../arm9/nns_g2d_load.h"

extern u8 BG_SYS_GetColorMode(int channel);

extern u32 BG_SYS_GetBuf(int channel);


/* The DS code was built against other parameter widths for BG_SYS_PushTile (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void BG_SYS_PushTile(u8 channel);
extern void BG_SYS_DrawTileEx(unsigned int index, unsigned char dx, unsigned char dy, unsigned char cw, unsigned char ch, void *src, unsigned char sx, unsigned char sy, unsigned char sw, unsigned char sh);
#else
#include "../arm9/bg_sys.h"
#endif

extern u8   BG_SYS_GetPriority(u32 layer);

struct Actor;




#include "../arm9/touchpanel.h"


#include "../arm9/key.h"




#include "../arm9/gfl_use.h"

struct Ov208Mgr *ZKND_TBAR_CreateButtonList(struct Ov208ActList *list, u16 heap);

void ZKND_TBAR_DeleteButtonList(struct Ov208Mgr *m);

void ZKND_TBAR_UpdateButtons(struct Ov208Mgr *p);

int ZKND_TBAR_GetPressedKey(struct Ov208Mgr *p);

int ZKND_TBAR_GetHeldKey(struct Ov208Mgr *m);

void ZKND_TBAR_SetButtonDrawEnable(struct Ov208Mgr *p, int v);

void ZKND_TBAR_SetTouchEnable(struct Ov208Mgr *p, int v);

int ZKND_TBAR_GetTouchEnable(struct Ov208Mgr *p);

void ZKND_TBAR_ClearButtonState(struct Ov208Mgr *p);

void ZKND_TBAR_SetButtonAnimSeq(struct Ov208Mgr *a, int b, int c);

void ZKND_TBAR_SetButtonVisible(struct Ov208Mgr *a, int b, int c);

int ZKND_TBAR_GetButtonVisible(struct Ov208Mgr *mgr, int key);

void ZKND_TBAR_SetButtonAnimSeqLoop(struct Ov208Mgr *a, int b, int c);

void ZKND_TBAR_SetButtonAnimSeqOnce(struct Ov208Mgr *a, int b, int c);

int ZKND_TBAR_IsButtonAnimActive(struct Ov208Mgr *mgr, int key);

int ZKND_TBAR_GetButtonActor(struct Ov208Mgr *mgr, int key);

void ZKND_TBAR_AddButtonPos(struct Ov208Mgr *p, int key, u16 *pos);

void ZKND_TBAR_GetButtonActorRaw(struct Ov208Mgr *mgr, int key);

struct Ov208Rec *ZKND_TBAR_FindButtonActor(struct Ov208Mgr *p, int key);

void *ZKND_TBAR_IsKeyAnimActive(void *mgr, int key);

void ZKND_TBAR_LoadButtonResources(struct Ov208Bg *p, u32 channel, u32 objChannel, u32 palOfs, u32 kind, u8 pal, u8 objPal, u32 skip, u16 heap);

void ZKND_TBAR_ReleaseButtonResources(char *p);

int ZKND_TBAR_GetResourceSlot(int *p, int i);

void ZKND_TBAR_LoadCellArchive(void *narc, u32 fileId, u32 channel, u32 add, u8 srcX, u8 srcY, u8 srcW, u8 srcH, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u16 heap);

void ZKND_TBAR_CreateButton(struct Ov208Rec *p, u32 owner, const int *res, struct Ov208ActDesc *desc, u32 prio, u16 mode);

void ZKND_TBAR_DeleteButton(char *p);

int ZKND_TBAR_UpdateButtonTouch(char *p);

int ZKND_TBAR_IsButtonAnimating(int *p);

int ZKND_TBAR_GetButtonActorBase(char *p);

void ZKND_TBAR_SetActorDrawEnable(struct ClactActor **p, unsigned int v);

unsigned ZKND_TBAR_GetActorDrawEnable(int *p);

void ZKND_TBAR_SetActorAnimSeq(char *p, int v);

void ZKND_TBAR_SetPressedAnim(char *p, int v);

void ZKND_TBAR_SetAnimByState(char *p, int which);

int ZKND_TBAR_GetButtonSound(const void *p);

void ZKND_TBAR_GetButtonCount(char *p);

void ZKND_TBAR_PlayCancelAnim(char *p);

void ZKND_TBAR_PlayButtonAnim(char *p);

extern const char data_021C8DD8[];

extern const struct Ov208ActKind data_021C8314[];

struct Ov208Mgr *ZKND_TBAR_CreateButtonList(struct Ov208ActList *list, u16 heap)
{
    struct Ov208Mgr *set;
    u32 size;
    u32 objChannel;
    u32 palOfs;
    u32 i;

    palOfs = 0;
    size = list->count * sizeof(struct Ov208Rec) + 0x28;
    set = GFL_HEAP_Alloc(heap, size, 0, data_021C8DD8, 0x107);
    MI_CpuFill8(set, 0, size);
    set->count = list->count;
    set->phase = 0;
    set->touchEnabled = 1;
    set->latched = 0;
    objChannel = 1;
    if (list->channel >= 4)
        palOfs = 4;
    else
        objChannel = 0;
    ZKND_TBAR_LoadButtonResources(&set->bg, (u8)list->channel, objChannel, palOfs, list->kind,
                        (u8)list->pal, (u8)list->objPal, list->skip, heap);
    for (i = 0; i < set->count; i++)
        ZKND_TBAR_CreateButton(&set->recs[i], list->owner, (const int *)&set->bg, &list->descs[i], objChannel, heap);
    return set;
}

void ZKND_TBAR_DeleteButtonList(struct Ov208Mgr *mgr)
{
    u32 i;
    for (i = 0; i < mgr->count; i++)
        ZKND_TBAR_DeleteButton((char *)(&mgr->recs[i]));
    ZKND_TBAR_ReleaseButtonResources((char *)&mgr->bg);
    GFL_HEAP_Free(mgr);
}

void ZKND_TBAR_UpdateButtons(struct Ov208Mgr *p)
{
    unsigned i;
    switch(p->phase) {
    case 0:
        p->pressedIndex=-1;
        if(p->touchEnabled && !p->latched) {
            for(i=0;i<p->count;i++) {
                if(ZKND_TBAR_UpdateButtonTouch((char *)&p->recs[i])) {
                    p->pressedIndex=i;
                    p->phase=1;
                    p->latched=1;
                    break;
                }
            }
        }
        break;
    case 1:
        p->phase=2;
    case 2:
        if(ZKND_TBAR_IsButtonAnimating((int *)&p->recs[p->pressedIndex]))p->phase=3;
        break;
    case 3:
        p->phase=0;
        break;
    }
    for(i=0;i<p->count;i++)ZKND_TBAR_GetButtonCount((char *)&p->recs[i]);
}

/*
 * Returns +0x14 of the 0x38-byte record selected by the index at +0, or -1.
 */
int ZKND_TBAR_GetPressedKey(struct Ov208Mgr *p)
{
    int i;

    if (p->phase == 3) {
        i = p->pressedIndex;
        if (i != -1)
            return ZKND_TBAR_GetButtonActorBase((char *)&p->recs[i]);
    }
    return -1;
}

int ZKND_TBAR_GetHeldKey(struct Ov208Mgr *mgr)
{
    if (mgr->phase == 1 && mgr->pressedIndex != -1)
        return ZKND_TBAR_GetButtonActorBase((char *)(&mgr->recs[mgr->pressedIndex]));
    return -1;
}

void ZKND_TBAR_SetButtonDrawEnable(struct Ov208Mgr *p, int enable)
{
    u32 i;

    for (i = 0; i < p->count; i++)
        ZKND_TBAR_SetActorDrawEnable((void *)((uptr)p + 0x28 + i * 0x38), enable);
}

/*
 * Stores the second argument at +0xC.
 */
void ZKND_TBAR_SetTouchEnable(struct Ov208Mgr *p, int enable)
{
    p->touchEnabled = enable;
}

/*
 * Returns the word at +0xC (the two words after it are untraced continuations).
 */
int ZKND_TBAR_GetTouchEnable(struct Ov208Mgr *p)
{
    return p->touchEnabled;
}

void ZKND_TBAR_ClearButtonState(struct Ov208Mgr *p)
{
    p->latched = 0;
}

void ZKND_TBAR_SetButtonAnimSeq(struct Ov208Mgr *mgr, int key, int enabled)
{
    ZKND_TBAR_SetActorAnimSeq((char *)ZKND_TBAR_FindButtonActor(mgr, key), enabled);
}

void ZKND_TBAR_SetButtonVisible(struct Ov208Mgr *mgr, int key, int visible)
{
    ZKND_TBAR_SetActorDrawEnable((struct ClactActor **)ZKND_TBAR_FindButtonActor(mgr, key), visible);
}

int ZKND_TBAR_GetButtonVisible(struct Ov208Mgr *mgr, int key)
{
    return ZKND_TBAR_GetActorDrawEnable(ZKND_TBAR_IsKeyAnimActive(mgr, key));
}

void ZKND_TBAR_SetButtonAnimSeqLoop(struct Ov208Mgr *mgr, int key, int keyMask)
{
    ZKND_TBAR_SetPressedAnim((char *)ZKND_TBAR_FindButtonActor(mgr, key), keyMask);
}

void ZKND_TBAR_SetButtonAnimSeqOnce(struct Ov208Mgr *mgr, int key, int pressed)
{
    ZKND_TBAR_SetAnimByState((char *)ZKND_TBAR_FindButtonActor(mgr, key), pressed);
}

int ZKND_TBAR_IsButtonAnimActive(struct Ov208Mgr *mgr, int key)
{
    return ZKND_TBAR_GetButtonSound(ZKND_TBAR_IsKeyAnimActive(mgr, key));
}

int ZKND_TBAR_GetButtonActor(struct Ov208Mgr *mgr, int key)
{
    return ZKND_TBAR_FindButtonActor(mgr, key)->actor;
}

void ZKND_TBAR_AddButtonPos(struct Ov208Mgr *p, int key, u16 *pos)
{
    struct Ov208Rec *r = ZKND_TBAR_FindButtonActor(p, key);

    r->desc.x = pos[0];
    r->desc.y = pos[1];
    CLACT_AddActorSurfacePos((struct ClactActor *)r->actor, (const struct ClactVec2 *)pos, (u16)(p->bg.channel >= 4 ? 1 : 0));
}

void ZKND_TBAR_GetButtonActorRaw(struct Ov208Mgr *mgr, int key)
{
    ZKND_TBAR_FindButtonActor(mgr, key)->forcePress = 1;
}

struct Ov208Rec *ZKND_TBAR_FindButtonActor(struct Ov208Mgr *p, int key)
{
    u32 i;

    for (i = 0; i < p->count; i++) {
        if (key == ZKND_TBAR_GetButtonActorBase((char *)((uptr)p + 0x28 + i * 0x38)))
            return (struct Ov208Rec *)((uptr)p + 0x28 + i * 0x38);
    }
    return 0;
}

void *ZKND_TBAR_IsKeyAnimActive(void *mgr, int key)
{
    return ZKND_TBAR_FindButtonActor(mgr, key);
}

void ZKND_TBAR_LoadButtonResources(struct Ov208Bg *p, u32 channel, u32 objChannel, u32 palOfs,
                         u32 kind, u8 pal, u8 objPal, u32 skip, u16 heap)
{
    void *h;

    MI_CpuFill8(p, 0, sizeof(*p));
    p->channel = channel;
    h = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), heap);
    if (skip == 0) {
        ARC_UTIL_UploadPaletteFromHandleWhole(h, APP_ICON_GetStatusAnimFileId(), palOfs, pal << 5, 0x20, heap);
        p->charRange = ARC_UTIL_RegisterObjCharFromHandle(h, APP_ICON_GetStatusFrameFileId(), p->channel, 0x800, 0, heap);
        ZKND_TBAR_LoadCellArchive(h, APP_ICON_GetStatusDataFileId(), p->channel, (u16)p->charRange, 0, 0x15, 0x20, 0x18,
                            0, 0x15, 0x20, 3, pal, 0, heap);
    }
    p->palette = CLACT_RegisterPaletteEx(h, APP_ICON_GetMoveKindPaletteFileId(), objChannel, (u16)(objPal << 5), 0, 3, heap);
    p->character = CLACT_RegisterCharacter(h, APP_ICON_GetMoveKindAnimFileId(), 0, objChannel, heap);
    p->cellAnim = CLACT_RegisterCellAnim(h, APP_ICON_GetStatusCellFileId(kind), APP_ICON_GetStatusPaletteFileId(kind), heap);
    ARC_TOOL_DeleteHandle(h);
}

/*
 * Releases +8, +4 and +0, passes the pair at +0x10 on and clears the 0x14-byte object.
 */
void ZKND_TBAR_ReleaseButtonResources(char *p)
{
    unsigned int w;

    CLACT_ReleaseCellAnim(((struct Ov208Bg *)p)->cellAnim);
    CLACT_ReleaseCharacter(((struct Ov208Bg *)p)->character);
    CLACT_ReleasePalette(((struct Ov208Bg *)p)->palette);
    w = ((struct Ov208Bg *)p)->charRange;
    BG_SYS_FreeTileRun(((struct Ov208Bg *)p)->channel, (unsigned short)w, (unsigned short)(w >> 16));
    MI_CpuFill8((void *)((sptr)p), 0, 0x14);
}

int ZKND_TBAR_GetResourceSlot(int *p, int i)
{
    return p[i];
}

void ZKND_TBAR_LoadCellArchive(void *narc, u32 fileId, u32 channel, u32 add, u8 srcX, u8 srcY, u8 srcW,
                         u8 srcH, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 decompress, u16 heap)
{
    struct Ov208Scrn *scr;
    uptr file;
    int i;
    u16 *d;

    file = (uptr)ARC_UTIL_LoadHandleMember(narc, fileId, decompress, (u16)((heap & 0x7fff) | 0x8000));
    NNS_G2dGetUnpackedScreenData((void *)file, (void **)(&scr));
    if (add != 0 && BG_SYS_GetColorMode((u8)channel) == 0) {
        d = scr->tiles;
        for (i = 0; i < srcW * srcH; i++)
            d[i] += (u16)add;
    }
    if ((int)BG_SYS_GetBuf((u8)channel) != 0) {
        BG_SYS_DrawTileEx((u8)channel, x, y, w, h, scr->tiles, srcX, srcY, srcW, srcH);
        BG_SYS_FillTileMap(channel, x, y, w, h, pal);
        BG_SYS_PushTile(channel);
    }
    GFL_HEAP_Free((void *)file);
}

void ZKND_TBAR_CreateButton(struct Ov208Rec *p, u32 owner, const int *res, struct Ov208ActDesc *desc,
                         u32 prio, u16 mode)
{
    struct Ov208Pos pos;
    u32 i;
    u32 j;
    u32 k;
    int n;

    MI_CpuFill8(p, 0, 0x38);
    p->desc = *desc;
    p->enabled = 1;
    p->forcePress = 0;
    MI_CpuFill8(&pos, 0, 8);
    pos.layer = BG_SYS_GetPriority((u8)res[3]);
    pos.x = desc->x;
    pos.y = desc->y;
    if (desc->key >= 7) {
        i = desc->charRes;
        j = desc->palRes;
        k = desc->cellRes;
        p->pressKind = 0;
    } else {
        i = ZKND_TBAR_GetResourceSlot((int *)res, 1);
        j = ZKND_TBAR_GetResourceSlot((int *)res, 0);
        k = ZKND_TBAR_GetResourceSlot((int *)res, 2);
        n = desc->key;
        p->desc.idleAnim = data_021C8314[n].a;
        p->desc.disabledAnim = data_021C8314[n].b;
        p->desc.pressedAnim = data_021C8314[n].c;
        p->desc.keyMask = data_021C8314[n].e;
        p->desc.seId = data_021C8314[n].d;
        p->pressKind = data_021C8314[n].f;
    }
    p->animSeq = p->desc.idleAnim;
    pos.animSeq = p->desc.idleAnim;
    p->actor = (uptr)CLACT_CreateActor((struct Unit *)owner, i, j, k, (struct ActorInitParam *)(&pos), prio, mode);
    CLACT_SetActorAutoAnim((struct ClactActor *)p->actor, 1);
    switch (p->pressKind) {
    case 0:
        p->onPress = (void (*)(void))ZKND_TBAR_PlayCancelAnim;
        break;
    case 1:
        p->onPress = (void (*)(void))ZKND_TBAR_PlayButtonAnim;
        break;
    }
}

/*
 * Releases +0 and clears 0x38 bytes of the object.
 */
void ZKND_TBAR_DeleteButton(char *p)
{
    CLACT_DeleteActor((struct ClactActor *)(((struct Ov208Rec *)p)->actor));
    MI_CpuFill8(p, 0, 0x38);
}

int ZKND_TBAR_UpdateButtonTouch(char *p)
{
    unsigned x,y;
    int hit=0;
    if(CLACT_GetActorDrawEnable((struct ClactActor *)((struct Ov208Rec *)p)->actor)&((struct Ov208Rec *)p)->enabled) {
        if(TOUCHPANEL_GetPointTrg(&x,&y) && x-((struct Ov208Rec *)p)->desc.x<=((struct Ov208Rec *)p)->desc.hitWidth && y-((struct Ov208Rec *)p)->desc.y<=24) {
            hit=1;
            UI_SetInputMode(1);
        }
        if(((struct Ov208Rec *)p)->desc.keyMask && (KEY_GetTrg()&((struct Ov208Rec *)p)->desc.keyMask)) {
            UI_SetInputMode(0);
            hit=1;
        }
        if(((struct Ov208Rec *)p)->forcePress) {
            UI_SetInputMode(0);
            hit=1;
        }
        if(hit) {
            (*(void (**)(char *))(p+0xc))(p);
            return 1;
        }
    }
    return 0;
}

/*
 * Returns 1 when the ARM9 call at 0x0204B98C on the word at [p] comes back zero.
 */
int ZKND_TBAR_IsButtonAnimating(int *p)
{
    return CLACT_IsActorAnimActive((struct ClactActor *)(*p)) == 0;
}

int ZKND_TBAR_GetButtonActorBase(char *p)
{
    return ((struct Ov208Rec *)p)->desc.key;
}

/*
 * Loads the word at [p] and tail-calls the function at 0x0204B3DC with it and
 * the second argument.
 */
void ZKND_TBAR_SetActorDrawEnable(struct ClactActor **p, unsigned int enable)
{
    CLACT_SetActorDrawEnable((struct ClactActor *)(*p), enable);
}

unsigned ZKND_TBAR_GetActorDrawEnable(int *p)
{
    return CLACT_GetActorDrawEnable((struct ClactActor *)(*p));
}

void ZKND_TBAR_SetActorAnimSeq(char *p, int enabled)
{
    ((struct Ov208Rec *)p)->enabled = enabled;
    if (enabled != 0) {
        if (((struct Ov208Rec *)p)->animSeq == ((struct Ov208Rec *)p)->desc.pressedAnim)
            ((struct Ov208Rec *)p)->animSeq = ((struct Ov208Rec *)p)->desc.idleAnim;
        CLACT_SetActorAnimSeq((struct ClactActor *)(((struct Ov208Rec *)p)->actor), (unsigned short)((struct Ov208Rec *)p)->animSeq);
    } else {
        CLACT_SetActorAnimSeq((struct ClactActor *)(((struct Ov208Rec *)p)->actor), ((struct Ov208Rec *)p)->desc.disabledAnim);
    }
}

void ZKND_TBAR_SetPressedAnim(char *p, int keyMask)
{
    ((struct Ov208Rec *)p)->desc.keyMask = keyMask;
}

void ZKND_TBAR_SetAnimByState(char *p, int which)
{
    if (which != 0)
    {
        ((struct Ov208Rec *)p)->animSeq = ((struct Ov208Rec *)p)->desc.pressedAnim;
    }
    else
    {
        ((struct Ov208Rec *)p)->animSeq = ((struct Ov208Rec *)p)->desc.idleAnim;
    }
    CLACT_SetActorAnimSeq((struct ClactActor *)((struct Ov208Rec *)p)->actor, (unsigned short)((struct Ov208Rec *)p)->animSeq);
}

int ZKND_TBAR_GetButtonSound(const void *p)
{
    u32 r1 = ((struct Ov208Rec *)p)->animSeq;
    u32 r0 = ((struct Ov208Rec *)p)->desc.pressedAnim;
    return r1 == r0;
}

/*
 * Clears the word at +0x34.
 */
void ZKND_TBAR_GetButtonCount(char *p)
{
    ((struct Ov208Rec *)p)->forcePress = 0;
}

/*
 * Re-verified 2026-09-27 (DIFF fixer lane): the +8 store in the image is a
 * full word, `str r1,[r4,#8]`, not `strh`: the zero-extended u16 is written
 * through an int lvalue.  With `*(int *)(p + 8) = h;` the whole function
 * reproduces, including `ldrh r1,[r4,#0x28]; ldr r0,[r4]; str r1,[r4,#8]`.
 * EXACT*: the inferred extent runs 2 bytes past `pop` (an unlabelled
 * follower/alignment word), never a byte difference.
 */
void ZKND_TBAR_PlayCancelAnim(char *p)
{
    unsigned short h = ((struct Ov208Rec *)p)->desc.pressedAnim;
    int v = ((struct Ov208Rec *)p)->actor;

    ((struct Ov208Rec *)p)->animSeq = h;
    CLACT_SetActorAnimSeq((struct ClactActor *)v, h);
    if (((struct Ov208Rec *)p)->desc.seId != 0)
        GFL_USE_PlaySeDefaultVolume(((struct Ov208Rec *)p)->desc.seId);
}

void ZKND_TBAR_PlayButtonAnim(char *p)
{
    int f = ZKND_TBAR_GetButtonSound(p) == 0;

    ZKND_TBAR_SetAnimByState(p, f);
    if (((struct Ov208Rec *)p)->desc.seId != 0)
        GFL_USE_PlaySeDefaultVolume(((struct Ov208Rec *)p)->desc.seId);
}
