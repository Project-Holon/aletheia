/*
 * file:     shinka_demo.c
 * unit:     yes
 * function: func_02203FA0, func_02204098, func_022040E0, func_02204C24, func_02204D5C, func_02204DC4, func_02204DDC, func_02204DE0, func_02204EA0, func_02204EB0, func_02204ED0, func_02204EF0, func_02204F00, func_02204F24, func_02204F40, func_02204F68, func_02204F78, func_02204F90, func_02204FA0, func_02204FC4, func_02204FD4, func_02204FF8, func_02205010, func_0220506C, func_02205070, func_02205100, func_02205138, func_02205168, func_022051A8, func_022051FC, func_022052E8, func_02205340, func_02205360, func_02205384, func_022053E8, func_0220546C, func_0220549C, func_022054E8, func_02205530, func_02205580, func_022055BC, func_02205620, func_022056E8, func_02205844, func_02205854
 * address:  0x02203FA0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_02017E1C 0x02017E1C thumb
 *   sub_02030734 0x02030734 arm
 *   func_0204E720 0x0204E720 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   PROCSYS_Create 0x02031324 arm
 *   func_0203D34C 0x0203D34C arm
 *   d_02208F40 0x02208F40 data a4
 *   PROCSYS_Delete 0x0203133C arm
 *   sub_02030EAC 0x02030EAC arm
 *   sub_020307B0 0x020307B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   PROCSYS_Main 0x02031330 arm
 *   PROCSYS_Push 0x02031348 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0200873C 0x0200873C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_02012F2C 0x02012F2C thumb
 *   POKE_TOOL_ChangeSpecies 0x020178D8 thumb
 *   func_020181F4 0x020181F4 thumb
 *   POKE_TOOL_GetLevelUpMove 0x02018328 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02021518 0x02021518 thumb
 *   func_02021540 0x02021540 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020215A0 0x020215A0 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   GAME_BEACON_SetPokeEvolution 0x020272A4 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02030D28 0x02030D28 arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B6DC0 0x021B6DC0 thumb ov067
 *   func_021B709C 0x021B709C thumb ov067
 *   func_021B70F4 0x021B70F4 thumb ov067
 *   func_021B72DC 0x021B72DC thumb ov067
 *   func_021B7378 0x021B7378 thumb ov067
 *   func_021B76B0 0x021B76B0 thumb ov067
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   ov131_id 0x00000083 data a1
 *   ov196_id 0x000000C4 data a1
 *   ov198_id 0x000000C6 data a1
 *   func_0220F3E8 0x0220F3E8 thumb ov198
 *   func_022059FC 0x022059FC thumb ov195
 *   func_02205A10 0x02205A10 thumb ov195
 *   func_02205A1C 0x02205A1C thumb ov195
 *   func_02205A28 0x02205A28 thumb ov195
 *   func_02205A34 0x02205A34 thumb ov195
 *   func_02205A84 0x02205A84 thumb ov195
 *   func_02205D50 0x02205D50 thumb ov195
 *   func_0220602C 0x0220602C thumb ov195
 *   func_02206044 0x02206044 thumb ov195
 *   func_0220604C 0x0220604C thumb ov195
 *   func_02206050 0x02206050 thumb ov195
 *   func_02206058 0x02206058 thumb ov195
 *   func_0220605C 0x0220605C thumb ov195
 *   func_02206064 0x02206064 thumb ov195
 *   func_0220606C 0x0220606C thumb ov195
 *   func_02206070 0x02206070 thumb ov195
 *   func_02206074 0x02206074 thumb ov195
 *   func_02206078 0x02206078 thumb ov195
 *   func_0220878C 0x0220878C thumb ov195
 *   func_02208804 0x02208804 thumb ov195
 *   func_02208814 0x02208814 thumb ov195
 *   func_0220882C 0x0220882C thumb ov195
 *   func_02208844 0x02208844 thumb ov195
 *   func_02208850 0x02208850 thumb ov195
 *   func_02208860 0x02208860 thumb ov195
 *   ov067_id 0x00000043 data
 *   func_0203064C 0x0203064C arm
 *   func_02040588 0x02040588 arm
 *   func_0204047C 0x0204047C arm
 *   func_02040EBC 0x02040EBC arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_022058F8 0x022058F8 thumb ov195
 *   func_02205C74 0x02205C74 thumb ov195
 *   func_0220871C 0x0220871C thumb ov195
 *   func_02208770  0x02208770  thumb
 *   func_02205D28  0x02205D28  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_022059A0  0x022059A0  thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   func_02005F38 0x02005F38 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GFL_USE_StepBgmLoad 0x020063B4 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   d_02208C4C 0x02208C4C data a4
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   func_0204B98C  0x0204B98C  arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0203101C 0x0203101C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02028590 0x02028590 thumb
 *   func_02028604 0x02028604 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02031140 0x02031140 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020310C4 0x020310C4 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_02006238 0x02006238 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CD10 0x0201CD10 thumb
 *   func_0203630C  0x0203630C  arm
 *   func_02035C38  0x02035C38  arm
 *   func_02035C60  0x02035C60  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   d_020A7370 0x020A7370 data a4
 *   func_0201292C 0x0201292C thumb
 *   func_0201AA14 0x0201AA14 thumb
 *   func_02007F68 0x02007F68 thumb
 *   func_02007F1C 0x02007F1C thumb
 *   func_020173EC 0x020173EC thumb
 *   func_02019CE0 0x02019CE0 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_02008F08 0x02008F08 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   d_02208CCC 0x02208CCC data a4
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 */
#include "../../matched/include/Obj00734.h"
#include "../../matched/include/Obj05515.h"
#include "../../matched/include/Obj08345.h"
#include "../../matched/include/Obj24942.h"
#include "../../matched/include/Obj24943.h"
#include "../../matched/include/Obj03902.h"
#include "../../matched/include/Obj24944.h"
#include "../../matched/include/Obj14523.h"
#include "../../matched/include/Obj24946.h"
#include "../../matched/include/Obj10816.h"
#include "../../matched/include/Obj08346.h"
#include "../../matched/include/Obj14525.h"
#include "../../matched/include/Obj24949.h"
#include "../../matched/include/Obj14527.h"
#include "../../matched/include/Obj08347.h"
#include "../../matched/include/Obj01971.h"
#include "../../matched/include/Obj14528.h"
#include "../../matched/include/Obj04593.h"
#include "../../matched/include/Obj04594.h"
#include "../../matched/include/Obj00844.h"
#include "../../matched/include/Obj02240.h"
#include "../../matched/include/Obj06642.h"
#include "../../matched/include/Obj01429.h"
#include "../../matched/include/Obj10819.h"
#include "../../matched/include/Obj03344.h"
#include "../../matched/include/Obj04595.h"
#include "../../matched/include/Obj03903.h"
#include "../../matched/include/Obj06644.h"
#include "../../matched/include/Obj24950.h"

