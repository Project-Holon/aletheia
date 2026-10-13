/*
 * file:     unit_021C5A28.c
 * unit:     yes
 * function: func_021C5A28, func_021C5A54, func_021C5AAC, func_021C5B58, func_021C5BD0, func_021C5C08
 * address:  0x021C5A28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldeff_splash.c at 0x021C5A28 (lane FXC, CL129: script event helpers called by scrcmd_c03center.c and scrcmd_proc_fld.c; no home evidence, original unknown).
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020146F8  0x020146F8  thumb
 *   func_02014728  0x02014728  thumb
 *   func_02012374  0x02012374  thumb
 *   abs_id_C2      0x000000C2  data
 *   d_021F5580     0x021F5580  data  ov194  a4
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0216BFD4  0x0216BFD4  thumb  ov010
 *   func_02017E40  0x02017E40  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0216C0C0  0x0216C0C0  thumb  ov010
 *   ov171_id       0x000000AB  data  a1
 *   d_021DEA44    0x021DEA44  data  ov021  a1
 */
#include "field_effect_types.h"
#include "../ov010/fldmmdl_types.h"

struct BbActDesc;
struct BbActSys;
struct BbActRec;
struct X;
struct Actor;
struct Res_021C48A0;
struct IcaAnime;
struct Rec12;
struct Mtx33;
struct Big;
struct BgTemplate;
struct Bank;
struct GfFont;
struct MsgBank;
struct Obj;
struct PrintSys;
struct Rec;
struct Node;
struct Descriptor;
struct Cfg;
struct Slot;
struct Src;
struct PtS;
struct Vec2;
struct Desc;
struct Evt;
struct BigObj;
struct Ctx;
struct Sub02008C20Obj;
struct Self;
struct S0201235C;

typedef signed short   s16_021C48A0;

typedef signed char    s8;

typedef int            s32_021C4E6C;

typedef signed int     s32_021C4F7C;

typedef signed short   s16_021C59A8;

/* Parameter block of the name entry screen (ov194 proc), as far as this file reads it. */
typedef struct NameInParam {
    u32 setup[7];                         /* 0x00 */
    int cancelled;                        /* 0x1C: 1 when the player backed out */
    u16 *name;                            /* 0x20: the entered name */
} NameInParam;

typedef struct NameInEventWork {
    void *gameSystem;                     /* 0x00 */
    void *fieldMap;                       /* 0x04 */
    NameInParam *nameIn;                  /* 0x08 */
    u32 mode;                             /* 0x0C: selects which proc starter runs */
} NameInEventWork;

typedef struct NicknameEventWork {
    void *gameSystem;                     /* 0x00 */
    void *fieldMap;                       /* 0x04 */
    NameInParam *nameIn;                  /* 0x08 */
    void *mon;                            /* 0x0C: the party member being named */
    u16 *result;                          /* 0x10: script result, 1 when a name was set */
    int mode;                             /* 0x14 */
} NicknameEventWork;

typedef struct SubProcParam {
    void *gameData;                       /* 0x00 */
    u16 procId;                           /* 0x04 */
    u16 resultCode;                       /* 0x06: written by the proc */
} SubProcParam;

typedef struct SubProcEventWork {
    void *gameSystem;                     /* 0x00 */
    void *fieldMap;                       /* 0x04 */
    SubProcParam param;                   /* 0x08 */
    u16 *result;                          /* 0x10 */
} SubProcEventWork;

typedef short s16_021C577C;

typedef struct { fx32 m[3][3]; } MtxFx33;

/* Entry template for BILLBOARD_ACT_CreateEntries (0x24 bytes). */
typedef struct BbActDesc {
    u16 imageIdx;
    u16 scaleX;
    u16 scaleY;
    u8 alpha;
    u8 pad07;
    u32 visible;
    u32 animEnable;
    VecFx32 pos;
    void (*onEnd)(void);
    void *userData;
} BbActDesc;

/* Image record for BILLBOARD_ACT_CreateSlots. */
typedef struct BbActRec {
    void *resource;
    u8 type;
    u8 imageId;
    u8 cellWidth;
    u8 cellHeight;
    u32 count;
} BbActRec;

extern void *func_02012EBC(struct Big *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
extern void *func_020146F8(char *gameSystem, int fieldMap, int overlayId, int procData, int procWork);
extern void *func_02014728(char *gameSystem, int fieldMap, int overlayId, int procData, int procWork);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *a);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_0200C0F0(void *a);
extern u32 func_02017E1C(void *a, u32 b, u32 c);
extern int *func_0216BFD4(int a, int b, int c, int d, int e, int f, void *g);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int func_0216C0C0(int a0);
/* Retain the mode used to store f59 for the helper's second argument. */
void *func_021C5A28(void *gameSystem, void *fieldMap, NameInParam *nameIn, u32 mode);
int func_021C5A54(struct Evt *event, int *state, NameInEventWork *work);
int func_021C5AAC(void *gameSystem, u16 *result, int partyIndex, int mode);
int func_021C5B58(struct Evt *event, int *state, NicknameEventWork *work);
void *func_021C5BD0(void *gameSystem, u32 procId, u16 *result);
int func_021C5C08(struct Evt *event, int *state, SubProcEventWork *work);
extern char d_021F5580;
extern unsigned char abs_id_C2[];
extern char d_021DEA44[];
extern char ov171_id[];
/*
 * Spawns the func_021C5A54 task with a four-word work area.
 */
