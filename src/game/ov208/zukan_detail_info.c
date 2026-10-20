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
 *   GFL_HEAP_Free 0x020307B0  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   CLACT_RegisterCharacter        0x0204A6C8  arm
 *   CLACT_RegisterCellAnim        0x0204AF28  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   ov067_id 0x00000043 data
 *   ov206_id 0x000000CE data
 *   ZUKAN_DETAIL_PROCSYS_AllocBuffer 0x021BC32C thumb
 *   ZUKAN_DETAIL_COMMON_AllocBlendWork 0x021BC448 thumb
 *   ZUKAN_DETAIL_COMMON_InitBrightnessTarget 0x021BC518 thumb
 *   ZUKAN_DETAIL_COMMON_SetBrightnessNone 0x021BC508 thumb
 *   ZUKAN_INFO_Delete 0x021BA2CC thumb ov206
 *   ZUKAN_DETAIL_COMMON_FreeBlendWork 0x021BC464 thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_FreeBuffer 0x021BC34C thumb ov208
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr 0x021BC3B4 thumb
 *   ZUKAN_DETAIL_COMMON_GetHeadbar 0x021BC3B8 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetMode 0x021BDAD0 thumb
 *   ZUKAN_DETAIL_COMMON_GetEntryCount 0x021BC3BC thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetMode 0x021BDAAC thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetEnabled 0x021BDAD4 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind 0x021BDBB8 thumb
 *   ZUKAN_DETAIL_COMMON_GetSource 0x021BC3A4 thumb
 *   GAME_DATA_ContainsRecentId 0x02012BF8 thumb
 *   ZUKAN_DETAIL_HEADBAR_GetIconKind 0x021BE840 thumb
 *   ZUKAN_DETAIL_HEADBAR_SetIconKind 0x021BE82C thumb
 *   ZUKAN_DETAIL_HEADBAR_SetIconSpecies 0x021BE844 thumb
 *   ZUKAN_DETAIL_COMMON_GetDisplay 0x021BC3A8 thumb
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   ZUKAN_DETAIL_COMMON_GetGraphics 0x021BC3B0 thumb
 *   ZUKAN_INFO_Create 0x021B9E68 thumb ov206
 *   ZUKAN_INFO_Show 0x021BA7C8 thumb ov206
 *   ZUKAN_DETAIL_COMMON_StartBlendIn 0x021BC4D8 thumb
 *   ZUKAN_DETAIL_COMMON_IsBlendBusy 0x021BC4C8 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_ClearButtonState 0x021BDBA0 thumb
 *   ZUKAN_DETAIL_COMMON_StartBlendOut 0x021BC4E4 thumb
 *   ZUKAN_DETAIL_HEADBAR_SetIconForm 0x021BE854 thumb
 *   ZUKAN_INFO_Update 0x021BA374 thumb ov206
 *   ZUKAN_DETAIL_COMMON_UpdateBlendFades 0x021BC46C thumb
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry  0x021BC3C0  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies  0x021BC3CC  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies  0x021BC40C  thumb  ov208
 *   GAME_DATA_SetRecentId  0x02012BE0  thumb
 *   ZUKAN_DETAIL_INFO_SelectLanguageButton  0x021BF280  thumb  ov208
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   ZUKAN_INFO_SetPokemon 0x021BA550 thumb ov206
 *   ZUKAN_INFO_SetPokemonPage 0x021BA6B0 thumb ov206
 *   ZUKAN_INFO_Hide 0x021BA814 thumb ov206
 *   ZUKAN_INFO_ShowPage 0x021BA64C thumb ov206
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
#include "../arm9/game_data.h"
#include "zukan_detail_types.h"
#include "zukan_detail_shared_types.h"


#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/arc_tool.h"

#include "../arm9/tcb_list.h"

#include "../arm9/gfl_use.h"


#include "../arm9/bg_sys.h"

#include "../arm9/msgdata.h"


void ZUKAN_DETAIL_INFO_SetHeapId(u16 *p, u16 v);

void ZUKAN_DETAIL_INFO_SetHeapId(u16 *p, u16 v)
{
    *p = v;
}

extern void *ZUKAN_SAVE_GetFromGameData(void *a);

#include "../arm9/gf_font.h"


struct Ov208Heap;

/*
 * One language button record of the info screen, 0x14 bytes. actor is the
 * CLACT actor, x/y/w/h its tile rectangle, idleAnim/pressedAnim the two halfwords copied
 * from the layout table (idle and pressed animation), language the language
 * flag index and state the press animation step.
 */
struct Ov208InfoButton {
    void *actor;               /* 0x00 */
    unsigned char x;           /* 0x04 */
    unsigned char y;           /* 0x05 */
    unsigned char w;           /* 0x06 */
    unsigned char h;           /* 0x07 */
    unsigned short idleAnim;        /* 0x08 */
    unsigned short pressedAnim;        /* 0x0a */
    unsigned char language;         /* 0x0c */
    unsigned char pad0d[3];
    unsigned int state;        /* 0x10 */
};

/*
 * Work object of the Pokedex detail info screen, 0x120 bytes, allocated by
 * ZUKAN_DETAIL_INFO_Init. task is the vblank task, speciesInfo/langInfo the two
 * ZUKAN_INFO panes (default page and language page), blendMain/blendSub the two
 * blend records, mode the leave request and keyFlag the key-input flag. buttons
 * holds the six language buttons, pressedButton/currentButton the pressed and
 * current button index (6 = none), palRes/charRes/cellRes the language icon
 * resources, srcA/srcB the two highlight palettes blended into dst by
 * blinkPhase, blinkRestart the blink reset flag and font/msg0..msg2 the font and
 * message banks.
 */
