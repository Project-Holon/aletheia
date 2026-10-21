/*
 * file:     br_util.c
 * unit:     yes
 * function: BR_UTIL_Create, BR_UTIL_Delete, BR_UTIL_SetTextFromMessage, BR_UTIL_SetTextFromBuffer, BR_UTIL_FlushText, BR_UTIL_SetTextLayout, BR_UTIL_AlignText, BR_UTIL_CreateListMenu, BR_UTIL_DeleteListMenu, BR_UTIL_MainListMenu, BR_UTIL_ListMenuIsScrollable, BR_UTIL_GetListMenuHitId, BR_UTIL_SetListItemBitmap, BR_UTIL_GetListItemBitmap, BR_UTIL_GetListMenuField, BR_UTIL_RefreshList, BR_UTIL_DrawListRows, BR_UTIL_PollScrollDrag, BR_UTIL_BlitRows, BR_UTIL_ScrollRows, BR_UTIL_ScrollWithCursor, BR_UTIL_NeedsScroll, BR_UTIL_HasMultipleRows, BR_UTIL_HandleRowTouch, BR_UTIL_UpdateRowSelection, BR_UTIL_CreateTextWin, BR_UTIL_DeleteTextWin, BR_UTIL_SetWindowText, BR_UTIL_SetWindowTextBuf, BR_UTIL_FlushWindow, BR_UTIL_CreateProfileScreen, BR_UTIL_DeleteProfileScreen, BR_UTIL_MainProfileScreen, BR_UTIL_CreateTask, BR_UTIL_DeleteTask, BR_UTIL_RunTask, BR_UTIL_IsTaskIdle, BR_UTIL_SetTaskStep, BR_UTIL_ClearTaskStep, BR_UTIL_IsTaskStep, BR_UTIL_CreateHandles, BR_UTIL_DeleteHandles, BR_UTIL_RunHandles, BR_UTIL_StartEffect, BR_UTIL_IsEffectDone, BR_UTIL_SetHandlesAnimSeq, BR_UTIL_EffectIdle, BR_UTIL_EffectSpiral, BR_UTIL_EffectFollow12, BR_UTIL_EffectFollow6, BR_UTIL_EffectFlyIn, BR_UTIL_EffectFlyInSlow, BR_UTIL_EffectNoop, BR_UTIL_EffectToTarget, BR_UTIL_EffectToPoint, BR_UTIL_InitOrbit, BR_UTIL_StepOrbit, BR_UTIL_InitSpiral, BR_UTIL_StepSpiral, BR_UTIL_InitLine, BR_UTIL_StepLine, BR_UTIL_Init, BR_UTIL_StepFollow
 * address:  0x021FC6A4
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from br_proc_sys.c, br_btn.c, br_graphic.c, br_util.c, br_net.c, BR_MEMBER_COUNT_GetU16Count.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   GF_PANIC_Fail 0x02034714 arm
 *   STRBUF_Delete 0x02045808 arm
 *   GDS_PROFILE_CreateNameStr 0x0200D6D0 thumb
 *   GDS_PROFILE_GetEggFlag 0x0200D6EC thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_UTIL_DeleteTask  0x021FD714  thumb  ov186
 *   BR_UTIL_DeleteTextWin  0x021FD15C  thumb  ov186
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   STRBUF_Clone 0x02045874 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   BMP_Create 0x02043678 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_Delete 0x020437AC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_RegisterCharacter    0x0204A6C8  arm
 *   CLACT_RegisterPaletteEx    0x0204AC18  arm
 *   CLACT_RegisterCellAnim    0x0204AF28  arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   d_02200D5C 0x02200D5C data a1
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Copy 0x02045838 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_GetWidth 0x020437DC arm
 *   BMP_GetHeight 0x020437E4 arm
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   PRINTSYS_CountLines 0x0201D42C thumb
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   d_02200D68 0x02200D68 data a4
 *   d_02200B0C 0x02200B0C data a4
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   d_02200AF0 0x02200AF0 data a4
 *   BMP_GetPixels 0x020437D4 arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   PMS_DRAW_Create 0x0202DB0C thumb
 *   PMS_DRAW_SetDecoPriority 0x0202DCFC thumb
 *   PMS_DRAW_SetNullColorPalette 0x0202DE5C thumb
 *   PMS_DRAW_SetPrintColor 0x0202DE64 thumb
 *   PMS_DRAW_PrintOffset 0x0202DC60 thumb
 *   GDS_PROFILE_GetSpecies 0x0200D6FC thumb
 *   GDS_PROFILE_GetFormSpecies 0x0200D70C thumb
 *   GDS_PROFILE_GetNicknameFlag 0x0200D72C thumb
 *   GDS_PROFILE_GetBadEggFlag 0x0200D73C thumb
 *   GDS_PROFILE_GetValidatedCountry 0x0200D74C thumb
 *   GDS_PROFILE_GetValidatedRegion 0x0200D760 thumb
 *   GDS_PROFILE_ExportRecord 0x0200D774 thumb
 *   GDS_PROFILE_GetBirthMonth 0x0200D810 thumb
 *   GDS_PROFILE_GetTrainerSprite 0x0200D820 thumb
 *   WORDSET_SetSlotMonth 0x0201F230 thumb
 *   WORDSET_SetSlotFromMsgE7 0x0201F048 thumb
 *   WORDSET_SetSlotFromKeyedMessage 0x0201F094 thumb
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   POKE_TOOL_GetIconCellArcId 0x0201BC40 thumb
 *   POKE_TOOL_GetIconCellEntryId 0x0201BCB4 thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   d_02200B34 0x02200B34 data a4
 *   d_02200B6C 0x02200B6C data a4
 *   d_02200AFC 0x02200AFC data a1
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   PMS_DRAW_Main 0x0202DBC4 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   d_02200AD0 0x02200AD0 data a4
 *   d_02200AE8 0x02200AE8 data a4
 *   d_02200AD8 0x02200AD8 data a4
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   VEC_Mag 0x0207CBD0 arm
 *   FX_Div 0x0207C768 arm
 *   BR_UTIL_MainListMenu 0x021FCD0C thumb ov186
 *   BR_UTIL_GetListMenuHitId 0x021FCDA8 thumb ov186
 *   BR_UTIL_IsEffectDone 0x021FD938 thumb ov186
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextLayout 0x021FC868 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   BR_UTIL_CreateListMenu 0x021FC8C8 thumb ov186
 *   BR_UTIL_DeleteListMenu 0x021FCC80 thumb ov186
 *   _fadd                        0x0209C95C  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "br_types.h"

extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
struct Strbuf;

extern void STRBUF_Delete(struct Strbuf *strbuf);

#include "../arm9/gds_profile.h"
struct StoredMon;


#include "../arm9/gfl_heap_wrap.h"


extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);

#include "../arm9/gfl_use.h"

extern struct Strbuf *STRBUF_Clone(struct Strbuf *src, unsigned int heapId);
struct MsgBank;
struct ClactActor;

#include "../arm9/msgdata.h"

extern void CLACT_SetActorObjMode(struct ClactActor *actor, u32 value);

typedef short s16_p07;
#include "../arm9/bmp.h"
struct WordSet;

#include "../arm9/wordset.h"

extern void ARC_TOOL_DeleteHandle(void *);

#include "../arm9/bg_sys.h"

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

struct CharBuf;

struct Descriptor;

struct StrObj;

struct GdsRecord;

struct PmsDraw;

typedef struct {u16 x,y,id;u8 flag,pad;} BrUtilRequest;

typedef struct {void *text;int id;} BrUtilItem;

typedef struct {BrUtilItem *list;u32 count;u8 x,y,width,height,palette,bg,spacing,pad;int mode;char *resources;u32 manager,cursor,other;u16 *selection;} BrUtilConfig;

typedef struct {u8 top,bottom,left,right;} Area;

typedef struct {BrUtilConfig cfg;u32 handles[4],descriptor;u16 selected,last,index,start,visible;u16 pad46;int hitId;signed char dragDir;u8 scroll,pad4e[2];void (*methods[3])(void);Area areas[10];int dragActive;u16 dragY;u8 pad8A[2];void *bitmaps[];} BrUtilListMenu;

/* One text window: window descriptor, owner, string buffer and layout, 0x24 bytes. */
typedef struct {
    void *bmp;         /* 0x00 window descriptor */
    u8 dirty;          /* 0x04 nonzero while the window holds unwritten text */
    u8 pad5[3];
    void *owner;       /* 0x08 print owner */
    void *window;      /* 0x0C window descriptor copy */
    void *strbuf;      /* 0x10 string buffer */
    u16 clearColor;    /* 0x14 colour the window is cleared with */
    u16 plane;         /* 0x16 bg plane the window is built on */
    int alignMode;     /* 0x18 BR_UTIL_AlignText mode */
    int layoutA;       /* 0x1C */
    int layoutB;       /* 0x20 */
} BrUtilTextWin;

typedef struct {char pad[0x8C];int bitmap[1];} BrUtilListView;

typedef struct {u32 x,y;} BrUtilPair;

typedef struct {u16 x,y,z,w;} BrUtilReq;

typedef struct {u8 x,y,w,h;u32 msg;} Ent;

typedef void (*Callback)(u8 *,int *,u32);

/* The effect object created by BR_UTIL_CreateHandles, 0x264 bytes. */
typedef struct BrUtilEffect {
    int x;                      /* 0x00 origin x */
    int y;                      /* 0x04 origin y */
    const BrPair *target;         /* 0x08 target position */
    int index;                  /* 0x0C sprite index */
    int *task;                  /* 0x10 effect task */
    char *resources;            /* 0x14 resource base */
    char record[12][32];        /* 0x18 motion records */
    BrPair positions[12];         /* 0x198 handle positions */
    void *handles[12];          /* 0x1F8 actors */
    int timer;                  /* 0x228 effect step counter */
    int flag;                   /* 0x22C effect finished flag */
    int done[12];               /* 0x230 per-handle done flags */
    char pad260[4];             /* 0x260 trailing */
} BrUtilEffect;

/* The task object created by BR_UTIL_CreateTask, 16 bytes. */
typedef struct BrUtilTask {
    Callback step;              /* 0x00 step function */
    int state;                  /* 0x04 step state, passed by address */
    int payload;                /* 0x08 object the step runs on */
    int unusedC;                /* 0x0C */
} BrUtilTask;

/* An orbit motion record, 28 bytes. */
typedef struct BrUtilOrbit {
    int x;                      /* 0x00 start x */
    int y;                      /* 0x04 start y */
    int posX;                   /* 0x08 current x */
    int posY;                   /* 0x0C current y */
    u16 radius;                 /* 0x10 start radius */
    u16 targetRadius;           /* 0x12 end radius */
    u16 angle;                  /* 0x14 start angle */
    u16 targetAngle;            /* 0x16 end angle */
    int duration;               /* 0x18 steps */
} BrUtilOrbit;

/* A spiral motion record, 24 bytes. */
typedef struct BrUtilSpiral {
    int x;                      /* 0x00 origin x */
    int y;                      /* 0x04 origin y */
    int posX;                   /* 0x08 current x */
    int posY;                   /* 0x0C current y */
    u16 radius;                 /* 0x10 */
    u16 angle;                  /* 0x12 start angle */
    int duration;               /* 0x14 */
} BrUtilSpiral;

/* A follow motion record, 20 bytes. */
typedef struct BrUtilFollow {
    int *target;                /* 0x00 target position */
    int posX;                   /* 0x04 current x, 20.12 fixed point */
    int posY;                   /* 0x08 current y, 20.12 fixed point */
    int unusedC;                /* 0x0C */
    int speed;                  /* 0x10 step fraction */
} BrUtilFollow;

typedef struct {short x,y;} ShortPair;

typedef struct {BrPair first,second,third;} Table;

#include "../sdk_fx.h"

/* The DS code was built against a prototype that returns the destination and takes a word fill value. The host build uses the header. */
#include "../arm9/mi_memory.h"


struct BmpWin;

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);


extern void BMP_WIN_TransferChars(struct BmpWin *win);

extern void BMP_WIN_MakeScreen(struct BmpWin *win);

extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);

extern void BMP_WIN_ClearScreen(struct BmpWin *win);

extern u32 BMP_WIN_Delete(struct BmpWin *win);

struct GfFont;
struct PrintQueue;

#include "../arm9/printsys.h"

extern void STRBUF_Copy(struct Strbuf *dst, struct Strbuf *src);






extern void GF_PANIC_Fail(const char *,u32,const char *);



extern void CLACT_SetActorAutoAnim(struct ClactActor *actor, u32 enable);

