/*
 * file:     research_top.c
 * unit:     yes
 * function: func_021B95A0, func_021B9600, func_021B9620, func_021B96A0, func_021B96C8, func_021B970C, func_021B9774, func_021B97B8, func_021B97BC, func_021B97F8, func_021B9824, func_021B9850, func_021B9854, func_021B985C, func_021B9874, func_021B9884, func_021B9894, func_021B98A8, func_021B98B8, func_021B990C, func_021B9920, func_021B99EC, func_021B9A24, func_021B9AD0, func_021B9AF8, func_021B9B08, func_021B9B80, func_021B9B90, func_021B9B98, func_021B9C54, func_021B9E44, func_021BA078, func_021BA094, func_021BA0C4, func_021BA144, func_021BA150, func_021BA158, func_021BA180, func_021BA190, func_021BA194, func_021BA19C, func_021BA1C0, func_021BA1CC, func_021BA1D4, func_021BA1F8, func_021BA228, func_021BA254, func_021BA284, func_021BA2BC, func_021BA2FC, func_021BA31C, func_021BA328, func_021BA354, func_021BA364, func_021BA374, func_021BA37C, func_021BA380, func_021BA384, func_021BA388, func_021BA3B0, func_021BA3B4, func_021BA3D0, func_021BA3D8, func_021BA3E0, func_021BA3E8, func_021BA40C, func_021BA41C, func_021BA434, func_021BA4C8, func_021BA4CC, func_021BA4D0, func_021BA4D4, func_021BA4E0, func_021BA4FC, func_021BA504, func_021BA560, func_021BA5B4, func_021BA5BC, func_021BA5D8, func_021BA5E4, func_021BA5F8, func_021BA624, func_021BA63C, func_021BA674, func_021BA67C, func_021BA68C, func_021BA698, func_021BA748, func_021BA768, func_021BA7B4, func_021BA7B8, func_021BA7D0, func_021BA7E0, func_021BA82C, func_021BA830, func_021BA848, func_021BA858, func_021BA86C, func_021BA8E0, func_021BA8FC, func_021BA910, func_021BA960, func_021BA978, func_021BA9D0, func_021BA9E8, func_021BA9FC, func_021BAA28, func_021BAA40, func_021BAA48, func_021BAAB8, func_021BAAC4, func_021BAAD8, func_021BAAF4, func_021BAB0C, func_021BAB38, func_021BAB50, func_021BAB58, func_021BAB68, func_021BAB70
 * address:  0x021B95A0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from research_top.c, unit_021BFFC8.c, queue.c, palette_anime.c, ov217_func_021C2E20.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02012204 0x02012204 thumb
 *   RESEARCH_COMMON_SetInputFlag 0x021C09FC thumb ov217
 *   WIH_DWC_PollStatus  0x0201058C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   func_0201283C  0x0201283C  thumb
 *   RESEARCH_COMMON_SetScreen  0x021C09BC  thumb  ov217
 *   RESEARCH_COMMON_Create  0x021C097C  thumb  ov217
 *   RESEARCH_COMMON_Destroy  0x021C099C  thumb  ov217
 *   ListViewState_Create  0x021C0DC4  thumb  ov217
 *   ListViewState_Reset  0x021C0DE4  thumb  ov217
 *   ListViewState_Destroy  0x021C0DDC  thumb  ov217
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   d_021C2E30     0x021C2E30  data  ov217  a4
 *   d_021C2E60     0x021C2E60  data  a4
 *   d_021C2E40     0x021C2E40  data  ov217  a4
 *   d_021C2E80     0x021C2E80  data  ov217  a4
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   func_02062A98 0x02062A98 arm
 *   func_02040E78 0x02040E78 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02062A4C 0x02062A4C arm
 *   func_02040B1C 0x02040B1C arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   sub_020307B0 0x020307B0 arm
 *   sub_020409B4 0x020409B4 arm
 *   RESEARCH_COMMON_GetHeapId  0x021C09AC  thumb  ov217
 *   RESEARCH_COMMON_UpdatePaletteAnime 0x021C09D0 thumb ov217
 *   CLACT_DrawSystem 0x0204A600 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   RESEARCH_COMMON_GetTouchRects 0x021C09B8 thumb ov217
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   RESEARCH_COMMON_StopPaletteAnime  0x021C09E0  thumb  ov217
 *   RESEARCH_COMMON_RestorePaletteAnime  0x021C09EC  thumb  ov217
 *   RingQueue_Push  0x021C0E4C  thumb  ov217
 *   RingQueue_Pop  0x021C0E54  thumb  ov217
 *   RingQueue_IsEmpty  0x021C0E64  thumb  ov217
 *   RESEARCH_COMMON_GetPreviousScreen  0x021C09C8  thumb  ov217
 *   RESEARCH_COMMON_GetEntryHandled  0x021C09CC  thumb  ov217
 *   RESEARCH_COMMON_SetEntryHandled  0x021C09C4  thumb  ov217
 *   GAME_BEACON_PopQuestionnaireUpdated  0x020270E0  thumb
 *   BgTextLabel_SetPalette  0x021C1038  thumb  ov217
 *   RESEARCH_COMMON_StartPaletteAnime  0x021C09D8  thumb  ov217
 *   PALETTE_ANIME_Start  0x021C29F8  thumb  ov217
 *   d_021C3008  0x021C3008  data  a4
 *   d_021C3004  0x021C3004  data  a4
 *   PALETTE_ANIME_Stop  0x021C2A00  thumb  ov217
 *   PALETTE_ANIME_Update  0x021C29F0  thumb  ov217
 *   RESEARCH_COMMON_GetAppResource 0x021C09B4 thumb ov217
 *   func_0201296C 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   RESEARCH_COMMON_GetInputFlag  0x021C09F8  thumb  ov217
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   d_021C2ED8  0x021C2ED8  data  a4
 *   MSGDATA_Delete  0x02045C04  arm
 *   d_021C2EE0  0x021C2EE0  data  a4
 *   RingQueue_Create  0x021C0E08  thumb  ov217
 *   RingQueue_Destroy  0x021C0E3C  thumb  ov217
 *   func_0207D63C 0x0207D63C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   d_021C2EEC 0x021C2EEC data a4
 *   d_021C2F78 0x021C2F78 data a4
 *   d_021C2F18 0x021C2F18 data a4
 *   d_021C2F38 0x021C2F38 data a4
 *   d_021C2F58 0x021C2F58 data a4
 *   func_02040DA8  0x02040DA8  arm
 *   BgTextLabel_Create 0x021C0EF4 thumb ov217
 *   BgTextLabel_PrintMessage 0x021C0F5C thumb ov217
 *   d_021C2F98 0x021C2F98 data a4
 *   BgTextLabel_Destroy  0x021C0F48  thumb  ov217
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   d_021C2ED2  0x021C2ED2  data  a4
 *   d_021C2ED0  0x021C2ED0  data  a4
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   d_021C2EFC 0x021C2EFC data a4
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   PALETTE_ANIME_Create  0x021C29C8  thumb  ov217
 *   PALETTE_ANIME_Destroy  0x021C29D8  thumb  ov217
 *   PALETTE_ANIME_Bind  0x021C29E8  thumb  ov217
 *   PALETTE_ANIME_Restore  0x021C2A08  thumb  ov217
 *   d_021C2FF8  0x021C2FF8  data  a4
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   func_02005654  0x02005654  thumb
 *   func_020413B0 0x020413B0 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   func_02045B38 0x02045B38 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   FADE_Start  0x0204E720  arm
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   PROCSYS_AllocProcWork  0x0203159C  arm  arm9
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm  arm9
 *   FADE_IsActive  0x0204E804  arm  arm9
 *   func_02030734  0x02030734  arm
 *   func_021BAB80 0x021BAB80 thumb ov217
 *   func_021BABB4 0x021BABB4 thumb ov217
 *   func_021BABC4 0x021BABC4 thumb ov217
 *   func_021BAC90 0x021BAC90 thumb ov217
 *   func_021BAC98 0x021BAC98 thumb ov217
 *   func_021BD5F4 0x021BD5F4 thumb ov217
 *   func_021BD61C 0x021BD61C thumb ov217
 *   func_021BD62C 0x021BD62C thumb ov217
 *   func_021BD708 0x021BD708 thumb ov217
 *   func_021BD710 0x021BD710 thumb ov217
 */
