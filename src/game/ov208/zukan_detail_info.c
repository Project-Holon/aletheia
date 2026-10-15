/*
 * file:     zukan_detail_info.c
 * unit:     yes
 * function: ZUKAN_DETAIL_INFO_SetHeapId, ZUKAN_DETAIL_INFO_Init, ZUKAN_DETAIL_INFO_Exit, ZUKAN_DETAIL_INFO_Main, ZUKAN_DETAIL_INFO_HandleKeyEvent, ZUKAN_DETAIL_INFO_NoOp, ZUKAN_DETAIL_INFO_HandleTouchLanguageButton, ZUKAN_DETAIL_INFO_HandleKeyLanguageSelect, ZUKAN_DETAIL_INFO_RefreshLanguagePanel, ZUKAN_DETAIL_INFO_SelectLanguageButton, ZUKAN_DETAIL_INFO_CreateLanguageButtons, ZUKAN_DETAIL_INFO_DeleteLanguageButtons, ZUKAN_DETAIL_INFO_UpdateButtonPressAnim, ZUKAN_DETAIL_INFO_ResetButtons, ZUKAN_DETAIL_INFO_GetPanelParams, ZUKAN_DETAIL_INFO_LoadHighlightPalettes, ZUKAN_DETAIL_INFO_NoOpHighlight, ZUKAN_DETAIL_INFO_StartHighlightBlink, ZUKAN_DETAIL_INFO_ClearButtonHighlight, ZUKAN_DETAIL_INFO_UpdateHighlightBlink
 * address:  0x021BEA00
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan_detail_headbar.c, zukan_detail_page.c, zukan_detail_voice.c, zukan_detail_form.c by tools/splitfile.py.
 *
 * symbols:
 *   func_020307B0 0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02040618 0x02040618 arm
 *   func_02045B38 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020414AC 0x020414AC arm
 *   CLACT_RegisterCharacter        0x0204A6C8  arm
 *   CLACT_RegisterCellAnim        0x0204AF28  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   func_02049F34  0x02049F34  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   func_02061CA4 0x02061CA4 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   func_02034AC4 0x02034AC4 arm
 *   ov067_id 0x00000043 data
 *   ov206_id 0x000000CE data
 *   ZUKAN_DETAIL_PROCSYS_AllocBuffer 0x021BC32C thumb
 *   ZUKAN_DETAIL_COMMON_AllocBlendWork 0x021BC448 thumb
 *   ZUKAN_DETAIL_COMMON_InitBrightnessTarget 0x021BC518 thumb
 *   ZUKAN_DETAIL_COMMON_SetBrightnessNone 0x021BC508 thumb
 *   func_021BA2CC 0x021BA2CC thumb ov206
 *   ZUKAN_DETAIL_COMMON_FreeBlendWork 0x021BC464 thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_FreeBuffer 0x021BC34C thumb ov208
 *   func_02034A5C 0x02034A5C arm
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr 0x021BC3B4 thumb
 *   ZUKAN_DETAIL_COMMON_GetCursorValue 0x021BC3B8 thumb
 *   func_021BDAD0 0x021BDAD0 thumb
 *   func_021BC3BC 0x021BC3BC thumb
 *   func_021BDAAC 0x021BDAAC thumb
 *   func_021BDAD4 0x021BDAD4 thumb
 *   func_021BDBB8 0x021BDBB8 thumb
 *   ZUKAN_DETAIL_COMMON_GetSource 0x021BC3A4 thumb
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   func_021BE840 0x021BE840 thumb
 *   func_021BE82C 0x021BE82C thumb
 *   func_021BE844 0x021BE844 thumb
 *   ZUKAN_DETAIL_COMMON_GetDisplay 0x021BC3A8 thumb
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   ZUKAN_DETAIL_COMMON_GetGraphics 0x021BC3B0 thumb
 *   func_021B9E68 0x021B9E68 thumb ov206
 *   func_021BA7C8 0x021BA7C8 thumb ov206
 *   func_021BC4D8 0x021BC4D8 thumb
 *   func_021BC4C8 0x021BC4C8 thumb
 *   func_021BDBA0 0x021BDBA0 thumb
 *   func_021BC4E4 0x021BC4E4 thumb
 *   func_021BE854 0x021BE854 thumb
 *   func_021BA374 0x021BA374 thumb ov206
 *   func_021BC46C 0x021BC46C thumb
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry  0x021BC3C0  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies  0x021BC3CC  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies  0x021BC40C  thumb  ov208
 *   GAME_DATA_SetSaveFlag  0x02012BE0  thumb
 *   ov208_func_021BF280  0x021BF280  thumb  ov208
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_021BA550 0x021BA550 thumb ov206
 *   func_021BA6B0 0x021BA6B0 thumb ov206
 *   func_021BA814 0x021BA814 thumb ov206
 *   func_021BA64C 0x021BA64C thumb ov206
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   d_021C851C 0x021C851C data ov208 a1
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   ZUKAN_SAVE_GetViewGenderAndForm 0x0200CC40 thumb
 *   ZUKAN_SAVE_GetSpindaPersonality 0x0200D288 thumb
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 *   ZUKAN_SAVE_HasLanguageFlag 0x0200D3C0 thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled  0x021BDC48  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq  0x021BDC14  thumb
 *   ZUKAN_DETAIL_GRAPHIC_Reset3dState 0x021BCF4C thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled 0x021BDAE8 thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive 0x021BDC2C thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_GetCurrentSlot 0x021BDC80 thumb ov208
 */