#define W(n) (*(u32 *)(s+(n)))
#define P(n) (*(void **)(s+(n)))
#define H(n) (*(u16 *)(s+(n)))
#define B(n) (*(u8 *)(s+(n)))
#define A(n) (*(u32 *)(a+(n)))
#define AH(n) (*(u16 *)(a+(n)))
#define AB(n) (*(u8 *)(a+(n)))
#define REG_BG0CNT     (*(volatile u16 *)0x04000008)
#define REG_DISP3DCNT  (*(volatile u16 *)0x04000060)
#define REG_VIEWPORT   (*(volatile u32 *)0x04000580)
struct Obj0203159C;
struct U16Vec;
struct App;
struct Scene;
struct S020314B8;
struct S020315D4;
struct Node;
struct Anim;
struct Big;
struct Blk37;
struct Ctx;
struct Obj02021EE4;
struct Owner;
struct PalAnmSlot;
struct PrintSys;
struct S;
struct Sub02008700Obj;
struct Sub02008C20Obj;
struct GfFont;
struct Obj;
struct Actor;
struct S02021D50;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Tcbl;
struct Rec3;
struct S02031140;
struct Rec;
struct WordSet;
struct BigObj;
struct RecDC;
struct Party;
struct PartyMon;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct App {
    u8 pad00[8];
    u16 f08;
    u8 f0a;
    u8 f0b;
    u8 pad0c[4];
    u32 f10;
} App;

typedef struct Scene {
    u16 pad00;
    u16 heap;
    void *f04;
    u32 f08;
    void *f0c;
    void *f10;
    u8 pad14[0x28 - 0x14];
    u32 f28;
    u8 pad2c[0x60 - 0x2c];
    u32 f60;
    u8 pad64[0x9c - 0x64];
    u32 f9c;
    u8 padA0[0x104 - 0xa0];
    void *f104;
    void *f108;
} Scene;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u32 kind;
    u32 val;
} Param;

