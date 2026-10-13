/*
 * file:     btl_rec_sel.c
 * unit:     yes
 * function: func_021B95A0, func_021B9798, func_021B9834, func_021B9EB8, func_021B9ED4, func_021B9EF0, func_021B9EFC, func_021B9F10, func_021B9F18, func_021B9F24, func_021BA018, func_021BA058, func_021BA074, func_021BA0B0, func_021BA0DC, func_021BA108, func_021BA16C, func_021BA190, func_021BA254, func_021BA2B8, func_021BA2F4, func_021BA39C, func_021BA3A0, func_021BA3C4, func_021BA43C, func_021BA45C, func_021BA4E8, func_021BA5C8, func_021BA650, func_021BA6A0, func_021BA6F0, func_021BA794, func_021BA8DC, func_021BAAB0, func_021BAB0C, func_021BABA4, func_021BABF4, func_021BAC3C, func_021BAC58, func_021BAC90, func_021BACCC, func_021BAD08, func_021BAD14, func_021BAE10, func_021BAE4C, func_021BAE88, func_021BAE9C, func_021BAF30, func_021BAF64, func_021BB0D4
 * address:  0x021B95A0
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02040588 0x02040588 arm
 *   func_021BB178 0x021BB178 thumb ov214
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_0201292C 0x0201292C thumb
 *   func_02007F68 0x02007F68 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0204047C 0x0204047C arm
 *   func_02040EBC 0x02040EBC arm
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   ov67_id 0x00000043 data a1
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_021BB220 0x021BB220 thumb ov214
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   KEY_GetTrg 0x020362DC arm
 *   FADE_IsActive 0x0204E804 arm
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   func_020355D8 0x020355D8 arm
 *   BATTLE_REC_CheckSaved 0x0200B5CC thumb
 *   BATTLE_REC_LoadAlloc 0x0200B5A4 thumb
 *   BATTLE_REC_GetHeaderOf 0x0200B934 thumb
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   BATTLE_REC_Delete 0x0200B438 thumb
 *   func_020056BC 0x020056BC thumb
 *   TIME_ICON_Create 0x0202EE30 thumb
 *   func_0200B6E0 0x0200B6E0 thumb
 *   BATTLE_REC_DecodeWork 0x0200B490 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021BB27C 0x021BB27C thumb ov214
 *   func_021BB290 0x021BB290 thumb ov214
 *   func_021BB29C 0x021BB29C thumb ov214
 *   func_02030734 0x02030734 arm
 *   func_02040E78 0x02040E78 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02041B6C 0x02041B6C arm
 *   d_021BB658 0x021BB658 data a1
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
 *   func_0203FB44 0x0203FB44 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Main 0x020310C4 arm
 *   func_02035630 0x02035630 arm
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   func_0203FA08 0x0203FA08 arm
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   d_021BB480 0x021BB480 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_021BB2A8 0x021BB2A8 thumb ov214
 *   func_0201BC3C 0x0201BC3C thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 *   d_021BB4C4 0x021BB4C4 data a1
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0204989C 0x0204989C arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_02040618 0x02040618 arm
 *   func_02041570 0x02041570 arm
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0207D518 0x0207D518 arm
 *   BG_SYS_ClearSubBgPlanes 0x02043558 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021BB498 0x021BB498 data a4
 *   d_021BB640 0x021BB640 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   func_02030D28 0x02030D28 arm
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   rects 0x021BB568 data a4
 */
#include "../../matched/include/Obj00182.h"
#include "../../matched/include/Obj06705.h"
#include "../../matched/include/Obj00636.h"
#include "../../matched/include/Obj05548.h"
#include "../../matched/include/Obj25721.h"
#include "../../matched/include/Obj10934.h"
#include "../../matched/include/Obj14698.h"
#include "../../matched/include/Obj14699.h"
#include "../../matched/include/Obj10935.h"
#include "../../matched/include/Obj25724.h"
#include "../../matched/include/Obj14700.h"
#include "../../matched/include/Obj01782.h"
#include "../../matched/include/Obj04632.h"
#include "../../matched/include/Obj01082.h"
#include "../../matched/include/Obj04633.h"
#include "../../matched/include/Obj10937.h"
#include "../../matched/include/Obj00202.h"
#include "../../matched/include/Obj01588.h"
#include "../../matched/include/Obj02552.h"
#include "../../matched/include/Obj25726.h"
#include "../../matched/include/Obj08422.h"
#include "../../matched/include/Obj25728.h"
#include "../../matched/include/Obj14701.h"
#include "../../matched/include/Obj14702.h"
#include "../../matched/include/Obj25729.h"

#define REG3D (*(volatile u16 *)0x04000060)
struct Obj0203159C;
struct C;
struct BigObj;
struct GfFont;
struct MsgBank;
struct Rec;
struct Node;
struct PrintSys;
struct S020315D4;
struct BattleRec;
struct Big;
struct Entry;
struct Link;
struct ObjC4;
struct BtlRecSel;
struct CharBuf;
struct Descriptor;
struct Tcbl;
struct Rec3;
struct S02031140;
struct U16Vec;
struct Cfg;
struct WinDat;
struct BmpMenu;
struct WordSet;
struct Obj;
struct BgTemplate;
struct Sub0200852CObj;
struct Ctx;
struct Obj02021EE4;
struct PalAnmSlot;
struct PalAnmObj;
struct S02021D50;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct C {u16 heap; u8 pad[0x66]; void *task,*win1,*win0,*font; u32 f78;};

struct Palette {u16 a,b,c;};

typedef struct {u8 a,b,c,d,e,f;} Rec;

typedef struct {Rec r[4];} Table;

typedef struct {int a,b,c;} Obj;

struct Cell { u32 a,b,c,d,out0,out1,out2,out3,actor; u8 x,y,flag,order; };

struct BtlRecSel {
    u16 heap, pad2;
    u8 *owner;
    u32 f08;
    u8 pad0C[0x14 - 0x0C];
    struct PrintSys *printA, *printB;
    u8 pad1C[0x58 - 0x1C];
    struct MsgBank *msgBank;
    u8 pad5C[0x8C - 0x5C];
    struct Descriptor *descriptors[2];
    struct Descriptor *other1, *other2;
    u32 flags[2];
    int clearA, clearB;
    u8 padAC[0xBC - 0xAC];
    int lastMode;
    u16 lastValue, padC2;
    struct Cell cells[2][6];
    u32 spare, mode;
    u8 pad2AC[0x2D8 - 0x2AC];
    void *heapHandle;
    u32 unused2DC;
    char *anm;
    u32 request, state;
};

typedef struct {int f0;u32 f4;int f8,fC,f10,f14,f18;u8 b1c,b1d,b1e;} In;

typedef struct {u8 a,b;} Pair;

struct Rect {u16 h[4];};

typedef enum { GX_SHADING_TOON, GX_SHADING_HIGHLIGHT } GXShading;