#include "zukan_detail_types.h"
#include "zukan_detail_shared_types.h"
#include "../../matched/include/Obj03362.h"
#include "../../matched/include/Obj00442.h"
#include "../../matched/include/Obj02254.h"
#include "../../matched/include/Obj05538.h"
#include "../../matched/include/Obj12120.h"
#include "../../matched/include/Obj10901.h"
#include "../../matched/include/Obj18262.h"
#include "../../matched/include/Obj25493.h"

extern u32 func_020307B0(void *p);

extern void ARC_TOOL_DeleteHandle(void *h);

extern void func_02030EAC(struct Node *n);

extern void *func_020056A0(unsigned,unsigned,unsigned);

extern void *func_020490F4(unsigned int id, unsigned int heap);

extern void func_02040618(unsigned,unsigned,unsigned);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern unsigned int MSGDATA_Delete(struct Rec *rec);

void ZUKAN_DETAIL_INFO_SetHeapId(u16 *p, u16 v);

void ZUKAN_DETAIL_INFO_SetHeapId(u16 *p, u16 v)
{
    *p = v;
}

extern void *ZUKAN_SAVE_GetFromGameData(void *a);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern u32 GF_FONT_Delete(void *ptr);

struct Ov208Main;

struct Ov208Heap;

struct Ov208Main {
    int task;
    int f4; int f8;
    void *fc;
    void *f10;
    int f14; int f18;
    char pad[0x94 - 0x1c];
    int f94; int f98;
    char pad2[0x10c - 0x9c];
    int f10c;
};

struct Ov208Scn {
    u16 pad0; u16 pad2;
    void *f4; void *f8;
    struct Ov208Blend *fc; struct Ov208Blend *f10;
    int f14; int f18;
    char pad1c[0x94 - 0x1c];
    int f94;
    int f98;
    char pad9c[0xa8 - 0x9c];
    u16 srcA[0x10];
    u16 srcB[0x10];
    u16 dst[0x10];
    int f108;
    int f10c;
    void *font; void *msg0; void *msg1; void *msg2;
};

struct Ov208Heap { u16 heap; };

struct S_021BEE70 {
    u8 pad0[0x14];
    u32 f14;
    u32 f18;
};

struct E {
    u8 pad0[0x1c];
    int h1c;
    u8 x0;
    u8 y0;
    u8 w;
    u8 h;
    u8 pad24[2];
    u16 f26;
    u8 pad28[4];
    u32 f2c;
    u8 pad30[4];
};

struct S_021BEFA0 {
    u8 pad0[0x94];
    u32 cur;
    u32 prev;
};

struct Params {u16 a,b,c,d; unsigned x,y,arr[6];};

enum Index { INDEX_ZERO = 0 };

struct Pos_021BD574 { u16 x, y, z, pad; };

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void func_020414AC(u8);

extern u32  CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

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

extern u32 KEY_GetRepeat(void);

extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);

extern void MI_CpuCopy8(void *src, void *dst, u32 size);

extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

extern s32_021BD574 func_02061CA4(void *p, u32 a, u32 b, s32_021BD574 size);

extern int func_02034AC4(s32_021BD574 handle);

extern void *ZUKAN_DETAIL_PROCSYS_AllocBuffer(struct Ov208Fsm *p, u32 size, u32 heap);

extern void *ZUKAN_DETAIL_COMMON_AllocBlendWork(u32 heap);

extern void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(int *p);

extern void ZUKAN_DETAIL_COMMON_SetBrightnessNone(int flag, int *p);

extern void func_021BA2CC(char *);

extern void ZUKAN_DETAIL_COMMON_FreeBlendWork(void *);

extern void ZUKAN_DETAIL_PROCSYS_FreeBuffer(char *);

extern void func_02034A5C(int);

extern int ZUKAN_DETAIL_COMMON_GetWorkPtr(int *p);

extern int ZUKAN_DETAIL_COMMON_GetCursorValue(char *p);

extern int func_021BDAD0(void *s);

extern u16 func_021BC3BC(int *ctx);

extern void func_021BDAAC(void *s, u32 a, u32 b, u32 c);

extern void func_021BDAD4(void *s, int a);

extern void func_021BDBB8(void *s, u32 a);

extern int ZUKAN_DETAIL_COMMON_GetSource(int *ctx);

extern int GAME_DATA_CheckSaveFlag(int a, int b);

extern int func_021BE840(void *s);

extern void func_021BE82C(void *s, int a);

extern void func_021BE844(void *s);

extern int ZUKAN_DETAIL_COMMON_GetDisplay(int *ctx);

extern u32 ZUKAN_SAVE_GetViewMode(struct Blk37 *p);

extern int ZUKAN_DETAIL_COMMON_GetGraphics(int *ctx);

extern void *func_021B9E68(u32 heap, u16 a1, u16 a2, u16 a3, u16 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u8 a10, u32 a11, u32 a12, u32 a13, u32 a14, u32 a15, u32 a16);

extern void func_021BA7C8(void *p);

extern void func_021BC4D8(struct Ov208Blend *b);

extern int func_021BC4C8(struct Ov208Blend *b);

extern void func_021BDBA0(void *s);

extern void func_021BC4E4(struct Ov208Blend *b);

extern void func_021BE854(void *s);

