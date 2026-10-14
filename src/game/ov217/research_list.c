/*
 * file:     research_list.c
 * unit:     yes
 * function: func_021BAB80, func_021BABB4, func_021BABC4, func_021BAC90, func_021BAC98, func_021BACA0, func_021BAE00, func_021BAF70, func_021BB190, func_021BB200, func_021BB2B4, func_021BB37C, func_021BB484, func_021BB534, func_021BB5F4, func_021BB69C, func_021BB710, func_021BB784, func_021BB84C, func_021BB908, func_021BB910, func_021BB91C, func_021BB928, func_021BB934, func_021BB940, func_021BB948, func_021BB94C, func_021BB974, func_021BB978, func_021BB98C, func_021BB990, func_021BB998, func_021BB9A0, func_021BB9D0, func_021BBA00, func_021BBA30, func_021BBAA4, func_021BBAD0, func_021BBADC, func_021BBB60, func_021BBBE4, func_021BBC50, func_021BBCB0, func_021BBCFC, func_021BBD14, func_021BBD18, func_021BBD28, func_021BBD38, func_021BBD40, func_021BBD68, func_021BBDAC, func_021BBDF0, func_021BBE7C, func_021BBF04, func_021BBF1C, func_021BBF28, func_021BBF3C, func_021BBF4C, func_021BBF60, func_021BC014, func_021BC06C, func_021BC07C, func_021BC0E8, func_021BC128, func_021BC168, func_021BC1AC, func_021BC200, func_021BC250, func_021BC264, func_021BC274, func_021BC280, func_021BC2B8, func_021BC2CC, func_021BC2D8, func_021BC2FC, func_021BC30C, func_021BC330, func_021BC338, func_021BC380, func_021BC3AC, func_021BC3B8, func_021BC3D4, func_021BC3E0, func_021BC3EC, func_021BC3F8, func_021BC400, func_021BC40C, func_021BC41C, func_021BC428, func_021BC43C, func_021BC480, func_021BC490, func_021BC4A0, func_021BC4B4, func_021BC50C, func_021BC55C, func_021BC574, func_021BC580, func_021BC5A8, func_021BC5B8, func_021BC5D4, func_021BC5F0, func_021BC5FC, func_021BC600, func_021BC608, func_021BC610, func_021BC628, func_021BC634, func_021BC638, func_021BC63C, func_021BC640, func_021BC644, func_021BC688, func_021BC6D0, func_021BC6DC, func_021BC6E4, func_021BC6EC, func_021BC6F4, func_021BC708, func_021BC714, func_021BC720, func_021BC72C, func_021BC740, func_021BC758, func_021BC774, func_021BC818, func_021BC820, func_021BC8B4, func_021BC8D0, func_021BC8D8, func_021BC8E4, func_021BC910, func_021BC924, func_021BC93C, func_021BC94C, func_021BC954, func_021BC960, func_021BC9FC, func_021BCAC0, func_021BCAE8, func_021BCB44, func_021BCB48, func_021BCB60, func_021BCB70, func_021BCBCC, func_021BCBD0, func_021BCC3C, func_021BCC40, func_021BCC58, func_021BCC68, func_021BCD6C, func_021BCD90, func_021BCDDC, func_021BCDF0, func_021BCE5C, func_021BCE7C, func_021BCF20, func_021BCF4C, func_021BCF68, func_021BCF98, func_021BCFB4, func_021BCFD0, func_021BD05C, func_021BD078, func_021BD094, func_021BD0C4, func_021BD178, func_021BD274, func_021BD370, func_021BD38C, func_021BD3A4, func_021BD3B4, func_021BD458, func_021BD474, func_021BD47C, func_021BD4CC, func_021BD4F0, func_021BD50C, func_021BD520, func_021BD53C, func_021BD56C, func_021BD588, func_021BD5B4, func_021BD5C4, func_021BD5E0
 * address:  0x021BAB80
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
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
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
 *   RESEARCH_COMMON_GetEntryHandled  0x021C09CC  thumb  ov217
 *   RESEARCH_COMMON_SetEntryHandled  0x021C09C4  thumb  ov217
 *   BgTextLabel_SetPalette  0x021C1038  thumb  ov217
 *   RESEARCH_COMMON_StartPaletteAnime  0x021C09D8  thumb  ov217
 *   PALETTE_ANIME_Start  0x021C29F8  thumb  ov217
 *   PALETTE_ANIME_Stop  0x021C2A00  thumb  ov217
 *   PALETTE_ANIME_Update  0x021C29F0  thumb  ov217
 *   RESEARCH_COMMON_GetAppResource 0x021C09B4 thumb ov217
 *   func_0201296C 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   RESEARCH_COMMON_GetInputFlag  0x021C09F8  thumb  ov217
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   RingQueue_Create  0x021C0E08  thumb  ov217
 *   RingQueue_Destroy  0x021C0E3C  thumb  ov217
 *   func_0207D63C 0x0207D63C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_02040DA8  0x02040DA8  arm
 *   BgTextLabel_Create 0x021C0EF4 thumb ov217
 *   BgTextLabel_PrintMessage 0x021C0F5C thumb ov217
 *   BgTextLabel_Destroy  0x021C0F48  thumb  ov217
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   PALETTE_ANIME_Create  0x021C29C8  thumb  ov217
 *   PALETTE_ANIME_Destroy  0x021C29D8  thumb  ov217
 *   PALETTE_ANIME_Bind  0x021C29E8  thumb  ov217
 *   PALETTE_ANIME_Restore  0x021C2A08  thumb  ov217
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   KEY_GetCont 0x0203630C arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200E394 0x0200E394 thumb
 *   func_0200E44C 0x0200E44C thumb
 *   d_021C308A 0x021C308A data a1
 *   d_021C3080 0x021C3080 data a1
 *   d_021C30A8 0x021C30A8 data a1
 *   func_0200E440 0x0200E440 thumb
 *   BMP_OAM_SetPalette  0x02025A54  thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0204162C 0x0204162C arm
 *   func_02041648  0x02041648  arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   d_021C309E 0x021C309E data a1
 *   d_021C3094 0x021C3094 data a1
 *   d_021C30D0 0x021C30D0 data a1
 *   BgTextLabel_SetVisible  0x021C0FF8  thumb  ov217
 *   func_02041EE4 0x02041EE4 arm
 *   func_02040804  0x02040804  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   d_021C326C 0x021C326C data a4
 *   PALETTE_ANIME_IsRunning  0x021C2A10  thumb  ov217
 *   ListViewState_GetMode 0x021C0DF0 thumb ov217
 *   ListViewState_GetScrollX 0x021C0DF4 thumb ov217
 *   ListViewState_GetScrollY 0x021C0DF8 thumb ov217
 *   ListViewState_SetScrollY 0x021C0E04 thumb ov217
 *   ListViewState_SetScrollX 0x021C0E00 thumb ov217
 *   ListViewState_SetMode 0x021C0DFC thumb ov217
 *   BMP_OAM_SetEnabled  0x02025774  thumb
 *   d_021C3068  0x021C3068  data  ov217  a4
 *   func_02045B38 0x02045B38 arm
 *   d_021C3078 0x021C3078 data a4
 *   d_021C30B2 0x021C30B2 data a1 ov217
 *   d_021C3190 0x021C3190 data a4
 *   d_021C3070 0x021C3070 data a4 ov217
 *   d_021C30C0 0x021C30C0 data a4 ov217
 *   d_021C3110 0x021C3110 data a4 ov217
 *   d_021C3130 0x021C3130 data a4 ov217
 *   d_021C30F0 0x021C30F0 data a4 ov217
 *   d_021C3150 0x021C3150 data a4
 *   d_021C3170 0x021C3170 data a4 ov217
 *   d_021C33C8 0x021C33C8 data a4
 *   d_021C3520 0x021C3520 data a4
 *   CLACT_CreateUnit 0x0204B100 arm
 *   d_021C305C 0x021C305C data a1
 *   d_021C3060 0x021C3060 data a2
 *   d_021C320C 0x021C320C data a4
 *   BMP_Create 0x02043678 arm
 *   d_021C3470 0x021C3470 data a4
 *   BMP_CreateFromArchive 0x0204384C arm
 *   BMP_Blit 0x020439A0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_Delete 0x020437AC arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   d_021C3350 0x021C3350 data a4
 *   d_021C349C 0x021C349C data a4
 *   d_021C32D8 0x021C32D8 data a4
 *   d_021C34C8 0x021C34C8 data a4
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *   BMP_OAM_Create  0x020255A0  thumb
 *   BMP_OAM_UploadChars  0x020257D0  thumb
 *   d_021C31BC 0x021C31BC data a4
 *   BMP_OAM_Delete  0x0202570C  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   d_021C3260 0x021C3260 data a4
 *   func_020056A0  0x020056A0  thumb
 *   FADE_Start  0x0204E720  arm
 *   PALANM_RequestFade 0x0202173C thumb
 *   func_020056BC 0x020056BC thumb
 *   PALANM_TransferPalettes  0x02021D50  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   PALANM_Create  0x02021518  thumb  arm9
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb  arm9
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb  arm9
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb  arm9
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   FADE_IsActive  0x0204E804  arm  arm9
 *   func_02030EAC  0x02030EAC  arm
 *   func_02030734  0x02030734  arm
 */
#include "../../matched/include/Obj00801.h"
#include "../../matched/include/Obj25879.h"
#include "../../matched/include/Obj14733.h"
#include "../../matched/include/Obj14734.h"
#include "../../matched/include/Obj25887.h"
#include "research_top_shared_types.h"
#include "research_list_shared_types.h"

#define GB ((const struct G *)gb)

struct ResearchTop {
    u32 f0;
    union { void * f4; u32 f4u; };
    u16 f8;
    u8 padA[0x2];
    union { u32 fC; void * fCp; };
    union {
        u32 arr[0x50];
        struct {
            u8 pad10[0x8];
            u32 f18;
            u32 f1C;
            u32 f20;
            u32 f24;
            u32 f28;
            u32 f2C;
            u8 f30;
            u8 f31;
            u8 f32;
            u8 pad33;
            int f34;
            u32 f38;
            u32 f3C;
            union { u32 f40; int f40s; };
            int f44;
            int f48;
            int f4C;
            u32 f50;
            u32 f54;
            u8 pad58[0x40];
            void * f98;
            u8 pad9C[0x18];
            void * fB4[8];
            u8 padD4[0x10];
            u32 fE4;
            u32 fE8;
            u32 fEC;
            u32 fF0;
            u32 fF4;
            int fF8;
            int fFC;
            int f100;
            int f104;
            int f108;
            int f10C;
            int f110;
            int f114[3];
            u8 pad120[0xC];
            u32 f12C;
            u8 pad130[0x10];
            void * f140[4];
        };
    };
    union { void * f150; u32 f150u; };
    u32 f154;
    u32 f158;
    u32 f15C;
    u32 f160;
    u32 f164;
    u32 f168;
};

typedef enum { INDEX_ZERO=0 } Index;

typedef enum { PLANE_NONE=0,PLANE_OUT=31,PLANE_IN=19 } Plane;

typedef enum { FALSE=0,TRUE=1 } Bool;

typedef enum { ZERO = 0 } Origin;

struct Ent_021BBF04 { unsigned int a; unsigned short b; unsigned short pad; unsigned int c[3]; };

struct Ent_021BCAE8 {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad;
    u32 idx;
    u32 arg;
    u32 w;
};

struct Loc {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad;
    u32 w;
};

struct Entry_021BBF04 { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };

struct Entry_021C3470 { int x, y, z; int bank; int index; int px; int py; u8 r, g, b, pad2; u32 arc, member, enabled; };

typedef short s16_021BD178;

struct Tab { int v[3][10]; };

struct G {
    char pad0[0xc];
    u32 f0c;
    u32 f10;
    int f14;
    int f18;
    u8 f1c;
    u8 f1d;
    u8 f1e;
    u8 pad1f;
    u32 f20;
    u32 f24;
};