struct Ov208InfoWork {
    void *task;                 /* 0x00 */
    void *speciesInfo;                   /* 0x04 */
    void *langInfo;                   /* 0x08 */
    struct Ov208Blend *blendMain;      /* 0x0C */
    struct Ov208Blend *blendSub;     /* 0x10 */
    int mode;                    /* 0x14 */
    int keyFlag;                    /* 0x18 */
    struct Ov208InfoButton buttons[6]; /* 0x1C */
    int pressedButton;                    /* 0x94 */
    int currentButton;                    /* 0x98 */
    unsigned int palRes;        /* 0x9C */
    unsigned int charRes;       /* 0xA0 */
    unsigned int cellRes;       /* 0xA4 */
    unsigned short srcA[0x10];  /* 0xA8 */
    unsigned short srcB[0x10];  /* 0xC8 */
    unsigned short dst[0x10];   /* 0xE8 */
    int blinkPhase;                   /* 0x108 */
    int blinkRestart;                   /* 0x10C */
    void *font;                 /* 0x110 */
    void *msg0;                 /* 0x114 */
    void *msg1;                 /* 0x118 */
    void *msg2;                 /* 0x11C */
};

struct Ov208Heap { u16 heap; };

struct ZukanDetailInfoLangSlot {
    u8 pad0[0x1c];
    int actor;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
    u8 pad24[2];
    u16 pressedAnim;
    u8 pad28[4];
    u32 state;
    u8 pad30[4];
};

struct Params {u16 a,b,c,d; unsigned x,y,arr[6];};

enum Index { INDEX_ZERO = 0 };

struct ZukanPos { u16 x, y, z, pad; };

#include "../arm9/mi_memory.h"


struct ClactActor;
struct Ov208Scene;
struct ZukanSave;
struct ZukanInfo;
struct GameData;
extern s32 CLACT_RegisterCharacter(void *archive, u32 file_idx, u32 compressed, u32 vram_mode, u16 heap_id);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern struct Obj *CLACT_CreateActor(u32 owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);

extern void CLACT_SetActorAutoAnim(struct ClactActor *actor, u32 enable);

extern void CLACT_DeleteActor(struct ClactActor *actor);

extern u32 CLACT_GetActorDrawEnable(struct ClactActor *actor);

#include "../arm9/touchpanel.h"

#include "../arm9/ui.h"

#include "../arm9/key.h"

extern u32 CLACT_IsActorAnimActive(struct ClactActor *actor);

extern void CLACT_SetActorDrawEnable(struct ClactActor *actor, u32 value);

extern void CLACT_SetActorAnimSeq(struct ClactActor *actor, u16 value);



#include "../arm9/arc_util.h"


extern void CLACT_SetActorPaletteOffset(struct ClactActor *actor, u32 offset, u32 pltt_op);

#include "../arm9/nns_gfd_vram_transfer.h"

#include "../arm9/gf_overlay.h"

#include "zukan_detail_procsys.h"

#include "zukan_detail_common.h"



extern void ZUKAN_INFO_Delete(char *);




extern int ZUKAN_DETAIL_TOUCHBAR_GetMode(struct Ov208Scene *p);

extern void ZUKAN_DETAIL_TOUCHBAR_SetMode(struct Ov208Scene *p, u32 mode, u32 kind, u32 flag);

extern void ZUKAN_DETAIL_TOUCHBAR_SetEnabled(struct Ov208Scene *p, int scrollIdx);

extern void ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(struct Ov208Scene *p, u32 kind);


#include "zukan_detail_headbar.h"



extern u32 ZUKAN_SAVE_GetViewMode(struct ZukanSave *pZukan);

extern void *ZUKAN_INFO_Create(u32 heap, u16 species, u16 form, u16 gender, u16 rare, u32 personalParam, u32 formTableNeeded, u32 showCurrent, u32 mode, u32 femaleFlag, u8 a10, u32 a11, u32 a12, void *a13, u32 a14, u32 a15, u32 a16);

extern void ZUKAN_INFO_Show(struct ZukanInfo *p);



extern void ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(struct Ov208Scene *p);



extern void ZUKAN_INFO_Update(char *p);


extern void GAME_DATA_SetRecentId(struct GameData *gd, u32 id, u32 on);


extern void ZUKAN_INFO_SetPokemon(char *p, u16 species, u16 form, u16 gender, u16 rare, int personalParam, int showCurrent);

extern void ZUKAN_INFO_SetPokemonPage(char *p, u16 species, u16 form, u16 gender, u16 rare, int personalParam, int showCurrent, int page);

extern void ZUKAN_INFO_Hide(struct ZukanInfo *p);

extern void ZUKAN_INFO_ShowPage(char *p, int mode);

extern void CLACT_SetActorObjMode(struct ClactActor *actor, u32 value);

extern void ZUKAN_SAVE_GetViewGenderAndForm(struct ZukanSave *, u32, u32 *, u32 *, u32 *, u16);

extern u32 ZUKAN_SAVE_GetSpindaPersonality(struct ZukanSave *pZukan, u32 which);

extern u32 ZUKAN_SAVE_IsCaught(struct ZukanSave *, u32);

extern u32 ZUKAN_SAVE_HasLanguageFlag(struct ZukanSave *pZukan, u32 species, u32 language);