extern void CLACT_SetActorDrawEnable(struct ClactActor *,unsigned int);

struct BrRes;

extern void BR_RES_LoadSprite(struct BrRes *res, unsigned int spriteIndex, unsigned int heapId);


extern unsigned BR_RES_GetFont(struct BrRes *res);

extern void CLACT_DeleteActor(struct ClactActor *p);


extern void BR_RES_ReleaseSprite(struct BrRes *res, unsigned int spriteIndex);



extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);




extern void BR_RES_ApplyBgSet(void *unusedA, u32 palSet);

extern int BR_RES_GetMsgData(struct BrRes *res);

extern int BR_RES_GetWordSet(struct BrRes *res);

#include "../arm9/pms_draw.h"








struct GdsProfileRaw;











#include "../arm9/poke_tool_ext.h"





extern int CLACT_RegisterPaletteCompressed(void *,u32,u32,u32,u16);

extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);

extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16);




extern void CLACT_SetActorAnimSeq(struct ClactActor *,u16);


#include "../arm9/fx_vec.h"

#include "../arm9/fx_cp.h"
/* The DS code passes the heap id as a halfword (the original prototype); the header takes a word. The host build uses the header. */
#ifdef __MWERKS__
#define STRBUF_Create STRBUF_Create_header
#endif
#include "../arm9/strbuf.h"
#ifdef __MWERKS__
#undef STRBUF_Create
extern struct Strbuf *STRBUF_Create(u32 capacity, u16 heapId);
#endif
/* The DS code passes the window width as a word (the original prototype); the header takes a byte. The host build uses the header. */
#ifdef __MWERKS__
#define BMP_WIN_Create BMP_WIN_Create_header
#endif
#include "../arm9/bmp_win.h"
#ifdef __MWERKS__
#undef BMP_WIN_Create
extern struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u32 width, u8 height, u8 palette, u8 allocDir);
#endif
/* The DS code passes the actor heap id as a word and the surface offset selector as a halfword (the original prototypes); the header has a halfword heap id and a word selector. The host build uses the header. */
#ifdef __MWERKS__
#define CLACT_AddActorSurfacePos CLACT_AddActorSurfacePos_header
#define CLACT_SetActorPaletteOffset CLACT_SetActorPaletteOffset_header
#define CLACT_CreateActor CLACT_CreateActor_header
#endif
#include "../arm9/clact.h"
#ifdef __MWERKS__
#undef CLACT_AddActorSurfacePos
#undef CLACT_SetActorPaletteOffset
#undef CLACT_CreateActor
extern void CLACT_AddActorSurfacePos(struct ClactActor *actor, const struct ClactVec2 *delta, u16 which);
extern void *CLACT_SetActorPaletteOffset(struct ClactActor *actor, u32 offset, u32 pltt_op);
extern struct ClactActor *CLACT_CreateActor(struct Unit *unit, u32 char_idx, u32 pltt_idx, u32 cell_idx, const struct ActorInitParam *init, u16 space, int heap_id);
#endif
/* The DS code passes a signed sprite index (the original prototype); the header takes an unsigned index. The host build uses the header. */
#ifdef __MWERKS__
#define BR_RES_GetSprite BR_RES_GetSprite_header
#endif
#include "../ov186/br_res.h"
#ifdef __MWERKS__
#undef BR_RES_GetSprite
extern int BR_RES_GetSprite(struct BrRes *res, int spriteIndex, void *outSprite);
#endif
#include "../arm9/touchpanel.h"
/* The DS code passes the heap id as a halfword (the original prototype); the header takes a word. The host build uses the header. */
#ifdef __MWERKS__
#define ARC_TOOL_CreateHandle ARC_TOOL_CreateHandle_header
#endif
#include "../arm9/arc_tool.h"
#ifdef __MWERKS__
#undef ARC_TOOL_CreateHandle
extern void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);
#endif

void *BR_UTIL_Create(unsigned short plane,unsigned a,unsigned short b,unsigned short c,unsigned char d,unsigned char e,void *owner,unsigned short heap);

void BR_UTIL_Delete(u8*p);

void BR_UTIL_SetTextFromMessage(char *p,void *a,void *b,void *font,unsigned short value);

void BR_UTIL_SetTextFromBuffer(char *p,void *text,void *font,unsigned short value);

int BR_UTIL_FlushText(u8*p);

void BR_UTIL_SetTextLayout(u8*p,u32 a,u32 b,u32 c);

void BR_UTIL_AlignText(int mode,BrPair *base,const void *bmp,void *text,void *font,BrPair *out);

BrUtilListMenu *BR_UTIL_CreateListMenu(const BrUtilConfig *cfg,u16 heap);

void BR_UTIL_DeleteListMenu(char *p);

void BR_UTIL_MainListMenu(char *p);

int BR_UTIL_ListMenuIsScrollable(char *p);

int BR_UTIL_GetListMenuHitId(char *p);

void BR_UTIL_SetListItemBitmap(u8 *p, u16 i, u32 v);

u32 BR_UTIL_GetListItemBitmap(u8 *p, u16 i);

int BR_UTIL_GetListMenuField(char *p,unsigned field);

void BR_UTIL_RefreshList(char *p);

void BR_UTIL_DrawListRows(char *p,int start);

int BR_UTIL_PollScrollDrag(char *p);

void BR_UTIL_BlitRows(int dest,int src,int dx,int dy,unsigned short sx,unsigned short sy,unsigned short width,unsigned short height);

int BR_UTIL_ScrollRows(char *p,int change);

int BR_UTIL_ScrollWithCursor(char *p,int step);

int BR_UTIL_NeedsScroll(char *p);

int BR_UTIL_HasMultipleRows(char *p);

void BR_UTIL_HandleRowTouch(char *p);

void BR_UTIL_UpdateRowSelection(char *p);

void *BR_UTIL_CreateTextWin(void *a, void *owner, u16 heap);

void BR_UTIL_DeleteTextWin(void *p, int res);

void BR_UTIL_SetWindowText(char *p,char *q,void *text);

void BR_UTIL_SetWindowTextBuf(char *p,void *q,void *text);

void BR_UTIL_FlushWindow(void *p);

char *BR_UTIL_CreateProfileScreen(void *prof,char *q,void *unit,void *printQue,int mode,u16 heap);

void BR_UTIL_DeleteProfileScreen(int *p);

int BR_UTIL_MainProfileScreen(u8 *p);

int *BR_UTIL_CreateTask(int payload,int callback,int heap);

void BR_UTIL_DeleteTask(void *p);

void BR_UTIL_RunTask(u8 *p);

int BR_UTIL_IsTaskIdle(int *p);

int *BR_UTIL_SetTaskStep(int *p, int v);

int BR_UTIL_ClearTaskStep(int *a);

int BR_UTIL_IsTaskStep(int *p, int v);

char *BR_UTIL_CreateHandles(void *owner, char *resources, int index, int heap);

void BR_UTIL_DeleteHandles(char *r5);

void BR_UTIL_RunHandles(char *p);

void BR_UTIL_StartEffect(char *p,u32 mode,const BrPair *pair);

int BR_UTIL_IsEffectDone(char *p);

void BR_UTIL_SetHandlesAnimSeq(u8 *p,u32 value);

void BR_UTIL_EffectIdle(void *unused,int *state,u8 *p);

void BR_UTIL_EffectSpiral(int unused,int *state,BrUtilEffect *p);

void BR_UTIL_EffectFollow12(int unused,int *state,BrUtilEffect *p);

void BR_UTIL_EffectFollow6(int unused,int *state,BrUtilEffect *p);

void BR_UTIL_EffectFlyIn(int unused,int *state,BrUtilEffect *p);

void BR_UTIL_EffectFlyInSlow(int unused,int *state,BrUtilEffect *p);

void BR_UTIL_EffectNoop(void);

void BR_UTIL_EffectToTarget(int *obj,int *state,BrUtilEffect *p);

void BR_UTIL_EffectToPoint(int *task,int *state,char *p);

int BR_UTIL_InitOrbit(u8 *p,const BrPair *origin,u16 a,u16 b,u16 c,u16 d,int duration);

int BR_UTIL_StepOrbit(char *p, int *out, int step);

int BR_UTIL_InitSpiral(u8 *p,const BrPair *origin,u16 a,u16 b,int duration);

int BR_UTIL_StepSpiral(char *p, int *out, int step);

void BR_UTIL_InitLine(int *p,const BrPair *a,const BrPair *b,int c,int d);

int BR_UTIL_StepLine(int *p, BrPair *out, int step);

void BR_UTIL_Init(int *p, int a, const int *values, int duration);

int BR_UTIL_StepFollow(char *p,int *out);

extern const char d_02200D5C[];

extern const char d_02200D68[];

extern const BrPair d_02200B0C[];

extern const char d_02200AF0[];

extern const Ent d_02200B34[];

extern const BrUtilPair d_02200B6C;

extern const u8 d_02200AFC[];

extern const Table d_02200AD0;

extern const Table d_02200AE8;

extern const u32 d_02200AD8[];

extern const short FX_SinCosTable_[];

void *BR_UTIL_Create(unsigned short plane,unsigned a,unsigned short b,unsigned short c,unsigned char d,unsigned char e,void *owner,unsigned short heap)
{
    char *p;
    void *bmp;
    p=GFL_HEAP_Alloc(heap,0x24,0,d_02200D5C,0x5f);
    MI_CpuFill8(p,0,0x24);
    ((BrUtilTextWin *)p)->clearColor=0;
    ((BrUtilTextWin *)p)->owner=owner;
    ((BrUtilTextWin *)p)->plane=plane;
    ((BrUtilTextWin *)p)->strbuf=STRBUF_Create(0xff,heap);
    bmp=(void *)BMP_WIN_Create((unsigned char)plane,a,b,c,d,e,1);
    ((BrUtilTextWin *)p)->window=bmp;
    ((BrUtilTextWin *)p)->bmp=bmp;
    p[4]=0;
    BMP_Clear(BMP_WIN_GetBmp(bmp),((BrUtilTextWin *)p)->clearColor);
    bmp=((BrUtilTextWin *)p)->window;
    BMP_WIN_TransferChars(bmp);
    BMP_WIN_MakeScreen(bmp);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(bmp));
    return p;
}

void BR_UTIL_Delete(u8*p){BMP_WIN_ClearScreen(*(void* *)&((BrUtilTextWin *)p)->window);BMP_WIN_Delete(*(void* *)&((BrUtilTextWin *)p)->window);STRBUF_Delete(*(void* *)&((BrUtilTextWin *)p)->strbuf);GFL_HEAP_Free(p);}

void BR_UTIL_SetTextFromMessage(char *p,void *a,void *b,void *font,unsigned short value)
{
    BrPair xy;
    void *owner;
    BMP_Clear(BMP_WIN_GetBmp(((BrUtilTextWin *)p)->window),((BrUtilTextWin *)p)->clearColor);
    MSGDATA_ReadString(a,(uptr)b,((BrUtilTextWin *)p)->strbuf);
    BR_UTIL_AlignText(((BrUtilTextWin *)p)->alignMode, (BrPair *)(p+28), BMP_WIN_GetBmp(((BrUtilTextWin *)p)->window), ((BrUtilTextWin *)p)->strbuf, font, (BrPair *)&xy);
    owner=((BrUtilTextWin *)p)->owner;
    PRINTSYS_PrintQueColor(owner,BMP_WIN_GetBmp(((BrUtilTextWin *)p)->bmp),(short)xy.x,(short)xy.y,(((BrUtilTextWin *)p)->strbuf),font,value);
    p[4]=1;
}

void BR_UTIL_SetTextFromBuffer(char *p,void *text,void *font,unsigned short value)
{
    BrPair xy;
    void *owner;
    BMP_Clear(BMP_WIN_GetBmp(((BrUtilTextWin *)p)->window),((BrUtilTextWin *)p)->clearColor);
    STRBUF_Copy(((BrUtilTextWin *)p)->strbuf,text);
    BR_UTIL_AlignText(((BrUtilTextWin *)p)->alignMode, (BrPair *)(p+28), BMP_WIN_GetBmp(((BrUtilTextWin *)p)->window), ((BrUtilTextWin *)p)->strbuf, font, (BrPair *)&xy);
    owner=((BrUtilTextWin *)p)->owner;
    PRINTSYS_PrintQueColor(owner,BMP_WIN_GetBmp(((BrUtilTextWin *)p)->bmp),(short)xy.x,(short)xy.y,(((BrUtilTextWin *)p)->strbuf),font,value);
    p[4]=1;
}

