/*
 * file:     zukan_detail_touchbar.c
 * unit:     yes
 * function: ZUKAN_DETAIL_TOUCHBAR_Create, ZUKAN_DETAIL_TOUCHBAR_Delete, ZUKAN_DETAIL_TOUCHBAR_Update, ZUKAN_DETAIL_TOUCHBAR_SetMode, ZUKAN_DETAIL_TOUCHBAR_GetMode, ZUKAN_DETAIL_TOUCHBAR_SetEnabled, ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled, ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId, ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId, ZUKAN_DETAIL_TOUCHBAR_ClearButtonState, ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable, ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind, ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible, ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq, ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive, ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled, ZUKAN_DETAIL_TOUCHBAR_GetCurrentSlot, ZUKAN_DETAIL_TOUCHBAR_SetBgPriority, ZUKAN_DETAIL_TOUCHBAR_FlushBar, ZUKAN_DETAIL_TOUCHBAR_LoadResources, ZUKAN_DETAIL_TOUCHBAR_ReleaseResources, ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos, ZUKAN_DETAIL_TOUCHBAR_LoadBarResources, ZUKAN_DETAIL_TOUCHBAR_ReleaseBarResources, ZUKAN_DETAIL_TOUCHBAR_UpdateInput, ZUKAN_DETAIL_TOUCHBAR_FreeAnimBuffer, ZUKAN_DETAIL_TOUCHBAR_GetPaletteFlag, ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteLeft, ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteRight, ZUKAN_DETAIL_TOUCHBAR_LoadPaletteTable, ZUKAN_DETAIL_TOUCHBAR_GetPaletteForKind, ZUKAN_DETAIL_TOUCHBAR_GetLeftPalette, ZUKAN_DETAIL_TOUCHBAR_GetRightPalette, ZUKAN_DETAIL_TOUCHBAR_LoadLeftArrowResources, ZUKAN_DETAIL_TOUCHBAR_ReleaseLeftArrowResources, ZUKAN_DETAIL_TOUCHBAR_LoadRightArrowResources, ZUKAN_DETAIL_TOUCHBAR_ReleaseRightArrowResources, ZUKAN_DETAIL_TOUCHBAR_UpdateArrowInput
 * address:  0x021BD8C0
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
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_Create 0x021BD8C0 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_Delete 0x021BD954 thumb ov208
 *   TCB_DeleteTask 0x02030EAC arm
 *   ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId 0x021BDB08 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId 0x021BDB54 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_Update 0x021BD974 thumb
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   CLACT_RegisterPaletteEx        0x0204AC18  arm
 *   CLACT_RegisterCharacter        0x0204A6C8  arm
 *   CLACT_RegisterCellAnim        0x0204AF28  arm
 *   KEY_GetTrg 0x020362DC arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BG_SYS_SetPriority 0x0204047C arm
 *   ZUKAN_DETAIL_TOUCHBAR_LoadResources 0x021BDCF8 thumb ov208
 *   d_021C8DE4 0x021C8DE4 data a1
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BG_SYS_GetScrollY 0x02040804 arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   d_021C8388 0x021C8388 data a4
 *   d_021C8384 0x021C8384 data a1
 *   ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteLeft  0x021BE170  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_LoadBarResources  0x021BDD98  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_LoadLeftArrowResources  0x021BE3C4  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_LoadRightArrowResources  0x021BE504  thumb
 *   CLACT_GetActorPos 0x0204B53C arm
 *   CLACT_SetActorPos 0x0204B528 arm
 *   ZKND_TBAR_CreateButtonList  0x021BD148  thumb
 *   ZKND_TBAR_AddButtonPos  0x021BD3CC  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_FreeAnimBuffer  0x021BE128  thumb
 *   data_021C8440  0x021C8440  data
 *   data_021C83A4  0x021C83A4  data
 *   ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteRight 0x021BE1BC thumb
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   data_021C8390  0x021C8390  data
 *   data_021C83C8  0x021C83C8  data
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   ZUKAN_DETAIL_TOUCHBAR_GetMode  0x021BDAD0  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetMode  0x021BDAAC  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetEnabled  0x021BDAD4  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind  0x021BDBB8  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_ClearButtonState  0x021BDBA0  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible 0x021BDBEC thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled  0x021BDC48  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq  0x021BDC14  thumb
 *   ZKND_TBAR_DeleteButtonList 0x021BD208 thumb ov208
 *   ZKND_TBAR_UpdateButtons 0x021BD23C thumb ov208
 *   ZKND_TBAR_GetPressedKey 0x021BD2E0 thumb ov208
 *   ZKND_TBAR_GetHeldKey 0x021BD308 thumb ov208
 *   ZKND_TBAR_SetButtonDrawEnable 0x021BD330 thumb ov208
 *   ZKND_TBAR_SetTouchEnable 0x021BD358 thumb ov208
 *   ZKND_TBAR_GetTouchEnable 0x021BD35C thumb ov208
 *   ZKND_TBAR_ClearButtonState 0x021BD360 thumb ov208
 *   ZKND_TBAR_SetButtonAnimSeq 0x021BD368 thumb ov208
 *   ZKND_TBAR_SetButtonVisible 0x021BD378 thumb ov208
 *   ZKND_TBAR_GetButtonVisible 0x021BD388 thumb ov208
 *   ZKND_TBAR_SetButtonAnimSeqLoop 0x021BD394 thumb ov208
 *   ZKND_TBAR_SetButtonAnimSeqOnce 0x021BD3A4 thumb ov208
 *   ZKND_TBAR_IsButtonAnimActive 0x021BD3B4 thumb ov208
 *   ZKND_TBAR_GetButtonActor 0x021BD3C0 thumb ov208
 *   ZKND_TBAR_GetButtonActorRaw 0x021BD3F8 thumb ov208
 */
