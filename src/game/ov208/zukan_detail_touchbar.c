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
 * Cut from zukan_detail_common.c, zukan_detail_graphic.c, zukan_detail_form.c, ov208_func_021C80CC.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020056A0 0x020056A0 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_Create 0x021BD8C0 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_Delete 0x021BD954 thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId 0x021BDB08 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId 0x021BDB54 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_Update 0x021BD974 thumb
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   CLACT_RegisterPaletteEx        0x0204AC18  arm
 *   CLACT_RegisterCharacter        0x0204A6C8  arm
 *   CLACT_RegisterCellAnim        0x0204AF28  arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_02040618 0x02040618 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   func_021BDCF8 0x021BDCF8 thumb ov208
 *   d_021C8DE4 0x021C8DE4 data a1
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   func_02040804 0x02040804 arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   d_021C8388 0x021C8388 data a4
 *   d_021C8384 0x021C8384 data a1
 *   func_021BE170  0x021BE170  thumb
 *   func_021BDD98  0x021BDD98  thumb
 *   func_021BE3C4  0x021BE3C4  thumb
 *   func_021BE504  0x021BE504  thumb
 *   CLACT_GetActorPos 0x0204B53C arm
 *   CLACT_SetActorPos 0x0204B528 arm
 *   func_021BD148  0x021BD148  thumb
 *   func_021BD3CC  0x021BD3CC  thumb
 *   func_021BE128  0x021BE128  thumb
 *   data_021C8440  0x021C8440  data
 *   data_021C83A4  0x021C83A4  data
 *   func_021BE1BC 0x021BE1BC thumb
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   func_02049F34  0x02049F34  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   func_02061CA4 0x02061CA4 arm
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
#include "zukan_detail_types.h"
#include "../../matched/include/Obj01080.h"
#include "../../matched/include/Obj02345.h"
#include "../../matched/include/Obj10895.h"
#include "../../matched/include/Obj14649.h"
#include "../../matched/include/Obj10896.h"
#include "../../matched/include/Obj14650.h"
#include "../../matched/include/Obj09200.h"
#include "../../matched/include/Obj07227.h"
#include "../../matched/include/Obj09201.h"
#include "../../matched/include/Obj01081.h"
#include "../../matched/include/Obj25442.h"
#include "../../matched/include/Obj14652.h"
#include "../../matched/include/Obj03931.h"
#include "zukan_detail_shared_types.h"

extern u32 func_020307B0(void *p);

extern void ARC_TOOL_DeleteHandle(void *h);

extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);

extern void func_02030EAC(struct Node *n);

struct Ov208SelectScene;

struct Ov208SelectScene { char pad[0x68]; unsigned char count; };

extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned short);

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void *func_020056A0(unsigned,unsigned,unsigned);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void *func_020490F4(unsigned int id, unsigned int heap);

extern u32  CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern u32  CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern u32 KEY_GetTrg(void);

extern void func_02040618(unsigned,unsigned,unsigned);

extern void BG_SYS_SetVisibleLayer(int,u16);

extern void func_021BDCF8(struct Ov208Scene *);

extern u32 func_02040804(u32 layer);

extern void func_021BE170(struct Ov208Scene *p);

extern void CLACT_SetActorBgPriority(int, int);

extern void func_021BDD98(struct Ov208Scene *p);

extern void func_021BE3C4(struct Ov208Scene *p);

extern void func_021BE504(struct Ov208Scene *p);

extern void CLACT_GetActorPos(const struct Actor *,struct Pt *);

extern void CLACT_SetActorPos(struct Actor *,const struct Pt *);

extern struct Ov208Mgr *func_021BD148(struct Ov208ActList *list, u16 heap);

extern void func_021BD3CC(struct Ov208Mgr *mgr, int key, u16 *pos);

extern void func_021BE128(struct Ov208Scene *p);

extern void func_021BE1BC(struct Ov208Scene *e);

extern u32 KEY_GetRepeat(void);

extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);

extern void MI_CpuCopy8(void *src, void *dst, u32 size);

extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

extern s32_021BD574 func_02061CA4(void *p, u32 a, u32 b, s32_021BD574 size);

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