typedef signed short s16_021BD370;

struct Param { void *bmp; s16_021BD370 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

struct Entry_021BD0C4 { s16_021BD370 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

struct Entry021C3260 {
    int a;
    int b;
    unsigned char c;
    unsigned char pad[11];
};

typedef struct { unsigned short x, y; } Pos;

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void func_0203FC28(struct DispConfig *cfg);

extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void func_02040588(unsigned char which, unsigned char enable);

extern u32 func_020403F4(u32 i);

extern void *func_020490F4(unsigned int id, u32 heap);

extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *, u32, u32);

extern u32 func_020307B0(void *p);

extern int func_02062B30(void *, void **);

extern void func_02041090(u32, u32, u32, u32, u8, u8);

extern void ARC_TOOL_DeleteHandle(void *);

extern void func_020413B0(int index, int x0, int y0, int w, int h, int pal);

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

extern u32 RESEARCH_COMMON_GetEntryHandled(void *p);

extern void RESEARCH_COMMON_SetEntryHandled(u8 *p, u32 v);

extern void BgTextLabel_SetPalette(u8 *p, u8 palette);

extern void RESEARCH_COMMON_StartPaletteAnime(u8 *p, u32 i);

extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);

extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);

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

extern int TOUCHPANEL_HitCont(const void *p);

extern u32 TOUCHPANEL_GetPointCont(u32 *,u32 *);

extern u32 KEY_GetCont(void);

extern void *GAME_DATA_GetSaveControl(struct Big *);

extern void *func_0200E394(void *a0);

extern int func_0200E44C(int p0, int p1);

extern void func_0200E440(u8 *p, int value, int index);

extern void BMP_OAM_SetPalette(u8 *g, u32 a);

extern void func_02041B6C(u32 layer);

extern u32 func_0204162C(int channel);

extern u32 func_02041648(u8 channel);

extern void CLACT_AddActorSurfacePos(struct Obj *p,const struct Vec2 *delta,u32 which);

extern void BgTextLabel_SetVisible(u8 *p, int visible);

extern void func_02041EE4(unsigned layer,unsigned mode,unsigned value);

extern u32 func_02040804(u32 layer);

extern void func_02040618(u32 layer, u32 a, u32 b);

extern u32 func_0209C0A4(u32, u32);

extern int PALANM_RequestFade(PalAnmObj *, u16, u16, s16, u8, u8, u16, void *);

extern u32 PALANM_GetFadeRequestBits(const char *ptr);

extern u32 PALETTE_ANIME_IsRunning();

extern u32 PALANM_TransferPalettes(struct S02021D50 *p);

extern u32 func_020419E4();

extern u32 ListViewState_GetMode(void *p);

extern u32 ListViewState_GetScrollX(void *p);

extern u32 ListViewState_GetScrollY(void *p);

extern void ListViewState_SetScrollY(void *, u32);

extern void ListViewState_SetScrollX(void *, u32);

extern void ListViewState_SetMode(void *, u8);

extern void BMP_OAM_SetEnabled(u8 *g, u32 a);

extern u32 func_020056BC(void);

extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

extern struct Bmp *BMP_CreateFromArchive(u32,u32,u32,u32);

extern void BMP_Blit(struct Bmp *,struct Bmp *,u32,u32,int,int,u32,u32,u32);

extern void *func_02045EC0(struct MsgBank *,u32);

extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);

extern void BMP_Delete(struct Obj020437AC *p);

extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);

extern void BMP_OAM_DeleteSys(void *p);

extern struct Grid *BMP_OAM_Create(struct Sys *,const struct Param *);

extern void BMP_OAM_UploadChars(struct Obj *);

extern void BMP_OAM_Delete(struct Grid *g);

extern void *PALANM_Create(u32);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *, u32, u32, u32);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *, u32, u32, u32);

extern u32 PALANM_Delete(void *a0);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);

extern int func_020056A0(void (*)(void), void *, int);

extern void func_02030EAC(struct Node *n);

u32 func_021BAB80(u32 a0, u32 a1);

u32 func_021BABB4(void *a0);

void func_021BABC4(void *self);

u32 func_021BAC90(void *p);

u32 func_021BAC98(void *p);

void func_021BACA0(u8 *p);

void func_021BAE00(u8 *p);

void func_021BAF70(char *p);

void func_021BB190(u8 *p);

void func_021BB200(struct ResearchTop *p);

void func_021BB2B4(char *p);

void func_021BB37C(char *p);

void func_021BB484(u8 *p);

void func_021BB534(u8 *p);

void func_021BB5F4(u8 *p);

void func_021BB69C(u8 *p);

void func_021BB710(u8 *p);

void func_021BB784(struct ResearchTop *p);

void func_021BB84C(u8 *p);

void func_021BB908(void *p);

void func_021BB910(u8 *a0, u32 a1);

void func_021BB91C(void *p);

u32 func_021BB928(u8 *a0);

void func_021BB934(u8 *a0, u32 a1);

void func_021BB940(void *p, u32 v);

u32 func_021BB948(u8 *a0);

void func_021BB94C(u32 a0);

u32 func_021BB974(void *p);

int func_021BB978(char *p, int a1);

u32 func_021BB98C(void *p);

void func_021BB990(void *p);

void *func_021BB998(void *p);

void func_021BB9A0(u32 a0);

void func_021BB9D0(u32 a0);

void func_021BBA00(u32 a0, u32 a1);

void func_021BBA30(u8 *p);

void func_021BBAA4(u32 a0, u8 a1);

void func_021BBAD0(u32 a0);

void func_021BBADC(u8 *p);

void func_021BBB60(u8 *p);

void func_021BBBE4(u8 *p);

u8 func_021BBC50(u8 *p);

void func_021BBCB0(u8 *p);

void func_021BBCFC(void *p, s32 v);

void func_021BBD14(void *p, u32 v);

void func_021BBD18(int a, int b);

void func_021BBD28(int a, int b);

void func_021BBD38(void *p, u8 v);

void func_021BBD40(u8 *p, int a);

void func_021BBD68(u8 *p);

void func_021BBDAC(u8 *p);

void func_021BBDF0(u32 object,u32 slot);

void func_021BBE7C(u32 object,u32 slot);

u32 func_021BBF04(u32 a0, u32 a1);

u32 func_021BBF1C(u32 unused, u32 v);

int func_021BBF28(unsigned char *p, unsigned int slot);

int func_021BBF3C(unsigned char *p, unsigned char index);

int func_021BBF4C(unsigned char *p, unsigned int index);

void func_021BBF60(u8 *p);

void func_021BC014(u8 *p);

int func_021BC06C(char *p);

int func_021BC07C(u8 *p, u8 index);

void func_021BC0E8(u32 a0);

void func_021BC128(u32 a0);

void func_021BC168(u32 a0);

int func_021BC1AC(void *p);

int func_021BC200(void *p,int position);

void func_021BC250(void *p);

int func_021BC264(void *p);

void func_021BC274(void *p);

void func_021BC280(struct ResearchTop *p);

void func_021BC2B8(void *p);

void func_021BC2CC(void *p, u32 a, u32 b, u32 c);

void func_021BC2D8(struct ResearchTop *p);

int func_021BC2FC(void *p);

void func_021BC30C(struct ResearchTop *p, int v);

void func_021BC330(void *p, u32 v);

void func_021BC338(u8 *p);

void func_021BC380(struct ResearchTop *p);

int func_021BC3AC(void);

void func_021BC3B8(u32 a0);

u32 func_021BC3D4(void);

u32 func_021BC3E0(void);

int func_021BC3EC(u32 a0);

u32 func_021BC3F8(u32 v);

u32 func_021BC400(u32 v);

int func_021BC40C(void *p);

u32 func_021BC41C(void *p);

int func_021BC428(void *p);

void func_021BC43C(u8 *p);

void func_021BC480(void);

void func_021BC490(void);

int func_021BC4A0(void);

void func_021BC4B4(char *p);

void func_021BC50C(char *p);

u32 func_021BC55C(u32 a0);

void func_021BC574(u8 **p, u32 i);

void func_021BC580(char *p, int i);

void func_021BC5A8(u8 *a0, int a1);

u32 func_021BC5B8(u32 a0, u32 a1);

void func_021BC5D4(int *p);

void func_021BC5F0(u8 *a0);

u32 func_021BC5FC(void *p);

void func_021BC600(void *p);

void func_021BC608(void *p);

void func_021BC610(u32 a0, u32 a1);

u32 func_021BC628(u8 *a0);

void func_021BC634(void *p, u32 v);

void func_021BC638(void *p, u32 v);

u32 func_021BC63C(void *p);

void func_021BC640(void *p, u32 v);

void func_021BC644(struct ResearchTop *p);

void func_021BC688(char *p);

u32 func_021BC6D0(void *p);

u32 func_021BC6DC(void *p);

u32 func_021BC6E4(void *p);

void func_021BC6EC(void *p, u8 v);

u32 func_021BC6F4(u32 a0, u32 a1);

u32 func_021BC708(void *p, u32 i);

u32 func_021BC714(void *p, u32 i);

u32 func_021BC720(void *p, u32 i);

void func_021BC72C(u8 *a0, u32 a1, u8 *a2);

int func_021BC740(char *p, int i);

u32 func_021BC758(u32 a0);

void func_021BC774(u8 *p);

u32 func_021BC818(void *a0);

void func_021BC820(u8 *p);

void func_021BC8B4(u32 a0);

void func_021BC8D0(void *p);

void func_021BC8D8(u8 *a0);

void func_021BC8E4(struct ResearchTop *p);

void func_021BC910(void *p);

void func_021BC924(int *p);

void func_021BC93C(u32 a0);

void func_021BC94C(void *p);

void func_021BC954(u8 *a0);

void func_021BC960(u8 *p);

void func_021BC9FC(char *p);

u32 func_021BCAC0(u8 *a0);

void func_021BCAE8(char *p);

void func_021BCB44(u8 *a0);

u32 func_021BCB48(u32 a0);

void func_021BCB60(u32 a0);

void func_021BCB70(char *p);

void func_021BCBCC(u8 *a0);

void func_021BCBD0(struct ResearchTop *p);

void func_021BCC3C(u8 *a0);

u32 func_021BCC40(u32 a0);

void func_021BCC58(u32 a0);

void func_021BCC68(struct ResearchTop *p);

void func_021BCD6C(void *p);

void func_021BCD90(u8 *p);

void func_021BCDDC(void *p);

void func_021BCDF0(char *p);

u32 func_021BCE5C(u32 a0);

void func_021BCE7C(char *p);

u32 func_021BCF20(u32 a0);

void func_021BCF4C(void *p);

void func_021BCF68(struct ResearchTop *p);

void func_021BCF98(int *p);

void func_021BCFB4(void *p);

void func_021BCFD0(u8 *p);

void func_021BD05C(int *p);

void func_021BD078(void *p);

void func_021BD094(struct ResearchTop *p);

void func_021BD0C4(u8 *p);

void func_021BD178(struct ResearchTop *p);

void func_021BD274(struct ResearchTop *p);

void func_021BD370(int *p);

void func_021BD38C(char *p);

void func_021BD3A4(u8 *a0);

void func_021BD3B4(u8 *p);

void func_021BD458(int *p);

void func_021BD474(void *p);

void func_021BD47C(u8 *p);

u32 func_021BD4CC(u32 a0);

void func_021BD4F0(char *p);

void func_021BD50C(void *p);

void func_021BD520(int *p);

void func_021BD53C(int *p);

void func_021BD56C(int *p);

void func_021BD588(void *p);

void func_021BD5B4(u32 a0);

void func_021BD5C4(char *p);

void func_021BD5E0(u32 a0);

extern const u8 d_021C308A[];

extern const u8 d_021C3080[];

extern const u8 d_021C30A8[];

extern const u8 d_021C309E[];

extern const u8 d_021C3094[];