#include "../types.h"
#include "../arm9/gfl_use.h"
#include "../arm9/clact.h"
#include "zukan_detail_types.h"
#include "zukan_detail_shared_types.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/arc_tool.h"

#include "../arm9/bg_sys.h"
struct TcbTask;

#include "../arm9/tcb_list.h"


#include "../arm9/mi_memory.h"



struct Unit;
struct ClactActor;
struct Pt16;









#include "../arm9/key.h"





extern void ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteLeft(struct Ov208Scene *p);
struct Actor;

struct Pt16;






#include "zknd_tbar.h"





#include "../arm9/arc_util.h"



#include "../arm9/nns_gfd_vram_transfer.h"

















char *ZUKAN_DETAIL_TOUCHBAR_Create(u16 heap,unsigned arg);

void ZUKAN_DETAIL_TOUCHBAR_Delete(struct Ov208Scene *m);

void ZUKAN_DETAIL_TOUCHBAR_Update(struct Ov208Scene *m);

void ZUKAN_DETAIL_TOUCHBAR_SetMode(struct Ov208Scene *p, u32 mode, u32 kind, u32 flag);

int ZUKAN_DETAIL_TOUCHBAR_GetMode(struct Ov208Scene *p);

void ZUKAN_DETAIL_TOUCHBAR_SetEnabled(struct Ov208Scene *p, int v);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(struct Ov208Scene *p, int v);

unsigned ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId(const struct Ov208Scene *p);

unsigned ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId(const struct Ov208Scene *p);

void ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(struct Ov208Scene *p);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable(struct Ov208Scene *p, int v);

void ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(struct Ov208Scene *p, u32 kind);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(struct Ov208Scene *p, int v);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(struct Ov208Scene *p, int b);

int ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(char *p);

void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(struct Ov208Scene *p, u32 on);

int ZUKAN_DETAIL_TOUCHBAR_GetCurrentSlot(char *p);

void ZUKAN_DETAIL_TOUCHBAR_SetBgPriority(char *p, unsigned char v);

void ZUKAN_DETAIL_TOUCHBAR_FlushBar(struct TcbTask *unused, void *p);

void ZUKAN_DETAIL_TOUCHBAR_LoadResources(struct Ov208Scene *p);

void ZUKAN_DETAIL_TOUCHBAR_ReleaseResources(char *p);

void ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos(char *p,short offset);

void ZUKAN_DETAIL_TOUCHBAR_LoadBarResources(struct Ov208Scene *p);

void ZUKAN_DETAIL_TOUCHBAR_ReleaseBarResources(struct Ov208Scene *e);

void ZUKAN_DETAIL_TOUCHBAR_UpdateInput(struct Ov208Scene *m);

void ZUKAN_DETAIL_TOUCHBAR_FreeAnimBuffer(u8 *p);

void ZUKAN_DETAIL_TOUCHBAR_GetPaletteFlag(struct Ov208Scene *e);

void ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteLeft(struct Ov208Scene *p);

void ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteRight(struct Ov208Scene *p);

s32 ZUKAN_DETAIL_TOUCHBAR_LoadPaletteTable(struct Ov208Scene *m);

int ZUKAN_DETAIL_TOUCHBAR_GetPaletteForKind(int kind);

unsigned ZUKAN_DETAIL_TOUCHBAR_GetLeftPalette(unsigned n);

unsigned ZUKAN_DETAIL_TOUCHBAR_GetRightPalette(unsigned n);

void ZUKAN_DETAIL_TOUCHBAR_LoadLeftArrowResources(struct Ov208Scene *p);