extern int func_02034AC4(int);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void*,u32,u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040EBC(u32,u32);
extern void FADE_Start(u32,int,int,int);
extern char *func_021BB178(u32,u32);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void*);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02007F68(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_020056A0(void(*)(void*),void*,u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void func_02030EAC(struct Node *n);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_021BB220(char *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int handle);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 KEY_GetTrg(void);
extern int FADE_IsActive(void);
extern u32 BMP_MENU_ProcessYesNo(u8*);
extern void BMP_MENU_DeleteYesNo(u8 *o);
extern void func_020355D8(u8);
extern u32 BATTLE_REC_CheckSaved(void*,u32,u32*,u32);
extern struct BattleRec *BATTLE_REC_LoadAlloc(void *a, u32 heap, u32 *dp, u32 id);
extern u8 *BATTLE_REC_GetHeaderOf(struct ObjC4 *p);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
extern void func_021B9EF0(void*,char*,u32,u32,u32),BATTLE_REC_Delete(void*);
extern u32 func_020056BC(void);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern u32 func_0200B6E0(void*,u16,u32,u32,u32,u16*,u16*);
extern void BATTLE_REC_DecodeWork(void),TIME_ICON_Delete(u8*),GFL_USE_PlaySeDefaultVolume(u32);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32 lo, u32 hi);
extern u32 func_0200FB24(void);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, u32 lo, u32 hi);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_021BB27C(u8*),func_021BB290(u8*),func_021BB29C(char*);
extern void *func_02030734(u32,u32,int,const char*,u16);
extern void func_02040E78(u32,void*,u32,u32);
extern void func_020307B0(void *);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void *func_0201F5DC(void*,u32,u32,u32);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void func_02041B6C(u32);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void TCBL_Destroy(struct S02031140 *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void TCBL_Main(struct Tcbl *);
extern u8 func_02035630(void);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern void func_0201F7A8(void *desc, u32 kind);
extern unsigned char BMP_WIN_GetBgLayer(struct Descriptor *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern signed char func_02012FFC(void);
extern void*PRINTSYS_PrintStream(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
extern unsigned PRINTSYS_PrintStreamGetState(void*);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamReleasePause(void*);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *,void *);
extern unsigned func_0203FA08(unsigned,unsigned,unsigned);
extern struct BmpMenu *BMP_MENU_CreateYesNo(const struct WinDat *,u16,u8,u8,u16);
extern void PRINTSYS_PrintQueColor(void *, unsigned, unsigned, unsigned, unsigned, unsigned, int);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_021BB2A8(u8 *);
extern int func_0201BC3C(void);
extern u32 POKE_TOOL_CalcGraphicIndex(u32,u32,u32,u32);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern void UI_SCENE_LoadActorGfx(void*,In*,int,u16);
extern int UI_SCENE_CreateActor(void*,int,u16,u16,u8,u16);
extern void CLACT_SetActorBgPriority(int,u32);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
extern u32 POKE_TOOL_CalcIconPalette(u32,u32,u32,u32);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_DeleteActor(struct Obj *p);
extern void UI_SCENE_FreeActorGfx(unsigned int *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern unsigned int func_02049740(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_02041EE4(u32,u32,u32);
extern void func_02040618(u32,u32,u32);
extern void func_02041570(int channel, u16 val);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0207D518(u32);
extern void BG_SYS_ClearSubBgPlanes(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_020409B4(u32);
extern void func_020403F4(u8);
extern u32 func_02030CB0(u32);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *PALANM_Create(u32);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,u32);
extern void PALANM_Delete(void *);
extern void func_02030DA4(void *);
extern void func_02030D28(struct Ctx *c);
extern u32 PALANM_GetFadeRequestBits(const char *);
extern int PALANM_RequestFade(struct PalAnmObj *,u16,u32,s16,u8,u8,u16,void *);
extern void PALANM_TransferPalettes(struct S02021D50 *);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16,int,int,int,int);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32);
int func_021B95A0(void *manager,char *state,char * const obj);
int func_021B9798(void *owner,int unused,int state,char *p);
int func_021B9834(void *unused,u32 *state,const char *obj,char *p);
void func_021B9EB8(char *a, int b, char *c, int d, int e, int f, int g, int h, int i);
void func_021B9ED4(unsigned *out,void *a,char *p,unsigned b,unsigned c,unsigned d);
void func_021B9EF0(void *unused,char *p,unsigned a,unsigned b,unsigned c);
void func_021B9EFC(int *out, int a, int b, int c, int d);
void func_021B9F10(int unused, char *b, int c, int d);
void func_021B9F18(void *unused, char *p);
void func_021B9F24(void *unused, struct C *p);
void func_021BA018(int unused,char*p);
void func_021BA058(int unused,char *p);
void func_021BA074(int unused,char *p);
void func_021BA0A4(int unused,char *p);
void func_021BA0B0(int unused, char *p);
void func_021BA0DC(int unused,char *p);
void func_021BA108(int unused,char*p,unsigned entry,int v);
int func_021BA16C(int a,char *p);
int func_021BA190(int unused,char*p);
void func_021BA254(void*obj,char*p,unsigned entry);
u32 func_021BA2B8(int unused,u8 *p);
void func_021BA2F4(int unused,char*p);
void func_021BA39C(int unused, char *p);
void func_021BA3A0(int unused,u8 *p);
void func_021BA3C4(int unused,char*p);
void func_021BA43C(int unused, char *p);
void func_021BA45C(Obj*obj,char*p);
void func_021BA4E8(void *unused,struct BtlRecSel *p);
void func_021BA5C8(void*obj,char*p);
void func_021BA650(int unused,char*p);
void func_021BA6A0(void *obj, char *p, u32 v);
void func_021BA6F0(void*obj,char*p);
void func_021BA794(Obj *obj, struct BtlRecSel *e, unsigned int v);
void func_021BA8DC(void *unused,struct BtlRecSel *p);
void func_021BAAB0(int unused, int base);
int func_021BAB0C(int a,u16 b,int c,u8 d,u32 e,u32 f,u32 g,u32 h,void*x,u8 i,u8 j,u8 k,u8 l,u8 m);
void func_021BABA4(void*p,void*actor);
void func_021BABB8(int unused,char*p);
void func_021BABF4(int unused, char *p);
void func_021BAC3C(int unused,u8 *p);
void func_021BAC58(int unused,u8 *p);
void func_021BAC90(int unused,u8 *p);
void func_021BACCC(int unused,u8 *p);
void func_021BAD08(void *a0, char *a1);
void func_021BAD14(void **a,char *p);
void func_021BAE10(int unused, char *p);
void func_021BAE4C(int unused,u8 *p);
void func_021BAE88(int unused,u8 *p);
void func_021BAE9C(int unused,char *p);
void func_021BAF30(int unused,u8 *p);
void func_021BAF64(void *unused,struct BtlRecSel *p);
void func_021BB0C4(char *p);
void func_021BB0D4(void);
extern u8 ov67_id[];
extern const char ov067_id[];
extern const char d_021BB658[];
extern const Table d_021BB480;
extern const Pair d_021BB4C4[];
extern const u32 d_021BB498[][11];
extern u32 d_021BB640[][3];
extern const struct Rect rects[];








int func_021B95A0(void *manager,char *state,char * const obj)
{
    char *p;
    u8 i;
    enum {K=3} k;
    func_02034AC4((int)ov67_id);
    GFL_HEAP_CreateChildHeap(1,0x75,0x50000);
    p=PROCSYS_AllocProcWork(manager,0x2f0,0x75);
    MI_CpuFill8(p,0,0x2f0);
    ((struct Obj00182 *)p)->f0=0x75;
    for(i=0;i<=7;i++)func_02040588(i,0);
    *(void* *)&((struct Obj00182 *)p)->f4=func_021BB178(1,((struct Obj00182 *)p)->f0);
    *(void* *)&((struct Obj00182 *)p)->f8=GF_FONT_Create(23,0,0,0,((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->fC=PRINTSYS_QUE_Create((void*)(u32)((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f10=PRINTSYS_QUE_Create((void*)(u32)((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f14=PRINTSYS_QUE_Create((void*)(u32)((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f18=PRINTSYS_QUE_Create((void*)(u32)((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f50=func_02007F68(func_0201292C(*(void* *)&((struct Obj06705 *)obj)->f0),0x1d1,1,((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f54=0;
    ((struct Obj00182 *)p)->f4C=func_020056A0((void (*)(void *))func_021B9F18,p,1);
    *(void* *)&((struct Obj00182 *)p)->f58=func_02045B38(0,2,19,((struct Obj00182 *)p)->f0);
    func_021BABF4((int)obj,p);func_021BAD08(obj,p);func_021BAD14((void **)obj,p);
    func_021B9F24(obj,(struct C *)p);func_021BA074((int)obj,p);func_021BA2F4((int)obj,p);func_021BA3C4((int)obj,p);
    func_0204047C(2,2);k=K;func_0204047C(k,1);func_0204047C(1,0);
    func_02040588(2,1);func_02040588(3,1);func_02040588(1,1);
    func_02040EBC(0,0);func_02040EBC(4,0);FADE_Start(3,16,16,0);
    if(((struct Obj00182 *)p)->f50){
        if(((struct Obj06705 *)obj)->fC){
          if(((struct Obj06705 *)obj)->f4){
            func_021B9EB8(state,(int)obj,p,2,k,16,0,2,0);
            func_021B9EF0(obj,p,5,0,1);func_021BA6A0(obj,p,60);
            if(((struct Obj06705 *)obj)->f8)func_021BAC58((int)obj,(u8 *)p);
            ((struct Obj00182 *)p)->fB4=1;
          }else {func_021B9EB8(state,(int)obj,p,15,k,16,0,2,0);}
        }else {common:func_021B9EB8(state,(int)obj,p,15,k,16,0,2,0);}
    }else if(((struct Obj06705 *)obj)->f8){func_021B9EB8(state,(int)obj,p,15,k,16,0,2,0);}
    else ((struct Obj00182 *)p)->f54=1;
    func_021BAE4C((int)obj,(u8 *)p);func_021BAE9C((int)obj,p);func_021BAE88((int)obj,(u8 *)p);
    GFL_NET_RestartWithDefaultTimeout(1,((struct Obj00182 *)p)->f0);
    return 1;
}








int func_021B9798(void *owner,int unused,int state,char *p)
{
    func_021BAF30(state,(u8 *)p);
    func_021BA43C(state,p);
    func_021BA39C(state,p);
    func_021BA018(state,p);
    func_021BAE10(state,p);
    func_021BAC3C(state,(u8 *)p);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj00636 *)p)->f58);
    func_02030EAC((struct Node *)(((struct Obj00636 *)p)->f4C));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj00636 *)p)->f18));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj00636 *)p)->f18));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj00636 *)p)->f14));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj00636 *)p)->f14));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj00636 *)p)->f10));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj00636 *)p)->f10));
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj00636 *)p)->fC));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj00636 *)p)->fC));
    GF_FONT_Delete(((struct Obj00636 *)p)->f8);
    func_021BB220(*(char * *)&((struct Obj00636 *)p)->f4);
    func_020315D4(owner);
    func_020306F0(117);
    func_02034A5C((int)ov067_id);
    return 1;
}