#include "../../matched/include/Obj10952.h"
#include "../../matched/include/Obj25801.h"
#include "../../matched/include/Obj25805.h"
#include "research_top_shared_types.h"

struct DispVram;

struct Obj0203159C;

struct S020315D4;

struct NitroFileHeader;

struct Context;

struct Desc {u8 a,b,c,d,e,f,g,h,i,j,k;unsigned data;};

struct Entry_021BA86C {struct Desc desc;unsigned mode,data;};

struct Context {void *owner;u16 heap,pad6;char gap8[0x54];int slots[6];};

struct Vec {short x,y,z;unsigned char a,b;};

struct Entry_021BAA48 {struct Vec vec;unsigned first,second,third,fourth;u16 arg,pad;};

struct Ent_021C2FF8 { u32 a; u32 b; u8 c; u8 pad[11]; };

struct ResearchObjC {
    union { void * f0; u32 f0u; };
    u16 f4;
    u8 pad6[0x2];
    u32 f8;
    u8 padC[0x8];
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
    u8 pad2C[0x28];
    u32 f54;
    u8 pad58[0x4];
    u32 f5C;
    u32 f60;
    u32 f64;
    u32 f68;
    u32 f6C;
    u32 f70;
    u8 pad74[0x8];
    void * f7C;
    u32 f80;
    u32 f84;
    u32 f88;
    u32 f8C;
};

struct ResearchProc {
    u16 f0;
    u8 pad2[0x2];
    union { void * f4; u32 f4u; };
    u32 f8;
    u32 fC;
    u32 f10;
    union { u32 f14; void * f14p; };
    u32 f18;
    u32 f1C;
};

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void func_0204363C(u32 swap);

extern void func_020315D4(struct S020315D4 *);

extern u32 func_02012204(const struct Ctx *);

extern void RESEARCH_COMMON_SetInputFlag(void *);

extern u32 WIH_DWC_PollStatus(void *key);

extern void *func_020120F4(const struct Ctx *p);

extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);

extern u32 func_0201283C(const struct BigObj *p);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void RESEARCH_COMMON_SetScreen(void *p, u32 v);

extern int RESEARCH_COMMON_Create(int a0, int a1);

extern u32 RESEARCH_COMMON_Destroy(void *a0);

extern u32 ListViewState_Create(u32 a0);

extern void ListViewState_Reset(void *p);

extern void ListViewState_Destroy(void *a0);

extern void func_0203F8F4(unsigned short heapId);

extern void func_0203FC28(struct DispConfig *cfg);

extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void func_02040588(unsigned char which, unsigned char enable);

extern u32 func_0203F9B4();

extern u32 func_020403F4(u32 i);

extern void *func_020490F4(unsigned int id, u32 heap);

extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *, u32, u32);

extern int func_02062A98(struct NitroFileHeader *, void **);

extern void func_02040E78(u32, void *, u32, u32);

extern u32 func_020307B0(void *p);

extern int func_02062A4C(struct NitroFileHeader *, void **);

extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);

extern int func_02062B30(void *, void **);

extern void func_02041090(u32, u32, u32, u32, u8, u8);

extern int func_020409B4(int);

extern void ARC_TOOL_DeleteHandle(void *);

extern void func_020413B0(int index, int x0, int y0, int w, int h, int pal);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern u32 sub_020307B0(void *p);

extern void sub_020409B4(u32);

extern u32 RESEARCH_COMMON_GetHeapId(void *);

extern void RESEARCH_COMMON_UpdatePaletteAnime(unsigned);

extern void CLACT_DrawSystem();

extern u32 KEY_GetTrg(void);

extern int TOUCHPANEL_HitTrg(const void *);

extern void * RESEARCH_COMMON_GetTouchRects(void *);

extern u32 GFL_USE_PlaySeDefaultVolume(u32 a);

extern int FADE_IsActive(void);

extern void RESEARCH_COMMON_StopPaletteAnime(u32 a0);

extern void RESEARCH_COMMON_RestorePaletteAnime(u32 a0);

extern void RingQueue_Push(u32, u32);

extern u32 RingQueue_Pop(struct Ring *r);

extern u32 RingQueue_IsEmpty();

extern u32 RESEARCH_COMMON_GetPreviousScreen(void *p);

extern u32 RESEARCH_COMMON_GetEntryHandled(void *p);

extern void RESEARCH_COMMON_SetEntryHandled(u8 *p, u32 v);

extern u8 GAME_BEACON_PopQuestionnaireUpdated(void);

extern void BgTextLabel_SetPalette(u8 *p, u8 palette);

extern void RESEARCH_COMMON_StartPaletteAnime(u8 *p, u32 i);

extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);

extern u32 CLACT_SetActorAnimFrame();

extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);

extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);

extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

extern void PALETTE_ANIME_Start(u8 *p, u32 b, u16 c);

extern void PALETTE_ANIME_Stop(u32 a0);

extern void PALETTE_ANIME_Update(int);

extern unsigned RESEARCH_COMMON_GetAppResource(void *);

extern u32 func_0201296C(const struct BigObj *p);

extern unsigned ZONEDATA_CheckEventFlag(void *,int);

extern u32 RESEARCH_COMMON_GetInputFlag(void *p);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern u32 GF_FONT_Delete(void *ptr);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern int RingQueue_Create(int a0, int a1);

extern void RingQueue_Destroy(void *p);

extern void func_0207D63C(volatile unsigned *,unsigned,unsigned,unsigned,unsigned);

extern void BMP_WIN_Init(u16);

extern void BMP_WIN_Exit(void);

extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);

extern u32 func_020414EC();

extern void func_02040DA8(u32, u32, u32);

extern struct Record *BgTextLabel_Create(const struct Config *config, u32 a, u32 b, u32 heap);

u32 BgTextLabel_PrintMessage(u32 a0, u32 a1);

extern void BgTextLabel_Destroy(u8 *p);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleaseCharacter(u32 i);

extern u32 CLACT_ReleasePalette(u32 i);

extern u32 CLACT_ReleaseCellAnim();

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 PALETTE_ANIME_Create(u32 a0);

extern u32 PALETTE_ANIME_Destroy(void *a0);

extern void PALETTE_ANIME_Bind(void *p, u32 b, u32 c, u32 d);

extern int PALETTE_ANIME_Restore(char *p);

extern void CLACT_VBlankSystem(void);

extern int func_02005654(int a, int b);

extern void func_0200566C(void);

u32 func_021B95A0(u32 a0, u32 a1, u8 *a2, u32 a3);

u32 func_021B9600(u32 a0, u32 a1, u32 a2, u32 a3);

int func_021B9620(void *unused, u32 *state, u32 unused2, u32 *p);

void func_021B96A0(u32 a0);

void func_021B96C8(void *a, int *p, int c);

void func_021B970C(u32 *p, u32 *state);