void ZUKAN_DETAIL_TOUCHBAR_ReleaseLeftArrowResources(struct Ov208Scene *e);

void ZUKAN_DETAIL_TOUCHBAR_LoadRightArrowResources(struct Ov208Scene *p);

void ZUKAN_DETAIL_TOUCHBAR_ReleaseRightArrowResources(char *p);

void ZUKAN_DETAIL_TOUCHBAR_UpdateArrowInput(char *p);

extern const char d_021C8DE4[];

extern const int d_021C8388[];

extern const u8 d_021C8384[];

extern struct Ov208ActSrc data_021C8440[];

extern u16 data_021C83A4[][2];

extern s16 FX_SinCosTable_[];

extern struct Ov208ActSrc data_021C8390[];

extern struct Ov208ActSrc data_021C83C8[];

extern s16 FX_SinCosTable_[];

char *ZUKAN_DETAIL_TOUCHBAR_Create(u16 heap,unsigned dexFlags)
{
    struct Ov208Scene *p=GFL_HEAP_Alloc(heap,sizeof(struct Ov208Scene),1,d_021C8DE4,0x148);
    p->heap=heap;p->dexFlags=dexFlags;
    p->state=0;p->prevMode=0;p->mode=0;
    p->prevKind=1;p->kind=0;p->arrowKind=0;p->scrollIdx=0;
    BG_SYS_ChangeScrollImmediate(1,3,-24);BG_SYS_SetPriority(1,0);
    p->bgPriority=0;p->bgDirty=0;
    p->clactUnit=(struct Unit *)CLACT_CreateUnit(16,0,p->heap);
    CLACT_SetUnitDefaultRenderer((struct Unit *)p->clactUnit);
    p->mgr=0;ZUKAN_DETAIL_TOUCHBAR_LoadResources(p);
    ZKND_TBAR_SetTouchEnable(p->mgr,0);
    p->pos=24;ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos((char *)p,p->pos);
    p->task=(struct Node *)GFL_USE_AddMainTask(ZUKAN_DETAIL_TOUCHBAR_FlushBar, p,1);
    return (char *)p;
}

/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void ZUKAN_DETAIL_TOUCHBAR_Delete(struct Ov208Scene *m)
{
    TCB_DeleteTask((struct TcbTask *)m->task);
    ZUKAN_DETAIL_TOUCHBAR_ReleaseResources((char *)m);
    CLACT_DeleteUnit((struct Unit *)m->clactUnit);
    GFL_HEAP_Free(m);
}

void ZUKAN_DETAIL_TOUCHBAR_Update(struct Ov208Scene *m)
{
    int v;
    switch (m->state) {
    case 0:
    case 2:
        break;
    case 1:
        if (m->step == 0) {
            if ((int)BG_SYS_GetScrollY((int)1) >= 0) {
                BG_SYS_ChangeScroll(1, 3, 0);
                m->pos = 0;
                ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos((char *)m, m->pos);
                m->state = 2;
                if (m->slotsEnabled != 0)
                    ZKND_TBAR_SetTouchEnable(m->mgr, 1);
                break;
            }
            BG_SYS_ChangeScroll(1, 4, d_021C8388[m->scrollIdx]);
            m->pos = m->pos - (short)d_021C8388[m->scrollIdx];
            ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos((char *)m, m->pos);
            m->step = d_021C8384[m->scrollIdx];
        } else {
            m->step--;
        }
        break;
    case 3:
        if (m->step == 0) {
            if ((int)BG_SYS_GetScrollY((int)1) <= -24) {
                BG_SYS_ChangeScroll(1, 3, -24);
                m->pos = 24;
                ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos((char *)m, m->pos);
                m->state = 0;
            } else {
                BG_SYS_ChangeScroll(1, 5, d_021C8388[m->scrollIdx]);
                m->pos = m->pos + (short)d_021C8388[m->scrollIdx];
                ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos((char *)m, m->pos);
                m->step = d_021C8384[m->scrollIdx];
            }
        } else {
            m->step--;
        }
        break;
    }
    ZKND_TBAR_UpdateButtons(m->mgr);
    if (m->mode == 0) {
        ZUKAN_DETAIL_TOUCHBAR_UpdateInput((struct Ov208Scene *)m);
        ZUKAN_DETAIL_TOUCHBAR_LoadPaletteTable((struct Ov208Scene *)m);
    } else if (m->mode == 2) {
        ZUKAN_DETAIL_TOUCHBAR_UpdateArrowInput((char *)m);
    }
}