extern void func_021BA374(char *p);

extern void func_021BC46C(struct Ov208Blend *a, struct Ov208Blend *b);

extern u16 ZUKAN_DETAIL_COMMON_GetCurrentEntry(void *p);

extern void ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(char *p);

extern void ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies(struct Ov208Cur *p);

extern void GAME_DATA_SetSaveFlag(void *p, u32 a, u32 b);

extern void ov208_func_021BF280(void *first, char *q, void *third, int next);

extern void func_021BA550(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6);

extern void func_021BA6B0(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7);

extern void func_021BA814(void *);

extern void func_021BA64C(char *p, int mode);

extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);

extern void ZUKAN_SAVE_GetViewGenderAndForm(void *, u32, u32 *, u32 *, u32 *, u16);

extern u32 ZUKAN_SAVE_GetSpindaPersonality(struct Blk37 *, u32);

extern u32 ZUKAN_SAVE_IsCaught(struct Blk37 *, u32);

extern u32 ZUKAN_SAVE_HasLanguageFlag(struct Blk37 *, u32, u32);

int ZUKAN_DETAIL_GRAPHIC_Reset3dState(char *p);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(struct Ov208Scene *p, int v);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(struct Ov208Scene *p, int b);

int ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(char *p);

void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(struct Ov208Scene *p, u32 on);

int ZUKAN_DETAIL_TOUCHBAR_GetCurrentSlot(char *p);

int ZUKAN_DETAIL_INFO_Init(void *owner, int unused, u16 *heap);

int ZUKAN_DETAIL_INFO_Exit(char *first,unsigned unused,int owner,char *q,unsigned heap);

int ZUKAN_DETAIL_INFO_Main(void *unused, int *state, struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);

void ZUKAN_DETAIL_INFO_HandleKeyEvent(void *a0, void *a1, void *heap, struct S_021BEE70 *st, int *obj, int key);

void ZUKAN_DETAIL_INFO_NoOp(void *p);

int ZUKAN_DETAIL_INFO_HandleTouchLanguageButton(void *a0, struct S_021BEFA0 *st, int *obj);

int ZUKAN_DETAIL_INFO_HandleKeyLanguageSelect(void *first,char *p,int key);

void ZUKAN_DETAIL_INFO_RefreshLanguagePanel(void *first,char *q,void *third);

void ZUKAN_DETAIL_INFO_SelectLanguageButton(void *first,char *q,void *third,int next);

void ZUKAN_DETAIL_INFO_CreateLanguageButtons(u16 *heap, char *p, int key);

void ZUKAN_DETAIL_INFO_DeleteLanguageButtons(int unused, char *q, u32 a2);

void ZUKAN_DETAIL_INFO_UpdateButtonPressAnim(void *unused, char *p, int key);

void ZUKAN_DETAIL_INFO_ResetButtons(int unused, char *q, int c, int *tbl);

void ZUKAN_DETAIL_INFO_GetPanelParams(const u16 *heap, u8 *p, int *key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7);

void ZUKAN_DETAIL_INFO_LoadHighlightPalettes(u16 *heap, u8 *p, int *ctx);

void ZUKAN_DETAIL_INFO_NoOpHighlight(int unused0, char *unused1, unsigned unused2);

void ZUKAN_DETAIL_INFO_StartHighlightBlink(struct Ov208Heap *unused, int *p, int *ctx);

void ZUKAN_DETAIL_INFO_ClearButtonHighlight(int unused, char *p, unsigned unused2);

void ZUKAN_DETAIL_INFO_UpdateHighlightBlink(struct Ov208Heap *a0, struct Ov208Scn *e, int *ctx);

extern s16_021BE20C FX_SinCosTable_[];

extern const char ov067_id[];

extern const char ov206_id[];

extern const u8 d_021C851C[];

extern s16_021C23BC FX_SinCosTable_[];

/*
 * 2026-10-04 (D2-16): callback ZUKAN_DETAIL_INFO_NoOp filed EXACT as src/matched/ov/ov208_func_021BEF9C.c (empty void function, bx lr). Still MATCH only
 * because no shard witnesses it yet; the integrator manifest run should make this EXACT. Symbols line now carries the ov208 hint.
 * 2026-10-02: only ZUKAN_DETAIL_INFO_NoOp (task callback, no witness yet) blocks EXACT; bytes match.
 */
int ZUKAN_DETAIL_INFO_Init(void *owner, int unused, u16 *heap)
{
    struct Ov208Main *s;
    func_02034AC4((u32)ov067_id);
    func_02034AC4((u32)ov206_id);
    s = ZUKAN_DETAIL_PROCSYS_AllocBuffer(owner, 0x120, *heap);
    MI_CpuFill8(s, 0, 0x120);
    s->task = (int)func_020056A0((unsigned)ZUKAN_DETAIL_INFO_NoOp, (unsigned)s, 1);
    s->f94 = 6;
    s->f98 = 6;
    s->f10c = 0;
    s->fc = ZUKAN_DETAIL_COMMON_AllocBlendWork(*heap);
    s->f10 = ZUKAN_DETAIL_COMMON_AllocBlendWork(*heap);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(s->fc);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(s->f10);
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(0, s->fc);
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(1, s->f10);
    s->f14 = 0;
    s->f18 = 1;
    return 1;
}

/*
 * matching: full-width stack argument reloads; small pool operands are overlay ID symbols.
 * Caller visibly supplies third arguments to helpers and a live r0 to BC464.
 */