#include "zukan_detail_graphic.h"

void ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(struct Ov208Scene *p, int v);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(struct Ov208Scene *p, int b);

int ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(char *p);

void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(struct Ov208Scene *p, u32 on);

int ZUKAN_DETAIL_TOUCHBAR_GetCurrentSlot(char *p);

int ZUKAN_DETAIL_INFO_Init(void *owner, int unused, u16 *heap);

int ZUKAN_DETAIL_INFO_Exit(char *first,unsigned unused,int owner,char *q,unsigned heap);

int ZUKAN_DETAIL_INFO_Main(void *unused, int *state, struct Ov208Heap *h, struct Ov208InfoWork *p, struct Ov208Ctx *ctx);

void ZUKAN_DETAIL_INFO_HandleKeyEvent(void *proc, void *seq, void *heap, struct Ov208InfoWork *st, struct Ov208Ctx *obj, int key);

void ZUKAN_DETAIL_INFO_NoOp(void *p);

int ZUKAN_DETAIL_INFO_HandleTouchLanguageButton(void *heap, struct Ov208InfoWork *st, struct Ov208Ctx *obj);

int ZUKAN_DETAIL_INFO_HandleKeyLanguageSelect(void *first,char *p,struct Ov208Ctx *key);

void ZUKAN_DETAIL_INFO_RefreshLanguagePanel(void *first,char *q,struct Ov208Ctx *third);

void ZUKAN_DETAIL_INFO_SelectLanguageButton(void *first,char *q,struct Ov208Ctx *third,int next);