void ZUKAN_DETAIL_TOUCHBAR_SetMode(struct Ov208Scene *p, u32 mode, u32 kind, u32 flag)
{
    p->prevMode = p->mode;
    p->mode = mode;
    p->prevKind = p->kind;
    p->kind = kind;
    p->buttonFlag = flag;
    ZUKAN_DETAIL_TOUCHBAR_ReleaseResources((char *)p);
    p->arrowKind = p->kind;
    ZUKAN_DETAIL_TOUCHBAR_LoadResources(p);
}

int ZUKAN_DETAIL_TOUCHBAR_GetMode(struct Ov208Scene *p)
{
    return p->state;
}

void ZUKAN_DETAIL_TOUCHBAR_SetEnabled(struct Ov208Scene *p, int scrollIdx)
{
    p->scrollIdx = scrollIdx;
    if (p->state != 2) {
        p->state = 1;
        p->step = 0;
    }
}

/*
 * Stores the argument at +0x20 and, when +8 is set, restarts it at state 3.
 */
void ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(struct Ov208Scene *p, int scrollIdx)
{
    p->scrollIdx = scrollIdx;
    if (p->state != 0) {
        p->state = 3;
        p->step = 0;
        ZKND_TBAR_SetTouchEnable(p->mgr, 0);
    }
}

unsigned ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId(const struct Ov208Scene *p)
{
    int key=ZKND_TBAR_GetPressedKey(p->mgr);
    unsigned result=0;
    unsigned char i;
    unsigned count;
    struct Ov208ActSrc *entry;
    if(key!=-1) {
        switch(p->mode) {
        case 0: case 1: case 2:
            i=0;
            count=p->count;
            for(;i<count;i++) {
                entry=p->slots[i].src;
                if(key==entry->id) { result=entry->pressedId; break; }
            }
            break;
        }
    }
    return result;
}

/*
 * trailing: 021BDB9E..021BDBA0 is two-byte zero alignment padding.
 * matching: initialize the byte counter before reading the bound.
 */
unsigned ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId(const struct Ov208Scene *p)
{
    int key=ZKND_TBAR_GetHeldKey(p->mgr);
    unsigned result=0;
    unsigned char i;
    unsigned count;
    struct Ov208ActSrc *entry;
    if(key!=-1) {
        switch(p->mode) {
        case 0: case 1: case 2:
            i=0;
            count=p->count;
            for(;i<count;i++) {
                entry=p->slots[i].src;
                if(key==entry->id) { result=entry->heldId; break; }
            }
            break;
        }
    }
    return result;
}

void ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(struct Ov208Scene *p)
{
    ZKND_TBAR_ClearButtonState(p->mgr);
}

void ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable(struct Ov208Scene *p, int enable)
{
    ZKND_TBAR_SetButtonDrawEnable(p->mgr, enable);
}

void ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(struct Ov208Scene *p, u32 kind)
{
    u32 saved;
    int restore;

    if (p->mode == 0) {
        restore = 0;
        p->prevKind = p->kind;
        p->kind = kind;
        if (kind == p->arrowKind) {
            saved = p->arrowKind;
            restore = 1;
            p->arrowKind = 4;
        }
        ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteRight(p);
        ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteLeft(p);
        if (restore)
            p->arrowKind = saved;
    }
}

void ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(struct Ov208Scene *p, int visible)
{
    if (p->mode == 2) {
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[1].src->id, visible);
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[2].src->id, visible);
    }
}

/*
 * Calls ZKND_TBAR_SetButtonAnimSeqOnce with two fields and the second argument while +0x10 is clear.
 */
void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(struct Ov208Scene *p, int enabled)
{
    if (p->mode == 0)
        ZKND_TBAR_SetButtonAnimSeqOnce(p->mgr, p->slots[2].src->id, enabled);
}

int ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(char *p)
{
    if (((struct Ov208Scene *)p)->mode == 0)
        return ZKND_TBAR_IsButtonAnimActive(((struct Ov208Scene *)p)->mgr,
                             ((struct Ov208Scene *)p)->slots[2].src->id);
    return 0;
}

void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(struct Ov208Scene *p, u32 on)
{
    p->slotsEnabled = on;
    if (on != 0) {
        if (ZKND_TBAR_GetTouchEnable(p->mgr) == 0 && p->state == 2)
            ZKND_TBAR_SetTouchEnable(p->mgr, 1);
    } else {
        if (ZKND_TBAR_GetTouchEnable(p->mgr) != 0)
            ZKND_TBAR_SetTouchEnable(p->mgr, 0);
    }
}

int ZUKAN_DETAIL_TOUCHBAR_GetCurrentSlot(char *p)
{
    switch (((struct Ov208Scene *)p)->mode) {
    case 0:
        return ((struct Ov208Scene *)p)->palRes0;
    case 1:
        return ((struct Ov208Scene *)p)->palRes1;
    case 2:
        return ((struct Ov208Scene *)p)->palRes2;
    }
    return -1;
}

