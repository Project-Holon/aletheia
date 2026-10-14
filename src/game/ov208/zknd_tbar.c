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
 * Cut from zukan_detail_common.c, zukan_detail_graphic.c, zukan_detail_form.c, ov208_func_021C80CC.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049740  0x02049740  arm
 *   func_020413B0  0x020413B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_0203FB44 0x0203FB44 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021BD634        0x021BD634  thumb
 *   data_021C8DD8        0x021C8DD8  data
 *   CLACT_AddActorSurfacePos        0x0204B404  arm
 *   func_020275E4        0x020275E4  thumb
 *   func_02027624        0x02027624  thumb
 *   func_02049B68        0x02049B68  arm
 *   func_02027628        0x02027628  thumb
 *   func_0202762C        0x0202762C  thumb
 *   func_02027614        0x02027614  thumb
 *   CLACT_RegisterPaletteEx        0x0204AC18  arm
 *   func_02027618        0x02027618  thumb
 *   CLACT_RegisterCharacter        0x0204A6C8  arm
 *   func_0202761C        0x0202761C  thumb
 *   func_02027620        0x02027620  thumb
 *   CLACT_RegisterCellAnim        0x0204AF28  arm
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0204169C  0x0204169C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_020410D0  0x020410D0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020416D4  0x020416D4  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   data_021C8314  0x021C8314  data
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
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
#include "../../matched/include/Obj05865.h"
#include "zukan_detail_types.h"
#include "../../matched/include/Obj18236.h"
#include "../../matched/include/Obj03928.h"
#include "../../matched/include/Obj18238.h"
#include "../../matched/include/Obj03065.h"
#include "../../matched/include/Obj18242.h"
#include "../../matched/include/Obj05536.h"
#include "../../matched/include/Obj14647.h"
#include "../../matched/include/Obj18243.h"
#include "../../matched/include/Obj05866.h"
#include "../../matched/include/Obj12118.h"
#include "zukan_detail_procsys_shared_types.h"
#include "zukan_detail_common_shared_types.h"
#include "zknd_tbar_shared_types.h"

extern u32 func_020307B0(void *p);

extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern void ARC_TOOL_DeleteHandle(void *h);

extern void func_0203FB44(u32 layer, u32 offset, u32 size);

struct Scrn {
    u8  pad0[0xc];
    u16 data[1];
};

typedef signed short   s16_021BD574;

struct Ov208ActKind {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u32 e;
    u32 f;
};

struct Ov208Pos {
    s16_021BD574 x;
    s16_021BD574 y;
    u16 h4;
    u8  b6;
    u8  b7;
};

extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned short);

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void func_021BD634(struct Ov208Rec *p, u32 owner, struct Ov208Bg *res,
                          struct Ov208ActDesc *desc, u32 prio, u32 mode);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

extern u32  func_020275E4(void);

extern void *func_020490F4(unsigned int id, unsigned int heap);

extern u32  func_02027624(void);

extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern u32  func_02027628(void);

extern u32  func_0202762C(void);

extern u32  func_02027614(void);

extern u32  CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern u32  func_02027618(void);

extern u32  CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern u32  func_0202761C(u32 a);

extern u32  func_02027620(u32 a);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);

extern int func_02062B30(void *file, void **out);

extern u8 func_0204169C(int channel);

extern u32 func_0204162C(int channel);

extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);

extern void func_020409B4(u8 channel);

extern u8   func_020416D4(u32 layer);

extern struct Obj *CLACT_CreateActor(u32 owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);

extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 CLACT_GetActorDrawEnable(struct Obj *p);

extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);

extern void func_020355D8(u8 v);

extern u32 KEY_GetTrg(void);

extern u32 CLACT_IsActorAnimActive(struct Actor *a);

extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

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

void ZKND_TBAR_LoadCellArchive(void *a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6, u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u16 heap);

void ZKND_TBAR_CreateButton(struct Ov208Rec *p, u32 owner, const int *res, struct Ov208ActDesc *desc, u32 prio, u16 mode);

void ZKND_TBAR_DeleteButton(char *p);

int ZKND_TBAR_UpdateButtonTouch(char *p);

int ZKND_TBAR_IsButtonAnimating(int *p);

int ZKND_TBAR_GetButtonActorBase(char *p);