void ZUKAN_DETAIL_INFO_CreateLanguageButtons(u16 *heap, char *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_INFO_DeleteLanguageButtons(int unused, char *q, u32 heap);

void ZUKAN_DETAIL_INFO_UpdateButtonPressAnim(void *unused, char *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_INFO_ResetButtons(int unused, char *q, struct Ov208Ctx *c, int *tbl);

void ZUKAN_DETAIL_INFO_GetPanelParams(const u16 *heap, u8 *p, struct Ov208Ctx *key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7);

void ZUKAN_DETAIL_INFO_LoadHighlightPalettes(u16 *heap, u8 *p, struct Ov208Ctx *ctx);

void ZUKAN_DETAIL_INFO_NoOpHighlight(int unused0, char *unused1, unsigned unused2);

void ZUKAN_DETAIL_INFO_StartHighlightBlink(struct Ov208Heap *unused, int *p, struct Ov208Ctx *ctx);

void ZUKAN_DETAIL_INFO_ClearButtonHighlight(int unused, char *p, unsigned unused2);

void ZUKAN_DETAIL_INFO_UpdateHighlightBlink(struct Ov208Heap *heap, struct Ov208InfoWork *e, struct Ov208Ctx *ctx);

extern s16 FX_SinCosTable_[];

extern const char ov067_id[];

extern const char ov206_id[];

extern const u8 d_021C851C[];

extern s16 FX_SinCosTable_[];

/*
 * 2026-10-04 (D2-16): callback ZUKAN_DETAIL_INFO_NoOp filed EXACT as src/matched/ov/ZUKAN_DETAIL_INFO_NoOp.c (empty void function, bx lr). Still MATCH only
 * because no shard witnesses it yet; the integrator manifest run should make this EXACT. Symbols line now carries the ov208 hint.
 * 2026-10-02: only ZUKAN_DETAIL_INFO_NoOp (task callback, no witness yet) blocks EXACT; bytes match.
 */
int ZUKAN_DETAIL_INFO_Init(void *owner, int unused, u16 *heap)
{
    struct Ov208InfoWork *s;
    GF_OVERLAY_Load((uptr)ov067_id);
    GF_OVERLAY_Load((uptr)ov206_id);
    s = ZUKAN_DETAIL_PROCSYS_AllocBuffer((struct Ov208Fsm *)owner, 0x120, *heap);
    MI_CpuFill8(s, 0, 0x120);
    s->task = (void *)GFL_USE_AddMainTask((void (*)(struct TcbTask *, void *))((uptr)ZUKAN_DETAIL_INFO_NoOp), (void *)((uptr)s), 1);
    s->pressedButton = 6;
    s->currentButton = 6;
    s->blinkRestart = 0;
    s->blendMain = ZUKAN_DETAIL_COMMON_AllocBlendWork(*heap);
    s->blendSub = ZUKAN_DETAIL_COMMON_AllocBlendWork(*heap);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget((struct Ov208Blend *)s->blendMain);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget((struct Ov208Blend *)s->blendSub);
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(0, (struct Ov208Blend *)s->blendMain);
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(1, (struct Ov208Blend *)s->blendSub);
    s->mode = 0;
    s->keyFlag = 1;
    return 1;
}

/*
 * matching: full-width stack argument reloads; small pool operands are overlay ID symbols.
 * Caller visibly supplies third arguments to helpers and a live r0 to BC464.
 */
int ZUKAN_DETAIL_INFO_Exit(char *first,unsigned unused,int owner,char *q,unsigned heap)
{
    ZUKAN_DETAIL_INFO_ClearButtonHighlight(owner,q,heap);ZUKAN_DETAIL_INFO_NoOpHighlight(owner,q,heap);
    ZUKAN_INFO_Delete((char *)((struct Ov208InfoWork *)q)->langInfo);ZUKAN_INFO_Delete((char *)((struct Ov208InfoWork *)q)->speciesInfo);
    ZUKAN_DETAIL_INFO_DeleteLanguageButtons(owner,q,heap);
    GF_FONT_Delete(((struct Ov208InfoWork *)q)->font);
    MSGDATA_Delete((struct MsgBank *)((struct Rec *)((struct Ov208InfoWork *)q)->msg2));
    MSGDATA_Delete((struct MsgBank *)((struct Rec *)((struct Ov208InfoWork *)q)->msg1));
    MSGDATA_Delete((struct MsgBank *)((struct Rec *)((struct Ov208InfoWork *)q)->msg0));
    ZUKAN_DETAIL_COMMON_FreeBlendWork((void *)(((struct Ov208InfoWork *)q)->blendSub));ZUKAN_DETAIL_COMMON_FreeBlendWork((void *)(((struct Ov208InfoWork *)q)->blendMain));
    TCB_DeleteTask((struct TcbTask *)((struct Node *)((struct Ov208InfoWork *)q)->task));ZUKAN_DETAIL_PROCSYS_FreeBuffer((char *)first);
    GF_OVERLAY_Unload((sptr)ov206_id);GF_OVERLAY_Unload((sptr)ov067_id);return 1;
}

/*
 * 2026-10-05 (wD8 lane04): EXACT. The three "ov093" callees are in ov206 (matched there, co-resident with
 *   ov208 as in the matched siblings 021BEA04/021BEA90); the region token on their symbols lines is ov206.
 * 2026-10-05 (D5-03): MATCH. Byte-correct except the five calls to the ov093 callees 0x021B9E68,
 *   0x021BA7C8, 0x021BA374 (no witness label; ov093 below 0x021D4000, pengy). Fixes: the colour loop
 *   calls are BG_SYS_ChangeScrollImmediate(i, 0, 0) and (i, 3, 0) (the draft passed i; the image keeps the 0 in r7, which
 *   is why ctx left r7), the first 9E68 call passes (2, 0, 1), locals v54 before v50 before w, the
 *   021BDAD0 test written `!= 2` first, and case 4 writes `*state = 5` in both arms.
 * 2026-10-04 (wD2 lane19): also tried ctx as a one-field struct by value and as u32 with casts: no change (frame 0x74/0x78 vs 0x70,
 *   ctx still in r7). Residue unchanged: image stores ctx back to [sp,#0x88] at entry and keeps state at [sp,#0x34], r7 free.
 * 2026-10-05 (wave D4 lane 02): frame layout check: image has v40 at sp+0x40, v44 0x44, w 0x48, v50 0x50,
 *   v54 0x54, tbl 0x58 (frame 0x70). Ours puts two spilled constant temps (0x17+0xfd and 0xf5+0x27, the
 *   msg field offsets) at 0x40/0x44 because ctx holds r7, so everything shifts by 8 (frame 0x78). Tried:
 *   both state and ctx `*volatile` (882 bytes, worse). Root residue is still ctx kept in r7 instead of its
 *   home slot. Also blocked: ZUKAN_INFO_Create, ZUKAN_INFO_Show, ZUKAN_INFO_Update have no label (ov093 low, pengy).
 * 2026-10-02 (lane C2-01): control flow, callees and frame layout recovered (tbl[6] at sp+0x58 gives the 0x70 frame);
 * the six-state task body is complete. Still DIFF in register allocation: the image keeps the stack argument ctx in
 * its home slot [sp,#0x88] (reloaded at every use, stored back once at entry) and state in [sp,#0x34], leaving r7
 * free for hoisted constants (0x17 and 0xf5 bases in the font/message setup). Here ctx lands in r7 and the setup
 * spills those constants. Tried: int *volatile ctx (state then takes r7).
 * Also unresolved: ZUKAN_INFO_Create, ZUKAN_INFO_Show, ZUKAN_INFO_Update (ov093 below 0x021D4000, not ours).
 */
int ZUKAN_DETAIL_INFO_Main(void *unused, int *state, struct Ov208Heap *h, struct Ov208InfoWork *p, struct Ov208Ctx *ctx)
{
    void *scn = ZUKAN_DETAIL_COMMON_GetWorkPtr(ctx);
    void *icon = ZUKAN_DETAIL_COMMON_GetHeadbar(ctx);
    int actorUnit;
    int viewMode;
    u32 personality;
    u32 caught;
    u16 w[4];
    u32 tbl[6];
    u8 i;
    void *t;
    switch (*state) {
    case 0:
        *state = 1;
        p->font = GF_FONT_Create(0x17, 0, 1, 0, h->heap);
        p->msg0 = MSGDATA_CreateFromArchive(1, 2, 0x104, h->heap);
        p->msg1 = MSGDATA_CreateFromArchive(1, 2, 0xf5, h->heap);
        p->msg2 = MSGDATA_CreateFromArchive(1, 2, 0x10c, h->heap);
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                BG_SYS_ChangeScrollImmediate(i, 0, 0);
                BG_SYS_ChangeScrollImmediate(i, 3, 0);
                BG_SYS_FreeSlot(i);
            }
        }
        if (ZUKAN_DETAIL_TOUCHBAR_GetMode(scn) != 2) {
            ZUKAN_DETAIL_TOUCHBAR_SetMode(scn, 0, 0, ZUKAN_DETAIL_COMMON_GetEntryCount(ctx) > 1);
            ZUKAN_DETAIL_TOUCHBAR_SetEnabled(scn, 0);
        } else {
            ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(scn, 0);
        }
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scn, 0);
        ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(scn, GAME_DATA_ContainsRecentId(ZUKAN_DETAIL_COMMON_GetSource(ctx), 0x11));
        if (ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) != 2) {
            ZUKAN_DETAIL_HEADBAR_SetIconKind(icon, 0);
            ZUKAN_DETAIL_HEADBAR_SetIconSpecies(icon);
        }
        ZUKAN_DETAIL_INFO_CreateLanguageButtons((u16 *)h, (char *)p, ctx);
        t = ZUKAN_SAVE_GetFromGameData(ZUKAN_DETAIL_COMMON_GetSource(ctx));
        actorUnit = ZUKAN_DETAIL_GRAPHIC_Reset3dState(ZUKAN_DETAIL_COMMON_GetDisplay(ctx));
        viewMode = ZUKAN_SAVE_GetViewMode(t);
        ZUKAN_DETAIL_INFO_GetPanelParams((const u16 *)h, (u8 *)p, ctx, &w[3], &w[2], &w[1], &w[0], &personality, &caught, tbl);
        p->speciesInfo = ZUKAN_INFO_Create(h->heap, w[3], w[2], w[1], w[0], personality, viewMode, caught, 2, 0, 1, actorUnit, (uptr)p->font, ZUKAN_DETAIL_COMMON_GetGraphics(ctx), (uptr)p->msg0, (uptr)p->msg1, (uptr)p->msg2);
        p->langInfo = ZUKAN_INFO_Create(h->heap, w[3], w[2], w[1], w[0], personality, viewMode, caught, 2, 1, 1, actorUnit, (uptr)p->font, ZUKAN_DETAIL_COMMON_GetGraphics(ctx), (uptr)p->msg0, (uptr)p->msg1, (uptr)p->msg2);
        ZUKAN_INFO_Show(p->langInfo);
        ZUKAN_DETAIL_INFO_ResetButtons((sptr)h, (char *)p, ctx, (int *)tbl);
        ZUKAN_DETAIL_INFO_LoadHighlightPalettes((u16 *)h, (u8 *)p, ctx);
        ZUKAN_DETAIL_INFO_StartHighlightBlink(h, (int *)p, ctx);
        break;
    case 1:
        *state = 2;
        ZUKAN_DETAIL_COMMON_StartBlendIn(p->blendMain);
        ZUKAN_DETAIL_COMMON_StartBlendIn(p->blendSub);
        break;
    case 2:
        if (ZUKAN_DETAIL_COMMON_IsBlendBusy(p->blendMain) == 0 && ZUKAN_DETAIL_TOUCHBAR_GetMode(scn) == 2 && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 2) {
            ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(scn);
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scn, 1);
            *state = 3;
        }
        break;
    case 3:
        if (p->mode != 0) {
            *state = 4;
            ZUKAN_DETAIL_COMMON_StartBlendOut(p->blendMain);
            ZUKAN_DETAIL_COMMON_StartBlendOut(p->blendSub);
            ZUKAN_DETAIL_HEADBAR_SetIconForm(icon);
            if (p->mode == 2)
                ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(scn, 0);
        } else if (p->keyFlag != 0) {
            if (ZUKAN_DETAIL_INFO_HandleTouchLanguageButton(h, (struct Ov208InfoWork *)((struct Ov208AreaState *)p), ctx) == 0)
                ZUKAN_DETAIL_INFO_HandleKeyLanguageSelect(h, (char *)p, ctx);
        }
        break;
    case 4:
        if (ZUKAN_DETAIL_COMMON_IsBlendBusy(p->blendMain) == 0 && ZUKAN_DETAIL_COMMON_IsBlendBusy(p->blendSub) == 0 && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 0) {
            if (p->mode == 2) {
                if (ZUKAN_DETAIL_TOUCHBAR_GetMode(scn) == 0)
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
        ZUKAN_DETAIL_INFO_UpdateButtonPressAnim(h, (char *)p, ctx);
        ZUKAN_INFO_Update(p->speciesInfo);
        ZUKAN_INFO_Update(p->langInfo);
        if (p->pressedButton == 6)
            ZUKAN_DETAIL_INFO_UpdateHighlightBlink(h, p, ctx);
    }
    ZUKAN_DETAIL_COMMON_UpdateBlendFades(p->blendMain, p->blendSub);
    return 0;
}