/*
 * note 2026-10-05: no default label (the dispatch bhi lands on case 3's own break stub);
 * the finish call (18,3,0,16,2,0) is written inline in case 15 and again in case 17, never by goto;
 * case 5 writes its own cancel copy (no goto into case 6); side and index are int; c = 0 is set
 * before the first BATTLE_REC_GetHeaderParam call; case 12 stores p+0x64 = 120 in both arms.
 * GAME_DATA_GetSaveControl 0x02012EBC thumb
 * KEY_GetTrg 0x020362DC arm
 * FADE_Start 0x0204E720 arm
 * FADE_IsActive 0x0204E804 arm
 * func_021BA108 0x021BA108 thumb ov214
 * func_021BA16C 0x021BA16C thumb ov214
 * func_021BA3A0 0x021BA3A0 thumb ov214
 * BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 * BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 * func_020355D8 0x020355D8 arm
 * BATTLE_REC_CheckSaved 0x0200B5CC thumb
 * func_021B9EB8 0x021B9EB8 thumb ov214
 * func_021BA6F0 0x021BA6F0 thumb ov214
 * func_021B9ED4 0x021B9ED4 thumb ov214
 * BATTLE_REC_LoadAlloc 0x0200B5A4 thumb
 * func_021BAD08 0x021BAD08 thumb ov214
 * func_021BA0B0 0x021BA0B0 thumb ov214
 * BATTLE_REC_GetHeaderOf 0x0200B934 thumb
 * BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 * func_021BABB8 0x021BABB8 thumb ov214
 * func_021BA5C8 0x021BA5C8 thumb ov214
 * func_021BA8DC 0x021BA8DC thumb ov214
 * func_021BAC90 0x021BAC90 thumb ov214
 * func_021BACCC 0x021BACCC thumb ov214
 * func_021B9EF0 0x021B9EF0 thumb ov214
 * BATTLE_REC_Delete 0x0200B438 thumb
 * func_021BA650 0x021BA650 thumb ov214
 * func_021BAAB0 0x021BAAB0 thumb ov214
 * func_021BA0DC 0x021BA0DC thumb ov214
 * func_021BA0A4 0x021BA0A4 thumb ov214
 * func_021BA254 0x021BA254 thumb ov214
 * func_021BA2B8 0x021BA2B8 thumb ov214
 * func_020056BC 0x020056BC thumb
 * TIME_ICON_Create 0x0202EE30 thumb
 * func_0200B6E0 0x0200B6E0 thumb
 * BATTLE_REC_DecodeWork 0x0200B490 thumb
 * TIME_ICON_Delete 0x0202F038 thumb
 * GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 * func_021B9EFC 0x021B9EFC thumb ov214
 * GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 * GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 * func_0200FB24 0x0200FB24 thumb
 * GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 * func_021BA058 0x021BA058 thumb ov214
 * func_021BA45C 0x021BA45C thumb ov214
 * func_021BA4E8 0x021BA4E8 thumb ov214
 * func_021BAF64 0x021BAF64 thumb ov214
 * PRINTSYS_QUE_Main 0x0201C4E4 thumb
 * func_021BB27C 0x021BB27C thumb ov214
 * func_021BB290 0x021BB290 thumb ov214
 * func_021BB29C 0x021BB29C thumb ov214
 */