extern const u8 d_021C30D0[];

extern const struct Ent_021BBF04 d_021C326C[];

extern int d_021C3068[];

extern const unsigned int d_021C3078[];

extern const u8 d_021C30B2[];

extern const u8 d_021C3190[];

extern const u8 d_021C3070[];

extern struct DispConfig d_021C30C0;

extern const struct BgTemplate d_021C3110, d_021C3130, d_021C30F0, d_021C3150, d_021C3170;

extern const struct Ent_021BCAE8 d_021C33C8[];

extern const struct Ent_021BCAE8 d_021C3520[];

extern const u8 d_021C305C[];

extern const u16 d_021C3060[];

extern const struct Entry_021BBF04 d_021C320C[];

extern const struct Entry_021C3470 d_021C3470[];

extern const struct Tab d_021C3350;

extern const struct G d_021C349C;

extern const struct Tab d_021C32D8;

extern const struct G d_021C34C8;

extern const struct Entry_021BD0C4 d_021C31BC[];

extern const struct Entry021C3260 d_021C3260[];

u32 func_021BAB80(u32 a0, u32 a1)
{
    u32 v1 = RESEARCH_COMMON_GetHeapId((void *)a0);
    u32 v2 = func_021BC758(v1);
    func_021BC774((u8 *)v2);
    func_021BC634((void *)v2, v1);
    func_021BC638((void *)v2, a0);
    func_021BC640((void *)v2, a1);
    return v2;
}

u32 func_021BABB4(void *a0)
{
    func_021BC954((u8 *)a0);
    return func_021BC818(a0);
}

void func_021BABC4(void *self)
{
    switch (func_021BB974(self)) {
    case 0: func_021BACA0(self); break;
    case 1: func_021BAE00(self); break;
    case 2: func_021BAF70(self); break;
    case 3: func_021BB190(self); break;
    case 4: func_021BB200((struct ResearchTop *)self); break;
    case 6: func_021BB69C(self); break;
    case 5: func_021BB710(self); break;
    case 7: func_021BB484(self); break;
    case 8: func_021BB2B4(self); break;
    case 9: func_021BB534(self); break;
    case 10: func_021BB37C(self); break;
    case 11: func_021BB784((struct ResearchTop *)self); break;
    case 12: func_021BB5F4(self); break;
    case 13: func_021BB84C(self); break;
    case 14: break;
    }
    if (!func_021BAC90(self)) {
        func_021BC5F0(self);
        func_021BC5D4(self);
        CLACT_DrawSystem();
    }
    func_021BB908(self);
    func_021BB94C((u32)self);
}

u32 func_021BAC90(void *p)
{
    return ((struct ResearchTop *)p)->f164;
}

/*
 * Field getter, u32 at +0x168.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BAC98(void *p)
{
    return ((struct ResearchTop *)p)->f168;
}

void func_021BACA0(u8 *p)
{
    u8 slot;
    func_021BC93C((u32)p);
    func_021BC8B4((u32)p);
    func_021BC8E4((struct ResearchTop *)p);
    func_021BC960(p);
    func_021BC43C(p);
    func_021BC820(p);
    func_021BC9FC((char *)p);
    func_021BCAE8((char *)p);
    func_021BCB48((u32)p);
    func_021BCB70((char *)p);
    func_021BCBD0((struct ResearchTop *)p);
    func_021BCC40((u32)p);
    func_021BCC68((struct ResearchTop *)p);
    func_021BCDF0((char *)p);
    func_021BCE7C((char *)p);
    func_021BCF68((struct ResearchTop *)p);
    func_021BCFD0(p);
    func_021BD094((struct ResearchTop *)p);
    func_021BD0C4(p);
    func_021BD178((struct ResearchTop *)p);
    func_021BD274((struct ResearchTop *)p);
    func_021BD38C((char *)p);
    func_021BD3B4(p);
    func_021BD47C(p);
    func_021BD4F0((char *)p);
    func_021BD53C((int *)p);
    func_021BD5C4((char *)p);
    func_021BD5B4((u32)p);
    func_021BD588(p);
    func_021BC580((char *)p,0);
    func_021BC72C(p,0,0);
    func_021BC72C(p,1,0);
    func_021BC72C(p,2,0);
    func_021BC644((struct ResearchTop *)p);
    slot=func_021BBC50(p);
    if(slot!=255) {
        func_021BBDF0((u32)p,slot);
        func_021BC6EC(p,slot);
        func_021BC014(p);
    }
    func_021BC43C(p);
    func_021BC168((u32)p);
    func_021BC014(p);
    func_021BBF60(p);
    func_021BC06C((char *)p);
    if(func_021BB928(p)==0) {
        func_021BBD68(p);
        func_021BC128((u32)p);
        func_021BB91C(p);
        func_021BB910(p,2);
    } else {
        func_021BBDAC(p);
        func_021BC0E8((u32)p);
        func_021BB91C(p);
        func_021BB910(p,1);
    }
    func_021BC480();
}

/* Narrow selection parameters follow the caller's explicit lsls/lsrs #24 pairs. */
void func_021BAE00(u8 *p)
{
    u32 keys=KEY_GetTrg();
    int sel=TOUCHPANEL_HitTrg(p+0x64);
    int flag;
    u32 a,b;
    flag=TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(*(void **)p));
    TOUCHPANEL_GetPointCont(&a,&b);
    if(func_021BC6D0(p)!=0 || flag==0) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021BBAD0((u32)p);
        func_021BB934(p,1);
        func_021BB91C(p);
        func_021BB910(p,5);
        return;
    }
    if(keys&2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021BBAD0((u32)p);
        func_021BB934(p,0);
        func_021BB91C(p);
        func_021BB910(p,5);
        return;
    }
    if((keys&0x40)||(keys&0x80)||(keys&0x20)||(keys&0x10)||(keys&1)) {
        func_021BBD68(p);
        func_021BC128((u32)p);
        func_021BB91C(p);
        func_021BB910(p,2);
        return;
    }
    if(sel>=0 && sel<=9) {
        if(b>=24 && b<=168) {
            if(func_021BC6F4((u32)p,(u8)sel)==1) {
                func_021BBAA4((u32)p,sel);
                func_021BC6EC(p,p[0x32]);
                GFL_USE_PlaySeDefaultVolume(0x54c);
                func_021BC580((char *)p,2);
                func_021BC06C((char *)p);
                func_021BC128((u32)p);
                func_021BB91C(p);
                func_021BB910(p,7);
                return;
            }
        }
    } else {
        if(TOUCHPANEL_HitCont(p+0x90)==0 || TOUCHPANEL_HitTrg(p+0x90)==0) {
            if(func_021BC428(p)==1) {
                func_021BB91C(p);
                func_021BB910(p,4);
                func_021BB910(p,1);
            }
        }
    }
}

void func_021BAF70(char *p)
{
    u32 trg = KEY_GetCont();
    u32 keys = KEY_GetTrg();
    int sel = TOUCHPANEL_HitTrg(p + 0x64);
    int flag;
    u32 a;
    u32 b;
    flag = TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(*(void **)p));
    TOUCHPANEL_GetPointCont(&a, &b);
    if (trg & 0xc0) {
        func_021BC600(p);
    } else {
        func_021BC608(p);
    }
    if (func_021BC6D0(p) != 0 || flag == 0) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021BBAD0((u32)p);
        func_021BB934((u8 *)p, (int)1);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)6);
        return;
    }
    if ((keys & 0x40) || ((trg & 0x40) && ((struct ResearchTop *)p)->f32 != 0 && func_021BC5FC(p) > 10)) {
        func_021BBDAC((u8 *)p);
        func_021BBD40((u8 *)p, -1);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)3);
        func_021BB910((u8 *)p, (int)2);
        return;
    }
    if ((keys & 0x80) || ((trg & 0x80) && ((struct ResearchTop *)p)->f32 < (int)func_021BC6DC(p) - 1 && func_021BC5FC(p) > 10)) {
        func_021BBDAC((u8 *)p);
        func_021BBD40((u8 *)p, 1);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)3);
        func_021BB910((u8 *)p, (int)2);
        return;
    }
    if (keys & 1) {
        func_021BC580(p, 2);
        func_021BC6EC(p, ((struct ResearchTop *)p)->f32);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        func_021BB910((u8 *)p, (int)9);
        func_021BB91C(p);
        return;
    }
    if (sel >= 0 && sel <= 9) {
        if (b >= 0x18 && b <= 0xa8 && func_021BC6F4((u32)p, (u8)sel) == 1) {
            func_021BBAA4((u32)p, (u8)sel);
            func_021BC6EC(p, ((struct ResearchTop *)p)->f32);
            func_021BC580(p, 2);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            func_021BC06C(p);
            func_021BB91C(p);
            func_021BB910((u8 *)p, (int)7);
        }
        return;
    }
    if (keys & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021BBAD0((u32)p);
        func_021BB934((u8 *)p, (int)0);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)6);
        return;
    }
    if (TOUCHPANEL_HitCont(p + 0x90) == 0 || TOUCHPANEL_HitTrg(p + 0x90) == 0) {
        if (func_021BC428(p) == 1) {
            func_021BBDAC((u8 *)p);
            func_021BC0E8((u32)p);
            func_021BB91C(p);
            func_021BB910((u8 *)p, (int)4);
            func_021BB910((u8 *)p, (int)1);
        }
    }
}

void func_021BB190(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBADC(p);
        func_021BBAA4((unsigned)p, p[0x33]);
        func_021BC06C((char *)p);
        func_021BB990(p);
        break;
    case 1:
        func_021BC2D8((struct ResearchTop *)p);
        func_021BC338(p);
        func_021BC43C(p);
        func_021BC168((unsigned)p);
        func_021BC014(p);
        func_021BBF60(p);
        if (func_021BC2FC(p)) {
            func_021BBF60(p);
            func_021BB91C(p);
        }
        break;
    }
}

void func_021BB200(struct ResearchTop *p)
{
    int a;
    int b;
    int r = TOUCHPANEL_GetPointCont((unsigned int *)(&a), (unsigned int *)(&b));
    int m = func_021BB98C(p);
    switch (m) {
    case 0:
    {
        if (r == 0) {
            func_021BC280((struct ResearchTop *)p);
            func_021BC2B8(p);
            func_021BB990(p);
        } else {
            func_021BC30C((struct ResearchTop *)p, func_021BC200(p, b));
            func_021BC380((struct ResearchTop *)p);
            func_021BC43C((u8 *)p);
            func_021BC168((unsigned int)p);
            func_021BC014((u8 *)p);
            func_021BC274(p);
        }
        break;
    }
    case 1:
    {
        func_021BC30C((struct ResearchTop *)p, p->f34 + p->f4C);
        func_021BC380((struct ResearchTop *)p);
        func_021BC43C((u8 *)p);
        func_021BC168((unsigned int)p);
        func_021BC014((u8 *)p);
        func_021BC250(p);
        if (func_021BC264(p) == 0) {
            func_021BC06C((char *)p);
            func_021BB91C(p);
        }
        break;
    }
    }
    func_021BBA30((u8 *)p);
}

void func_021BB2B4(char *p)
{
    u32 keys = KEY_GetTrg();
    int st = TOUCHPANEL_HitTrg(p + 0x58);
    if ((keys & 0x40) || (keys & 0x80) || (keys & 0x20) || (keys & 0x10) || (keys & 1)) {
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 9);
        return;
    }
    if (st == 0) {
        func_021BBA00((u32)p, 0);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        func_021BB934((u8 *)p, 1);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 12);
        return;
    }
    if (func_021BC6D0(p) != 0 || (keys & 2) || st == 1) {
        func_021BBA00((u32)p, 1);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 11);
        func_021BB910((unsigned char *)p, 2);
    }
}