void ZUKAN_DETAIL_INFO_HandleKeyEvent(void *proc, void *seq, void *heap, struct Ov208InfoWork *st, struct Ov208Ctx *obj, int key)
{
    void *sc;
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
        st->keyFlag = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 7: case 8: case 9:
        flag = 1;
        st->keyFlag = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj);
        ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(obj);
        if (old != ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj)) {
            ZUKAN_DETAIL_INFO_RefreshLanguagePanel(heap, (char *)st, obj);
        }
        break;
    }
    case 13: {
        u16 old = ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj);
        ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies(obj);
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
        st->mode = 2;
        return;
    case 7: case 8: case 9:
        st->mode = 1;
        return;
    case 3:
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sc);
        return;
    case 4:
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sc);
        return;
    case 5:
        GAME_DATA_SetRecentId(ZUKAN_DETAIL_COMMON_GetSource(obj), 0x11, ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive((char *)sc));
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sc);
        return;
    default:
        if (flag != 0) {
            ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sc);
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
 * note:     2026-10-04 (D1-08): f2c store fixed by raw `*(u32 *)((u8 *)st + st->pressedButton * 0x14 + 0x2c) = 1`. Now 4 bytes: the two
 *            bounds tests are `cmp x0,x; bhi` in the image (x0 in r1, x in r0) and `cmp x,x0; blo` here (same registers). Writing
 *            `e->x > x` instead flips the registers (x0 in r0) but keeps the compare order; neither gives the image.
 * note:     2026-10-02 lane C2-02: two compare directions (image: cmp x0,x then bhi) and the f2c store constant order differ; tried x0<=x, !(x0>x), locals.
 *
 * 2026-10-05 (D4-18): still 4 bytes. Tried: positive form x >= x0 && x < x0 + w (4 bytes, same as now), !(e->x > x || ...) (13 bytes: x0 lands in r0), int-cast compares (17 bytes, bgt). The compare order of the image needs x0 in r1 with the unsigned-greater test; every spelling that gives that order puts x0 in r0.
 */