extern void sub_0203064C(u32 src, u32 dst, u32 size);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,u32,u32);
extern void *POKEPARTY_GetMember(void *,u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern u32 func_02017E1C(void *,u32,u32);
extern void *sub_02030734(u32,u32,int,const char *,u16);
extern void func_0204E720(u32,int,int,int);
extern void *GFL_USE_AddMainTask(u32,u32,u32);
extern void *PROCSYS_Create(int a0);
extern void func_0203D34C(u32,u32);
extern void PROCSYS_Delete(struct S020314B8 *);
extern void sub_02030EAC(struct Node *);
extern u32 sub_020307B0(void *p);
extern void STRBUF_Delete(struct U16Vec *);
extern void PROCSYS_FreeProcWork(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
extern u32 PROCSYS_Main(void *);
/* Original explicitly prepares all four registers, despite the current forwarding own source. */
extern void PROCSYS_Push(void *,int,void *,void *);
extern void func_020061E4(u32);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void *func_02012EBC(struct Big *p);
extern void *func_02012F2C(int *p);
extern void POKE_TOOL_ChangeSpecies(void *,u32);
extern void func_020181F4(void *,u16,u32);
extern u16 POKE_TOOL_GetLevelUpMove(void *,u32 *,u32);
extern u32 func_0201AA18(void *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02021518(u32);
extern u32 func_02021540(void *a0);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
/* Caller narrows only r0; r1 retains the full word, copied to the callee's u16 store. */
extern void GAME_BEACON_SetPokeEvolution(u16,u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 func_020307B0(void *p);
extern u32 func_02030CB0(u32);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_02030D28(struct Ctx *c);
extern void func_02030DA4(void *);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern u8 func_020355C4(void);
extern void func_020355D8(u32);
extern u32 func_020362DC(void);
extern int func_0204E804(void);
extern void *func_021B6DC0(u16,u32,u32,u32,u8,u32,u32,u32,u32);
extern void func_021B709C(u8 *p);
extern void func_021B70F4(struct S *s, u32 a1, u32 a2);
extern void func_021B72DC(struct S *s);
extern void func_021B7378(struct S *p);
extern int func_021B76B0(struct S *p);
extern void func_0220F3E8(u8 *);
extern void func_022059FC(char *a);
extern void func_02205A10(char *a);
extern void func_02205A1C(char *a);
extern void func_02205A34();
extern void func_02205A84(int a0);
extern void func_02205D50(char *p);
extern void func_0220602C(struct Owner *o);
extern int func_02205A28(char *a);
extern void func_02206044(int *p);
extern void func_02206050(int *p);
extern void func_0220605C(int *p);
extern void func_02206064(int *p);
extern void func_0220878C(struct Anim *p);
extern void func_02208804(char *a);
extern void func_02208814(char *a);
extern void func_0220882C(int *p);
extern void func_02208844(int *p);
extern int func_0220604C(int *p);
extern int func_02206058(int *p);
extern int func_0220606C(int *p);
extern int func_02206070(int *p);
extern int func_02206074(int *p);
extern int func_02206078(int *p);
extern int func_02208850(int *p);
extern int func_02208860(int *p);
extern void func_0203064C(u32 parent, u32 id, u32 size);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_0207D63C(int, int, int, int, int);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern char *func_022058F8(u32 a, u32 b);
extern struct Owner *func_02205C74(u16 heap, u32 f08, void *res0, u16 f0c);
extern struct Anim *func_0220871C(u16 heap, u32 x);
extern void func_02208770(char *a);
extern void func_02205D28(char *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_022059A0(char *p);
extern void GFL_USE_FadeOutBgm(u32);
extern int GFL_USE_IsBgmFading(void);
extern int func_02005F38(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern u32 GFL_USE_StepBgmLoad(u8 *a0, u32 *a1, u32 a2);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *);
extern void func_020409B4(u32 index);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(u32);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void CLACT_SetActorAnimIndex(int, int);
extern u32 func_0204B98C(struct Actor *a);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, int value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern u32 func_02028590(int, int, int, u16);
extern int func_02028604(int);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02031140(struct S02031140 *p);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020310C4(struct Tcbl *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern int func_02006238(void);
extern signed char func_02012FFC(void);
extern struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern u32 func_0201CE30(void *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *p);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern int func_02035C60(void);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_0201AA14(void *p);
extern u32 func_02007F68(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_020173EC(void);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void *func_02008F08(int a0);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0207DC44(int, int, int, int);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void func_02046BE0(u32 a, u32 b);
int func_02203FA0(struct Obj0203159C *owner,int unused,u8 *app);
int func_02204098(struct S020315D4 *a, int unused, int b, int *p);
int func_022040E0(int unused0,int unused1,char *a,char *s);
void func_02204C24(App *a, Scene *s);
void func_02204D5C(int a, int *p);
void func_02204DC4(u8 *p, u8 *q);
void func_02204DDC(int a0, int *a1);
void func_02204DE0(char *a, char *b);
int func_02204EA0(int a, int *p);
void func_02204EB0(char *a, char *b);
void func_02204ED0(int a, int *p);
int func_02204EF0(int a, int *p);
void func_02204F00(int unused, char *p);
void func_02204F24(int a, int *b);
void func_02204F40(int a, int *p);
int func_02204F68(int a, int *p);
void func_02204F78(int a, char *b);
int func_02204F90(int a, char *b);
void func_02204FA0(int a, int *p);
int func_02204FC4(int a, int *p);
void func_02204FD4(int a, int *p);
void func_02204FF8(int a, char *b);
void func_02205010(int a, char *b);
void func_0220506C(int a0, int *a1);
void func_02205070(int a, char *b);
void func_02205100(void *unused,char *p);
void func_02205138(int a, int *p);
int func_02205168(int a, int *p);
void func_022051A8(int task, char *p);
void func_022051FC(int a, char *b);
void func_022052E8(int task, int *p);
void func_02205340(int a, char *b);
int func_02205360(int a);
void func_02205384(char *a, u32 b, u32 c, u32 d, u32 k0, u32 v0, u32 k1, u32 v1);
int func_022053E8(char *a);
int func_0220546C(char *s);
void func_0220549C(char *a, int b);
void func_022054E8(int a, int *p, int flag);
void func_02205530(int a, char *b);
void func_02205580(void *unused,char *p);
void func_022055BC(char *a, u32 a1, u32 a2, u32 k0, u32 v0, u32 k1, u32 v1, u32 b1, u32 b2, u32 m0, u32 w0, u32 m1, u32 w1);
u32 func_02205620(u32 heap, u32 a, u32 b, u32 k0, u32 v0, u32 k1, u32 v1);
void func_022056E8(u32 *a, char *b);
void func_02205844(int a, char *b);
void func_02205854(void);
extern const char d_02208F40[];
extern u8 gPokeStatusProcData[];
extern const char ov131_id[];
extern const char ov196_id[];
extern const char ov198_id[];
extern u8 ov067_id[];
extern u8 d_02208C4C[];
extern u32 d_020A7370;
extern u8 d_02208CCC[];




/*
 * ABI: 0203159C and 02031324 own files return void; caller consumes r0.
 * ABI: 02031324 also receives the heap in r0, preserved in this extern.
 */
int func_02203FA0(struct Obj0203159C *owner,int unused,u8 *app)
{
    char *p;
    sub_0203064C(1,0x94,0x10000);
    p=func_0203159C(owner,0x120,0x94);
    func_02082BCC(p,0,0x120);
    ((struct Obj00734 *)p)->f0=0x94;
    ((struct Obj00734 *)p)->f28=0;
    ((struct Obj00734 *)p)->f2C=5;
    ((struct Obj00734 *)p)->f30=0;
    ((struct Obj00734 *)p)->f10=POKEPARTY_GetMember(((struct Obj05515 *)app)->f4,app[0xa]);
    *(struct U16Vec * *)&((struct Obj00734 *)p)->f14=STRBUF_Create(0x100,((struct Obj00734 *)p)->f0);
    func_02017E1C(((struct Obj00734 *)p)->f10,0x73,*(u32 *)&((struct Obj00734 *)p)->f14);
    ((struct Obj00734 *)p)->f24=0;
    ((struct Obj00734 *)p)->fA0=0;
    ((struct Obj00734 *)p)->fA4=0;
    ((struct Obj00734 *)p)->fA8=0;
    ((struct Obj00734 *)p)->fAC=0;
    ((struct Obj00734 *)p)->f100=sub_02030734(((struct Obj00734 *)p)->f0,0x28,1,d_02208F40,0x242);
    func_0204E720(3,16,16,-16);
    func_02204DC4(app,(u8 *)p);
    ((struct Obj00734 *)p)->f38=GFL_USE_AddMainTask((u32)func_022051A8,(u32)p,1);
    ((struct Obj00734 *)p)->f10C=0;
    ((struct Obj00734 *)p)->f110=0;
    ((struct Obj00734 *)p)->f114=0;
    ((struct Obj00734 *)p)->f118=0;
    ((struct Obj00734 *)p)->f11C=(unsigned int)PROCSYS_Create(((struct Obj00734 *)p)->f0);
    func_02204C24((App *)((struct App *)app), (Scene *)((struct Scene *)p));
    func_0203D34C(0,((struct Obj00734 *)p)->f0);
    return 1;
}




/*
 * Padding: two zero bytes at 0x022040DE, then a function prologue.
 */
int func_02204098(struct S020315D4 *a, int unused, int b, int *p)
{
    func_02204D5C(b, p);
    PROCSYS_Delete(*(struct S020314B8 * *)&((struct Obj08345 *)p)->f11C);
    sub_02030EAC(*(struct Node * *)&((struct Obj08345 *)p)->f38);
    func_02204DDC(b, p);
    sub_020307B0(((struct Obj08345 *)p)->f100);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj08345 *)p)->f14);
    PROCSYS_FreeProcWork(a);
    func_020306F0(0x94);
    return 1;
}



/*
 * note: 2026-10-05 wave P23 closed EXACT*. Case 34 also calls func_02204FD4(a,s) after func_02205384 (same as case 18), so the tails cross-jump into case 18's copy; case 39 reads W(0x90) into a local once for both func_022055BC arguments (ldr before the s+0x1c add). Older 5-byte DIFF came from those two points.
 * checks: 1 fresh own callee definitions and same-overlay callers confirm arities; unit355C4 setteru8 widened tou32 because caller sends only0/1 without truncation; caller-loaded forwarder args and272A4 wide-r1 payload preserved; 2 matched03FA0/05384/055BC/056E8 and loader twins read; 3 u16 keys (only bit2 used) regresses699, a/s writable so no const; 4 Boolean call/inline-wrapper and flag-ternary idioms read; 5 fresh unfiltered idioms and04DE0/04FC4/math neighbours.
 * extent: 02204B66 and 02204BB2 are internal shared tails; true end 02204C24 (2884B).
 */
int func_022040E0(int unused0,int unused1,char *a,char *s)
{
    u32 tick,keys,result;
    u8 *q;
    void *v;
    tick=PROCSYS_Main(P(0x11c));if(tick==1)return 0;
    switch(W(0x28)){
    case 0:if(W(0x2c)==0){W(0x28)=1;func_0204E720(3,16,0,-16);}else W(0x2c)--;break;
    case 1:if(!func_0204E804()){W(0x28)=2;func_02205138((int)a,(int *)s);}break;
    case 2:if(!func_02204EA0((int)a,(int *)s)&&func_02205168((int)a,(int *)s)){if(W(0x8c))W(0x28)=4;else{W(0x28)=3;func_022054E8((int)a,(int *)s,1);}}break;
    case 3:W(0x88)=1;W(0x28)=4;break;
    case 4:func_02205384(s,W(0x78),0,0,2,W(0x10),4,0);W(0x28)=5;break;
    case 5:if(func_022053E8(s)&&func_0220546C(s)){func_022054E8((int)a,(int *)s,0);W(0x28)=6;func_02206044(P(0x104));}break;
    case 6:if(func_0220604C(P(0x104))){W(0x28)=7;func_02204ED0((int)a,(int *)s);}break;
    case 7:if(!func_02204EF0((int)a,(int *)s)){W(0x28)=8;func_02206050(P(0x104));func_0220882C(P(0x108));func_020061E4(0x7dc);W(0x10c)=1;W(0x2c)=0;}break;
    case 8:
        keys=func_020362DC();
        if(func_0220606C(P(0x104))){if(W(0x24))W(0x28)=13;else W(0x28)=9;break;}
        if(func_02206070(P(0x104)))func_02204F00((int)a,s);
        if(func_02206074(P(0x104)))func_02204F24((int)a,(int *)s);
        if(func_02206058(P(0x104))){func_02208844(P(0x108));if(!W(0x110)){func_020061E4(0x7df);W(0x10c)=0;W(0x110)=1;}}
        if(func_02208850(P(0x108)))func_0220605C(P(0x104));
        if(func_02208860(P(0x108))){func_02206064(P(0x104));if(!W(0x114)){if(!W(0x24))W(0x10c)=1;W(0x114)=1;}}
        if(W(0x10c)){
            if(!W(0x118)&&W(0x2c)>=90){if(func_02204F68((int)a,(int *)s)){func_020061E4(0x7dd);W(0x118)=1;}}
            else if(W(0x2c)==0x212||W(0x2c)==0x249||W(0x2c)==0x280||W(0x2c)==0x2b7)func_020061E4(0x7de);
            else if(W(0x2c)==0x2e4)func_020061E4(0x7e0);
            W(0x2c)++;
        }
        if(A(0x10)&&func_02204F68((int)a,(int *)s)&&!W(0x24)&&(keys&2)&&func_02206078(P(0x104))){W(0x24)=1;func_020355D8(0);func_02208814(P(0x108));}break;
    case 9:
        POKE_TOOL_ChangeSpecies(P(0x10),AH(8));
        if(A(0)){v=func_0200CA1C((void *)A(0));func_0200CFA0(v,P(0x10));func_0200CDE0(v,P(0x10));}
        func_02204FA0((int)a,(int *)s);if(W(0x8c))W(0x28)=11;else{func_022054E8((int)a,(int *)s,1);W(0x28)=10;}break;
    case 10:W(0x88)=1;W(0x28)=11;break;
    case 11:func_02205384(s,W(0x78),2,0,0,W(0x14),1,W(0x10));W(0x28)=12;break;
    case 12:if(func_022053E8(s)&&!func_02204FC4((int)a,(int *)s)&&func_0220546C(s)){GAME_BEACON_SetPokeEvolution((u16)func_02017E1C(P(0x10),5,0),W(0x14));v=func_02012F2C((void *)A(0));func_02008DF0(v,10);func_02008DF0(v,88);W(0x28)=17;}break;
    case 13:if(W(0x24))func_02204FF8((int)a,s);else func_02204F40((int)a,(int *)s);if(W(0x8c))W(0x28)=15;else{func_022054E8((int)a,(int *)s,1);W(0x28)=14;}break;
    case 14:W(0x88)=1;W(0x28)=15;break;
    case 15:func_02205384(s,W(0x78),1,0,2,W(0x10),4,0);W(0x28)=16;break;
    case 16:if(func_022053E8(s)&&func_0220546C(s))W(0x28)=42;break;
    case 17:switch(AB(11)){case 14:func_022056E8((u32 *)a,s);break;case 6:case 19:case 20:func_02205844((int)a,s);break;}W(0x28)=18;W(0x20)=0;break;
    case 18:
        H(0x1c)=POKE_TOOL_GetLevelUpMove(P(0x10),(u32 *)(s+0x20),H(0));
        if(!H(0x1c))W(0x28)=42;else if(H(0x1c)!=0xfffe){if(H(0x1c)&0x8000){H(0x1c)&=0x7fff;W(0x28)=20;}else{W(0x28)=19;func_02205384(s,W(0x7c),3,0,2,W(0x10),3,(u32)(s+0x1c));func_02204FD4((int)a,(int *)s);}}break;
    case 19:if(func_022053E8(s)&&func_0220546C(s))W(0x28)=18;break;
    case 20:W(0x28)=21;func_02205384(s,W(0x7c),4,0,2,W(0x10),3,(u32)(s+0x1c));break;
    case 21:if(func_022053E8(s)){W(0x28)=22;func_022055BC(s,W(0x90),2,4,0,4,0,W(0x90),3,4,0,4,0);func_021B70F4(P(0x9c),W(0x94),W(0x98));}break;
    case 22:
        result=func_021B76B0(P(0x9c));if(result==2)break;
        if(result==1){if(A(0xc)){W(0x28)=23;func_0204E720(3,0,16,0);}else{W(0x28)=27;func_0204E720(2,0,16,0);}}
        else if(!result)W(0x28)=36;
        func_021B72DC(P(0x9c));break;
    case 23:
        if(func_0204E804())break;
        func_02204D5C((int)a,(int *)s);W(0x28)=24;
        v=func_02012EBC((void *)A(0));
        ((u8 *)P(0x100))[0xc]=1;*(u32 *)((char *)P(0x100)+8)=A(0);*(u32 *)((char *)P(0x100)+0x24)=0;*(u32 *)P(0x100)=A(4);
        *(void **)((char *)P(0x100)+4)=func_0200873C(v);((u8 *)P(0x100))[0xe]=func_0201AA18((void *)A(4));((u8 *)P(0x100))[0xf]=AB(0xa);*(u16 *)((char *)P(0x100)+0x14)=H(0x1c);
        ((u8 *)P(0x100))[0xd]=2;((u8 *)P(0x100))[0x10]=1;*(u32 *)((char *)P(0x100)+0x20)=0;
        func_02034AC4((int)ov131_id);PROCSYS_Push(P(0x11c),-1,gPokeStatusProcData,P(0x100));break;
    case 24:if(tick!=1)W(0x28)=25;else return 0;break;
    case 25:func_02034A5C((int)ov131_id);W(0x28)=26;func_02204C24((App *)((struct App *)a), (Scene *)((struct Scene *)s));func_0203D34C(0,H(0));func_0204E720(3,16,0,0);break;
    case 26:
        if(!func_0204E804()){q=P(0x100);switch(q[0x12]){case 0:result=q[0x11];B(0x1a)=result;H(0x18)=func_02017E1C(P(0x10),result+0x36,0);W(0x28)=31;break;case 1:case 2:default:W(0x28)=36;break;}}break;
    case 27:
        if(func_0204E804())break;
        W(0x28)=28;func_021B709C(P(0x9c));W(0x9c)=0;func_02205A84((int)P(4));B(0xac)=func_020355C4()==0;
        P(0xa4)=func_02030734(H(0),func_02030CB0(8),0,(char *)d_02208F40,0x548);
        func_02082BCC(P(0xa4),0,func_02030CB0(8));P(0xa0)=func_02030CBC(8,P(0xa4));P(0xa8)=func_02021518(H(0));PALANM_SetAutoTransfer(P(0xa8),1);
        func_0202155C(P(0xa8),1,0x1e0,H(0));func_0202155C(P(0xa8),3,0x1e0,H(0));
        W(0xb0)=A(0);W(0xb4)=A(4);W(0xbc)=W(8);H(0xc0)=H(0);B(0xcf)=4;B(0xfc)=0;B(0xd0)=AB(0xa);H(0xd6)=H(0x1c);W(0xc4)=0;P(0xf4)=s+0xac;W(0xd8)=W(0xa0);W(0xdc)=W(0xa8);W(0xf0)=1;
        func_02034AC4((int)ov196_id);func_02034AC4((int)ov198_id);func_0220F3E8((u8 *)(s+0xb0));func_0204E720(2,16,0,0);break;
    case 28:func_02030D28(P(0xa0));if(B(0xfc)){W(0x28)=29;func_0204E720(2,0,16,0);}break;
    case 29:
        if(func_0204E804())break;
        W(0x28)=30;func_02034A5C((int)ov196_id);func_02034A5C((int)ov198_id);func_020215A0(P(0xa8),1);func_020215A0(P(0xa8),3);func_02021540(P(0xa8));func_02030DA4(P(0xa0));func_020307B0(P(0xa4));W(0xa0)=0;W(0xa4)=0;W(0xa8)=0;
        func_02205A34(P(4));P(0x9c)=func_021B6DC0(H(0),5,0,1,0,func_02205A28(P(4)),W(8),W(0xc),0);func_0203D34C(0,H(0));func_0204E720(2,16,0,0);break;
    case 30:
        if(func_0204E804())break;
        B(0x1a)=B(0xfb);if(B(0x1a)==4)W(0x28)=36;else{H(0x18)=func_02017E1C(P(0x10),B(0x1a)+0x36,0);W(0x28)=31;}
        func_020355D8(B(0xac)?0:1);break;
    case 31:if(W(0x8c))W(0x28)=33;else{W(0x28)=32;func_022054E8((int)a,(int *)s,1);}break;
    case 32:W(0x88)=1;W(0x28)=33;break;
    case 33:func_02205384(s,W(0x7c),5,(u32)func_02205360,2,W(0x10),3,(u32)(s+0x18));W(0x28)=34;break;
    case 34:if(func_022053E8(s)){func_020181F4(P(0x10),H(0x1c),B(0x1a));W(0x28)=35;func_02205384(s,W(0x7c),6,0,2,W(0x10),3,(u32)(s+0x1c));func_02204FD4((int)a,(int *)s);}break;
    case 35:if(func_022053E8(s))W(0x28)=18;break;
    case 36:if(W(0x8c))W(0x28)=38;else{W(0x28)=37;func_022054E8((int)a,(int *)s,1);}break;
    case 37:W(0x88)=1;W(0x28)=38;break;
    case 38:func_02205384(s,W(0x7c),7,0,4,0,3,(u32)(s+0x1c));W(0x28)=39;break;
    case 39:if(func_022053E8(s)){W(0x28)=40;{u32 w=W(0x90);func_022055BC(s,w,4,3,(u32)(s+0x1c),4,0,w,5,3,(u32)(s+0x1c),4,0);}func_021B70F4(P(0x9c),W(0x94),W(0x98));}break;
    case 40:
        result=func_021B76B0(P(0x9c));if(result==2)break;
        if(result==1){W(0x28)=41;func_02205384(s,W(0x7c),8,0,2,W(0x10),3,(u32)(s+0x1c));}else if(!result)W(0x28)=20;
        func_021B72DC(P(0x9c));break;
    case 41:if(func_022053E8(s))W(0x28)=18;break;
    case 42:if(W(0x24)){func_0204E720(3,0,16,2);W(0x28)=43;}else if(func_02204F68((int)a,(int *)s)){func_02204F78((int)a,s);func_0204E720(3,0,16,2);W(0x28)=43;}break;
    case 43:if(!func_02204F90((int)a,s)){W(0x28)=44;func_02204EB0(a,s);}break;
    case 44:if(!func_0204E804()){W(0x28)=45;return 1;}break;
    case 45:return 1;
    }
    func_02204DE0(a,s);
    if(W(0x28)!=24&&W(0x28)!=25){
        if(P(0x9c))func_021B7378(P(0x9c));
        func_02205340((int)a,s);func_0201C4E4(P(0xc));func_02205D50(P(0x104));func_0220878C(P(0x108));func_022059FC(P(4));func_02205A10(P(4));func_02208804(P(0x108));func_0220602C(P(0x104));func_02205A1C(P(4));
    }
    return 0;
}








void func_02204C24(App *a, Scene *s)
{
    u8 i;
    u8 b;

    func_0203064C(1, 0x68, 0x70000);
    s->heap = 0x68;
    func_02034AC4((u32)ov067_id);
    for (i = 0; i <= 7; i++)
        func_02040588(i, 0);
    s->f04 = func_022058F8(1, s->heap);
    func_02205A34();
    s->f08 = (u32)func_0201D7EC(0x17, 0, 0, 0, s->heap);
    s->f0c = (void *)func_0201C440((void *)s->heap);
    func_022051FC((int)a, (char *)s);
    s->f9c = 0;
    func_02205530((int)a, (char *)s);
    func_02205010((int)a, (char *)s);
    s->f60 = 0;
    if (s->f28 == 0)
        func_02205070((int)a, (char *)s);
    func_0204047C(0, 2);
    func_0204047C(2, 1);
    func_0204047C(1, 0);
    func_0204047C(4, 2);
    func_02040588(0, 1);
    func_02040588(2, 1);
    func_02040588(4, 1);
    func_02040EBC(0, 0);
    func_02040EBC(4, 0);
    if (s->f28 == 0) {
        b = a->f0b;
        if (b == 8 || (u8)(b + 0xef) <= 1)
            a->f10 = 0;
    }
    if (s->f28 == 0)
        s->f104 = func_02205C74(s->heap, 0, s->f10, a->f08);
    else
        s->f104 = func_02205C74(s->heap, 1, s->f10, a->f08);
    if (s->f28 == 0)
        s->f108 = func_0220871C(s->heap, 0);
    else
        s->f108 = func_0220871C(s->heap, 1);
    func_0207D63C(0x04000050, 1, 0x3e, 0, 0);
}








/*
 * Leaf of the func_022040E0 dependency tree: the scene object's teardown.
 * It releases the two +0x104/+0x108 sub-objects, tears the controller links
 * down, then frees the +0x0c/+0x08/+0x04 allocations and drops the 0x43 /
 * 0x68 pools.
 */
void func_02204D5C(int a, int *p)
{
    func_02208770((char *)p[0x42]);
    func_02205D28((char *)p[0x41]);
    func_02205100((void *)a, (char *)p);
    func_0220506C(a, p);
    func_02205580((void *)a, (char *)p);
    func_022052E8(a, p);
    func_0201C6EC((struct PrintSys *)p[3]);
    func_0201C4C0((struct PrintSys *)p[3]);
    func_0201D83C((void *)p[2]);
    func_02205A84(p[1]);
    func_022059A0((char *)p[1]);
    func_02034A5C((int)ov067_id);
    func_020306F0(0x68);
}








/*
 * Addresses are Black-image addresses.
 */
void func_02204DC4(u8 *p, u8 *q)
{
    if (((struct Obj24942 *)p)->fC != 0) {
        GFL_USE_FadeOutBgm(0x1e);
    }
    ((struct Obj24943 *)q)->f30 = 1;
}







void func_02204DDC(int a0, int *a1) {}








void func_02204DE0(char *a, char *b)
{
    switch (((struct Obj03902 *)b)->f30) {
    case 0:
        break;
    case 1:
        if (GFL_USE_IsBgmFading() == 0) {
            if (((struct Obj24944 *)a)->fC != 0) {
                GFL_USE_SetBgmPlayerParam((void *)1);
                GFL_USE_PushBgm();
            }
            ((struct Obj03902 *)b)->f30 = 0;
        }
        break;
    case 2:
        if (func_02005F38() == 0)
            ((struct Obj03902 *)b)->f30 = 0;
        break;
    case 3:
        if (GFL_USE_StepBgmLoad((u8 *)0x3f3, (u32 *)(b + 0x34), 0) != 0)
            ((struct Obj03902 *)b)->f30 = 4;
        break;
    case 4:
    case 5:
        break;
    case 6:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_CancelChangeAndStopBgm();
            ((struct Obj03902 *)b)->f30 = 0;
        }
        break;
    case 7:
        if (GFL_USE_StepBgmLoad((u8 *)0x519, (u32 *)(b + 0x34), 0) != 0)
            ((struct Obj03902 *)b)->f30 = 8;
        break;
    case 8:
        if (func_02005F38() == 0)
            func_02204F40((int)a, (int *)b);
        break;
    case 9:
        if (func_02005F38() == 0)
            func_02204F40((int)a, (int *)b);
        break;
    }
}







/*
 * Leaf of the func_022040E0 dependency tree: true when the scene object's
 * state word +0x30 is 1.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int func_02204EA0(int a, int *p)
{
    return p[0xc] == 1;
}








void func_02204EB0(char *a, char *b)
{
    if (((struct Obj24946 *)b)->f30 == 0 && ((struct Obj14523 *)a)->fC != 0) {
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPlayerParam(0);
        GFL_USE_FadeInBgmFull(0x3c);
    }
}








/*
 * Leaf of the func_022040E0 dependency tree: when the scene object sits in
 * state word +0x30 == 0, play cue 0x3f2 and move it to state 2.
 */
void func_02204ED0(int a, int *p)
{
    if (p[0xc] == 0) {
        GFL_USE_CancelChangeAndPlayBgm(0x3f2, 0xffff);
        p[0xc] = 2;
    }
}






/*
 * Leaf of the func_022040E0 dependency tree: true when the scene object's
 * state word +0x30 is 2.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int func_02204EF0(int a, int *p)
{
    return p[0xc] == 2;
}







void func_02204F00(int unused, char *p)
{
    if (((struct Obj10816 *)p)->f30 == 0)
    {
        ((struct Obj10816 *)p)->f34 = 0;
        GFL_USE_StepBgmLoad((void *)0x3f3, (u32 *)(p + 0x34), 1);
        ((struct Obj10816 *)p)->f30 = 3;
    }
}







void func_02204F24(int a, int *b)
{
    if (((struct Obj08346 *)b)->f30 == 4) {
        GFL_USE_SetBgmPlayerParam((void *)1);
        GFL_USE_PushBgm();
        ((struct Obj08346 *)b)->f30 = 5;
    }
}







/*
 * Leaf of the func_022040E0 dependency tree: when the scene object sits in
 * state 5 or in state 8/9, run the cue trio and drop it into state 4.
 */
void func_02204F40(int a, int *p)
{
    int s = p[0xc];

    if (s == 5 || (unsigned)(s - 8) <= 1) {
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPlayerParam(0);
        GFL_USE_FadeInBgmFull(6);
        p[0xc] = 4;
    }
}






/*
 * Leaf of the func_022040E0 dependency tree: true when the scene object's
 * state word +0x30 is 4.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int func_02204F68(int a, int *p)
{
    return p[0xc] == 4;
}







void func_02204F78(int a, char *b)
{
    if (((struct Obj14525 *)b)->f30 == 4) {
        GFL_USE_FadeOutBgm(0x3c);
        ((struct Obj14525 *)b)->f30 = 6;
    }
}







int func_02204F90(int a, char *b)
{
    if (((struct Obj24949 *)b)->f30 == 6)
        return 1;
    return 0;
}







/*
 * Leaf of the func_022040E0 dependency tree: when the scene object sits in
 * state word +0x30 == 5, clear word +0x34, arm a 1-flag timer on it and move
 * to state 7.
 */
void func_02204FA0(int a, int *p)
{
    if (p[0xc] == 5) {
        p[0xd] = 0;
        GFL_USE_StepBgmLoad((unsigned char *)0x519, (u32 *)(&p[0xd]), 1);
        p[0xc] = 7;
    }
}






/*
 * Leaf of the func_022040E0 dependency tree: true when the scene object's
 * state word +0x30 is 7 or 8.
 */
int func_02204FC4(int a, int *p)
{
    return p[0xc] == 7 || p[0xc] == 8;
}







/*
 * Leaf of the func_022040E0 dependency tree: when the scene object sits in
 * state word +0x30 == 4, hand it to func_02204F24 and play cue 0x515, then
 * park it in state 9.  First argument is forwarded untouched.
 */
void func_02204FD4(int a, int *p)
{
    if (p[0xc] == 4) {
        func_02204F24(a, p);
        GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        p[0xc] = 9;
    }
}







void func_02204FF8(int a, char *b)
{
    if (((struct Obj14527 *)b)->f30 == 5) {
        GFL_USE_PopBgm();
        GFL_USE_CancelChangeAndStopBgm();
        ((struct Obj14527 *)b)->f30 = 0;
    }
}






void func_02205010(int a, char *b)
{
    void *h = func_020490F4(0xb6, ((struct Obj08347 *)b)->f2);

    func_02049B68(h, 3, 0, 0, 0x20, ((struct Obj08347 *)b)->f2);
    func_02049658(h, 5, 2, 0, 0, 0, ((struct Obj08347 *)b)->f2);
    func_020498F4(h, 4, 2, 0, 0, 0, ((struct Obj08347 *)b)->f2);
    func_02049238(h);
    func_020409B4(2);
}





void func_0220506C(int a0, int *a1) {}






void func_02205070(int a, char *b)
{
    void *h;
    u8 i;
    int z;

    h = func_020490F4(0xb6, ((struct Obj01971 *)b)->f2);
    i = 0;
    ((struct Obj01971 *)b)->f40 = func_0204AC18(h, 3, 0, 0, i, 1, ((struct Obj01971 *)b)->f2);
    ((struct Obj01971 *)b)->f3C = func_0204A6C8(h, 2, 0, 0, ((struct Obj01971 *)b)->f2);
    ((struct Obj01971 *)b)->f44 = func_0204AF28(h, 1, 0, ((struct Obj01971 *)b)->f2);
    func_02049238(h);
    for (z = i; i < 6; i++) {
        char *e = b + i * 4;
        ((struct Obj14528 *)e)->f48 = (u32)func_0204B294((void *)func_02205A28((char *)(((struct Obj01971 *)b)->f4)), ((struct Obj01971 *)b)->f3C, ((struct Obj01971 *)b)->f40,
                                           ((struct Obj01971 *)b)->f44, d_02208C4C + i * 8, z, ((struct Obj01971 *)b)->f2);
        func_0204B92C((struct Obj *)((struct Obj14528 *)e)->f48, z);
    }
    ((struct Obj01971 *)b)->f60 = 1;
}





void func_02205100(void *unused,char *p) {u8 i;if(((struct Obj04593 *)p)->f60){for(i=0;i<6;i++)func_0204B3B4((struct Obj *)(*(u32 *)(p+0x48+i*4)));func_0204AFD8(((struct Obj04593 *)p)->f44);func_0204A8D4(((struct Obj04593 *)p)->f3C);func_0204ADA4(((struct Obj04593 *)p)->f40);((struct Obj04593 *)p)->f60=0;}}






/*
 * Leaf of the func_022040E0 dependency tree: when the scene object has the
 * +0x60 pointer set, tear down the six +0x48 handles.
 */
void func_02205138(int a, int *p)
{
    unsigned char i;

    if (p[0x18] == 0)
        return;
    for (i = 0; i < 6; i++) {
        CLACT_SetActorAnimIndex(p[0x12 + i], 0);
        func_0204B92C((struct Obj *)p[0x12 + i], 1);
    }
}






/*
 * Leaf of the func_022040E0 dependency tree: probe all six +0x48 handles;
 * if every one is idle, hand the scene object to func_02205100.  A missing
 * +0x60 pointer reports success without probing.
 */
int func_02205168(int a, int *p)
{
    unsigned char i;

    if (p[0x18] != 0) {
        int ok = 1;

        for (i = 0; i < 6; i++) {
            if (func_0204B98C((struct Actor *)p[0x12 + i]) != 0) {
                ok = 0;
                break;
            }
        }
        if (ok)
            func_02205100((void *)a, (char *)p);
        return ok;
    }
    return 1;
}





/*
 * extent: 82 code bytes followed by two zero alignment bytes at 0x022051FA.
 */
void func_022051A8(int task, char *p)
{
    switch (((struct Obj04594 *)p)->f88) {
    case 1:
        func_02040588(1, 1);
        ((struct Obj04594 *)p)->f8C = 1;
        ((struct Obj04594 *)p)->f88 = 0;
        break;
    case 2:
        func_02040588(1, 0);
        ((struct Obj04594 *)p)->f8C = 0;
        ((struct Obj04594 *)p)->f88 = 0;
        break;
    }
    if (((struct Obj04594 *)p)->fA8)
        PALANM_TransferPalettes(((struct Obj04594 *)p)->fA8);
}






void func_022051FC(int a, char *b)
{
    u32 p;

    func_02049B40(0x17, 5, 0, 0x20, 0x20, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f70 = func_020450F0(1, 0, 0, 1, 1, 1, 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00844 *)b)->f70)), 0);
    func_02045334((struct Descriptor *)((struct Obj00844 *)b)->f70);
    ((struct Obj00844 *)b)->f6C = func_020450F0(1, 1, 0x13, 0x1e, 4, 1, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00844 *)b)->f6C)), 0);
    p = ((struct Obj00844 *)b)->f6C;
    func_02045334((struct Descriptor *)p);
    func_02045374((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
    ((struct Obj00844 *)b)->f74 = (u32)func_0201F5DC((void *)1, 2, 0, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f78 = (u32)func_02045B38(0, 2, 0xac, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f7C = (u32)func_02045B38(0, 2, 0xcc, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f68 = (u32)func_0203101C(((struct Obj00844 *)b)->f2, ((struct Obj00844 *)b)->f2, 1, 0);
    func_0201DD78(1, 2, 0xf);
    ((struct Obj00844 *)b)->f80 = 0;
    ((struct Obj00844 *)b)->f64 = 0;
    ((struct Obj00844 *)b)->f84 = func_02028590(0xf, 1, 1, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f88 = 0;
    func_02040588(1, 0);
    ((struct Obj00844 *)b)->f8C = 0;
}





void func_022052E8(int task, int *p)
{
    func_02028604(((struct Obj02240 *)p)->f84);
    if (((struct Obj02240 *)p)->f64) func_0201CE48((struct Rec3 *)(((struct Obj02240 *)p)->f64));
    func_02031140((struct S02031140 *)(((struct Obj02240 *)p)->f68));
    if (((struct Obj02240 *)p)->f80) func_02045808((struct U16Vec *)(((struct Obj02240 *)p)->f80));
    func_02045C04(((struct Obj02240 *)p)->f78);
    func_02045C04(((struct Obj02240 *)p)->f7C);
    func_0203FB44(1, (unsigned short)(((struct Obj02240 *)p)->f74), (unsigned short)(((struct Obj02240 *)p)->f74 >> 16));
    func_020452E8((struct Descriptor *)(((struct Obj02240 *)p)->f6C));
    func_020452E8((struct Descriptor *)(((struct Obj02240 *)p)->f70));
}






void func_02205340(int a, char *b)
{
    func_020310C4((struct Tcbl *)(((struct Obj06642 *)b)->f68));
    if (((struct Obj06642 *)b)->f64 != 0)
        func_020286C4((struct Ctx *)(((struct Obj06642 *)b)->f84), (void *)(((struct Obj06642 *)b)->f64), (void *)(((struct Obj06642 *)b)->f6C));
}






int func_02205360(int a)
{
    switch (a) {
    case 3:
        func_020061E4(0x56b);
        break;
    case 5:
        return func_02006238();
    }
    return 0;
}





void func_02205384(char *a, u32 b, u32 c, u32 d, u32 k0, u32 v0, u32 k1, u32 v1)
{
    func_0220549C(a, 0xf);
    *(u32 *)&((struct Obj01429 *)a)->f80 = func_02205620(((struct Obj01429 *)a)->f2, b, c, k0, v0, k1, v1);
    *(u32 *)&((struct Obj01429 *)a)->f64 = (u32)func_0201CD10(*(u32 *)&((struct Obj01429 *)a)->f6C, 0, 0, *(u32 *)&((struct Obj01429 *)a)->f80, ((struct Obj01429 *)a)->f8,
                                       func_02012FFC(), ((struct Obj01429 *)a)->f68, 2, ((struct Obj01429 *)a)->f2, 0xf, d);
}





/*
 * The `(x & 3) != 0 ? 0 : 1` call arguments must be written as an explicit
 * if/else. The ternary makes mwccarm pick the opposite branch polarity and
 * then colour the pointer r5/result r4 the other way; the if/else gives the
 * original pointer r4 / result r5 split and the shared return. See
 * docs/idioms/a-ternary-constant-call-argument-takes-the-opposite-branch-polarity.md.
 */
int func_022053E8(char *a)
{
    int r = 0;

    switch (func_0201CE30((void *)(((struct Obj10819 *)a)->f64))) {
    case 0:
        if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
            func_0201CE5C((struct Rec *)(((struct Obj10819 *)a)->f64), 0);
            if ((func_0203630C() & 3) != 0)
                func_020355D8(0);
            else
                func_020355D8(1);
        }
        break;
    case 1:
        if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
            func_020061E4(0x547);
            func_0201CE38((void *)(((struct Obj10819 *)a)->f64));
            if ((func_020362DC() & 3) != 0)
                func_020355D8(0);
            else
                func_020355D8(1);
        }
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}





/*
 * Leaf of the func_022040E0 dependency tree: a confirm gate.  True once the
 * action key is held (func_020362DC & 3) or the touch probe fires; it hands
 * the pressed/released flag to func_020355D8.  The two arms must be separate
 * call statements, not a selected value: only then does mwccarm tail-merge
 * them with the original's `beq`-to-true orientation.
 */
int func_0220546C(char *s)
{
    if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
        if ((func_020362DC() & 3) != 0)
            func_020355D8(0);
        else
            func_020355D8(1);
        return 1;
    }
    return 0;
}




void func_0220549C(char *a, int b)
{
    int p;

    func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)((struct Obj01429 *)a)->f6C), b);
    p = ((struct Obj01429 *)a)->f6C;
    func_02045334((struct Descriptor *)p);
    func_02045374((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
    if (((struct Obj01429 *)a)->f64 != 0)
        func_0201CE48((struct Rec3 *)(((struct Obj01429 *)a)->f64));
    if (((struct Obj01429 *)a)->f80 != 0)
        func_02045808((struct U16Vec *)(((struct Obj01429 *)a)->f80));
    ((struct Obj01429 *)a)->f64 = 0;
    ((struct Obj01429 *)a)->f80 = 0;
}





/*
 * Leaf of the func_022040E0 dependency tree: either build the +0x6c render
 * node from the +0x74 id (and flush the +0x104/+0x108 stage), or arm the
 * +0x88 transition word with 2.
 */
void func_022054E8(int a, int *p, int flag)
{
    if (flag != 0) {
        int *q;

        func_0201F73C((void *)p[0x1b], 0, (unsigned short)p[0x1d], 2);
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p[0x1b])), 0xf);
        q = (int *)p[0x1b];
        func_02045334((struct Descriptor *)q);
        func_02045374((struct Cfg *)((int)q));
        func_020409B4(func_02045730((struct Descriptor *)((int)q)));
    } else {
        p[0x22] = 2;
    }
}