void func_021BB37C(char *p)
{
    u32 keys = KEY_GetTrg();
    int st = TOUCHPANEL_HitTrg(p + 0x58);
    if (keys & 0x40) {
        func_021BB9A0((u32)p);
    }
    if (keys & 0x80) {
        func_021BB9D0((u32)p);
    }
    if (keys & 1) {
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        switch (*(int *)&((struct ResearchTop *)p)->f2C) {
        case 0:
            func_021BB934((u8 *)p, 0);
            func_021BB91C(p);
            func_021BB910((unsigned char *)p, 12);
            break;
        case 1:
            GFL_USE_PlaySeDefaultVolume(0x551);
            func_021BB91C(p);
            func_021BB910((unsigned char *)p, 11);
            func_021BB910((unsigned char *)p, 2);
            break;
        }
        return;
    }
    if (st == 0) {
        func_021BBA00((u32)p, 0);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        func_021BB934((u8 *)p, 1);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 12);
        return;
    }
    if (func_021BC6D0(p) != 0 || (keys & 2) || st == 1) {
        func_021BBA00((u32)p, 1);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 11);
        func_021BB910((unsigned char *)p, 2);
    }
}

void func_021BB484(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBD28((int)p, 1);
        func_021BBD28((int)p, 0);
        func_021BC72C(p, 0, (u8 *)1);
        func_021BC72C(p, 1, (u8 *)1);
        func_021BC72C(p, 2, (u8 *)1);
        if (((struct ResearchTop *)p)->f15C == 0) {
            BgTextLabel_SetPalette((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 14);
            func_021BC4B4((char *)p);
        }
        func_021BBBE4(p);
        func_021BB990(p);
        break;
    case 1:
        func_021BC2D8((struct ResearchTop *)p);
        func_021BC338(p);
        func_021BC43C(p);
        func_021BC168((unsigned)p);
        func_021BC014(p);
        func_021BBF60(p);
        if (func_021BC2FC(p)) {
            func_021BB91C(p);
            func_021BB910(p, 8);
        }
        break;
    }
}

void func_021BB534(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBD14(p, 0);
        func_021BBD28((int)p, 1);
        func_021BBD18((int)p, 0);
        func_021BC580((char *)((unsigned)p), 3);
        func_021BC72C(p, 0, (u8 *)1);
        func_021BC72C(p, 1, (u8 *)1);
        func_021BC72C(p, 2, (u8 *)1);
        if (((struct ResearchTop *)p)->f15C == 0) {
            BgTextLabel_SetPalette((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 14);
            func_021BC4B4((char *)p);
        }
        func_021BBBE4(p);
        func_021BB990(p);
        break;
    case 1:
        func_021BC2D8((struct ResearchTop *)p);
        func_021BC338(p);
        func_021BC43C(p);
        func_021BC168((unsigned)p);
        func_021BC014(p);
        func_021BBF60(p);
        if (func_021BC2FC(p)) {
            func_021BB91C(p);
            func_021BB910(p, 10);
        }
        break;
    }
}

/*
 * arity: BB910 retains supplied r1=13 through its forwarding chain.
 */
void func_021BB5F4(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBE7C((unsigned int)p, func_021BBC50(p));
        func_021BBCB0(p);
        func_021BBDF0((unsigned int)p, func_021BC6E4(p));
        func_021BC014(p);
        func_021BC72C(p, 3, (u8 *)1);
        GFL_USE_PlaySeDefaultVolume(1898);
        func_021BB990(p);
        break;
    case 1:
        if (((struct ResearchTop *)p)->f24 >= 60) {
            func_021BC490();
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC4A0()) {
            func_021BC50C((char *)p);
            func_021BB990(p);
        }
        break;
    case 3:
        if (func_021BC55C((unsigned)p)) {
            func_021BB91C(p);
            func_021BB910(p, 13);
        }
        break;
    }
}

/*
 * extent: 021BB70E..021BB710 is two zero bytes of alignment padding.
 * arity: BB910 visibly receives r1=13; retain it through the forwarding chain despite its one-argument legacy file.
 */
void func_021BB69C(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        if (func_021BB948(p) < ((struct ResearchTop *)p)->f24) {
            func_021BC490();
            func_021BB990(p);
        }
        break;
    case 1:
        if (func_021BC4A0()) {
            func_021BC50C((char *)p);
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC55C((unsigned)p)) {
            BgTextLabel_SetPalette((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 15);
            func_021BB91C(p);
            func_021BB910(p, 13);
        }
        break;
    }
}

/*
 * extent: 021BB782..021BB784 is two zero bytes of alignment padding.
 * arity: BB910 visibly receives r1=13; retain it through the forwarding chain despite its one-argument legacy file.
 */
void func_021BB710(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        if (func_021BB948(p) < ((struct ResearchTop *)p)->f24) {
            func_021BC490();
            func_021BB990(p);
        }
        break;
    case 1:
        if (func_021BC4A0()) {
            func_021BC50C((char *)p);
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC55C((unsigned)p)) {
            BgTextLabel_SetPalette((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 15);
            func_021BB91C(p);
            func_021BB910(p, 13);
        }
        break;
    }
}

void func_021BB784(struct ResearchTop *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBB60((u8 *)p);
        func_021BB990(p);
        break;
    case 1:
        func_021BC2D8((struct ResearchTop *)p);
        func_021BC338((u8 *)p);
        func_021BC43C((u8 *)p);
        func_021BC168((unsigned int)p);
        func_021BC014((u8 *)p);
        func_021BBF60((u8 *)p);
        if (func_021BC2FC(p) != 0) {
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC5B8((u32)p, 5) != 0) {
            func_021BC72C((u8 *)p, 0, 0);
            func_021BC72C((u8 *)p, 1, 0);
            func_021BC72C((u8 *)p, 2, 0);
            func_021BBF60((u8 *)p);
            func_021BC50C((char *)p);
            func_021BB990(p);
        }
        break;
    case 3:
        if (func_021BC55C((u32)p) != 0) {
            BgTextLabel_SetPalette(p->fB4[p->f32], 15);
            func_021BB91C(p);
        }
        break;
    }
}

/*
 * volatile: DISPCNT read at 021BB8FA and write at 021BB900.
 * arity: C09E0/C09EC overwrite r1 before their indexed targets; BD3A4 overwrites r1=300; BCC58/BCB60 overwrite r1/r2 before 02040DA8. Omit only unused legacy trailing inputs, retain each visibly supplied context and BB910 r1=14.
 */
void func_021BB84C(u8 *p)
{
    func_021BC688((char *)p);
    func_021BD5E0((unsigned)p);
    func_021BD56C((int *)p);
    func_021BD520((int *)p);
    RESEARCH_COMMON_StopPaletteAnime(*(unsigned *)p);
    RESEARCH_COMMON_RestorePaletteAnime(*(unsigned *)p);
    func_021BD4CC((unsigned)p);
    func_021BD370((int *)p);
    func_021BD458((int *)p);
    func_021BD3A4(p);
    func_021BD05C((int *)p);
    func_021BCF98((int *)p);
    func_021BCE5C((unsigned)p);
    func_021BCF20((unsigned)p);
    func_021BCD90(p);
    func_021BCC58((unsigned)p);
    func_021BCBCC(p);
    func_021BCC3C(p);
    func_021BCB60((unsigned)p);
    func_021BCB44(p);
    func_021BCAC0(p);
    func_021BC924((int *)p);
    func_021BC8D8(p);
    func_021BB940(p, 0);
    func_021BB91C(p);
    func_021BB910(p, 14);
    ((struct ResearchTop *)p)->f164 = 1;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
}

void func_021BB908(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x24);
    *c += 1;
}

void func_021BB910(u8 *a0, u32 a1)
{
    RingQueue_Push((u32)(((struct ResearchTop *)a0)->f18), a1);
}

/*
 * Set the u32 at +0x158 to 1.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB91C(void *p)
{
    ((struct ResearchTop *)p)->f158 = 1;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_GetEntryHandled.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BB928(u8 *a0)
{
    return RESEARCH_COMMON_GetEntryHandled((void *)((u32)(((struct ResearchTop *)a0)->f0)));
}

void func_021BB934(u8 *a0, u32 a1)
{
    RESEARCH_COMMON_SetEntryHandled(*(u8 * *)&((struct ResearchTop *)a0)->f0, a1);
}

/*
 * Field setter, u32 at +0x168.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB940(void *p, u32 v)
{
    ((struct ResearchTop *)p)->f168 = v;
}

u32 func_021BB948(u8 *a0)
{
    return ((struct ResearchTop *)a0)->f28;
}

/*
 * Same guard shape as 021BA158 on the +0x158 word, handing the +0x18
 * handle to func_021BB978.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB94C(u32 a0)
{
    if (((struct ResearchTop *)a0)->f158 != 0) {
    if (RingQueue_IsEmpty(((struct ResearchTop *)a0)->f18) == 0) {
    func_021BB978((char *)a0, RingQueue_Pop((struct Ring *)(((struct ResearchTop *)a0)->f18)));
    }
    }
}

u32 func_021BB974(void *p)
{
    return ((struct ResearchTop *)p)->f1C;
}

int func_021BB978(char *p, int a1)
{
    int off = 0x56;
    ((struct ResearchTop *)p)->f1C = a1;
    ((struct ResearchTop *)p)->f24 = 0;
    *(int *)(p + (off << 2)) = 0;
    return (int)func_021BB998(p);
}

u32 func_021BB98C(void *p)
{
    return ((struct ResearchTop *)p)->f20;
}

void func_021BB990(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x20);
    *c += 1;
}

/*
 * Unlabelled Thumb leaf in a .word run:
 *   movs r1,#0; str r1,[r0,#0x20]; bx lr
 * Clears the word at p+0x20.
 */
void *func_021BB998(void *p)
{
    ((struct ResearchTop *)p)->f20 = 0;
    return p;
}

void func_021BB9A0(u32 a0)
{
    func_021BBD28(a0, ((struct ResearchTop *)a0)->f2C);
    func_021BBCFC((void *)a0, -1);
    func_021BBD18(a0, ((struct ResearchTop *)a0)->f2C);
    GFL_USE_PlaySeDefaultVolume(1352);
    func_021BC580((char *)a0, 4);
}

void func_021BB9D0(u32 a0)
{
    func_021BBD28(a0, ((struct ResearchTop *)a0)->f2C);
    func_021BBCFC((void *)a0, 1);
    func_021BBD18(a0, ((struct ResearchTop *)a0)->f2C);
    GFL_USE_PlaySeDefaultVolume(1352);
    func_021BC580((char *)a0, 4);
}

void func_021BBA00(u32 a0, u32 a1)
{
    func_021BBD28(a0, ((struct ResearchTop *)a0)->f2C);
    func_021BBD14((void *)a0, a1);
    func_021BBD18(a0, ((struct ResearchTop *)a0)->f2C);
    GFL_USE_PlaySeDefaultVolume(1352);
    func_021BC580((char *)a0, 4);
}

/*
 * arity: BC400 forwards entry r0 into BC3F8, so retain supplied argument despite legacy void. BC3EC overwrites r1 with 24 and tail-calls signed division; legacy trailing a1 neither read nor forwarded.
 */
void func_021BBA30(u8 *p)
{
    int low, high, left, right;
    u8 index;
    low = func_021BC3D4();
    high = func_021BC3E0();
    left = func_021BC3F8(p[0x32]);
    right = func_021BC400(p[0x32]);
    if (right <= low) {
        index = func_021BC3EC(right + 1);
        if (((struct ResearchTop *)p)->f160) func_021BBAA4((unsigned)p, index);
        else func_021BBD38(p, index);
    }
    if (high <= left) {
        index = func_021BC3EC(left - 1);
        if (((struct ResearchTop *)p)->f160) func_021BBAA4((unsigned)p, index);
        else func_021BBD38(p, index);
    }
}

void func_021BBAA4(u32 a0, u8 a1)
{
    func_021BBDAC((u8 *)a0);
    func_021BBD38((void *)a0, a1);
    func_021BBD68((u8 *)a0);
    GFL_USE_PlaySeDefaultVolume(1352);
    func_021BC580((char *)a0, 1);
}

