/*
 * file:     intro_cmd.c
 * unit:     yes
 * function: func_021BE328, func_021BE360, func_021BE374, func_021BE398, func_021BE3A4, func_021BE3B8, func_021BE3CC, func_021BE3DC, func_021BE3EC, func_021BE420, func_021BE430, func_021BE44C, func_021BE460, func_021BE478, func_021BE4AC, func_021BE4B8, func_021BE510, func_021BE524, func_021BE54C, func_021BE560, func_021BE578, func_021BE61C, func_021BE6A4, func_021BE6B4, func_021BE6E8, func_021BE6F8, func_021BE708, func_021BE770, func_021BE78C, func_021BE7A8, func_021BE838, func_021BE864, func_021BE874, func_021BE884, func_021BE898, func_021BE970, func_021BE984, func_021BEB00, func_021BEBEC, func_021BED6C, func_021BEDB8, func_021BEE5C, func_021BEEF0, func_021BEF08, func_021BEF20, func_021BEF74, func_021BEF88, func_021BF00C, func_021BF030, func_021BF080, func_021BF094, func_021BF0A0, func_021BF1A4, func_021BF204, func_021BF228, func_021BF23C, func_021BF2D4, func_021BF2E0, func_021BF2F4, func_021BF374, func_021BF384, func_021BF4E8, func_021BF528, func_021BF538, func_021BF55C, func_021BF560, func_021BF580, func_021BF594, func_021BF5E0, func_021BF610, func_021BF624
 * address:  0x021BE328
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   BRIGHTNESS_ChangeRequest 0x02023EF4 thumb
 *   BRIGHTNESS_IsFinished 0x02024004 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   GFL_USE_SetSeSlotVolume 0x020062BC thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 *   d_021C09D4 0x021C09D4 data a4
 *   func_021BF67C 0x021BF67C thumb ov204
 *   func_021BF7CC 0x021BF7CC thumb ov204
 *   d_021BFFE4 0x021BFFE4 data a1
 *   func_021BF720 0x021BF720 thumb ov204
 *   func_021BF744 0x021BF744 thumb ov204
 *   func_021BF77C 0x021BF77C thumb ov204
 *   func_021BF788 0x021BF788 thumb ov204
 *   func_021BF804 0x021BF804 thumb ov204
 *   func_021BF794 0x021BF794 thumb ov204
 *   SAVE_CONTROL_INTR_Start 0x021BD2B0 thumb
 *   SAVE_CONTROL_INTR_Pause 0x021BD368 thumb ov088
 *   SAVE_CONTROL_INTR_IsPausedOrFinished 0x021BD380 thumb ov088
 *   SAVE_CONTROL_INTR_Resume 0x021BD374 thumb ov088
 *   SAVE_CONTROL_INTR_NoOp 0x021BD39C thumb ov088
 *   SAVE_CONTROL_INTR_IsFinished 0x021BD3A0 thumb ov088
 *   CONFIG_SetAppliedFlag 0x020083EC thumb
 *   func_0200854C 0x0200854C thumb
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb
 *   PM_VOICE_Start  0x02006A64  thumb
 *   PM_VOICE_IsSlotActive  0x02006BD0  thumb
 *   func_021BF864  0x021BF864  thumb ov204
 *   func_0207D63C 0x0207D63C arm
 *   INTRO_PARTICLE_StartEffect 0x021BFCE8 thumb ov204
 *   func_021BFAE4 0x021BFAE4 thumb
 *   func_021BFBC8 0x021BFBC8 thumb
 *   func_021BFA40 0x021BFA40 thumb ov204
 *   func_021BFAE8 0x021BFAE8 thumb ov204
 *   func_021BFB2C 0x021BFB2C thumb ov204
 *   KEY_GetTrg 0x020362DC arm
 *   func_021BFBA0 0x021BFBA0 thumb ov204
 *   func_020411E8 0x020411E8 arm
 *   func_02040588 0x02040588 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041300 0x02041300 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02008550 0x02008550 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021BDD78 0x021BDD78 thumb ov204
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   init 0x021BFFCC data a2
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_GetActorObjMode 0x0204B6E4 arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_02030734 0x02030734 arm
 *   d_021C0AAC 0x021C0AAC data a1
 *   func_020307B0 0x020307B0 arm
 *   d_021C09D8 0x021C09D8 data a4
 *   d_021C0AB8 0x021C0AB8 data a4
 *   site 0x021C0AE4 data a1
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   TCBL_Create 0x0203101C arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02028590 0x02028590 thumb
 *   TIME_ICON_Alloc 0x0202EF60 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   func_02045B38 0x02045B38 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont  0x0203630C  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   func_020409B4 0x020409B4 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02020D10 0x02020D10 thumb
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   func_020056BC 0x020056BC thumb
 *   TIME_ICON_Start 0x0202EF98 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   site_021C0AF0 0x021C0AF0 data ov204
 *   MCSS_SetPaletteTransAdrs 0x02016024 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *   MCSS_Del 0x02015BA4 thumb
 *   MCSS_Exit 0x02014BA8 thumb
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw 0x02014D2C thumb
 *   defaultPos 0x021C08F0 data ov204
 *   func_021BF7F0 0x021BF7F0 thumb ov204
 *   MCSS_SetScale 0x02015CAC thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   MCSS_Init  0x02014B08  thumb  arm9
 *   MCSS_Add  0x020159C8  thumb  arm9
 *   MCSS_SetAnimCallback  0x02015F2C  thumb  arm9
 *   MCSS_SetTextureTransAdrs  0x02016020  thumb  arm9
 *   BRIGHTNESS_Set  0x02023F60  thumb  arm9
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 */
#include "../../matched/include/Obj25350.h"
#include "../../matched/include/Obj14608.h"
#include "../../matched/include/Obj25352.h"
#include "../../matched/include/Obj10874.h"
#include "../../matched/include/Obj25353.h"
#include "../../matched/include/Obj25354.h"
#include "../../matched/include/Obj25355.h"
#include "../../matched/include/Obj25357.h"
#include "../../matched/include/Obj25359.h"
#include "../../matched/include/Obj04609.h"
#include "../../matched/include/Obj05529.h"
#include "../../matched/include/Obj25360.h"
#include "../../matched/include/Obj14612.h"
#include "../../matched/include/Obj25361.h"
#include "../../matched/include/Obj25362.h"
#include "../../matched/include/Obj05530.h"
#include "../../matched/include/Obj25363.h"
#include "../../matched/include/Obj25365.h"
#include "../../matched/include/Obj25366.h"
#include "../../matched/include/Obj08382.h"
#include "../../matched/include/Obj25369.h"
#include "../../matched/include/Obj25370.h"
#include "../../matched/include/Obj25372.h"
#include "../../matched/include/Obj25374.h"
#include "../../matched/include/Obj03920.h"
#include "../../matched/include/Obj25376.h"
#include "../../matched/include/Obj00550.h"
#include "../../matched/include/Obj06672.h"
#include "../../matched/include/Obj08383.h"
#include "../../matched/include/Obj14616.h"
#include "../../matched/include/Obj14617.h"
#include "../../matched/include/Obj25378.h"
#include "../../matched/include/Obj14618.h"
#include "../../matched/include/Obj03921.h"
#include "../../matched/include/Obj25381.h"
#include "../../matched/include/Obj25382.h"
#include "../../matched/include/Obj06673.h"
#include "../../matched/include/Obj14620.h"
#include "../../matched/include/Obj01008.h"
#include "../../matched/include/Obj01292.h"
#include "../../matched/include/Obj08384.h"
#include "../../matched/include/Obj14621.h"
#include "../../matched/include/Obj02540.h"
#include "../../matched/include/Obj25385.h"
#include "../../matched/include/Obj25386.h"
#include "../../matched/include/Obj03358.h"
#include "../../matched/include/Obj14622.h"
#include "../../matched/include/Obj10880.h"
#include "../../matched/include/Obj14623.h"
#include "../../matched/include/Obj14624.h"
#include "../../matched/include/Obj25387.h"
#include "../../matched/include/Obj25389.h"
#include "../../matched/include/Obj14625.h"
#include "../../matched/include/Obj14626.h"
#include "../../matched/include/Obj14627.h"
#include "../../matched/include/Obj25390.h"

