/*
 * file:     unit_021C8DA0.c
 * unit:     yes
 * function: func_021C8DA0, func_021C8E2C, func_021C8F2C, func_021C8F88, func_021C9154, func_021C9180, func_021C91CC, func_021C9238, func_021C9244, func_021C93C0, func_021C9450, func_021C94DC, func_021C9544, func_021C958C, func_021C95CC, func_021C9628, func_021C9730, func_021C97A0, func_021C987C, func_021C98EC, func_021C991C, func_021C9BC4, func_021C9BEC, func_021C9BF8, func_021C9CCC, func_021C9D0C, func_021C9D88, func_021C9E10, func_021C9E54, func_021C9E6C, func_021C9EB4, func_021C9ED0, func_021C9EF0, func_021C9EF4, func_021C9EFC, func_021C9F30, func_021C9F6C, func_021C9F8C, func_021C9FC8, func_021CA014, func_021CA084, func_021CA0BC, func_021CA10C, func_021CA124, func_021CA154, func_021CA16C, func_021CA184, func_021CA19C, func_021CA1E0, func_021CA25C, func_021CA294, func_021CA2AC, func_021CA2C4, func_021CA2DC, func_021CA320, func_021CA3A0, func_021CA3C4, func_021CA3E8, func_021CA40C, func_021CA42C, func_021CA444, func_021CA458, func_021CA478, func_021CA4B4
 * address:  0x021C8DA0
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NAMEIN_SETUP_CreateArgs 0x0216BFD4 thumb ov010
 *   STRBUF_SetString 0x02045924 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   func_021C6438 0x021C6438 thumb ov128
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   d_021CA529 0x021CA529 data a1
 *   func_021C63AC 0x021C63AC thumb ov128
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009860 0x02009860 thumb
 *   DWC_CreateFriendKey 0x0205994C arm
 *   func_02045CAC 0x02045CAC arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   STRBUF_Clear 0x0204581C arm
 *   STRBUF_AppendChar 0x02045AFC arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_02049EF4 0x02049EF4 arm
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   d_021CA674 0x021CA674 data a4
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021C6ADC 0x021C6ADC thumb ov128
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021C6B38 0x021C6B38 thumb ov128
 *   func_02041300 0x02041300 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   func_02041EE4 0x02041EE4 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_021C6E18 0x021C6E18 thumb ov128
 *   KEY_GetCont 0x0203630C arm
 *   d_021CA576 0x021CA576 data a1
 *   func_021C6DF8 0x021C6DF8 thumb ov128
 *   func_02040618 0x02040618 arm
 *   d_021CA564 0x021CA564 data a2
 *   d_021CA538 0x021CA538 data a4
 *   d_021CA7E0 0x021CA7E0 data a4
 *   d_021CA521 0x021CA521 data a1
 *   func_021C6BCC 0x021C6BCC thumb ov128
 *   func_021C6DD8 0x021C6DD8 thumb ov128
 *   func_021CA4C8 0x021CA4C8 thumb ov128
 *   func_02009864 0x02009864 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_GetDispWidth 0x02045748 arm
 *   TOUCHBAR_PrintYesNoCancelLabels 0x021B6B2C thumb ov067
 *   func_021C6C94 0x021C6C94 thumb ov128
 *   func_021C6C20 0x021C6C20 thumb ov128
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02025C88 0x02025C88 thumb
 *   POKEGRA_OpenTrainerHandle 0x0202DA04 thumb
 *   POKEGRA_RegisterTrainerCgr 0x0202DA48 thumb
 *   POKEGRA_RegisterTrainerPalette 0x0202DA18 thumb
 *   POKEGRA_RegisterTrainerCellAnim 0x0202DA6C thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   d_021CA640 0x021CA640 data a2
 *   func_020410D0 0x020410D0 arm
 *   d_021CA544 0x021CA544 data a1
 *   d_021CA4F7 0x021CA4F7 data a1
 *   d_021CA554 0x021CA554 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021CA648 0x021CA648 data a2
 *   d_021CA5A2 0x021CA5A2 data a2
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   _ull_mul 0x0209C054 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   BLINK_PALANM_Create 0x0202E940 thumb
 *   BLINK_PALANM_LoadPalettes 0x0202E9AC thumb
 *   func_0202EA20  0x0202EA20  thumb
 *   func_020413B0 0x020413B0 arm
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *   func_020355C4 0x020355C4 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   func_0207D658 0x0207D658 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 */
#include "../../matched/include/Obj00227.h"
#include "../../matched/include/Obj03544.h"
#include "../../matched/include/Obj03813.h"
#include "../../matched/include/Obj10489.h"
#include "../../matched/include/Obj00329.h"
#include "../../matched/include/Obj10490.h"
#include "../../matched/include/Obj14044.h"
#include "../../matched/include/Obj23102.h"
#include "../../matched/include/Obj23103.h"
#include "../../matched/include/Obj00773.h"
#include "../../matched/include/Obj10491.h"
#include "../../matched/include/Obj08131.h"
#include "../../matched/include/Obj23105.h"
#include "../../matched/include/Obj10493.h"
#include "../../matched/include/Obj02842.h"
#include "../../matched/include/Obj00992.h"
#include "../../matched/include/Obj10494.h"
#include "../../matched/include/Obj14046.h"
#include "../../matched/include/Obj23107.h"
#include "../../matched/include/Obj23108.h"
#include "../../matched/include/Obj23109.h"
#include "../../matched/include/Obj08133.h"
#include "../../matched/include/Obj10496.h"
#include "../../matched/include/Obj14048.h"
#include "../../matched/include/Obj03812.h"
#include "../../matched/include/Obj00725.h"
#include "../../matched/include/Obj00774.h"
#include "../../matched/include/Obj14051.h"
#include "../../matched/include/Obj23113.h"
#include "../../matched/include/Obj00775.h"
#include "../../matched/include/Obj00179.h"
#include "../../matched/include/Obj14052.h"
#include "../../matched/include/Obj06477.h"
#include "../../matched/include/Obj08135.h"

struct Big;
struct Sub020097BCObj;
struct BigObj;
struct Strbuf;
struct Actor;
struct DWCstAccUserData;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PrintSys;
struct CharBuf;
struct Obj;
struct CodeIn;
struct Obj0202EA20;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct { u16 v[10]; } Tbl;

typedef signed char s8;

typedef struct {u16 v[4];} Bounds;

typedef signed int     s32;

typedef struct {u16 x,y,z,pad;u32 value;void *items[8];volatile u32 count[8];} Record;

extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200C0F0(void *);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern char *NAMEIN_SETUP_CreateArgs(int,int,u32,u32,int,int,void *);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void func_021C6438(u8 *p, u8 a, u8 b);
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
extern u32 WIPE_SYS_EndCheck(void);
extern int TOUCHPANEL_HitTrg(const void *);
extern void func_020355D8(u8 v);
extern u32 KEY_GetTrg(void);
extern void func_021C63AC(void *, u32 *, u32, u32, u8, u8, u8, u8, u32, u8);
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern unsigned long long DWC_CreateFriendKey(struct DWCstAccUserData *userdata);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void STRBUF_AppendChar(struct U16Vec *vec, u16 value);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *func_02049EF4(void *arc, u32 id, u32 comp, void **out, u16 heap);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_021C6ADC(u8 *p, u8 *q, unsigned v);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02041B6C(u32 bit);
extern void func_021C6B38(u8 *p);
extern void func_02041300(u32,int,u8,u8,u8,u8,u8);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_021C6E18(u8 *p, int i, u16 a);
extern unsigned int KEY_GetCont(void);
extern void func_021C6DF8(u8 *p, u32 a);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_021C6BCC(u8 *,u8 *,int,unsigned);
extern void func_021C6DD8(u8 *p, u32 a);
extern void func_021CA4C8(int *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u8 BMP_WIN_GetDispWidth(struct Descriptor *p);
extern void TOUCHBAR_PrintYesNoCancelLabels(u32 a0, void *a1, u32 a2, u16 a3, u16 a4, u16 a5, u32 a6, u32 a7, u16 heap);
extern void func_021C6C94(char **,int);
extern int func_021C6C20(u8 *,u8 *,int);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern u32 func_02025C88(u32);
extern int POKEGRA_OpenTrainerHandle(int);
extern u32 POKEGRA_RegisterTrainerCgr(u32,u32,u32,u32);
extern s32 POKEGRA_RegisterTrainerPalette(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int POKEGRA_RegisterTrainerCellAnim(int a0, int a1, int a2, unsigned short a3);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u16 STRBUF_GetEosChar(void);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern int TOUCHPANEL_GetTrg(void);
extern struct CodeIn *BLINK_PALANM_Create(u16 a0, u16 a1, u32 a2, u16 heap);
extern void BLINK_PALANM_LoadPalettes(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern u32 func_0202EA20(struct Obj0202EA20 *p);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);
extern u8 func_020355C4(void);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void func_0207D658(u32,int,int);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
char *func_021C8DA0(void *unused,char *q,int mode,int heap);
void func_021C8E24(void *p,void *q,void *r,u16 s);
int func_021C8E2C(void *p, u8 *q, u8 *r, int heap);
void func_021C8F24(void *p, void *q, void *r);
int func_021C8F2C(void *unused,int *q);
void func_021C8F88(u8 *p, u8 *q, u8 *ctx, u16 heap);
void func_021C9154(char *p,int unused,char *q);
void func_021C9180(char *p,char *q,char *r);
void func_021C91CC(char *p,void *q);
void func_021C9238(u8 *p,u8 *b,u8 *c,u16 d);
int func_021C9244(u8 *p,u8 *q,u8 *r,u16 heap);
int func_021C93C0(char *p,void *q,void *r,int n);
int func_021C9450(void *p,int *q,void *r);
int func_021C94DC(void *p,void *q,void *r,int *flag);
int func_021C9544(void *p,int *q,char *r);
void func_021C958C(char *p, void *q, void *r, int s);
int func_021C95CC(u8 *p,void *a,void *b,int c);
void func_021C9628(u8 *p, void *unused, u8 *q, u16 heap);
void func_021C9730(u8 *p,void *unused,u8 *q);
void func_021C97A0(u8 *p,u8 *q,u8 *r,u16 heap);
void func_021C987C(u8 *p,u8 *q);
void func_021C98EC(char *p,u8 *q);
void func_021C991C(u8 *p,u8 *q,u8 *ctx,u16 heap);
void func_021C9BC4(u32 p);
void func_021C9BEC(u16 *p, void *b, void *c, int flag, int value, int a5);
void func_021C9BF8(u8 *p,u8 *q,int idx);
void func_021C9CCC(void *unused,u8 *p);
int func_021C9D0C(u8 *p,int direction);
int func_021C9D88(u8 *p,int direction);
void func_021C9E10(u8 *p,u8 *q,u16 heap);
void func_021C9E54(u8 *p);
void func_021C9E6C(u8 *p,void *q);
void func_021C9EB4(u8 *p, void *a1);
void func_021C9ED0(u32 p,int unused,const u16 *q,u32 value,u16 heap);
void func_021C9EF0(void *a0);
void func_021C9EF4(u32 p,int unused,u32 index,u32 value,u32 unused5,u16 heap);
void func_021C9EFC(Record *p,u32 index);
void func_021C9F30(char *p,u32 index);
void func_021C9F6C(char *p,void *q);
void func_021C9F8C(void *q,char *p);
void func_021C9FC8(u8 *p,void *unused,u8 *q,u32 item,int x,int y,int color);
u64 func_021CA014(void *p,int *ok);
int func_021CA084(int *p);
void func_021CA0BC(u8 *p,u16 heap);
void func_021CA10C(u8 *p);
void func_021CA124(u32 a,u32 b);
void func_021CA154(u8 *p, int a);
void func_021CA16C(u8 *p, int a);
void func_021CA184(u8 *p, int a, int b);
void func_021CA19C(unsigned *p);
int func_021CA1E0(char *p);
void func_021CA25C(u32 a,u32 b);
void func_021CA294(u8 *p, int a);
void func_021CA2AC(u8 *p, int a);
void func_021CA2C4(u8 *p, int a, int b);
void func_021CA2DC(char *p);
int func_021CA320(char *p);
void func_021CA3A0(char *p);
void func_021CA3C4(char *p);
void func_021CA3E8(int a);
void func_021CA40C(char *p, int n);
void func_021CA42C(char *p);
void func_021CA444(char *p);
void func_021CA458(char *p,void *q);
void func_021CA478(char *p);
void func_021CA4B4(char *p);
extern const u8 d_021CA529[];
extern const Tbl d_021CA674;
extern const u8 d_021CA576[];
extern const s16 d_021CA564[][3];
extern const u32 d_021CA538[];
extern const u32 d_021CA7E0[];
extern const u8 d_021CA521[];
extern const Bounds d_021CA640;
extern const u8 d_021CA544[];
extern const u8 d_021CA4F7[];
extern const u8 d_021CA554[];
extern const u16 d_021CA648[4];
extern const u8 d_021CA5A2[10][4];



char *func_021C8DA0(void *unused,char *q,int mode,int heap) {
 void *v;void *base;int idx;char *ret;unsigned kind;
 v=func_0200C0F0(GAME_DATA_GetSaveControl(((struct Obj00227 *)q)->f4));
 base=(void *)func_0201283C(((struct Obj00227 *)q)->f4);idx=*(u8 *)(q+24+*(signed char *)&((struct Obj00227 *)q)->fB);
 kind=func_02009864(base,idx,9);
 if(mode==1 || kind==2) ret=NAMEIN_SETUP_CreateArgs(heap,4,65535,0,7,0,v);
 else ret=NAMEIN_SETUP_CreateArgs(heap,4,func_02009864(base,idx,8),0,7,0,v);
 if(((struct Obj00227 *)q)->f64==1) {STRBUF_SetString(((struct Obj03544 *)ret)->f20,(const u16 *)(((struct Obj00227 *)q)->f60));((struct Obj00227 *)q)->f64=0;}
 return ret;
}



/*
 * extent: includes the eight-byte forwarding follower at 0x021C8E24.
 */
void func_021C8E24(void *p,void *q,void *r,u16 s) {
 func_021C8F88(p,q,r,s);
}



/*
 * extent: Includes the eight-byte forwarding follower at 0x021C8F24.
 */
int func_021C8E2C(void *p, u8 *q, u8 *r, int heap)
{
    int v;
    switch (q[8]) {
    case 0:
        func_021C8E24(p, q, r, 52);
        func_021C9180(p, (char *)q, (char *)r);
        q[8] = 1;
        break;
    case 1:
        v = func_021C8F2C(p, (int *)q);
        if (v == 0) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            func_021CA3A0((char *)r);
            q[8] = 2;
        } else if (v == 1) {
            GFL_USE_PlaySeDefaultVolume(0x556);
            func_021CA3C4((char *)r);
            q[8] = 3;
        }
        break;
    case 2:
        if (CLACT_IsActorAnimActive(((struct Obj03813 *)r)->f164) != 1) {
            func_021C6438(q, 0, 2);
            func_021C91CC(p, r);
            func_021C8F24(p, q, r);
            return 1;
        }
        break;
    case 3:
        if (CLACT_IsActorAnimActive(((struct Obj03813 *)r)->f168) != 1) q[8] = 4;
        break;
    case 4:
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, heap);
        q[8] = 5;
        break;
    case 5:
        if (WIPE_SYS_EndCheck() == 1) {
            func_021C6438(q, 6, 0);
            func_021C8F24(p, q, r);
            return 1;
        }
        break;
    }
    return 0;
}