/*
 * Reconstructed from the listing.
 *
 * evidence: func_021BC574 is ov217's own code ("ldr r0, [r0]; ldr r3,
 * =RESEARCH_COMMON_StartPaletteAnime; bx r3" after the pop at 0x021BC570), inside ov217's window,
 * so only ov217 can be resident there when this pool word is used.  Its start
 * is seeded in layout/function_starts.txt from this pointer word, the only
 * reference; it attests as sole-ref/code from ov217's own listing.  The old
 * hint ov209 named a different overlay's function mapped over the address.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBAD0(u32 a0)
{
    func_021BC574((u8 **)a0, 0);
}

void func_021BBADC(u8 *p)
{
    int start, end, low, high, step, low2, high2;
    start = ((struct ResearchTop *)p)->f34;
    if (p[0x32] < p[0x33]) end = func_021BC400(p[0x33]) + 1;
    else end = func_021BC3F8(p[0x33]);
    low = func_021BC3D4();
    high = func_021BC3E0();
    if (end < low || high < end) {
        if (start < end) start = high;
        else start = low;
    }
    step = ((start >= end ? start : end) - (start <= end ? start : end)) / 4;
    low2 = func_021BC3D4();
    high2 = func_021BC3E0();
    if (low2 <= start && start <= high2 && low2 <= end && end <= high2) step = 0;
    func_021BC2CC(p, start, end, step);
}

void func_021BBB60(u8 *p)
{
    int start, end, step, low, high, low2, high2;
    start = ((struct ResearchTop *)p)->f34;
    end = start;
    if ((int)func_021BC41C(p) < start) end = func_021BC40C(p) + 24;
    else if (start < 0) end = 144;
    low = func_021BC3D4();
    high = func_021BC3E0();
    if (end < low || high < end) {
        if (start < end) start = high;
        else start = low;
    }
    step = ((start >= end ? start : end) - (start <= end ? start : end)) / 3;
    low2 = func_021BC3D4();
    high2 = func_021BC3E0();
    if (low2 <= start && start <= high2 && low2 <= end && end <= high2) step = 1;
    func_021BC2CC(p, start, end, step);
}

void func_021BBBE4(u8 *p)
{
    int center, target, start, end;
    center = (int)(func_021BC3D4() + func_021BC3E0()) / 2;
    target = func_021BBF1C((unsigned)p, p[0x32]) * 8;
    if (center < target) {
        start = func_021BC3E0();
        end = (target - center) + func_021BC3E0();
    } else {
        start = func_021BC3D4();
        end = func_021BC3D4() - (center - target);
    }
    func_021BC2CC(p, start, end, ((start >= end ? start : end) - (start <= end ? start : end)) / 3);
}

u8 func_021BBC50(u8 *p)
{
    u8 values[3];
    int i;
    void *data;
    u8 a, b, c, index;
    data = func_0200E394(GAME_DATA_GetSaveControl((struct Big *)func_021BC628(p)));
    for (i = 0; i < 3; i++) values[i] = func_0200E44C((int)data, i);
    a = values[0];
    b = values[1];
    c = values[2];
    for (index = 0; index < 10; index++)
        if (a == d_021C30A8[index] && b == d_021C3080[index] && c == d_021C308A[index]) return index;
    return 0;
}

/*
 * blocker C: typedef unsigned char u8; void func_0200E440(u8 *p,int value,int index) { (p+index)[640]=value; }
 * arity: BC628 returns C09B4's +8 pointer; E394 returns 071CC's pointer, both used live despite legacy void declarations.
 */
void func_021BBCB0(u8 *p)
{
    u32 index;
    int data;
    index=func_021BC6E4(p);
    data=(int)func_0200E394((void *)((int)GAME_DATA_GetSaveControl((struct Big *)func_021BC628(p))));
    func_0200E440((u8 *)data,d_021C30A8[index],0);
    func_0200E440((u8 *)data,d_021C3080[index],1);
    func_0200E440((u8 *)data,d_021C308A[index],2);
}

/*
 * Advance the u32 at +0x2c by the argument plus two, reduced modulo two.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBCFC(void *p, s32 v)
{
    *(s32 *)&((struct ResearchTop *)p)->f2C = (*(s32 *)&((struct ResearchTop *)p)->f2C + v + 2) % 2;
}

/*
 * Field setter, u32 at +0x2c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBD14(void *p, u32 v)
{
    ((struct ResearchTop *)p)->f2C = v;
}

void func_021BBD18(int a, int b)
{
    BMP_OAM_SetPalette((u8 *)func_021BC740((char *)a, b), 0);
}

void func_021BBD28(int a, int b)
{
    BMP_OAM_SetPalette((u8 *)func_021BC740((char *)a, b), 1);
}

/*
 * Field setter, u8 at +0x32.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBD38(void *p, u8 v)
{
    ((struct ResearchTop *)p)->f32 = v;
}

void func_021BBD40(u8 *p, int a)
{
    int base = p[0x32];
    int x = (int)func_021BC6DC(p);
    int s = base + a;
    p[0x33] = (u8)((s + x) % (int)func_021BC6DC(p));
}

void func_021BBD68(u8 *p)
{
    u8 slot;
    u32 x;
    u32 y;
    slot=p[0x32];
    x=func_021BBF04((u32)p,slot);
    y=func_021BBF1C((u32)p,slot);
    func_020413B0(2,x,y,28,3,10);
    func_02041B6C(2);
    ((struct ResearchTop *)p)->f160=1;
}

void func_021BBDAC(u8 *p)
{
    u8 slot;
    u32 x;
    u32 y;
    slot=p[0x32];
    x=func_021BBF04((u32)p,slot);
    y=func_021BBF1C((u32)p,slot);
    func_020413B0(2,x,y,28,3,9);
    func_02041B6C(2);
    ((struct ResearchTop *)p)->f160=0;
}

void func_021BBDF0(u32 object,u32 slot)
{
    u16 *first;
    int row;
    u16 *second;
    int column;
    Index index;
    int base,destination;
    first=(u16 *)func_0204162C(2);
    second=(u16 *)func_0204162C(3);
    for(row=0;row<3;row++) {
        for(column=0;column<28;column++) {
            base=func_021BBF1C(object,slot);
            index=column+2+(base+row)*32;
            destination=index-1;
            first[destination]=first[index];
            second[destination]=second[index];
        }
    }
    base=func_021BBF1C(object,slot);
    first[base*32+29]=first[0];
    second[base*32+29]=second[0];
    first[(base+1)*32+29]=first[0];
    second[(base+1)*32+29]=second[0];
    first[(base+2)*32+29]=first[0];
    second[(base+2)*32+29]=second[0];
    func_02041B6C(2);
    func_02041B6C(3);
}

void func_021BBE7C(u32 object,u32 slot)
{
    u16 *first;
    int row;
    u16 *second;
    int column;
    Index index;
    int base,destination;
    first=(u16 *)func_0204162C(2);
    second=(u16 *)func_0204162C(3);
    for(row=2;row>=0;row--) {
        for(column=27;column>=0;column--) {
            base=func_021BBF1C(object,slot);
            index=column+1+(base+row)*32;
            destination=index+1;
            first[destination]=first[index];
            second[destination]=second[index];
        }
    }
    base=func_021BBF1C(object,slot);
    first[base*32+1]=first[0];
    second[base*32+1]=second[0];
    first[(base+1)*32+1]=first[0];
    second[(base+1)*32+1]=second[0];
    first[(base+2)*32+1]=first[0];
    second[(base+2)*32+1]=second[0];
    func_02041B6C(2);
    func_02041B6C(3);
}

/*
 * Returns 2, or 1 when func_021BBC50() reports the caller's own a1.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BBF04(u32 a0, u32 a1)
{
    u8 v = 2;
    if (a1 == func_021BBC50((u8 *)a0)) {
    v -= 1;
    }
    return v;
}

u32 func_021BBF1C(u32 unused, u32 v)
{
    return (u8)(v * 3);
}

int func_021BBF28(unsigned char *p, unsigned int slot)
{
    int t = func_021BBF04((unsigned int)p, slot) << 3;
    return t - func_02041648(2);
}

int func_021BBF3C(unsigned char *p, unsigned char index)
{
    int t = func_021BBF1C((unsigned int)p, index) << 3;
    return t - func_021BC3AC();
}

int func_021BBF4C(unsigned char *p, unsigned int index)
{
    int t = (func_021BBF1C((unsigned int)p, index) << 3) + 0x17;
    return t - func_021BC3AC();
}

static inline void outside(Plane wnd,Bool effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x0400004A & ~63u) | (u32)wnd;
    if(effect)tmp|=32;
    *(volatile u16 *)0x0400004A=(u16)tmp;
}

static inline void inside(Plane wnd,Bool effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x04000048 & ~63u) | (u32)wnd;
    if(effect)tmp|=32;
    *(volatile u16 *)0x04000048=(u16)tmp;
}

void func_021BBF60(u8 *p)
{
    int active;
    int top,bottom;
    int x1,x2,y1,y2;
    active=0;
    top=func_021BBF3C(p,0);
    bottom=func_021BBF4C(p,9);
    if(top>0) {
        active=1;x1=0;x2=240;y1=0;y2=top-1;
    } else if(bottom<192) {
        active=1;x1=0;x2=240;y1=bottom+1;y2=192;
    }
    if(active) {
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000 & 0xFFFF1FFF)|0x2000;
        *(volatile u16 *)0x04000040=(u16)(((x1<<8)&0xFF00)|(x2&0xFF));
        *(volatile u16 *)0x04000044=(u16)(((y1<<8)&0xFF00)|(y2&0xFF));
        outside(PLANE_OUT,TRUE);
        inside(PLANE_IN,TRUE);
    } else {
        *(volatile u32 *)0x04000000=*(volatile u32 *)0x04000000 & 0xFFFF1FFF;
    }
}

/*
 * arity: BF28/BF3C forward entry r0/r1 to BF04/BF1C; preserve both, with observed u8 argument truncation.
 */
void func_021BC014(u8 *p)
{
    struct Vec2 point;
    u32 index;
    struct Obj *obj;
    index=func_021BBC50(p);
    obj=(struct Obj *)func_021BC720(p,2);
    if(index==255) {
        CLACT_SetActorDrawEnable(obj,0);
        return;
    }
    point.x=func_021BBF28(p,(u8)index);
    point.y=func_021BBF3C(p,index)+10;
    CLACT_AddActorSurfacePos(obj,&point,0);
    CLACT_SetActorAutoAnim(obj,1);
    CLACT_SetActorDrawEnable(obj,1);
}

int func_021BC06C(char *p)
{
    return func_021BC07C((u8 *)p, ((struct ResearchTop *)p)->f32);
}

/*
 * arity: original visibly supplies r1 to C0F5C; preserve second argument omitted by legacy source.
 */
int func_021BC07C(u8 *p, u8 index)
{
    BgTextLabel_PrintMessage(((struct ResearchTop *)p)->fE4,d_021C309E[index]);
    BgTextLabel_PrintMessage(((struct ResearchTop *)p)->fE8,d_021C3094[index]);
    BgTextLabel_PrintMessage(((struct ResearchTop *)p)->fEC,d_021C30D0[d_021C30A8[index]]);
    BgTextLabel_PrintMessage(((struct ResearchTop *)p)->fF0,d_021C30D0[d_021C3080[index]]);
    return BgTextLabel_PrintMessage(((struct ResearchTop *)p)->fF4,d_021C30D0[d_021C308A[index]]);
}

void func_021BC0E8(u32 a0)
{
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->fE4), 0);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->fE8), 0);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->fEC), 0);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->fF0), 0);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->fF4), 0);
}

void func_021BC128(u32 a0)
{
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->fE4), 1);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->fE8), 1);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->fEC), 1);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->fF0), 1);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->fF4), 1);
}