void func_021B9774(u32 *p, u32 *state, u32 kind);

int func_021B97B8(void *a0);

u32 func_021B97BC(u8 *a0);

u32 func_021B97F8(u32 a0);

u32 func_021B9824(u32 a0);

u32 func_021B9850(const void *p);

void func_021B9854(void *p);

void func_021B985C(void *p, u32 value);

void func_021B9874(u32 a0);

u32 func_021B9884(u32 a0);

void func_021B9894(u32 a0);

u32 func_021B98A8(u32 a0);

void func_021B98B8(unsigned short heapId);

u32 func_021B990C(void);

void func_021B9920(u32 heap);

void func_021B99EC(const void *p);

void func_021B9A24(u32 heap);

u32 func_021B9AD0(void *self);

u32 func_021B9AF8(void *a0);

void func_021B9B08(char *p);

int func_021B9B80(void *p);

u32 func_021B9B90(void *p);

void func_021B9B98(char *p);

void func_021B9C54(char *p);

void func_021B9E44(char *p);

void func_021BA078(u32 a0);

void func_021BA094(u32 a0);

void func_021BA0C4(u32 a0);

void func_021BA144(u8 *a0, u32 a1);

void func_021BA150(void *p);

void func_021BA158(u32 a0);

void func_021BA180(void *p, u32 v);

u32 func_021BA190(void *p);

void func_021BA194(void *p);

u32 func_021BA19C(u8 *a0);

void func_021BA1C0(u8 *a0, u32 a1);

void func_021BA1CC(void *p, u32 v);

void func_021BA1D4(u32 a0);

void func_021BA1F8(u32 a0);

void func_021BA228(u32 a0);

void func_021BA254(u32 a0, u32 a1);

void func_021BA284(int sel);

void func_021BA2BC(int sel);

void func_021BA2FC(u32 a0);

void func_021BA31C(u8 *a0);

u32 func_021BA328(u32 a0);

void func_021BA354(void);

void func_021BA364(void);

void func_021BA374(void *p);

u32 func_021BA37C(void *p);

void func_021BA380(void *p, u32 v);

u32 func_021BA384(void *p);

void func_021BA388(char *self, int d);

void func_021BA3B0(void *p, u32 v);

u32 func_021BA3B4(u32 a0, u32 a1);

u32 func_021BA3D0(void *p, u32 i);

u32 func_021BA3D8(void *p, u32 i);

u32 func_021BA3E0(void *p, u32 i);

void func_021BA3E8(char *self, int i);

void func_021BA40C(u8 *a0, u32 a1);

void func_021BA41C(int *p);

unsigned char func_021BA434(char *p);

u32 func_021BA4C8(void *p);

void func_021BA4CC(void *p, u32 v);

void func_021BA4D0(void *p, u32 v);

u32 func_021BA4D4(void *p);

u32 func_021BA4E0(u32 a0);

u32 func_021BA4FC(void *a0);

void func_021BA504(char *p);

void func_021BA560(char *p);

void func_021BA5B4(void *p);

void func_021BA5BC(u32 a0);

void func_021BA5D8(u8 *a0);

void func_021BA5E4(void *p);

void func_021BA5F8(char *self);

void func_021BA624(int *p);

void func_021BA63C(u8 *self);

void func_021BA674(void *p);

void func_021BA67C(u32 a0);

void func_021BA68C(Rec *p);

void func_021BA698(char *p);

void func_021BA748(u32 a0);

void func_021BA768(char *p);

void func_021BA7B4(u32 a0);

u32 func_021BA7B8(void *a0);

void func_021BA7D0(u32 a0);

void func_021BA7E0(char *p);

void func_021BA82C(u32 a0);

u32 func_021BA830(void *a0);

void func_021BA848(u32 a0);

void func_021BA858(void *p);

void func_021BA86C(char *p);

void func_021BA8E0(int *p);

void func_021BA8FC(void *p);

void func_021BA910(struct Context *p);

u32 func_021BA960(u32 a0);

void func_021BA978(struct Context *p);

u32 func_021BA9D0(u32 a0);

void func_021BA9E8(void *p);

void func_021BA9FC(char *self);

void func_021BAA28(int *p);

void func_021BAA40(void *p);

void func_021BAA48(char *p);

void func_021BAAB8(u8 *a0);

void func_021BAAC4(void *p);

void func_021BAAD8(char *p);

void func_021BAAF4(int *p);

void func_021BAB0C(char *self);

void func_021BAB38(char *self);

void func_021BAB50(void);

void func_021BAB58(void *a0);

void func_021BAB68(void);

void func_021BAB70(u32 a0);

u32 func_021BAB80(u32 a0, u32 a1);

u32 func_021BABB4(void *a0);

void func_021BABC4(void *self);

u32 func_021BAC90(void *p);

u32 func_021BAC98(void *p);

void *func_021BD5F4(void *p);

u32 func_021BD61C(void *a0);

void func_021BD62C(unsigned char *p);

u32 func_021BD708(void *p);

u32 func_021BD710(void *p);

extern int d_021C2E30;

extern int d_021C2E60;

extern int d_021C2E40;

extern int d_021C2E80;

extern u8 d_021C3008[];

extern u8 d_021C3004[];

extern u32 d_021C2ED8[];

extern u8 d_021C2EE0[];

extern struct DispConfig d_021C2EEC;

extern const struct BgTemplate d_021C2F78,d_021C2F18,d_021C2F38,d_021C2F58;

extern const struct Entry_021BA86C d_021C2F98[];

extern u16 d_021C2ED2[];

extern u8 d_021C2ED0[];

extern const struct Entry_021BAA48 d_021C2EFC;

extern struct Ent_021C2FF8 d_021C2FF8[];

u32 func_021B95A0(u32 a0, u32 a1, u8 *a2, u32 a3)
{
    switch (((struct Obj10952 *)((u8*)a1))->f0) {
    case 0:
    PROCSYS_AllocProcWork((struct Obj0203159C *)a0, 32, 1);
    ((struct Obj10952 *)((u8*)a1))->f0 = (u32)(((struct Obj10952 *)((u8*)a1))->f0 + 1);
    break;
    case 1:
    func_021B985C((void *)a3, ((struct Obj25801 *)((u8*)a2))->f0);
    BG_SYS_SetVramBanks((const struct DispVram *)0x21C2EA0);
    func_0204363C(0);
    func_021B98B8(((struct ResearchProc *)a3)->f0);
    func_021B9A24(((struct ResearchProc *)a3)->f0);
    func_021B9920(((struct ResearchProc *)a3)->f0);
    func_021B9874(a3);
    func_021B9894(a3);
    return 1;
    }
    return 0;
}

u32 func_021B9600(u32 a0, u32 a1, u32 a2, u32 a3)
{
    func_021B98A8(a3);
    func_021B9884(a3);
    func_021B990C();
    func_020315D4((struct S020315D4 *)a0);
    return 1;
}

/*
 * tail: zero halfword alignment at 021B969E.
 * state domain: procsys 020315F0 resets subseq to 0 before this main callback;
 *   97B8 returns 1, 97BC returns 1..4, 97F8 returns 1/2/4, 9824 returns 1/3/4.
 *   96C8/9774 stores only those new states; state 4 exits immediately.
 *   Full lifecycle/body proof: scratchpad/overlay-goal-20260930-w32/S23/state-proof.md.
 */