int BR_UTIL_FlushText(u8*p){void*owner=*(void* *)&((BrUtilTextWin *)p)->owner;if(p[4]){if(!PRINTSYS_QUE_IsExistTarget(owner,BMP_WIN_GetBmp(*(void* *)&((BrUtilTextWin *)p)->bmp))){BMP_WIN_TransferChars(*(void* *)&((BrUtilTextWin *)p)->bmp);p[4]=0;}}if(!p[4])return 1;return 0;}

void BR_UTIL_SetTextLayout(u8*p,u32 a,u32 b,u32 c){((BrUtilTextWin *)p)->alignMode=c;((BrUtilTextWin *)p)->layoutA=a;((BrUtilTextWin *)p)->layoutB=b;}

/*
 * extent: two zero alignment bytes follow the 86-byte function.
 */
void BR_UTIL_AlignText(int mode,BrPair *base,const void *bmp,void *text,void *font,BrPair *out)
{
    unsigned x,y;
    switch(mode) {
    case 0:*out=*base;break;
    case 1:
        x=(unsigned)BMP_GetWidth(bmp)>>1;y=(unsigned)BMP_GetHeight(bmp)>>1;
        x-=PRINTSYS_MeasureWidestLine(text,font,0)>>1;
        y-=PRINTSYS_CountLines(text,font)>>1;
        out->x=x+base->x;out->y=y+base->y;break;
    }
}

/*
 * lever: u16 heap and const Config pointer restore scheduling; bounded permuter count-before-limit restores the clamp registers. Resource before font gives the original spill slots.
 */
BrUtilListMenu *BR_UTIL_CreateListMenu(const BrUtilConfig *cfg,u16 heap)
{
    BrTriple arrows,marks;
    BrUtilRequest arrow,mark;
    BrUtilListMenu *p;
    int size,mode,count;
    int limit;
    u16 resource;
    sptr font;
    int i;
    size=cfg->count*4+0x8c;
    p=GFL_HEAP_Alloc(heap,size,0,d_02200D5C,0x1a1);
    MI_CpuFill8(p,0,size);
    p->cfg=*cfg;
    p->selected=0;p->last=cfg->count;
    p->visible=cfg->height/cfg->spacing;
    count=cfg->count;
    limit=p->visible;
    if((int)limit>count) limit=count;
    p->visible=limit;
    if(cfg->selection) {p->start=cfg->selection[0];p->index=cfg->selection[1];}
    if(p->cfg.mode==0) {
        for(i=0;i<p->visible;i++) {
            if(i>=10) GF_PANIC_Fail(d_02200D68,0,d_02200D68);
            p->areas[i].left=p->cfg.x*8;
            p->areas[i].top=(p->cfg.y+i*p->cfg.spacing)*8;
            p->areas[i].right=(p->cfg.x+p->cfg.width)*8;
            p->areas[i].bottom=(p->cfg.y+(i+1)*p->cfg.spacing)*8;
        }
        if(i>=10) GF_PANIC_Fail(d_02200D68,0,d_02200D68);
        p->areas[i].left=255;p->areas[i].top=255;p->areas[i].right=255;p->areas[i].bottom=255;
        p->methods[0]=(void (*)(void))BR_UTIL_ScrollRows;p->methods[1]=(void (*)(void))BR_UTIL_NeedsScroll;p->methods[2]=(void (*)(void))BR_UTIL_HandleRowTouch;
    } else if(p->cfg.mode==1) {
        p->methods[0]=(void (*)(void))BR_UTIL_ScrollWithCursor;p->methods[1]=(void (*)(void))BR_UTIL_HasMultipleRows;p->methods[2]=(void (*)(void))BR_UTIL_UpdateRowSelection;
        if(p->cfg.cursor) BR_UTIL_StartEffect((char *)p->cfg.cursor,5,(const BrPair *)&d_02200B0C[p->index]);
    }
    p->descriptor=(uptr)BMP_WIN_Create(cfg->bg,cfg->x,cfg->y,cfg->width,cfg->height,cfg->palette,1);
    BMP_WIN_MakeScreen((struct BmpWin *)p->descriptor);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)p->descriptor));
    i=0;
    MI_CpuFill8((void *)&arrow,0,8);
    if(cfg->bg<4) {
        BR_RES_LoadSprite((struct BrRes *)p->cfg.resources,7,heap);
        if(!BR_RES_GetSprite((struct BrRes *)p->cfg.resources,7,(void *)&arrows)) GF_PANIC_Fail((const char *)d_02200D68,0,(const char *)d_02200D68);
        mode=0;
    } else {
        BR_RES_LoadSprite((struct BrRes *)p->cfg.resources,8,heap);
        if(!BR_RES_GetSprite((struct BrRes *)p->cfg.resources,8,(void *)&arrows)) GF_PANIC_Fail((const char *)d_02200D68,0,(const char *)d_02200D68);
        mode=1;
    }
    arrow.x=128;arrow.flag=0;
    i=0;
    resource=mode;
    for(;i<2;i++) {
        if(cfg->mode==0) arrow.y=i==0?16:128;
        else arrow.y=i==0?64:184;
        arrow.id=i;
        p->handles[i]=(uptr)CLACT_CreateActor((struct Unit *)((void *)cfg->manager),arrows.y,arrows.z,arrows.x,(const struct ActorInitParam *)&arrow,resource,heap);
        CLACT_SetActorAutoAnim((struct ClactActor *)p->handles[i],1);CLACT_SetActorObjMode((struct ClactActor *)p->handles[i],1);
    }
    i=0;
    CLACT_SetActorDrawEnable((struct ClactActor *)p->handles[0],0);
    MI_CpuFill8((void *)&mark,0,8);
    mark.y=72;mark.id=5;mark.flag=0;
    if(!BR_RES_GetSprite((struct BrRes *)p->cfg.resources,6,(void *)&marks)) GF_PANIC_Fail((const char *)d_02200D68,0,(const char *)d_02200D68);
    for(i=2;i<4;i++) {
        mark.x=i==2?24:232;
        p->handles[i]=(uptr)CLACT_CreateActor((struct Unit *)((void *)p->cfg.manager),marks.y,marks.z,marks.x,(const struct ActorInitParam *)&mark,1,heap);
        CLACT_SetActorObjMode((struct ClactActor *)p->handles[i],1);
    }
    font=BR_RES_GetFont((struct BrRes *)p->cfg.resources);
    for(i=0;(u32)i<p->cfg.count;i++) {
        void *text;
        text=p->cfg.list[i].text;
        if(text) {
            p->bitmaps[i]=BMP_Create(p->cfg.width,p->cfg.spacing,32,heap);
            BMP_Clear(p->bitmaps[i],0);
            PRINTSYS_PrintColor(p->bitmaps[i],0,0,text,(void *)font,0x3da0);
        }
    }
    BR_UTIL_DrawListRows((char *)p,p->start);
    if(cfg->count<p->visible) {
        p->scroll=0;CLACT_SetActorDrawEnable((struct ClactActor *)p->handles[0],0);CLACT_SetActorDrawEnable((struct ClactActor *)p->handles[1],0);
    } else {
        p->scroll=1;
        if(p->scroll) {
            if(p->start==0) CLACT_SetActorDrawEnable((struct ClactActor *)p->handles[0],0);
            else CLACT_SetActorDrawEnable((struct ClactActor *)p->handles[0],1);
            if(p->cfg.count==p->start+p->visible) CLACT_SetActorDrawEnable((struct ClactActor *)p->handles[1],0);
            else CLACT_SetActorDrawEnable((struct ClactActor *)p->handles[1],1);
        }
    }
    if(BR_UTIL_ListMenuIsScrollable((char *)p)) for(i=2;i<4;i++) CLACT_SetActorAutoAnim((struct ClactActor *)p->handles[i],1);
    return p;
}

void BR_UTIL_DeleteListMenu(char *p)
{
    int i;
    if(((BrUtilListMenu *)p)->cfg.cursor) BR_UTIL_StartEffect((char *)((BrUtilListMenu *)p)->cfg.cursor,0,0);
    for(i=0;i<4;i++) CLACT_DeleteActor((struct ClactActor *)(*(int *)(p+0x28+i*4)));
    for(i=0;(unsigned)i<((BrUtilListMenu *)p)->cfg.count;i++) {
        if(((BrUtilListMenu *)p)->bitmaps[i] && ((BrUtilListMenu *)p)->cfg.list[i].text) BMP_Delete((struct Bmp *)((BrUtilListMenu *)p)->bitmaps[i]);
    }
    BMP_WIN_ClearScreen((struct BmpWin *)((BrUtilListMenu *)p)->descriptor);BMP_WIN_Delete((struct BmpWin *)((BrUtilListMenu *)p)->descriptor);
    if(((BrUtilListMenu *)p)->cfg.bg<4) BR_RES_ReleaseSprite((struct BrRes *)(((BrUtilListMenu *)p)->cfg.resources),7);
    else BR_RES_ReleaseSprite((struct BrRes *)(((BrUtilListMenu *)p)->cfg.resources),8);
    if(((BrUtilListMenu *)p)->cfg.selection) {
        ((BrUtilListMenu *)p)->cfg.selection[0]=((BrUtilListMenu *)p)->start;
        ((BrUtilListMenu *)p)->cfg.selection[1]=((BrUtilListMenu *)p)->index;
    }
    GFL_HEAP_Free(p);
}

void BR_UTIL_MainListMenu(char *p)
{
    if(BR_UTIL_ListMenuIsScrollable(p)) {
        ((BrUtilListMenu *)p)->dragDir=BR_UTIL_PollScrollDrag(p);
        if(((BrUtilListMenu *)p)->dragDir) {
            if(((int (*)(char *,int))*(int *)(p+0x50))(p,((BrUtilListMenu *)p)->dragDir)) {
                if(GFL_USE_IsSeqPlaying(0x6FE)==0) GFL_USE_PlaySeDefaultVolume(0x6FE);
                BR_UTIL_DrawListRows(p,((BrUtilListMenu *)p)->start);
            }
            if(((BrUtilListMenu *)p)->scroll) {
                if(((BrUtilListMenu *)p)->start==0) CLACT_SetActorDrawEnable((struct ClactActor *)*(int *)&((BrUtilListMenu *)p)->handles[0],0);
                else CLACT_SetActorDrawEnable((struct ClactActor *)*(int *)&((BrUtilListMenu *)p)->handles[0],1);
                if(((BrUtilListMenu *)p)->cfg.count==((BrUtilListMenu *)p)->start+((BrUtilListMenu *)p)->visible) CLACT_SetActorDrawEnable((struct ClactActor *)*(int *)&((BrUtilListMenu *)p)->handles[1],0);
                else CLACT_SetActorDrawEnable((struct ClactActor *)*(int *)&((BrUtilListMenu *)p)->handles[1],1);
            }
        }
    }
    ((void (*)(char *))*(int *)(p+0x58))(p);
}

int BR_UTIL_ListMenuIsScrollable(char *p){return (*(int(**)(char *))(p+0x54))(p);}

/*
 * leaf: S27 parent clearance; ov183 callers DFFB0 and E024C sole blocker.
 */
int BR_UTIL_GetListMenuHitId(char *p)
{
    return ((BrUtilListMenu *)p)->hitId;
}

void BR_UTIL_SetListItemBitmap(u8 *p, u16 i, u32 v)
{
    if(i>=*(u32 *)(p+4))GF_PANIC_Fail(d_02200D68,0,d_02200D68);
    if(*(u32 *)(*(u32 *)p+i*8)!=0)GF_PANIC_Fail(d_02200D68,0,d_02200D68);
    *(u32 *)((uptr)p+i*4+0x8c)=v;
}

u32 BR_UTIL_GetListItemBitmap(u8 *p, u16 i)
{
    if(i>=((BrUtilListMenu *)p)->cfg.count)GF_PANIC_Fail(d_02200D68,0,d_02200D68);
    return *(u32 *)((uptr)p+i*4+0x8c);
}

/*
 * extent: lead plus tail-call stub at 021FCE50.
 */
int BR_UTIL_GetListMenuField(char *p,unsigned field)
{
    switch(field) {
    case 0:return ((BrUtilListMenu *)p)->index;
    case 1:return ((BrUtilListMenu *)p)->start;
    case 2:return ((BrUtilListMenu *)p)->dragDir;
    case 3:return ((BrUtilListMenu *)p)->cfg.count;
    default:GF_PANIC_Fail(d_02200D68,0,d_02200D68);return 0;
    }
}

