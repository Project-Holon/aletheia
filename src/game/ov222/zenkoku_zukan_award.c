/*
 * file:     zenkoku_zukan_award.c
 * unit:     yes
 * function: ZENKOKU_ZUKAN_AWARD_Init, ZENKOKU_ZUKAN_AWARD_Exit, ZENKOKU_ZUKAN_AWARD_Main, ZENKOKU_ZUKAN_AWARD_LoadBgAssets, ZENKOKU_ZUKAN_AWARD_Noop, ZENKOKU_ZUKAN_AWARD_SetupWindows, ZENKOKU_ZUKAN_AWARD_DeleteWindows, ZENKOKU_ZUKAN_AWARD_FlushWindows, ZENKOKU_ZUKAN_AWARD_SetupTiles, ZENKOKU_ZUKAN_AWARD_CreateActor, ZENKOKU_ZUKAN_AWARD_DeleteActor, ZENKOKU_ZUKAN_AWARD_SetupActorPos, ZENKOKU_ZUKAN_AWARD_UpdateActor, ZENKOKU_ZUKAN_AWARD_IsActorIdle, ZENKOKU_ZUKAN_AWARD_Callback
 * address:  0x021B95A0
 * region:   ov222
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_Create 0x021B9F10 thumb ov222
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BG_SYS_SetPriority 0x0204047C arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GXS_SetGraphicsMode 0x0207D518 arm
 *   BG_SYS_ClearSubBgPlanes 0x02043558 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   tbl_021BA1F4 0x021BA1F4 data a4
 *   tbl_021BA360 0x021BA360 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_Delete 0x021B9FB8 thumb ov222
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   d_021BA1F4 0x021BA1F4 data a4
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_Update 0x021BA014 thumb ov222
 *   FADE_IsActive 0x0204E804 arm
 *   KEY_GetTrg 0x020362DC arm
 *   UI_SetInputMode 0x020355D8 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SYSTEM_DATA_GetConfig 0x0200873C thumb
 *   CONFIG_GetTextLanguage 0x020083E4 thumb
 *   ARC_UTIL_UploadPaletteFromArchive 0x02049B90 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_SetPosX 0x02045780 arm
 *   BMP_WIN_SetPosY 0x02045788 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   BMP_GetWidth 0x020437DC arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   d_021BA220 0x021BA220 data a1
 *   d_021BA1E0 0x021BA1E0 data a1
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_LoadPltt 0x02040E78 arm
 *   BMP_WIN_GetCharOffset 0x02045768 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   d_021BA378 0x021BA378 data a1
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetActor 0x021BA028 thumb ov222
 *   d_021BA1D8 0x021BA1D8 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BG_SYS_GetScrollY 0x02040804 arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021BA2AC 0x021BA2AC data a4
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb  arm9
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb  arm9
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 *   GFL_USE_IsBgmFading  0x02005E50  thumb  arm9
 *   GFL_USE_PushBgm  0x02005E64  thumb  arm9
 *   GFL_USE_PopBgm  0x02005E9C  thumb  arm9
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb  arm9
 */
#define R (*(volatile u16*)0x04000060)
struct BgTemplate;
struct Obj;
struct Proc;
struct GfFont;
struct Node;
struct PrintSys;
struct Proc;
struct Big;
struct Bmp;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct Sub02008700Obj;
struct U16Vec;
struct WordSet;
struct Rec;
struct Vec2;
struct Actor;
struct PtS;
#include "../types.h"

typedef struct {u32 id;u8 cfg[32];u32 type,enable;} AwardBgLayerRow;

typedef struct {u32 a,b,c;} Assets;

typedef enum { BG_MODE0=0, BG_MODE1=1 } BGMode;

typedef enum { COUNT=1 } LayerCount;

typedef struct {u32 layer;u8 data[40];} AwardBgTemplate;

struct Pos { u8 a, b, c, d; };

typedef struct {s16 x,y;} Pt;

/* Caller input, the third Init argument. */
struct ZenkokuZukanAwardArgs {
    void *owner;    /* +0x00 passed to GAME_DATA_GetMyStatus */
    int bgmActive;  /* +0x04 nonzero suppresses the BGM restart */
};