struct Sub0200852CObj;
struct Obj;
struct Actor;
struct WordSet;
struct Q021BF00C;
struct S021BF00C;
struct State;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct Tcbl;
struct U16Vec;
struct S02031140;
struct Rec3;
struct PrintSys;
struct Rec;
struct MsgBank;
struct Ctx;
struct Slot;
struct Src;
struct McssSys;
struct Sub150;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef enum { B_FALSE, B_TRUE } Bool;

struct S { u8 pad[0xA8]; u8 data[4096]; };

typedef struct {u16 v[12];} Init;

typedef signed int     s32;

typedef struct Row { unsigned tag; unsigned data[5]; } Row;

struct S021BF00C
{
    char pad[0x20];
    void *slots[8];
};

struct Q021BF00C
{
    char pad[0x14];
    unsigned char b : 1;
};

typedef struct Command { unsigned tag; unsigned data[5]; } Command;

typedef struct Slot { unsigned data[3]; } Slot;

typedef struct State { char pad[0x20]; Command *commands[8]; Slot slots[8]; } State;

typedef struct {
    void *arr,*b,*c,*obj;
    u16 count,rows;
    u8 f14,f15,f16;
    u8 f17lo:4,f17hi:4;
    u8 f18lo:4,f18hi:4;
    u8 f19;
    u16 f1Alo:3,f1Amid:4,f1Apad:2,f1Amid2:6,f1Atop:1;
    u32 f1c;
    u16 f20,f22;
    u32 f24;
    void *f28,*f2c,*f30;
} Config;

struct Vec { int v[3]; };