int ZUKAN_DETAIL_INFO_Exit(char *first,unsigned unused,int owner,char *q,unsigned heap)
{
    ZUKAN_DETAIL_INFO_ClearButtonHighlight(owner,q,heap);ZUKAN_DETAIL_INFO_NoOpHighlight(owner,q,heap);
    func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f8);func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f4);
    ZUKAN_DETAIL_INFO_DeleteLanguageButtons(owner,q,heap);
    GF_FONT_Delete(((struct Obj03362 *)q)->f110);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj03362 *)q)->f11C);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj03362 *)q)->f118);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj03362 *)q)->f114);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(((struct Obj03362 *)q)->f10);ZUKAN_DETAIL_COMMON_FreeBlendWork(((struct Obj03362 *)q)->fC);
    func_02030EAC(*(struct Node * *)&((struct Obj03362 *)q)->f0);ZUKAN_DETAIL_PROCSYS_FreeBuffer(first);
    func_02034A5C((int)ov206_id);func_02034A5C((int)ov067_id);return 1;
}

/*
 * 2026-10-05 (wD8 lane04): EXACT. The three "ov093" callees are in ov206 (matched there, co-resident with
 *   ov208 as in the matched siblings 021BEA04/021BEA90); the region token on their symbols lines is ov206.
 * 2026-10-05 (D5-03): MATCH. Byte-correct except the five calls to the ov093 callees 0x021B9E68,
 *   0x021BA7C8, 0x021BA374 (no witness label; ov093 below 0x021D4000, pengy). Fixes: the colour loop
 *   calls are func_02040618(i, 0, 0) and (i, 3, 0) (the draft passed i; the image keeps the 0 in r7, which
 *   is why ctx left r7), the first 9E68 call passes (2, 0, 1), locals v54 before v50 before w, the
 *   021BDAD0 test written `!= 2` first, and case 4 writes `*state = 5` in both arms.
 * 2026-10-04 (wD2 lane19): also tried ctx as a one-field struct by value and as u32 with casts: no change (frame 0x74/0x78 vs 0x70,
 *   ctx still in r7). Residue unchanged: image stores ctx back to [sp,#0x88] at entry and keeps state at [sp,#0x34], r7 free.
 * 2026-10-05 (wave D4 lane 02): frame layout check: image has v40 at sp+0x40, v44 0x44, w 0x48, v50 0x50,
 *   v54 0x54, tbl 0x58 (frame 0x70). Ours puts two spilled constant temps (0x17+0xfd and 0xf5+0x27, the
 *   msg field offsets) at 0x40/0x44 because ctx holds r7, so everything shifts by 8 (frame 0x78). Tried:
 *   both state and ctx `*volatile` (882 bytes, worse). Root residue is still ctx kept in r7 instead of its
 *   home slot. Also blocked: func_021B9E68, func_021BA7C8, func_021BA374 have no label (ov093 low, pengy).
 * 2026-10-02 (lane C2-01): control flow, callees and frame layout recovered (tbl[6] at sp+0x58 gives the 0x70 frame);
 * the six-state task body is complete. Still DIFF in register allocation: the image keeps the stack argument ctx in
 * its home slot [sp,#0x88] (reloaded at every use, stored back once at entry) and state in [sp,#0x34], leaving r7
 * free for hoisted constants (0x17 and 0xf5 bases in the font/message setup). Here ctx lands in r7 and the setup
 * spills those constants. Tried: int *volatile ctx (state then takes r7).
 * Also unresolved: func_021B9E68, func_021BA7C8, func_021BA374 (ov093 below 0x021D4000, not ours).
 */