int func_021B9834(void *unused,u32 *state,const char *obj,char *p)
{
    void *owner,*record;
    u32 result;
    int done;
    int side,index;
    long i;
    u32 status0,status1,a,b,c;
    u32 addr;
    owner=GAME_DATA_GetSaveControl(*(void**)obj);
    KEY_GetTrg();
    switch(*state){
    case 0:
        if((*(u32*)(p+0x54))){*state=18;break;}
        if((*(u32*)(p+0x30))==1){if((*(u32*)(p+0x24))==0)(*(u32*)(p+0x2e4))=2;else (*(u32*)(p+0x2e4))=1;}
        else FADE_Start((*(u32*)(p+0x20)),(*(u32*)(p+0x24)),(*(u32*)(p+0x28)),(*(u32*)(p+0x2c)));
        *state=1;break;
    case 1:
        done=0;
        if((*(u32*)(p+0x30))==1){if((*(u32*)(p+0x2e8))==0||(*(u32*)(p+0x2e8))==2)done=1;}
        else if(!FADE_IsActive())done=1;
        if(done){(*(u32*)(p+0xb4))=0;*state=(*(u32*)(p+0x1c));}break;
    case 2:func_021BA108((int)obj,p,(*(u32*)(p+0x38)),0);*state=3;break;
    case 3:
        if(!func_021BA16C((int)obj,p))break;
        func_021BA3A0((int)obj,(u8 *)p);*state=(*(u32*)(p+0x34));break;
    case 4:func_021BA108((int)obj,p,(*(u32*)(p+0x44)),0);*state=(*(u32*)(p+0x40));break;
    case 5:
        result=BMP_MENU_ProcessYesNo((u8*)(*(u32*)(p+0x88)));
        if(result!=0xffffffff){
            func_020355D8(0);
            if(result==0){
                if(BATTLE_REC_CheckSaved(owner,*(u16*)p,&status0,0)){
                    (*(u32*)(p+0xb4))=1;func_021B9EB8((char*)state,(int)obj,p,8,1,0,16,-2,1);break;
                }else{func_021BA6F0((void*)obj,p);*state=10;}
            }else func_021B9ED4(state,(void*)obj,p,6,3,1);
        }else if((*(u32*)(p+0xb8))){BMP_MENU_DeleteYesNo((void*)(*(u32*)(p+0x88)));*state=15;}
        break;
    case 6:
        result=BMP_MENU_ProcessYesNo((u8*)(*(u32*)(p+0x88)));
        if(result!=0xffffffff){
            func_020355D8(0);
            if(result==0){func_021BA6F0((void*)obj,p);*state=15;}
            else func_021B9ED4(state,(void*)obj,p,5,0,1);
        }else if((*(u32*)(p+0xb8))){BMP_MENU_DeleteYesNo((void*)(*(u32*)(p+0x88)));*state=15;}
        break;
    case 7:
        result=BMP_MENU_ProcessYesNo((u8*)(*(u32*)(p+0x88)));
        if(result!=0xffffffff){
            func_020355D8(0);
            if(result==0)(*(u32*)(p+0x48))=10;else (*(u32*)(p+0x48))=15;
            func_021BA6F0((void*)obj,p);
            func_021B9EB8((char*)state,(int)obj,p,9,1,0,16,-2,1);break;
        }else if((*(u32*)(p+0xb8))){
            BMP_MENU_DeleteYesNo((void*)(*(u32*)(p+0x88)));(*(u32*)(p+0x48))=15;
            func_021B9EB8((char*)state,(int)obj,p,9,1,0,16,-2,1);break;
        }
        break;
    case 8:
        (*(u32*)(p+0x2ac))=(u32)BATTLE_REC_LoadAlloc(owner,*(u16*)p,&status1,0);
        func_021BAD08((void*)obj,p);func_021BA0B0((int)obj,p);
        if(status1==1){
            record=BATTLE_REC_GetHeaderOf((void*)(*(u32*)(p+0x2ac)));
            (*(u32*)(p+0x2b0))=BATTLE_REC_GetHeaderParam(record,3,0);
            func_021BABB8((int)obj,p);
            for(i=0;i<12;i++){
                b=0;c=0;a=BATTLE_REC_GetHeaderParam(record,0,i);
                if(a){b=BATTLE_REC_GetHeaderParam(record,1,i);c=BATTLE_REC_GetHeaderParam(record,6,i);}
                if((*(u32*)(p+0x2a8))){
                    if(i<6){
                        addr=(u32)p+(u32)(i%6)*40;
                        *(u32*)(addr+0x1b4)=a;*(u32*)(addr+0x1b8)=b;*(u32*)(addr+0x1bc)=c;
                    }else{
                        addr=(u32)p+(u32)(i%6)*40;
                        *(u32*)(addr+0xc4)=a;*(u32*)(addr+0xc8)=b;*(u32*)(addr+0xcc)=c;
                    }
                }else{
                    if(i<3){side=1;index=i;}
                    else if(i<6){side=0;index=i-3;}
                    else if(i<9){side=1;index=i-3;}
                    else{side=0;index=i-6;}
                    addr=(u32)p+(u32)side*240+(u32)index*40;
                    *(u32*)(addr+0xc4)=a;*(u32*)(addr+0xc8)=b;*(u32*)(addr+0xcc)=c;
                }
            }
            func_021BA5C8((void*)obj,p);func_021BA8DC((void*)obj,(struct BtlRecSel *)p);
            if((*(u32*)(p+0x2a8)))func_021BAC90((int)obj,(u8 *)p);else func_021BACCC((int)obj,(u8 *)p);
            func_021B9EB8((char*)state,(int)obj,p,2,1,16,0,-2,1);
            func_021B9EF0((void*)obj,p,7,6,0);
        }else func_021B9EB8((char*)state,(int)obj,p,10,1,16,0,-2,1);
        BATTLE_REC_Delete((void*)(*(u32*)(p+0x2ac)));break;
    case 9:
        func_021BA650((int)obj,p);func_021BAAB0((int)obj,(int)p);func_021BAD08((void*)obj,p);
        func_021B9EB8((char*)state,(int)obj,p,(*(u32*)(p+0x48)),1,16,0,-2,1);
        func_021BA0B0((int)obj,p);
        if((*(u32*)(p+0x48))==15 && (*(u32*)(p+0x50)) && (*(u32*)(obj+4)) && !(*(u32*)(obj+8))){func_021BA0DC((int)obj,p);func_021BA0A4((int)obj,p);}
        func_021BA6F0((void*)obj,p);break;
    case 10:func_021BA254((void*)obj,p,9);*state=11;break;
    case 11:
        if(func_021BA2B8((int)obj,(u8 *)p)){
            (*(u32*)(p+0x2ec))=(u32)TIME_ICON_Create((void *)func_020056BC(),(void*)(*(u32*)(p+0x6c)),15,16,*(u16*)p);
            (*(u32*)(p+0x2b4))=0;*(u16*)(p+0x2b8)=0;*(u16*)(p+0x2ba)=0;(*(u32*)(p+0x2bc))=0;
            *state=12;
        }break;
    case 12:
        if((*(u32*)(p+0x2bc))!=2 && (*(u32*)(p+0x2bc))!=3)(*(u32*)(p+0x2bc))=func_0200B6E0(*(void**)obj,*(u16*)p,(*(u32*)(obj+0x10)),(*(u32*)(obj+0x14)),0,(u16*)(p+0x2b8),(u16*)(p+0x2ba));
        if((u32)((*(u32*)(p+0x2bc))-2)<=1){
            BATTLE_REC_DecodeWork();TIME_ICON_Delete((u8*)(*(u32*)(p+0x2ec)));
            if((*(u32*)(p+0x2bc))==2){GFL_USE_PlaySeDefaultVolume(0x558);func_021B9EFC((int*)state,(int)obj,(int)p,13,10);(*(u32*)(p+0x64))=120;}
            else if((*(u32*)(p+0x2bc))==3){func_021B9EFC((int*)state,(int)obj,(int)p,14,11);(*(u32*)(p+0x64))=120;}
        }break;
    case 13:if(func_021BA16C((int)obj,p))*state=15;break;
    case 14:if(func_021BA16C((int)obj,p))*state=15;break;
    case 15:
        if((*(u32*)(p+0x50))){
            if((*(u32*)(obj+0xc))){
                if((*(u32*)(obj+4))){
                    if((*(u32*)(obj+8)))a=12;
                    else{func_021B9EB8((char*)state,(int)obj,p,18,3,0,16,2,0);break;}
                }else if((*(u32*)(obj+8)))a=13;else a=14;
            }else a=15;
        }else if((*(u32*)(obj+8)))a=12;else{*state=18;break;}
        if((*(u32*)(obj+8)))func_021BA254((void*)obj,p,a);else func_021BA108((int)obj,p,a,1);
        *state=16;break;
    case 16:
        done=0;
        if((*(u32*)(obj+8))){if(func_021BA2B8((int)obj,(u8 *)p))done=1;}
        else if(func_021BA16C((int)obj,p))done=1;
        if(done){
            if((*(u32*)(obj+8))){
                GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),150,43);
                (*(u32*)(p+0x2ec))=(u32)TIME_ICON_Create((void *)func_020056BC(),(void*)(*(u32*)(p+0x6c)),15,16,*(u16*)p);
            }
            *state=17;
        }break;
    case 17:
        done=1;
        if((*(u32*)(obj+8))){
            if(!func_0200FB24())done=GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),150,43);
            if(done)TIME_ICON_Delete((u8*)(*(u32*)(p+0x2ec)));
        }
        if(done)func_021B9EB8((char*)state,(int)obj,p,18,3,0,16,2,0);
        break;
    case 18:return 1;
    }
    func_021BA058((int)obj,p);func_021BA45C((void*)obj,p);func_021BA4E8((void*)obj,(struct BtlRecSel *)p);func_021BAF64((void*)obj,(struct BtlRecSel *)p);
    PRINTSYS_QUE_Main((void*)(*(u32*)(p+0xc)));PRINTSYS_QUE_Main((void*)(*(u32*)(p+0x10)));PRINTSYS_QUE_Main((void*)(*(u32*)(p+0x14)));PRINTSYS_QUE_Main((void*)(*(u32*)(p+0x18)));
    func_021BB27C((u8*)(*(u32*)(p+4)));func_021BB290((u8*)(*(u32*)(p+4)));func_021BB29C((char*)(*(u32*)(p+4)));
    return 0;
}








void func_021B9EB8(char *a, int b, char *c, int d, int e, int f, int g, int h, int i)
{
    ((struct Obj25721 *)a)->f0 = 0;
    ((struct Obj05548 *)c)->f1C = d;
    ((struct Obj05548 *)c)->f20 = e;
    ((struct Obj05548 *)c)->f24 = f;
    ((struct Obj05548 *)c)->f28 = g;
    ((struct Obj05548 *)c)->f2C = h;
    ((struct Obj05548 *)c)->f30 = i;
}







void func_021B9ED4(unsigned *out,void *a,char *p,unsigned b,unsigned c,unsigned d){*out=2;func_021B9EF0(a,p,b,c,d);}







void func_021B9EF0(void *unused,char *p,unsigned a,unsigned b,unsigned c){((struct Obj10934 *)p)->f34=a;((struct Obj10934 *)p)->f38=b;((struct Obj10934 *)p)->f3C=c;}