int func_021B9620(void *unused, u32 *state, u32 unused2, u32 *p)
{
    u32 next;
    func_021B96A0((u32)p);
    if (func_02012204((const struct Ctx *)p[1]) != 0)
        RESEARCH_COMMON_SetInputFlag((void *)p[3]);
    switch (*state) {
    case 0: next = func_021B97B8(p); break;
    case 1: next = func_021B97BC((u8 *)p); break;
    case 2: next = func_021B97F8((u32)p); break;
    case 3: next = func_021B9824((u32)p); break;
    case 4: return 1;
    }
    func_021B99EC(p);
    func_021B9854(p);
    if (*state != next)
        func_021B96C8(p, (int *)state, next);
    return 0;
}

/*
 * Flushes the +4 handle through three sub-calls, then raises event 1 with
 * the record's leading halfword when the fourth sub-call reports busy.
 *
 * Addresses are Black-image addresses.
 */
void func_021B96A0(u32 a0)
{
    WIH_DWC_PollStatus((void *)func_0201283C(func_020120F4(((struct ResearchProc *)a0)->f4)));
    if (GAMESYSTEM_TryStartAutoComm((struct IcaAnime *)(*(u32 *)&((struct ResearchProc *)a0)->f4)) != 0) {
    GFL_NET_RestartWithDefaultTimeout(1, ((struct ResearchProc *)a0)->f0);
    }
}

void func_021B96C8(void *a, int *p, int c)
{
    func_021B970C(a, (u32 *)p);
    func_021B9774(a, (u32 *)p, c);
    switch (*p) {
    case 1:
        RESEARCH_COMMON_SetScreen((void *)(*(int *)((char *)a + 0xc)), 1);
        break;
    case 2:
        RESEARCH_COMMON_SetScreen((void *)(*(int *)((char *)a + 0xc)), 2);
        break;
    case 3:
        RESEARCH_COMMON_SetScreen((void *)(*(int *)((char *)a + 0xc)), 3);
        break;
    }
}

/*
 * tail: zero halfword alignment at 021B9772.
 */
void func_021B970C(u32 *p, u32 *state)
{
    switch (*state) {
    case 0: case 4: break;
    case 1: func_021B9AF8((void *)p[4]); break;
    case 2: func_021BABB4((void *)p[5]); break;
    case 3: func_021BD61C((void *)p[6]); break;
    }
    switch (*state) {
    case 0: case 4: break;
    case 1: p[4] = 0; break;
    case 2: p[5] = 0; break;
    case 3: p[6] = 0; break;
    }
}

void func_021B9774(u32 *p, u32 *state, u32 kind)
{
    switch (kind) {
    case 0:
    case 4:
        break;
    case 1:
        p[4] = func_021B9AD0((void *)p[3]);
        break;
    case 2:
        p[5] = func_021BAB80(p[3], p[7]);
        break;
    case 3:
        p[6] = (u32)func_021BD5F4((void *)p[3]);
        break;
    }
    *state = kind;
}

int func_021B97B8(void *a0)
{
    return 1;
}

u32 func_021B97BC(u8 *a0)
{
    func_021B9B08((char *)(((struct ResearchProc *)a0)->f10));
    if (func_021B9B80((void *)(((struct ResearchProc *)a0)->f10)) != 0) {
    switch (func_021B9B90((void *)(((struct ResearchProc *)a0)->f10))) {
    case 0:
    return 2;
    case 1:
    return 3;
    case 2:
    return 4;
    }
    return 4;
    }
    return 1;
}

u32 func_021B97F8(u32 a0)
{
    func_021BABC4((void *)(((struct ResearchProc *)a0)->f14));
    if (func_021BAC90((void *)(((struct ResearchProc *)a0)->f14)) != 0) {
    if (func_021BAC98((void *)(((struct ResearchProc *)a0)->f14)) == 0) {
    return 1;
    }
    return 4;
    }
    return 2;
}

u32 func_021B9824(u32 a0)
{
    func_021BD62C((unsigned char *)(((struct ResearchProc *)a0)->f18));
    if (func_021BD708((void *)(((struct ResearchProc *)a0)->f18)) != 0) {
    if (func_021BD710((void *)(((struct ResearchProc *)a0)->f18)) == 0) {
    return 1;
    }
    return 4;
    }
    return 3;
}

u32 func_021B9850(const void *p)
{
    return *(const u32 *)&((struct ResearchProc *)p)->f8;
}

void func_021B9854(void *p)
{
    u32 *counter = (u32 *)((char *)p + 8);
    *counter += 1;
}

void func_021B985C(void *p, u32 value)
{
    ((struct ResearchProc *)p)->f0 = 1;
    ((struct ResearchProc *)p)->f4u = value;
    ((struct ResearchProc *)p)->f8 = 0;
    ((struct ResearchProc *)p)->fC = 0;
    ((struct ResearchProc *)p)->f10 = 0;
    ((struct ResearchProc *)p)->f14 = 0;
    ((struct ResearchProc *)p)->f18 = 0;
    ((struct ResearchProc *)p)->f1C = 0;
}

void func_021B9874(u32 a0)
{
    ((struct ResearchProc *)a0)->fC = RESEARCH_COMMON_Create(((struct ResearchProc *)a0)->f0, ((struct ResearchProc *)a0)->f4u);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B9884(u32 a0)
{
    RESEARCH_COMMON_Destroy((void *)(((struct ResearchProc *)a0)->fC));
    ((struct ResearchProc *)a0)->fC = 0;
    return 0;
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void func_021B9894(u32 a0)
{
    u32 r = ListViewState_Create(((struct ResearchProc *)a0)->f0);
    ((struct ResearchProc *)a0)->f1C = r;
    ListViewState_Reset((void *)r);
}

u32 func_021B98A8(u32 a0)
{
    ListViewState_Destroy((void *)(((struct ResearchProc *)a0)->f1C));
    ((struct ResearchProc *)a0)->f1C = 0;
    return 0;
}

/*
 * Hint note: d_021C2E60 data line carries no overlay token (contested hint).
 */
void func_021B98B8(unsigned short heapId)
{
    func_0203F8F4(heapId);
    func_0203FC28((struct DispConfig *)(&d_021C2E30));
    func_0203FCA0(4, (const struct BgTemplate *)(&d_021C2E60), 0);
    func_0203FCA0(5, (const struct BgTemplate *)(&d_021C2E40), 0);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_0203FCA0(1, (const struct BgTemplate *)(&d_021C2E80), 0);
    func_02040588(1, 1);
}

u32 func_021B990C(void)
{
    func_020403F4(1);
    func_020403F4(4);
    return func_0203F9B4();
}

void func_021B9920(u32 heap)
{
    void *palette;
    void *character;
    void *screen;
    void *screen2;
    struct ArcFile *arc;
    void *buffer;
    arc = func_020490F4(192, heap);
    buffer = ARC_TOOL_LoadHandleMember(arc, 9, heap);
    func_02062A98(buffer, &palette);
    func_02040E78(4, *(void **)((char *)palette + 12), 512, 0);
    func_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 10, heap);
    func_02062A4C(buffer, &character);
    func_02040B1C(4, *(void **)((char *)character + 0x14), *(u32 *)((char *)character + 0x10), 0);
    func_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 11, heap);
    func_02062B30(buffer, &screen);
    func_02041090(4, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_020409B4(4);
    func_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 12, heap);
    func_02062B30(buffer, &screen2);
    func_02041090(5, (u32)((char *)screen2 + 12), 0, 0, 32, 24);
    func_020409B4(5);
    func_020307B0(buffer);
    ARC_TOOL_DeleteHandle(arc);
}

void func_021B99EC(const void *p)
{
    u32 t = func_021B9850(p) / 10;
    u32 m = (u8)(t % 6);
    func_020413B0(5, 0, 0, 0x20, 0x18, (u8)m);
    func_020409B4(5);
}