int ZUKAN_DETAIL_INFO_Main(void *unused, int *state, struct Ov208Heap *h, struct Ov208Scn *p, int *ctx)
{
    void *scn = (void *)ZUKAN_DETAIL_COMMON_GetWorkPtr(ctx);
    void *icon = (void *)ZUKAN_DETAIL_COMMON_GetCursorValue((char *)ctx);
    int v40;
    int v44;
    u32 v54;
    u32 v50;
    u16 w[4];
    u32 tbl[6];
    u8 i;
    int t;
    switch (*state) {
    case 0:
        *state = 1;
        p->font = GF_FONT_Create(0x17, 0, 1, 0, h->heap);
        p->msg0 = func_02045B38(1, 2, 0x104, h->heap);
        p->msg1 = func_02045B38(1, 2, 0xf5, h->heap);
        p->msg2 = func_02045B38(1, 2, 0x10c, h->heap);
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                func_02040618(i, 0, 0);
                func_02040618(i, 3, 0);
                func_020414AC(i);
            }
        }
        if (func_021BDAD0(scn) != 2) {
            func_021BDAAC(scn, 0, 0, func_021BC3BC(ctx) > 1);
            func_021BDAD4(scn, 0);
        } else {
            func_021BDBB8(scn, 0);
        }
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scn, 0);
        ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(scn, GAME_DATA_CheckSaveFlag(ZUKAN_DETAIL_COMMON_GetSource(ctx), 0x11));
        if (func_021BE840(icon) != 2) {
            func_021BE82C(icon, 0);
            func_021BE844(icon);
        }
        ZUKAN_DETAIL_INFO_CreateLanguageButtons((u16 *)h, (char *)p, (int)ctx);
        t = (int)ZUKAN_SAVE_GetFromGameData((void *)ZUKAN_DETAIL_COMMON_GetSource(ctx));
        v40 = ZUKAN_DETAIL_GRAPHIC_Reset3dState((char *)ZUKAN_DETAIL_COMMON_GetDisplay(ctx));
        v44 = ZUKAN_SAVE_GetViewMode((void *)t);
        ZUKAN_DETAIL_INFO_GetPanelParams((const u16 *)h, (u8 *)p, (int *)ctx, &w[3], &w[2], &w[1], &w[0], &v54, &v50, tbl);
        p->f4 = func_021B9E68(h->heap, w[3], w[2], w[1], w[0], v54, v44, v50, 2, 0, 1, v40, (u32)p->font, ZUKAN_DETAIL_COMMON_GetGraphics(ctx), (u32)p->msg0, (u32)p->msg1, (u32)p->msg2);
        p->f8 = func_021B9E68(h->heap, w[3], w[2], w[1], w[0], v54, v44, v50, 2, 1, 1, v40, (u32)p->font, ZUKAN_DETAIL_COMMON_GetGraphics(ctx), (u32)p->msg0, (u32)p->msg1, (u32)p->msg2);
        func_021BA7C8(p->f8);
        ZUKAN_DETAIL_INFO_ResetButtons((int)h, (char *)p, (int)ctx, (int *)tbl);
        ZUKAN_DETAIL_INFO_LoadHighlightPalettes((u16 *)h, (u8 *)p, ctx);
        ZUKAN_DETAIL_INFO_StartHighlightBlink(h, (int *)p, ctx);
        break;
    case 1:
        *state = 2;
        func_021BC4D8(p->fc);
        func_021BC4D8(p->f10);
        break;
    case 2:
        if (func_021BC4C8(p->fc) == 0 && func_021BDAD0(scn) == 2 && func_021BE840(icon) == 2) {
            func_021BDBA0(scn);
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scn, 1);
            *state = 3;
        }
        break;
    case 3:
        if (p->f14 != 0) {
            *state = 4;
            func_021BC4E4(p->fc);
            func_021BC4E4(p->f10);
            func_021BE854(icon);
            if (p->f14 == 2)
                ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(scn, 0);
        } else if (p->f18 != 0) {
            if (ZUKAN_DETAIL_INFO_HandleTouchLanguageButton(h, (struct S_021BEFA0 *)((struct Ov208AreaState *)p), ctx) == 0)
                ZUKAN_DETAIL_INFO_HandleKeyLanguageSelect(h, (char *)p, (int)ctx);
        }
        break;
    case 4:
        if (func_021BC4C8(p->fc) == 0 && func_021BC4C8(p->f10) == 0 && func_021BE840(icon) == 0) {
            if (p->f14 == 2) {
                if (func_021BDAD0(scn) == 0)
                    *state = 5;
            } else {
                *state = 5;
            }
        }
        break;
    case 5:
        return 1;
    }
    if (*state >= 2) {
        ZUKAN_DETAIL_INFO_UpdateButtonPressAnim(h, (char *)p, (int)ctx);
        func_021BA374(p->f4);
        func_021BA374(p->f8);
        if (p->f94 == 6)
            ZUKAN_DETAIL_INFO_UpdateHighlightBlink(h, p, ctx);
    }
    func_021BC46C(p->fc, p->f10);
    return 0;
}

void ZUKAN_DETAIL_INFO_HandleKeyEvent(void *a0, void *a1, void *heap, struct S_021BEE70 *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = ZUKAN_DETAIL_COMMON_GetWorkPtr(obj);
    flag = 0;
    switch (key) {
    case 15:
        break;
    case 10: case 11: case 12: case 13: case 14: case 16: case 17: case 18:
        st->f18 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 7: case 8: case 9:
        flag = 1;
        st->f18 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj);
        ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies((char *)obj);
        if (old != ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj)) {
            ZUKAN_DETAIL_INFO_RefreshLanguagePanel(heap, (char *)st, obj);
        }
        break;
    }
    case 13: {
        u16 old = ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj);
        ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies((struct Ov208Cur *)obj);
        if (old != ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj)) {
            ZUKAN_DETAIL_INFO_RefreshLanguagePanel(heap, (char *)st, obj);
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->f14 = 2;
        return;
    case 7: case 8: case 9:
        st->f14 = 1;
        return;
    case 3:
        func_021BDBA0((void *)sc);
        return;
    case 4:
        func_021BDBA0((void *)sc);
        return;
    case 5:
        GAME_DATA_SetSaveFlag((void *)ZUKAN_DETAIL_COMMON_GetSource(obj), 0x11, ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive((char *)sc));
        func_021BDBA0((void *)sc);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0((void *)sc);
        }
        break;
    }
}

void ZUKAN_DETAIL_INFO_NoOp(void *p)
{
}