/*
 * Stores the mode at +0x38, arms +0x3C and hands the mode to every +0x70 handle.
 */
void ZUKAN_DETAIL_TOUCHBAR_SetBgPriority(char *p, unsigned char priority)
{
    unsigned char i;

    ((struct Ov208Scene *)p)->bgPriority = priority;
    ((struct Ov208Scene *)p)->bgDirty = 1;
    for (i = 0; i < ((struct Ov208Scene *)p)->count; i++)
        CLACT_SetActorBgPriority(((struct Ov208Scene *)p)->slots[i].obj, priority);
}

/*
 * BLOCKED.  MATCH: the call at +0x10 targets 0204047C, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */
void ZUKAN_DETAIL_TOUCHBAR_FlushBar(struct TcbTask *unused, void *p)
{
    if (((struct Ov208Scene *)p)->bgDirty != 0) {
        BG_SYS_SetPriority(1, ((struct Ov208Scene *)p)->bgPriority);
        ((struct Ov208Scene *)p)->bgDirty = 0;
    }
}

void ZUKAN_DETAIL_TOUCHBAR_LoadResources(struct Ov208Scene *p)
{
    switch (p->mode) {
    case 0:
        ZUKAN_DETAIL_TOUCHBAR_LoadBarResources(p);
        break;
    case 1:
        ZUKAN_DETAIL_TOUCHBAR_LoadLeftArrowResources(p);
        break;
    case 2:
        ZUKAN_DETAIL_TOUCHBAR_LoadRightArrowResources(p);
        break;
    }
    p->slotsEnabled = 1;
}

void ZUKAN_DETAIL_TOUCHBAR_ReleaseResources(char *p)
{
    switch (((struct Ov208Scene *)p)->prevMode) {
    case 0:
        ZUKAN_DETAIL_TOUCHBAR_ReleaseBarResources((struct Ov208Scene *)p);
        break;
    case 1:
        ZUKAN_DETAIL_TOUCHBAR_ReleaseLeftArrowResources((struct Ov208Scene *)p);
        break;
    case 2:
        ZUKAN_DETAIL_TOUCHBAR_ReleaseRightArrowResources(p);
        break;
    }
}

void ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos(char *p,short offset)
{
    unsigned char i;
    struct ZukanDetailPt pt;
    for(i=0;i<((struct Ov208Scene *)p)->count;i++) {
        CLACT_GetActorPos(((struct Ov208Scene *)p)->slots[i].obj,(struct Pt16 *)(&pt));
        pt.y=*(short *)((char *)((struct Ov208Scene *)p)->slots[i].src + 6);
        pt.y=(short)pt.y+offset;
        CLACT_SetActorPos(((struct Ov208Scene *)p)->slots[i].obj,(const struct Pt16 *)((struct Pt16 *)(&pt)));
    }
}

void ZUKAN_DETAIL_TOUCHBAR_LoadBarResources(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[9];
    void *h;
    u8 i;
    int v;

    h = ARC_TOOL_CreateHandle(0x9f, p->heap);
    p->palRes0 = CLACT_RegisterPaletteEx(h, 3, 0, 0x160, 0, 3, p->heap);
    p->charRes0 = CLACT_RegisterCharacter(h, 0xd, 0, 0, p->heap);
    p->cellRes0 = CLACT_RegisterCellAnim(h, 0x1b, 0x2c, p->heap);
    ARC_TOOL_DeleteHandle(h);
    p->count = 9;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C8440[i];
    for (i = 0; i < p->count; i++) {
        descs[i].key = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].hitWidth = p->slots[i].src->hitWidth;
    }
    descs[3].charRes = p->charRes0;
    descs[3].palRes = p->palRes0;
    descs[3].cellRes = p->cellRes0;
    descs[3].idleAnim = 3;
    descs[3].disabledAnim = 3;
    descs[3].pressedAnim = 7;
    descs[3].keyMask = 0;
    descs[3].seId = 0x54a;
    descs[4].charRes = p->charRes0;
    descs[4].palRes = p->palRes0;
    descs[4].cellRes = p->cellRes0;
    descs[4].idleAnim = 2;
    descs[4].disabledAnim = 2;
    descs[4].pressedAnim = 6;
    descs[4].keyMask = 0;
    descs[4].seId = 0x54a;
    descs[5].charRes = p->charRes0;
    descs[5].palRes = p->palRes0;
    descs[5].cellRes = p->cellRes0;
    descs[5].idleAnim = 1;
    descs[5].disabledAnim = 1;
    descs[5].pressedAnim = 5;
    descs[5].keyMask = 0;
    descs[5].seId = 0x54a;
    descs[6].charRes = p->charRes0;
    descs[6].palRes = p->palRes0;
    descs[6].cellRes = p->cellRes0;
    descs[6].idleAnim = 0;
    descs[6].disabledAnim = 0;
    descs[6].pressedAnim = 4;
    descs[6].keyMask = 0;
    descs[6].seId = 0x54a;
    MI_CpuFill8(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 9;
    list.owner = p->clactUnit;
    list.channel = 1;
    list.pal = 0xd;
    list.objPal = 8;
    list.kind = 2;
    p->mgr = ZKND_TBAR_CreateButtonList(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = ZKND_TBAR_GetButtonActor(p->mgr, p->slots[i].src->id);
    if (p->dexFlags == 0) {
        for (i = 0; i < 9; i++)
            ZKND_TBAR_AddButtonPos(p->mgr, p->slots[i].src->id, data_021C83A4[i]);
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[3].src->id, 0);
    }
    v = ZUKAN_DETAIL_TOUCHBAR_GetPaletteForKind(p->kind);
    if (v != 9)
        ZKND_TBAR_SetButtonAnimSeq(p->mgr, p->slots[v].src->id, 0);
    ZUKAN_DETAIL_TOUCHBAR_FreeAnimBuffer((u8 *)(p));
    ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteLeft((struct Ov208Scene *)p);
    if (p->buttonFlag == 0) {
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[8].src->id, 0);
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[7].src->id, 0);
    }
}