void BR_UTIL_RefreshList(char *p)
{
    BR_UTIL_DrawListRows(p,((BrUtilListMenu *)p)->start);
}

void BR_UTIL_DrawListRows(char *p,int start)
{
    int i,height;
    BMP_Clear((struct Bmp *)((sptr)BMP_WIN_GetBmp((struct BmpWin *)*(int *)&((BrUtilListMenu *)p)->descriptor)),0);
    for(i=start;i<start+((BrUtilListMenu *)p)->visible;i++) {
        if((unsigned)i<((BrUtilListMenu *)p)->cfg.count && ((BrUtilListView *)p)->bitmap[i]) {
            height=((BrUtilListMenu *)p)->cfg.spacing;
            BR_UTIL_BlitRows(((BrUtilListView *)p)->bitmap[i],(sptr)BMP_WIN_GetBmp((struct BmpWin *)*(int *)&((BrUtilListMenu *)p)->descriptor),0,0,0,(i-start)*height,((BrUtilListMenu *)p)->cfg.width,height);
        }
    }
    BMP_WIN_TransferChars((struct BmpWin *)*(int *)&((BrUtilListMenu *)p)->descriptor);
}

int BR_UTIL_PollScrollDrag(char *p)
{
    int x,y;
    int direction=0;
    int delta,absolute;
    if(TOUCHPANEL_HitCont((const TouchHitTable *)d_02200AF0)!=-1) {
        TOUCHPANEL_GetPointCont((u32 *)(&x),(u32 *)(&y));
        if(((BrUtilListMenu *)p)->dragActive==0) {((BrUtilListMenu *)p)->dragActive=1;((BrUtilListMenu *)p)->dragY=y;}
        else {
            delta=y-((BrUtilListMenu *)p)->dragY;
            if(delta<0) absolute=-delta;else absolute=delta;
            if(absolute>8) {
                if(delta<0) direction=-1;else direction=1;
                ((BrUtilListMenu *)p)->dragY=y;
            }
        }
    } else if(((BrUtilListMenu *)p)->dragActive) ((BrUtilListMenu *)p)->dragActive=0;
    return direction;
}

/*
 * extent: 80-byte scrolling follower filed as BR_UTIL_ScrollRows.c.
 * lever: width-first multiply preserves the stack load and register order.
 */
void BR_UTIL_BlitRows(int dest,int src,int dx,int dy,unsigned short sx,unsigned short sy,unsigned short width,unsigned short height)
{
    char *d,*s;
    int doff,soff;
    d=BMP_GetPixels((const struct Bmp *)dest);s=BMP_GetPixels((const struct Bmp *)src);
    doff=width*dy+dx;
    soff=width*sy+sx;
    MIi_CpuCopy32(d+doff*32,s+soff*32,width*height*32);
}

/*
 * follower: scroll range update after BR_UTIL_BlitRows.
 */
int BR_UTIL_ScrollRows(char *p,int change)
{
    if(((BrUtilListMenu *)p)->start!=0 && change==-1) {
        ((BrUtilListMenu *)p)->start+=(unsigned short)change;
        return 1;
    }
    if(((BrUtilListMenu *)p)->start+((BrUtilListMenu *)p)->visible<((BrUtilListMenu *)p)->cfg.count && change==1) {
        ((BrUtilListMenu *)p)->start+=(unsigned short)change;
        return 1;
    }
    return 0;
}

/*
 * followers: unlabelled store-free accessors 021FD094 and 021FD0A8 included; final 2-byte alignment outside TU length.
 */
int BR_UTIL_ScrollWithCursor(char *p,int step)
{
    int count,changed,half;
    count=((BrUtilListMenu *)p)->visible;
    changed=0;
    half=(count-1)/2+(count-1)%2;
    if(step>0) {
        if(half==((BrUtilListMenu *)p)->index && (u32)(((BrUtilListMenu *)p)->start+count)<((BrUtilListMenu *)p)->cfg.count) {
            ((BrUtilListMenu *)p)->start+=(u16)step;changed=1;
        } else if((u32)(((BrUtilListMenu *)p)->start+((BrUtilListMenu *)p)->index)<((BrUtilListMenu *)p)->cfg.count-1) {
            ((BrUtilListMenu *)p)->index+=(u16)step;changed=1;
        }
    } else if(step<0) {
        if(half==((BrUtilListMenu *)p)->index && ((BrUtilListMenu *)p)->start) {
            ((BrUtilListMenu *)p)->start+=(u16)step;changed=1;
        } else if(((BrUtilListMenu *)p)->index) {
            ((BrUtilListMenu *)p)->index+=(u16)step;changed=1;
        }
    }
    if(changed && ((BrUtilListMenu *)p)->cfg.cursor) BR_UTIL_StartEffect((char *)((BrUtilListMenu *)p)->cfg.cursor,5,&d_02200B0C[((BrUtilListMenu *)p)->index]);
    return changed;
}

int BR_UTIL_NeedsScroll(char *p) { return ((BrUtilListMenu *)p)->cfg.count>=((BrUtilListMenu *)p)->visible; }

int BR_UTIL_HasMultipleRows(char *p) { return ((BrUtilListMenu *)p)->cfg.count>1; }

/*
 * extent: accessor at 021FD110 filed separately, then two zero alignment bytes.
 */
void BR_UTIL_HandleRowTouch(char *p)
{
    int x,y;
    BrPair pair;
    int result;
    ((BrUtilListMenu *)p)->hitId=-1;
    result=TOUCHPANEL_HitTrg((const TouchHitTable *)(p+0x5C));
    if(result!=-1) {
        if(((BrUtilListMenu *)p)->cfg.other) {
            TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));pair.x=x;pair.y=y;
            BR_UTIL_StartEffect((char *)((BrUtilListMenu *)p)->cfg.other, 1, (const BrPair *)&pair);
        }
        GFL_USE_PlaySeDefaultVolume(0x703);
        ((BrUtilListMenu *)p)->hitId=((int *)((sptr)((BrUtilListMenu *)p)->cfg.list+(result+((BrUtilListMenu *)p)->start)*8))[1];
    }
}

/*
 * follower: accessor after BR_UTIL_HandleRowTouch; two alignment bytes after return.
 */
void BR_UTIL_UpdateRowSelection(char *p)
{
    ((BrUtilListMenu *)p)->hitId=((int *)((sptr)((BrUtilListMenu *)p)->cfg.list+(((BrUtilListMenu *)p)->index+((BrUtilListMenu *)p)->start)*8))[1];
}

void *BR_UTIL_CreateTextWin(void *a, void *owner, u16 heap)
{
    u8 *p;
    BR_RES_LoadBgGraphics((void *)a,2,heap);
    p=BR_UTIL_Create(0,1,19,30,4,2,owner,heap);
    ((BrUtilTextWin *)p)->clearColor=12;
    return p;
}

void BR_UTIL_DeleteTextWin(void *p, int res)
{
    BR_UTIL_Delete(p);
    BR_RES_ApplyBgSet((void *)res, 2);
}

void BR_UTIL_SetWindowText(char *p,char *q,void *text)
{
    uptr font;
    font=BR_RES_GetFont((struct BrRes *)q);
    BR_UTIL_SetTextFromMessage(p,(void *)BR_RES_GetMsgData((struct BrRes *)q),text,(void *)font,0x3dac);
}

void BR_UTIL_SetWindowTextBuf(char *p,void *q,void *text)
{
    BR_UTIL_SetTextFromBuffer(p,text,(void *)BR_RES_GetFont(q),0x3dac);
}

/*
 * note: 2026-10-05 integrator: label left open after the pengy waves; written from the listing.
 */
void BR_UTIL_FlushWindow(void *p)
{
    BR_UTIL_FlushText(p);
}