/*
 * note (2026-10-05, integrator): EXACT. The rect bytes are read through a byte pointer with the offset in a local (k = 0x20, c[k] .. c[k + 3]), as in ov208 021C6760; the byte loads then come before x.
 * 2026-10-04 (D2-16): also tried positive forms `x0 <= x && x < x0+w` (13 bytes out, shape changes) and `x0 > x` with u32 or int casts and
 * no locals (13 to 15 bytes out). With `x0 > x` the compare order is right but x0 lands in r0 and x in r1 (the image has x0 in r1);
 * with `x < x0` the registers are right and the compare order flips. The residue is one register colour pair.
 * note:     2026-10-04 (D1-08): f2c store fixed by raw `*(u32 *)((u8 *)st + st->cur * 0x14 + 0x2c) = 1`. Now 4 bytes: the two
 *            bounds tests are `cmp x0,x; bhi` in the image (x0 in r1, x in r0) and `cmp x,x0; blo` here (same registers). Writing
 *            `e->x0 > x` instead flips the registers (x0 in r0) but keeps the compare order; neither gives the image.
 * note:     2026-10-02 lane C2-02: two compare directions (image: cmp x0,x then bhi) and the f2c store constant order differ; tried x0<=x, !(x0>x), locals.
 *
 * 2026-10-05 (D4-18): still 4 bytes. Tried: positive form x >= x0 && x < x0 + w (4 bytes, same as now), !(e->x0 > x || ...) (13 bytes: x0 lands in r0), int-cast compares (17 bytes, bgt). The compare order of the image needs x0 in r1 with the unsigned-greater test; every spelling that gives that order puts x0 in r0.
 */
int ZUKAN_DETAIL_INFO_HandleTouchLanguageButton(void *a0, struct S_021BEFA0 *st, int *obj)
{
    int sc;
    int res;
    u32 x;
    u32 y;
    u8 i;
    struct E *e;
    u8 *c;
    int k;

    sc = ZUKAN_DETAIL_COMMON_GetWorkPtr(obj);
    res = 0;
    if (st->cur == 6 && TOUCHPANEL_GetPointTrg(&x, &y) != 0) {
        for (i = 0; i < 6; i++) {
            e = (struct E *)((u8 *)st + i * 0x14);
            c = (u8 *)e;
            k = 0x20;
            if (CLACT_GetActorDrawEnable((struct Obj *)e->h1c) != 0
                && (u32)c[k] <= x && x < (u32)c[k] + c[k + 2]
                && (u32)c[k + 1] <= y && y < (u32)c[k + 1] + c[k + 3]) {
                if (st->prev == i) break;
                st->cur = i;
                res = 1;
                break;
            }
        }
    }
    if (res != 0) {
        ov208_func_021BF280(a0, (char *)st, obj, st->cur);
        *(u32 *)((u8 *)st + st->cur * 0x14 + 0x2c) = 1;
        e = (struct E *)((u8 *)st + st->cur * 0x14);
        CLACT_SetActorAnimSeq((struct Obj *)e->h1c, e->f26);
        GFL_USE_PlaySeDefaultVolume(0x54a);
        func_020355D8(1);
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled((void *)sc, 0);
    }
    return res;
}

int ZUKAN_DETAIL_INFO_HandleKeyLanguageSelect(void *first,char *p,int key)
{
    void *scene;
    int changed;
    u32 buttons,press;
    u8 i,next;
    scene=(void *)ZUKAN_DETAIL_COMMON_GetWorkPtr((int *)key);
    changed=0;
    if(((struct Obj00442 *)p)->f94==6) {
        buttons=KEY_GetRepeat();
        press=KEY_GetTrg();
        if(((struct Obj00442 *)p)->f98==6) {
            if((buttons&0x300)||(press&1)) {
                for(i=0;i<6;i++) {
                    if(CLACT_GetActorDrawEnable(*(struct Obj **)((u32)p+(u32)i*20+0x1c))!=0) {
                        ((struct Obj00442 *)p)->f94=i; changed=1; break;
                    }
                }
            }
        } else if((buttons&0x100)||(press&1)) {
            for(i=1;i<6;i++) {
                next=(((struct Obj00442 *)p)->f98+i)%6;
                if(CLACT_GetActorDrawEnable(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    ((struct Obj00442 *)p)->f94=next; changed=1; break;
                }
            }
        } else if(buttons&0x200) {
            for(i=1;i<6;i++) {
                next=(((struct Obj00442 *)p)->f98+6-i)%6;
                if(CLACT_GetActorDrawEnable(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    ((struct Obj00442 *)p)->f94=next; changed=1; break;
                }
            }
        }
    }
    if(changed!=0) {
        ZUKAN_DETAIL_INFO_SelectLanguageButton(first,p,(void *)key,((struct Obj00442 *)p)->f94);
        *(u32 *)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x2c)=1;
        CLACT_SetActorAnimSeq(*(struct Obj **)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x1c),*(u16 *)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x26));
        GFL_USE_PlaySeDefaultVolume(0x54a);
        func_020355D8(0);
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled((void *)((int)scene), 0);
    }
    return changed;
}

/*
 * matching: initialize the flag after the output-producing call to keep its zero-cost schedule.
 * Third helper arguments are explicitly live in the original caller.
 */