void ZKND_TBAR_SetActorDrawEnable(struct Obj **p, unsigned int v);

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
    set = func_02030734(heap, size, 0, data_021C8DD8, 0x107);
    MI_CpuFill8(set, 0, size);
    set->count = list->count;
    set->f8 = 0;
    set->fc = 1;
    set->f10 = 0;
    objChannel = 1;
    if (list->channel >= 4)
        palOfs = 4;
    else
        objChannel = 0;
    ZKND_TBAR_LoadButtonResources(&set->bg, (u8)list->channel, objChannel, palOfs, list->kind,
                        (u8)list->pal, (u8)list->objPal, list->skip, heap);
    for (i = 0; i < set->count; i++)
        func_021BD634(&set->recs[i], list->owner, &set->bg, &list->descs[i], objChannel, heap);
    return set;
}

void ZKND_TBAR_DeleteButtonList(struct Ov208Mgr *m)
{
    u32 i;
    for (i = 0; i < m->count; i++)
        ZKND_TBAR_DeleteButton((char *)(&m->recs[i]));
    ZKND_TBAR_ReleaseButtonResources((char *)&m->bg);
    func_020307B0(m);
}

void ZKND_TBAR_UpdateButtons(struct Ov208Mgr *p)
{
    unsigned i;
    switch(p->f8) {
    case 0:
        p->f0=-1;
        if(p->fc && !p->f10) {
            for(i=0;i<p->count;i++) {
                if(ZKND_TBAR_UpdateButtonTouch((char *)&p->recs[i])) {
                    p->f0=i;
                    p->f8=1;
                    p->f10=1;
                    break;
                }
            }
        }
        break;
    case 1:
        p->f8=2;
    case 2:
        if(ZKND_TBAR_IsButtonAnimating((int *)&p->recs[p->f0]))p->f8=3;
        break;
    case 3:
        p->f8=0;
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

    if (p->f8 == 3) {
        i = p->f0;
        if (i != -1)
            return ZKND_TBAR_GetButtonActorBase((char *)&p->recs[i]);
    }
    return -1;
}

int ZKND_TBAR_GetHeldKey(struct Ov208Mgr *m)
{
    if (m->f8 == 1 && m->f0 != -1)
        return ZKND_TBAR_GetButtonActorBase((char *)(&m->recs[m->f0]));
    return -1;
}

void ZKND_TBAR_SetButtonDrawEnable(struct Ov208Mgr *p, int v)
{
    u32 i;

    for (i = 0; i < p->count; i++)
        ZKND_TBAR_SetActorDrawEnable((void *)((u32)p + 0x28 + i * 0x38), v);
}

/*
 * Stores the second argument at +0xC.
 */
void ZKND_TBAR_SetTouchEnable(struct Ov208Mgr *p, int v)
{
    p->fc = v;
}

/*
 * Returns the word at +0xC (the two words after it are untraced continuations).
 */
int ZKND_TBAR_GetTouchEnable(struct Ov208Mgr *p)
{
    return p->fc;
}

void ZKND_TBAR_ClearButtonState(struct Ov208Mgr *p)
{
    p->f10 = 0;
}

void ZKND_TBAR_SetButtonAnimSeq(struct Ov208Mgr *a, int b, int c)
{
    ZKND_TBAR_SetActorAnimSeq((char *)ZKND_TBAR_FindButtonActor(a, b), c);
}

void ZKND_TBAR_SetButtonVisible(struct Ov208Mgr *a, int b, int c)
{
    ZKND_TBAR_SetActorDrawEnable((struct Obj **)ZKND_TBAR_FindButtonActor(a, b), c);
}

int ZKND_TBAR_GetButtonVisible(struct Ov208Mgr *mgr, int key)
{
    return ZKND_TBAR_GetActorDrawEnable(ZKND_TBAR_IsKeyAnimActive(mgr, key));
}

void ZKND_TBAR_SetButtonAnimSeqLoop(struct Ov208Mgr *a, int b, int c)
{
    ZKND_TBAR_SetPressedAnim((char *)ZKND_TBAR_FindButtonActor(a, b), c);
}

void ZKND_TBAR_SetButtonAnimSeqOnce(struct Ov208Mgr *a, int b, int c)
{
    ZKND_TBAR_SetAnimByState((char *)ZKND_TBAR_FindButtonActor(a, b), c);
}

int ZKND_TBAR_IsButtonAnimActive(struct Ov208Mgr *mgr, int key)
{
    return ZKND_TBAR_GetButtonSound(ZKND_TBAR_IsKeyAnimActive(mgr, key));
}

int ZKND_TBAR_GetButtonActor(struct Ov208Mgr *mgr, int key)
{
    return ZKND_TBAR_FindButtonActor(mgr, key)->f0;
}

void ZKND_TBAR_AddButtonPos(struct Ov208Mgr *p, int key, u16 *pos)
{
    struct Ov208Rec *r = ZKND_TBAR_FindButtonActor(p, key);

    r->desc.x = pos[0];
    r->desc.y = pos[1];
    CLACT_AddActorSurfacePos((struct Obj *)r->f0, (const struct Vec2 *)pos, (u16)(p->bg.fc >= 4 ? 1 : 0));
}

void ZKND_TBAR_GetButtonActorRaw(struct Ov208Mgr *mgr, int key)
{
    ZKND_TBAR_FindButtonActor(mgr, key)->f34 = 1;
}

struct Ov208Rec *ZKND_TBAR_FindButtonActor(struct Ov208Mgr *p, int key)
{
    u32 i;

    for (i = 0; i < p->count; i++) {
        if (key == ZKND_TBAR_GetButtonActorBase((char *)((u32)p + 0x28 + i * 0x38)))
            return (struct Ov208Rec *)((u32)p + 0x28 + i * 0x38);
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
    p->fc = channel;
    h = func_020490F4(func_020275E4(), heap);
    if (skip == 0) {
        func_02049B68(h, func_02027624(), palOfs, pal << 5, 0x20, heap);
        p->f10 = func_02049740(h, func_02027628(), p->fc, 0x800, 0, heap);
        ZKND_TBAR_LoadCellArchive(h, func_0202762C(), p->fc, (u16)p->f10, 0, 0x15, 0x20, 0x18,
                            0, 0x15, 0x20, 3, pal, 0, heap);
    }
    p->f0 = CLACT_RegisterPaletteEx(h, func_02027614(), objChannel, (u16)(objPal << 5), 0, 3, heap);
    p->f4 = CLACT_RegisterCharacter(h, func_02027618(), 0, objChannel, heap);
    p->f8 = CLACT_RegisterCellAnim(h, func_0202761C(kind), func_02027620(kind), heap);
    ARC_TOOL_DeleteHandle(h);
}

/*
 * Releases +8, +4 and +0, passes the pair at +0x10 on and clears the 0x14-byte object.
 */
void ZKND_TBAR_ReleaseButtonResources(char *p)
{
    unsigned int w;

    CLACT_ReleaseCellAnim(((struct Obj05865 *)p)->f8);
    CLACT_ReleaseCharacter(((struct Obj05865 *)p)->f4);
    CLACT_ReleasePalette(((struct Obj05865 *)p)->f0);
    w = ((struct Obj05865 *)p)->f10;
    func_0203FB44(((struct Obj05865 *)p)->fC, (unsigned short)w, (unsigned short)(w >> 16));
    MI_CpuFill8((void *)((int)p), 0, 0x14);
}

int ZKND_TBAR_GetResourceSlot(int *p, int i)
{
    return p[i];
}

void ZKND_TBAR_LoadCellArchive(void *a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6,
                         u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u16 heap)
{
    struct Scrn *scr;
    u32 file;
    int i;
    u16 *d;

    file = (u32)ARC_UTIL_LoadHandleMember(a0, a1, a13, (u16)((heap & 0x7fff) | 0x8000));
    func_02062B30((void *)file, (void **)(&scr));
    if (add != 0 && func_0204169C((u8)channel) == 0) {
        d = scr->data;
        for (i = 0; i < a6 * a7; i++)
            d[i] += (u16)add;
    }
    if ((int)func_0204162C((u8)channel) != 0) {
        func_020410D0((u8)channel, x, y, w, h, (u32)scr->data, a4, a5, a6, a7);
        func_020413B0(channel, x, y, w, h, pal);
        func_020409B4(channel);
    }
    func_020307B0((void *)file);
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
    p->f4 = 1;
    p->f34 = 0;
    MI_CpuFill8(&pos, 0, 8);
    pos.b7 = func_020416D4((u8)res[3]);
    pos.x = desc->x;
    pos.y = desc->y;
    if (desc->f0 >= 7) {
        i = desc->ha;
        j = desc->hc;
        k = desc->he;
        p->f10 = 0;
    } else {
        i = ZKND_TBAR_GetResourceSlot((int *)res, 1);
        j = ZKND_TBAR_GetResourceSlot((int *)res, 0);
        k = ZKND_TBAR_GetResourceSlot((int *)res, 2);
        n = desc->f0;
        p->desc.h10 = data_021C8314[n].a;
        p->desc.h12 = data_021C8314[n].b;
        p->desc.h14 = data_021C8314[n].c;
        p->desc.f18 = data_021C8314[n].e;
        p->desc.f1c = data_021C8314[n].d;
        p->f10 = data_021C8314[n].f;
    }
    p->f8 = p->desc.h10;
    pos.h4 = p->desc.h10;
    p->f0 = (u32)CLACT_CreateActor((u32)owner, i, j, k, &pos, prio, mode);
    CLACT_SetActorAutoAnim((struct Obj *)p->f0, 1);
    switch (p->f10) {
    case 0:
        p->fc = (void (*)(void))ZKND_TBAR_PlayCancelAnim;
        break;
    case 1:
        p->fc = (void (*)(void))ZKND_TBAR_PlayButtonAnim;
        break;
    }
}

/*
 * Releases +0 and clears 0x38 bytes of the object.
 */
void ZKND_TBAR_DeleteButton(char *p)
{
    CLACT_DeleteActor((struct Obj *)(((struct Obj18236 *)p)->f0));
    MI_CpuFill8(p, 0, 0x38);
}

int ZKND_TBAR_UpdateButtonTouch(char *p)
{
    unsigned x,y;
    int hit=0;
    if(CLACT_GetActorDrawEnable(((struct Obj03928 *)p)->f0)&((struct Obj03928 *)p)->f4) {
        if(TOUCHPANEL_GetPointTrg(&x,&y) && x-((struct Obj03928 *)p)->f18<=((struct Obj03928 *)p)->f1C && y-((struct Obj03928 *)p)->f1A<=24) {
            hit=1;
            func_020355D8(1);
        }
        if(((struct Obj03928 *)p)->f2C && (KEY_GetTrg()&((struct Obj03928 *)p)->f2C)) {
            func_020355D8(0);
            hit=1;
        }
        if(((struct Obj03928 *)p)->f34) {
            func_020355D8(0);
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
    return CLACT_IsActorAnimActive((struct Actor *)(*p)) == 0;
}

int ZKND_TBAR_GetButtonActorBase(char *p)
{
    return ((struct Obj18238 *)p)->f14;
}

/*
 * Loads the word at [p] and tail-calls the function at 0x0204B3DC with it and
 * the second argument.
 */
void ZKND_TBAR_SetActorDrawEnable(struct Obj **p, unsigned int v)
{
    CLACT_SetActorDrawEnable(*p, v);
}

unsigned ZKND_TBAR_GetActorDrawEnable(int *p)
{
    return CLACT_GetActorDrawEnable((struct Obj *)(*p));
}

void ZKND_TBAR_SetActorAnimSeq(char *p, int v)
{
    ((struct Obj03065 *)p)->f4 = v;
    if (v != 0) {
        if (((struct Obj03065 *)p)->f8 == ((struct Obj03065 *)p)->f28)
            ((struct Obj03065 *)p)->f8 = ((struct Obj03065 *)p)->f24;
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj03065 *)p)->f0), (unsigned short)((struct Obj03065 *)p)->f8);
    } else {
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj03065 *)p)->f0), ((struct Obj03065 *)p)->f26);
    }
}