/*
 * 2026-10-05 (wave P2, lane Q6, pengy share): first full draft, 1148 B,
 * same size as the original, 12 bytes differ. Constructor of the GDS
 * profile screen (pair of BR_UTIL_DeleteProfileScreen, the matched destructor): 0x44 B
 * object, 7 text windows from the 8-byte table d_02200B34 (switch on the
 * row: 0 name, 1 and 3 and 4 number rows, 6 optional record with a
 * fallback draw, 2 and 5 plain message), then an arc load that builds the
 * object at +0x24 when the profile has a icon and a second one at +0x28
 * chosen by mode (0, 1, other). The earlier layout residue is closed:
 * the table row is read as d_02200B34[i].f at every use (CSE gives the
 * r6 address), the pair constant d_02200B6C is read twice by initialiser
 * (BrUtilPair b = d at function level, BrUtilPair c = d in case 6, which gives the
 * hidden copy at [sp,#0x38]), the two position records are memset with
 * MI_CpuFill8(&r,0,8) then only x,y,z / x,y are stored, hf is a u32 so
 * the u16 truncation is repeated per call, mode is a switch.
 * Residue (12 B, two spots): (1) in the icon block the original builds the
 * z=1 store and the later CLACT_SetActorObjMode(obj,1) argument with separate
 * movs r1,#1; mine pools the 1 in r7 (movs r7,#1; strh r7; adds r1,r7,#0).
 * (2) in mode 0 the original schedules movs r7,#4 and movs r7,#6 before the
 * str of k2 (the [sp,#0x20] slot); mine stores first. Tried, no change:
 * store order z first (moves the pooled 1 earlier), scheduling off,
 * opt_lifetimes off. opt_common_subs off breaks the whole body. Not
 * tried: opt_propagation off, peephole off, opt_dead_assignments off.
 * Callee prototypes for the unlabelled arm9 getters GDS_PROFILE_GetSpecies,
 * 70C, 72C, 73C, 810, 820 are guessed (u32 f(void *)); GDS_PROFILE_ExportRecord
 * takes the 4-halfword record out pointer.
 *
 * 2026-10-05 (wave P2, lane Q6b): 12 B -> 4 B, and now compiles in --lang c
 * (BrUtilPair b moved into a block that wraps the row loop, Req r declared at the
 * top of its block). Residue (2) closed: assign k3 first in each mode-0 arm
 * (k3=4;k1=0x14;k2=0x12;k4=0x13; and k3=6;k1=0x17;...), which gives the
 * original's movs r7 before the str to [sp,#0x20]; k1,k3,k2,k4 also works.
 * Residue left (4 B, icon block): original `movs r1,#1; strh r1,[r0,#0x14]`
 * and later `movs r1,#1` for CLACT_SetActorObjMode(obj,1); mine pools the 1 in r7
 * (movs r7,#1; strh r7; adds r1,r7,#0). Pragmas opt_propagation off and
 * opt_dead_assignments off break the whole body (960+ B); peephole off: no
 * change. Tried, no change: B688 second parameter u8 or int; Req as
 * {short x,y,z;u8 a,b} (the ov183 021DCBD8 Position shape); z and the B688
 * argument spelled as an enum TRUE (each alone); z from a u16 local and the
 * argument from an int local; Req as u16 r[4]. In block 2 the same two 1s
 * (B6F4 arg and B688 arg, call between) are not pooled, so the pooling is
 * caused by the strh of a constant before the call; no source spelling found
 * that keeps the store value apart from the later argument.
 *
 * 2026-10-05 (wave P2, lane Q6c): still 4 B (same icon-block residue). New
 * tries, all unchanged (movs r7,#1; strh r7; adds r1,r7,#0): z=1 inside a
 * static inline SetPos(&r,x,y) (ov183 021DCBD8 shape); z and the B688 argument
 * both as enum BOOL TRUE; z as 1u; z as (u16)1; z stored between x and y;
 * B688 prototype unprototyped (K&R); object kept in a local `icon` (breaks
 * the body: the original reloads [r4,#0x24]); B688 (alone, or with B6F4) moved
 * into a second `if(B)` (the branch stays and B moves to r7, breaks layout);
 * one function-level Req shared by both blocks (moves the slots); pragmas
 * opt_lifetimes off and scheduling off on the current shape. z first moves the
 * pooled 1 to the top (as before). Reading: docs/idioms/a-repeated-constant-
 * pools-only-within-one-block-... says the pooler works per block, so the
 * original probably has a block boundary between the strh and the B688 call
 * that emits no branch; none found. In block 2 the same two 1s (both call
 * arguments, precoloured r2 and r1) do not pool, so only a store operand 1
 * followed by an argument 1 merges. Not tried: opt_common_subs off alone
 * (breaks the body per Q6).
 *
 * recoup 2026-10-05 (lane R10): still 4 B, same icon-block residue
 * (movs r7,#1; strh r7; adds r1,r7,#0 vs original movs r1,#1 twice). New
 * tries, all unchanged or worse: tail B6F4+B688 as a static inline (1152 B,
 * 326 off); opt_common_subs off alone (1176 B); z stored through
 * *(u16 *)((char *)&r+4) (4 B); z as *(u32 *)&r.z (5 B); B688 argument as
 * r.z (14 B); Req reached through a pointer rp (4 B); block locals declared
 * Req first, or Req then hf,h,t (4 B each); B688 second parameter u16, short
 * or char (4 B each). Matched twins read: ov183 021DF428 and 021DCBD8,
 * ov208 021C0B6C, ov206 021BB304 and 021BB534 (none has a strh of 1 before a
 * later literal 1 argument in one block). Reading: only a store operand 1
 * followed by an argument 1 merges, and no real source form splits them.
 *
 * final push 2026-10-05 G1L6: still 4 B (same icon-block residue). Research
 * first (idioms: repeated-constant-pools-only-within-one-block, repeated-small-
 * constant-takes-a-callee-saved-register, small-constant-is-rematerialised...,
 * store-stays-above-the-argument-constant, pool-constant-kept-live-past-a-join,
 * narrow-flag-local-is-spilled, sub-word-parameter-type..., one-element-array-
 * initialiser; twins ov183 021DCBD8/021DF428, ov206, ov208, ov218 021BA328:
 * none has a constant strh then a literal 1 argument in one block with a free
 * register). New tries, bytes off: aggregate initialiser `Req r={0x4b,0x40,1,0}`
 * (246 B: compiler copies the record from a pool table, no memset); do/while(0)
 * around B6F4+B688 (4); mid-function `#pragma opt_common_subs off` before the
 * if(B) (1093); B688 through a static inline SetVis(obj,v) or SetVis(obj) (4
 * each); stores through a static inline SetReq(&r,x,y,z) with int or u16
 * params (4 each); Req of short fields with B688 arg 1u (4); z as 1u with arg
 * -1+2 (4); keeping h live past the stores (ARC_TOOL_DeleteHandle moved after B688)
 * to test register pressure: still pooled (r6 instead of r7), so pressure is
 * not the cause; the whole icon block as a static inline MakeIcon (11 B, slots
 * move, still pooled). Conclusion unchanged: store operand 1 followed by an
 * argument 1 in one block always merges; no human source form found.
 *
 * final push 2026-10-05 G1R5: still 4 B (same icon-block residue). Control
 * test: B688 argument 2 instead of 1 gives 1 B off (only the constant), so
 * the merge is a plain value-number CSE of the two literal 1s, and with them
 * apart the whole block matches. New tries, all 4 B (movs r7,#1 pooled) unless
 * noted: Req stores and B294 in an inner block; function-level int vis=1 for
 * the argument, and for both z and argument; goto/label, switch(1), for(;;)
 * around B6F4+B688; z through a u16 *zp; B688 argument as (u8)1, (u16)1,
 * (char)1, (short)1, 1u, 1L, (u32)1, (unsigned long)1; per-function pragmas
 * opt_strength_reduction, opt_dead_code, opt_unroll_loops, opt_vectorize_loops,
 * optimize_for_size off (no change), opt_loop_invariants off (948 B off);
 * argument as B!=0, B>0, !!B, mode>=0 (real compares, 328+ B off); z stored
 * after B294 (42 B off, registers shift). Matched-assembly search (strh of a
 * fresh movs #1 followed later by a fresh movs #1 before a call): hits ov070
 * 021B6A14, 021B7688, 021B7CD0 (p->f83E = 1 then B92C(..,1), BB3F4(p,1)), plus
 * ov103/ov170/ov035 with no call-arg 1. ov070 021B6A14's C stores through a
 * pointer member and does not merge; our store goes to an address-taken stack
 * record and merges. No source form found that separates them.
 *
 * pass 2 2026-10-06 P2L06: still 4 B (same icon-block residue), form unchanged.
 * 40 compiles. Findings: compiler pins dsi/1.2 and 1.3 give the same 4 B, 1.6sp2
 * 7 lines, 2.0 1188 B. opt_common_subs off and optimization_level 3 keep the
 * merge (it is backend, not IRO CSE). Diagnostics: replacing BB5C(B,C,D,A) by
 * constants (or the B6F4 argument by 5) removes the merge, so it appears only
 * while the spilled A..D stay live across the icon tail; tiny repros never merge
 * the 1. Stores through a walking or indexed u16 pointer from &r.x also remove
 * the merge but use r6 as the base instead of sp+0x70 (60 lines off). Tried, all
 * 4 B: A..D as a local struct, a u32 info[4] array, an array with a call
 * initialiser, BB5C result in a local, one function-level h, declaration orders
 * of A..D and of the icon-block locals, z first, B294 stack arg changes.
 * Open lead: a form that keeps A..D in real memory (not spilled registers).
 *
 * pass 3 2026-10-06 P3L02: EXACT (c99 and c). The icon-block residue was the
 * callee declaration, not the block: CLACT_SetActorPaletteOffset declared `void *` (returns
 * its object) instead of `void`. With a void declaration r0 is dead after the
 * call and mwcc keeps the constant 1 in r7 across it (store z=1, later
 * CLACT_SetActorObjMode(obj,1)); with a value return it rebuilds `movs r1,#1` at each
 * use, as the image does (docs/idioms/a-callee-declared-void-that-returns-a-
 * value-changes-later-constant-copies.md). Evidence: the ARM body of
 * CLACT_SetActorPaletteOffset (src/matched/arm9/unit_0204B6F4.c, written there as void) never
 * writes r0, so it is byte-identical to a definition that ends `return o;`.
 * The integrator should know that the matched definition is spelled void.
 * Also: t inlined into the CLACT_RegisterCellAnim call (same bytes, one fewer local).
 */
/*
 * 2026-10-05 (wave P2, lane Q6, pengy share): first full draft, 1148 B,
 * same size as the original, 12 bytes differ. Constructor of the GDS
 * profile screen (pair of BR_UTIL_DeleteProfileScreen, the matched destructor): 0x44 B
 * object, 7 text windows from the 8-byte table d_02200B34 (switch on the
 * row: 0 name, 1 and 3 and 4 number rows, 6 optional record with a
 * fallback draw, 2 and 5 plain message), then an arc load that builds the
 * object at +0x24 when the profile has a icon and a second one at +0x28
 * chosen by mode (0, 1, other). The earlier layout residue is closed:
 * the table row is read as d_02200B34[i].f at every use (CSE gives the
 * r6 address), the pair constant d_02200B6C is read twice by initialiser
 * (Pair b = d at function level, Pair c = d in case 6, which gives the
 * hidden copy at [sp,#0x38]), the two position records are memset with
 * MI_CpuFill8(&r,0,8) then only x,y,z / x,y are stored, hf is a u32 so
 * the u16 truncation is repeated per call, mode is a switch.
 * Residue (12 B, two spots): (1) in the icon block the original builds the
 * z=1 store and the later CLACT_SetActorObjMode(obj,1) argument with separate
 * movs r1,#1; mine pools the 1 in r7 (movs r7,#1; strh r7; adds r1,r7,#0).
 * (2) in mode 0 the original schedules movs r7,#4 and movs r7,#6 before the
 * str of k2 (the [sp,#0x20] slot); mine stores first. Tried, no change:
 * store order z first (moves the pooled 1 earlier), scheduling off,
 * opt_lifetimes off. opt_common_subs off breaks the whole body. Not
 * tried: opt_propagation off, peephole off, opt_dead_assignments off.
 * Callee prototypes for the unlabelled arm9 getters GDS_PROFILE_GetSpecies,
 * 70C, 72C, 73C, 810, 820 are guessed (u32 f(void *)); GDS_PROFILE_ExportRecord
 * takes the 4-halfword record out pointer.
 *
 * 2026-10-05 (wave P2, lane Q6b): 12 B -> 4 B, and now compiles in --lang c
 * (Pair b moved into a block that wraps the row loop, Req r declared at the
 * top of its block). Residue (2) closed: assign k3 first in each mode-0 arm
 * (k3=4;k1=0x14;k2=0x12;k4=0x13; and k3=6;k1=0x17;...), which gives the
 * original's movs r7 before the str to [sp,#0x20]; k1,k3,k2,k4 also works.
 * Residue left (4 B, icon block): original `movs r1,#1; strh r1,[r0,#0x14]`
 * and later `movs r1,#1` for CLACT_SetActorObjMode(obj,1); mine pools the 1 in r7
 * (movs r7,#1; strh r7; adds r1,r7,#0). Pragmas opt_propagation off and
 * opt_dead_assignments off break the whole body (960+ B); peephole off: no
 * change. Tried, no change: B688 second parameter u8 or int; Req as
 * {short x,y,z;u8 a,b} (the ov183 021DCBD8 Position shape); z and the B688
 * argument spelled as an enum TRUE (each alone); z from a u16 local and the
 * argument from an int local; Req as u16 r[4]. In block 2 the same two 1s
 * (B6F4 arg and B688 arg, call between) are not pooled, so the pooling is
 * caused by the strh of a constant before the call; no source spelling found
 * that keeps the store value apart from the later argument.
 *
 * 2026-10-05 (wave P2, lane Q6c): still 4 B (same icon-block residue). New
 * tries, all unchanged (movs r7,#1; strh r7; adds r1,r7,#0): z=1 inside a
 * static inline SetPos(&r,x,y) (ov183 021DCBD8 shape); z and the B688 argument
 * both as enum BOOL TRUE; z as 1u; z as (u16)1; z stored between x and y;
 * B688 prototype unprototyped (K&R); object kept in a local `icon` (breaks
 * the body: the original reloads [r4,#0x24]); B688 (alone, or with B6F4) moved
 * into a second `if(B)` (the branch stays and B moves to r7, breaks layout);
 * one function-level Req shared by both blocks (moves the slots); pragmas
 * opt_lifetimes off and scheduling off on the current shape. z first moves the
 * pooled 1 to the top (as before). Reading: docs/idioms/a-repeated-constant-
 * pools-only-within-one-block-... says the pooler works per block, so the
 * original probably has a block boundary between the strh and the B688 call
 * that emits no branch; none found. In block 2 the same two 1s (both call
 * arguments, precoloured r2 and r1) do not pool, so only a store operand 1
 * followed by an argument 1 merges. Not tried: opt_common_subs off alone
 * (breaks the body per Q6).
 *
 * recoup 2026-10-05 (lane R10): still 4 B, same icon-block residue
 * (movs r7,#1; strh r7; adds r1,r7,#0 vs original movs r1,#1 twice). New
 * tries, all unchanged or worse: tail B6F4+B688 as a static inline (1152 B,
 * 326 off); opt_common_subs off alone (1176 B); z stored through
 * *(u16 *)((char *)&r+4) (4 B); z as *(u32 *)&r.z (5 B); B688 argument as
 * r.z (14 B); Req reached through a pointer rp (4 B); block locals declared
 * Req first, or Req then hf,h,t (4 B each); B688 second parameter u16, short
 * or char (4 B each). Matched twins read: ov183 021DF428 and 021DCBD8,
 * ov208 021C0B6C, ov206 021BB304 and 021BB534 (none has a strh of 1 before a
 * later literal 1 argument in one block). Reading: only a store operand 1
 * followed by an argument 1 merges, and no real source form splits them.
 *
 * final push 2026-10-05 G1L6: still 4 B (same icon-block residue). Research
 * first (idioms: repeated-constant-pools-only-within-one-block, repeated-small-
 * constant-takes-a-callee-saved-register, small-constant-is-rematerialised...,
 * store-stays-above-the-argument-constant, pool-constant-kept-live-past-a-join,
 * narrow-flag-local-is-spilled, sub-word-parameter-type..., one-element-array-
 * initialiser; twins ov183 021DCBD8/021DF428, ov206, ov208, ov218 021BA328:
 * none has a constant strh then a literal 1 argument in one block with a free
 * register). New tries, bytes off: aggregate initialiser `Req r={0x4b,0x40,1,0}`
 * (246 B: compiler copies the record from a pool table, no memset); do/while(0)
 * around B6F4+B688 (4); mid-function `#pragma opt_common_subs off` before the
 * if(B) (1093); B688 through a static inline SetVis(obj,v) or SetVis(obj) (4
 * each); stores through a static inline SetReq(&r,x,y,z) with int or u16
 * params (4 each); Req of short fields with B688 arg 1u (4); z as 1u with arg
 * -1+2 (4); keeping h live past the stores (ARC_TOOL_DeleteHandle moved after B688)
 * to test register pressure: still pooled (r6 instead of r7), so pressure is
 * not the cause; the whole icon block as a static inline MakeIcon (11 B, slots
 * move, still pooled). Conclusion unchanged: store operand 1 followed by an
 * argument 1 in one block always merges; no human source form found.
 *
 * final push 2026-10-05 G1R5: still 4 B (same icon-block residue). Control
 * test: B688 argument 2 instead of 1 gives 1 B off (only the constant), so
 * the merge is a plain value-number CSE of the two literal 1s, and with them
 * apart the whole block matches. New tries, all 4 B (movs r7,#1 pooled) unless
 * noted: Req stores and B294 in an inner block; function-level int vis=1 for
 * the argument, and for both z and argument; goto/label, switch(1), for(;;)
 * around B6F4+B688; z through a u16 *zp; B688 argument as (u8)1, (u16)1,
 * (char)1, (short)1, 1u, 1L, (u32)1, (unsigned long)1; per-function pragmas
 * opt_strength_reduction, opt_dead_code, opt_unroll_loops, opt_vectorize_loops,
 * optimize_for_size off (no change), opt_loop_invariants off (948 B off);
 * argument as B!=0, B>0, !!B, mode>=0 (real compares, 328+ B off); z stored
 * after B294 (42 B off, registers shift). Matched-assembly search (strh of a
 * fresh movs #1 followed later by a fresh movs #1 before a call): hits ov070
 * 021B6A14, 021B7688, 021B7CD0 (p->f83E = 1 then B92C(..,1), BB3F4(p,1)), plus
 * ov103/ov170/ov035 with no call-arg 1. ov070 021B6A14's C stores through a
 * pointer member and does not merge; our store goes to an address-taken stack
 * record and merges. No source form found that separates them.
 *
 * pass 2 2026-10-06 P2L06: still 4 B (same icon-block residue), form unchanged.
 * 40 compiles. Findings: compiler pins dsi/1.2 and 1.3 give the same 4 B, 1.6sp2
 * 7 lines, 2.0 1188 B. opt_common_subs off and optimization_level 3 keep the
 * merge (it is backend, not IRO CSE). Diagnostics: replacing BB5C(B,C,D,A) by
 * constants (or the B6F4 argument by 5) removes the merge, so it appears only
 * while the spilled A..D stay live across the icon tail; tiny repros never merge
 * the 1. Stores through a walking or indexed u16 pointer from &r.x also remove
 * the merge but use r6 as the base instead of sp+0x70 (60 lines off). Tried, all
 * 4 B: A..D as a local struct, a u32 info[4] array, an array with a call
 * initialiser, BB5C result in a local, one function-level h, declaration orders
 * of A..D and of the icon-block locals, z first, B294 stack arg changes.
 * Open lead: a form that keeps A..D in real memory (not spilled registers).
 *
 * pass 3 2026-10-06 P3L02: EXACT (c99 and c). The icon-block residue was the
 * callee declaration, not the block: CLACT_SetActorPaletteOffset declared `void *` (returns
 * its object) instead of `void`. With a void declaration r0 is dead after the
 * call and mwcc keeps the constant 1 in r7 across it (store z=1, later
 * CLACT_SetActorObjMode(obj,1)); with a value return it rebuilds `movs r1,#1` at each
 * use, as the image does (docs/idioms/a-callee-declared-void-that-returns-a-
 * value-changes-later-constant-copies.md). Evidence: the ARM body of
 * CLACT_SetActorPaletteOffset (src/matched/arm9/unit_0204B6F4.c, written there as void) never
 * writes r0, so it is byte-identical to a definition that ends `return o;`.
 * The integrator should know that the matched definition is spelled void.
 * Also: t inlined into the CLACT_RegisterCellAnim call (same bytes, one fewer local).
 */