void ZUKAN_DETAIL_INFO_RefreshLanguagePanel(void *first,char *q,void *third)
{
    struct Params p;
    int okay,index;
    ZUKAN_DETAIL_INFO_GetPanelParams(first,(u8 *)q,(int *)third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
    okay=1;
    func_021BA550(((struct Obj00442 *)q)->f4,p.d,p.c,p.b,p.a,p.y,p.x);
    index=((struct Obj00442 *)q)->f98;
    if(index!=6) {
        if(p.arr[index]!=0) okay=0;
        else {ZUKAN_DETAIL_INFO_ClearButtonHighlight((int)first, q, (unsigned)third);((struct Obj00442 *)q)->f98=6;}
    }
    if(okay) func_021BA7C8(((struct Obj00442 *)q)->f8);
    else func_021BA6B0(((struct Obj00442 *)q)->f8,p.d,p.c,p.b,p.a,p.y,p.x,((struct Obj00442 *)q)->f98);
    ZUKAN_DETAIL_INFO_ResetButtons((int)first,q,(int)third,(int *)p.arr);
}

void ZUKAN_DETAIL_INFO_SelectLanguageButton(void *first,char *q,void *third,int next)
{
    struct Params p;
    int current=((struct Obj00442 *)q)->f98;
    if(current!=next) {
        if(current==6) {
            ZUKAN_DETAIL_INFO_GetPanelParams(first,(u8 *)q,(int *)third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
            func_021BA6B0(((struct Obj00442 *)q)->f8,p.d,p.c,p.b,p.a,p.y,p.x,next);
            func_021BA814(((struct Obj00442 *)q)->f8);
        } else func_021BA64C(((struct Obj00442 *)q)->f8,next);
        ZUKAN_DETAIL_INFO_ClearButtonHighlight((int)first, q, (unsigned)third);((struct Obj00442 *)q)->f98=next;
        ZUKAN_DETAIL_INFO_StartHighlightBlink(first,(int *)q,third);
    }
}

void ZUKAN_DETAIL_INFO_CreateLanguageButtons(u16 *heap, char *p, int key)
{
    struct Pos_021BD574 pos;
    void *scene;
    int owner;
    void *arc;
    enum Index i;
    u16 flag;
    scene = (void *)ZUKAN_DETAIL_COMMON_GetWorkPtr((int *)key);
    owner = ZUKAN_DETAIL_GRAPHIC_Reset3dState((char *)ZUKAN_DETAIL_COMMON_GetDisplay((int *)key));
    i = 0;
    arc = func_020490F4(0x9f, *heap);
    ((struct Obj05538 *)p)->f9C = ZUKAN_DETAIL_TOUCHBAR_GetCurrentSlot(scene);
    ((struct Obj05538 *)p)->fA0 = CLACT_RegisterCharacter(arc, 0xd, 0, 0, *heap);
    ((struct Obj05538 *)p)->fA4 = CLACT_RegisterCellAnim(arc, 0x1b, 0x2c, *heap);
    ARC_TOOL_DeleteHandle(arc);
    flag = (u16)i;
    do {
        char *q;
        const u8 *t;
        MI_CpuFill8(&pos, 0, 8);
        t = d_021C851C + i * 9;
        q = p + i * 20;
        q[0x20] = t[2];
        q[0x21] = t[3];
        q[0x22] = t[4];
        q[0x23] = t[5];
        ((struct Obj02254 *)q)->f24 = t[6];
        ((struct Obj02254 *)q)->f26 = t[7];
        q[0x28] = t[8];
        ((struct Obj02254 *)q)->f2C = 0;
        pos.x = t[0];
        pos.y = t[1];
        pos.z = ((struct Obj02254 *)q)->f24;
        ((struct Obj02254 *)q)->f1C = (u32)CLACT_CreateActor(owner, ((struct Obj05538 *)p)->fA0, ((struct Obj05538 *)p)->f9C, ((struct Obj05538 *)p)->fA4, &pos, flag, *heap);
        CLACT_SetActorAutoAnim((struct Obj *)((struct Obj02254 *)q)->f1C, 1);
        CLACT_SetActorObjMode((struct Actor *)(((struct Obj02254 *)q)->f1C), 1);
        i = (u8)(i + 1);
    } while ((u32)i < 6);
}

/*
 * Releases the sixth 0x14-byte element handle at +0x1C and the two at +0xA0 and +0xA4.
 */
void ZUKAN_DETAIL_INFO_DeleteLanguageButtons(int unused, char *q, u32 a2)
{
    unsigned char i;

    for (i = 0; i < 6; i++)
        CLACT_DeleteActor((struct Obj *)(*(int *)(q + i * 0x14 + 0x1c)));
    CLACT_ReleaseCharacter(((struct Obj12120 *)q)->fA0);
    CLACT_ReleaseCellAnim(((struct Obj12120 *)q)->fA4);
}

/*
 * Byte-based state indexing preserves the shared 20-byte stride; u32 indexing changes it to shift/add.
 */
void ZUKAN_DETAIL_INFO_UpdateButtonPressAnim(void *unused, char *p, int key)
{
    void *scene = (void *)ZUKAN_DETAIL_COMMON_GetWorkPtr((int *)key);
    if (((struct Obj10901 *)p)->f94 != 6) {
        u8 i = ((struct Obj10901 *)p)->f94;
        char *states = p + 0x2c;
        switch (*(unsigned *)(states + i * 20)) {
        case 0: break;
        case 1: *(unsigned *)(states + i * 20) = 2; break;
        case 2:
            if (CLACT_IsActorAnimActive(*(struct Actor **)(p + i * 20 + 0x1c)) == 0)
                *(unsigned *)(states + i * 20) = 3;
            break;
        case 3:
            CLACT_SetActorAnimSeq(*(struct Obj **)(p + i * 20 + 0x1c), *(u16 *)(p + i * 20 + 0x24));
            *(unsigned *)(states + i * 20) = 0;
            ((struct Obj10901 *)p)->f94 = 6;
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 1);
            break;
        }
    }
}

void ZUKAN_DETAIL_INFO_ResetButtons(int unused, char *q, int c, int *tbl)
{
    unsigned char i;

    for (i = 0; i < 6; i++) {
        CLACT_SetActorDrawEnable((struct Obj *)*(int *)(q + i * 0x14 + 0x1c), tbl[i]);
        *(int *)(q + i * 0x14 + 0x2c) = 0;
        CLACT_SetActorAnimSeq((struct Obj *)(*(int *)(q + i * 0x14 + 0x1c)), *(unsigned short *)(q + i * 0x14 + 0x24));
    }
    ((struct Obj18262 *)q)->f94 = 6;
}

/*
 * Species local and CC40/CED4 species arguments are u32: this caller has no u16 truncation before either call.
 */
void ZUKAN_DETAIL_INFO_GetPanelParams(const u16 *heap, u8 *p, int *key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7)
{
    u32 values[6];
    u32 a, b, c, special, value;
    struct Blk37 *ctx;
    u32 id;
    u8 i;
    ctx = ZUKAN_SAVE_GetFromGameData((void *)ZUKAN_DETAIL_COMMON_GetSource(key));
    id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
    special = 0;
    ZUKAN_SAVE_GetViewGenderAndForm((u8 *)ctx, id, &b, &c, &a, *heap);
    if (id == 327) special = ZUKAN_SAVE_GetSpindaPersonality(ctx, special);
    value = ZUKAN_SAVE_IsCaught(ctx, id);
    for (i = 0; i < 6; i++) values[i] = ZUKAN_SAVE_HasLanguageFlag(ctx, id, p[i * 20 + 0x28]);
    *out1 = id;
    *out2 = a;
    *out3 = b;
    *out4 = c;
    *out5 = special;
    *out6 = value;
    for (i = 0; i < 6; i++) out7[i] = values[i];
}

void ZUKAN_DETAIL_INFO_LoadHighlightPalettes(u16 *heap, u8 *p, int *ctx)
{
    struct Ov208Pltt *pltt;
    u32 file;
    u8 *data;
    file = (u32)func_02049F34(159, 3, (u32)(&pltt), *heap);
    data = pltt->data;
    MI_CpuCopy8(data + 0x20, p + 0xa8, 32);
    MI_CpuCopy8(data + 0x60, p + 0xc8, 32);
    func_020307B0((void *)file);
    ((struct Obj25493 *)p)->f108 = 0;
    MI_CpuCopy8(p + 0xa8, p + 0xe8, 32);
    func_02061CA4((void *)14, 192, (u32)(p + 0xe8), 32);
}

void ZUKAN_DETAIL_INFO_NoOpHighlight(int unused0, char *unused1, unsigned unused2)
{
}

/*
 * Zeroes word 0x42 and sets word 0x43 when word 0x26 is not 6.
 */
void ZUKAN_DETAIL_INFO_StartHighlightBlink(struct Ov208Heap *unused, int *p, int *ctx)
{
    if (p[0x26] == 6)
        return;
    p[0x42] = 0;
    p[0x43] = 1;
}

/*
 * Frees the 0x14-byte record at the index held in +0x98.
 */
void ZUKAN_DETAIL_INFO_ClearButtonHighlight(int unused, char *p, unsigned unused2)
{
    int i = ((struct Obj00442 *)p)->f98;

    if (i == 6)
        return;
    CLACT_SetActorPaletteOffset((struct Obj *)(*(int *)(p + i * 0x14 + 0x1c)), 0, 0);
    ((struct Obj00442 *)p)->f10C = 0;
}

/*
 * note: 2026-10-05 (D5-03): closed by u8 channel locals for colour A, the store as
 *   r | g << 5 | b << 10 (GX_RGB order) with the three lerps inline, and the f108 wrap
 *   written on the field directly (no x/y locals).
 */
void ZUKAN_DETAIL_INFO_UpdateHighlightBlink(struct Ov208Heap *a0, struct Ov208Scn *e, int *ctx)
{
    if (e->f10c != 0) {
        int v = e->f98;

        if (v != 6)
            CLACT_SetActorPaletteOffset((struct Obj *)(*(int *)((char *)e + v * 0x14 + 0x1c)), 2, 0);
        e->f10c = 0;
    }

    if (e->f108 + 0x400 >= 0x10000)
        e->f108 = e->f108 + 0x400 - 0x10000;
    else
        e->f108 = e->f108 + 0x400;

    {
        unsigned char i;
        int t = e->f108;
        short ratio;

        t = ((t >> 4) << 1) + 1;
        ratio = (FX_SinCosTable_[t] + 0x1000) / 2;

        for (i = 0; i < 0x10; i++) {
            unsigned short A = e->srcA[i];
            unsigned short B = e->srcB[i];
            unsigned char g = (A & 0x3e0) >> 5;
            unsigned char r = A & 0x1f;
            unsigned char b = (A & 0x7c00) >> 10;

            e->dst[i] = (unsigned short)((unsigned char)(r + ((ratio * ((unsigned char)(B & 0x1f) - r)) >> 12))
                | ((unsigned char)(g + ((ratio * ((unsigned char)((B & 0x3e0) >> 5) - g)) >> 12)) << 5)
                | ((unsigned char)(b + ((ratio * ((unsigned char)((B & 0x7c00) >> 10) - b)) >> 12)) << 10));
        }

        func_02061CA4((void *)0xe, 0xc0, (int)e->dst, 0x20);
    }
}