void func_021C8F24(void *p, void *q, void *r)
{
    func_021C9154(p, (int)q, r);
}




int func_021C8F2C(void *unused,int *q) {
 int v=TOUCHPANEL_HitTrg(d_021CA529);
 if(v!=-1) {func_020355D8(1);*q=1;return v;}
 if(KEY_GetTrg()&2) {func_020355D8(0);*q=0;return 0;}
 if(KEY_GetTrg()&1024) {func_020355D8(0);*q=0;return 1;}
 return -1;
}




static inline u8 *second(u8 *p)
{
    return p + 8;
}




/*
 * note 2026-10-05 (wave P5 lane T2): written from the listing, 460 bytes, same size, same
 *   instruction stream. Only residue: the loop counter i and the text buffer are in swapped
 *   callee-saved registers (original text r4, i/const 10 r5; build text r5, i/10 r4), 38 bytes
 *   of register operands plus entry-prologue order. Spill slots match (w1, buf2, gfx, pal, n
 *   declared in that order). Tried: six per-function pragmas (opt_lifetimes, opt_propagation,
 *   opt_common_subs, opt_dead_assignments, scheduling, peephole; none helps, opt_propagation
 *   is worse), decl order of i/x/t/text, do-while loop, i assigned before pal, ctx fields read
 *   inline in the loop (worse), int n. 17 compiles used.
 *   Struct: p is two 8-byte windows (desc at +0, +8), p+0x10 = archive handle, p+0x14 = out ptr;
 *   q+4 holds the save object; ctx+4 bank, +8 archive, +0x34 / +0x17c gfx args. Friend code
 *   screen: u64 key, 12 digits (u64 /10, %10), gap of 8 after every 4th digit.
 *   All callee prototypes already match the arity of the call sites.
 *   recoup 2026-10-05 (lane R20): lever 2 closed the entry-prologue part: heap as u16 here AND
 *   in STRBUF_Create / func_02049EF4 prototypes (38 -> 22 B, the str r3 spill now comes first).
 *   Remaining 22 B: pure colour swap, classes {10, i} and {2, text} swapped (orig r5/r4, build r4/r5).
 *   Tried, no change: u8 heap, text/i decl order, w1 inline, x decl order, long i/x/n, six pragmas
 *   (propagation worse), pal/gfx swap 28, t before call 98, w1 late 39, u32/u8 i 146/130, i<13 24.
 *   Twin search: grep DWC_CreateFriendKey / func_021CA4B4 / STRBUF_AppendChar in src/matched/ov: no loop twin.
 *   Idioms checked: two-long-lived-values-in-each-others-registers (no applicable form),
 *   a-long-index-colours-apart-from-an-int (22), a-colour-swap-...-opt-lifetimes-off (22),
 *   a-loop-counter-zero-before-an-offset-assignment (n/a).
 *   final push 2026-10-05 G5L9 (40 compiles, all 22 B, same pure swap): the (u16) cast on the
 *   third blit argument is dropped (callee takes u16; same bytes, now plain). Tried, no change:
 *   block-scoped t/x/i, declarations at the point of use, u8* text, key decl first/last, i/x
 *   first, STRBUF_AppendChar u16 value, func_021C63AC with u8 fourth parameter, BMP_WIN_GetWidth as u8
 *   (same bytes) with n u32/int/u8, named constants ten/two (int, u8; with opt_propagation off 449 B),
 *   constants as locals in both orders, text/buf2/key as declaration initialisers (30 B, only slot
 *   order moves), inline put()/blit() helpers, struct view of p (two windows), i++ as body statement
 *   (while, for with empty step; i++ before key= is 27 B), pragma pairs (lifetimes+common_subs,
 *   lifetimes+dead_assignments, common_subs+dead_assignments, lifetimes+peephole,
 *   lifetimes+scheduling, common_subs+peephole, dead_assignments+peephole). Reading of mwcc
 *   Coloring.c: nodes with degree >= K are pushed by lowest spill_cost/degree, popped last-first and
 *   take the lowest free colour. Both colourings are legal; in the build i is coloured before text
 *   (i takes r4, then text r5, v10 shares r4 with i, v2 shares r5 with text); the original colours
 *   text first. So the lever is i's cost/degree versus text's, not a declaration order. No human
 *   source form found that lowers i's cost or raises text's without changing the code.
 *   Matched-assembly search: halfword copy loops with a counter (asm/overlays, asm/arm9): only
 *   ov021 021CFB1C, ov093 021D54F4 (leaf copies) share the counter shape; neither shows the rule.
 *   pass 2 2026-10-06 P2L33 (35 compiles): EXACT in --lang c99 and --lang c. The text buffer is
 *   held as a u32 handle (the type TOUCHBAR_PrintAligned takes for its string argument, as the sibling
 *   ov128 021C9FC8 passes a u32 field), with (void *) at the pointer callees. A u32 local and a
 *   pointer local colour differently; with the u32 handle text takes r4 before the held constant
 *   10 and the loop counter, as in the original. Tried before this, no change: a local
 *   u16 digit array with an initialiser, explicit copy loops, inline helpers, statement order,
 *   prototype widths, loop/strength/unroll pragmas, a non-const table.
 */