void func_02205530(int a, char *b)
{
    ((struct Obj03344 *)b)->f90 = (u32)func_02045B38(0, 2, 0xe9, ((struct Obj03344 *)b)->f2);
    ((struct Obj03344 *)b)->f9C = (u32)func_021B6DC0(((struct Obj03344 *)b)->f2, 5, 0, 1, 0, func_02205A28((char *)(((struct Obj03344 *)b)->f4)),
                                       ((struct Obj03344 *)b)->f8, ((struct Obj03344 *)b)->fC, 0);
    ((struct Obj03344 *)b)->f94 = 0;
    ((struct Obj03344 *)b)->f98 = 0;
}



void func_02205580(void *unused,char *p) {func_021B709C(*(u8 * *)&((struct Obj04595 *)p)->f9C);*(u32 *)&((struct Obj04595 *)p)->f9C=0;if(((struct Obj04595 *)p)->f94)func_02045808((struct U16Vec *)(((struct Obj04595 *)p)->f94));if(((struct Obj04595 *)p)->f98)func_02045808((struct U16Vec *)(((struct Obj04595 *)p)->f98));func_02045C04(*(struct Rec * *)&((struct Obj04595 *)p)->f90);}




void func_022055BC(char *a, u32 a1, u32 a2, u32 k0, u32 v0, u32 k1, u32 v1,
                   u32 b1, u32 b2, u32 m0, u32 w0, u32 m1, u32 w1)
{
    if (((struct Obj03903 *)a)->f94 != 0)
        func_02045808((struct U16Vec *)(((struct Obj03903 *)a)->f94));
    if (((struct Obj03903 *)a)->f98 != 0)
        func_02045808((struct U16Vec *)(((struct Obj03903 *)a)->f98));
    ((struct Obj03903 *)a)->f94 = func_02205620(((struct Obj03903 *)a)->f2, a1, a2, k0, v0, k1, v1);
    ((struct Obj03903 *)a)->f98 = func_02205620(((struct Obj03903 *)a)->f2, b1, b2, m0, w0, m1, w1);
}