void ZKND_TBAR_GetButtonActorRaw(struct Ov208Mgr *mgr, int key);

char *ZUKAN_DETAIL_TOUCHBAR_Create(u16 heap,unsigned arg);

void ZUKAN_DETAIL_TOUCHBAR_Delete(struct Ov208Scene *m);

void ZUKAN_DETAIL_TOUCHBAR_Update(struct Ov208Scene *m);

void ZUKAN_DETAIL_TOUCHBAR_SetMode(struct Ov208Scene *p, u32 mode, u32 kind, u32 flag);

int ZUKAN_DETAIL_TOUCHBAR_GetMode(struct Ov208Scene *p);

void ZUKAN_DETAIL_TOUCHBAR_SetEnabled(struct Ov208Scene *p, int v);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(struct Ov208Scene *p, int v);

unsigned ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId(const struct Ov208SelectScene *p);

unsigned ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId(const struct Ov208SelectScene *p);

void ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(struct Ov208Scene *p);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable(struct Ov208Scene *p, int v);

void ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(struct Ov208Scene *p, u32 kind);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(struct Ov208Scene *p, int v);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(struct Ov208Scene *p, int b);

int ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(char *p);

void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(struct Ov208Scene *p, u32 on);

int ZUKAN_DETAIL_TOUCHBAR_GetCurrentSlot(char *p);

void ZUKAN_DETAIL_TOUCHBAR_SetBgPriority(char *p, unsigned char v);

void ZUKAN_DETAIL_TOUCHBAR_FlushBar(int unused, char *p);

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

s32_021BD574 ZUKAN_DETAIL_TOUCHBAR_LoadPaletteTable(struct Ov208Scene *m);

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

extern s16_021BE20C FX_SinCosTable_[];

extern struct Ov208ActSrc data_021C8390[];

extern struct Ov208ActSrc data_021C83C8[];

extern s16_021C23BC FX_SinCosTable_[];

char *ZUKAN_DETAIL_TOUCHBAR_Create(u16 heap,unsigned arg)
{
    char *p=func_02030734(heap,0x11c,1,d_021C8DE4,0x148);
    ((struct Obj01080 *)p)->f0=heap;((struct Obj01080 *)p)->f4=arg;
    ((struct Obj01080 *)p)->f8=0;((struct Obj01080 *)p)->fC=0;((struct Obj01080 *)p)->f10=0;
    ((struct Obj01080 *)p)->f14=1;((struct Obj01080 *)p)->f18=0;((struct Obj01080 *)p)->f1C=0;((struct Obj01080 *)p)->f20=0;
    func_02040618(1,3,-24);BG_SYS_SetVisibleLayer(1,0);
    p[0x38]=0;((struct Obj01080 *)p)->f3C=0;
    *(struct Bank * *)&((struct Obj01080 *)p)->f28=CLACT_CreateUnit(16,0,((struct Obj01080 *)p)->f0);
    CLACT_SetUnitDefaultRenderer(*(struct Bank * *)&((struct Obj01080 *)p)->f28);
    *(unsigned *)&((struct Obj01080 *)p)->f30=0;func_021BDCF8((struct Ov208Scene *)p);
    ZKND_TBAR_SetTouchEnable(((struct Obj01080 *)p)->f30,0);
    ((struct Obj01080 *)p)->fB4=24;ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos(p,((struct Obj01080 *)p)->fB4);
    ((struct Obj01080 *)p)->f2C=func_020056A0((unsigned)ZUKAN_DETAIL_TOUCHBAR_FlushBar,(unsigned)p,1);
    return p;
}