void func_021C8F88(u8 *p, u8 *q, u8 *ctx, u16 heap)
{
    u8 *w1;
    void *buf2;
    u32 gfx;
    u32 pal;
    u32 n;
    u32 text;
    u64 key;
    Tbl t;
    int x;
    int i;
    func_021C63AC(ctx, (u32 *)p, 3, 2, 10, 0x1e, 8, 10, 1, 0);
    func_021C63AC(ctx, (u32 *)(p + 8), 3, 9, 6, 0xe, 2, 10, 0xf1, 0);
    text = (u32)STRBUF_Create(0xc0, heap);
    buf2 = STRBUF_Create(0x80, heap);
    key = DWC_CreateFriendKey((struct DWCstAccUserData *)func_02009860((void *)func_0201283C(*(void **)(q + 4))));
    if (key != 0) {
        func_02045CAC(*(void **)(ctx + 4), 0x35, (void *)text);
        TOUCHBAR_PrintAligned(p, (void *)(*(u32 *)(ctx + 0x34)), 4, 0, text, *(u32 *)(ctx + 0x17c), 0x440, 0);
        func_021CA4B4(*(char **)p);
        pal = *(u32 *)(ctx + 0x17c);
        gfx = *(u32 *)(ctx + 0x34);
        t = d_021CA674;
        x = 0;
        n = BMP_WIN_GetWidth(*(void **)(p + 8));
        w1 = second(p);
        for (i = 1; i <= 12; i++) {
            STRBUF_Clear((void *)text);
            STRBUF_AppendChar((void *)text, t.v[key % 10]);
            TOUCHBAR_PrintAligned(w1, (void *)gfx, (n - i) * 8 - x + 1, 0, text, pal, 0x3c40, 0);
            if (i % 4 == 0)
                x += 8;
            key = key / 10;
        }
        func_021CA4B4(*(char **)(p + 8));
    } else {
        func_02045CAC(*(void **)(ctx + 4), 0x36, (void *)text);
        TOUCHBAR_PrintAligned(p, (void *)(*(u32 *)(ctx + 0x34)), 4, 0, text, *(u32 *)(ctx + 0x17c), 0x440, 0);
        func_021CA4B4(*(char **)p);
    }
    STRBUF_Delete((void *)text);
    STRBUF_Delete(buf2);
    *(void **)(p + 0x10) = func_02049EF4(*(void **)(ctx + 8), 6, 0, (void **)(p + 0x14), heap);
}




void func_021C9154(char *p,int unused,char *q) { func_021CA444(q);func_021CA458(q,q+12);BMP_WIN_Delete(((struct Obj10489 *)p)->f0);BMP_WIN_Delete(((struct Obj10489 *)p)->f8);func_020307B0(((struct Obj10489 *)p)->f10);}




void func_021C9180(char *p,char *q,char *r) {
 char *s;
 func_0201F02C(((struct Obj00329 *)r)->f0,0,func_02012944(((struct Obj23102 *)q)->f4));
 func_021C6ADC((u8 *)r,(u8 *)(r+12),50);
 s=*(char * *)&((struct Obj10490 *)p)->f14;
 func_02041090(2,(u32)(s+12),0,0,(((struct Obj14044 *)s)->f0>>3)&255,(((struct Obj14044 *)s)->f2>>3)&255);
 func_02041B6C(2);
}




void func_021C91CC(char *p,void *q) {
 void *v;
 func_021C6B38(q);
 func_02041300(2,0,0,0,32,24,0);func_02041B6C(2);
 v=((struct Obj10490 *)p)->f0;BMP_WIN_ClearScreen(v);func_02041B6C(BMP_WIN_GetBgLayer(v));
 v=((struct Obj10490 *)p)->f8;BMP_WIN_ClearScreen(v);func_02041B6C(BMP_WIN_GetBgLayer(v));
 func_02041300(3,0,0,0,32,24,0);func_02041B6C(3);
}




void func_021C9238(u8 *p,u8 *b,u8 *c,u16 d) { ((struct Obj23103 *)p)->f10=1; func_021C9628(p,b,c,d); }




int func_021C9244(u8 *p,u8 *q,u8 *r,u16 heap)
{
    switch(q[8]) {
    case 0:
        ((struct Obj00773 *)p)->fE=0; ((struct Obj00773 *)p)->f0=0;
    case 1:
        func_021C9238(p,q,r,heap);
        func_021C97A0(p,q,r,heap);
        q[8]=2;
        break;
    case 2: q[8]=func_021C9544(p,(int *)q,(char *)r); break;
    case 3:
        func_021C958C((char *)p,q,r,heap);
        func_021C95CC(p,q,r,heap);
        q[8]=4; break;
    case 4: if(func_021C95CC(p,q,r,heap)==1)q[8]=5; break;
    case 5:
        if(PRINTSYS_QUE_IsFinished(((struct Obj10491 *)r)->f34)==1) {
            func_02041EE4(2,0,0);func_02041EE4(3,0,0);q[8]=2;
        } break;
    case 6:
        if(((struct Obj00773 *)p)->fE) {
            --((struct Obj00773 *)p)->fC;
            if(((struct Obj00773 *)p)->fC)break;
        }
        if(func_021C9D0C(q,((struct Obj00773 *)p)->f8)) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            func_021C98EC((char *)p,r);
            func_021C6438(q,4,1);
            ((struct Obj00773 *)p)->fE=1;
            func_021C9730(p,q,r);
            return 1;
        } else q[8]=2;
        break;
    case 7:
        if(CLACT_IsActorAnimActive(((struct Obj10491 *)r)->f164)!=1) {
            func_021C987C(p,r);
            func_021C6438(q,1,11);
            func_021C9730(p,q,r);
            return 1;
        } break;
    case 8: if(CLACT_IsActorAnimActive(((struct Obj10491 *)r)->f168)!=1)q[8]=9; break;
    case 9: WIPE_SYS_Start(0,0,0,0,6,1,heap);q[8]=10;break;
    case 10: if(WIPE_SYS_EndCheck()) {
        func_021C6438(q,6,0);func_021C9730(p,q,r);return 1;
        }break;
    }
    return 0;
}




int func_021C93C0(char *p,void *q,void *r,int n) {
 switch(n) {
 case 0:GFL_USE_PlaySeDefaultVolume(0x551);func_021CA3A0(r);return 7;
 case 1:GFL_USE_PlaySeDefaultVolume(0x556);func_021CA3C4(r);return 8;
 case 2:if(func_021C9D88(q,0)==1) {((struct Obj08131 *)p)->fC=4;((struct Obj08131 *)p)->f8=0;func_021C6E18(r,1,11);return 6;}break;
 case 3:if(func_021C9D88(q,1)==1) {((struct Obj08131 *)p)->fC=4;((struct Obj08131 *)p)->f8=1;func_021C6E18(r,0,10);return 6;}break;
 }
 return 2;
}