void func_021B9A24(u32 heap)
{
    void *palette;
    void *character;
    void *screen;
    struct ArcFile *arc;
    void *buffer;
    arc = ARC_TOOL_CreateHandle(192, (u16)((heap & 0x7fff) | 0x8000));
    buffer = ARC_TOOL_LoadHandleMember(arc, 0, heap);
    func_02062A98(buffer, &palette);
    func_02040E78(1, ((struct Obj25805 *)palette)->fC, 512, 0);
    sub_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 1, heap);
    func_02062A4C(buffer, &character);
    func_02040B1C(1, ((struct ResearchProc *)character)->f14p, ((struct ResearchProc *)character)->f10, 0);
    sub_020307B0(buffer);
    buffer = ARC_TOOL_LoadHandleMember(arc, 2, heap);
    func_02062B30(buffer, &screen);
    func_02041090(1, (u32)((char *)screen + 12), 0, 0, 32, 24);
    sub_020409B4(1);
    sub_020307B0(buffer);
    ARC_TOOL_DeleteHandle(arc);
}

u32 func_021B9AD0(void *self)
{
    u32 v = RESEARCH_COMMON_GetHeapId(self);
    u32 o = func_021BA4E0(v);
    func_021BA504((char *)o);
    func_021BA4D0((void *)o, v);
    func_021BA4CC((void *)o, (u32)self);
    return o;
}

u32 func_021B9AF8(void *a0)
{
    func_021BA68C((void *)a0);
    return func_021BA4FC(a0);
}

void func_021B9B08(char *p)
{
    switch (((struct ResearchObjC *)p)->f18) {
    case 0:func_021B9B98(p);break;
    case 1:func_021B9C54(p);break;
    case 2:func_021B9E44(p);break;
    case 3:func_021BA078((unsigned)p);break;
    case 4:func_021BA094((unsigned)p);break;
    case 5:func_021BA0C4((unsigned)p);break;
    case 6:return;
    }
    if (func_021B9B80(p)==0) {
        func_021BA1D4((unsigned)p);func_021BA41C((int *)p);
        RESEARCH_COMMON_UpdatePaletteAnime(*(unsigned *)&((struct ResearchObjC *)p)->f0);CLACT_DrawSystem();
    }
    func_021BA374(p);func_021BA158((unsigned)p);
}

int func_021B9B80(void *p)
{
    if (((struct ResearchObjC *)p)->f88 != 0) {
        return 1;
    }
    return 0;
}

/*
 * Field getter, u32 at +0x8c.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B9B90(void *p)
{
    return ((struct ResearchObjC *)p)->f8C;
}

void func_021B9B98(char *p)
{
    unsigned kind;
    func_021BA67C((unsigned)p);func_021BA5BC((unsigned)p);
    func_021BA5F8(p);func_021BA63C((u8 *)p);func_021BA560(p);
    func_021BA698(p);func_021BA768(p);func_021BA7B8(p);
    func_021BA7E0(p);func_021BA830(p);func_021BA86C(p);
    func_021BA910((struct Context *)p);func_021BA978((struct Context *)p);
    func_021BA9FC(p);func_021BAA48(p);func_021BAAD8(p);
    func_021BAB0C(p);func_021BAB70((unsigned)p);func_021BAB58(p);
    if (func_021BA3B4((unsigned)p,0)==0)func_021BA2FC((unsigned)p);
    kind=func_021BA19C((unsigned char *)p);
    func_021BA144((unsigned char *)p,func_021BA19C((unsigned char *)p));
    if (kind==2) {func_021BA284(((struct ResearchObjC *)p)->f28);func_021BA3E8((char *)((unsigned)p),0);}
    func_021BA354();func_021BA150(p);
}

/*
 * ABI: 02035C08 result is compared in the original; matched 02025EA4/02027E3C callers also declare its int return despite the forwarding body's void spelling.
 * Original passes p to 020362DC although the own matched body ignores entry r0.
 */