void func_021B9EFC(int *out, int a, int b, int c, int d)
{
    *out = 4;
    func_021B9F10(a, (char *)b, c, d);
}







void func_021B9F10(int unused, char *b, int c, int d)
{
    ((struct Obj14698 *)b)->f40 = c;
    ((struct Obj14698 *)b)->f44 = d;
}






/*
 * blocker-leaf: sole callback blocker of ov214 021B95A0; no existing source/unit/shard, parent ownership cleared.
 */
void func_021B9F18(void *unused, char *p)
{
    func_021BB0C4(p);
}






static inline void init_palette(struct Palette *pal)
{
    pal->a=0x294b; pal->b=0x5694; pal->c=0x7fff;
}






void func_021B9F24(void *unused, struct C *p)
{
    struct Palette *pal = func_02030734(p->heap,6,1,d_021BB658,0x5e9);
    init_palette(pal);
    func_02040E78(2,pal,6,0x13a);
    func_020307B0(pal);
    func_02049B40(0x17,5,0,0x180,0x20,p->heap);
    p->win0=(void *)BMP_WIN_Create(1,0,0,1,1,9,0);
    BMP_Clear(BMP_WIN_GetBmp(p->win0),0);
    BMP_WIN_TransferChars(p->win0);
    p->win1=(void *)BMP_WIN_Create(1,1,0x13,0x1e,4,0xc,0);
    BMP_Clear(BMP_WIN_GetBmp(p->win1),0xf);
    BMP_WIN_TransferChars(p->win1);
    p->font=func_0201F5DC((void*)1,0xa,0,p->heap);
    p->task=TCBL_Create(p->heap,p->heap,1,0);
    GF_FONT_SetTextColor(1,2,0xf);
    func_02041B6C(1);
    *(u32*)((u8*)p+0x5c)=0;
    *(u32*)((u8*)p+0x60)=0;
    *(u32*)((u8*)p+0x64)=0;
    p->f78=0;
}






void func_021BA018(int unused,char*p)
{
    if(*(void* *)&((struct Obj00636 *)p)->f5C)PRINTSYS_PrintStreamDelete(*(void* *)&((struct Obj00636 *)p)->f5C);
    if(*(void* *)&((struct Obj00636 *)p)->f78)STRBUF_Delete(*(void* *)&((struct Obj00636 *)p)->f78);
    TCBL_Destroy(*(void* *)&((struct Obj00636 *)p)->f68);
    func_0203FB44(1,(u16)(((struct Obj00636 *)p)->f74),(u16)(((struct Obj00636 *)p)->f74>>16));
    BMP_WIN_Delete(*(void* *)&((struct Obj00636 *)p)->f6C);
    BMP_WIN_Delete(*(void* *)&((struct Obj00636 *)p)->f70);
}






/*
 * Tail: two zero alignment bytes at 021BA072.
 */
void func_021BA058(int unused,char *p){TCBL_Main(*(struct Tcbl * *)&((struct Obj14699 *)p)->f68);if(func_02035630()==30)TCBL_Main(*(struct Tcbl * *)&((struct Obj14699 *)p)->f68);}





/*
 * Parameter evidence: original narrows third input to u16 before func_0201F73C.
 */
void func_021BA074(int unused,char *p){struct Descriptor *d;func_0201F73C(((struct Obj10935 *)p)->f6C,1,(unsigned short)(((struct Obj10935 *)p)->f74),10);d=*(struct Descriptor * *)&((struct Obj10935 *)p)->f6C;BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);func_02041B6C(BMP_WIN_GetBgLayer(d));}





void func_021BA0A4(int unused,char *p){func_0201F7A8(((struct Obj25724 *)p)->f6C,(int)1);}





void func_021BA0B0(int unused, char *p)
{
    struct Descriptor *d;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj14700 *)p)->f6C), 15);
    d = ((struct Obj14700 *)p)->f6C;
    BMP_WIN_TransferChars(d);
    BMP_WIN_MakeScreen((struct Cfg *)d);
    func_02041B6C(BMP_WIN_GetBgLayer(d));
}





/*
 * Tail: two zero alignment bytes at 021BA106.
 */
void func_021BA0DC(int unused,char *p){struct Descriptor *d;BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj14700 *)p)->f6C),0);d=*(struct Descriptor * *)&((struct Obj14700 *)p)->f6C;BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);func_02041B6C(BMP_WIN_GetBgLayer(d));}





/*
 * note: 0201CCE4's r0 remains live and is stored at +5c after the call;
 * its caller declaration returns that word despite the own source's void.
 * extent-tail: 021BA16A alignment padding (two zero bytes).
 */
void func_021BA108(int unused,char*p,unsigned entry,int v)
{
    int x;
    BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct Obj01782 *)p)->f6C),15);
    if(*(void* *)&((struct Obj01782 *)p)->f5C)PRINTSYS_PrintStreamDelete(*(void* *)&((struct Obj01782 *)p)->f5C);
    if(*(void* *)&((struct Obj01782 *)p)->f78)STRBUF_Delete(*(void* *)&((struct Obj01782 *)p)->f78);
    *(void* *)&((struct Obj01782 *)p)->f78=func_02045EC0(*(void* *)&((struct Obj01782 *)p)->f58,entry);
    x=func_02012FFC();
    *(void* *)&((struct Obj01782 *)p)->f5C=PRINTSYS_PrintStream(*(unsigned *)&((struct Obj01782 *)p)->f6C,0,0,*(unsigned *)&((struct Obj01782 *)p)->f78,((struct Obj01782 *)p)->f8,x,((struct Obj01782 *)p)->f68,2,((struct Obj01782 *)p)->f0,15);
    ((struct Obj01782 *)p)->f60=v;
}





int func_021BA16C(int a,char *p){int result=func_021BA190(a,p);if(result==0){if(func_02035630()==30)result=func_021BA190(a,p);}return result;}





int func_021BA190(int unused,char*p)
{
    int result=0;
    switch(PRINTSYS_PrintStreamGetState(*(void* *)&((struct Obj04632 *)p)->f5C)){
    case 0:
        if((KEY_GetCont()&3)||TOUCHPANEL_GetCont()){
            PRINTSYS_PrintStreamShortWait(*(void* *)&((struct Obj04632 *)p)->f5C,0);
            if(KEY_GetCont()&3)func_020355D8(0);else func_020355D8(1);
        }
        break;
    case 1:
        if((KEY_GetTrg()&3)||TOUCHPANEL_GetTrg()){
            GFL_USE_PlaySeDefaultVolume(0x547);
            PRINTSYS_PrintStreamReleasePause(*(void* *)&((struct Obj04632 *)p)->f5C);
            if(KEY_GetTrg()&3)func_020355D8(0);else func_020355D8(1);
        }
        break;
    case 2:
        if(((struct Obj04632 *)p)->f64)--((struct Obj04632 *)p)->f64;
        else if(((struct Obj04632 *)p)->f60){
            if((KEY_GetTrg()&3)||TOUCHPANEL_GetTrg()){
                if(KEY_GetTrg()&3)func_020355D8(0);else func_020355D8(1);
                ((struct Obj04632 *)p)->f60=0;
                result=1;
            }
        }else result=1;
        break;
    }
    return result;
}





void func_021BA254(void*obj,char*p,unsigned entry)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct Obj01082 *)p)->f6C),15);
    if(*(void* *)&((struct Obj01082 *)p)->f5C)PRINTSYS_PrintStreamDelete(*(void* *)&((struct Obj01082 *)p)->f5C);
    *(int *)&((struct Obj01082 *)p)->f5C=0;
    if(*(void* *)&((struct Obj01082 *)p)->f78)STRBUF_Delete(*(void* *)&((struct Obj01082 *)p)->f78);
    *(void* *)&((struct Obj01082 *)p)->f78=func_02045EC0(*(void* *)&((struct Obj01082 *)p)->f58,entry);
    *(int *)&((struct Obj01082 *)p)->f7C=0;
    PRINTSYS_PrintQue(*(void* *)&((struct Obj01082 *)p)->fC,(unsigned)BMP_WIN_GetBmp(*(void* *)&((struct Obj01082 *)p)->f6C),0,0,*(void* *)&((struct Obj01082 *)p)->f78,((struct Obj01082 *)p)->f8);
    func_021BA2B8((int)obj,(u8 *)p);
}