void ZUKAN_DETAIL_TOUCHBAR_ReleaseBarResources(struct Ov208Scene *e)
{
    if (e->mgr != 0) {
        ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteRight(e);
        ZUKAN_DETAIL_TOUCHBAR_GetPaletteFlag(e);
        ZKND_TBAR_DeleteButtonList(e->mgr);
        CLACT_ReleasePalette((u32)e->palRes0);
        CLACT_ReleaseCharacter((u32)e->charRes0);
        CLACT_ReleaseCellAnim((u32)e->cellRes0);
    }
    e->mgr = 0;
}

void ZUKAN_DETAIL_TOUCHBAR_UpdateInput(struct Ov208Scene *m)
{
    u32 sel = 9;
    u32 trg = KEY_GetTrg();
    u32 held = KEY_GetRepeat();
    u32 a;
    u32 b;
    u32 c;
    volatile u32 d; /* volatile on purpose: image spills it to the stack and re-reads it */
    u8 i;
    if (held & 0x20) {
        switch (m->kind) {
        case 0:
            if (ZKND_TBAR_GetButtonVisible(m->mgr, m->slots[3].src->id))
                sel = 3;
            else
                sel = 4;
            break;
        case 1:
            sel = 6;
            break;
        case 2:
            sel = 5;
            break;
        case 3:
            sel = 4;
            break;
        }
    } else if (held & 0x10) {
        switch (m->kind) {
        case 0:
            sel = 5;
            break;
        case 1:
            sel = 4;
            break;
        case 2:
            if (ZKND_TBAR_GetButtonVisible(m->mgr, m->slots[3].src->id))
                sel = 3;
            else
                sel = 6;
            break;
        case 3:
            sel = 6;
            break;
        }
    }
    if (sel != 9)
        ZKND_TBAR_GetButtonActorRaw(m->mgr, m->slots[sel].src->id);
    if ((trg & 0xc0) == 0) {
        if (held & 0x40)
            ZKND_TBAR_GetButtonActorRaw(m->mgr, m->slots[8].src->id);
        else if (held & 0x80)
            ZKND_TBAR_GetButtonActorRaw(m->mgr, m->slots[7].src->id);
    }
    a = ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId((const struct Ov208Scene *)m);
    b = ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId((const struct Ov208Scene *)m);
    if (a != 0) {
        c = ZUKAN_DETAIL_TOUCHBAR_GetLeftPalette(a);
        d = ZUKAN_DETAIL_TOUCHBAR_GetRightPalette(a);
        if (c != 9 && d != 4) {
            for (i = 3; i <= 6; i++)
                ZKND_TBAR_SetButtonAnimSeq(m->mgr, m->slots[i].src->id, i != c);
            m->arrowKind = d;
            ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteLeft((struct Ov208Scene *)((struct Ov208Scene *)m));
        }
    }
    if (b != 0) {
        switch (b) {
        case 15:
        case 16:
        case 17:
        case 18:
            ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteRight((struct Ov208Scene *)m);
            break;
        }
    }
}