/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void ZUKAN_DETAIL_TOUCHBAR_Delete(struct Ov208Scene *m)
{
    func_02030EAC((struct Node *)m->f2c);
    ZUKAN_DETAIL_TOUCHBAR_ReleaseResources((char *)m);
    CLACT_DeleteUnit((struct Bank *)m->f28);
    func_020307B0(m);
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
            if ((int)func_02040804((int)1) >= 0) {
                BG_SYS_ResetSlot(1, 3, 0);
                m->pos = 0;
                ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos((char *)m, m->pos);
                m->state = 2;
                if (m->f34 != 0)
                    ZKND_TBAR_SetTouchEnable(m->mgr, 1);
                break;
            }
            BG_SYS_ResetSlot(1, 4, d_021C8388[m->idx]);
            m->pos = m->pos - (short)d_021C8388[m->idx];
            ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos((char *)m, m->pos);
            m->step = d_021C8384[m->idx];
        } else {
            m->step--;
        }
        break;
    case 3:
        if (m->step == 0) {
            if ((int)func_02040804((int)1) <= -24) {
                BG_SYS_ResetSlot(1, 3, -24);
                m->pos = 24;
                ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos((char *)m, m->pos);
                m->state = 0;
            } else {
                BG_SYS_ResetSlot(1, 5, d_021C8388[m->idx]);
                m->pos = m->pos + (short)d_021C8388[m->idx];
                ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos((char *)m, m->pos);
                m->step = d_021C8384[m->idx];
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
    p->fc = p->mode;
    p->mode = mode;
    p->f14 = p->f18;
    p->f18 = kind;
    p->f40 = flag;
    ZUKAN_DETAIL_TOUCHBAR_ReleaseResources((char *)p);
    p->f1c = p->f18;
    func_021BDCF8(p);
}

int ZUKAN_DETAIL_TOUCHBAR_GetMode(struct Ov208Scene *p)
{
    return p->state;
}

void ZUKAN_DETAIL_TOUCHBAR_SetEnabled(struct Ov208Scene *p, int v)
{
    p->idx = v;
    if (p->state != 2) {
        p->state = 1;
        p->step = 0;
    }
}

/*
 * Stores the argument at +0x20 and, when +8 is set, restarts it at state 3.
 */
void ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(struct Ov208Scene *p, int v)
{
    p->idx = v;
    if (p->state != 0) {
        p->state = 3;
        p->step = 0;
        ZKND_TBAR_SetTouchEnable(p->mgr, 0);
    }
}

unsigned ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId(const struct Ov208SelectScene *p)
{
    int key=ZKND_TBAR_GetPressedKey(*(struct Ov208Mgr * *)&((struct Obj10895 *)p)->f30);
    unsigned result=0;
    unsigned char i;
    unsigned count;
    char *entry;
    if(key!=-1) {
        switch(((struct Obj10895 *)p)->f10) {
        case 0: case 1: case 2:
            i=0;
            count=p->count;
            for(;i<count;i++) {
                entry=*(char **)((char *)p+i*8+0x6c);
                if(key==((struct Obj14649 *)entry)->f0) { result=((struct Obj14649 *)entry)->fC; break; }
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
unsigned ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId(const struct Ov208SelectScene *p)
{
    int key=ZKND_TBAR_GetHeldKey((struct Ov208Mgr *)(*(char * *)&((struct Obj10896 *)p)->f30));
    unsigned result=0;
    unsigned char i;
    unsigned count;
    char *entry;
    if(key!=-1) {
        switch(((struct Obj10896 *)p)->f10) {
        case 0: case 1: case 2:
            i=0;
            count=p->count;
            for(;i<count;i++) {
                entry=*(char **)((char *)p+i*8+0x6c);
                if(key==((struct Obj14650 *)entry)->f0) { result=((struct Obj14650 *)entry)->f10; break; }
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

void ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable(struct Ov208Scene *p, int v)
{
    ZKND_TBAR_SetButtonDrawEnable(p->mgr, v);
}

void ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(struct Ov208Scene *p, u32 kind)
{
    u32 saved;
    int restore;

    if (p->mode == 0) {
        restore = 0;
        p->f14 = p->f18;
        p->f18 = kind;
        if (kind == p->f1c) {
            saved = p->f1c;
            restore = 1;
            p->f1c = 4;
        }
        ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteRight(p);
        func_021BE170(p);
        if (restore)
            p->f1c = saved;
    }
}

void ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(struct Ov208Scene *p, int v)
{
    if (p->mode == 2) {
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[1].src->id, v);
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[2].src->id, v);
    }
}

/*
 * Calls ZKND_TBAR_SetButtonAnimSeqOnce with two fields and the second argument while +0x10 is clear.
 */
void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(struct Ov208Scene *p, int b)
{
    if (p->mode == 0)
        ZKND_TBAR_SetButtonAnimSeqOnce(p->mgr, p->slots[2].src->id, b);
}

int ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(char *p)
{
    if (((struct Obj09200 *)p)->f10 == 0)
        return ZKND_TBAR_IsButtonAnimActive((void *)(((struct Obj09200 *)p)->f30),
                             *(int *)*(int * *)&((struct Obj09200 *)p)->f7C);
    return 0;
}

void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(struct Ov208Scene *p, u32 on)
{
    p->f34 = on;
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
    switch (((struct Obj07227 *)p)->f10) {
    case 0:
        return ((struct Obj07227 *)p)->f44;
    case 1:
        return ((struct Obj07227 *)p)->f50;
    case 2:
        return ((struct Obj07227 *)p)->f5C;
    }
    return -1;
}

/*
 * Stores the mode at +0x38, arms +0x3C and hands the mode to every +0x70 handle.
 */
void ZUKAN_DETAIL_TOUCHBAR_SetBgPriority(char *p, unsigned char v)
{
    unsigned char i;

    ((struct Obj02345 *)p)->f38 = v;
    ((struct Obj02345 *)p)->f3C = 1;
    for (i = 0; i < ((struct Obj02345 *)p)->f68; i++)
        CLACT_SetActorBgPriority(*(int *)(p + i * 8 + 0x70), v);
}

/*
 * BLOCKED.  MATCH: the call at +0x10 targets 0204047C, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */
void ZUKAN_DETAIL_TOUCHBAR_FlushBar(int unused, char *p)
{
    if (((struct Obj09201 *)p)->f3C != 0) {
        BG_SYS_SetVisibleLayer(1, ((struct Obj09201 *)p)->f38);
        ((struct Obj09201 *)p)->f3C = 0;
    }
}

void ZUKAN_DETAIL_TOUCHBAR_LoadResources(struct Ov208Scene *p)
{
    switch (p->mode) {
    case 0:
        func_021BDD98(p);
        break;
    case 1:
        func_021BE3C4(p);
        break;
    case 2:
        func_021BE504(p);
        break;
    }
    p->f34 = 1;
}

void ZUKAN_DETAIL_TOUCHBAR_ReleaseResources(char *p)
{
    switch (((struct Obj01081 *)p)->fC) {
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
    struct Pt pt;
    for(i=0;i<((struct Obj25442 *)p)->f68;i++) {
        CLACT_GetActorPos(*(struct Actor **)(p+i*8+0x70),&pt);
        pt.y=*(short *)(*(char **)(p+i*8+0x6c)+6);
        pt.y=(short)pt.y+offset;
        CLACT_SetActorPos(*(struct Actor **)(p+i*8+0x70),&pt);
    }
}

void ZUKAN_DETAIL_TOUCHBAR_LoadBarResources(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[9];
    void *h;
    u8 i;
    int v;

    h = func_020490F4(0x9f, p->heap);
    p->f44 = CLACT_RegisterPaletteEx(h, 3, 0, 0x160, 0, 3, p->heap);
    p->f48 = CLACT_RegisterCharacter(h, 0xd, 0, 0, p->heap);
    p->f4c = CLACT_RegisterCellAnim(h, 0x1b, 0x2c, p->heap);
    ARC_TOOL_DeleteHandle(h);
    p->count = 9;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C8440[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    descs[3].ha = p->f48;
    descs[3].hc = p->f44;
    descs[3].he = p->f4c;
    descs[3].h10 = 3;
    descs[3].h12 = 3;
    descs[3].h14 = 7;
    descs[3].f18 = 0;
    descs[3].f1c = 0x54a;
    descs[4].ha = p->f48;
    descs[4].hc = p->f44;
    descs[4].he = p->f4c;
    descs[4].h10 = 2;
    descs[4].h12 = 2;
    descs[4].h14 = 6;
    descs[4].f18 = 0;
    descs[4].f1c = 0x54a;
    descs[5].ha = p->f48;
    descs[5].hc = p->f44;
    descs[5].he = p->f4c;
    descs[5].h10 = 1;
    descs[5].h12 = 1;
    descs[5].h14 = 5;
    descs[5].f18 = 0;
    descs[5].f1c = 0x54a;
    descs[6].ha = p->f48;
    descs[6].hc = p->f44;
    descs[6].he = p->f4c;
    descs[6].h10 = 0;
    descs[6].h12 = 0;
    descs[6].h14 = 4;
    descs[6].f18 = 0;
    descs[6].f1c = 0x54a;
    MI_CpuFill8(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 9;
    list.owner = p->f28;
    list.channel = 1;
    list.pal = 0xd;
    list.objPal = 8;
    list.kind = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = ZKND_TBAR_GetButtonActor((void *)p->mgr, p->slots[i].src->id);
    if (p->f4 == 0) {
        for (i = 0; i < 9; i++)
            func_021BD3CC(p->mgr, p->slots[i].src->id, data_021C83A4[i]);
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[3].src->id, 0);
    }
    v = ZUKAN_DETAIL_TOUCHBAR_GetPaletteForKind(p->f18);
    if (v != 9)
        ZKND_TBAR_SetButtonAnimSeq(p->mgr, p->slots[v].src->id, 0);
    func_021BE128(p);
    func_021BE170((struct Ov208Scene *)p);
    if (p->f40 == 0) {
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[8].src->id, 0);
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[7].src->id, 0);
    }
}

void ZUKAN_DETAIL_TOUCHBAR_ReleaseBarResources(struct Ov208Scene *e)
{
    if (e->mgr != 0) {
        func_021BE1BC(e);
        ZUKAN_DETAIL_TOUCHBAR_GetPaletteFlag(e);
        ZKND_TBAR_DeleteButtonList(e->mgr);
        CLACT_ReleasePalette((u32)e->f44);
        CLACT_ReleaseCharacter((u32)e->f48);
        CLACT_ReleaseCellAnim((u32)e->f4c);
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
        switch (m->f18) {
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
        switch (m->f18) {
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
    a = ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId((const struct Ov208SelectScene *)m);
    b = ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId((const struct Ov208SelectScene *)m);
    if (a != 0) {
        c = ZUKAN_DETAIL_TOUCHBAR_GetLeftPalette(a);
        d = ZUKAN_DETAIL_TOUCHBAR_GetRightPalette(a);
        if (c != 9 && d != 4) {
            for (i = 3; i <= 6; i++)
                ZKND_TBAR_SetButtonAnimSeq(m->mgr, m->slots[i].src->id, i != c);
            m->f1c = d;
            func_021BE170((struct Ov208Scene *)((struct Ov208Scene *)m));
        }
    }
    if (b != 0) {
        switch (b) {
        case 15:
        case 16:
        case 17:
        case 18:
            func_021BE1BC((struct Ov208Scene *)m);
            break;
        }
    }
}

void ZUKAN_DETAIL_TOUCHBAR_FreeAnimBuffer(u8 *p)
{
    struct Ov208Pltt *pltt;
    u32 file;
    u8 *data;

    file = (u32)func_02049F34(0x9f, 3, (u32)(&pltt), ((struct Obj14652 *)p)->f0);
    data = pltt->data;
    MI_CpuCopy8(data + 0x20, p + 0xb6, 0x20);
    MI_CpuCopy8(data + 0x60, p + 0xd6, 0x20);
    func_020307B0((void *)file);
    ((struct Obj14652 *)p)->f118 = 0;
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

    switch (p->f1c) {
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
        CLACT_SetActorPaletteOffset((struct Obj *)ZKND_TBAR_GetButtonActor(p->mgr, p->slots[idx].src->id), 2, 0);
}

void ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteRight(struct Ov208Scene *p)
{
    int slot = 9;

    switch (p->f1c) {
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
        CLACT_SetActorPaletteOffset((struct Obj *)ZKND_TBAR_GetButtonActor(p->mgr, p->slots[slot].src->id), 0, 0);
        p->f1c = 4;
    }
}

s32_021BD574 ZUKAN_DETAIL_TOUCHBAR_LoadPaletteTable(struct Ov208Scene *m)
{
    s16_021BE20C t;
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
    return func_02061CA4((void *)14, 0x1a0, (u32)m->palOut, 0x20);
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

    h = func_020490F4(0x55, p->heap);
    p->f50 = CLACT_RegisterPaletteEx(h, 2, 0, 0x160, 2, 3, p->heap);
    p->f54 = CLACT_RegisterCharacter(h, 8, 0, 0, p->heap);
    p->f58 = CLACT_RegisterCellAnim(h, 0xc, 0x13, p->heap);
    ARC_TOOL_DeleteHandle(h);
    p->count = 1;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C8390[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    MI_CpuFill8(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 1;
    list.owner = p->f28;
    list.channel = 1;
    list.pal = 0xd;
    list.objPal = 8;
    list.kind = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = ZKND_TBAR_GetButtonActor(p->mgr, p->slots[i].src->id);
}

void ZUKAN_DETAIL_TOUCHBAR_ReleaseLeftArrowResources(struct Ov208Scene *e)
{
    if (e->mgr != 0) {
        ZKND_TBAR_DeleteButtonList(e->mgr);
        CLACT_ReleasePalette((u32)e->f50);
        CLACT_ReleaseCharacter((u32)e->f54);
        CLACT_ReleaseCellAnim((u32)e->f58);
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

    h = func_020490F4(0x9f, p->heap);
    p->f5c = CLACT_RegisterPaletteEx(h, 3, 0, 0x160, 0, 3, p->heap);
    p->f60 = CLACT_RegisterCharacter(h, 0xd, 0, 0, p->heap);
    p->f64 = CLACT_RegisterCellAnim(h, 0x1b, 0x2c, p->heap);
    ARC_TOOL_DeleteHandle(h);
    p->count = 6;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C83C8[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    d = &descs[3];
    d->ha = p->f60;
    d->hc = p->f5c;
    d->he = p->f64;
    d->h10 = 0xe;
    d->h12 = 0xe;
    d->h14 = 0x14;
    d->f18 = 1;
    d->f1c = 0x54c;
    MI_CpuFill8(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 6;
    list.owner = p->f28;
    list.channel = 1;
    list.pal = 0xd;
    list.objPal = 8;
    list.kind = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = ZKND_TBAR_GetButtonActor(p->mgr, p->slots[i].src->id);
    ZKND_TBAR_SetButtonAnimSeqLoop(p->mgr, p->slots[1].src->id, 0x110);
    ZKND_TBAR_SetButtonAnimSeqLoop(p->mgr, p->slots[2].src->id, 0x220);
    if (p->f40 == 0) {
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[5].src->id, 0);
        ZKND_TBAR_SetButtonVisible(p->mgr, p->slots[4].src->id, 0);
    }
}

void ZUKAN_DETAIL_TOUCHBAR_ReleaseRightArrowResources(char *p)
{
    if (*(int *)&((struct Obj01081 *)p)->f30 != 0) {
        ZKND_TBAR_DeleteButtonList((struct Ov208Mgr *)(*(int *)&((struct Obj01081 *)p)->f30));
        CLACT_ReleasePalette(((struct Obj01081 *)p)->f5C);
        CLACT_ReleaseCharacter(((struct Obj01081 *)p)->f60);
        CLACT_ReleaseCellAnim(((struct Obj01081 *)p)->f64);
    }
    *(int *)&((struct Obj01081 *)p)->f30 = 0;
}

void ZUKAN_DETAIL_TOUCHBAR_UpdateArrowInput(char *p)
{
    unsigned held=KEY_GetTrg();
    unsigned keys=KEY_GetRepeat();
    if(!(held&0x3f0)) {
        if(keys&0x40) ZKND_TBAR_GetButtonActorRaw(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f94);
        else if(keys&0x80) ZKND_TBAR_GetButtonActorRaw(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f8C);
        else if(keys&0x220) ZKND_TBAR_GetButtonActorRaw(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f7C);
        else if(keys&0x110) ZKND_TBAR_GetButtonActorRaw(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f74);
    }
}