int ZUKAN_DETAIL_INFO_HandleTouchLanguageButton(void *heap, struct Ov208InfoWork *st, struct Ov208Ctx *obj)
{
    void *sc;
    int res;
    u32 x;
    u32 y;
    u8 i;
    struct ZukanDetailInfoLangSlot *e;
    u8 *c;
    int k;

    sc = ZUKAN_DETAIL_COMMON_GetWorkPtr(obj);
    res = 0;
    if (st->pressedButton == 6 && TOUCHPANEL_GetPointTrg(&x, &y) != 0) {
        for (i = 0; i < 6; i++) {
            e = (struct ZukanDetailInfoLangSlot *)((u8 *)st + i * 0x14);
            c = (u8 *)e;
            k = 0x20;
            if (CLACT_GetActorDrawEnable((struct ClactActor *)e->actor) != 0
                && (u32)c[k] <= x && x < (u32)c[k] + c[k + 2]
                && (u32)c[k + 1] <= y && y < (u32)c[k + 1] + c[k + 3]) {
                if (st->currentButton == i) break;
                st->pressedButton = i;
                res = 1;
                break;
            }
        }
    }
    if (res != 0) {
        ZUKAN_DETAIL_INFO_SelectLanguageButton(heap, (char *)st, obj, st->pressedButton);
        *(u32 *)((u8 *)st + st->pressedButton * 0x14 + 0x2c) = 1;
        e = (struct ZukanDetailInfoLangSlot *)((u8 *)st + st->pressedButton * 0x14);
        CLACT_SetActorAnimSeq((struct ClactActor *)e->actor, e->pressedAnim);
        GFL_USE_PlaySeDefaultVolume(0x54a);
        UI_SetInputMode(1);
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(sc, 0);
    }
    return res;
}

int ZUKAN_DETAIL_INFO_HandleKeyLanguageSelect(void *first,char *p,struct Ov208Ctx *key)
{
    void *scene;
    int changed;
    u32 buttons,press;
    u8 i,next;
    scene=ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    changed=0;
    if(((struct Ov208InfoWork *)p)->pressedButton==6) {
        buttons=KEY_GetRepeat();
        press=KEY_GetTrg();
        if(((struct Ov208InfoWork *)p)->currentButton==6) {
            if((buttons&0x300)||(press&1)) {
                for(i=0;i<6;i++) {
                    if(CLACT_GetActorDrawEnable((struct ClactActor *)(*(struct Obj **)((uptr)p+(u32)i*20+0x1c)))!=0) {
                        ((struct Ov208InfoWork *)p)->pressedButton=i; changed=1; break;
                    }
                }
            }
        } else if((buttons&0x100)||(press&1)) {
            for(i=1;i<6;i++) {
                next=(((struct Ov208InfoWork *)p)->currentButton+i)%6;
                if(CLACT_GetActorDrawEnable((struct ClactActor *)(*(struct Obj **)((uptr)p+(u32)next*20+0x1c)))!=0) {
                    ((struct Ov208InfoWork *)p)->pressedButton=next; changed=1; break;
                }
            }
        } else if(buttons&0x200) {
            for(i=1;i<6;i++) {
                next=(((struct Ov208InfoWork *)p)->currentButton+6-i)%6;
                if(CLACT_GetActorDrawEnable((struct ClactActor *)(*(struct Obj **)((uptr)p+(u32)next*20+0x1c)))!=0) {
                    ((struct Ov208InfoWork *)p)->pressedButton=next; changed=1; break;
                }
            }
        }
    }
    if(changed!=0) {
        ZUKAN_DETAIL_INFO_SelectLanguageButton(first,p,key,((struct Ov208InfoWork *)p)->pressedButton);
        *(u32 *)((uptr)p+*(u32 *)&((struct Ov208InfoWork *)p)->pressedButton*20+0x2c)=1;
        CLACT_SetActorAnimSeq((struct ClactActor *)(*(struct Obj **)((uptr)p+*(u32 *)&((struct Ov208InfoWork *)p)->pressedButton*20+0x1c)),*(u16 *)((uptr)p+*(u32 *)&((struct Ov208InfoWork *)p)->pressedButton*20+0x26));
        GFL_USE_PlaySeDefaultVolume(0x54a);
        UI_SetInputMode(0);
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled((void *)((sptr)scene), 0);
    }
    return changed;
}

/*
 * matching: initialize the flag after the output-producing call to keep its zero-cost schedule.
 * Third helper arguments are explicitly live in the original caller.
 */