void func_021B9C54(char *p)
{
    u32 keys=KEY_GetTrg();
    int choice=TOUCHPANEL_HitTrg(p+44);
    int other=TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct ResearchObjC *)p)->f0));
    if(func_021BA4D4(p)!=0 || other==0) {
        func_021BA1C0((u8 *)p,1);func_021BA1CC(p,2);func_021BA31C((u8 *)p);GFL_USE_PlaySeDefaultVolume(1361);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);return;
    }
    if(keys&2) {
        func_021BA1C0((u8 *)p,0);func_021BA1CC(p,2);func_021BA31C((u8 *)p);GFL_USE_PlaySeDefaultVolume(1361);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);return;
    }
    if((keys&64)||(keys&128)||(keys&32)||(keys&16)||(keys&1)) {
        func_021BA284(*(int *)&((struct ResearchObjC *)p)->f28);func_021BA3E8(p,0);func_021BA150(p);func_021BA144((u8 *)p,2);return;
    }
    if(choice==0) {
        if(func_021BA3B4((u32)p,0)!=0) {
            func_021BA1C0((u8 *)p,1);func_021BA1CC(p,0);func_021BA254((u32)p,0);func_021BA284(*(int *)&((struct ResearchObjC *)p)->f28);func_021BA40C((u8 *)p,0);func_021BA3E8(p,2);GFL_USE_PlaySeDefaultVolume(1356);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(choice==1) {
        if(func_021BA3B4((u32)p,1)!=0) {
            func_021BA1C0((u8 *)p,1);func_021BA1CC(p,1);func_021BA254((u32)p,1);func_021BA284(*(int *)&((struct ResearchObjC *)p)->f28);func_021BA40C((u8 *)p,0);func_021BA3E8(p,2);GFL_USE_PlaySeDefaultVolume(1356);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    }
}

void func_021B9E44(char *p)
{
    u32 keys=KEY_GetTrg();
    int choice=TOUCHPANEL_HitTrg(p+44);
    int other=TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct ResearchObjC *)p)->f0));
    if(func_021BA4D4(p)!=0 || other==0) {
        func_021BA1C0((u8 *)p,1);func_021BA1CC(p,2);func_021BA31C((u8 *)p);GFL_USE_PlaySeDefaultVolume(1361);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);return;
    }
    if(keys&64)func_021BA1F8((u32)p);
    if(keys&128)func_021BA228((u32)p);
    if(keys&1) {
        func_021BA1C0((u8 *)p,0);func_021BA40C((u8 *)p,0);func_021BA3E8(p,2);GFL_USE_PlaySeDefaultVolume(1356);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
        switch(((struct ResearchObjC *)p)->f28) {
        case 0:func_021BA1CC(p,0);return;
        case 1:func_021BA1CC(p,1);return;
        default:func_021BA1CC(p,2);return;
        }
    }
    if(choice==0) {
        if(func_021BA3B4((u32)p,0)!=0) {
            func_021BA1C0((u8 *)p,1);func_021BA254((u32)p,0);func_021BA40C((u8 *)p,0);func_021BA3E8(p,2);GFL_USE_PlaySeDefaultVolume(1356);func_021BA1CC(p,0);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(choice==1) {
        if(func_021BA3B4((u32)p,1)!=0) {
            func_021BA1C0((u8 *)p,1);func_021BA254((u32)p,1);func_021BA40C((u8 *)p,0);func_021BA3E8(p,2);GFL_USE_PlaySeDefaultVolume(1356);func_021BA1CC(p,1);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(keys&2) {
        func_021BA31C((u8 *)p);GFL_USE_PlaySeDefaultVolume(1361);func_021BA1CC(p,2);func_021BA380(p,15);func_021BA150(p);func_021BA144((u8 *)p,3);func_021BA144((u8 *)p,4);func_021BA144((u8 *)p,5);
    }
}

/*
 * Steps the record through func_021BA150 while the running count is below
 * func_021BA37C().
 *
 * Addresses are Black-image addresses.
 */
void func_021BA078(u32 a0)
{
    u32 v1 = func_021BA384((void *)a0);
    if (v1 < func_021BA37C((void *)a0)) {
    func_021BA150((void *)a0);
    }
}

void func_021BA094(u32 a0)
{
    switch (func_021BA190((void *)a0)) {
    case 0:
    func_021BA364();
    func_021BA194((void *)a0);
    break;
    case 1:
    if (FADE_IsActive() == 0) {
    func_021BA150((void *)a0);
    }
    break;
    }
}

void func_021BA0C4(u32 a0)
{
    func_021BAB68();
    RESEARCH_COMMON_StopPaletteAnime(*(u32 *)&((struct ResearchObjC *)a0)->f0);
    RESEARCH_COMMON_RestorePaletteAnime(*(u32 *)&((struct ResearchObjC *)a0)->f0);
    func_021BAB38((char *)a0);
    func_021BAAF4((int *)a0);
    func_021BAAB8((u8 *)a0);
    func_021BAA28((int *)a0);
    func_021BA960(a0);
    func_021BA9D0(a0);
    func_021BA8E0((int *)a0);
    func_021BA848(a0);
    func_021BA82C(a0);
    func_021BA7D0(a0);
    func_021BA7B4(a0);
    func_021BA748(a0);
    func_021BA624((int *)a0);
    func_021BA5D8((u8 *)a0);
    ((struct ResearchObjC *)a0)->f88 = 1;
    func_021BA144((u8 *)a0, 6);
    func_021BA150((void *)a0);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 20)) to RingQueue_Push.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA144(u8 *a0, u32 a1)
{
    RingQueue_Push((u32)(((struct ResearchObjC *)a0)->f14), a1);
}

void func_021BA150(void *p)
{
    ((struct ResearchObjC *)p)->f80 = 1;
}

void func_021BA158(u32 a0)
{
    if (((struct ResearchObjC *)a0)->f80 != 0) {
    if (RingQueue_IsEmpty(((struct ResearchObjC *)a0)->f14) == 0) {
    func_021BA180((void *)a0, RingQueue_Pop((struct Ring *)(((struct ResearchObjC *)a0)->f14)));
    }
    }
}

/*
 * Set +0x18, clear +0x1c, +0x20 and +0x80.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA180(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->f18 = v;
    ((struct ResearchObjC *)p)->f1C = 0;
    ((struct ResearchObjC *)p)->f20 = 0;
    ((struct ResearchObjC *)p)->f80 = 0;
}

u32 func_021BA190(void *p)
{
    return ((struct ResearchObjC *)p)->f1C;
}

void func_021BA194(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x1c);
    *c += 1;
}

u32 func_021BA19C(u8 *a0)
{
    u32 v = ((struct ResearchObjC *)a0)->f0u;
    u32 a = RESEARCH_COMMON_GetPreviousScreen((void *)v);
    u32 b = RESEARCH_COMMON_GetEntryHandled((void *)v);
    if (a != 0 && b == 0) {
    return 2;
    }
    return 1;
}

void func_021BA1C0(u8 *a0, u32 a1)
{
    RESEARCH_COMMON_SetEntryHandled(*(u8 * *)&((struct ResearchObjC *)a0)->f0, a1);
}

void func_021BA1CC(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->f8C = v;
}

/*
 * One-shot latch on the +0x84 field.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA1D4(u32 a0)
{
    if (((struct ResearchObjC *)a0)->f84 == 0) {
    if (GAME_BEACON_PopQuestionnaireUpdated() == 1) {
    ((struct ResearchObjC *)a0)->f84 = 1;
    func_021BA328(a0);
    }
    }
}

void func_021BA1F8(u32 a0)
{
    func_021BA2BC(((struct ResearchObjC *)a0)->f28);
    func_021BA388((char *)a0, -1);
    func_021BA284(((struct ResearchObjC *)a0)->f28);
    GFL_USE_PlaySeDefaultVolume(1352);
    func_021BA3E8((char *)a0, 1);
}

void func_021BA228(u32 a0)
{
    func_021BA2BC(((struct ResearchObjC *)a0)->f28);
    func_021BA388((char *)a0, 1);
    func_021BA284(((struct ResearchObjC *)a0)->f28);
    GFL_USE_PlaySeDefaultVolume(1352);
    func_021BA3E8((char *)a0, 1);
}

void func_021BA254(u32 a0, u32 a1)
{
    func_021BA2BC(((struct ResearchObjC *)a0)->f28);
    func_021BA3B0((void *)a0, a1);
    func_021BA284(((struct ResearchObjC *)a0)->f28);
    GFL_USE_PlaySeDefaultVolume(1352);
    func_021BA3E8((char *)a0, 1);
}

void func_021BA284(int sel)
{
    int a, b, c, d, e, f;
    switch (sel) {
    case 0:
        a = 2; b = 3; c = 5; d = 0x1a; e = 5; f = 0xa;
        break;
    case 1:
        a = 2; b = 3; c = 0xc; d = 0x1a; e = 5; f = 0xa;
        break;
    default:
        return;
    }
    func_020413B0(a, b, c, d, e, f);
    func_020409B4(a);
}

void func_021BA2BC(int sel)
{
    int a, b, c, d, e, f;
    switch (sel) {
    case 0:
        a = 2; b = 3; c = 5; d = 0x1a; e = 5; f = 5;
        break;
    case 1:
        a = 2; b = 3; c = 0xc; d = 0x1a; e = 5; f = 6;
        break;
    default:
        return;
    }
    func_020413B0(a, b, c, d, e, f);
    func_020409B4(a);
}

void func_021BA2FC(u32 a0)
{
    BgTextLabel_SetPalette((u8 *)(((struct ResearchObjC *)a0)->f54), 15);
    func_021BA3E8((char *)a0, 3);
    func_021BA3E8((char *)a0, 4);
}

void func_021BA31C(u8 *a0)
{
    RESEARCH_COMMON_StartPaletteAnime((u8 *)(((struct ResearchObjC *)a0)->f0u), 0);
}

u32 func_021BA328(u32 a0)
{
    u32 v1 = func_021BA3E0((void *)a0, 0);
    CLACT_SetActorDrawEnable((struct Obj *)v1, 1);
    CLACT_SetActorAutoAnim((struct Obj *)v1, 1);
    CLACT_SetActorAutoAnimSpeed((struct Actor *)v1, 4096);
    return CLACT_SetActorAnimFrame(v1, 0);
}

void func_021BA354(void)
{
    FADE_Start(3, 0x10, 0, 0);
}

void func_021BA364(void)
{
    FADE_Start(3, 0, 16, 0);
}

void func_021BA374(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x20);
    *c += 1;
}

u32 func_021BA37C(void *p)
{
    return ((struct ResearchObjC *)p)->f20;
}

/*
 * Field setter, u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA380(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->f24 = v;
}

u32 func_021BA384(void *p)
{
    return ((struct ResearchObjC *)p)->f24;
}

void func_021BA388(char *self, int d)
{
    int n = *(int *)&((struct ResearchObjC *)self)->f28;
    do {
        n = (n + d + 2) % 2;
    } while (!func_021BA3B4((u32)self, n));
    *(int *)&((struct ResearchObjC *)self)->f28 = n;
}

/*
 * Field setter, u32 at +0x28.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA3B0(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->f28 = v;
}

u32 func_021BA3B4(u32 a0, u32 a1)
{
    if (a1 == 0) {
    if (func_021BA434((char *)a0) > 1) {
    return 1;
    }
    return 0;
    }
    return 1;
}

/*
 * Indexed u32 read: element i of the table at +0x5c.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BA3D0(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x5c);
}

/*
 * Indexed u32 read: element i of the table at +0x74.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BA3D8(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x74);
}

/*
 * Indexed u32 read: element i of the table at +0x7c.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BA3E0(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x7c);
}

void func_021BA3E8(char *self, int i)
{
    PALETTE_ANIME_Start(*(void **)(self + i * 4 + 0x38),
                  *(u32 *)(d_021C3004 + i * 0x14),
                  *(u16 *)(d_021C3008 + i * 0x14));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 56)), (a1)*4 to PALETTE_ANIME_Stop.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA40C(u8 *a0, u32 a1)
{
    PALETTE_ANIME_Stop((u32)(*(u32*)(a0 + (a1)*4 + 56)));
}

void func_021BA41C(int *p)
{
    int i;
    for (i = 0; i < 5; i++)
        PALETTE_ANIME_Update(p[i + 0x0E]);
}

/*
 * trailing: 021BA4C6..021BA4C8 zero alignment padding.
 */
unsigned char func_021BA434(char *p)
{
    void *bitmap=(void *)func_0201296C((const struct BigObj *)RESEARCH_COMMON_GetAppResource(((struct ResearchObjC *)p)->f0));
    int count=1;
    if(ZONEDATA_CheckEventFlag(bitmap,240)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,241)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,242)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,243)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,244)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,245)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,246)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,247)==1)count++;
    if(ZONEDATA_CheckEventFlag(bitmap,248)==1)count++;
    return count;
}