u32 func_021BA2B8(int unused,u8 *p){struct Descriptor *d;if(((struct Obj01082 *)p)->f7C==0){if(PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj01082 *)p)->fC,BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj01082 *)p)->f6C))==0){d=*(struct Descriptor * *)&((struct Obj01082 *)p)->f6C;BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);func_02041B6C(BMP_WIN_GetBgLayer(d));((struct Obj01082 *)p)->f7C=1;}}return ((struct Obj01082 *)p)->f7C;}





void func_021BA2F4(int unused,char*p)
{
    unsigned off;
    u16*colors;
    off=func_0203FA08(1,0x500,1);
    func_0203FB44(1,off,0x500);
    func_02049B40(0x17,5,0,0x160,0x20,((struct Obj04633 *)p)->f0);
    colors=func_02030734(((struct Obj04633 *)p)->f0,6,1,d_021BB658,0x6f9);
    colors[0]=0x294b;colors[1]=0x5694;colors[2]=0x7fff;
    func_02040E78(2,colors,6,0x17a);
    func_020307B0(colors);
    ((struct Obj04633 *)p)->f80=1;((struct Obj04633 *)p)->f81=0x18;((struct Obj04633 *)p)->f82=0xd;((struct Obj04633 *)p)->f83=0xb;
    ((struct Obj04633 *)p)->f84=off;
}





void func_021BA39C(int unused, char *p){}





void func_021BA3A0(int unused,u8 *p){*(struct BmpMenu * *)&((struct Obj10937 *)p)->f88=BMP_MENU_CreateYesNo((const struct WinDat *)(p+0x80),((struct Obj10937 *)p)->f74,10,0,((struct Obj10937 *)p)->f0);}





void func_021BA3C4(int unused,char*p)
{
    Table t=d_021BB480;
    u8 i;
    for(i=0;i<4;i++){
        *(unsigned*)(p+i*4+0x8c)=BMP_WIN_Create(t.r[i].a,t.r[i].b,t.r[i].c,t.r[i].d,t.r[i].e,9,t.r[i].f);
        BMP_Clear(BMP_WIN_GetBmp(*(void**)(p+i*4+0x8c)),0);
        *(int*)(p+i*4+0x9c)=1;
    }
    ((struct Obj00182 *)p)->fBC=0;
    ((struct Obj00182 *)p)->fC0=0;
}





void func_021BA43C(int unused, char *p)
{
    unsigned char i;
    for (i = 0; i < 4; i++)
    {
        BMP_WIN_Delete(*(void **)(p + 0x8c + i * 4));
    }
}




/*
 * note: BA794's third argument is narrowed at 021BA49A..A0; caller
 * extern uses u16 despite its own source's unsigned parameter.
 */
void func_021BA45C(Obj*obj,char*p)
{
    unsigned threshold;
    if(func_02035630()==30)threshold=30;else threshold=60;
    if(obj->c && !((struct Obj00202 *)p)->fB4 && (((struct Obj00202 *)p)->fAC>=threshold || *(int *)&((struct Obj00202 *)p)->fB0)){
        func_021BA794(obj,(struct BtlRecSel *)p,(u16)(((struct Obj00202 *)p)->fAC/threshold));
        if(((struct Obj00202 *)p)->fAC>=threshold){
            --((struct Obj00202 *)p)->fAC;
            if(((struct Obj00202 *)p)->fAC==threshold-1)((struct Obj00202 *)p)->fB8=1;
        }else{
            --((struct Obj00202 *)p)->fB0;
            if(!((struct Obj00202 *)p)->fB0)func_021BA6F0(obj,p);
        }
    }
}




/*
 * extent: two bytes zero alignment at 021BA5C6.
 * lever: indexed struct members keep the fixed field offset inside the loop;
 *   raw pointer form was DIFF236/217, integer form DIFF222/66.
 */
void func_021BA4E8(void *unused,struct BtlRecSel *p)
{
    u8 i;
    struct Descriptor *d;
    for (i=0;i<=1;i++) {
        if (p->flags[i]==0) {
            if (PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj01588 *)p)->f10,BMP_WIN_GetBmp(p->descriptors[i]))==0) {
                d=p->descriptors[i];
                BMP_WIN_TransferChars(d);
                BMP_WIN_MakeScreen((struct Cfg *)d);
                func_02041B6C(BMP_WIN_GetBgLayer(d));
                p->flags[i]=1;
            }
        }
    }
    if (((struct Obj01588 *)p)->fA4==0) {
        if (PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj01588 *)p)->f14,BMP_WIN_GetBmp(p->other1))==0) {
            d=p->other1;
            BMP_WIN_TransferChars(d);
            BMP_WIN_MakeScreen((struct Cfg *)d);
            func_02041B6C(BMP_WIN_GetBgLayer(d));
            ((struct Obj01588 *)p)->fA4=1;
        }
    }
    if (((struct Obj01588 *)p)->fA8==0) {
        if (PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj01588 *)p)->f18,BMP_WIN_GetBmp(p->other2))==0) {
            d=p->other2;
            BMP_WIN_TransferChars(d);
            BMP_WIN_MakeScreen((struct Cfg *)d);
            func_02041B6C(BMP_WIN_GetBgLayer(d));
            ((struct Obj01588 *)p)->fA8=1;
        }
    }
}



void func_021BA5C8(void*obj,char*p)
{
    void*h;
    h=func_02045EC0(*(void* *)&((struct Obj02552 *)p)->f58,19);
    PRINTSYS_PrintQueColor(*(void* *)&((struct Obj02552 *)p)->f10,(unsigned)BMP_WIN_GetBmp(*(void* *)&((struct Obj02552 *)p)->f8C),4,1,(unsigned)h,((struct Obj02552 *)p)->f8,0x440);
    STRBUF_Delete(h);
    ((struct Obj02552 *)p)->f9C=0;
    h=func_02045EC0(*(void* *)&((struct Obj02552 *)p)->f58,((struct Obj02552 *)p)->f2A4);
    PRINTSYS_PrintQueColor(*(void* *)&((struct Obj02552 *)p)->f10,(unsigned)BMP_WIN_GetBmp(*(void* *)&((struct Obj02552 *)p)->f90),4,1,(unsigned)h,((struct Obj02552 *)p)->f8,0x440);
    STRBUF_Delete(h);
    ((struct Obj02552 *)p)->fA0=0;
    func_021BA4E8(obj,(struct BtlRecSel *)p);
}



void func_021BA650(int unused,char*p)
{
    u8 i;
    void*h;
    for(i=0;i<=1;i++){
        PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj25726 *)p)->f10));
        BMP_Clear(BMP_WIN_GetBmp(*(void**)(p+i*4+0x8c)),0);
        h=*(void**)(p+i*4+0x8c);
        BMP_WIN_TransferChars(h);
        BMP_WIN_MakeScreen(h);
        func_02041B6C(BMP_WIN_GetBgLayer(h));
        *(int*)(p+i*4+0x9c)=1;
    }
}



void func_021BA6A0(void *obj, char *p, u32 v)
{
    u32 threshold;
    if (func_02035630() == 30) threshold = 30;
    else threshold = 60;
    ((struct Obj00202 *)p)->fAC = threshold * (v + 1) - 1;
    ((struct Obj00202 *)p)->fB0 = threshold >> 1;
    ((struct Obj00202 *)p)->fB4 = 0;
    ((struct Obj00202 *)p)->fB8 = 0;
    ((struct Obj00202 *)p)->fBC = 0;
    ((struct Obj00202 *)p)->fC0 = 0;
    func_021BA794(obj, (struct BtlRecSel *)p, v);
}





void func_021BA6F0(void*obj,char*p)
{
    void*h;
    *(int *)&((struct Obj00202 *)p)->fAC=0;
    *(int *)&((struct Obj00202 *)p)->fB0=0;
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj00202 *)p)->f14));
    BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct Obj00202 *)p)->f94),0);
    h=*(void* *)&((struct Obj00202 *)p)->f94;
    BMP_WIN_TransferChars(h);BMP_WIN_MakeScreen(h);func_02041B6C(BMP_WIN_GetBgLayer(h));
    ((struct Obj00202 *)p)->fA4=1;
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj00202 *)p)->f18));
    BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct Obj00202 *)p)->f98),0);
    h=*(void* *)&((struct Obj00202 *)p)->f98;
    BMP_WIN_TransferChars(h);BMP_WIN_MakeScreen(h);func_02041B6C(BMP_WIN_GetBgLayer(h));
    ((struct Obj00202 *)p)->fA8=1;
    if(((struct Obj00202 *)p)->f3C)func_021BAD08(obj,p);
    ((struct Obj00202 *)p)->fBC=0;
    ((struct Obj00202 *)p)->fC0=0;
}