void ZUKAN_DETAIL_TOUCHBAR_FreeAnimBuffer(u8 *p)
{
    struct Ov208Pltt *pltt;
    uptr file;
    u8 *data;

    file = (uptr)ARC_UTIL_LoadPaletteBlockFromArchive(0x9f, 3, (&pltt), ((struct Ov208Scene *)p)->heap);
    data = pltt->data;
    MI_CpuCopy8(data + 0x20, ((struct Ov208Scene *)p)->palA, 0x20);
    MI_CpuCopy8(data + 0x60, ((struct Ov208Scene *)p)->palB, 0x20);
    GFL_HEAP_Free((void *)file);
    ((struct Ov208Scene *)p)->phase = 0;
}

/*
 * Empty stub; the listing pads it with two zero bytes.
 */
void ZUKAN_DETAIL_TOUCHBAR_GetPaletteFlag(struct Ov208Scene *e)
{
}

void ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteLeft(struct Ov208Scene *p)
{
    u32 idx = 9;

    switch (p->arrowKind) {
    case 0:
        idx = 6;
        break;
    case 1:
        idx = 5;
        break;
    case 2:
        idx = 4;
        break;
    case 3:
        idx = 3;
        break;
    }
    if (idx != 9)
        CLACT_SetActorPaletteOffset(ZKND_TBAR_GetButtonActor(p->mgr, p->slots[idx].src->id), 2, 0);
}

void ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteRight(struct Ov208Scene *p)
{
    int slot = 9;

    switch (p->arrowKind) {
    case 0:
        slot = 6;
        break;
    case 1:
        slot = 5;
        break;
    case 2:
        slot = 4;
        break;
    case 3:
        slot = 3;
        break;
    }
    if (slot != 9) {
        CLACT_SetActorPaletteOffset(ZKND_TBAR_GetButtonActor(p->mgr, p->slots[slot].src->id), 0, 0);
        p->arrowKind = 4;
    }
}

s32 ZUKAN_DETAIL_TOUCHBAR_LoadPaletteTable(struct Ov208Scene *m)
{
    s16 t;
    u8 i;
    if (m->phase + 0x400 >= 0x10000)
        m->phase -= 0xfc00;
    else
        m->phase += 0x400;
    t = (FX_SinCosTable_[2 * (m->phase >> 4) + 1] + 0x1000) / 2;
    for (i = 0; i < 16; i++) {
        u16 c1 = m->palA[i];
        u16 c2 = m->palB[i];
        u8 r1 = c1 & 0x1f;
        u8 g1 = (c1 & 0x3e0) >> 5;
        u8 b1 = (c1 & 0x7c00) >> 10;
        u8 r2 = c2 & 0x1f;
        u8 g2 = (c2 & 0x3e0) >> 5;
        u8 b2 = (c2 & 0x7c00) >> 10;
        u8 r = r1 + ((r2 - r1) * t >> 12);
        u8 g = g1 + ((g2 - g1) * t >> 12);
        u8 b = b1 + ((b2 - b1) * t >> 12);
        m->palOut[i] = r | g << 5 | b << 10;
    }
    return NNS_GfdRegisterNewVramTransferTask(14, 0x1a0, m->palOut, 0x20);
}

/*
 * Returns 6, 5, 4 or 3 for the four known kinds and 9 for anything else.
 */
int ZUKAN_DETAIL_TOUCHBAR_GetPaletteForKind(int kind)
{
    switch (kind) {
    case 0:
        return 6;
    case 1:
        return 5;
    case 2:
        return 4;
    case 3:
        return 3;
    }
    return 9;
}

/*
 * trailing: 021BE376..021BE378 is two-byte zero alignment padding.
 */
unsigned ZUKAN_DETAIL_TOUCHBAR_GetLeftPalette(unsigned n)
{
    switch(n) {
    case 0: break;
    case 6: case 15: return 6;
    case 7: case 16: return 5;
    case 8: case 17: return 4;
    case 9: case 18: return 3;
    default: break;
    }
    return 9;
}

/*
 * trailing: 021BE3C2..021BE3C4 is two-byte zero alignment padding.
 */
unsigned ZUKAN_DETAIL_TOUCHBAR_GetRightPalette(unsigned n)
{
    switch(n) {
    case 0: break;
    case 6: case 15: return 0;
    case 7: case 16: return 1;
    case 8: case 17: return 2;
    case 9: case 18: return 3;
    default: break;
    }
    return 4;
}