u32 func_021BA4C8(void *p)
{
    return ((struct ResearchObjC *)p)->f0u;
}

void func_021BA4CC(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->f0u = v;
}

/*
 * Field setter, u16 at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA4D0(void *p, u32 v)
{
    ((struct ResearchObjC *)p)->f4 = v;
}

u32 func_021BA4D4(void *p)
{
    return RESEARCH_COMMON_GetInputFlag((void *)func_021BA4C8(p));
}

u32 func_021BA4E0(u32 a0)
{
    return (u32)func_02030734(a0, 144, 0, (const char *)0x21C3FEC, 1486);
}

u32 func_021BA4FC(void *a0)
{
    return func_020307B0(a0);
}

/*
 * trailing: 021BA55E..021BA560 zero alignment padding.
 */
void func_021BA504(char *p)
{
    ((struct ResearchObjC *)p)->f80=0;((struct ResearchObjC *)p)->f84=0;((struct ResearchObjC *)p)->f88=0;
    ((struct ResearchObjC *)p)->f18=0;((struct ResearchObjC *)p)->f20=0;((struct ResearchObjC *)p)->f24=0;
    ((struct ResearchObjC *)p)->f28=0;((struct ResearchObjC *)p)->f8C=2;((struct ResearchObjC *)p)->f1C=0;
    func_021BA8FC(p);func_021BA674(p);func_021BA5E4(p);func_021BA5B4(p);
    func_021BA858(p);func_021BA9E8(p);func_021BAA40(p);func_021BAAC4(p);
}

void func_021BA560(char *p)
{
    void *owner=((struct ResearchObjC *)p)->f0;
    unsigned a=RESEARCH_COMMON_GetPreviousScreen(owner),b=RESEARCH_COMMON_GetEntryHandled(owner);
    if(a!=0 && b==0) {
        unsigned mode;
        switch(a) {case 2:default:mode=0;break;case 3:mode=1;break;}
        func_021BA3B0(p,mode);
    } else {
        if(func_021BA3B4((unsigned)p,0)!=0) func_021BA3B0(p,0);
        else func_021BA3B0(p,1);
    }
}

void func_021BA5B4(void *p)
{
    ((struct ResearchObjC *)p)->f8 = 0;
}

void func_021BA5BC(u32 a0)
{
    u8 s[4];
    ((struct ResearchObjC *)a0)->f8 = (u32)GF_FONT_Create(23, 0, 0, 0, (u32)(((struct ResearchObjC *)a0)->f4));
}

void func_021BA5D8(u8 *a0)
{
    GF_FONT_Delete((void *)((u32)(((struct ResearchObjC *)a0)->f8)));
}

/*
 * Clear two u32 slots at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA5E4(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0xc) = 0;
}

void func_021BA5F8(char *self)
{
    int i = 0;
    do {
        int o = i * 4;
        *(u32 *)(self + o + 0xc) = (u32)func_02045B38((int)0, (int)2, (u16)(*(u32 *)((char *)d_021C2ED8 + o)), (u16)(((struct ResearchObjC *)self)->f4));
        i++;
    } while (i < 2);
}

void func_021BA624(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        MSGDATA_Delete((struct Rec *)p[i + 3]);
}

void func_021BA63C(u8 *self)
{
    int i = 0;
    do {
        int o = i * 4;
        u8 *t = d_021C2EE0 + o;
        self[o + 0x2e] = t[0];
        self[o + 0x2f] = t[1];
        self[o + 0x2c] = t[2];
        self[o + 0x2d] = t[3];
        i++;
    } while (i < 3);
}

void func_021BA674(void *p)
{
    ((struct ResearchObjC *)p)->f14 = 0;
}

void func_021BA67C(u32 a0)
{
    ((struct ResearchObjC *)a0)->f14 = RingQueue_Create(10, ((struct ResearchObjC *)a0)->f4);
}

void func_021BA68C(Rec *p)
{
    RingQueue_Destroy((void *)p->a);
}

void func_021BA698(char *p)
{
    func_0203FC28(&d_021C2EEC);
    func_0203FCA0(6,&d_021C2F78,0);func_0203FCA0(7,&d_021C2F18,0);
    func_0203FCA0(2,&d_021C2F38,0);func_0203FCA0(3,&d_021C2F58,0);
    func_02040588(4,1);func_02040588(5,1);func_02040588(6,1);func_02040588(7,1);
    func_02040588(1,1);func_02040588(2,1);func_02040588(3,1);
    func_0207D63C((volatile unsigned *)0x04001050,2,1,7,15);
    func_0207D63C((volatile unsigned *)0x04000050,4,2,16,5);
    BMP_WIN_Init(((struct ResearchObjC *)p)->f4);
}

void func_021BA748(u32 a0)
{
    BMP_WIN_Exit();
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(7);
    func_020403F4(6);
}

void func_021BA768(char *p)
{
    struct ArcFile *arc=func_020490F4(192,((struct ResearchObjC *)p)->f4);
    void *file=ARC_TOOL_LoadHandleMember(arc,13,((struct ResearchObjC *)p)->f4);
    void *data;
    func_02062B30(file,&data);
    func_02041090(6,(unsigned)((char *)data+12),0,0,32,24);
    func_020409B4(6);func_020307B0(file);ARC_TOOL_DeleteHandle(arc);
}

void func_021BA7B4(u32 a0)
{
}

u32 func_021BA7B8(void *a0)
{
    func_02040C14(7, 0, 1, 0);
    return func_020414EC(7);
}

void func_021BA7D0(u32 a0)
{
    func_02040DA8(7, 1, 0);
}

void func_021BA7E0(char *p)
{
    struct ArcFile *arc=func_020490F4(192,((struct ResearchObjC *)p)->f4);
    void *file=ARC_TOOL_LoadHandleMember(arc,4,((struct ResearchObjC *)p)->f4);
    void *data;
    func_02062B30(file,&data);
    func_02041090(2,(unsigned)((char *)data+12),0,0,32,24);
    func_020409B4(2);func_020307B0(file);ARC_TOOL_DeleteHandle(arc);
}

void func_021BA82C(u32 a0)
{
}

u32 func_021BA830(void *a0)
{
    func_02040C14(3, 0, 1, 0);
    return func_020414EC(3);
}

void func_021BA848(u32 a0)
{
    func_02040DA8(3, 1, 0);
}

void func_021BA858(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x4c) = 0;
}

void func_021BA86C(char *p)
{
    struct Desc desc;
    int i;
    for(i=0;i<4;i++) {
        const struct Entry_021BA86C *s=&d_021C2F98[i];
        desc.a=s->desc.a;desc.b=s->desc.b;desc.c=s->desc.c;desc.d=s->desc.d;
        desc.e=s->desc.e;desc.f=s->desc.f;desc.g=s->desc.g;desc.h=s->desc.h;
        desc.i=s->desc.i;desc.j=s->desc.j;desc.k=s->desc.k;desc.data=s->data;
        *(unsigned *)(p+i*4+0x4c)=(unsigned int)BgTextLabel_Create((const struct Config *)(&desc),((struct ResearchObjC *)p)->f8,*(unsigned *)(p+s->desc.data*4+0xc),((struct ResearchObjC *)p)->f4);
        BgTextLabel_PrintMessage(*(unsigned *)(p+i*4+0x4c),s->mode);
    }
}

void func_021BA8E0(int *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        BgTextLabel_Destroy((u8 *)p[i + 0x13]);
        p[i + 0x13] = 0;
    }
}

/*
 * Clear six u32 slots at +0x5c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA8FC(void *p)
{
    int i;
    for (i = 0; i < 6; i++)
        *(u32 *)((char *)p + i * 4 + 0x5c) = 0;
}

/*
 * trailing: 021BA95E..021BA960 zero alignment padding.
 * lever: acquisition-order a,b,c stores hoist spilled b reload before c store.
 * ABF0 forwards AC18's returned r0; caller stores it at +0x6c.
 */