void ZKND_TBAR_SetPressedAnim(char *p, int v)
{
    ((struct Obj18242 *)p)->f2C = v;
}

void ZKND_TBAR_SetAnimByState(char *p, int which)
{
    if (which != 0)
    {
        ((struct Obj05536 *)p)->f8 = ((struct Obj05536 *)p)->f28;
    }
    else
    {
        ((struct Obj05536 *)p)->f8 = ((struct Obj05536 *)p)->f24;
    }
    CLACT_SetActorAnimSeq(((struct Obj05536 *)p)->f0, (unsigned short)((struct Obj05536 *)p)->f8);
}

int ZKND_TBAR_GetButtonSound(const void *p)
{
    u32 r1 = ((struct Obj14647 *)p)->f8;
    u32 r0 = ((struct Obj14647 *)p)->f28;
    return r1 == r0;
}

/*
 * Clears the word at +0x34.
 */
void ZKND_TBAR_GetButtonCount(char *p)
{
    ((struct Obj18243 *)p)->f34 = 0;
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
    unsigned short h = ((struct Obj05866 *)p)->f28;
    int v = ((struct Obj05866 *)p)->f0;

    ((struct Obj05866 *)p)->f8 = h;
    CLACT_SetActorAnimSeq((struct Obj *)v, h);
    if (((struct Obj05866 *)p)->f30 != 0)
        GFL_USE_PlaySeDefaultVolume(((struct Obj05866 *)p)->f30);
}

void ZKND_TBAR_PlayButtonAnim(char *p)
{
    int f = ZKND_TBAR_GetButtonSound(p) == 0;

    ZKND_TBAR_SetAnimByState(p, f);
    if (((struct Obj12118 *)p)->f30 != 0)
        GFL_USE_PlaySeDefaultVolume(((struct Obj12118 *)p)->f30);
}