void ZUKAN_DETAIL_INFO_RefreshLanguagePanel(void *first,char *q,struct Ov208Ctx *third)
{
    struct Params p;
    int okay,index;
    ZUKAN_DETAIL_INFO_GetPanelParams(first,(u8 *)q,third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
    okay=1;
    ZUKAN_INFO_SetPokemon(((struct Ov208InfoWork *)q)->speciesInfo,p.d,p.c,p.b,p.a,p.y,p.x);
    index=((struct Ov208InfoWork *)q)->currentButton;
    if(index!=6) {
        if(p.arr[index]!=0) okay=0;
        else {ZUKAN_DETAIL_INFO_ClearButtonHighlight((sptr)first, q, (uptr)third);((struct Ov208InfoWork *)q)->currentButton=6;}
    }
    if(okay) ZUKAN_INFO_Show(((struct Ov208InfoWork *)q)->langInfo);
    else ZUKAN_INFO_SetPokemonPage(((struct Ov208InfoWork *)q)->langInfo,p.d,p.c,p.b,p.a,p.y,p.x,((struct Ov208InfoWork *)q)->currentButton);
    ZUKAN_DETAIL_INFO_ResetButtons((sptr)first,q,third,(int *)p.arr);
}

void ZUKAN_DETAIL_INFO_SelectLanguageButton(void *first,char *q,struct Ov208Ctx *third,int next)
{
    struct Params p;
    int current=((struct Ov208InfoWork *)q)->currentButton;
    if(current!=next) {
        if(current==6) {
            ZUKAN_DETAIL_INFO_GetPanelParams(first,(u8 *)q,third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
            ZUKAN_INFO_SetPokemonPage(((struct Ov208InfoWork *)q)->langInfo,p.d,p.c,p.b,p.a,p.y,p.x,next);
            ZUKAN_INFO_Hide(((struct Ov208InfoWork *)q)->langInfo);
        } else ZUKAN_INFO_ShowPage(((struct Ov208InfoWork *)q)->langInfo,next);
        ZUKAN_DETAIL_INFO_ClearButtonHighlight((sptr)first, q, (uptr)third);((struct Ov208InfoWork *)q)->currentButton=next;
        ZUKAN_DETAIL_INFO_StartHighlightBlink(first,(int *)q,third);
    }
}

void ZUKAN_DETAIL_INFO_CreateLanguageButtons(u16 *heap, char *p, struct Ov208Ctx *key)
{
    struct ZukanPos pos;
    void *scene;
    int owner;
    void *arc;
    enum Index i;
    u16 flag;
    scene = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    owner = ZUKAN_DETAIL_GRAPHIC_Reset3dState(ZUKAN_DETAIL_COMMON_GetDisplay(key));
    i = 0;
    arc = ARC_TOOL_CreateHandle(0x9f, *heap);
    ((struct Ov208InfoWork *)p)->palRes = ZUKAN_DETAIL_TOUCHBAR_GetCurrentSlot(scene);
    ((struct Ov208InfoWork *)p)->charRes = CLACT_RegisterCharacter(arc, 0xd, 0, 0, *heap);
    ((struct Ov208InfoWork *)p)->cellRes = CLACT_RegisterCellAnim(arc, 0x1b, 0x2c, *heap);
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
        ((struct Ov208InfoWork *)q)->buttons[0].idleAnim = t[6];
        ((struct Ov208InfoWork *)q)->buttons[0].pressedAnim = t[7];
        q[0x28] = t[8];
        ((struct Ov208InfoWork *)q)->buttons[0].state = 0;
        pos.x = t[0];
        pos.y = t[1];
        pos.z = ((struct Ov208InfoWork *)q)->buttons[0].idleAnim;
        ((struct Ov208InfoWork *)q)->buttons[0].actor = CLACT_CreateActor(owner, ((struct Ov208InfoWork *)p)->charRes, ((struct Ov208InfoWork *)p)->palRes, ((struct Ov208InfoWork *)p)->cellRes, &pos, flag, *heap);
        CLACT_SetActorAutoAnim((struct ClactActor *)((struct Obj *)((struct Ov208InfoWork *)q)->buttons[0].actor), 1);
        CLACT_SetActorObjMode((struct ClactActor *)((struct Actor *)((struct Ov208InfoWork *)q)->buttons[0].actor), 1);
        i = (u8)(i + 1);
    } while ((u32)i < 6);
}

/*
 * Releases the sixth 0x14-byte element handle at +0x1C and the two at +0xA0 and +0xA4.
 */
void ZUKAN_DETAIL_INFO_DeleteLanguageButtons(int unused, char *q, u32 heap)
{
    unsigned char i;

    for (i = 0; i < 6; i++)
        CLACT_DeleteActor((struct ClactActor *)((struct Obj *)(*(int *)(q + i * 0x14 + 0x1c))));
    CLACT_ReleaseCharacter(((struct Ov208InfoWork *)q)->charRes);
    CLACT_ReleaseCellAnim(((struct Ov208InfoWork *)q)->cellRes);
}

/*
 * Byte-based state indexing preserves the shared 20-byte stride; u32 indexing changes it to shift/add.
 */
void ZUKAN_DETAIL_INFO_UpdateButtonPressAnim(void *unused, char *p, struct Ov208Ctx *key)
{
    void *scene = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    if (((struct Ov208InfoWork *)p)->pressedButton != 6) {
        u8 i = ((struct Ov208InfoWork *)p)->pressedButton;
        char *states = p + 0x2c;
        switch (*(unsigned *)(states + i * 20)) {
        case 0: break;
        case 1: *(unsigned *)(states + i * 20) = 2; break;
        case 2:
            if (CLACT_IsActorAnimActive((struct ClactActor *)(*(struct Actor **)(p + i * 20 + 0x1c))) == 0)
                *(unsigned *)(states + i * 20) = 3;
            break;
        case 3:
            CLACT_SetActorAnimSeq((struct ClactActor *)(*(struct Obj **)(p + i * 20 + 0x1c)), *(u16 *)(p + i * 20 + 0x24));
            *(unsigned *)(states + i * 20) = 0;
            ((struct Ov208InfoWork *)p)->pressedButton = 6;
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 1);
            break;
        }
    }
}