extern void FADE_Start(unsigned,int,int,int);
extern int FADE_IsActive(void);
extern void BRIGHTNESS_Set(u32 a0, u32 a1, u32 mask);
extern void BRIGHTNESS_ChangeRequest(int, int, int, int, int);
extern int BRIGHTNESS_IsFinished(int a);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern int GFL_USE_IsBgmPlaying(void);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void GFL_USE_PlaySeDefaultVolume(unsigned),GFL_USE_SetSeSlotVolume(int,unsigned),GFL_USE_SetSeSlotParams(int,unsigned,unsigned,unsigned);
extern int GFL_USE_GetSeSlot(unsigned);
extern void GFL_USE_StopSeSlot(int);
extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetTrg(void);
extern void func_021BF67C(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i);
extern void func_021BF7CC(u8 *p, u8 index, int flag);
extern void func_021BF720(u8 *p, int flag, u8 index);
extern void func_021BF744(char *p, unsigned int i, unsigned int flag, unsigned int v);
extern unsigned func_021BF77C(char *,unsigned char);
extern void func_021BF788(u8 *p, u8 index);
extern int func_021BF804(char *p, unsigned int i, int step, int limit);
extern void func_021BF794(u8 *p, u8 index, u32 alpha);
extern void SAVE_CONTROL_INTR_Start(int);
extern void SAVE_CONTROL_INTR_Pause(unsigned char *);
extern int SAVE_CONTROL_INTR_IsPausedOrFinished(unsigned char *);
extern void SAVE_CONTROL_INTR_Resume(unsigned char *p);
extern void SAVE_CONTROL_INTR_NoOp(int);
extern int SAVE_CONTROL_INTR_IsFinished(unsigned char *p);
extern void CONFIG_SetAppliedFlag(u16*,u32);
extern void func_0200854C(struct Sub0200852CObj*,u32);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern int  GFL_USE_IsAnySeBusy(void);
extern int PM_VOICE_Start(u32 idx);
extern u32 PM_VOICE_IsSlotActive(u32 i);
extern int func_021BF864(char *p, int delta, int limit);
extern void func_0207D63C(volatile void *, int, int, int, int);
extern void INTRO_PARTICLE_StartEffect(u32*,u32,u32,u32);
extern void func_021BFAE4(char *p, int v);
extern void func_021BFBC8(char *p, unsigned value);
extern int func_021BFA40(char*);
extern void func_021BFAE8(char *,u32);
extern int func_021BFB2C(char *);
extern int func_021BFBA0(int *p);
extern void func_020411E8(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02041B6C(u32);
extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern void *func_020490F4(u32 id, u32 heap);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern unsigned func_021BDD78(char *p);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
extern void CLACT_ReleaseCellAnim(unsigned);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern u32 CLACT_GetActorObjMode(const struct Actor *actor);
extern void func_0201F02C(struct WordSet*,u32,void*);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void *func_02028590(u32,u32,u32,u32);
extern struct Obj *TIME_ICON_Alloc(u32 heap);
extern int APP_KEYCURSOR_Delete(int);
extern void STRBUF_Delete(struct U16Vec *);
extern unsigned int GF_FONT_Delete(void *ptr);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern void TCBL_Destroy(struct S02031140 *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void TCBL_Main(struct Tcbl*);
extern u32 PRINTSYS_QUE_Main(struct PrintSys*);
extern signed char MSG_SPEED_GetWait(void);
extern void GF_FONT_SetTextColor(unsigned int, unsigned int, unsigned int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *PRINTSYS_PrintStream(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short, unsigned short);
extern void func_0201F73C(void *, int, int, int);
extern void func_0201F7A8(void*,u32);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamReleasePause(void *p);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);
extern void *MI_CpuFill8(void *,int,u32);
extern void *BMP_MENUWORK_Create(u32,u32);
extern void BMP_MENUWORK_AddStrItem(struct Slot *table, u32 a, u32 b, u32 tag);
extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);
extern void func_02020CF8(struct Obj *p, int heap);
extern void func_020409B4(u32 index);
extern void func_02020D10(u8 *p, u32 v);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern u32 BMP_MENUWORK_Delete(void *p);
extern int BMP_MENULIST_Main(struct Obj *);
extern u32 func_020056BC(void);
extern void TIME_ICON_Start(u8 *,u32,u32,u8,u8);
extern void TIME_ICON_Delete(u8 *);
extern void *MCSS_Init(u32 id, void *heap);
extern void MCSS_SetTextureTransAdrs(void *, unsigned int);
extern void MCSS_SetPaletteTransAdrs(char *p, unsigned int v);
extern void MCSS_SetOrthoMode(void *);
extern void MCSS_Del(void *,void *);
extern void MCSS_Exit(u8 *);
extern void MCSS_Main(char *);
extern void MCSS_Draw(struct McssSys *);
extern struct Rec *MCSS_Add(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void MCSS_SetScale(void *p, u32 *src);
extern void func_021BF7F0(u8 *p);
extern void MCSS_SetAnimCallback(void *, void *, void (*)(void *, void *), int);
int func_021BE328(char *p,int *state,int *q);
u32 func_021BE360(u32 a, u32 b, u32 *c);
int func_021BE374(int a0, int a1, int *src);
int func_021BE398(void);
u32 func_021BE3A4(u32 a, u32 b, u32 *c);
u32 func_021BE3B8(void);
int func_021BE3CC(int a, int b, int *p);
int func_021BE3DC(int a, int b, int *p);
int func_021BE3EC(char *p,int *state,unsigned *q);
int func_021BE420(int a, int b, int *p);
u32 func_021BE430(void);
int func_021BE44C(char *p,int *state,unsigned *q);
int func_021BE460(char *p,int *state,int *q);
int func_021BE478(char *p,int *state,unsigned *q);
int func_021BE4AC(char *p,int *state,int *q);
int func_021BE4B8(char *p, int unused, unsigned *q);
int func_021BE510(char *p,int *state,int *q);
int func_021BE524(char *p,int *state,unsigned *q);
unsigned func_021BE53C(char *p,int *state,unsigned *q);
int func_021BE54C(char *p,int *state,unsigned *q);
int func_021BE560(char *p,int *state,int *q);
int func_021BE578(char *p, int *state, unsigned *q);
int func_021BE61C(char *p, int *state, unsigned *q);
int func_021BE6A4(char *a);
int func_021BE6B4(char *p,int *state,unsigned *q);
int func_021BE6E8(char *a);
int func_021BE6F8(char *a);
int func_021BE708(char *p, int *state);
int func_021BE770(u8*p,u32 unused,u32*q);
int func_021BE78C(u8*p,u32 unused,u32*q);
int func_021BE7A8(u8 *p, u32 *q);
int func_021BE838(u8*p,u32 unused,u32*q);
int func_021BE864(char *a, int b, int *p);
int func_021BE874(char *a, int b, int *p);
int func_021BE884(u8*p);
int func_021BE898(char *p,u32 *q);
int func_021BE970(u8*p);
int func_021BE984(struct S *p,u32 *q);
int func_021BEB00(void *p,u32 *q);
int func_021BEBEC(char *p);
int func_021BED6C(char *p);
int func_021BEDB8(char *p, unsigned *state, unsigned *q);
int func_021BEE5C(char *p, unsigned *state, unsigned *q);
int func_021BEEF0(u8*p);
void func_021BEF08(u8*p,u32 a);
char *func_021BEF20(void *a, unsigned b, unsigned c, char *d, unsigned e, unsigned short heap);
void func_021BEF74(u8*p);
int func_021BEF88(char *p);
int func_021BF00C(struct S021BF00C *p, struct Q021BF00C *q);
int func_021BF030(State *p);
void func_021BF080(char *p, u8 i);
Row *func_021BF094(u32 n);
char *func_021BF0A0(u16 heap);
void func_021BF1A4(char *p);
void func_021BF204(char *p, unsigned a, unsigned short b);
void func_021BF228(u8*p);
void func_021BF23C(char *p, void *a, int flag);
void func_021BF2D4(u8*p);
u32 func_021BF2E0(u8*p);
int func_021BF2F4(char *a);
int *func_021BF374(char *p, int v);
void func_021BF384(char *p,u32 *entries,u32 count,int flag);
void func_021BF4E8(char *p);
void func_021BF528(u8 *p);
int func_021BF538(u8 *p,int *out);
int func_021BF55C(u8 *p);
void func_021BF560(u8 *p);
void func_021BF580(u8 *p);
void *func_021BF594(unsigned int heap, int kind);
void func_021BF5E0(u8 *p);
void func_021BF610(u8 *p);
void func_021BF624(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i);
extern const char d_021BFFE4[];
extern const Init init;
extern const char d_021C0AAC[];
extern const u32 d_021C0AB8[];
extern const char site[];
extern const char site_021C0AF0[];
extern const struct Vec defaultPos;




int func_021BE328(char *p,int *state,int *q){switch(*state){case 0:FADE_Start(q[0],q[1],q[2],q[3]);(*state)++;break;case 1:if(FADE_IsActive()==0)return 1;break;}return 0;}





/*
 * Addresses are Black-image addresses.
 */
u32 func_021BE360(u32 a, u32 b, u32 *c)
{
    BRIGHTNESS_Set((s16)*c, 0x1d, 1);
    return 1;
}





int func_021BE374(int a0, int a1, int *src)
{
    BRIGHTNESS_ChangeRequest((unsigned char)src[0], (short)src[1], (short)src[2], 0x1d, 1);
    return 1;
}




int func_021BE398(void) {BRIGHTNESS_IsFinished(1);return 1;}





u32 func_021BE3A4(u32 a, u32 b, u32 *c)
{
    GFL_USE_CancelChangeAndPlayBgm(*c, 0xffff);
    return 1;
}





u32 func_021BE3B8(void)
{
    if (GFL_USE_IsBgmPlaying() != 0) {
        return 1;
    }
    return 0;
}





int func_021BE3CC(int a, int b, int *p)
{
    GFL_USE_FadeOutBgm((unsigned short)*p);
    return 1;
}





int func_021BE3DC(int a, int b, int *p)
{
    GFL_USE_FadeInBgmFull((unsigned short)*p);
    return 1;
}




int func_021BE3EC(char *p,int *state,unsigned *q){int i;GFL_USE_PlaySeDefaultVolume(q[0]);i=GFL_USE_GetSeSlot(q[0]);if(q[1])GFL_USE_SetSeSlotVolume(i,q[1]);if(q[2])GFL_USE_SetSeSlotParams(i,-1,-1,q[2]);return 1;}





int func_021BE420(int a, int b, int *p)
{
    GFL_USE_StopSeSlot(GFL_USE_GetSeSlot(*p));
    return 1;
}





u32 func_021BE430(void)
{
    if (TOUCHPANEL_GetTrg() != 0 || KEY_GetTrg() != 0) {
        return 1;
    }
    return 0;
}




int func_021BE44C(char *p,int *state,unsigned *q){func_021BF204(*(char * *)&((struct Obj25350 *)p)->f18,q[0],q[1]);return 1;}




extern int (*const d_021C09D4[])(char *,int);




int func_021BE460(char *p,int *state,int *q){d_021C09D4[q[0]](p,q[1]);return 1;}




int func_021BE478(char *p,int *state,unsigned *q){switch(*state){case 0:func_021BF23C(*(char * *)&((struct Obj14608 *)p)->f18,(void *)q[0],q[1]);(*state)++;break;case 1:if(func_021BF2F4(*(char * *)&((struct Obj14608 *)p)->f18))return 1;break;}return 0;}




int func_021BE4AC(char *p,int *state,int *q){func_021BF2D4((u8 *)(*(char * *)&((struct Obj25352 *)p)->f18));return 1;}




int func_021BE4B8(char *p, int unused, unsigned *q)
{
    if (q[1] == 0) {
        func_021BF624(((struct Obj10874 *)p)->f8, q[2], q[3], 0, (void *)d_021BFFE4, q[0]);
        func_021BF7CC(((struct Obj10874 *)p)->f8, q[0], 1);
    } else {
        func_021BF67C(((struct Obj10874 *)p)->f8, q[2], q[3], 0x1000, q[1], q[0]);
    }
    return 1;
}




int func_021BE510(char *p,int *state,int *q){func_021BF720(((struct Obj25353 *)p)->f8,q[1],q[0]);return 1;}




/*
 * follower: tail-call stub 0x021BE53C included; function_starts seed.
 */
int func_021BE524(char *p,int *state,unsigned *q){func_021BF744(*(char * *)&((struct Obj25354 *)p)->f8,(unsigned char)q[0],q[1],q[2]);return 1;}




unsigned func_021BE53C(char *p,int *state,unsigned *q){return func_021BF77C(*(char * *)&((struct Obj25355 *)p)->f8,q[0]);}




int func_021BE54C(char *p,int *state,unsigned *q){func_021BF788((u8 *)(*(char * *)&((struct Obj25357 *)p)->f8),q[0]);return 1;}




int func_021BE560(char *p,int *state,int *q){return func_021BF804(*(char * *)&((struct Obj25359 *)p)->f8,(unsigned char)q[0],q[1],q[2]);}




int func_021BE578(char *p, int *state, unsigned *q)
{
    switch (*state) {
    case 0:
        if (q[1] != 0)
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)1);
        else
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)31);
        func_021BF720(((struct Obj04609 *)p)->f8, 1, q[0]);
        state[1] = 31;
        ++*state;
        break;
    case 1:
        state[1] -= 2;
        if (state[1] <= 0) {
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)31);
            func_021BF720(((struct Obj04609 *)p)->f8, q[1], q[0]);
            return 1;
        }
        if (q[1] == 1)
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)(31 - state[1]));
        else if (q[1] == 0)
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)state[1]);
        break;
    }
    return 0;
}