char *BR_UTIL_CreateProfileScreen(void *prof,char *q,void *unit,void *printQue,int mode,u16 heap)
{
    char *p;
    void *font;
    int i;
    void *bank;
    void *words;
    int ready;
    u32 k2,k1,k3,k4;
    void *text;
    u32 A,B,C,D;
    p=GFL_HEAP_Alloc(heap,0x44,0,d_02200D5C,0x541);
    MI_CpuFill8(p,0,0x44);
    *(char **)(p+0x1c)=q;
    font=(void *)BR_RES_GetFont((struct BrRes *)q);
    *(void **)(p+0x20)=PMS_DRAW_Create((uptr)unit,0,(uptr)printQue,(uptr)font,7,1,heap);
    PMS_DRAW_SetDecoPriority(*(void **)(p+0x20),0,1);
    BR_RES_LoadBgGraphics(*(void **)(p+0x1c),8,heap);
    bank=(void *)(u32)BR_RES_GetMsgData((struct BrRes *)q);
    words=(void *)(u32)BR_RES_GetWordSet((struct BrRes *)q);
    {
    BrUtilPair b=d_02200B6C;
    for(i=0;i<7;i++) {
        *(void **)(p+i*4)=BR_UTIL_Create(1,d_02200B34[i].x,d_02200B34[i].y,d_02200B34[i].w,d_02200B34[i].h,14,printQue,heap);
        BR_UTIL_SetTextLayout(*(void **)(p+i*4),0,1,0);
        ready=1;
        switch(i) {
        case 0:
            {
            void *name;
            void *msg;
            text=STRBUF_Create(0x80,(u16)heap);
            name=GDS_PROFILE_CreateNameStr(prof,heap);
            msg=MSGDATA_AllocString(bank,d_02200B34[i].msg);
            WORDSET_SetSlotTag(words,0,name,GDS_PROFILE_GetEggFlag(prof),1,2);
            WORDSET_CopyTaggedText(words,text,msg);
            STRBUF_Delete(name);
            STRBUF_Delete(msg);
            break;
            }
        case 1:
            {
            u32 v;
            void *msg;
            v=GDS_PROFILE_GetBirthMonth(prof);
            text=STRBUF_Create(0x80,(u16)heap);
            msg=MSGDATA_AllocString(bank,d_02200B34[i].msg);
            WORDSET_SetSlotMonth(words,0,v);
            WORDSET_CopyTaggedText(words,text,msg);
            STRBUF_Delete(msg);
            break;
            }
        case 3:
            {
            u32 v;
            void *msg;
            v=GDS_PROFILE_GetValidatedCountry(prof);
            text=STRBUF_Create(0x80,(u16)heap);
            msg=MSGDATA_AllocString(bank,d_02200B34[i].msg);
            WORDSET_SetSlotFromMsgE7(words,0,v);
            WORDSET_CopyTaggedText(words,text,msg);
            STRBUF_Delete(msg);
            BR_UTIL_SetTextLayout(*(void **)(p+i*4),8,1,0);
            break;
            }
        case 4:
            {
            u32 v,w;
            void *msg;
            v=GDS_PROFILE_GetValidatedCountry(prof);
            w=GDS_PROFILE_GetValidatedRegion(prof);
            text=STRBUF_Create(0x80,(u16)heap);
            msg=MSGDATA_AllocString(bank,d_02200B34[i].msg);
            WORDSET_SetSlotFromKeyedMessage(words,0,v,w);
            WORDSET_CopyTaggedText(words,text,msg);
            STRBUF_Delete(msg);
            BR_UTIL_SetTextLayout(*(void **)(p+i*4),8,1,0);
            break;
            }
        case 6:
            {
            u16 rec[4];
            void *msg;
            msg=GDS_PROFILE_ExportRecord(prof,(struct GdsRecord *)rec,heap);
            if(msg) {
                text=STRBUF_Clone(msg,heap);
                STRBUF_Delete(msg);
                BR_UTIL_SetTextLayout(*(void **)(p+i*4),8,1,0);
            } else {
                BrUtilPair c=d_02200B6C;
                PMS_DRAW_SetNullColorPalette(*(void **)(p+0x20),0);
                PMS_DRAW_SetPrintColor(*(void **)(p+0x20),0x3da0);
                PMS_DRAW_PrintOffset(*(void **)(p+0x20),(void *)((*(void **)(*(char **)(p+i*4)+0xc))),(void *)rec,0,(&c));
                ready=0;
            }
            break;
            }
        default:
            text=MSGDATA_AllocString(bank,d_02200B34[i].msg);
            break;
        }
        if(ready) {
            BR_UTIL_SetTextFromBuffer(*(void **)(p+i*4),text,font,0x3da0);
            STRBUF_Delete(text);
        }
    }
    }
    A=GDS_PROFILE_GetBadEggFlag(prof);
    B=GDS_PROFILE_GetSpecies(prof);
    C=GDS_PROFILE_GetFormSpecies(prof);
    D=GDS_PROFILE_GetNicknameFlag(prof);
    if(B) {
        u32 hf;
        void *h;
        BrUtilReq r;
        hf=(heap&0x7fff)|0x8000;
        h=ARC_TOOL_CreateHandle(7,hf);
        *(int *)(p+0x2c)=CLACT_RegisterPaletteCompressed(h,POKE_TOOL_GetIconPaletteArcId(),0,0x80,hf);
        *(int *)(p+0x34)=CLACT_RegisterCellAnim(h,POKE_TOOL_GetIconCellArcId(),POKE_TOOL_GetIconCellEntryId(),(u16)hf);
        *(int *)(p+0x30)=CLACT_RegisterCharacter(h,POKE_TOOL_CalcGraphicIndex(B,C,D,A),0,0,hf);
        ARC_TOOL_DeleteHandle((void *)h);
        MI_CpuFill8((void *)&r,0,8);
        r.x=0x4b;r.y=0x40;r.z=1;
        *(void **)(p+0x24)=CLACT_CreateActor((struct Unit *)unit,*(u32 *)(p+0x30),*(u32 *)(p+0x2c),*(u32 *)(p+0x34),(const struct ActorInitParam *)&r,0,heap);
        CLACT_SetActorPaletteOffset(*(void **)(p+0x24),POKE_TOOL_CalcIconPalette(B,C,D,A),0);
        CLACT_SetActorObjMode(*(void **)(p+0x24),1);
    }
    switch(mode) {
    case 0:
        {
        void *h;
        if(!GDS_PROFILE_GetEggFlag(prof)) {
            k3=4;k1=0x14;k2=0x12;k4=0x13;
        } else {
            k3=6;k1=0x17;k2=0x15;k4=0x16;
        }
        h=ARC_TOOL_CreateHandle(0x1f,(heap&0x7fff)|0x8000);
        *(int *)(p+0x38)=CLACT_RegisterPaletteEx(h,k3,0,0x1a0,0,1,heap);
        *(int *)(p+0x40)=CLACT_RegisterCellAnim(h,k2,k4,(u16)heap);
        *(int *)(p+0x3c)=CLACT_RegisterCharacter(h,k1,0,0,heap);
        ARC_TOOL_DeleteHandle(h);
        break;
        }
    case 1:
        {
        u32 k;
        void *h;
        k=GDS_PROFILE_GetTrainerSprite(prof);
        h=ARC_TOOL_CreateHandle(0x20,(heap&0x7fff)|0x8000);
        *(int *)(p+0x38)=CLACT_RegisterPaletteEx(h,0,0,0x1a0,d_02200AFC[k],1,heap);
        *(int *)(p+0x40)=CLACT_RegisterCellAnim(h,0x41,0x42,(u16)heap);
        *(int *)(p+0x3c)=CLACT_RegisterCharacter(h,k+0x31,0,0,heap);
        ARC_TOOL_DeleteHandle(h);
        break;
        }
    }
    {
        BrUtilReq r;
        MI_CpuFill8((void *)&r,0,8);
        r.x=0x30;r.y=0x40;
        *(void **)(p+0x28)=CLACT_CreateActor((struct Unit *)unit,*(u32 *)(p+0x3c),*(u32 *)(p+0x38),*(u32 *)(p+0x40),(const struct ActorInitParam *)&r,0,heap);
        CLACT_SetActorPaletteOffset(*(void **)(p+0x28),0,1);
        CLACT_SetActorObjMode(*(void **)(p+0x28),1);
    }
    return p;
}

void BR_UTIL_DeleteProfileScreen(int *p)
{
    int i;
    if(p[10]) {CLACT_DeleteActor((struct ClactActor *)p[10]);CLACT_ReleasePalette(p[14]);CLACT_ReleaseCharacter(p[15]);CLACT_ReleaseCellAnim(p[16]);}
    if(p[9]) {CLACT_DeleteActor((struct ClactActor *)p[9]);CLACT_ReleasePalette(p[11]);CLACT_ReleaseCharacter(p[12]);CLACT_ReleaseCellAnim(p[13]);}
    for(i=0;i<7;i++) if(p[i]) {BR_UTIL_Delete((void *)p[i]);p[i]=0;}
    PMS_DRAW_Delete((struct PmsDraw *)p[8]);BR_RES_ApplyBgSet((void *)p[7],8);GFL_HEAP_Free(p);BG_SYS_PushTile(1);
}