int func_021C9450(void *p,int *q,void *r) {
 if(*q==1 && (KEY_GetTrg()&0xcf3)) {func_020355D8(0);*q=0;}
 if(KEY_GetTrg()&2)return func_021C93C0(p,q,r,0);
 if(KEY_GetTrg()&1024)return func_021C93C0(p,q,r,1);
 if(KEY_GetCont()&64)return func_021C93C0(p,q,r,2);
 if(KEY_GetCont()&128)return func_021C93C0(p,q,r,3);
 return 2;
}




int func_021C94DC(void *p,void *q,void *r,int *flag) {
 int v=TOUCHPANEL_HitTrg(d_021CA576);
 if(v==-1)return 2;
 *flag=1;
 if(v==0)return func_021C93C0(p,q,r,3);
 if(v==1)return func_021C93C0(p,q,r,2);
 if(v==2)return func_021C93C0(p,q,r,0);
 return func_021C93C0(p,q,r,1);
}




int func_021C9544(void *p,int *q,char *r) {
 int flag=0; int ret;
 if(!PRINTSYS_QUE_IsFinished(((struct Obj23105 *)r)->f34)) return 2;
 ret=func_021C94DC(p,q,r,&flag);
 if(flag) {func_020355D8(1); *q=1; return ret;}
 return func_021C9450(p,q,r);
}




void func_021C958C(char *p, void *q, void *r, int s) {
 int mode;
 ((struct Obj10493 *)p)->f4=0;
 func_021C6DF8(r,0);
 mode=(((struct Obj10493 *)p)->f8==2)?2:1;
 func_021C9BEC((u16 *)p,q,r,mode,((struct Obj10493 *)p)->f0,s);
 GFL_USE_PlaySeDefaultVolume(0x548);
}




/*
 * extent: two-byte zero padding at 021C9626 before next label 021C9628.
 */
int func_021C95CC(u8 *p,void *a,void *b,int c)
{
    int value=((struct Obj02842 *)p)->f4;
    int offset;
    if(value>8) {
        func_021C9BEC((u16 *)p,a,b,0,((struct Obj02842 *)p)->f0,c);
        func_021C6DF8(b,1);
        func_021C9BF8(p,b,255);
        return 1;
    }
    offset=(value*256)/8;
    if(((struct Obj02842 *)p)->f8==2) offset=-offset;
    func_02040618(3,0,offset);
    ((struct Obj02842 *)p)->f4=((struct Obj02842 *)p)->f4+1;
    return 0;
}




static inline int absolute(s16 value) { if (value < 0) return -value; return value; }




/*
 * note 2026-10-05: the matched callees func_021C9ED0 and func_021C9EF4 declare 4 parameters,
 *   but this caller passes the heap id as a stack argument (5th for 9ED0, 6th for 9EF4); the
 *   prototypes below carry the real arity. The heap id is u16 here and in all callee prototypes
 *   (narrow param puts its home store first); the inner counter is long.
 */
void func_021C9628(u8 *p, void *unused, u8 *q, u16 heap)
{
    int i, k, x, y; long j;
    const s16 *row;
    func_021C9E10(p + 0xf8, q, heap);
    func_021C9E6C(p, q);
    for (k = 0; k < 2; k++) {
        row = d_021CA564[k];
        y = absolute(row[1]);
        x = absolute(row[0]);
        func_021C63AC(q, (u32 *)(p + 0x118 + k * 8), 3, (u8)(x + 2), y + 1, 26, 18, 10, 0, 0);
    }
    for (i = 0; i < 3; i++) {
        func_021C9ED0((u32)(p + 20 + i * 0x4c), (int)q, (const u16 *)d_021CA564[i], d_021CA538[i], heap);
        for (j = 0; j < 8; j++) {
            func_021C9EF4((u32)(p + 20 + i * 0x4c), (int)q, j, d_021CA521[j], d_021CA7E0[j], heap);
            *(void **)(p + 0x20 + j * 4) = p + 0x118;
            *(void **)(p + 0x6c + j * 4) = p + 0x120;
            *(void **)(p + 0xb8 + j * 4) = p + 0x120;
        }
    }
}




/*
 * extent: two-byte zero padding at 021C979E before next label 021C97A0.
 */
void func_021C9730(u8 *p,void *unused,u8 *q)
{
    u8 *base;
    int j;
    int i;
    func_021CA444((char *)q);
    func_021CA458((char *)q,q+12);
    base=p+20;
    for(i=0;i<3;i++) {
        for(j=0;j<8;j++) func_021C9EFC((Record *)(base+i*76), j);
        func_021C9EF0(base+i*76);
    }
    for(i=0;i<2;i++) BMP_WIN_Delete(*(void **)(p+i*8+0x118));
    func_021C9EB4(p,q);
    p+=0xf8;
    func_021C9E54(p);
}




/*
 * lever: u16 heap keeps its word spill before the first indexed load.
 */