int func_021BE61C(char *p, int *state, unsigned *q)
{
    unsigned index = q[0];
    unsigned other = q[1];
    switch (*state) {
    case 0:
        func_021BF23C(((struct Obj05529 *)p)->f18, (void *)index, q[2]);
        ++*state;
        break;
    case 1:
        if (func_021BF2F4(((struct Obj05529 *)p)->f18) != 0) {
            func_021BF7CC(((struct Obj05529 *)p)->f8, other, 1);
            return 1;
        }
        switch (func_021BF2E0(((struct Obj05529 *)p)->f18)) {
        case 1:
            func_021BF7CC(((struct Obj05529 *)p)->f8, other, 1);
            state[1] = 0;
            break;
        case 0:
            func_021BF7CC(((struct Obj05529 *)p)->f8, other, state[1] % 12 < 6 ? 1 : 0);
            state[1]++;
            break;
        case 2:
            break;
        }
        break;
    }
    return 0;
}





int func_021BE6A4(char *a)
{
    SAVE_CONTROL_INTR_Start(((struct Obj25360 *)a)->fA4);
    return 1;
}




int func_021BE6B4(char *p,int *state,unsigned *q){switch(*state){case 0:SAVE_CONTROL_INTR_Pause(*(unsigned char * *)&((struct Obj14612 *)p)->fA4);(*state)++;break;case 1:if(SAVE_CONTROL_INTR_IsPausedOrFinished(*(unsigned char * *)&((struct Obj14612 *)p)->fA4)==1)return 1;break;}return 0;}





int func_021BE6E8(char *a)
{
    SAVE_CONTROL_INTR_Resume((unsigned char *)(((struct Obj25361 *)a)->fA4));
    return 1;
}





/*
 * UNBLOCKED: 0x021BD39C is now an EXACT entry in layout/matched/ov088 (the
 * only overlay in the window that does not overlap the caller's ov204), so
 * the bl site resolves as matched and the verdict promoted to EXACT.
 */
int func_021BE6F8(char *a)
{
    SAVE_CONTROL_INTR_NoOp(((struct Obj25362 *)a)->fA4);
    return 1;
}




int func_021BE708(char *p, int *state)
{
    switch (*state) {
    case 0:
        if (SAVE_CONTROL_INTR_IsFinished(((struct Obj05530 *)p)->fA4) == 1)
            return 1;
        func_021BF23C(((struct Obj05530 *)p)->f18, (void *)5, 0);
        ++*state;
        break;
    case 1:
        if (func_021BF2F4(((struct Obj05530 *)p)->f18) == 1) {
            func_021BF560(((struct Obj05530 *)p)->f18);
            ++*state;
        }
        break;
    case 2:
        if (SAVE_CONTROL_INTR_IsFinished(((struct Obj05530 *)p)->fA4) == 1) {
            func_021BF580(((struct Obj05530 *)p)->f18);
            return 1;
        }
        break;
    }
    return 0;
}