/*
 * Packs a 0xF8 message (second halfword from func_021BC1AC()) and pushes
 * it through the +0x0c channel, on the path where func_021BC428() is clear.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC168(u32 a0)
{
    u8 s[4];
    u32 v1 = func_021BC720((void *)a0, 0);
    if (func_021BC428((void *)a0) == 0) {
    CLACT_SetActorDrawEnable((struct Obj *)v1, 0);
    return;
    }
    ((struct Obj00801 *)((u8*)s))->f0 = 248;
    *(u16 *)&((struct Obj00801 *)(((u8*)s)))->f2 = func_021BC1AC((void *)a0);
    CLACT_AddActorSurfacePos((struct Obj *)v1, (const struct Vec2 *)s, 0);
    CLACT_SetActorDrawEnable((struct Obj *)v1, 1);
}

/*
 * 021BC40C forwards live r0 to 021BC6DC's +0x30 getter despite legacy void prototype.
 */
int func_021BC1AC(void *p)
{
    int scroll;
    int height;
    float top;
    float span;
    int result;
    scroll=func_021BC3AC();
    height=func_021BC40C(p);
    scroll+=24;
    height+=24;
    top=(float)scroll;
    span=(float)height;
    result=(int)(32.0f+128.0f*(top/span));
    if(result<32)result=32;
    if(result>160)result=160;
    return result;
}

int func_021BC200(void *p,int position)
{
    float ratio;
    int height;
    float zero;
    Origin origin;
    if(position<32)position=32;
    if(position>160)position=160;
    ratio=(float)(position-32)/128.0f;
    height=func_021BC40C(p)+24;
    origin=ZERO;
    zero=(float)origin;
    return (int)(zero+ratio*(float)height);
}

/*
 * Accumulate +0x50 into +0x4c, zeroing the total when the product is not positive.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC250(void *p)
{
    s32 a = *(u32 *)&((struct ResearchTop *)p)->f4C;
    s32 b = ((struct ResearchTop *)p)->f50;
    s32 t = a + b;
    if (a * t <= 0) {
        t = 0;
    }
    *(u32 *)&((struct ResearchTop *)p)->f4C = t;
}

/*
 * Flag test: nonzero u32 at +0x4c as 1/0.
 *
 * Addresses are Black-image addresses.
 */
int func_021BC264(void *p)
{
    if (((struct ResearchTop *)p)->f4C != 0) {
        return 1;
    }
    return 0;
}

void func_021BC274(void *p)
{
    int a = *(u32 *)&((struct ResearchTop *)p)->f34;
    int b = ((struct ResearchTop *)p)->f38;
    *(u32 *)&((struct ResearchTop *)p)->f4C = a - b;
}

void func_021BC280(struct ResearchTop *p)
{
    double d = p->f4C;
    int v;
    d *= 1.5;
    v = d;
    p->f4C = v;
    if (v > 9) {
        p->f4C = 9;
    } else if (v < -9) {
        p->f4C = -9;
    }
}

void func_021BC2B8(void *p)
{
    if (((struct ResearchTop *)p)->f4C < 0) {
        ((struct ResearchTop *)p)->f50 = 1;
    } else {
        ((struct ResearchTop *)p)->f50 = -1;
    }
}

void func_021BC2CC(void *p, u32 a, u32 b, u32 c)
{
    ((struct ResearchTop *)p)->f3C = a;
    ((struct ResearchTop *)p)->f40 = b;
    *(u32 *)&((struct ResearchTop *)p)->f44 = c;
    *(u32 *)&((struct ResearchTop *)p)->f48 = 0;
}

void func_021BC2D8(struct ResearchTop *p)
{
    int base = p->f3C;
    int n = p->f48 + 1;
    p->f48 = n;
    func_021BC330(p, base + (p->f40s - base) * n / p->f44);
}

int func_021BC2FC(void *p)
{
    if (((struct ResearchTop *)p)->f44 > ((struct ResearchTop *)p)->f48) {
        return 0;
    }
    return 1;
}

void func_021BC30C(struct ResearchTop *p, int v)
{
    if (v < 0) {
        v = 0;
    }
    if ((int)func_021BC41C(p) < v) {
        v = (int)func_021BC41C(p);
    }
    p->f38 = p->f34;
    p->f34 = v;
}

void func_021BC330(void *p, u32 v)
{
    ((struct ResearchTop *)p)->f38 = v;
    ((struct ResearchTop *)p)->f34 = v;
}

void func_021BC338(u8 *p)
{
    int position;
    int low;
    int high;
    position=((struct ResearchTop *)p)->f34;
    low=func_021BC3D4();
    high=func_021BC3E0();
    if(position<low) {
        position-=24;
        func_02041EE4(2,3,position);
        func_02041EE4(3,3,position);
    } else if(high<position) {
        position-=168;
        func_02041EE4(2,3,position);
        func_02041EE4(3,3,position);
    }
}

void func_021BC380(struct ResearchTop *p)
{
    int v = p->f34 - 24;
    if (v < -24) {
        v = -24;
    }
    if (func_021BC40C(p) < v) {
        v = func_021BC40C(p);
    }
    func_021BC3B8(v);
}

int func_021BC3AC(void)
{
    return func_02040804(2);
}

void func_021BC3B8(u32 a0)
{
    func_02040618(2, 3, a0);
    func_02040618(3, 3, a0);
}

u32 func_021BC3D4(void)
{
    return func_021BC3AC() + 24;
}

u32 func_021BC3E0(void)
{
    return func_021BC3AC() + 168;
}

/*
 * Tail-call veneer: forwards arg(s) a0, 24 to func_0209C0A4.
 *
 * Addresses are Black-image addresses.
 */
int func_021BC3EC(u32 a0)
{
    return func_0209C0A4(a0, 24);
}

/*
 * Twenty-four times the argument.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC3F8(u32 v)
{
    return v * 24;
}

u32 func_021BC400(u32 v)
{
    return func_021BC3F8(v) + 23;
}

int func_021BC40C(void *p)
{
    return (int)func_021BC6DC(p) * 0x18 - 0xa8;
}

u32 func_021BC41C(void *p)
{
    return func_021BC40C(p) + 168;
}

int func_021BC428(void *p)
{
    return (int)func_021BC6DC(p) * 0x18 > 0x90;
}

void func_021BC43C(u8 *p)
{
    int i;
    int x;
    int y;
    for(i=0;i<=9;i++) {
        x=func_021BBF28(p,(u8)i);
        y=func_021BBF3C(p,i);
        p[i*4+0x66]=x;
        p[i*4+0x67]=x+0xd8;
        p[i*4+0x64]=y;
        p[i*4+0x65]=y+0x18;
    }
}

void func_021BC480(void)
{
    FADE_Start(3, 16, 0, 0);
}

void func_021BC490(void)
{
    FADE_Start(3, 0, 16, 0);
}

/*
 * Returns 1 when ARM FADE_IsActive() is 0.
 *
 * Addresses are Black-image addresses.
 */
int func_021BC4A0(void)
{
    return FADE_IsActive() == 0;
}

void func_021BC4B4(char *p)
{
    PALANM_RequestFade(*(PalAnmObj * *)&((struct ResearchTop *)p)->f98, 1, 0xBBFF, 2, 0, 10, 0, ((struct ResearchTop *)p)->f150);
    PALANM_RequestFade(*(PalAnmObj * *)&((struct ResearchTop *)p)->f98, 4, 0xCF, 2, 0, 10, 0, ((struct ResearchTop *)p)->f150);
    ((struct ResearchTop *)p)->f15C = 1;
}

void func_021BC50C(char *p)
{
    PALANM_RequestFade(*(PalAnmObj * *)&((struct ResearchTop *)p)->f98, 1, 0xBBFF, 2, 10, 0, 0, ((struct ResearchTop *)p)->f150);
    PALANM_RequestFade(*(PalAnmObj * *)&((struct ResearchTop *)p)->f98, 4, 0xCF, 2, 10, 0, 0, ((struct ResearchTop *)p)->f150);
    ((struct ResearchTop *)p)->f15C = 0;
}

u32 func_021BC55C(u32 a0)
{
    if (PALANM_GetFadeRequestBits((const char *)(((struct ResearchTop *)a0)->f98)) == 0) {
    return 1;
    }
    return 0;
}

void func_021BC574(u8 **p, u32 i)
{
    RESEARCH_COMMON_StartPaletteAnime(*p, i);
}

void func_021BC580(char *p, int i)
{
    PALETTE_ANIME_Start((u8 *)(*(int *)(p + 0x9c + i * 4)), d_021C326C[i].a, d_021C326C[i].b);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 156)), (a1)*4 to PALETTE_ANIME_Stop.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC5A8(u8 *a0, int a1)
{
    PALETTE_ANIME_Stop((u32)(*(u32*)(a0 + (a1)*4 + 156)));
}

/*
 * Reports whether the a1-th entry of the +0x9c handle array is still
 * active.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC5B8(u32 a0, u32 a1)
{
    if (PALETTE_ANIME_IsRunning(*(u32*)(((u8*)a0 + ((u32)a1 << 2) + 156))) == 0) {
    return 1;
    }
    return 0;
}

void func_021BC5D4(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        PALETTE_ANIME_Update(p[i + 0x27]);
}

void func_021BC5F0(u8 *a0)
{
    RESEARCH_COMMON_UpdatePaletteAnime((u32)(((struct ResearchTop *)a0)->f0));
}

u32 func_021BC5FC(void *p)
{
    return ((struct ResearchTop *)p)->f54;
}

/*
 * Increment the u32 at +0x54.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC600(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x54);
    *c += 1;
}

/*
 * Clear the u32 at +0x54.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC608(void *p)
{
    ((struct ResearchTop *)p)->f54 = 0;
}

void func_021BC610(u32 a0, u32 a1)
{
    func_020419E4();
    CLACT_VBlankSystem();
    PALANM_TransferPalettes((struct S02021D50 *)(((struct ResearchTop *)a1)->f98));
}

u32 func_021BC628(u8 *a0)
{
    return RESEARCH_COMMON_GetAppResource((void *)((u32)(((struct ResearchTop *)a0)->f0)));
}

/*
 * Field setter, u16 at +8.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC634(void *p, u32 v)
{
    ((struct ResearchTop *)p)->f8 = v;
}

/*
 * Field setter, u32 at +0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC638(void *p, u32 v)
{
    ((struct ResearchTop *)p)->f0 = v;
}

u32 func_021BC63C(void *p)
{
    return (u32)((struct ResearchTop *)p)->f0;
}

/*
 * Field setter, u32 at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC640(void *p, u32 v)
{
    ((struct ResearchTop *)p)->f4u = v;
}

void func_021BC644(struct ResearchTop *p)
{
    int v;
    if (p->f4 != 0) {
        v = ListViewState_GetScrollY(p->f4);
        if (v < -24) {
            v = -24;
        }
        if (v > 72) {
            v = 72;
        }
        func_021BC3B8(v);
        v = ListViewState_GetScrollX(p->f4);
        if (v < 0) {
            v = 0;
        }
        if (v > 240) {
            v = 240;
        }
        p->f34 = v;
        p->f32 = ListViewState_GetMode(p->f4);
    }
}

/*
 * Extent ends in two zero alignment bytes at 021BC6CE.
 * 021BC3AC is void in its source but forwards to 02040804. Original reads
 * r0 as a signed coordinate, so declare int and preserve its visible input.
 */
void func_021BC688(char *p)
{
    int y;
    if (*(u32 *)&((struct ResearchTop *)p)->f4 != 0) {
        y = func_021BC3AC();
        if (y < -24) y = -24;
        if (y > 72) y = 72;
        ListViewState_SetScrollY(((struct ResearchTop *)p)->f4, y);
        y = ((struct ResearchTop *)p)->f34;
        if (y < 0) y = 0;
        if (y > 240) y = 240;
        ListViewState_SetScrollX(((struct ResearchTop *)p)->f4, y);
        ListViewState_SetMode(((struct ResearchTop *)p)->f4, ((struct ResearchTop *)p)->f32);
    }
}