u32 func_02205620(u32 heap, u32 a, u32 b, u32 k0, u32 v0, u32 k1, u32 v1)
{
    Param p[2];
    u32 src, w, r, i;
    int z;

    if (k0 == 4 && k1 == 4) {
        r = (u32)func_02045EC0((struct MsgBank *)a, b);
    } else {
        src = (u32)func_02045EC0((struct MsgBank *)a, b);
        w = (u32)func_0201EC64(heap);
        p[0].kind = k0;
        p[0].val = v0;
        p[1].kind = k1;
        p[1].val = v1;
        for (i = 0, z = i; i < 2; i++) {
            switch (p[i].kind) {
            case 0:
                func_0201EE0C((struct WordSet *)w, i, (const void *)p[i].val, z, 1, z);
                break;
            case 1:
                func_0201EE84((void *)w, i, (void *)p[i].val);
                break;
            case 2:
                func_0201EEF4((void *)w, i, (void *)p[i].val);
                break;
            case 3:
                func_0201EF34((struct WordSet *)w, i, *(u16 *)p[i].val);
                break;
            }
        }
        r = (u32)func_020457B0(0x100, heap);
        func_0201F250((struct WordSet *)w, (void *)r, (void *)src);
        func_02045808((struct U16Vec *)src);
        func_0201ED04((struct WordSet *)w);
    }
    return r;
}