/* 0x58-byte proc work record (PROCSYS_AllocProcWork size). */
struct ZenkokuZukanAwardWork {
    u16 heap;                    /* +0x00 heap id 131 */
    u16 pad2;                    /* +0x02 */
    struct ZenkokuZukanAwardArgs *args; /* +0x04 caller input */
    void *graphic;               /* +0x08 ZENKOKU_ZUKAN_AWARD_GRAPHIC_Create */
    struct GfFont *font;         /* +0x0C GF_FONT_Create */
    void *printQue;              /* +0x10 PRINTSYS_QUE_Create */
    void *task;                  /* +0x14 GFL_USE_AddMainTask proc */
    struct MsgBank *msgBank;     /* +0x18 MSGDATA_CreateFromArchive, freed by MSGDATA_Delete */
    void *windows[5];            /* +0x1C BMP window descriptors */
    u32 done[5];                 /* +0x30 set once a window is uploaded */
    u8 countdown;                /* +0x44 */
    u8 pad45[3];                 /* +0x45 */
    u32 charId;                  /* +0x48 CLACT_RegisterCharacter */
    u32 paletteId;               /* +0x4C CLACT_RegisterPaletteEx */
    u32 cellAnimId;              /* +0x50 CLACT_RegisterCellAnim */
    struct Obj *actor;           /* +0x54 CLACT actor */
};

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void*,int,u32);
extern void *ZENKOKU_ZUKAN_AWARD_GRAPHIC_Create(u32,u32);
extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);
struct PrintQueue;
extern struct PrintQueue *PRINTSYS_QUE_Create(unsigned int heap);
extern void BG_SYS_SetPriority(int,u16);
extern void *GFL_USE_AddMainTask(u32,void*,u32);
struct GameData;
struct MyStatus;
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gd);
extern void BG_SYS_ClearSubPlanes(void),BG_SYS_ClearSubBgPlanes(void),GXS_SetGraphicsMode(BGMode);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_SetPlaneVisible(u8,u8);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void *ARC_TOOL_CreateHandle(unsigned int archiveID, unsigned short heapID);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void*,u32,u32,u32,u32,u16);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void*,u32,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void*);
extern void FADE_Start(u32,int,int,int),BG_SYS_PushTile(u32),GFL_NET_RefreshWmIconAtTopRight(u32,u32),GFL_USE_FadeOutBgm(u32);
extern void BG_SYS_FreeLayerBuf(u32 i);
struct TcbTask;
extern void TCB_DeleteTask(struct TcbTask *task);
extern void PRINTSYS_QUE_Clear(struct PrintQueue *queue);
extern void PRINTSYS_QUE_Delete(struct PrintQueue *queue);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Delete(char*);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int);
extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Update(char *p);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_SetBgmPaused(unsigned int value);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(unsigned int bgmNo, unsigned int trackMask);
extern int GFL_USE_IsBgmPlaying(void);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_FadeInBgmFull(u32);
extern void FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern u32 KEY_GetTrg(void);
extern void UI_SetInputMode(unsigned char);
extern u32 TOUCHPANEL_GetPointTrg(u32*,u32*);
extern u32 PRINTSYS_QUE_Main(struct PrintQueue *queue);
extern void BG_SYS_PushTile(unsigned);
struct SaveControl;
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);
extern struct Sub02008700Obj *SYSTEM_DATA_GetConfig(void *sys);
extern int CONFIG_GetTextLanguage(unsigned short *p);
extern void ARC_UTIL_UploadPaletteFromArchive(u32,u32,u32,u32,u32,u32,u16);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct BmpWin;
extern struct BmpWin *BMP_WIN_Create(unsigned int bgLayer, unsigned int posX, unsigned int posY, unsigned char width, unsigned char height, unsigned char palette, unsigned char allocDir);
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
extern void BMP_Clear(struct Bmp *bmp, unsigned char value);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_SetPosX(struct BmpWin *win, unsigned char posX);
extern void BMP_WIN_SetPosY(struct BmpWin *win, unsigned char posY);
extern struct WordSet *WORDSET_CreateDefault(unsigned short heapId);
struct Strbuf;
extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);
extern u32 PRINTSYS_MeasureWidestLine(struct Strbuf *text, struct GfFont *font, unsigned int spacing);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern void PRINTSYS_PrintQueColor(struct PrintQueue *queue, struct Bmp *bmp, unsigned int x, short y, struct Strbuf *str, struct GfFont *font, unsigned short color);
extern void STRBUF_Delete(struct Strbuf *strbuf);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern void BG_SYS_MarkTileDirty(u32);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp);
extern void *GFL_HEAP_Alloc(u32,u32,int,const char*,u16);
extern u32 GFL_HEAP_Free(void *p);
extern void BG_SYS_LoadPltt(u32,void*,u32,u32);
extern u16 BMP_WIN_GetCharOffset(struct BmpWin *win);
extern void BG_SYS_DrawTile(unsigned int index, void *src, unsigned char dx, unsigned char dy, unsigned char cw, unsigned char ch);
extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetActor(char *p);
extern struct Obj *CLACT_CreateActor(void*,u32,u32,u32,const void*,u16,u16);
extern void CLACT_SetActorDrawEnable(struct Actor *actor, unsigned int value);
extern void CLACT_SetActorAutoAnim(struct Actor *actor, unsigned int enable);
extern void CLACT_DeleteActor(struct Actor *actor);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void BG_SYS_ChangeScrollImmediate(unsigned,unsigned,unsigned);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern unsigned BG_SYS_GetScrollY(unsigned);
extern void BG_SYS_ChangeScroll(unsigned,unsigned,unsigned);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16,int,int,int,int);
struct G3dLight;
extern void G3D_SYSTEM_SetLight(unsigned int lightIdx, struct G3dLight *light);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32);
int ZENKOKU_ZUKAN_AWARD_Init(void *owner,void *unused,void *input);
int ZENKOKU_ZUKAN_AWARD_Exit(void*scene,int unused1,int unused2,char*p);
int ZENKOKU_ZUKAN_AWARD_Main(int unused, int *state, int unused2, unsigned char *p);
void ZENKOKU_ZUKAN_AWARD_Task(void);
void ZENKOKU_ZUKAN_AWARD_LoadBgAssets(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_Noop(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_SetupWindows(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_DeleteWindows(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_FlushWindows(struct ZenkokuZukanAwardWork *p);
int ZENKOKU_ZUKAN_AWARD_IsWindowsReady(char*p);
void ZENKOKU_ZUKAN_AWARD_SetupTiles(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_CreateActor(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_DeleteActor(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_SetupActorPos(char*p);
void ZENKOKU_ZUKAN_AWARD_UpdateActor(struct ZenkokuZukanAwardWork *p);
int ZENKOKU_ZUKAN_AWARD_IsActorIdle(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_Callback(void);
extern const AwardBgLayerRow tbl_021BA1F4[];
extern Assets tbl_021BA360[];
extern const AwardBgTemplate d_021BA1F4[];
extern const u8 d_021BA220[];
extern struct Pos d_021BA1E0[];
extern char d_021BA378[];
extern const u32 d_021BA1D8[];
extern const u16 d_021BA2AC[][4];

int ZENKOKU_ZUKAN_AWARD_Init(void *owner,void *unused,void *input)
{
 char *p,*settings;
 BGMode i;
 int selected,zero;
 const AwardBgLayerRow *row;
 u32 id;
 u16 heap;
 void *h;
 GFL_HEAP_CreateChildHeap((u32)((void*)1),131,0x30000);
 p=PROCSYS_AllocProcWork(owner,88,131);
 i=BG_MODE0;
 MI_CpuFill8(p,i,88);
 *(u16*)p=131;
 *(void**)(p+4)=input;
 *(void**)(p+8)=ZENKOKU_ZUKAN_AWARD_GRAPHIC_Create(1,*(u16*)p);
 *(void**)(p+12)=GF_FONT_Create(23,0,0,0,*(u16*)p);
 *(u32*)(p+16)=(unsigned int)PRINTSYS_QUE_Create((unsigned int)*(u16*)p);
 BG_SYS_SetPriority(1,1);BG_SYS_SetPriority(2,0);
 *(void**)(p+20)=GFL_USE_AddMainTask((u32)ZENKOKU_ZUKAN_AWARD_Task,p,1);
 ZENKOKU_ZUKAN_AWARD_LoadBgAssets((struct ZenkokuZukanAwardWork *)p);ZENKOKU_ZUKAN_AWARD_SetupWindows((struct ZenkokuZukanAwardWork *)p);ZENKOKU_ZUKAN_AWARD_SetupTiles((struct ZenkokuZukanAwardWork *)p);ZENKOKU_ZUKAN_AWARD_CreateActor((struct ZenkokuZukanAwardWork *)p);
 settings=(char *)GAME_DATA_GetMyStatus(*(void**)(*(char**)(p+4)));
 *(volatile u16*)0x04001050=i;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 *(volatile u32*)0x04001000 |= 0x10000;
 BG_SYS_ClearSubPlanes();GXS_SetGraphicsMode(i);BG_SYS_ClearSubBgPlanes();
 do {
  row=&tbl_021BA1F4[i];id=row->id;
  BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)row->cfg,(u8)row->type);BG_SYS_FreeSlot(id);BG_SYS_SetPlaneVisible(id,row->enable);
  i++;
 } while((u32)i<1u);
 BG_SYS_SetSubPlaneVisible(16,1);
 heap=*(u16*)p;
 selected=1;if(*(u8*)(settings+29)!=1) selected=0;
 h=ARC_TOOL_CreateHandle(30,heap);
 zero=0;
 ARC_UTIL_UploadPaletteFromHandleWhole(h,tbl_021BA360[selected].a,4,zero,zero,heap);
 ARC_UTIL_UploadBgCharFromHandle(h,tbl_021BA360[selected].b,4,zero,zero,zero,heap);
 ARC_UTIL_UploadBgPaletteFromHandle(h,tbl_021BA360[selected].c,4,zero,zero,zero,heap);
 ARC_TOOL_DeleteHandle(h);BG_SYS_PushTile(4);ZENKOKU_ZUKAN_AWARD_SetupActorPos((char *)p);
 FADE_Start(3,16,16,0);GFL_NET_RefreshWmIconAtTopRight(0,*(u16*)p);
 if(*(int*)(*(char**)(p+4)+4)==0) GFL_USE_FadeOutBgm(6);
 return 1;
}

int ZENKOKU_ZUKAN_AWARD_Exit(void*scene,int unused1,int unused2,char*p)
{
 LayerCount i;
 i=0;
 do {
  BG_SYS_FreeLayerBuf((u8)d_021BA1F4[i].layer);
  i++;
 } while((u32)i<COUNT);
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 ZENKOKU_ZUKAN_AWARD_DeleteActor((struct ZenkokuZukanAwardWork *)p);
 ZENKOKU_ZUKAN_AWARD_DeleteWindows((struct ZenkokuZukanAwardWork *)p);
 ZENKOKU_ZUKAN_AWARD_Noop((struct ZenkokuZukanAwardWork *)p);
 TCB_DeleteTask(((struct ZenkokuZukanAwardWork *)p)->task);
 PRINTSYS_QUE_Clear(((struct ZenkokuZukanAwardWork *)p)->printQue);
 PRINTSYS_QUE_Delete(((struct ZenkokuZukanAwardWork *)p)->printQue);
 GF_FONT_Delete(((struct ZenkokuZukanAwardWork *)p)->font);
 ZENKOKU_ZUKAN_AWARD_GRAPHIC_Delete((char *)((struct ZenkokuZukanAwardWork *)p)->graphic);
 PROCSYS_FreeProcWork(scene);
 GFL_HEAP_DeleteChecked(0x83);
 return 1;
}

int ZENKOKU_ZUKAN_AWARD_Main(int unused, int *state, int unused2, unsigned char *p)
{
 int ready;
 u32 x,y;
 switch(*state) {
 case 0:
  ready=1;
  if(ZENKOKU_ZUKAN_AWARD_IsWindowsReady((char *)p)==0) ready=0;
  if(ready && ((struct ZenkokuZukanAwardWork *)p)->args->bgmActive==0) {
   if(GFL_USE_IsBgmFading()) ready=0;
   else {GFL_USE_SetBgmPaused((unsigned int)1);GFL_USE_PushBgm();GFL_USE_CancelChangeAndPlayBgm(0x524,0xffff);}
  }
  if(ready) {FADE_Start(3,16,0,0);*state=1;}
  break;
 case 1:
  if(!FADE_IsActive()) {if(((struct ZenkokuZukanAwardWork *)p)->args->bgmActive!=0) *state=4;else *state=2;}
  break;
 case 2: if(ZENKOKU_ZUKAN_AWARD_IsActorIdle((struct ZenkokuZukanAwardWork *)p)) *state=3; break;
 case 3:
  if(!GFL_USE_IsBgmPlaying()) {GFL_USE_PopBgm();GFL_USE_SetBgmPaused(0);GFL_USE_FadeInBgmFull(6);*state=4;}
  break;
 case 4:
  ready=0;
  if(KEY_GetTrg()&3) {UI_SetInputMode(0);ready=1;}
  else if(TOUCHPANEL_GetPointTrg(&x,&y)) {UI_SetInputMode(1);ready=1;}
  if(ready) {*state=5;FADE_Start(3,0,16,0);}
  break;
 case 5: if(!FADE_IsActive()) *state=6; break;
 case 6: return 1;
 }
 PRINTSYS_QUE_Main(((struct ZenkokuZukanAwardWork *)p)->printQue);
 ZENKOKU_ZUKAN_AWARD_FlushWindows((struct ZenkokuZukanAwardWork *)p);
 if(*state>=1 && *state<=5) ZENKOKU_ZUKAN_AWARD_UpdateActor((struct ZenkokuZukanAwardWork *)p);
 ZENKOKU_ZUKAN_AWARD_GRAPHIC_Update((char *)((struct ZenkokuZukanAwardWork *)p)->graphic);
 return 0;
}

void ZENKOKU_ZUKAN_AWARD_Task(void) {}

void ZENKOKU_ZUKAN_AWARD_LoadBgAssets(struct ZenkokuZukanAwardWork *p)
{
    void *h;
    h=ARC_TOOL_CreateHandle(0xca,p->heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(h,2,0,0,0x1e0,p->heap);
    ARC_UTIL_UploadBgCharFromHandle(h,5,1,0,0,0,p->heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h,7,1,0,0,0,p->heap);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_PushTile(1);
}

void ZENKOKU_ZUKAN_AWARD_Noop(struct ZenkokuZukanAwardWork *p){}

void ZENKOKU_ZUKAN_AWARD_SetupWindows(struct ZenkokuZukanAwardWork *p)
{
    u8 i, j;
    char *msg;
    int flag;
    u32 h;
    s16 off;
    u32 ws, x, t;
    msg = (char *)GAME_DATA_GetMyStatus(p->args->owner);
    flag = CONFIG_GetTextLanguage((short unsigned int *)SYSTEM_DATA_GetConfig(GAME_DATA_GetSaveControl(p->args->owner)));
    p->msgBank = 0;
    for (i = 0; i < 5; i++) {
        p->windows[i] = 0;
        p->done[i] = 0;
    }
    p->done[0] = 1;
    p->done[1] = 1;
    ARC_UTIL_UploadPaletteFromArchive(0x17, 5, 0, 0, 0x1e0, 0x20, p->heap);
    p->msgBank = MSGDATA_CreateFromArchive(0, 3, 1, p->heap);
    for (i = 0; i < 5; i++) {
        p->windows[i] = (void *)BMP_WIN_Create(d_021BA220[i*9], d_021BA220[i*9+1], d_021BA220[i*9+2], d_021BA220[i*9+3], d_021BA220[i*9+4], d_021BA220[i*9+5], d_021BA220[i*9+6]);
        BMP_Clear(BMP_WIN_GetBmp(p->windows[i]), 0);
        BMP_WIN_TransferChars(p->windows[i]);
    }
    if (flag == 1) {
        for (j = 0; j < 5; j++) {
            BMP_WIN_SetPosX(p->windows[j], d_021BA1E0[j].a);
            BMP_WIN_SetPosY(p->windows[j], d_021BA1E0[j].b);
        }
    }
    ws = (u32)WORDSET_CreateDefault(p->heap);
    t = (u32)MSGDATA_AllocString(p->msgBank, 4);
    x = (u32)STRBUF_Create(0x20, p->heap);
    off = 0;
    WORDSET_SetSlotMyStatus((struct WordSet *)ws, 0, msg);
    WORDSET_CopyTaggedText((struct WordSet *)ws, (void *)x, (void *)t);
    PRINTSYS_MeasureWidestLine((struct Strbuf *)x, p->font, 0);
    BMP_GetWidth(BMP_WIN_GetBmp(p->windows[2]));
    PRINTSYS_PrintQueColor(p->printQue, BMP_WIN_GetBmp(p->windows[2]), 0, 0, (struct Strbuf *)x, p->font, 0x440);
    STRBUF_Delete((struct Strbuf *)x);
    STRBUF_Delete((struct Strbuf *)t);
    WORDSET_Delete((struct WordSet *)ws);
    t = (u32)MSGDATA_AllocString(p->msgBank, 6);
    x = (u16)PRINTSYS_MeasureWidestLine((struct Strbuf *)t, p->font, 0);
    h = BMP_GetWidth(BMP_WIN_GetBmp(p->windows[3]));
    if (h >= x && flag == 1) off = ((int)(h - x)) / 2;
    PRINTSYS_PrintQueColor(p->printQue, BMP_WIN_GetBmp(p->windows[3]), off, 0, (struct Strbuf *)t, p->font, 0x440);
    STRBUF_Delete((struct Strbuf *)t);
    t = (u32)MSGDATA_AllocString(p->msgBank, 5);
    PRINTSYS_MeasureWidestLine((struct Strbuf *)t, p->font, 0);
    BMP_GetWidth(BMP_WIN_GetBmp(p->windows[4]));
    PRINTSYS_PrintQueColor(p->printQue, BMP_WIN_GetBmp(p->windows[4]), 0, 0, (struct Strbuf *)t, p->font, 0x440);
    STRBUF_Delete((struct Strbuf *)t);
    for (i = 1; i < 5; i++) {
        void *d = p->windows[i];
        BMP_WIN_TransferChars(d);
        BMP_WIN_MakeScreen(d);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(d));
    }
    ZENKOKU_ZUKAN_AWARD_FlushWindows(p);
}

void ZENKOKU_ZUKAN_AWARD_DeleteWindows(struct ZenkokuZukanAwardWork *p) { u8 i;for(i=0;i<5;i++){struct Descriptor *q=p->windows[i];if(q)BMP_WIN_Delete((struct BmpWin *)q);}if(p->msgBank)MSGDATA_Delete((struct MsgBank *)p->msgBank); }

/*
 * function_starts: 021B9BFC
 * extent: lead 74B; 2 padding bytes; approved follower 30B; 2 terminal zero bytes at 021B9C1A outside TU.
 */
void ZENKOKU_ZUKAN_AWARD_FlushWindows(struct ZenkokuZukanAwardWork *p)
{
    u8 i;
    for(i=0;i<5;i++){
        if(p->done[i]==0){
            if(PRINTSYS_QUE_IsExistTarget(p->printQue,BMP_WIN_GetBmp(p->windows[i]))==0){
                void*h=p->windows[i];
                BMP_WIN_TransferChars(h);BMP_WIN_MakeScreen(h);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(h));
                p->done[i]=1;
            }
        }
    }
}

int ZENKOKU_ZUKAN_AWARD_IsWindowsReady(char*p)
{
    u8 i;
    for(i=0;i<5;i++){
        if(*(int*)(p+i*4+0x30)==0)return 0;
    }
    return 1;
}

void ZENKOKU_ZUKAN_AWARD_SetupTiles(struct ZenkokuZukanAwardWork *p)
{
 u16 *tiles;
 u16 *buf;
 u16 index;
 unsigned long tile;
 u8 x,y;
 buf=GFL_HEAP_Alloc(p->heap,32,1,d_021BA378,0x3db);
 index=0;
 buf[0]=0;
 buf[1]=0x1d29;
 buf[2]=0x3210;
 buf[3]=0;
 BG_SYS_LoadPltt(2,buf,32,480);
 GFL_HEAP_Free(buf);
 BMP_Clear(BMP_WIN_GetBmp(p->windows[1]),3);
 BMP_WIN_TransferChars(p->windows[1]);
 tiles=GFL_HEAP_Alloc(p->heap,1536,1,d_021BA378,0x3ec);
 tile=BMP_WIN_GetCharOffset(p->windows[1])|0xf000;
 for(y=0;y<24;y++) for(x=0;x<32;x++) {tiles[index]=tile;index++;}
 BG_SYS_DrawTile(2,tiles,0,24,32,24);
 BG_SYS_PushTile(2);
 GFL_HEAP_Free(tiles);
}

void ZENKOKU_ZUKAN_AWARD_CreateActor(struct ZenkokuZukanAwardWork *p)
{
 u32 t;
 void *h;
 h=ARC_TOOL_CreateHandle(0xca,p->heap);
 p->paletteId=CLACT_RegisterPaletteEx(h,0,0,0,0,2,p->heap);
 p->charId=CLACT_RegisterCharacter(h,3,0,0,p->heap);
 p->cellAnimId=CLACT_RegisterCellAnim(h,8,9,p->heap);
 ARC_TOOL_DeleteHandle((void*)h);
 t=ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetActor((char *)p->graphic);
 p->actor=CLACT_CreateActor((void*)t,p->charId,p->paletteId,p->cellAnimId,d_021BA1D8,0,p->heap);
 CLACT_SetActorDrawEnable((struct Actor *)p->actor,1);
 CLACT_SetActorAutoAnim((struct Actor *)p->actor,1);
}

void ZENKOKU_ZUKAN_AWARD_DeleteActor(struct ZenkokuZukanAwardWork *p)
{
    CLACT_DeleteActor((struct Actor *)p->actor);
    CLACT_ReleaseCellAnim(p->cellAnimId);
    CLACT_ReleaseCharacter(p->charId);
    CLACT_ReleasePalette(p->paletteId);
}

/*
 * note 2026-10-05 (final push G1L10): closed by a block-local table pointer `s16 *t` assigned after
 *   the two calls and read as t[0], t[1]. Earlier forms (pointer local at function top, late local
 *   with other types, byte-offset reads, int locals, pragmas) left the base and the first halfword
 *   in swapped registers (4 B).
 */
void ZENKOKU_ZUKAN_AWARD_SetupActorPos(char*p)
{
    Pt pos;
    if(*(int*)(*(char**)(p+4)+4)==0){
        s16 *t;
        BG_SYS_ChangeScrollImmediate(1,3,0x40);
        BG_SYS_ChangeScrollImmediate(2,3,0x40);
        t=(s16*)d_021BA1D8;
        pos.x=t[0];
        pos.y=t[1]-0x40;
        CLACT_AddActorSurfacePos(*(void**)(p+0x54),(const struct Vec2 *)(&pos),0);
        *(u8*)(p+0x44)=0;
    }
}

void ZENKOKU_ZUKAN_AWARD_UpdateActor(struct ZenkokuZukanAwardWork *p)
{
    int v;
    Pt pos;
    if(p->args->bgmActive==0){
        v=BG_SYS_GetScrollY(1);
        if(v!=0){
            if(p->countdown==0){
                if(v>=2)v=2;
                BG_SYS_ChangeScroll(1,5,v);BG_SYS_ChangeScroll(2,5,v);
                CLACT_GetActorSurfacePos((struct Actor *)p->actor,(struct PtS *)(&pos),0);
                pos.y=pos.y+(s16)v;
                CLACT_AddActorSurfacePos(p->actor,(const struct Vec2 *)(&pos),0);
                p->countdown=0;
            }else --p->countdown;
        }
    }
}

int ZENKOKU_ZUKAN_AWARD_IsActorIdle(struct ZenkokuZukanAwardWork *p) { int flag;int result;if(p->args->bgmActive!=0)return 1;flag=1;if(BG_SYS_GetScrollY(1)!=0)flag=0;result=0;if(flag!=0)result=1;return result; }

/*
 * lever: SDK BG0 priority uses explicit (u16) assignment; compound &= pools 0xfffc.
 * volatile: 021B9E7A..021B9EB8 BG0CNT/DISP3DCNT re-reads; 021B9ED6 VIEWPORT
 */
void ZENKOKU_ZUKAN_AWARD_Callback(void)
{
 u32 i;
 BG_SYS_SetMainPlaneVisible(1,1);
 *(volatile u16*)0x04000008 = (u16)(*(volatile u16*)0x04000008 & ~3);
 R=(R & ~0x3002)|2;
 R &= ~0x3010;
 R &= ~0x3004;
 R=(R & ~0x3000)|8;
 R &= ~0x3020;
 G3X_SetFog(0,0,0,0);
 G3X_SetClearColor(0,0,0x7fff,63,0);
 *(volatile u32*)0x04000580=0xbfff0000;
 for(i=0;i<4;i++)G3D_SYSTEM_SetLight((u8)i,(struct G3dLight *)d_021BA2AC[i]);
 G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