u32 func_021BC6D0(void *p)
{
    return RESEARCH_COMMON_GetInputFlag((void *)func_021BC63C(p));
}

u32 func_021BC6DC(void *p)
{
    return ((struct ResearchTop *)p)->f30;
}

/*
 * Field getter, u8 at +0x31.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC6E4(void *p)
{
    return ((struct ResearchTop *)p)->f31;
}

void func_021BC6EC(void *p, u8 v)
{
    ((struct ResearchTop *)p)->f31 = v;
}

u32 func_021BC6F4(u32 a0, u32 a1)
{
    if (a1 < func_021BC6DC((void *)a0)) {
    return 1;
    }
    return 0;
}

/*
 * Indexed u32 read: element i of the table at +0xf8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC708(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0xf8);
}

/*
 * Indexed u32 read: element i of the table at +0x114.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC714(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x114);
}

u32 func_021BC720(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x120);
}

void func_021BC72C(u8 *a0, u32 a1, u8 *a2)
{
    BMP_OAM_SetEnabled((u8 *)((u32)(*(u32*)(a0 + (a1)*4 + 304))), (u32)(a2 + 0));
}

int func_021BC740(char *p, int i)
{
    return *(int *)(p + (d_021C3068[i] << 2) + 0x130);
}

u32 func_021BC758(u32 a0)
{
    return (u32)func_02030734(a0, 364, 0, (const char *)0x21C3FFC, 3687);
}

/*
 * Extent ends in two zero alignment bytes at 021BC816.
 */
void func_021BC774(u8 *p)
{
    ((struct ResearchTop *)p)->f4u = 0;
    ((struct ResearchTop *)p)->f1C = 0;
    ((struct ResearchTop *)p)->f24 = 0;
    ((struct ResearchTop *)p)->f158 = 0;
    ((struct ResearchTop *)p)->f28 = 15;
    p[0x32] = 0;
    p[0x33] = 0;
    p[0x30] = 0;
    ((struct ResearchTop *)p)->f2C = 0;
    p[0x31] = 255;
    ((struct ResearchTop *)p)->f150u = func_020056BC();
    ((struct ResearchTop *)p)->f34 = 0;
    ((struct ResearchTop *)p)->f38 = 0;
    ((struct ResearchTop *)p)->f3C = 0;
    ((struct ResearchTop *)p)->f40 = 0;
    ((struct ResearchTop *)p)->f44 = 0;
    ((struct ResearchTop *)p)->f48 = 0;
    ((struct ResearchTop *)p)->f15C = 0;
    ((struct ResearchTop *)p)->f160 = 0;
    ((struct ResearchTop *)p)->f168 = 0;
    ((struct ResearchTop *)p)->f164 = 0;
    ((struct ResearchTop *)p)->f154 = 0;
    func_021BC94C(p);
    func_021BC910(p);
    func_021BC8D0(p);
    func_021BCD6C(p);
    func_021BCF4C(p);
    func_021BCFB4(p);
    func_021BCDDC(p);
    func_021BD474(p);
    func_021BD078(p);
    func_021BD50C(p);
}

/*
 * Tail-call veneer: branch to func_020307B0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC818(void *a0)
{
    return func_020307B0(a0);
}

void func_021BC820(u8 *p)
{
    void *bitmap;
    int n;
    bitmap = (void *)func_0201296C((const struct BigObj *)func_021BC628(p));
    n = 1;
    if (ZONEDATA_CheckEventFlag(bitmap, 240) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 241) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 242) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 243) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 244) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 245) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 246) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 247) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 248) == 1) n++;
    p[0x30] = n;
}

void func_021BC8B4(u32 a0)
{
    u8 s[4];
    *(u32 *)&((struct ResearchTop *)a0)->fCp = (u32)GF_FONT_Create(23, 0, 0, 0, (u32)(((struct ResearchTop *)a0)->f8));
}

/*
 * Clear the u32 at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC8D0(void *p)
{
    ((struct ResearchTop *)p)->fC = 0;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 12)) to GF_FONT_Delete.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC8D8(u8 *a0)
{
    GF_FONT_Delete((void *)((u32)(((struct ResearchTop *)a0)->fC)));
}

void func_021BC8E4(struct ResearchTop *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        p->arr[i] = (int)func_02045B38(0, 2, (u16)d_021C3078[i], p->f8);
    }
}

void func_021BC910(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0x10) = 0;
}

void func_021BC924(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        MSGDATA_Delete((struct Rec *)p[i + 4]);
}

void func_021BC93C(u32 a0)
{
    ((struct ResearchTop *)a0)->f18 = RingQueue_Create(10, ((struct ResearchTop *)a0)->f8);
}

/*
 * Clear the u32 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC94C(void *p)
{
    ((struct ResearchTop *)p)->f18 = 0;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 24)) to RingQueue_Destroy.
 *
 * Addresses are Black-image addresses.
 */
void func_021BC954(u8 *a0)
{
    RingQueue_Destroy((void *)((u32)(((struct Obj25879 *)a0)->f18)));
}

/*
 * Pool +94 names 021C3190; no cross-overlay loading proof. Drop contested
 * ov217 token to use the sole-ref/data witness without swapping tables.
 */
void func_021BC960(u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p[i * 4 + 0x5A] = d_021C30B2[i * 4];
        p[i * 4 + 0x5B] = d_021C30B2[i * 4 + 1];
        p[i * 4 + 0x58] = d_021C30B2[i * 4 + 2];
        p[i * 4 + 0x59] = d_021C30B2[i * 4 + 3];
    }
    for (i = 0; i < 11; i++) {
        p[i * 4 + 0x66] = d_021C3190[i * 4];
        p[i * 4 + 0x67] = d_021C3190[i * 4 + 1];
        p[i * 4 + 0x64] = d_021C3190[i * 4 + 2];
        p[i * 4 + 0x65] = d_021C3190[i * 4 + 3];
    }
    for (i = 0; i < 2; i++) {
        p[i * 4 + 0x92] = d_021C3070[i * 4];
        p[i * 4 + 0x93] = d_021C3070[i * 4 + 1];
        p[i * 4 + 0x90] = d_021C3070[i * 4 + 2];
        p[i * 4 + 0x91] = d_021C3070[i * 4 + 3];
    }
}

void func_021BC9FC(char *p)
{
    func_0203FC28(&d_021C30C0);
    func_0203FCA0(6, &d_021C3110, 0);
    func_0203FCA0(7, &d_021C3130, 0);
    func_0203FCA0(0, &d_021C30F0, 0);
    func_0203FCA0(2, &d_021C3150, 0);
    func_0203FCA0(3, &d_021C3170, 0);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    func_02040588(7, 1);
    func_02040588(1, 1);
    func_02040588(0, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_0207D63C((volatile unsigned *)0x04001050, 2, 1, 16, 5);
    func_0207D63C((volatile unsigned *)0x04000050, 4, 2, 16, 5);
    BMP_WIN_Init(((struct ResearchTop *)p)->f8);
}

u32 func_021BCAC0(u8 *a0)
{
    BMP_WIN_Exit();
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(0);
    func_020403F4(7);
    return func_020403F4(6);
}

/*
 * Original narrows the heap before 020490F4; its extern takes u16.
 */
void func_021BCAE8(char *p)
{
    void *arc;
    void *buf;
    void *screen;
    arc = func_020490F4(192, (u16)((((struct ResearchTop *)p)->f8 & 0x7FFF) | 0x8000));
    buf = ARC_TOOL_LoadHandleMember(arc, 13, ((struct ResearchTop *)p)->f8);
    func_02062B30(buf, &screen);
    func_02041090(6, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_02041B6C(6);
    func_020307B0(buf);
    ARC_TOOL_DeleteHandle(arc);
}

void func_021BCB44(u8 *a0)
{
}

u32 func_021BCB48(u32 a0)
{
    func_02040C14(7, 0, 1, 0);
    return func_020414EC(7);
}

void func_021BCB60(u32 a0)
{
    func_02040DA8(7, 1, 0);
}

void func_021BCB70(char *p)
{
    void *arc;
    void *buf;
    void *screen;
    arc = func_020490F4(192, (u16)((((struct ResearchTop *)p)->f8 & 0x7FFF) | 0x8000));
    buf = ARC_TOOL_LoadHandleMember(arc, 3, ((struct ResearchTop *)p)->f8);
    func_02062B30(buf, &screen);
    func_02041090(0, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_02041B6C(0);
    func_020307B0(buf);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * Empty stub.
 *
 * Addresses are Black-image addresses.
 */
void func_021BCBCC(u8 *a0)
{
}

void func_021BCBD0(struct ResearchTop *p)
{
    void *heap = func_020490F4(0xc0, (u16)((p->f8 & 0x7fff) | 0x8000));
    int v = func_021BC6DC(p) * 3;
    void *res = ARC_TOOL_LoadHandleMember(heap, 5, p->f8);
    char *q;
    func_02062B30(res, (void **)(&q));
    func_02041090(2, (u32)(q + 0xc), 0, 0, 0x20, (u8)v);
    func_02041B6C(2);
    func_020307B0(res);
    ARC_TOOL_DeleteHandle(heap);
}

void func_021BCC3C(u8 *a0)
{
}

u32 func_021BCC40(u32 a0)
{
    func_02040C14(3, 0, 1, 0);
    return func_020414EC(3);
}

void func_021BCC58(u32 a0)
{
    func_02040DA8(3, 1, 0);
}

void func_021BCC68(struct ResearchTop *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        const struct Ent_021BCAE8 *e = &d_021C33C8[i];
        struct Loc l1;
        l1.b0 = e->b0;
        l1.b1 = e->b1;
        l1.b2 = e->b2;
        l1.b3 = e->b3;
        l1.b4 = e->b4;
        l1.b5 = e->b5;
        l1.b6 = e->b6;
        l1.b7 = e->b7;
        l1.b8 = e->b8;
        l1.b9 = e->b9;
        l1.b10 = e->b10;
        l1.w = e->w;
        p->arr[0xdc / 4 - 4 + i] = (u32)BgTextLabel_Create((const struct Config *)(&l1), (u32)p->fC, p->arr[e->idx], p->f8);
        BgTextLabel_PrintMessage(p->arr[0xdc / 4 - 4 + i], e->arg);
    }
    for (i = 0; i < (int)func_021BC6DC(p); i++) {
        const struct Ent_021BCAE8 *e = &d_021C3520[i];
        struct Loc l2;
        l2.b0 = e->b0;
        l2.b1 = e->b1;
        l2.b2 = e->b2;
        l2.b3 = e->b3;
        l2.b4 = e->b4;
        l2.b5 = e->b5;
        l2.b6 = e->b6;
        l2.b7 = e->b7;
        l2.b8 = e->b8;
        l2.b9 = e->b9;
        l2.b10 = e->b10;
        l2.w = e->w;
        p->arr[0xb4 / 4 - 4 + i] = (u32)BgTextLabel_Create((const struct Config *)(&l2), (u32)p->fC, p->arr[e->idx], p->f8);
        BgTextLabel_PrintMessage(p->arr[0xb4 / 4 - 4 + i], e->arg);
    }
}

/*
 * Clear seven u32 slots at +0xdc, then ten at +0xb4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BCD6C(void *p)
{
    int i;
    for (i = 0; i < 7; i++)
        *(u32 *)((char *)p + i * 4 + 0xdc) = 0;
    for (i = 0; i < 10; i++)
        *(u32 *)((char *)p + i * 4 + 0xb4) = 0;
}

void func_021BCD90(u8 *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        BgTextLabel_Destroy(*(u8 **)(p + i * 4 + 0xDC));
        *(u32 *)(p + i * 4 + 0xDC) = 0;
    }
    for (i = 0; i < (int)func_021BC6DC(p); i++) {
        BgTextLabel_Destroy(*(u8 **)(p + i * 4 + 0xB4));
        *(u32 *)(p + i * 4 + 0xB4) = 0;
    }
}

void func_021BCDDC(void *p)
{
    int i;
    for (i = 0; i < 7; i++)
        *(u32 *)((char *)p + i * 4 + 0xf8) = 0;
}

/*
 * 0204ABF0 is void in its source but forwards to the int-returning
 * 0204AC18; the original stores its live r0 result. 020490F4 narrows heap.
 */
void func_021BCDF0(char *p)
{
    u16 heap;
    void *arc;
    int a, b, c;
    heap = ((struct ResearchTop *)p)->f8;
    arc = func_020490F4(192, (u16)((heap & 0x7FFF) | 0x8000));
    a = CLACT_RegisterCharacter((void *)((u32)arc), 15, 0, 1, heap);
    b = CLACT_RegisterPalette((void *)arc, 16, 1, 0, heap);
    c = CLACT_RegisterCellAnim((void *)((u32)arc), 14, 17, heap);
    ((struct ResearchTop *)p)->f108 = a;
    ((struct ResearchTop *)p)->f10C = b;
    ((struct ResearchTop *)p)->f110 = c;
    ARC_TOOL_DeleteHandle(arc);
}

u32 func_021BCE5C(u32 a0)
{
    CLACT_ReleaseCharacter(((struct ResearchTop *)a0)->f108);
    CLACT_ReleasePalette(((struct ResearchTop *)a0)->f10C);
    return CLACT_ReleaseCellAnim(((struct ResearchTop *)a0)->f110);
}

void func_021BCE7C(char *p)
{
    u16 heap;
    void *arc;
    int a, b, c, d;
    heap = ((struct ResearchTop *)p)->f8;
    arc = func_020490F4(192, (u16)((heap & 0x7FFF) | 0x8000));
    a = CLACT_RegisterCharacter((void *)((u32)arc), 15, 0, 0, heap);
    b = CLACT_RegisterPaletteEx((void *)((u32)arc), 16, 0, 192, 0, 4, heap);
    c = CLACT_RegisterCellAnim((void *)((u32)arc), 14, 17, heap);
    ARC_TOOL_DeleteHandle(arc);
    arc = func_020490F4(83, (u16)heap);
    d = CLACT_RegisterPaletteEx((void *)((u32)arc), 31, 0, 128, 0, 2, heap);
    ARC_TOOL_DeleteHandle(arc);
    ((struct ResearchTop *)p)->fF8 = a;
    ((struct ResearchTop *)p)->fFC = b;
    ((struct ResearchTop *)p)->f100 = c;
    ((struct ResearchTop *)p)->f104 = d;
}

u32 func_021BCF20(u32 a0)
{
    CLACT_ReleaseCharacter(((struct ResearchTop *)a0)->fF8);
    CLACT_ReleasePalette(((struct ResearchTop *)a0)->fFC);
    CLACT_ReleaseCellAnim(((struct ResearchTop *)a0)->f100);
    return CLACT_ReleasePalette(((struct ResearchTop *)a0)->f104);
}

void func_021BCF4C(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x114) = 0;
}

void func_021BCF68(struct ResearchTop *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p->f114[i] = (int)CLACT_CreateUnit(d_021C3060[i], d_021C305C[i], p->f8);
    }
}

void func_021BCF98(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        CLACT_DeleteUnit((struct Bank *)p[i + 0x45]);
}

void func_021BCFB4(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x120) = 0;
}