void func_021BA910(struct Context *p)
{
    u16 heap=p->heap;
    void *arc=func_020490F4(192,heap);
    int a=CLACT_RegisterCharacter((void *)((unsigned)arc),15,0,1,heap);
    int b=CLACT_RegisterPalette((void *)arc,16,1,0,heap);
    int c=CLACT_RegisterCellAnim((void *)((unsigned)arc),14,17,heap);
    p->slots[3]=a;p->slots[4]=b;p->slots[5]=c;
    ARC_TOOL_DeleteHandle(arc);
}

u32 func_021BA960(u32 a0)
{
    CLACT_ReleaseCharacter(((struct ResearchObjC *)a0)->f68);
    CLACT_ReleasePalette(((struct ResearchObjC *)a0)->f6C);
    return CLACT_ReleaseCellAnim(((struct ResearchObjC *)a0)->f70);
}

void func_021BA978(struct Context *p)
{
    u16 heap=p->heap;
    void *arc=func_020490F4(192,heap);
    int a=CLACT_RegisterCharacter((void *)((unsigned)arc),15,0,0,heap);
    int b=CLACT_RegisterPaletteEx((void *)((unsigned)arc),16,0,192,0,4,heap);
    int c=CLACT_RegisterCellAnim((void *)((unsigned)arc),14,17,heap);
    p->slots[0]=a;p->slots[1]=b;p->slots[2]=c;
    ARC_TOOL_DeleteHandle(arc);
}

u32 func_021BA9D0(u32 a0)
{
    CLACT_ReleaseCharacter(((struct ResearchObjC *)a0)->f5C);
    CLACT_ReleasePalette(((struct ResearchObjC *)a0)->f60);
    return CLACT_ReleaseCellAnim(((struct ResearchObjC *)a0)->f64);
}

void func_021BA9E8(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0x74) = 0;
}

void func_021BA9FC(char *self)
{
    int i = 0;
    do {
        *(u32 *)(self + i * 4 + 0x74) = (u32)CLACT_CreateUnit(d_021C2ED2[i], d_021C2ED0[i], ((struct ResearchObjC *)self)->f4);
        i++;
    } while (i < 2);
}

/*
 * Addresses are Black-image addresses.
 */
void func_021BAA28(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        CLACT_DeleteUnit((struct Bank *)p[i + 0x1D]);
}

/*
 * Clear the u32 at +0x7c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BAA40(void *p)
{
    ((struct ResearchObjC *)p)->f7C = 0;
}

/*
 * B294's returned r0 is stored and passed to B3DC in the original.
 */
void func_021BAA48(char *p)
{
    struct Vec vec;
    unsigned first,second,third,fourth;
    vec.x=d_021C2EFC.vec.x;vec.y=d_021C2EFC.vec.y;vec.z=d_021C2EFC.vec.z;
    vec.a=d_021C2EFC.vec.a;vec.b=d_021C2EFC.vec.b;
    first=func_021BA3D8(p,d_021C2EFC.first);
    second=func_021BA3D0(p,d_021C2EFC.second);
    third=func_021BA3D0(p,d_021C2EFC.third);
    fourth=func_021BA3D0(p,d_021C2EFC.fourth);
    *(unsigned *)&((struct ResearchObjC *)p)->f7C=(unsigned)CLACT_CreateActor((void *)first,second,third,fourth,&vec,d_021C2EFC.arg,((struct ResearchObjC *)p)->f4);
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ResearchObjC *)p)->f7C,0);
}

void func_021BAAB8(u8 *a0)
{
    CLACT_DeleteActor((struct Obj *)((u32)(((struct ResearchObjC *)a0)->f7C)));
}

/*
 * Clear five u32 slots at +0x38.
 *
 * Addresses are Black-image addresses.
 */
void func_021BAAC4(void *p)
{
    int i;
    for (i = 0; i < 5; i++)
        *(u32 *)((char *)p + i * 4 + 0x38) = 0;
}

void func_021BAAD8(char *p)
{
    int i;
    for (i = 0; i < 5; i++)
        ((int *)(p + 0x38))[i] = PALETTE_ANIME_Create(((struct ResearchObjC *)p)->f4);
}

void func_021BAAF4(int *p)
{
    int i;
    for (i = 0; i < 5; i++)
        PALETTE_ANIME_Destroy((void *)p[i + 0x0E]);
}

void func_021BAB0C(char *self)
{
    int i;
    for (i = 0; i < 5; i++) {
        PALETTE_ANIME_Bind((void *)(*(int *)(self + i * 4 + 0x38)), d_021C2FF8[i].a, d_021C2FF8[i].b, d_021C2FF8[i].c);
    }
}

void func_021BAB38(char *self)
{
    int i;
    for (i = 0; i < 5; i++) {
        PALETTE_ANIME_Restore((char *)(*(int *)(self + i * 4 + 0x38)));
    }
}

/*
 * Tail-call thunk: ldr r3,[pc,#0]; bx r3; .word 0x0204A648.  Blocker target
 * for func_021BAB58 (pkt_021B9850).
 */
void func_021BAB50(void)
{
    CLACT_VBlankSystem();
}

void func_021BAB58(void *a0)
{
    func_02005654((int)func_021BAB50, 0);
}

/*
 * Tail-call veneer: branch to func_0200566C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BAB68(void)
{
    func_0200566C();
}

void func_021BAB70(u32 a0)
{
    GFL_NET_RestartWithDefaultTimeout(1, ((struct ResearchObjC *)a0)->f4);
}