int func_021BE770(u8*p,u32 unused,u32*q){u16*obj=*(u16* *)&((struct Obj25365 *)(*(u8* *)&((struct Obj25363 *)p)->f4))->f4;Bool flag;if(*q==0)flag=B_FALSE;else flag=B_TRUE;CONFIG_SetAppliedFlag(obj,flag);return 1;}




/*
 * prototype: 0200854C widened to u32: original has no byte truncation; its u8 prototype added a shift pair.
 */
int func_021BE78C(u8*p,u32 unused,u32*q){struct Sub0200852CObj*obj=**(struct Sub0200852CObj** *)&((struct Obj25366 *)p)->f4;Bool flag;if(*q==0)flag=B_FALSE;else flag=B_TRUE;func_0200854C(obj,flag);return 1;}





int func_021BE7A8(u8 *p, u32 *q)
{
    switch (*q) {
    case 0:
        if (q[1] == 3) {
            q[1] = 0;
            (*q)++;
        } else {
            q[1] = q[1] + 1;
        }
        break;
    case 1:
        if (func_021BF864((char *)(((struct Obj08382 *)p)->f8), 0x1000, 0xFFFF4800) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x7F5);
            (*q)++;
        }
        break;
    case 2:
        if (GFL_USE_IsAnySeBusy() == 0) {
            func_021BF744((char *)(((struct Obj08382 *)p)->f8), 1, 0, 1);
            PM_VOICE_Start(*(u32 *)(((struct Obj08382 *)p)->f4 + 0x10));
            (*q)++;
        }
        break;
    case 3:
        if (PM_VOICE_IsSlotActive(*(u32 *)(((struct Obj08382 *)p)->f4 + 0x10)) == 0) {
            *q = 0;
            return 1;
        }
        break;
    }
    return 0;
}




int func_021BE838(u8*p,u32 unused,u32*q){func_0207D63C((void*)0x04000050,1,9,0,0);INTRO_PARTICLE_StartEffect(*(u32* *)&((struct Obj25369 *)p)->f10,q[0],q[1],0);return 1;}





int func_021BE864(char *a, int b, int *p)
{
    func_021BFAE4((char *)(((struct Obj25370 *)a)->fC), *p);
    return 1;
}





int func_021BE874(char *a, int b, int *p)
{
    func_021BFBC8((char *)(((struct Obj25372 *)a)->fC), *p);
    return 1;
}




int func_021BE884(u8*p){if(func_021BFA40(*(char* *)&((struct Obj25374 *)p)->fC))return 1;return 0;}




/*
 * lever: load the case-2 object once before q[1]'s comparison and reuse
 *   it in both arms; repeated arm loads gave 220 bytes/80 different.
 */
int func_021BE898(char *p,u32 *q)
{
    void *obj;
    switch (*q) {
    case 0:
        func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,0);
        *q=4;
        break;
    case 1:
        if (KEY_GetTrg()&16) {
            if (q[1]!=1) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,2);
                q[1]=1;
                *q=4;
            }
        } else if (KEY_GetTrg()&32) {
            if (q[1]!=0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,1);
                q[1]=0;
                *q=4;
            }
        } else if (KEY_GetTrg()&1) {
            GFL_USE_PlaySeDefaultVolume(0x54D);
            (*q)++;
        }
        break;
    case 2:
        obj=**(void ** *)&((struct Obj03920 *)p)->f4;
        if (q[1]==0) {
            func_0200854C(obj,0);
            func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,3);
        } else {
            func_0200854C(obj,1);
            func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,4);
        }
        (*q)++;
        break;
    case 3:
        if (func_021BFB2C(*(char * *)&((struct Obj03920 *)p)->fC)!=0) return 1;
        break;
    case 4:
        if (func_021BFB2C(*(char * *)&((struct Obj03920 *)p)->fC)!=0) *q=1;
        break;
    }
    return 0;
}





int func_021BE970(u8*p){if(func_021BFBA0((int *)(*(char* *)&((struct Obj25376 *)p)->fC)))return 1;return 0;}





/*
 * lever: unsigned integer p+0xA8 at the first paired call, member address
 *   at the second, keeps equivalent addresses apart; pointer-only was 364
 *   bytes/275 different, this spelling EXACT380 (existing distinct-arithmetic idiom).
 */