void func_021BA794(Obj *obj, struct BtlRecSel *e, unsigned int v)
{
    int state;
    int flag;
    int tmp;
    int h;
    int p;
    int x;
    int h2;
    int p2;
    int q;

    if (obj->c == 0)
        return;

    if (v > 0xa) {
        flag = 0x440;
        state = 1;
    } else {
        flag = 0xc80;
        state = 2;
    }

    if (state != e->lastMode) {
        tmp = (int)BMP_WIN_GetBmp(e->other1);
        BMP_Clear((struct CharBuf *)tmp, 0);
        tmp = (int)BMP_WIN_GetBmp(e->other2);
        BMP_Clear((struct CharBuf *)tmp, 0);
    } else if (v != e->lastValue) {
        tmp = (int)BMP_WIN_GetBmp(e->other2);
        BMP_Clear((struct CharBuf *)tmp, 0);
    }

    if (state != e->lastMode) {
        PRINTSYS_QUE_Clear(e->printA);
        h = (int)func_02045EC0(e->msgBank, 0x10);
        p = (int)BMP_WIN_GetBmp(e->other1);
        PRINTSYS_PrintQueColor(e->printA, p, 4, 1, h, e->f08, flag);
        e->clearA = 0;
        STRBUF_Delete((struct U16Vec *)h);
    }

    if (state != e->lastMode || v != e->lastValue) {
        x = (int)func_0201EC64(e->heap);
        h2 = (int)func_02045EC0(e->msgBank, 0x12);
        p2 = (int)STRBUF_Create(8, e->heap);
        PRINTSYS_QUE_Clear(e->printB);
        func_0201EFA4((struct WordSet *)x, 1, v, 2, 2, 1);
        func_0201F250((struct WordSet *)x, (void *)p2, (void *)h2);
        q = (int)BMP_WIN_GetBmp(e->other2);
        PRINTSYS_PrintQueColor(e->printB, q, 2, 2, p2, e->f08, flag);
        e->clearB = 0;
        STRBUF_Delete((struct U16Vec *)p2);
        STRBUF_Delete((struct U16Vec *)h2);
        func_0201ED04((struct WordSet *)x);
    }

    e->lastMode = state;
    e->lastValue = v;
    func_021BA4E8(obj, (struct BtlRecSel *)e);
}





/*
 * layout: two rows of six 0x28-byte cells, observed nested-loop bounds.
 * prototypes: BAB0C owning matched source; B2A8 own same-region getter.
 * extent: 466-byte function followed by two zero alignment bytes at 021BAAAE.
 * lever: order-byte store inside each branch preserves original address CSE
 * and shared-tail layout; factoring it outside produced 430 bytes / DIFF316.
 */