int BR_UTIL_MainProfileScreen(u8 *p)
{
    int result=1;
    int i;
    for(i=0;i<7;i++)if(*(void **)((uptr)p+(u32)i*4)!=0)result &=BR_UTIL_FlushText(*(void **)((uptr)p+(u32)i*4));
    PMS_DRAW_Main((struct PmsDraw *)(*(u8 * *)&((BrUtilListMenu *)p)->cfg.other));
    return result;
}

int *BR_UTIL_CreateTask(int payload,int callback,int heap)
{
    int *p;
    p=GFL_HEAP_Alloc(heap,16,0,d_02200D5C,0x6a2);
    MI_CpuFill8(p,0,16);
    p[2]=payload;
    BR_UTIL_SetTaskStep(p,callback);
    return p;
}

void BR_UTIL_DeleteTask(void *p)
{
    GFL_HEAP_Free(p);
}

void BR_UTIL_RunTask(u8 *p)
{
    if(((BrUtilTask *)p)->step!=0)((BrUtilTask *)p)->step(p,(int *)(p+4),((BrUtilTask *)p)->payload);
}

/*
 * Blocker leaf for ov183 021E1D48 and 021E20F8, parent cleared.
 */
int BR_UTIL_IsTaskIdle(int *p)
{
    if (*p==0) return 1;
    return 0;
}

int *BR_UTIL_SetTaskStep(int *p, int v)
{
    p[0] = v;
    p[1] = 0;
    return p;
}

int BR_UTIL_ClearTaskStep(int *a)
{
    return (sptr)BR_UTIL_SetTaskStep(a, 0);
}

int BR_UTIL_IsTaskStep(int *p, int v)
{
    return *p == v;
}

char *BR_UTIL_CreateHandles(void *owner, char *resources, int index, int heap)
{
    BrTriple triple;
    BrPair pair;
    unsigned short res;
    char *p;
    int i;
    p=GFL_HEAP_Alloc(heap,0x264,0,d_02200D5C,0x7CA);
    MI_CpuFill8(p,0,0x264);
    ((BrUtilEffect *)p)->resources=resources;((BrUtilEffect *)p)->index=index;
    ((BrUtilEffect *)p)->task=BR_UTIL_CreateTask((sptr)p,(sptr)BR_UTIL_EffectIdle,heap);
    BR_RES_LoadSprite((struct BrRes *)(((BrUtilEffect *)p)->resources),index+9,heap);
    MI_CpuFill8((void *)&pair,0,8);
    if(!BR_RES_GetSprite((struct BrRes *)(((BrUtilEffect *)p)->resources),index+9,(void *)&triple)) GF_PANIC_Fail((const char *)d_02200D68,0,(const char *)d_02200D68);
    i=0;
    res=index;
    for(;i<12;i++) {
        ((BrUtilEffect *)p)->handles[i]=CLACT_CreateActor((struct Unit *)((void *)owner),triple.y,triple.z,triple.x,(const struct ActorInitParam *)&pair,res,heap);
        CLACT_SetActorDrawEnable((struct ClactActor *)((BrUtilEffect *)p)->handles[i],0);
        CLACT_SetActorObjMode((struct ClactActor *)(((BrUtilEffect *)p)->handles[i]),1);
    }
    return p;
}

/*
 * Release the twelve handles at r5+0x1F8, then tear the object down.
 */
void BR_UTIL_DeleteHandles(char *r5)
{
    int i;
    for (i = 0; i < 0xC; i++)
        CLACT_DeleteActor((struct ClactActor *)(*(int *)(r5 + 0x1F8 + i * 4)));
    BR_RES_ReleaseSprite((struct BrRes *)(((BrUtilEffect *)r5)->resources), ((BrUtilEffect *)r5)->index + 9);
    BR_UTIL_DeleteTask((void *)((BrUtilEffect *)r5)->task);
    GFL_HEAP_Free((int *)r5);
}

void BR_UTIL_RunHandles(char *p)
{
    BR_UTIL_RunTask((u8 *)((BrUtilEffect *)p)->task);
}

/*
 * follower: 021FD938 already filed separately; lead excludes that existing accessor.
 */
void BR_UTIL_StartEffect(char *p,u32 mode,const BrPair *pair)
{
    if(pair) {
        *(BrPair *)p=*pair;
        *(const BrPair * *)&((BrUtilEffect *)p)->target=pair;
    }
    ((BrUtilEffect *)p)->flag=0;
    if(mode==0 && BR_UTIL_IsTaskStep(((BrUtilEffect *)p)->task,(sptr)BR_UTIL_EffectFlyIn)) GFL_USE_PlaySeDefaultVolume(0x701);
    switch(mode) {
    case 0: BR_UTIL_SetTaskStep(((BrUtilEffect *)p)->task,(sptr)BR_UTIL_EffectIdle);break;
    case 1: BR_UTIL_SetTaskStep(((BrUtilEffect *)p)->task,(sptr)BR_UTIL_EffectSpiral);break;
    case 2: BR_UTIL_SetTaskStep(((BrUtilEffect *)p)->task,(sptr)BR_UTIL_EffectFollow12);break;
    case 3: BR_UTIL_SetTaskStep(((BrUtilEffect *)p)->task,(sptr)BR_UTIL_EffectFollow6);break;
    case 4: BR_UTIL_SetTaskStep(((BrUtilEffect *)p)->task,(sptr)BR_UTIL_EffectFlyIn);break;
    case 5: BR_UTIL_SetTaskStep(((BrUtilEffect *)p)->task,(sptr)BR_UTIL_EffectFlyInSlow);break;
    case 6: BR_UTIL_SetTaskStep(((BrUtilEffect *)p)->task,(sptr)BR_UTIL_EffectNoop);break;
    case 7: BR_UTIL_SetTaskStep(((BrUtilEffect *)p)->task,(sptr)BR_UTIL_EffectToTarget);break;
    case 8: BR_UTIL_SetTaskStep(((BrUtilEffect *)p)->task,(sptr)BR_UTIL_EffectToPoint);break;
    }
}

int BR_UTIL_IsEffectDone(char *p){return ((BrUtilEffect *)p)->flag;}

/*
 * lever: Set the counter before narrowing value; its initialization splits the two shifts.
 */
void BR_UTIL_SetHandlesAnimSeq(u8 *p,u32 value)
{
    int i;
    u16 narrow;
    i=0;
    narrow=value;
    for(;i<12;i++)CLACT_SetActorAnimSeq(*(struct ClactActor **)((uptr)p+(u32)i*4+0x1f8),narrow);
}

void BR_UTIL_EffectIdle(void *unused,int *state,u8 *p)
{
    int i;
    switch(*state) {
    case 0:
        for(i=0;i<12;i++)CLACT_SetActorDrawEnable(*(struct ClactActor **)((uptr)p+(u32)i*4+0x1f8),0);
        ((BrUtilEffect *)p)->flag=1;
        *state=1;
        break;
    case 1:break;
    }
}

void BR_UTIL_EffectSpiral(int unused,int *state,BrUtilEffect *p)
{
    BrPair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            int angle;
            angle=i*0xffff/6;
            BR_UTIL_InitOrbit((unsigned char *)p->record[i],(const BrPair *)p,8,20,angle,angle+0x3333,15);
            CLACT_SetActorDrawEnable(p->handles[i],1);
        }
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            BR_UTIL_StepOrbit((char *)p->record[i],(int *)&full,p->timer);
            pos.x=full.x;pos.y=full.y;
            CLACT_AddActorSurfacePos((struct ClactActor *)p->handles[i],(const struct ClactVec2 *)&pos,p->index);
        }
        if(p->timer++>15) *state=2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(p->task,(sptr)BR_UTIL_EffectIdle);
        break;
    }
}

/*
 * lever: ShortPair declared before Pair gives +2C and +24 stack objects; initialize reused i=1 before FE478 so the call precedes its loop without relocating movs.
 */
void BR_UTIL_EffectFollow12(int unused,int *state,BrUtilEffect *p)
{
    ShortPair pos;
    BrPair initial;
    int i,done;
    switch(*state) {
    case 0:
        p->timer=0;
        initial=d_02200AD0.first;
        for(i=0;i<12;i++) {
            p->positions[i]=initial;
            CLACT_SetActorDrawEnable(p->handles[i],1);
        }
        BR_UTIL_InitLine((int *)p->record[0],&p->positions[0],&d_02200AE8.first,0,50);
        for(i=1;i<12;i++) BR_UTIL_Init((int *)p->record[i],(sptr)&p->positions[i-1],(int *)&p->positions[i],0x4000-i*0x666/2);
        *state=1;
    case 1:
        i=1;
        p->flag=BR_UTIL_StepLine((int *)p->record[0],&p->positions[0],p->timer);
        done=1;
        done&=p->flag;
        for(;i<12;i++) done&=BR_UTIL_StepFollow((char *)p->record[i],(int *)(&p->positions[i]));
        for(i=0;i<12;i++) {
            pos.x=p->positions[i].x;pos.y=p->positions[i].y;
            CLACT_AddActorSurfacePos((struct ClactActor *)p->handles[i],(const struct ClactVec2 *)&pos,p->index);
        }
        p->timer++;
        if(done) *state=2;
        break;
    case 2: BR_UTIL_SetTaskStep(p->task,(sptr)BR_UTIL_EffectIdle);break;
    }
}

void BR_UTIL_EffectFollow6(int unused,int *state,BrUtilEffect *p)
{
    ShortPair pos;
    ShortPair pos2;
    BrPair initial;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        initial=d_02200AD0.third;
        for(i=0;i<6;i++) {
            p->positions[i]=initial;
            CLACT_SetActorDrawEnable(p->handles[i],1);
        }
        BR_UTIL_InitLine((int *)p->record[0], (const BrPair *)(&p->positions[0]), (const BrPair *)(&d_02200AD0.second), 0, 36);
        for(i=1;i<6;i++) BR_UTIL_Init((int *)p->record[i],(sptr)&p->positions[i-1],(int *)&p->positions[i],0x3800-i*0xb33/2);
        *state=1;
    case 1:
        p->done[1]=BR_UTIL_StepLine((int *)p->record[0], (BrPair *)(&p->positions[0]), p->timer);
        for(i=1;i<6;i++) p->done[i+1]=BR_UTIL_StepFollow((char *)p->record[i],(int *)(&p->positions[i]));
        for(i=0;i<6;i++) {
            pos.x=p->positions[i].x;pos.y=p->positions[i].y;
            CLACT_AddActorSurfacePos((struct ClactActor *)p->handles[i],(const struct ClactVec2 *)&pos,p->index);
        }
        p->timer++;
        if(p->done[1]) {CLACT_SetActorDrawEnable(p->handles[0],0);*state=2;}
        break;
    case 2:
        p->timer=0;
        for(i=6;i<12;i++) {
            BR_UTIL_InitSpiral((u8 *)p->record[i], (const BrPair *)((void *)&d_02200AD0.second), 15, (i*0xffff-0x5fffa)/6, 90);
            CLACT_SetActorDrawEnable(p->handles[i],1);
        }
        *state=3;
    case 3:
        for(i=6;i<12;i++) BR_UTIL_StepSpiral(p->record[i],(int *)(&p->positions[i]),p->timer);
        for(i=1;i<6;i++) {
            p->done[i+1]=BR_UTIL_StepFollow((char *)p->record[i],(int *)(&p->positions[i]));
            if(p->done[i+1]) CLACT_SetActorDrawEnable(p->handles[i],0);
        }
        for(i=0;i<12;i++) {
            pos2.x=p->positions[i].x;pos2.y=p->positions[i].y;
            CLACT_AddActorSurfacePos((struct ClactActor *)p->handles[i],(const struct ClactVec2 *)&pos2,p->index);
        }
        p->flag=1;
        p->timer++;
        break;
    }
}

void BR_UTIL_EffectFlyIn(int unused,int *state,BrUtilEffect *p)
{
    BrPair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            BR_UTIL_InitSpiral((u8 *)p->record[i], (const BrPair *)((const BrPair *)p), 15, (i*0xFFFF)/6, 90);
            CLACT_SetActorDrawEnable((struct ClactActor *)p->handles[i],1);
        }
        GFL_USE_PlaySeDefaultVolume(0x705);
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            BR_UTIL_StepSpiral((char *)p->record[i],(int *)(&full),p->timer);
            pos.x=full.x;pos.y=full.y;
            CLACT_AddActorSurfacePos((struct ClactActor *)((void *)(p->handles[i])), (const struct ClactVec2 *)((const ShortPair *)((ShortPair *)&pos)), p->index);
        }
        p->timer++;
        break;
    }
}