void func_021C97A0(u8 *p,u8 *q,u8 *r,u16 heap)
{
    u16 *t;
    func_021C6BCC(r,(u8 *)q,(q+((struct Obj00992 *)q)->fB)[24],heap);
    func_021C6ADC(r,r+12,13);
    t=*(u16 * *)&((struct Obj00773 *)p)->fFC;
    func_02041090(0,(u32)((u8 *)t+12),0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(0);
    t=*(u16 * *)&((struct Obj00773 *)p)->f104;
    func_02041090(2,(u32)((u8 *)t+12),0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(2);
    func_021C991C(p,(u8 *)q,r,heap);
    func_021C9BEC((u16 *)p,(u8 *)q,r,0,*(s16 *)&((struct Obj00773 *)p)->f0,heap);
    if(func_021C9D88((u8 *)q,0)==1) {
        func_021C6E18(r,1,3);
        func_021C6E18(r,0,2);
    } else {
        func_021C6E18(r,1,17);
        func_021C6E18(r,0,16);
    }
    func_021C6DD8(r,1);
}




void func_021C987C(u8 *p,u8 *q)
{
    u16 *t;
    func_021C6DD8(q,0);
    func_021C9CCC(p,q);
    func_021C9BC4((u32)p);
    func_02041300(2,0,0,0,32,32,0);
    func_02041B6C(2);
    t=*(u16 * *)&((struct Obj00773 *)p)->f10C;
    func_02041090(0,(u32)((u8 *)t+12),0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(0);
    func_021C6B38(q);
    func_021CA4C8((int *)p);
}




void func_021C98EC(char *p,u8 *q) {char *base;int i;i=0;base=p+20;for(;i<3;i++) func_021C9F6C(base+i*76,q);func_021C6B38(q);func_021CA4C8((int *)p);}




/*
 * calls: 0202DA18/48 and 0204B294 leave the consumed handle in r0 despite
 * their void declarations. Heap externs are widened when no truncation
 * occurs. 0202DA04's legacy a1-a3 are neither read nor forwarded.
 * bounds: two unsigned loops cover ten eight-byte records at p+0x128;
 * signed q[11] accesses retain modular address arithmetic.
 */
void func_021C991C(u8 *p,u8 *q,u8 *ctx,u16 heap)
{
    u32 i,base,id,archive,offset;
    int pos;
    Bounds bounds;
    base=func_0201283C(((struct Obj00992 *)q)->f4);
    func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),9);
    for(i=0;i<10;i++) BMP_Clear(BMP_WIN_GetBmp(*(void **)(p+i*8+0x128)),0);
    offset=0x128;
    pos=BMP_WIN_GetDispWidth(*(void **)(p+offset));
    TOUCHBAR_PrintYesNoCancelLabels((u32)(p+offset),(void *)(*(u32 *)&((struct Obj00329 *)ctx)->f34),*(u32 *)&((struct Obj00329 *)ctx)->f17C,
        (int)((u32)pos*8)/2,0,0x3C40,
        *(u8 *)((u32)q+((struct Obj00992 *)q)->fB+0x38)+1,((struct Obj00992 *)q)->f14,heap);
    func_021C9FC8(p+(offset+8),q,ctx,19,0,0,0x3C40);
    func_021C9FC8(p+(offset+16),q,ctx,20,0,0,0x3C40);
    func_021C9FC8(p+0x140,q,ctx,21,0,0,0x3C40);
    func_021C6C94((char **)ctx,func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),2));
    func_021C9FC8(p+(offset+32),q,ctx,22,0,0,0x3C40);
    func_021C6C94((char **)ctx,func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),3));
    func_021C9FC8(p+0x150,q,ctx,22,0,0,0x3C40);
    func_021C9FC8(p+(offset+48),q,ctx,23,0,0,0x3C40);
    func_021C6C94((char **)ctx,func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),4));
    func_021C9FC8(p+0x160,q,ctx,24,0,0,0x3C40);
    func_021C9FC8(p+(offset+=64),q,ctx,27,0,0,0x3C40);
    if(func_021C6C20(ctx,q,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24))!=0)
        func_021C9FC8(p+0x170,q,ctx,28,0,0,0x3C40);
    else BMP_WIN_TransferChars(((struct Obj00773 *)p)->f170);
    for(i=0;i<10;i++) func_021CA4B4(*(char **)(p+i*8+0x128));
    bounds=d_021CA640;
    id=func_02025C88(func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),8));
    archive=POKEGRA_OpenTrainerHandle(heap);
    ((struct Obj00773 *)p)->f17C=POKEGRA_RegisterTrainerCgr(archive,id,0,heap);
    ((struct Obj00773 *)p)->f180=POKEGRA_RegisterTrainerPalette(archive,id,0,192,heap);
    ((struct Obj00773 *)p)->f184=POKEGRA_RegisterTrainerCellAnim(id,2,0,heap);
    ARC_TOOL_DeleteHandle((void *)archive);
    ((struct Obj00773 *)p)->f178=(u32)CLACT_CreateActor((void *)((struct Obj00329 *)ctx)->f138,((struct Obj00773 *)p)->f17C,
        ((struct Obj00773 *)p)->f180,((struct Obj00773 *)p)->f184,&bounds,0,heap);
}




void func_021C9BC4(u32 p) { int i;void *q;for(i=0;i<10;i++) {q=*(void **)(p+296+i*8);BMP_WIN_ClearScreen(q);func_02041B6C(BMP_WIN_GetBgLayer(q));}}




void func_021C9BEC(u16 *p, void *b, void *c, int flag, int value, int a5) { if(flag==0) *p=value; }




/*
 * lever: the table value in r1 supplies both destination x and clip x;
 * raw u32 address arithmetic preserves base-plus-row accesses without
 * imposing unproven row or index bounds; all shifts/adds wrap at 32 bits.
 */