/*
 * Lever: const source table and destination base without the field offset.
 */
void func_021BCFD0(u8 *p)
{
    struct Arg arg;
    const struct Entry_021BBF04 *q;
    u8 *dest;
    int i;
    u32 a,b,c,d;
    for (i=0;i<3;i++) {
        q=&d_021C320C[i];
        arg.x=q->x; arg.y=q->y; arg.z=q->z; arg.a=q->a; arg.b=q->b;
        a=func_021BC714(p,q->c);
        b=func_021BC708(p,q->d);
        c=func_021BC708(p,q->e);
        d=func_021BC708(p,q->f);
        dest=p+i*4;
        ((struct Obj14733 *)dest)->f120=(u32)CLACT_CreateActor((void *)a,b,c,d,&arg,q->g,((struct ResearchTop *)p)->f8);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj14733 *)dest)->f120,0);
    }
}

void func_021BD05C(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        CLACT_DeleteActor((struct Obj *)p[i + 0x48]);
}

void func_021BD078(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x140) = 0;
}

void func_021BD094(struct ResearchTop *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        p->f140[i] = (void *)BMP_Create(d_021C3470[i].x, d_021C3470[i].y, d_021C3470[i].z, p->f8);
    }
}

void func_021BD0C4(u8 *p)
{
    const struct Entry_021C3470 *q;
    struct Bmp *bmp;
    void *text;
    u16 color;
    u8 *dest;
    int i;
    for(i=0;i<4;i++) {
        q=&d_021C3470[i];
        if(q->enabled) {
            bmp=BMP_CreateFromArchive(q->arc,q->member,0,((struct ResearchTop *)p)->f8);
            dest=p+i*4;
            BMP_Blit(bmp,*(struct Bmp * *)&((struct Obj14734 *)dest)->f140,0,0,0,0,q->x<<3,q->y<<3,q->b);
            color=((q->r&31)<<10)|((q->g&31)<<5)|(q->b&31);
            text=func_02045EC0(*(struct MsgBank **)(p+16+q->bank*4),q->index);
            PRINTSYS_PrintColor(((struct Obj14734 *)dest)->f140,q->px,q->py,text,((struct ResearchTop *)p)->fCp,color);
            func_020307B0(text);
            BMP_Delete((struct Obj020437AC *)((int)bmp));
        }
    }
}

/*
 * Base address held in a u32 local and cast per use (reloads the pool word at each site); colour expression a | (c | b).
 */
void func_021BD178(struct ResearchTop *p)
{
    u32 gb = (u32)&d_021C349C;
    struct Tab tab = d_021C3350;
    int i;
    int j;
    void *heap;
    void *res;
    u16 color;
    heap = BMP_CreateFromArchive(GB->f20, GB->f24, 0, p->f8);
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 10; j++) {
            BMP_Blit(heap, p->f140[1], (tab.v[i][j] % 3) * 8, (tab.v[i][j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    BMP_Delete(heap);
    color = (GB->f1e & 0x1f) | (((GB->f1c & 0x1f) << 10) | ((GB->f1d & 0x1f) << 5));
    res = func_02045EC0((void *)p->arr[GB->f0c], GB->f10);
    PRINTSYS_PrintColor(p->f140[1], (s16_021BD178)GB->f14, (s16_021BD178)GB->f18, res, (void *)p->fC, color);
    func_020307B0(res);
}

/*
 * Same lever as 021BD178: u32 base local cast per use, colour a | (c | b).
 */
void func_021BD274(struct ResearchTop *p)
{
    u32 gb = (u32)&d_021C34C8;
    struct Tab tab = d_021C32D8;
    int i;
    int j;
    void *heap;
    void *res;
    u16 color;
    heap = BMP_CreateFromArchive(GB->f20, GB->f24, 0, p->f8);
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 10; j++) {
            BMP_Blit(heap, p->f140[2], (tab.v[i][j] % 3) * 8, (tab.v[i][j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    BMP_Delete(heap);
    color = (GB->f1e & 0x1f) | (((GB->f1c & 0x1f) << 10) | ((GB->f1d & 0x1f) << 5));
    res = func_02045EC0((void *)p->arr[GB->f0c], GB->f10);
    PRINTSYS_PrintColor(p->f140[2], (s16)GB->f14, (s16)GB->f18, res, (void *)p->fC, color);
    func_020307B0(res);
}

void func_021BD370(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        BMP_Delete((struct Obj020437AC *)p[i + 0x50]);
}

void func_021BD38C(char *p)
{
    int i = 0x47;
    *(void **)(p + (i << 2) + 0x10) =
        BMP_OAM_CreateSys(((struct ResearchTop *)p)->f8, *(void **)(p + (i << 2)));
}

void func_021BD3A4(u8 *a0)
{
    BMP_OAM_DeleteSys((void *)((u32)(((struct ResearchTop *)a0)->f12C)));
}

void func_021BD3B4(u8 *p)
{
    int sysOff,outOff,callOff,uploadOff;
    struct Param param;
    int i;
    const struct Entry_021BD0C4 *q;
    u8 *dest;
    sysOff=0x12C;
    outOff=0x130;
    callOff=0x130;
    uploadOff=0x130;
    for(i=0;i<4;i++) {
        dest=p+i*4;
        param.bmp=((struct Obj25887 *)dest)->f140;
        q=&d_021C31BC[i];
        param.x=q->x; param.y=q->y;
        param.f8=func_021BC708(p,q->f8);
        param.fc=q->fc;
        param.f10=q->f10; param.f11=q->f11;
        param.f12=q->f12; param.f14=q->f14;
        *(struct Grid **)(dest+outOff)=BMP_OAM_Create(*(struct Sys **)(p+sysOff),&param);
        BMP_OAM_SetEnabled(*(u8 **)(dest+callOff),0);
        BMP_OAM_UploadChars(*(struct Obj **)(dest+uploadOff));
    }
}

void func_021BD458(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        BMP_OAM_Delete((struct Grid *)p[i + 0x4C]);
}

void func_021BD474(void *p)
{
    ((struct ResearchTop *)p)->f98 = 0;
}

void func_021BD47C(u8 *p)
{
    *(struct PalAnmSlot * *)&((struct ResearchTop *)p)->f98 = PALANM_Create(((struct ResearchTop *)p)->f8);
    PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct ResearchTop *)p)->f98, 0, 512, ((struct ResearchTop *)p)->f8);
    PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct ResearchTop *)p)->f98, 2, 512, ((struct ResearchTop *)p)->f8);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct ResearchTop *)p)->f98, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct ResearchTop *)p)->f98, 2, 0, 512);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +001E THM_CALL PALANM_Delete       -> unresolved: 02021540 (arm, from name) has no witness outside 021BD4CC..021BD4F0
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BD4CC(u32 a0)
{
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(((struct ResearchTop *)a0)->f98), 0);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(((struct ResearchTop *)a0)->f98), 2);
    return PALANM_Delete((void *)(((struct ResearchTop *)a0)->f98));
}

void func_021BD4F0(char *p)
{
    int i;
    for (i = 0; i < 6; i++)
        ((int *)(p + 0x9c))[i] = PALETTE_ANIME_Create(((struct ResearchTop *)p)->f8);
}

/*
 * Clear six u32 slots at +0x9c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD50C(void *p)
{
    int i;
    for (i = 0; i < 6; i++)
        *(u32 *)((char *)p + i * 4 + 0x9c) = 0;
}

void func_021BD520(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        PALETTE_ANIME_Destroy((void *)p[i + 0x27]);
}

void func_021BD53C(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        PALETTE_ANIME_Bind((void *)p[i + 0x27], d_021C3260[i].a, d_021C3260[i].b, d_021C3260[i].c);
}

void func_021BD56C(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        PALETTE_ANIME_Restore((char *)p[i + 0x27]);
}

void func_021BD588(void *p)
{
    int obj = func_021BC720(p, 1);
    Pos pos;
    pos.x = 0x80;
    pos.y = 0x60;
    CLACT_AddActorSurfacePos((struct Obj *)obj, (const struct Vec2 *)(&pos), 0);
    CLACT_SetActorDrawEnable((struct Obj *)obj, 1);
}

void func_021BD5B4(u32 a0)
{
    GFL_NET_RestartWithDefaultTimeout(1, ((struct ResearchTop *)a0)->f8);
}

void func_021BD5C4(char *p)
{
    ((struct ResearchTop *)p)->f154 = func_020056A0((void (*)(void))func_021BC610, p, 0);
}

void func_021BD5E0(u32 a0)
{
    func_02030EAC((struct Node *)(((struct ResearchTop *)a0)->f154));
    ((struct ResearchTop *)a0)->f154 = 0;
}