void func_022056E8(u32 *a, char *b)
{
    void *save;
    u32 p, q, v;
    int i;

    save = func_0201292C((const struct BigObj *)a[0]);
    if ((int)func_0201AA18((void *)a[1]) >= (int)func_0201AA14((void *)a[1]))
        return;
    if (func_02007F68(save, 4, 1, ((struct Obj06644 *)b)->f0) == 0)
        return;
    p = (u32)func_02030734(((struct Obj06644 *)b)->f0, func_020173EC(), 1, (const char *)d_02208F40, 0xaf5);
    func_02019CE0((const struct RecDC *)(((struct Obj06644 *)b)->f10), (struct RecDC *)p);
    POKE_TOOL_ChangeSpecies((void *)p, 0x124);
    func_02017E40((void *)p, 0x98, 4);
    func_02017E40((void *)p, 6, 0);
    func_02017E40((void *)p, 0xb, 0);
    for (i = 0x19; i < 0x36; i++)
        func_02017E40((void *)p, i, 0);
    for (i = 0x4d; i < 0x6d; i++)
        func_02017E40((void *)p, i, 0);
    for (i = 0x78; i < 0x8d; i++)
        func_02017E40((void *)p, i, 0);
    v = (u32)func_02045EC0((struct MsgBank *)d_020A7370, func_02017E1C((void *)p, 5, 0));
    func_02017E40((void *)p, 0x73, v);
    func_02045808((struct U16Vec *)v);
    func_02017E40((void *)p, 0x9d, 0);
    v = (u32)func_02008F08(((struct Obj06644 *)b)->f0);
    func_02017E40((void *)p, 0xa7, v);
    func_020307B0((void *)v);
    func_02017E40((void *)p, 0x9f, 0);
    func_0201A98C((void *)a[1], (void *)p);
    func_02007F1C(save, 4, 1, ((struct Obj06644 *)b)->f0);
    func_020307B0((void *)p);
    q = (u32)func_0200CA1C((void *)a[0]);
    func_0200CFA0((struct Blk37 *)q, (void *)p);
    func_0200CDE0((struct Blk37 *)q, (void *)p);
    q = (u32)func_02012F2C((int *)a[0]);
    func_02008DF0((struct Sub02008C20Obj *)q, 10);
    func_02008DF0((struct Sub02008C20Obj *)q, 0x58);
}




void func_02205844(int a, char *b)
{
    func_02017E40((void *)(((struct Obj24950 *)b)->f10), 6, 0);
}




void func_02205854(void)
{
    u32 i;

    func_020434DC(1, 1);
    REG_BG0CNT = REG_BG0CNT & ~3;
    REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3002) | 2;
    REG_DISP3DCNT &= ~0x3010;
    REG_DISP3DCNT &= ~0x3004;
    REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 8;
    REG_DISP3DCNT &= ~0x3020;
    func_0207DC44(0, 0, 0, 0);
    i = 0;
    func_0207DD24(0, 0, 0x7fff, 0x3f, i);
    REG_VIEWPORT = 0xbfff0000;
    for (; i < 4; i++)
        G3D_SYSTEM_SetLight((u8)i, (const u16 *)(d_02208CCC + i * 8));
    func_02046BE0(1, 0);
}