int func_021BE984(struct S *p,u32 *q)
{
    switch (*q) {
    case 0:
        func_02040588(2,1);
        func_020411E8(2,0,8,64,2,(u32)p->data,0,8,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 1:
        func_020411E8(2,0,7,64,1,(u32)p+0xA8,0,7,64,32);
        func_020411E8(2,0,10,64,1,(u32)p->data,0,10,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 2:
        func_020411E8(2,0,6,64,1,(u32)p+0xA8,0,6,64,32);
        func_020411E8(2,0,11,64,1,(u32)p->data,0,11,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 3:
        func_020411E8(2,0,5,64,1,(u32)p+0xA8,0,5,64,32);
        func_020411E8(2,0,12,64,1,(u32)p->data,0,12,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 4:
        func_020411E8(2,0,4,64,1,(u32)p+0xA8,0,4,64,32);
        func_020411E8(2,0,13,64,1,(u32)p->data,0,13,64,32);
        func_02041B6C(2);
        *q=0;
        return 1;
    }
    return 0;
}





/*
 * extent: two bytes of zero alignment at 0x021BEBEA.
 */
int func_021BEB00(void *p,u32 *q)
{
    switch (*q) {
    case 0:
        func_02041300(2,0,0,7,64,1,0);
        func_02041300(2,0,0,16,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 1:
        func_02041300(2,0,0,8,64,1,0);
        func_02041300(2,0,0,15,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 2:
        func_02041300(2,0,0,6,64,1,0);
        func_02041300(2,0,0,14,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 3:
        func_02041300(2,0,0,5,64,1,0);
        func_02041300(2,0,0,13,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 4:
        func_02040588(2,0);
        *q=0;
        return 1;
    }
    return 0;
}





int func_021BEBEC(char *p)
{
    Init local;
    void *arc;
    u32 i;
    char *row;
    arc=func_020490F4(170,((struct Obj00550 *)p)->f0);
    if(func_02008550(**(void ** *)&((struct Obj00550 *)p)->f4)==0){
        ((struct Obj00550 *)p)->f10B4=(void *)CLACT_RegisterCharacter(arc,6,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10C0=(void *)CLACT_RegisterPalette(arc,7,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10CC=(void *)CLACT_RegisterCellAnim(arc,5,4,((struct Obj00550 *)p)->f0);
    }else{
        ((struct Obj00550 *)p)->f10B4=(void *)CLACT_RegisterCharacter(arc,10,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10C0=(void *)CLACT_RegisterPalette(arc,11,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10CC=(void *)CLACT_RegisterCellAnim(arc,9,8,((struct Obj00550 *)p)->f0);
    }
    ((struct Obj00550 *)p)->f10B8=(void *)CLACT_RegisterCharacter(arc,17,0,0,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10C4=(void *)CLACT_RegisterPalette(arc,18,0,32,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10D0=(void *)CLACT_RegisterCellAnim(arc,16,15,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10BC=(void *)CLACT_RegisterCharacter(arc,21,0,0,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10C8=(void *)CLACT_RegisterPalette(arc,22,0,64,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10D4=(void *)CLACT_RegisterCellAnim(arc,20,19,((struct Obj00550 *)p)->f0);
    ARC_TOOL_DeleteHandle(arc);
    local=init;
    for(i=0;i<3;i++){
        row=p+i*4;
        ((struct Obj06672 *)row)->f10A8=CLACT_CreateActor((void *)func_021BDD78(((struct Obj00550 *)p)->f14),(unsigned int)((struct Obj06672 *)row)->f10B4,(unsigned int)((struct Obj06672 *)row)->f10C0,(unsigned int)((struct Obj06672 *)row)->f10CC,(char *)&local+i*8,0,((struct Obj00550 *)p)->f0);
        CLACT_SetActorDrawEnable(((struct Obj06672 *)row)->f10A8,0);
    }
    return 1;
}





int func_021BED6C(char *p)
{
    unsigned i;
    for (i = 0; i < 3; i++) {
        char *q = p + i * 4;
        CLACT_ReleaseCharacter(((struct Obj08383 *)q)->f10B4);
        CLACT_ReleasePalette(((struct Obj08383 *)q)->f10C0);
        CLACT_ReleaseCellAnim(((struct Obj08383 *)q)->f10CC);
        CLACT_DeleteActor(((struct Obj08383 *)q)->f10A8);
    }
    return 1;
}





static inline void change_alpha(int a, int b)
{
    *(volatile unsigned short *)0x04000052 = (unsigned short)(a | (b << 8));
}





int func_021BEDB8(char *p, unsigned *state, unsigned *q)
{
    unsigned i;
    switch (*state) {
    case 0:
        func_0207D63C((volatile void *)0x04000050, 0, 12, 0, 16);
        CLACT_SetActorObjMode(*(void **)(p + 0x10a8 + q[0] * 4), 1);
        CLACT_SetActorDrawEnable(*(void **)(p + 0x10a8 + q[0] * 4), 1);
        ++*state;
        break;
    case 16:
        for (i = 0; i < 3; i++) {
            char *row = p + i * 4;
            if (CLACT_GetActorObjMode(((struct Obj14616 *)row)->f10A8) == 1)
                CLACT_SetActorObjMode(((struct Obj14616 *)row)->f10A8, 0);
        }
        *state = 0;
        return 1;
    default:
        ++*state;
        change_alpha(*state, 16 - *state);
        break;
    }
    return 0;
}





/*
 * volatile: hardware BLDALPHA write at 021BEEDC.
 */
int func_021BEE5C(char *p, unsigned *state, unsigned *q)
{
    unsigned i;
    switch (*state) {
    case 0:
        func_0207D63C((volatile void *)0x04000050, 0, 12, 16, 0);
        for (i = 0; i < 3; i++)
            CLACT_SetActorObjMode(*(void **)(p + 0x10a8 + i * 4), 1);
        ++*state;
        break;
    case 16:
        for (i = 0; i < 3; i++) {
            char *row = p + i * 4;
            CLACT_SetActorObjMode(((struct Obj14617 *)row)->f10A8, 0);
            CLACT_SetActorDrawEnable(((struct Obj14617 *)row)->f10A8, 0);
        }
        *state = 0;
        return 1;
    default:
        ++*state;
        change_alpha(16 - *state, *state);
        break;
    }
    return 0;
}





int func_021BEEF0(u8*p){if(!func_02008550(**(struct Sub0200852CObj** *)&((struct Obj25378 *)p)->f4))return 1;return 0;}





void func_021BEF08(u8*p,u32 a){struct WordSet*q=(struct WordSet *)func_021BF55C(*(u8* *)&((struct Obj14618 *)p)->f18);func_0201F02C(q,a,**(void** *)&((struct Obj14618 *)p)->f4);}





char *func_021BEF20(void *a, unsigned b, unsigned c, char *d, unsigned e, unsigned short heap)
{
    char *p = func_02030734(heap, 0x10d8, 1, d_021C0AAC, 0x6f2);
    ((struct Obj03921 *)p)->f0 = heap;
    *(char * *)&((struct Obj03921 *)p)->f4 = d;
    ((struct Obj03921 *)p)->f8 = c;
    ((struct Obj03921 *)p)->fC = a;
    ((struct Obj03921 *)p)->f10 = b;
    ((struct Obj03921 *)p)->f14 = e;
    ((struct Obj03921 *)p)->fA4 = ((struct Obj25381 *)d)->fC;
    ((struct Obj03921 *)p)->f18 = func_021BF0A0(heap);
    return p;
}





void func_021BEF74(u8*p){func_021BF1A4(*(char* *)&((struct Obj25382 *)p)->f18);func_020307B0(p);}





extern int (*const d_021C09D8[])(void *, void *, void *);





int func_021BEF88(char *p)
{
    func_021BF228(((struct Obj06673 *)p)->f18);
    if (func_021BF030((struct State *)p) == 0) {
        char *base = p;
        int i;
        base += 0x40;
        for (i = 0; i < 9; i++) {
            Row *row = func_021BF094(((struct Obj06673 *)p)->f1C) + ((struct Obj06673 *)p)->fA0;
            if (row->tag == 1) {
                d_021C09D8[row->tag](p, base + i * 12, row->data);
                row = func_021BF094(((struct Obj06673 *)p)->f1C);
            }
            if (row->tag == 0x34)
                return 0;
            ++((struct Obj06673 *)p)->fA0;
            if (!func_021BF00C((struct S021BF00C *)p, (struct Q021BF00C *)row))
                break;
        }
    }
    return 1;
}






int func_021BF00C(struct S021BF00C *p, struct Q021BF00C *q)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (p->slots[i] == 0)
        {
            p->slots[i] = q;
            break;
        }
    }
    return q->b;
}



extern int (*const d_021C09D8[])(void *, void *, void *);



int func_021BF030(State *p)
{
    int result = 0;
    int i;
    for (i = 0; i < 8; i++) {
        Command *q = p->commands[i];
        if (q) {
            if (!d_021C09D8[q->tag](p, &p->slots[i], q->data)) result = 1;
            else func_021BF080((char *)p, i);
        }
    }
    return result;
}




void func_021BF080(char *p, u8 i)
{
    char *q;

    *(int *)(p + i * 4 + 0x20) = 0;
    q = p + i * 0xC;
    ((struct Obj14620 *)q)->f40 = 0;
    ((struct Obj14620 *)q)->f44 = 0;
}



Row *func_021BF094(u32 n){return *(Row **)((u32)d_021C0AB8+n*4);}



char *func_021BF0A0(u16 heap)
{
    char *p;
    void *obj;
    p=func_02030734(heap,72,1,site,129);
    ((struct Obj01008 *)p)->f0=heap;
    ((struct Obj01008 *)p)->f8=GF_FONT_Create_EC64(heap);
    ((struct Obj01008 *)p)->f4=(void *)PRINTSYS_QUE_Create((void *)heap);
    ((struct Obj01008 *)p)->f18=TCBL_Create(((struct Obj01008 *)p)->f0,((struct Obj01008 *)p)->f0,2,0);
    func_02049B40(23,5,0,320,32,heap);
    func_0201F5BC(1,7,9,0,heap);
    func_0201F5BC(1,16,8,1,heap);
    ((struct Obj01008 *)p)->f10=GF_FONT_Create(23,0,1,0,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f3C=STRBUF_Create(1600,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f40=STRBUF_Create(1600,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f38=(void *)BMP_WIN_Create(1,22,13,9,4,10,1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj01008 *)p)->f38),0);
    obj=((struct Obj01008 *)p)->f38;
    BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_02041B6C(BMP_WIN_GetBgLayer(obj));
    ((struct Obj01008 *)p)->f1C=(void *)BMP_WIN_Create(1,1,19,30,4,10,1);
    ((struct Obj01008 *)p)->f20=func_02028590(15,1,1,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f44=TIME_ICON_Alloc(((struct Obj01008 *)p)->f0);
    return p;
}



void func_021BF1A4(char *p)
{
    func_021BF580((u8 *)p);
    APP_KEYCURSOR_Delete(((struct Obj01292 *)p)->f20);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01292 *)p)->f3C);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01292 *)p)->f40);
    GF_FONT_Delete(((struct Obj01292 *)p)->f10);
    if (((struct Obj01292 *)p)->f14 != 0)
        PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj01292 *)p)->f14));
    BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj01292 *)p)->f1C);
    if (((struct Obj01292 *)p)->f38)
        BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj01292 *)p)->f38);
    TCBL_Destroy(*(struct S02031140 * *)&((struct Obj01292 *)p)->f18);
    PRINTSYS_QUE_Delete(((struct Obj01292 *)p)->f4);
    if (((struct Obj01292 *)p)->fC)
        MSGDATA_Delete(((struct Obj01292 *)p)->fC);
    WORDSET_DeleteStrbufED04(((struct Obj01292 *)p)->f8);
    func_020307B0(p);
}