void func_021C9BF8(u8 *p,u8 *q,int idx)
{
    u16 *t;
    if (((struct Obj02842 *)p)->f10==1) {
        t=*(u16 * *)&((struct Obj10494 *)q)->f178;
        func_020410D0(2,0,20,32,4,(u32)((u8 *)t+12),0,12,(u32)t[0]>>3,(u32)t[1]>>3);
    } else {
        t=*(u16 * *)&((struct Obj10494 *)q)->f178;
        func_020410D0(2,0,20,32,4,(u32)((u8 *)t+12),0,20,(u32)t[0]>>3,(u32)t[1]>>3);
    }
    if (idx==255) {
        func_02041B6C(2);
        return;
    }
    t=*(u16 * *)&((struct Obj10494 *)q)->f178;
    func_020410D0(2,*(const u8 *)((u32)d_021CA544+((u32)((struct Obj02842 *)p)->f10<<3)+(u32)idx),20,
        *(const u8 *)((u32)d_021CA554+((u32)((struct Obj02842 *)p)->f10<<3)+(u32)idx),4,(u32)((u8 *)t+12),
        *(const u8 *)((u32)d_021CA544+((u32)((struct Obj02842 *)p)->f10<<3)+(u32)idx),
        *(const u8 *)((u32)d_021CA4F7+(u32)((struct Obj02842 *)p)->f10),(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(2);
}




void func_021C9CCC(void *unused,u8 *p)
{
    u16 *q = *(u16 * *)&((struct Obj14046 *)p)->f178;
    func_020410D0(2,0,20,32,4,(u32)((u8 *)q+12),0,28,(u32)q[0]>>3,(u32)q[1]>>3);
    func_02041B6C(2);
}




/*
 * extent: two-byte zero padding at 021C9D86 before next label 021C9D88.
 */
int func_021C9D0C(u8 *p,int direction)
{
    int index;
    u32 data;
    u32 count;
    data=func_0201283C(((struct Obj00227 *)p)->f4);
    index=*(s8 *)&((struct Obj00227 *)p)->fB;
    if(direction==0) {
        for(count=0;count<((struct Obj00227 *)p)->f10-1;count++) {
            index--;
            if(index<0) index+=((struct Obj00227 *)p)->f10;
            if(func_02009864((const struct Sub020097BCObj *)data,p[index+24],9)!=2) {
                p[11]=index;
                return 1;
            }
        }
    } else {
        for(count=0;count<((struct Obj00227 *)p)->f10-1;count++) {
            index=(u32)(index+1)%((struct Obj00227 *)p)->f10;
            if(func_02009864((const struct Sub020097BCObj *)data,p[index+24],9)!=2) {
                p[11]=index;
                return 1;
            }
        }
    }
    return 0;
}




/*
 * extent: two-byte zero padding at 021C9E0E before next label 021C9E10.
 * lever: writing the reloaded signed byte on the left of == fixes both cmp operands.
 */
int func_021C9D88(u8 *p,int direction)
{
    int index;
    u32 data;
    u32 count;
    data=func_0201283C(((struct Obj00992 *)p)->f4);
    index=((struct Obj00992 *)p)->fB;
    if(direction==0) {
        for(count=0;count<((struct Obj00992 *)p)->f10-1;count++) {
            index--;
            if(index<0) index+=((struct Obj00992 *)p)->f10;
            if(((struct Obj00992 *)p)->fB==index) goto fail;
            if(func_02009864((const struct Sub020097BCObj *)data,p[index+24],9)!=2) return 1;
        }
    } else {
        for(count=0;count<((struct Obj00992 *)p)->f10-1;count++) {
            index=(u32)(index+1)%((struct Obj00992 *)p)->f10;
            if(((struct Obj00992 *)p)->fB==index) goto fail;
            if(func_02009864((const struct Sub020097BCObj *)data,p[index+24],9)!=2) return 1;
        }
    }
fail:
    return 0;
}




void func_021C9E10(u8 *p,u8 *q,u16 heap)
{
    u16 ids[4];
    int i;
    ids[0]=d_021CA648[0]; ids[1]=d_021CA648[1];
    ids[2]=d_021CA648[2]; ids[3]=d_021CA648[3];
    for(i=0;i<4;i++) {
        ((struct Obj23107 *)p)->f0=func_02049EF4(((struct Obj23108 *)q)->f8,ids[i],0,(void **)(p+4),heap);
        p+=8;
    }
}





/*
 * Addresses are Black-image addresses.
 */
void func_021C9E54(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        func_020307B0(((struct Obj23109 *)p)->f0);
        p += 8;
    }
}




void func_021C9E6C(u8 *p,void *q)
{
    int i;
    p+=0x128;
    for(i=0;i<10;i++)
        func_021C63AC(q,(u32 *)(p+i*8),1,d_021CA5A2[i][0],d_021CA5A2[i][1],d_021CA5A2[i][2],d_021CA5A2[i][3],10,0,0);
}





void func_021C9EB4(u8 *p, void *a1)
{
    int i;
    for (i = 0; i < 10; i++)
        BMP_WIN_Delete(*(void **)(p + 0x128 + i * 8));
}




void func_021C9ED0(u32 p,int unused,const u16 *q,u32 value,u16 heap) { int i; ((struct Obj08133 *)p)->f8=value; ((struct Obj08133 *)p)->f0=q[0]; ((struct Obj08133 *)p)->f2=q[1]; ((struct Obj08133 *)p)->f4=q[2]; for(i=0;i<8;i++) *(u32 *)(p+44+i*4)=0; }



void func_021C9EF0(void *a0) {}



void func_021C9EF4(u32 p,int unused,u32 index,u32 value,u32 unused5,u16 heap) { *(u32 *)(p+44+index*4)=value; }



/*
 * volatile: 021C9F1E rereads loop bound field, also entry021C9F0E.
 */
void func_021C9EFC(Record *p,u32 index) {u8 i;if(p->items[index]){for(i=0;i<p->count[index];i++) {} p->items[index]=0;p->count[index]=0;}}



void func_021C9F30(char *p,u32 index) {u32 i;void *q;char *base;base=p+index*4;for(i=0;i<((struct Obj10496 *)base)->f2C;i++){BMP_Clear(BMP_WIN_GetBmp(**(void ** *)&((struct Obj10496 *)base)->fC),0);q=**(void ** *)&((struct Obj10496 *)base)->fC;BMP_WIN_ClearScreen(q);func_02041B6C(BMP_WIN_GetBgLayer(q));}}



void func_021C9F6C(char *p,void *q) { int i; for(i=0;i<8;i++)func_021C9F30(p,i);func_021C9F8C(q,p); }



static inline int ab(int x) { return x<0?-x:x; }



void func_021C9F8C(void *q,char *p) { func_02041300(3,0,ab(((struct Obj14048 *)p)->f0),ab(((struct Obj14048 *)p)->f2),32,24,0);func_02041B6C(3); }



void func_021C9FC8(u8 *p,void *unused,u8 *q,u32 item,int x,int y,int color)
{
    func_02045CAC(((struct Obj00329 *)q)->f4,item,((struct Obj00329 *)q)->f20);
    func_0201F250(((struct Obj00329 *)q)->f0,(void *)(((struct Obj00329 *)q)->f1C),((struct Obj00329 *)q)->f20);
    TOUCHBAR_PrintAligned(p,(void *)(*(u32 *)&((struct Obj00329 *)q)->f34),x,y,((struct Obj00329 *)q)->f1C,*(u32 *)&((struct Obj00329 *)q)->f17C,color,0);
}



/*
 * lever: initialize value before *ok; multiply and add the u64 digit separately;
 *        cast the u16 counter to int for its bound, and share failure via done.
 */
u64 func_021CA014(void *p,int *ok)
{
    u16 end=STRBUF_GetEosChar();
    u16 *text=STRBUF_GetChars(p);
    u64 value;
    u16 i;
    u16 digit;
    value=0;
    *ok=0;
    i=0;
    while(text[i]!=end) {
        if((int)i>=18) goto done;
        digit=(u16)(text[i]-0x30);
        if(digit>=10) {
            digit=(u16)(text[i]-0xff10);
            if(digit>=10) goto done;
        }
        value*=10;
        value+=(u64)digit;
        i++;
    }
    *ok=1;
done:
    return value;
}



/*
 * extent: two trailing bytes of zero alignment padding.
 */
int func_021CA084(int *p) { if(TOUCHPANEL_GetTrg()==1) {func_020355D8(1);*p=1;return 1;} if(KEY_GetTrg()&3) {func_020355D8(0);*p=0;return 1;} return 0; }



void func_021CA0BC(u8 *p,u16 heap)
{
    ((struct Obj03812 *)p)->f184=BLINK_PALANM_Create(48,16,0,heap);
    BLINK_PALANM_LoadPalettes(((struct Obj03812 *)p)->f184,*(u8 * *)&((struct Obj03812 *)p)->f8,0,32,48);
    ((struct Obj03812 *)p)->f188=BLINK_PALANM_Create(16,16,0xfffe,heap);
    BLINK_PALANM_LoadPalettes(((struct Obj03812 *)p)->f188,*(u8 * *)&((struct Obj03812 *)p)->f8,2,0,16);
}




void func_021CA10C(u8 *p)
{
    func_0202EA20(((struct Obj00725 *)p)->f188);
    func_0202EA20(((struct Obj00725 *)p)->f184);
}



void func_021CA124(u32 a,u32 b) {func_020413B0(2,2,(a+1)*5,28,4,b);func_02041B6C(2);}




void func_021CA154(u8 *p, int a)
{
    func_021CA124(a, 1);
    BLINK_PALANM_ResetPhase(((struct Obj00329 *)p)->f184);
}




void func_021CA16C(u8 *p, int a)
{
    func_021CA124(a, 3);
    BLINK_PALANM_ResetPhase(((struct Obj00329 *)p)->f184);
}




void func_021CA184(u8 *p, int a, int b)
{
    func_021CA154(p, b);
    func_021CA16C(p, a);
}



/*
 * extent: two-byte zero padding at 021CA1DE; next labelled function 021CA1E0.
 */
void func_021CA19C(unsigned *p)
{
    unsigned i;
    if(func_020355C4()==1) {
        for(i=0;i<3;i++) func_021CA124(i,1);
        return;
    }
    for(i=0;i<3;i++) {
        if(i==*p) func_021CA124(i,3);
        else func_021CA124(i,1);
    }
}



/*
 * Extent ends with two bytes of zero alignment padding.
 */
int func_021CA1E0(char *p)  {
    switch(((struct Obj00774 *)p)->f8)  {
        case 0: func_021CA124((u32)(((struct Obj00774 *)p)->f0),1);
        ((struct Obj00774 *)p)->fA=0;
        (((struct Obj00774 *)p)->f8)++;
        break;
        case 1: (((struct Obj00774 *)p)->fA)++;
        if(((struct Obj00774 *)p)->fA==4)  {
            func_021CA124((u32)(((struct Obj00774 *)p)->f0),2);
            ((struct Obj00774 *)p)->fA=0;
            (((struct Obj00774 *)p)->f8)++;
        }
        break;
        case 2: (((struct Obj00774 *)p)->fA)++;
        if(((struct Obj00774 *)p)->fA==4)  {
            func_021CA124((u32)(((struct Obj00774 *)p)->f0),1);
            ((struct Obj00774 *)p)->fA=0;
            (((struct Obj00774 *)p)->f8)++;
        }
        break;
        case 3: (((struct Obj00774 *)p)->fA)++;
        if(((struct Obj00774 *)p)->fA==4)  {
            func_021CA124((u32)(((struct Obj00774 *)p)->f0),2);
            ((struct Obj00774 *)p)->fA=0;
            (((struct Obj00774 *)p)->f8)++;
        }
        break;
        case 4: (((struct Obj00774 *)p)->fA)++;
        if(((struct Obj00774 *)p)->fA==4)  {
            ((struct Obj00774 *)p)->f8=0;
            ((struct Obj00774 *)p)->fA=0;
            return 0;
        }
        break;
    }
    return 1;
}



void func_021CA25C(u32 a,u32 b) {func_020413B0(2,(a>>2)*14+2,(a&3)*4+4,14,4,b);func_02041B6C(2);}




void func_021CA294(u8 *p, int a)
{
    func_021CA25C(a, 1);
    BLINK_PALANM_ResetPhase(((struct Obj14051 *)p)->f184);
}




void func_021CA2AC(u8 *p, int a)
{
    func_021CA25C(a, 3);
    BLINK_PALANM_ResetPhase(((struct Obj14051 *)p)->f184);
}




void func_021CA2C4(u8 *p, int a, int b)
{
    func_021CA294(p, b);
    func_021CA2AC(p, a);
}



void func_021CA2DC(char *p)  {
    unsigned i;
    if(func_020355C4()==1)  {
        for(i=0;i<8;i++) func_021CA25C(i,1);
    }
    else  {
        for(i=0;i<8;i++)  {
            if(i==((struct Obj23113 *)p)->f4) func_021CA25C(i,3);
            else func_021CA25C(i,1);
        }
    }
}



int func_021CA320(char *p)  {
    switch(((struct Obj00775 *)p)->f8)  {
        case 0: func_021CA25C(((struct Obj00775 *)p)->f4,1);
        ((struct Obj00775 *)p)->fA=0;
        (((struct Obj00775 *)p)->f8)++;
        break;
        case 1: (((struct Obj00775 *)p)->fA)++;
        if(((struct Obj00775 *)p)->fA==4)  {
            func_021CA25C(((struct Obj00775 *)p)->f4,2);
            ((struct Obj00775 *)p)->fA=0;
            (((struct Obj00775 *)p)->f8)++;
        }
        break;
        case 2: (((struct Obj00775 *)p)->fA)++;
        if(((struct Obj00775 *)p)->fA==4)  {
            func_021CA25C(((struct Obj00775 *)p)->f4,1);
            ((struct Obj00775 *)p)->fA=0;
            (((struct Obj00775 *)p)->f8)++;
        }
        break;
        case 3: (((struct Obj00775 *)p)->fA)++;
        if(((struct Obj00775 *)p)->fA==4)  {
            func_021CA25C(((struct Obj00775 *)p)->f4,2);
            ((struct Obj00775 *)p)->fA=0;
            (((struct Obj00775 *)p)->f8)++;
        }
        break;
        case 4: (((struct Obj00775 *)p)->fA)++;
        if(((struct Obj00775 *)p)->fA==4)  {
            ((struct Obj00775 *)p)->f8=0;
            ((struct Obj00775 *)p)->fA=0;
            return 0;
        }
        break;
    }
    return 1;
}



void func_021CA3A0(char *p) {CLACT_SetActorAnimFrame(((struct Obj03813 *)p)->f164,0);CLACT_SetActorAnimSeq(((struct Obj03813 *)p)->f164,9);CLACT_SetActorAutoAnim(((struct Obj03813 *)p)->f164,1);}



void func_021CA3C4(char *p) {CLACT_SetActorAnimFrame(((struct Obj03813 *)p)->f168,0);CLACT_SetActorAnimSeq(((struct Obj03813 *)p)->f168,8);CLACT_SetActorAutoAnim(((struct Obj03813 *)p)->f168,1);}



void func_021CA3E8(int a) {if(a==1)func_0207D658(0x04000050,28,0);else func_0207D658(0x04000050,28,-8);}



void func_021CA40C(char *p, int n) {CLACT_SetActorAnimFrame(((struct Obj00179 *)p)->f1A4,0);CLACT_SetActorAnimSeq(((struct Obj00179 *)p)->f1A4,n+2);}




void func_021CA42C(char *p)
{
    BMP_WIN_MakeScreen(((struct Obj14052 *)p)->fC);
    func_02041B6C(BMP_WIN_GetBgLayer(((struct Obj14052 *)p)->fC));
}



void func_021CA444(char *p)
{
    unsigned int i;

    for (i = 0; i < 0x40; i++)
        *(unsigned int *)(p + i * 4 + 0x38) = 0;
}




void func_021CA458(char *p,void *q) {u32 i;for(i=0;i<64;i++) {if(!*(void **)(p+i*4+56)) {*(void **)(p+i*4+56)=q;return;}}}



void func_021CA478(char *p) {u32 i;char *q;void *v;for(i=0;i<64;i++){q=*(char **)(p+i*4+56);if(!q)break;v=((struct Obj06477 *)p)->f34;if(((struct Obj08135 *)q)->f4) {if(!PRINTSYS_QUE_IsExistTarget(v,BMP_WIN_GetBmp(((struct Obj08135 *)q)->f0))) {BMP_WIN_TransferChars(((struct Obj08135 *)q)->f0);((struct Obj08135 *)q)->f4=0;}}}}




void func_021CA4B4(char *p)
{
    BMP_WIN_MakeScreen((struct Cfg *)p);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)p));
}