void ZUKAN_DETAIL_TOUCHBAR_LoadLeftArrowResources(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[1];
    void *h;
    u8 i;

    h = ARC_TOOL_CreateHandle(0x55, p->heap);
    p->palRes1 = CLACT_RegisterPaletteEx(h, 2, 0, 0x160, 2, 3, p->heap);
    p->charRes1 = CLACT_RegisterCharacter(h, 8, 0, 0, p->heap);
    p->cellRes1 = CLACT_RegisterCellAnim(h, 0xc, 0x13, p->heap);
    ARC_TOOL_DeleteHandle(h);
    p->count = 1;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C8390[i];
    for (i = 0; i < p->count; i++) {
        descs[i].key = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].hitWidth = p->slots[i].src->hitWidth;
    }
    MI_CpuFill8(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 1;
    list.owner = p->clactUnit;
    list.channel = 1;
    list.pal = 0xd;
    list.objPal = 8;
    list.kind = 2;
    p->mgr = ZKND_TBAR_CreateButtonList(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = ZKND_TBAR_GetButtonActor(p->mgr, p->slots[i].src->id);
}

void ZUKAN_DETAIL_TOUCHBAR_ReleaseLeftArrowResources(struct Ov208Scene *e)
{
    if (e->mgr != 0) {
        ZKND_TBAR_DeleteButtonList(e->mgr);
        CLACT_ReleasePalette((u32)e->palRes1);
        CLACT_ReleaseCharacter((u32)e->charRes1);
        CLACT_ReleaseCellAnim((u32)e->cellRes1);
    }
    e->mgr = 0;
}

void ZUKAN_DETAIL_TOUCHBAR_LoadRightArrowResources(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[6];
    struct Ov208ActDesc *d;
    void *h;
    u8 i;

    h = ARC_TOOL_CreateHandle(0x9f, p->heap);
    p->palRes2 = CLACT_RegisterPaletteEx(h, 3, 0, 0x160, 0, 3, p->heap);
    p->charRes2 = CLACT_RegisterCharacter(h, 0xd, 0, 0, p->heap);
    p->cellRes2 = CLACT_RegisterCellAnim(h, 0x1b, 0x2c, p->heap);
    ARC_TOOL_DeleteHandle(h);
    p->count = 6;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C83C8[i];
    for (i = 0; i < p->count; i++) {
        descs[i].key = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].hitWidth = p->slots[i].src->hitWidth;
    }
    d = &descs[3];
    d->charRes = p->charRes2;
    d->palRes = p->palRes2;
    d->cellRes = p->cellRes2;
    d->idleAnim = 0xe;
    d->disabledAnim = 0xe;
    d->pressedAnim = 0x14;
    d->keyMask = 1;
    d->seId = 0x54c;
    MI_CpuFill8(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 6;
    list.owner = p->clactUnit;
    list.channel = 1;
    list.pal = 0xd;
    list.objPal = 8;
    list.kind = 2;
    p->mgr = ZKND_TBAR_CreateButtonList(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = ZKND_TBAR_GetButtonActor(p->mgr, p->slots[i].src->id);
    ZKND_TBAR_SetButtonAnimSeqLoop(p->mgr, p->slots[1].src->id, 0x110);
    ZKND_TBAR_SetButtonAnimSeqLoop(p->mgr, p->slots[2].src->id, 0x220);
    if (p->buttonFlag == 0) {
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[5].src->id, 0);
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[4].src->id, 0);
    }
}

void ZUKAN_DETAIL_TOUCHBAR_ReleaseRightArrowResources(char *p)
{
    if (((struct Ov208Scene *)p)->mgr != 0) {
        ZKND_TBAR_DeleteButtonList(((struct Ov208Scene *)p)->mgr);
        CLACT_ReleasePalette(((struct Ov208Scene *)p)->palRes2);
        CLACT_ReleaseCharacter(((struct Ov208Scene *)p)->charRes2);
        CLACT_ReleaseCellAnim(((struct Ov208Scene *)p)->cellRes2);
    }
    ((struct Ov208Scene *)p)->mgr = 0;
}

void ZUKAN_DETAIL_TOUCHBAR_UpdateArrowInput(char *p)
{
    unsigned held=KEY_GetTrg();
    unsigned keys=KEY_GetRepeat();
    if(!(held&0x3f0)) {
        if(keys&0x40) ZKND_TBAR_GetButtonActorRaw(((struct Ov208Scene *)p)->mgr,((struct Ov208Scene *)p)->slots[5].src->id);
        else if(keys&0x80) ZKND_TBAR_GetButtonActorRaw(((struct Ov208Scene *)p)->mgr,((struct Ov208Scene *)p)->slots[4].src->id);
        else if(keys&0x220) ZKND_TBAR_GetButtonActorRaw(((struct Ov208Scene *)p)->mgr,((struct Ov208Scene *)p)->slots[2].src->id);
        else if(keys&0x110) ZKND_TBAR_GetButtonActorRaw(((struct Ov208Scene *)p)->mgr,((struct Ov208Scene *)p)->slots[1].src->id);
    }
}