void func_021BF204(char *p, unsigned a, unsigned short b)
{
    if (((struct Obj08384 *)p)->fC != 0)
    {
        MSGDATA_Delete(((struct Obj08384 *)p)->fC);
    }
    ((struct Obj08384 *)p)->fC = func_02045B38(a, 2, b, ((struct Obj08384 *)p)->f0);
}


void func_021BF228(u8*p){TCBL_Main(*(struct Tcbl* *)&((struct Obj14621 *)p)->f18);PRINTSYS_QUE_Main(*(struct PrintSys* *)&((struct Obj14621 *)p)->f4);}



/*
 * Caller consumes 0201CCE4's live r0 result; return declared pointer despite callee's void source.
 */
void func_021BF23C(char *p, void *a, int flag)
{
    unsigned int value = MSG_SPEED_GetWait();
    void *desc = ((struct Obj02540 *)p)->f1C;
    BMP_Clear(BMP_WIN_GetBmp(desc), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    func_02045CAC(((struct Obj02540 *)p)->fC, (unsigned int)a, ((struct Obj02540 *)p)->f3C);
    func_0201F250(((struct Obj02540 *)p)->f8, ((struct Obj02540 *)p)->f40, ((struct Obj02540 *)p)->f3C);
    ((struct Obj02540 *)p)->f14 = PRINTSYS_PrintStream((unsigned int)desc, 4, 0, *(unsigned int *)&((struct Obj02540 *)p)->f40, ((struct Obj02540 *)p)->f10, value, ((struct Obj02540 *)p)->f18, 0xFFFF, ((struct Obj02540 *)p)->f0, 15);
    if (flag == 0)
        func_0201F73C(desc, 1, 7, 9);
    else
        func_0201F73C(desc, 1, 16, 8);
    BMP_WIN_TransferChars(desc);
    BMP_WIN_MakeScreen(desc);
    func_02041B6C(BMP_WIN_GetBgLayer(desc));
}


void func_021BF2D4(u8*p){func_0201F7A8(*(void* *)&((struct Obj25385 *)p)->f1C,0);}


u32 func_021BF2E0(u8*p){u32 a=((struct Obj25386 *)p)->f14;if(a==0){return 2;}else{return PRINTSYS_PrintStreamGetState((void *)a);}}



int func_021BF2F4(char *a)
{
    if (((struct Obj03358 *)a)->f14 != 0) {
        APP_KEYCURSOR_Update((struct Ctx *)(((struct Obj03358 *)a)->f20), (void *)(((struct Obj03358 *)a)->f14),
                      (void *)(((struct Obj03358 *)a)->f1C));

        switch (PRINTSYS_PrintStreamGetState((void *)(((struct Obj03358 *)a)->f14))) {
        case 2:
            PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj03358 *)a)->f14));
            ((struct Obj03358 *)a)->f14 = 0;
            return 1;
        case 1:
            if (KEY_GetTrg() == 1 || KEY_GetTrg() == 2
                || TOUCHPANEL_GetTrg() != 0) {
                PRINTSYS_PrintStreamReleasePause((void *)(((struct Obj03358 *)a)->f14));
                GFL_USE_PlaySeDefaultVolume(0x547);
            }
            break;
        case 0:
            if ((KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0)
                PRINTSYS_PrintStreamShortWait((struct Rec *)(((struct Obj03358 *)a)->f14), 0);
            break;
        }
        return 0;
    }
    return 0;
}



int *func_021BF374(char *p, int v)
{
    ((struct Obj14622 *)p)->f30 = v;
    ((struct Obj14622 *)p)->f34 = 0;
    return (int *)(p + 0x30);
}