/*
 * follower: empty return at 021FDFF0; trailing two zero alignment bytes excluded.
 */
void BR_UTIL_EffectFlyInSlow(int unused,int *state,BrUtilEffect *p)
{
    BrPair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            BR_UTIL_InitSpiral((u8 *)p->record[i], (const BrPair *)((const BrPair *)p), 10, (i*0xFFFF)/6, 90);
            CLACT_SetActorDrawEnable((struct ClactActor *)p->handles[i],1);
        }
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            BR_UTIL_StepSpiral((char *)p->record[i],(int *)(&full),p->timer);
            pos.x=full.x;pos.y=full.y;
            CLACT_AddActorSurfacePos((struct ClactActor *)((void *)(p->handles[i])), (const struct ClactVec2 *)((const ShortPair *)((ShortPair *)&pos)), p->index);
        }
        p->timer++;
        break;
    }
}

void BR_UTIL_EffectNoop(void)
{
}

void BR_UTIL_EffectToTarget(int *obj,int *state,BrUtilEffect *p)
{
    ShortPair pos;
    ShortPair pos2;
    int i;
    int all;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            BR_UTIL_InitOrbit((u8 *)p->record[i], (const BrPair *)((const BrPair *)p), 8, 20, (i*0xFFFF)/6, (i*0xFFFF)/6+0x3333, 16);
            CLACT_SetActorDrawEnable((struct ClactActor *)p->handles[i],1);
        }
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            BR_UTIL_StepOrbit((char *)p->record[i],(int *)&p->positions[i],p->timer);
            pos.x=p->positions[i].x;pos.y=p->positions[i].y;
            CLACT_AddActorSurfacePos((struct ClactActor *)((void *)((sptr)(p->handles[i]))), (const struct ClactVec2 *)((const ShortPair *)((ShortPair *)&pos)), p->index);
        }
        if(p->timer++>16) *state=2;
        break;
    case 2:
        *state=3;
        break;
    case 3:
        for(i=0;i<6;i++)
            BR_UTIL_Init((int *)p->record[i],(sptr)p->target,(const int *)&p->positions[i],0x4000-(i*0x99A)/2);
        *state=4;
    case 4:
        all=1;
        for(i=0;i<6;i++) {
            all&=BR_UTIL_StepFollow((char *)p->record[i],(int *)&p->positions[i]);
            pos2.x=p->positions[i].x;pos2.y=p->positions[i].y;
            CLACT_AddActorSurfacePos((struct ClactActor *)((void *)((sptr)(p->handles[i]))), (const struct ClactVec2 *)((const ShortPair *)((ShortPair *)&pos2)), p->index);
        }
        if(all) *state=5;
        break;
    case 5:
        BR_UTIL_SetTaskStep(obj,(sptr)BR_UTIL_EffectIdle);
        break;
    }
}

/*
 * lever: Initialize i before the second start=p+18 assignment to interleave movs with the pointer adds (four bytes out to EXACT).
 * abi: B404 third parameter is u16 because the original truncates the loaded heap word immediately before blx.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`start=p;` before `start=p+0x18;`; `offset=0x228;` before
 * `offset=0x1f8;`). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 */
void BR_UTIL_EffectToPoint(int *task,int *state,char *p)
{
    BrPair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0: {
        char *start;
        int offset;
        BR_UTIL_SetHandlesAnimSeq((unsigned char *)p,0);
        start=p+0x18;
        offset=0x1f8;
        for(i=6;i<12;i++) {
            u16 angle;
            angle=*(u16 *)(p+i*32+0x2a)+((BrUtilEffect *)p)->timer/ *(int *)(p+i*32+0x2c);
            BR_UTIL_InitOrbit((unsigned char *)(start+i*32),(void *)d_02200AD8,15,1,angle,angle+0xf000,30);
            CLACT_SetActorObjMode(*(void **)(p+i*4+offset),0);
        }
        ((BrUtilEffect *)p)->timer=0;
        *state=1;
    }
    case 1: {
        char *start;
        int offset;
        offset=0x228;start=p;i=6;start=p+0x18;offset=0x1f8;
        for(;i<12;i++) {
            BR_UTIL_StepOrbit((char *)(start+i*32),(int *)&full,((BrUtilEffect *)p)->timer);
            pos.x=full.x;pos.y=full.y;
            CLACT_AddActorSurfacePos((struct ClactActor *)((void *)((sptr)(*(void **)(p+i*4+offset)))), (const struct ClactVec2 *)((const ShortPair *)((ShortPair *)&pos)), ((BrUtilEffect *)p)->index);
        }
        if((((BrUtilEffect *)p)->timer)++>60)*state=2;
        break;
    }
    case 2:BR_UTIL_SetTaskStep(task,(sptr)BR_UTIL_EffectIdle);break;
    }
}

/*
 * lever: A named x load before the last halfword store preserves the interleaved copy.
 */
int BR_UTIL_InitOrbit(u8 *p,const BrPair *origin,u16 a,u16 b,u16 c,u16 d,int duration)
{
    int x;
    MI_CpuFill8(p,0,28);
    ((BrUtilOrbit *)p)->radius=a;
    ((BrUtilOrbit *)p)->targetRadius=b;
    ((BrUtilOrbit *)p)->angle=c;
    x=origin->x;
    ((BrUtilOrbit *)p)->targetAngle=d;
    ((BrUtilOrbit *)p)->x=x;
    ((BrUtilOrbit *)p)->duration=duration;
    ((BrUtilOrbit *)p)->y=origin->y;
    return BR_UTIL_StepOrbit((char *)p,(int *)(p+8),0);
}

int BR_UTIL_StepOrbit(char *p, int *out, int step)
{
    unsigned short angle_delta;
    signed char direction;
    int angle;
    int initial_angle;
    int duration;
    unsigned short initial_radius;
    int radius_delta;
    int radius, x, y;
    initial_angle = ((BrUtilOrbit *)p)->angle;
    angle_delta = ((BrUtilOrbit *)p)->targetAngle - initial_angle;
    initial_radius = ((BrUtilOrbit *)p)->radius;
    radius_delta = (short)(*(short *)&((BrUtilOrbit *)p)->targetRadius - (short)initial_radius);
    direction = radius_delta / (radius_delta < 0 ? -radius_delta : radius_delta);
    duration = ((BrUtilOrbit *)p)->duration;
    angle = (unsigned short)(initial_angle + angle_delta * step / duration);
    if (radius_delta < 0) radius_delta = -radius_delta;
    radius = initial_radius + direction * (step * radius_delta / duration);
    if (radius < 0) radius = 0;
    x = (FX_SinCosTable_[(angle >> 4) * 2 + 1] * radius) >> 12;
    y = (FX_SinCosTable_[(angle >> 4) * 2] * radius) >> 12;
    x += ((BrUtilOrbit *)p)->x;
    y += ((BrUtilOrbit *)p)->y;
    ((BrUtilOrbit *)p)->posX = x;
    ((BrUtilOrbit *)p)->posY = y;
    if (out) { out[0] = x; out[1] = y; }
    return step == ((BrUtilOrbit *)p)->duration;
}

/*
 * lever: The two-word origin copy is a Pair assignment; separate field stores reorder it.
 */
int BR_UTIL_InitSpiral(u8 *p,const BrPair *origin,u16 a,u16 b,int duration)
{
    MI_CpuFill8(p,0,24);
    *(BrPair *)p=*origin;
    ((BrUtilSpiral *)p)->duration=duration;
    ((BrUtilSpiral *)p)->radius=a;
    ((BrUtilSpiral *)p)->angle=b;
    return BR_UTIL_StepSpiral((char *)p,0,0);
}

#pragma opt_common_subs off

/*
 * note: pass 2 2026-10-06 P2L30: EXACT (c and c99). The twin shape of
 *   BR_UTIL_StepOrbit (x, y products, then x += f0, y += f4, then the two
 *   stores) gives the original tail; with common subexpressions on, the
 *   front end turns the two radius reads into one temp and hoists it to
 *   right after the angle load. #pragma opt_common_subs off keeps the read
 *   inline at its first use (between the two table reads); a named index
 *   local i = (angle >> 4) * 2 then gives the shared index the pragma no
 *   longer finds. Earlier lanes: 26 (P19 lane 5), 15 (G6L8).
 */
int BR_UTIL_StepSpiral(char *p, int *out, int step)
{
    int angle, i, x, y;
    angle = (unsigned short)(*(unsigned short *)(p + 0x12) + 0xFFFF * step / *(int *)(p + 0x14));
    i = (angle >> 4) * 2;
    x = (FX_SinCosTable_[i + 1] * *(unsigned short *)(p + 0x10)) >> 12;
    y = (FX_SinCosTable_[i] * *(unsigned short *)(p + 0x10)) >> 12;
    x += *(int *)p;
    y += *(int *)(p + 4);
    *(int *)(p + 8) = x;
    *(int *)(p + 12) = y;
    if (out) { out[0] = x; out[1] = y; }
    return step == *(int *)(p + 0x14);
}

#pragma opt_common_subs reset

static inline void copyPair(BrPair *dest,const BrPair *src) { int y,x; y=src->y; x=src->x; dest->y=y; dest->x=x; }

/*
 * lever: inline pair copy loads y then x before storing; aggregate copy differed by 20 bytes, raw field stores by 23, const raw stores by 22.
 */
void BR_UTIL_InitLine(int *p,const BrPair *a,const BrPair *b,int c,int d) { MI_CpuFill8(p,0,0x20); copyPair((BrPair *)p,a); copyPair((BrPair *)(p+2),b); p[7]=d; p[6]=c; BR_UTIL_StepLine(p,0,0); }

int BR_UTIL_StepLine(int *p, BrPair *out, int step)
{
    int done = 0;
    int progress = step - p[6];
    if (progress < 0)
        progress = 0;
    p[4] = p[0] + (p[2] - p[0]) * progress / p[7];
    p[5] = p[1] + (p[3] - p[1]) * progress / p[7];
    if (progress >= p[7]) {
        *(BrPair *)(p + 4) = *(BrPair *)(p + 2);
        done = 1;
    }
    if (out) {
        *out = *(BrPair *)(p + 4);
    }
    return done;
}

void BR_UTIL_Init(int *p, int a, const int *values, int duration)
{
    float value;
    MI_CpuFill8(p, 0, 0x14);
    p[0] = a;
    if (values[0] > 0)
        value = 0.5f + (float)(values[0] << 12);
    else
        value = (float)(values[0] << 12) - 0.5f;
    p[1] = (int)value;
    if (values[1] > 0)
        value = 0.5f + (float)(values[1] << 12);
    else
        value = (float)(values[1] << 12) - 0.5f;
    p[2] = (int)value;
    p[3] = 0;
    p[4] = duration;
}

static inline int roundFixed(int x)
{
    float f;
    if(x>0)f=0.5f+(float)(x<<12);
    else f=(float)(x<<12)-0.5f;
    return (int)f;
}

int BR_UTIL_StepFollow(char *p,int *out)
{
    VecFx32 delta;
    int length,x,y;
    delta.x=roundFixed(((BrUtilFollow *)p)->target[0])-((BrUtilFollow *)p)->posX;
    delta.y=roundFixed(((BrUtilFollow *)p)->target[1])-((BrUtilFollow *)p)->posY;
    delta.z=0;
    length=VEC_Mag(&delta);
    if(length) {
        x=FX_Div((int)(((long long)delta.x* ((BrUtilFollow *)p)->speed+2048)>>12),length);
        y=FX_Div((int)(((long long)delta.y* ((BrUtilFollow *)p)->speed+2048)>>12),length);
        if((delta.x<0?-delta.x:delta.x)>(x<0?-x:x))((BrUtilFollow *)p)->posX+=x;
        else ((BrUtilFollow *)p)->posX=roundFixed(((BrUtilFollow *)p)->target[0]);
        if((delta.y<0?-delta.y:delta.y)>(y<0?-y:y))((BrUtilFollow *)p)->posY+=y;
        else ((BrUtilFollow *)p)->posY=roundFixed(((BrUtilFollow *)p)->target[1]);
    }
    if(out){out[0]=((BrUtilFollow *)p)->posX>>12;out[1]=((BrUtilFollow *)p)->posY>>12;}
    return length==0;
}