void func_021BA8DC(void *unused,struct BtlRecSel *p)
{
    int handle=func_021BB2A8(p->owner);
    u8 i,j;
    for(i=0;i<2;i++) for(j=0;j<6;j++) {
        p->cells[i][j].d=0;
        p->cells[i][j].flag=1;
    }
    for(i=0;i<2;i++) for(j=0;j<6;j++) {
        if(p->mode) {
            if(i==0) { *(u8 *)((u32)p+240*i+40*j+0xE8)=100+24*j; *(u8 *)((u32)p+240*i+40*j+0xE9)=64; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
            else { *(u8 *)((u32)p+240*i+40*j+0xE8)=36+24*j; *(u8 *)((u32)p+240*i+40*j+0xE9)=112; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
        } else {
            if(i==0) {
                if(j<3) { *(u8 *)((u32)p+240*i+40*j+0xE8)=172+24*j; *(u8 *)((u32)p+240*i+40*j+0xE9)=64; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
                else { *(u8 *)((u32)p+240*i+40*j+0xE8)=172+24*(j-3); *(u8 *)((u32)p+240*i+40*j+0xE9)=88; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
            } else {
                if(j<3) { *(u8 *)((u32)p+240*i+40*j+0xE8)=36+24*j; *(u8 *)((u32)p+240*i+40*j+0xE9)=88; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
                else { *(u8 *)((u32)p+240*i+40*j+0xE8)=36+24*(j-3); *(u8 *)((u32)p+240*i+40*j+0xE9)=112; *(u8 *)((u32)p+240*i+40*j+0xEB)=6-j; }
            }
        }
    }
    for(i=0;i<2;i++) for(j=0;j<6;j++) {
        if(p->cells[i][j].a) {
            p->cells[i][j].actor=func_021BAB0C(handle,p->heap,0,0,
                p->cells[i][j].a,p->cells[i][j].b,p->cells[i][j].c,p->cells[i][j].d,
                &p->cells[i][j].out0,p->cells[i][j].x,p->cells[i][j].y,
                p->cells[i][j].flag,1,p->cells[i][j].order);
        }
    }
}






void func_021BAAB0(int unused, int base)
{
    unsigned char j, i;

    for (j = 0; j < 2; j++) {
        char *p = (char *)base + j * 0xf0;
        char *q = (char *)base + 0xd4 + j * 0xf0;
        for (i = 0; i < 6; i++) {
            if (*(int *)(p + 0xc4 + i * 0x28) != 0) {
                func_021BABA4(q + i * 0x28, (void *)(*(int *)(p + 0xe4 + i * 0x28)));
            }
        }
    }
}





int func_021BAB0C(int a,u16 b,int c,u8 d,u32 e,u32 f,u32 g,u32 h,void*x,u8 i,u8 j,u8 k,u8 l,u8 m)
{
    In in;
    int actor;
    in.f0=c;
    in.f4=1;
    in.f8=7;
    in.fC=func_0201BC3C();
    in.f10=POKE_TOOL_CalcGraphicIndex(e,f,g,h);
    in.f14=func_0201BC40();
    in.f18=func_0201BCB4();
    in.b1c=d;
    in.b1d=0;
    in.b1e=3;
    UI_SCENE_LoadActorGfx(x,&in,a,b);
    actor=UI_SCENE_CreateActor(x,a,i,j,k,b);
    CLACT_SetActorBgPriority(actor,l);
    CLACT_SetActorDrawPriority((struct Node *)actor,m);
    CLACT_SetActorAutoAnim((struct Obj *)actor,1);
    CLACT_SetActorPaletteOffset((struct Obj *)actor,POKE_TOOL_CalcIconPalette(e,f,g,h),0);
    return actor;
}





/*
 * function_starts: 0x021BABB8
 * note: Cleared BABB8 follower occupies 60 bytes through BABF4. The pools
 * at BABEC/BABF0 point to the two fields of the same byte-pair table.
 */
void func_021BABA4(void*p,void*actor)
{
    CLACT_DeleteActor(actor);
    UI_SCENE_FreeActorGfx(p);
}





void func_021BABB8(int unused,char*p)
{
    u8 i=((struct Obj08422 *)p)->f2B0;
    if(i>=0x29)i=0;
    ((struct Obj08422 *)p)->f2A4=d_021BB4C4[i].a;
    if(d_021BB4C4[i].b==0)((struct Obj08422 *)p)->f2A8=1;
    else ((struct Obj08422 *)p)->f2A8=0;
}






void func_021BABF4(int unused, char *p)
{
    void *h = func_020490F4(188, ((struct Obj00182 *)p)->f0);
    func_02049B68(h, 0, 0, 0, 320, ((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f2C0 = func_02049740(h, 1, 2, 0, 0, ((struct Obj00182 *)p)->f0);
    ARC_TOOL_DeleteHandle(h);
}





void func_021BAC3C(int unused,u8 *p){u32 v=((struct Obj25728 *)p)->f2C0;func_0203FB44(2,(u16)v,(u16)(v>>16));}





void func_021BAC58(int unused,u8 *p){func_0204989C(188,2,2,(u16)(((struct Obj00182 *)p)->f2C0),0,0,((struct Obj00182 *)p)->f0);func_02041B6C(2);func_02041EE4(3,3,0);}





void func_021BAC90(int unused,u8 *p){enum{K=2}k=K;func_0204989C(188,3,k,(u16)(((struct Obj14701 *)p)->f2C0),0,0,((struct Obj14701 *)p)->f0);func_02041B6C(2);k-=10;func_02040618(3,3,k);}





void func_021BACCC(int unused,u8 *p){enum{K=3}k;func_0204989C(188,4,2,(u16)(((struct Obj14702 *)p)->f2C0),0,0,((struct Obj14702 *)p)->f0);func_02041B6C(2);k=K;func_02040618(3,3,k-11);}





void func_021BAD08(void *a0, char *a1){func_02041570(2,0);}



void func_021BAD14(void **a,char *p)
{
    u8 gender;
    int i,which;
    const u32 *row;
    u32 layer;
    u16 heap;
    void *arc;
    gender=(u8)(u32)func_02008550((const struct Sub0200852CObj *)func_02012944(*a));
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04001000 &=0xFFFF1FFF;
    *(volatile u32 *)0x04001000 |=0x10000;
    BG_SYS_ClearSubPlanes();
    func_0207D518(0);
    BG_SYS_ClearSubBgPlanes();
    for (i=0;i<1U;i++) {
        row=d_021BB498[i];
        layer=row[0];
        func_0203FCA0((u8)layer,(const struct BgTemplate *)(row+1),(u8)row[9]);
        func_020414AC(layer);
        func_02040588(layer,row[10]);
    }
    BG_SYS_SetSubPlaneVisible(16,1);
    heap=*(u16 *)p;
    which=1;
    if (gender!=1) which=0;
    arc=func_020490F4(30,heap);
    func_02049B68(arc,d_021BB640[which][0],4,0,0,heap);
    func_02049658(arc,d_021BB640[which][1],4,0,0,0,heap);
    func_020498F4(arc,d_021BB640[which][2],4,0,0,0,heap);
    ARC_TOOL_DeleteHandle(arc);
    func_020409B4(4);
}




static inline void GXS_SetVisibleWnd(int window){*(volatile u32 *)0x04001000=(*(volatile u32 *)0x04001000&~0xe000u)|(window<<13);}




/*
 * volatile: hardware registers 0x04001050 (021BAE30), 0x04001000 read/write (021BAE34/021BAE3A).
 */
void func_021BAE10(int unused, char *p){int i;for(i=0;i<1u;i++)func_020403F4(d_021BB498[i][0]);*(volatile u16 *)0x04001050=0;GXS_SetVisibleWnd(0);}




void func_021BAE4C(int unused,u8 *p){*(int *)&((struct Obj00182 *)p)->f2D4=func_021BAB0C(func_021BB2A8(*(u8 * *)&((struct Obj00182 *)p)->f4),((struct Obj00182 *)p)->f0,0,0,1,0,0,0,p+0x2c4,0,0,0,1,1);}




void func_021BAE88(int unused,u8 *p){func_021BABA4(p+0x2c4,((struct Obj00182 *)p)->f2D4);}




void func_021BAE9C(int unused,char *p)
{
    ((struct Obj00182 *)p)->f2DC=func_02030734(((struct Obj00182 *)p)->f0,func_02030CB0(2),1,d_021BB658,2403);
    ((struct Obj00182 *)p)->f2D8=func_02030CBC(2,((struct Obj00182 *)p)->f2DC);
    ((struct Obj00182 *)p)->f2E0=PALANM_Create(((struct Obj00182 *)p)->f0);
    PALANM_SetAutoTransfer(((struct Obj00182 *)p)->f2E0,1);
    PALANM_AllocSlotBuffers(((struct Obj00182 *)p)->f2E0,0,448,((struct Obj00182 *)p)->f0);
    PALANM_AllocSlotBuffers(((struct Obj00182 *)p)->f2E0,2,448,((struct Obj00182 *)p)->f0);
    PALANM_CopyHwPaletteToSlot(((struct Obj00182 *)p)->f2E0,0,0,448);
    PALANM_CopyHwPaletteToSlot(((struct Obj00182 *)p)->f2E0,2,0,448);
    ((struct Obj00182 *)p)->f2E8=2;
    ((struct Obj00182 *)p)->f2E4=0;
}




void func_021BAF30(int unused,u8 *p){PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00636 *)p)->f2E0,0);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00636 *)p)->f2E0,2);PALANM_Delete(((struct Obj00636 *)p)->f2E0);func_02030DA4(((struct Obj00636 *)p)->f2D8);func_020307B0(((struct Obj00636 *)p)->f2DC);}




/*
 * prototype: 0202173C's third parameter is widened to the observed full-word
 *   caller payload; own u16 declaration inserted four extra truncation pairs.
 *   Both fixed-flag TU runs preserve its low-halfword colour; widening gives EXACT368.
 * extent: lead and tail-call follower 021BB0C4.
 */
void func_021BAF64(void *unused,struct BtlRecSel *p)
{
    u32 mask;
    u8 i;
    func_02030D28(p->heapHandle);
    if (PALANM_GetFadeRequestBits(p->anm)!=0) return;
    switch (p->state) {
    case 1: p->state=2; break;
    case 3: p->state=0; break;
    }
    switch (p->request) {
    case 1:
        if (p->state==1) return;
        mask=0;
        for (i=0;i<14;i++) mask|=(u16)(1<<i);
        PALANM_RequestFade((struct PalAnmObj *)p->anm,1,mask,-2,16,0,0,p->heapHandle);
        mask=0;
        for (i=0;i<14;i++) mask|=(u16)(1<<i);
        PALANM_RequestFade((struct PalAnmObj *)p->anm,4,mask,-2,16,0,0,p->heapHandle);
        p->state=1;
        p->request=0;
        return;
    case 2:
        if (p->state==3) break;
        mask=0;
        for (i=0;i<14;i++) mask|=(u16)(1<<i);
        PALANM_RequestFade((struct PalAnmObj *)p->anm,1,mask,-2,0,16,0,p->heapHandle);
        mask=0;
        for (i=0;i<14;i++) mask|=(u16)(1<<i);
        PALANM_RequestFade((struct PalAnmObj *)p->anm,4,mask,-2,0,16,0,p->heapHandle);
        p->state=3;
        p->request=0;
        break;
    }
}




void func_021BB0C4(char *p)
{
    PALANM_TransferPalettes(*(struct S02021D50 * *)&((struct Obj25729 *)p)->f2E0);
}

static inline void G2_SetBG0Priority(int priority)
{
    *(volatile u16 *)0x04000008=(u16)((*(volatile u16 *)0x04000008 & ~3) | priority);
}

static inline void G3X_SetShading(GXShading shading)
{
    REG3D=(u16)((REG3D & ~(2|0x3000)) | (shading<<1));
}

static inline void G3X_AntiAlias(int enable)
{
    if(enable) REG3D=(u16)((REG3D & ~0x3000)|16);
    else REG3D &= (u16)~(16|0x3000);
}

static inline void G3X_AlphaTest(int enable,int ref)
{
    if(enable) { REG3D=(u16)((REG3D & ~0x3000)|4); *(volatile u16 *)0x04000340=(u16)ref; }
    else REG3D &= (u16)~(4|0x3000);
}

static inline void G3X_AlphaBlend(int enable)
{
    if(enable) REG3D=(u16)((REG3D & ~0x3000)|8);
    else REG3D &= (u16)~(8|0x3000);
}

static inline void G3X_EdgeMarking(int enable)
{
    if(enable) REG3D=(u16)((REG3D & ~0x3000)|32);
    else REG3D &= (u16)~(32|0x3000);
}

void func_021BB0D4(void)
{
    u32 i;
    BG_SYS_SetMainPlaneVisible(1,1);
    G2_SetBG0Priority(0);
    G3X_SetShading(GX_SHADING_HIGHLIGHT);
    G3X_AntiAlias(0);
    G3X_AlphaTest(0,0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(0);
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,32767,63,0);
    *(volatile u32 *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((u8)i,(const u16 *)(&rects[i]));
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