void ZUKAN_DETAIL_INFO_ResetButtons(int unused, char *q, struct Ov208Ctx *c, int *tbl)
{
    unsigned char i;

    for (i = 0; i < 6; i++) {
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct Obj *)*(int *)(q + i * 0x14 + 0x1c)), tbl[i]);
        *(int *)(q + i * 0x14 + 0x2c) = 0;
        CLACT_SetActorAnimSeq((struct ClactActor *)((struct Obj *)(*(int *)(q + i * 0x14 + 0x1c))), *(unsigned short *)(q + i * 0x14 + 0x24));
    }
    ((struct Ov208InfoWork *)q)->pressedButton = 6;
}

/*
 * Species local and CC40/CED4 species arguments are u32: this caller has no u16 truncation before either call.
 */
void ZUKAN_DETAIL_INFO_GetPanelParams(const u16 *heap, u8 *p, struct Ov208Ctx *key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7)
{
    u32 values[6];
    u32 a, b, c, special, value;
    struct Blk37 *ctx;
    u32 id;
    u8 i;
    ctx = ZUKAN_SAVE_GetFromGameData(ZUKAN_DETAIL_COMMON_GetSource(key));
    id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
    special = 0;
    ZUKAN_SAVE_GetViewGenderAndForm((struct ZukanSave *)ctx, id, &b, &c, &a, *heap);
    if (id == 327) special = ZUKAN_SAVE_GetSpindaPersonality((struct ZukanSave *)ctx, special);
    value = ZUKAN_SAVE_IsCaught((struct ZukanSave *)ctx, id);
    for (i = 0; i < 6; i++) values[i] = ZUKAN_SAVE_HasLanguageFlag((struct ZukanSave *)ctx, id, p[i * 20 + 0x28]);
    *out1 = id;
    *out2 = a;
    *out3 = b;
    *out4 = c;
    *out5 = special;
    *out6 = value;
    for (i = 0; i < 6; i++) out7[i] = values[i];
}

void ZUKAN_DETAIL_INFO_LoadHighlightPalettes(u16 *heap, u8 *p, struct Ov208Ctx *ctx)
{
    struct Ov208Pltt *pltt;
    uptr file;
    u8 *data;
    file = (uptr)ARC_UTIL_LoadPaletteBlockFromArchive(159, 3, (void *)((uptr)(&pltt)), *heap);
    data = pltt->data;
    MI_CpuCopy8(data + 0x20, p + 0xa8, 32);
    MI_CpuCopy8(data + 0x60, p + 0xc8, 32);
    GFL_HEAP_Free((void *)file);
    ((struct Ov208InfoWork *)p)->blinkPhase = 0;
    MI_CpuCopy8(p + 0xa8, p + 0xe8, 32);
    NNS_GfdRegisterNewVramTransferTask((void *)14, 192, (uptr)(p + 0xe8), 32);
}

void ZUKAN_DETAIL_INFO_NoOpHighlight(int unused0, char *unused1, unsigned unused2)
{
}

/*
 * Zeroes word 0x42 and sets word 0x43 when word 0x26 is not 6.
 */
void ZUKAN_DETAIL_INFO_StartHighlightBlink(struct Ov208Heap *unused, int *p, struct Ov208Ctx *ctx)
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
    int i = ((struct Ov208InfoWork *)p)->currentButton;

    if (i == 6)
        return;
    CLACT_SetActorPaletteOffset((struct ClactActor *)((struct Obj *)(*(int *)(p + i * 0x14 + 0x1c))), 0, 0);
    ((struct Ov208InfoWork *)p)->blinkRestart = 0;
}

/*
 * note: 2026-10-05 (D5-03): closed by u8 channel locals for colour A, the store as
 *   r | g << 5 | b << 10 (GX_RGB order) with the three lerps inline, and the f108 wrap
 *   written on the field directly (no x/y locals).
 */
void ZUKAN_DETAIL_INFO_UpdateHighlightBlink(struct Ov208Heap *heap, struct Ov208InfoWork *e, struct Ov208Ctx *ctx)
{
    if (e->blinkRestart != 0) {
        int v = e->currentButton;

        if (v != 6)
            CLACT_SetActorPaletteOffset((struct ClactActor *)((struct Obj *)(*(int *)((char *)e + v * 0x14 + 0x1c))), 2, 0);
        e->blinkRestart = 0;
    }

    if (e->blinkPhase + 0x400 >= 0x10000)
        e->blinkPhase = e->blinkPhase + 0x400 - 0x10000;
    else
        e->blinkPhase = e->blinkPhase + 0x400;

    {
        unsigned char i;
        int t = e->blinkPhase;
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

        NNS_GfdRegisterNewVramTransferTask((void *)0xe, 0xc0, (sptr)e->dst, 0x20);
    }
}