void *func_021C5A28(void *gameSystem, void *fieldMap, NameInParam *nameIn, u32 mode)
{
    void *task = func_020122C0(gameSystem, 0, func_021C5A54, 0x10);
    NameInEventWork *work = func_020124E8(task);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->nameIn = nameIn;
    work->mode = mode;
    return task;
}

/*
 * Blocked (MATCH, every concrete byte right): the pooled word 0x000000C2 is a
 * pooled small constant (abs_id_C2, R_ARM_ABS32) passed as the third argument
 * to func_020146F8 / func_02014728, neither of which is in match.py's
 * OVERLAY_ID_CONSUMERS, and no other pool word image-wide holds 0x000000C2,
 * so no evidence class attests it.  d_021F5580 resolves with the ov194 token (0xC2 is ov194; its proc table init/main/exit sits at 0x021F5580).
 */
int func_021C5A54(struct Evt *event, int *state, NameInEventWork *work)
{
    int childEvent;

    switch (*state) {
    case 0:
        if (work->mode != 0) {
            childEvent = (int)func_020146F8((char *)work->gameSystem, (int)work->fieldMap, (int)abs_id_C2, (int)(&d_021F5580), (int)work->nameIn);
        } else {
            childEvent = (int)func_02014728((char *)work->gameSystem, (int)work->fieldMap, (int)abs_id_C2, (int)(&d_021F5580), (int)work->nameIn);
        }
        func_02012374(event, (struct Evt **)childEvent);
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

int func_021C5AAC(void *gameSystem, u16 *result, int partyIndex, int mode)
{
    int task;
    NicknameEventWork *work;
    void *mon;
    void *saveData;
    int species;
    int monForm;

    if ((int)func_0201AA18(func_02012934(func_020120F4(gameSystem))) <= partyIndex) {
        partyIndex = 0;
    }
    task = (int)func_020122C0(gameSystem, 0, (void *)func_021C5B58, 0x18);
    work = func_020124E8((struct Obj *)task);
    work->gameSystem = gameSystem;
    work->fieldMap = func_0201210C(gameSystem);
    work->result = result;
    work->mode = mode;
    saveData = func_020120F4(work->gameSystem);
    mon = func_0201AB28(func_02012934(saveData), partyIndex);
    saveData = func_0200C0F0(func_02012EBC(saveData));
    species = func_02017E1C(mon, 5, 0);
    monForm = func_02017E1C(mon, 0x6f, 0) | (func_02017E1C(mon, 0x6e, 0) << 8);
    work->nameIn = (NameInParam *)func_0216BFD4(4, 1, species, monForm, 0xa, 0, saveData);
    work->mon = mon;
    return task;
}

int func_021C5B58(struct Evt *event, int *state, NicknameEventWork *work)
{
    NameInParam *nameIn;
    int confirmed;

    switch (*state) {
    case 0:
        func_02012374(event, func_021C5A28(work->gameSystem, work->fieldMap, work->nameIn, work->mode));
        (*state)++;
        break;
    case 1:
        nameIn = work->nameIn;
        if (nameIn->cancelled != 1) {
            func_02017E40(work->mon, 0x73, (u32)nameIn->name);
        }
        confirmed = 1;
        if (work->nameIn->cancelled == 1) {
            confirmed = 0;
        }
        *work->result = confirmed;
        if (*work->result == 1) {
            func_02008DF0(func_02012F2C(func_020120F4(work->gameSystem)), 0x1e);
        }
        func_0216C0C0((int)work->nameIn);
        return 1;
    }
    return 0;
}

/*
 * Spawns the func_021C5C08 task with a 0x14-byte work area.
 */
void *func_021C5BD0(void *gameSystem, u32 procId, u16 *result)
{
    void *task = func_020122C0(gameSystem, 0, func_021C5C08, 0x14);
    SubProcEventWork *work = func_020124E8(task);
    work->gameSystem = gameSystem;
    work->fieldMap = func_0201210C(gameSystem);
    work->result = result;
    work->param.gameData = func_020120F4(gameSystem);
    work->param.procId = procId;
    return task;
}

/*
 *           func_020146F8 (0x020146F8), which is not in match.py
 *           OVERLAY_ID_CONSUMERS, so the ABS32 has no witness (literal class
 *           refuses the range's own pool word).  Every concrete byte matches.
 */
int func_021C5C08(struct Evt *event, int *state, SubProcEventWork *work)
{
    int value;

    switch (*state) {
    case 0:
        func_02012374(event, func_020146F8((char *)work->gameSystem, (int)work->fieldMap, (int)ov171_id, (int)d_021DEA44, (int)&work->param));
        *state = *state + 1;
        break;
    case 1:
        switch (work->param.resultCode) {
        case 0:
            value = 0;
            *work->result = value;
            break;
        case 1:
            value = 1;
            *work->result = value;
            break;
        }
        return 1;
    }
    return 0;
}