/*
 * Owner unit_02045C44.c omits func_02045CAC from function:; singleton TU
 * --suggest-split leaves this caller out. the integrator owns that unit.
 * prior fixed-flag ARM9-45CAC.log, using the owner's unit declarations:
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest) {
 *   u32 size; struct MsgEntry *e;
 *   if (index >= bank->file->count) { STRBUF_Clear(dest); return; }
 *   func_02046180(bank);
 *   if (bank->resident == 0) {
 *     u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *     func_0204960C(bank->stream, pos + (index * 8 + 4));
 *     ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache); e = &bank->cache;
 *   } else { e = (struct MsgEntry *)((u8 *)bank->base + 4) + index; }
 *   if (bank->resident == 0) {
 *     void *buf; size = e->len * 2;
 *     buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),
 *                       size, 0, MSGDATA_AllocSite, 0xd6);
 *     if (buf != 0) {
 *       func_0204960C(bank->stream, e->off + (bank->origin
 *                     + bank->file->langOff[bank->langIndex]));
 *       ARC_TOOL_ReadHandle(bank->stream, size, buf);
 *       STRBUF_SetChars(dest, buf, e->len); func_020307B0(buf);
 *     }
 *   } else { STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len); }
 *   func_02045E04(dest, index);
 * }
 * lever: u16 heap local places its word home at sp+8; u32 swaps it with
 * the entry pointer at sp+12, leaving seven differing concrete bytes.
 */
void func_021BF384(char *p,u32 *entries,u32 count,int flag)
{
    Config config;
    char *state;
    void *obj;
    u16 heap;
    u32 i;
    state=p+36;
    heap=*(u16 *)p;
    obj=*(void **)(p+56);
    MI_CpuFill8(state,0,12);
    *(void **)(state+4)=BMP_MENUWORK_Create(count,heap);
    for(i=0;i<count;i++){
        func_02045CAC(*(void **)(p+12),*(u32 *)((char *)entries+i*8),*(void **)(p+60));
        BMP_MENUWORK_AddStrItem((struct Slot *)((char *)*(void **)(state+4)+i*8),*(u32 *)(p+60),*(u32 *)((char *)entries+i*8+4),heap);
    }
    MI_CpuFill8(&config,0,52);
    config.arr=*(void **)(state+4);config.obj=obj;
    config.count=count;config.rows=5;config.f14=0;config.f15=16;config.f16=0;
    config.f17lo=2;config.f17hi=1;config.f18lo=15;config.f18hi=2;
    config.f1Alo=0;config.f1Amid=0;config.f1Apad=1;config.f1Amid2=0;config.f1Atop=0;
    config.f1c=0;config.f20=16;config.f22=16;config.f24=0;
    config.f28=func_021BF374(p,(int)obj);config.f2c=*(void **)(p+4);config.f30=*(void **)(p+16);
    *(void **)state=BMP_MENULIST_Create((struct Src *)(&config),0,0,heap);
    func_02020CF8(*(void **)state,(u32)heap);
    BMP_WIN_TransferChars(obj);BMP_WIN_MakeScreen(obj);func_020409B4((u8)BMP_WIN_GetBgLayer(obj));
    func_0201F73C(obj,1,7,9);
    if(flag)func_02020D10(*(void **)state,0);
    else func_02020D10(*(void **)state,1);
}



/*
 * Trailing two bytes are zero alignment padding.
 */
void func_021BF4E8(char *p)
{
    char *block = p + 0x24;
    func_0201F7A8(((struct Obj10880 *)p)->f38, 0);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj10880 *)p)->f38), 0);
    BMP_WIN_TransferChars(((struct Obj10880 *)p)->f38);
    BMP_MENULIST_Delete(((struct Obj14623 *)block)->f0, 0, 0);
    BMP_MENUWORK_Delete(((struct Obj14623 *)block)->f4);
    MI_CpuFill8(block, 0, 12);
}


void func_021BF528(u8 *p)
{
    u8 *q=p+36;
    ((struct Obj14624 *)q)->f8=BMP_MENULIST_Main(*(struct Obj * *)&((struct Obj14624 *)q)->f0);
}



/*
 * lever: A switch with -1 before -2 preserves the outlined return order.
 */
int func_021BF538(u8 *p,int *out)
{
    int v=((struct Obj25387 *)p)->f2C;
    switch(v){case -1:return 0;case -2:return 2;}
    if(out!=0)*out=v;
    return 1;
}



int func_021BF55C(u8 *p)
{
    return ((struct Obj25389 *)p)->f8;
}


void func_021BF560(u8 *p)
{
    TIME_ICON_Start(*(u8 * *)&((struct Obj14625 *)p)->f44,func_020056BC(),((struct Obj14625 *)p)->f1C,15,16);
}


void func_021BF580(u8 *p)
{
    if(*(u8 * *)&((struct Obj01292 *)p)->f44!=0){TIME_ICON_Delete(*(u8 * *)&((struct Obj01292 *)p)->f44);*(u8 * *)&((struct Obj01292 *)p)->f44=0;}
}



void *func_021BF594(unsigned int heap, int kind)
{
    char *p = func_02030734(heap, 108, 1, site_021C0AF0, 98);
    *(void **)(p + 4) = MCSS_Init(8, (void *)heap);
    *(unsigned short *)p = heap;
    if (kind != 7)
        MCSS_SetTextureTransAdrs(*(void **)(p + 4), 7 << 16);
    MCSS_SetPaletteTransAdrs(*(void **)(p + 4), 1 << 14);
    MCSS_SetOrthoMode(*(void **)(p + 4));
    return p;
}


void func_021BF5E0(u8 *p)
{
    int i;
    for(i=0;i<8;i++)if(*(void **)((u32)p+(u32)i*12+8)!=0)MCSS_Del(((struct Obj14626 *)p)->f4,*(void **)((u32)p+(u32)i*12+8));
    MCSS_Exit(*(u8 * *)&((struct Obj14626 *)p)->f4);
    func_020307B0(p);
}


void func_021BF610(u8 *p)
{
    MCSS_Main(*(char * *)&((struct Obj14627 *)p)->f4);
    MCSS_Draw(*(struct McssSys * *)&((struct Obj14627 *)p)->f4);
}



/*
 * Enum zero preserves the clear before the indexed base add.
 */
void func_021BF624(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i)
{
    struct Vec pos = defaultPos;
    char *base = p + 8;
    unsigned int off = i * 12;
    enum { Zero } zero;
    *(void **)(base + off) = MCSS_Add(((struct Obj25390 *)p)->f4, a, b, c, d);
    MCSS_SetScale(*(void **)(base + off), (u32 *)(&pos));
    zero = Zero;
    *(unsigned int *)(p + off + 12) = zero;
    *(unsigned int *)(p + off + 16) = 1;
    MCSS_SetAnimCallback(*(void **)(base + off), base + off, (void (*)(void *, void *))func_021BF7F0, 0);
}
