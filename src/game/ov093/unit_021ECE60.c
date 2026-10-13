/*
 * file:     unit_021ECE60.c
 * unit:     yes
 * function: func_021ECE60, func_021ECEB8, func_021ECF50, func_021ECF68, func_021ED118, func_021ED158, func_021ED1B0, func_021ED208, func_021ED250, func_021ED268, func_021ED280, func_021ED294, func_021ED2BC, func_021ED2D0, func_021ED304, func_021ED318, func_021ED374, func_021ED384, func_021ED3D4, func_021ED450, func_021ED460, func_021ED494, func_021ED4D0, func_021ED4E4, func_021ED510, func_021ED53C, func_021ED554, func_021ED56C, func_021ED57C, func_021ED590, func_021ED5D8, func_021ED5E8, func_021ED660, func_021ED6BC, func_021ED714, func_021ED724, func_021ED76C, func_021ED798, func_021ED7C8, func_021ED814, func_021ED8AC, func_021ED8D8, func_021ED8E8, func_021ED930, func_021ED988, func_021ED9A4, func_021ED9C8, func_021ED9EC, func_021EDA04, func_021EDA3C, func_021EDA5C, func_021EDA94, func_021EDAB0, func_021EDAE0, func_021EDB00, func_021EDB20, func_021EDB3C, func_021EDBE8, func_021EDC28, func_021EDCA8, func_021EDE54, func_021EDF4C, func_021EDF78, func_021EDF7C, func_021EDFC4
 * address:  0x021ECE60
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BMP_Clear  0x02043B5C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BTL_MAIN_GetTextSpeedFrames  0x021B85DC  thumb  ov093
 *   PRINTSYS_PrintStreamCallBack  0x0201CD10  thumb
 *   PRINTSYS_PrintStreamStop  0x0201CE0C  thumb
 *   BTL_MAIN_GetCommPos  0x021B86C0  thumb  ov093
 *   PRINTSYS_PrintStreamRun  0x0201CE20  thumb  arm9
 *   PRINTSYS_PrintStreamIsOverrideSpeed  0x0201CED4  thumb  arm9
 *   func_0201CE8C  0x0201CE8C  thumb  arm9
 *   func_02013080  0x02013080  thumb  arm9
 *   func_0201CEB8  0x0201CEB8  thumb  arm9
 *   func_0201CE30  0x0201CE30  thumb  arm9
 *   func_0203630C  0x0203630C  arm  arm9
 *   TOUCHPANEL_GetCont  0x02035C38  arm  arm9
 *   func_020362DC  0x020362DC  arm  arm9
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   func_0201DD68  0x0201DD68  thumb  arm9
 *   func_0201CE48  0x0201CE48  thumb  arm9
 *   func_0201CE38  0x0201CE38  thumb  arm9
 *   GFL_USE_IsSeqPlaying  0x02006254  thumb  arm9
 *   func_020061E4  0x020061E4  thumb  arm9
 *   func_021F7B2C  0x021F7B2C  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021F80FC  0x021F80FC  thumb  ov094
 *   func_021F7C2C  0x021F7C2C  thumb  ov094
 *   func_021F8118  0x021F8118  thumb  ov094
 *   func_021F8180  0x021F8180  thumb  ov094
 *   func_021F80E4  0x021F80E4  thumb  ov094
 *   func_021F7CE4  0x021F7CE4  thumb  ov094
 *   func_021F7F04  0x021F7F04  thumb  ov094
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   func_021F7EE8  0x021F7EE8  thumb  ov094
 *   func_020311B8  0x020311B8  arm
 *   TCBL_GetWork  0x02031290  arm
 *   func_021F7A28  0x021F7A28  thumb  ov094
 *   TCBL_DeleteTask  0x02031194  arm
 *   func_021B9920  0x021B9920  thumb  ov093
 *   func_021F87D4  0x021F87D4  thumb  ov094
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   func_021F7D80  0x021F7D80  thumb  ov094
 *   func_021F7E38  0x021F7E38  thumb  ov094
 *   func_021F803C  0x021F803C  thumb  ov094
 *   func_021B8ED8  0x021B8ED8  thumb  ov093
 *   func_0207D63C  0x0207D63C  arm  arm9
 *   func_02045770  0x02045770  arm
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   BTL_MAIN_GetRuleSlotSpan  0x021B8640  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   func_021B9AE0  0x021B9AE0  thumb  ov093
 *   BTL_MAIN_IsLocalSide  0x021B8BD0  thumb  ov093
 *   func_021F8504  0x021F8504  thumb  ov094
 *   func_021F8B28  0x021F8B28  thumb  ov094
 *   func_02049DB4  0x02049DB4  arm
 *   BMP_Create  0x02043678  arm
 *   BMP_Delete  0x020437AC  arm
 *   func_020307B0  0x020307B0  arm
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021F8AE8  0x021F8AE8  thumb  ov094
 *   func_02040B1C 0x02040B1C arm
 *   func_02040618 0x02040618 arm
 *   BMP_GetPixels 0x020437D4 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   BMP_GetByteSize 0x020437EC arm
 *   func_02082A90 0x02082A90 arm
 *   BTL_MSG_FormatArgs 0x021EEE24 thumb ov093
 *   PALANM_RequestFade  0x0202173C  thumb  arm9
 */
#include "../../matched/include/Obj02796.h"
#include "../../matched/include/Obj00027.h"
#include "../../matched/include/Obj06290.h"
#include "../../matched/include/Obj04385.h"
#include "../../matched/include/Obj13565.h"
#include "../../matched/include/Obj21589.h"
#include "../../matched/include/Obj21590.h"
#include "../../matched/include/Obj13566.h"
#include "../../matched/include/Obj05231.h"
#include "../../matched/include/Obj21591.h"
#include "../../matched/include/Obj03709.h"
#include "../../matched/include/Obj10119.h"
#include "../../matched/include/Obj18521.h"
#include "../../matched/include/Obj13567.h"
#include "../../matched/include/Obj13568.h"
#include "../../matched/include/Obj21597.h"
#include "../../matched/include/Obj21598.h"
#include "../../matched/include/Obj21599.h"
#include "../../matched/include/Obj10120.h"
#include "../../matched/include/Obj10121.h"
#include "../../matched/include/Obj21604.h"
#include "../../matched/include/Obj10122.h"
#include "../../matched/include/Obj21607.h"
#include "../../matched/include/Obj21608.h"
#include "../../matched/include/Obj21609.h"
#include "../../matched/include/Obj21610.h"
#include "../../matched/include/Obj21611.h"
#include "../../matched/include/Obj21612.h"
#include "../../matched/include/Obj21613.h"
#include "../../matched/include/Obj21614.h"
#include "../../matched/include/Obj01044.h"
#include "../../matched/include/Obj00341.h"
#include "../../matched/include/Obj01524.h"
#include "../../matched/include/Obj02797.h"
#include "../../matched/include/Obj21615.h"
#include "../../matched/include/Obj21616.h"
#include "../../matched/include/Obj05234.h"
#include "../../matched/include/Obj21617.h"
#include "../../matched/include/Obj00623.h"

struct CharBuf;
struct Descriptor;
struct Rec;
struct S_021ECE60;
struct Rec3;
struct E;
struct Work;
struct S02030FB4;
struct TcblNode;
struct Q;
struct S;
struct E_021ED76C;
struct W_021ED76C;
struct Bmp;
struct Obj020437AC;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021ECE60;

typedef unsigned int   u32;

typedef short s16_021ECEB8;

typedef int s32_021ECEB8;

typedef signed char s8;

typedef signed short s16_021ECF50;

typedef signed int s32_021ECF50;

struct T_021ECF68 {
    u8 pad0[0x30];
    void *h30;
    u8 pad34[0x100];
    u8 **owner;
    u8 pad138[6];
    u8 b13e;
    u8 b13f;
    u8 pad140;
    u8 b141;
    u8 pad142[2];
    int i144;
    u16 h148;
    u16 h14a;
    u16 h14c;
    u8 pad14e[6];
    u8 s154[1];
};

typedef signed int     s32_021ECF68;

struct T_021ED118 {
    u16 h;
    int a;
    int b;
    u8 e;
    u8 f;
    u32 d;
};

typedef int (*Cb)(void *, u32);

typedef signed short s16;

typedef signed int s32;

struct T { char *e; u16 st; u16 pad; u8 *cnt; };

struct Q { u8 *a; u16 state; u8 *cnt; };

struct S_021ECE60 { char *p; u8 k; u8 pad[3]; u32 v; u32 c; u32 a; u8 *cnt; };

struct S_021ED5D8 { char *w; u8 k; u8 pad[3]; u32 v; u32 c; u32 a; u8 *cnt; };

struct S_021ED724 { char *w; u32 k; void *v; u32 c; u8 pad10; u8 f; u8 pad12[2]; u8 *cnt; };

struct S_021ED76C { int a; int x4; int x8; int xc; int x10; u8 state; u8 b15; };

struct S_021ED7C8 { int h; int x; int y; int dx; int dy; u8 state; u8 cnt; };

struct Q_021ED8AC { u8 *a; int b; u8 *c; };

struct Sub {
    u8 pad[0x14];
};

struct Q_021ED8E8 {
    char *f00;
    int f04;
    u8 *f08;
};

struct E_021ED76C { int a0; u8 *owner; u8 k8; u8 v9; u8 fa; u8 fb; };

struct E_021EDA04 { u8 *a0; u8 *owner; u8 k8; u8 v9; u8 fa; u8 fb; };

typedef enum { B_FALSE, B_TRUE } Bool;

struct X {
    u8 pad00[0x14];
    char *f14;
};

struct E {
    struct S *f00;
    int f04;
    u16 f08;
    u8 f0a;
    u8 f0b;
    u8 f0c;
    u8 pad0d[3];
    char *f10;
    u8 pad14[8];
    char *f1c;
    u8 pad20[2];
    u8 f22_0 : 1;
};

struct S {
    u8 pad00[0x90];
    struct E e[2];
    int fd8;
    struct X *fdc;
    u8 pade0[0x13c - 0xe0];
    u16 f13c;
};

struct W_021ED76C {
    char *f00;
    u8 pad04[4];
    u16 f08;
    u8 pad0a[2];
    u8 f0c;
    u8 f0d;
    u8 pad0e[0x14];
    u8 f22_0 : 1;
    u8 f22_1 : 1;
};

struct Flags { u8 shown : 1; u8 close : 1; };

struct W_021EDE54 {
    u8 pad[0xa];
    u8 fa;
    u8 fb;
    u8 pad2[0x16];
    u8 f22_0 : 1;
};

extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void PRINTSYS_Print(void *x, s16_021ECE60 y, s16_021ECE60 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern int BTL_MAIN_GetTextSpeedFrames(unsigned char *p);
extern struct Rec *PRINTSYS_PrintStreamCallBack(u32 a0, s16_021ECEB8 a1, s16_021ECEB8 a2, u32 a3, u32 a4, s32_021ECEB8 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void PRINTSYS_PrintStreamStop(void *p);
extern u8 BTL_MAIN_GetCommPos(u8 **);
extern void PRINTSYS_PrintStreamRun(void *);
extern u32 PRINTSYS_PrintStreamIsOverrideSpeed(struct Rec *p);
extern void func_0201CE8C(struct Rec *p, s32_021ECF68 v);
extern signed char func_02013080(u32 idx);
extern void func_0201CEB8(struct Rec *p);
extern u32 func_0201CE30(void *p);
extern u32 func_0203630C(void);
extern int TOUCHPANEL_GetCont(void);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
extern void func_0201DD68(void);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *);
extern int GFL_USE_IsSeqPlaying(u32 a);
extern void func_020061E4(u32 a);
extern void func_021F7B2C(u8 *);
extern int func_021F7EB4(void);
extern void GFL_USE_StopAllSe(void);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D59B4(u8 *p, int k);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void func_021F80FC(u32 a, u32 b);
extern void func_021F7C2C(int a, int b);
extern void func_021F8118(u32 a, u32 b);
extern int func_021F8180(void);
extern void func_021F80E4(u32);
extern void func_021F7CE4(int);
extern void func_021F7F04(int);
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern void func_021F7EE8(void *, int);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void func_021F7A28(int a, u32 b);
extern void TCBL_DeleteTask(struct TcblNode *n);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern void func_021F87D4(u32 v);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern void func_021F7D80(void *a, int b);
extern void func_021F7E38(void *a, int b);
extern void func_021F803C(u32 a, void *m, u32 c);
extern u8 func_021B8ED8(u8 *p, u8 k);
extern void func_0207D63C(int, int, int, int, int);
extern void *func_02045770(struct Descriptor *p);
extern u32 BTL_MAIN_GetRule(void **p);
extern unsigned int BTL_MAIN_GetRuleSlotSpan(unsigned int **p);
extern int BTL_POKEPARAM_IsFainted(void *m);
extern u8 func_021B9AE0(u32);
extern int BTL_MAIN_IsLocalSide(u8 *, u8);
extern void func_021F8504(u32, u32, u32);
extern int func_021F8B28(void);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void BMP_Delete(struct Obj020437AC *p);
extern u32 func_020307B0(void *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void func_021F8AE8(int a, u32 b);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_02040618(u32, u32, u32);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern int func_021F86E0(void);
extern void *func_021F86D4(void);
extern int PALANM_RequestFade(void *, u16, u16, s16, u8, u8, u16, void *);
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
extern void func_02082A90(const void *, void *, u32);
extern void BTL_MSG_FormatArgs(u32, u16, u32, ...);
extern u32 func_0201D33C(struct StrObj *s, u32 a, u32 b, u32 *out, u32 max);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n);
void func_021ECE60(u8 *a, int b);
void func_021ECEB8(u8 *a, u32 b, u16 s, u32 c);
u32 func_021ECF50(u8 *p);
int func_021ECF68(struct T_021ECF68 *p);
void func_021ED118(u8 *p, int a, int b, u32 c, u32 d, int e, u8 f);
int func_021ED158(int *st, u8 *b);
int func_021ED1B0(char *p);
void func_021ED208(char *p, u8 k, u16 a, int flag);
int func_021ED250(void);
void func_021ED268(u8 *p, u8 k, u32 x);
int func_021ED280(char *p);
void func_021ED294(u8 *p, int k, u32 x);
int func_021ED2BC(void);
void func_021ED2D0(u8 *p, u8 k);
int func_021ED304(void);
void func_021ED318(char *p, u16 k, u16 a, int flag);
u32 func_021ED374(u8 *p);
void func_021ED384(u32 a, u8 *t);
void func_021ED3D4(char *p, u8 k, int a, u8 b, int flag);
int func_021ED450(u8 *p);
void func_021ED460(void *task, struct Q *q);
void func_021ED494(u8 *p, u8 k, int x);
int func_021ED4D0(void);
void func_021ED4E4(u8 *p, int a, int b);
int func_021ED510(u8 *p, int a, int b);
void func_021ED53C(u8 *p, int k);
int func_021ED554(u8 *p, int k);
void func_021ED56C(int a, int b);
int func_021ED57C(int a, int b);
void func_021ED590(char *p, u8 k, u32 a);
u32 func_021ED5D8(u8 *p);
void func_021ED5E8(u32 x, struct S_021ED5D8 *t);
void func_021ED660(char *p, u32 k, u32 a, u32 b);
void func_021ED6BC(char *p, u32 k, u32 a);
u32 func_021ED714(u8 *p);
void func_021ED724(u32 x, struct S_021ED724 *t);
void func_021ED76C(struct S_021ED76C *s, int a);
void func_021ED798(struct S_021ED76C *s);
void func_021ED7C8(struct S_021ED7C8 *s, int keep);
int func_021ED814(struct S_021ED7C8 *s);
void func_021ED8AC(u8 *p);
u32 func_021ED8D8(u8 *p);
void func_021ED8E8(int a,struct Q_021ED8E8 *q);
void func_021ED930(char *s);
void func_021ED988(u8 *p);
void func_021ED9A4(struct E_021ED76C *e, u8 *o, u8 k);
void func_021ED9C8(struct E_021ED76C *e);
void func_021ED9EC(struct E_021ED76C *e);
void func_021EDA04(struct E_021EDA04 *e);
Bool func_021EDA3C(u8 *p, u32 x);
void func_021EDA5C(u8 *p, u8 a, int b);
void func_021EDA94(u8 *p, u32 x);
void func_021EDAB0(u8 *p, u32 x);
void func_021EDAE0(u8 *p, u32 x);
void func_021EDB00(u8 *p, u8 a);
void func_021EDB20(u8 *p, u32 x);
void func_021EDB3C(struct S *s, char *a1);
void func_021EDBE8(char *s);
void func_021EDC28(struct W_021ED76C *w, u8 a1, int flag);
int func_021EDCA8(u8 *p);
void func_021EDE54(u8 *p);
void func_021EDF4C(struct W_021EDE54 *w);
int func_021EDF78(u8 *a0);
void func_021EDF7C(u8 *p, u8 b);
int func_021EDFC4(u8 *p);









void func_021ECE60(u8 *a, int b)
{
    BMP_Clear((struct CharBuf *)(((struct Obj02796 *)a)->f4), 0xc);
    GF_FONT_SetTextColor(1, 9, 0xc);
    PRINTSYS_Print((void *)(((struct Obj02796 *)a)->f4), 0, 0, (void *)b, (void *)(((struct Obj02796 *)a)->f24));
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj02796 *)a)->f0);
    a[0x13f] = 0;
    ((struct Obj02796 *)a)->f148 = 0;
    ((struct Obj02796 *)a)->f14A = 0;
    ((struct Obj02796 *)a)->f14C = 0;
    a[0x13e] = 1;
    a[0x141] = 0;
}









void func_021ECEB8(u8 *a, u32 b, u16 s, u32 c)
{
    void *o;

    BMP_Clear((struct CharBuf *)(((struct Obj00027 *)a)->f4), 0xc);
    GF_FONT_SetTextColor(1, 9, 0xc);
    o = PRINTSYS_PrintStreamCallBack(((struct Obj00027 *)a)->f0, 0, 0, b, ((struct Obj00027 *)a)->f24,
                      BTL_MAIN_GetTextSpeedFrames((unsigned char *)(*(int *)&((struct Obj00027 *)a)->f134)),
                      ((struct Obj00027 *)a)->f2C, 0,
                      ((struct Obj00027 *)a)->f13C, 0xc, c);
    ((struct Obj00027 *)a)->f30 = o;
    PRINTSYS_PrintStreamStop(o);
    a[0x13f] = 0;
    a[0x13e] = 0;
    if (s == 0xff) {
        ((struct Obj00027 *)a)->f148 = 0x50;
        ((struct Obj00027 *)a)->f14C = 0;
    } else {
        ((struct Obj00027 *)a)->f148 = s;
        ((struct Obj00027 *)a)->f14C = s;
    }
    ((struct Obj00027 *)a)->f14A = ((struct Obj00027 *)a)->f148;
    a[0x141] = 0;
}









/*
 * Untraced mid-stream entry point (reached only through the `bx r3` tail thunks, so disasm.py emitted its bytes as a pool run).  Reads the byte at p+0x141: returns 1 and clears it when set, else 0.  The 0x141 index is too wide for Thumb ldrb's 5-bit immediate, so it lives in a pool word and the load is register-offset.
 */
u32 func_021ECF50(u8 *p) { if (p[0x141]) { p[0x141] = 0; return 1; } return 0; }








/*
 * Case 2 writes the next state in if/else arms (the ternary loses the 0x144 base kept in r5),
 * case 4 decrements with `--` (reload of the halfword), and case 5 restarts the counter from
 * h14a without a decrement.
 */
int func_021ECF68(struct T_021ECF68 *p)
{
    switch (p->b13f) {
    case 0:
        func_021ED7C8((struct S_021ED7C8 *)((struct S_021ECE60 *)p->s154), p->b13e);
        p->b13f = p->b13f + 1;
    case 1:
        if (func_021ED814((struct S_021ED7C8 *)((struct S_021ECE60 *)p->s154)) == 0)
            break;
        if (p->b13e != 0) {
            p->b13f = 6;
            break;
        }
        if (p->h30 != 0)
            PRINTSYS_PrintStreamRun(p->h30);
        p->b13f = p->b13f + 1;
    case 2:
        if (p->h30 != 0) {
            if (BTL_MAIN_GetCommPos(p->owner) == 0) {
                if ((func_0203630C() & 3) != 0 || TOUCHPANEL_GetCont() != 0) {
                    if (PRINTSYS_PrintStreamIsOverrideSpeed(p->h30) == 0)
                        func_0201CE8C(p->h30, func_02013080(2));
                } else {
                    if (PRINTSYS_PrintStreamIsOverrideSpeed(p->h30) != 0)
                        func_0201CEB8(p->h30);
                }
            }
            p->i144 = func_0201CE30(p->h30);
            if (p->i144 != 0) {
                if (BTL_MAIN_GetCommPos(p->owner) == 0)
                    p->b13f = 3;
                else
                    p->b13f = 4;
                if (p->i144 == 2) {
                    p->h148 = p->h14c;
                    p->b141 = 1;
                }
            }
        } else {
            p->b13f = 6;
        }
        break;
    case 3:
        if ((func_020362DC() & 3) != 0 || TOUCHPANEL_GetTrg() != 0)
            p->h148 = 0;
        if (p->h148 != 0) {
            p->h148 = p->h148 - 1;
            break;
        }
        p->b13f = 5;
        break;
    case 4:
        if (p->h148 != 0) {
            p->h148--;
            break;
        }
        p->b13f = 5;
        break;
    case 5:
        if (p->i144 == 2) {
            func_0201DD68();
            func_0201CE48(p->h30);
            p->h30 = 0;
            p->b13f = 6;
            break;
        }
        func_0201CE38(p->h30);
        func_020061E4(0x547);
        p->b13f = 2;
        p->h148 = p->h14a;
        break;
    case 6:
        if (GFL_USE_IsSeqPlaying(0x547) == 0) {
            p->b13f = 7;
            return 1;
        }
        break;
    case 7:
    default:
        return 1;
    }
    return 0;
}









void func_021ED118(u8 *p, int a, int b, u32 c, u32 d, int e, u8 f)
{
    struct T_021ED118 *q = (struct T_021ED118 *)(p + 0xf0);

    ((struct Obj06290 *)p)->fF0 = c;
    q->a = a;
    q->b = b;
    q->e = e;
    q->f = f;
    q->d = d;
    ((struct Obj06290 *)p)->fE0 = 0;
    *(int (**)(int *, u8 *))(p + 0xe4) = func_021ED158;
    *(u8 * *)&((struct Obj06290 *)p)->fE8 = p;
    ((struct Obj06290 *)p)->fEC = 0;
}









int func_021ED158(int *st, u8 *b)
{
    switch (*st) {
    case 0:
        func_021ED798((struct S_021ED76C *)((struct S_021ECE60 *)(b + 0x154)));
    inc:
        *st = *st + 1;
        break;
    case 1:
        if (func_021ED814((struct S_021ED7C8 *)((struct S_021ECE60 *)(b + 0x154))) != 0) {
            func_021F7B2C(b + 0xf0);
            goto inc;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            GFL_USE_StopAllSe();
            goto inc;
        }
        break;
    default:
        return 1;
    }
    return 0;
}









int func_021ED1B0(char *p)
{
    Cb f;

    f = *(Cb *)&((struct Obj04385 *)p)->fE0;
    if (f != 0) {
        if (f(p + 0xec, ((struct Obj04385 *)p)->fE8) != 0) {
            *(u32 *)&((struct Obj04385 *)p)->fE0 = 0;
            ((struct Obj04385 *)p)->fEC = 0;
        }
        return 0;
    }
    f = *(Cb *)&((struct Obj04385 *)p)->fE4;
    if (f != 0) {
        if (f(p + 0xec, ((struct Obj04385 *)p)->fE8) != 0) {
            *(u32 *)&((struct Obj04385 *)p)->fE4 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}









void func_021ED208(char *p, u8 k, u16 a, int flag)
{
    int t;
    u32 v;

    t = func_021D59B4(func_021B98AC(*(char *const * *)&((struct Obj13565 *)p)->f138, k), 0xd);
    v = func_021B8E70(*(u8 * *)&((struct Obj13565 *)p)->f134, k);
    if (flag == 0) {
        func_021F80FC(v, t);
        func_021F7C2C(v, a);
    } else {
        func_021F8118(v, t);
    }
}








int func_021ED250(void)
{
    int a = func_021F7EB4();
    if ((func_021F8180() | a) == 0)
        return 1;
    return 0;
}








void func_021ED268(u8 *p, u8 k, u32 x)
{
    func_021F7C2C(func_021B8E70(*(u8 * *)&((struct Obj21589 *)p)->f134, k), x);
}








int func_021ED280(char *p)
{
    if (func_021F7EB4() == 0)
        return 1;
    return 0;
}








void func_021ED294(u8 *p, int k, u32 x)
{
    u8 r = func_021B8E70(*(u8 * *)&((struct Obj21590 *)p)->f134, k);
    func_021F80E4(r);
    if (x == 0)
        func_021F7CE4(r);
    else
        func_021F7F04(r);
}








int func_021ED2BC(void)
{
    if (func_021F7EB4() == 0)
        return 1;
    return 0;
}








void func_021ED2D0(u8 *p, u8 k)
{
    u8 r = func_021B8E70(*(u8 * *)&((struct Obj13566 *)p)->f134, k);
    func_021F7EE8(BTL_POKEPARAM_GetDisplayMon((struct Work *)func_021B98AC(*(char *const * *)&((struct Obj13566 *)p)->f138, k)), r);
    func_021EDA04((struct E_021EDA04 *)((struct E *)(p + 0x48 + k * 12)));
}








int func_021ED304(void)
{
    if (func_021F7EB4() == 0)
        return 1;
    return 0;
}









void func_021ED318(char *p, u16 k, u16 a, int flag)
{
    u8 *t;

    if (flag != 0 || a == 0) {
        func_021F80E4(k);
        func_021F7F04(k);
        return;
    }
    t = TCBL_GetWork(func_020311B8(((struct Obj21591 *)p)->f2C, (void *)func_021ED384, 0x10, 1));
    ((struct Obj05231 *)t)->f6 = k;
    *(char * *)&((struct Obj05231 *)t)->f0 = p + 0x48 + k * 0xc;
    *(char * *)&((struct Obj05231 *)t)->fC = p + 0x42;
    if (a == 0)
        a = 0x26c;
    ((struct Obj05231 *)t)->f8 = a;
    ((struct Obj05231 *)t)->f4 = 0;
    (**(u8 * *)&((struct Obj05231 *)t)->fC)++;
}









u32 func_021ED374(u8 *p) { if (p[0x42] == 0) return 1; return 0; }









void func_021ED384(u32 a, u8 *t)
{
    switch (((struct Obj03709 *)t)->f4) {
    case 0:
        func_021F7A28(((struct Obj03709 *)t)->f6, ((struct Obj03709 *)t)->f8);
        (((struct Obj03709 *)t)->f4)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021F80E4(((struct Obj03709 *)t)->f6);
            func_021F7F04(((struct Obj03709 *)t)->f6);
            (((struct Obj03709 *)t)->f4)++;
        }
        break;
    case 2:
        (**(u8 * *)&((struct Obj03709 *)t)->fC)--;
        TCBL_DeleteTask((struct TcblNode *)a);
        break;
    }
}









/*
 * Lever: the record from TCBL_GetWork is a struct pointer, not u8 *: the
 * cnt field is then forwarded across the st store instead of being reloaded
 * (u8 * base plus a local kept in r1 gave 84 bytes out).
 */
void func_021ED3D4(char *p, u8 k, int a, u8 b, int flag)
{
    struct T *t;
    u8 *m;
    u8 y;

    t = (struct T *)TCBL_GetWork(func_020311B8(((struct Obj10119 *)p)->f2C, (void *)func_021ED460, 0xc, 1));
    t->e = p + 0x48 + k * 0xc;
    t->cnt = (u8 *)p + 0x41;
    t->st = 0;
    (*t->cnt)++;
    m = func_021B9920(((struct Obj10119 *)p)->f138, a, b);
    y = func_021B8E70(*(u8 * *)&((struct Obj10119 *)p)->f134, k);
    func_021F7EE8(BTL_POKEPARAM_GetDisplayMon((struct Work *)m), y);
    if (flag == 0)
        func_021F7A28(y, 0x26d);
}









/* 021ED450  adds r0,#0x41; ldrb; cmp #0; bne ->0 else 1 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: adds r0, #0x41; ldrb r0, [r0]; cmp r0, #0; bne loc_021ED45C; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
int func_021ED450(u8 *p) { return ((struct Obj18521 *)p)->f41 == 0; }








void func_021ED460(void *task, struct Q *q)
{
    switch (q->state) {
    case 0:
        if (func_021F7EB4() == 0) {
            func_021EDA04((struct E_021EDA04 *)((struct E *)q->a));
            q->state = q->state + 1;
        }
        break;
    case 1:
        (*q->cnt)--;
        TCBL_DeleteTask(task);
        break;
    }
}








void func_021ED494(u8 *p, u8 k, int x)
{
    int d = func_021D59B4(func_021B98AC(*(char *const * *)&((struct Obj13567 *)p)->f138, k), 0xd);
    u8 r = func_021B8E70(*(u8 * *)&((struct Obj13567 *)p)->f134, k);
    if (x != 0)
        func_021F8118(r, d);
    else
        func_021F80FC(r, d);
}








int func_021ED4D0(void)
{
    if (func_021F8180() == 0)
        return 1;
    return 0;
}








void func_021ED4E4(u8 *p, int a, int b)
{
    func_021ED9EC((struct E_021ED76C *)((struct E *)(p + 0x48 + a * 12)));
    func_021ED9EC((struct E_021ED76C *)((struct E *)(p + 0x48 + b * 12)));
    func_021F87D4(1);
}







int func_021ED510(u8 *p, int a, int b)
{
    func_021EDA04((struct E_021EDA04 *)((struct E *)(p + 0x48 + a * 12)));
    func_021EDA04((struct E_021EDA04 *)((struct E *)(p + 0x48 + b * 12)));
    func_021F87D4(0);
    return 1;
}







void func_021ED53C(u8 *p, int k)
{
    func_021ED9EC((struct E_021ED76C *)((struct E *)(p + 0x48 + k * 12)));
    func_021F87D4(1);
}







int func_021ED554(u8 *p, int k)
{
    func_021EDA04((struct E_021EDA04 *)((struct E *)(p + 0x48 + k * 12)));
    func_021F87D4(0);
    return 1;
}







void func_021ED56C(int a, int b)
{
    func_021F7A28(b, 0x25f);
}






int func_021ED57C(int a, int b)
{
    if (func_021F7EB4() == 0)
        return 1;
    return 0;
}







void func_021ED590(char *p, u8 k, u32 a)
{
    struct S_021ECE60 *t;

    if (k != 6) {
        t = (struct S_021ECE60 *)TCBL_GetWork(func_020311B8(((struct Obj13568 *)p)->f2C, (void *)func_021ED5E8, 0x18, 1));
        t->p = p;
        t->k = k;
        t->a = a;
        t->v = func_021B8E70(*(u8 * *)&((struct Obj13568 *)p)->f134, k);
        t->cnt = (u8 *)p + 0x40;
        t->c = 0;
        (*t->cnt)++;
    }
}






u32 func_021ED5D8(u8 *p) { if (p[0x40] == 0) return 1; return 0; }






void func_021ED5E8(u32 x, struct S_021ED5D8 *t)
{
    void *r;

    switch (t->c) {
    case 0:
        r = BTL_POKEPARAM_GetMon(func_021B98AC(*(char *const * *)&((struct Obj21597 *)(t->w))->f138, t->k));
        if (t->a == 0)
            func_021F7D80(r, t->v);
        else
            func_021F7E38(r, t->v);
        func_021F80E4(t->v);
        t->c++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021F803C(((struct Obj21598 *)(t->w))->f134,
                          func_021B98AC(*(char *const * *)&((struct Obj21599 *)(t->w))->f138, t->k), t->v);
            (*t->cnt)--;
            TCBL_DeleteTask((struct TcblNode *)x);
        }
        break;
    }
}





void func_021ED660(char *p, u32 k, u32 a, u32 b)
{
    struct S_021ED724 *t;

    t = (struct S_021ED724 *)TCBL_GetWork(func_020311B8(((struct Obj10120 *)p)->f2C, (void *)func_021ED724, 0x18, 1));
    t->v = BTL_POKEPARAM_GetMon(func_021B98AC(*(char *const * *)&((struct Obj10120 *)p)->f138,
                                              func_021B8ED8(*(u8 * *)&((struct Obj10120 *)p)->f134, a)));
    t->w = p;
    t->k = k;
    t->cnt = (u8 *)p + 0x40;
    t->f = b;
    t->c = 0;
    (*t->cnt)++;
}





void func_021ED6BC(char *p, u32 k, u32 a)
{
    struct S_021ED724 *t;

    t = (struct S_021ED724 *)TCBL_GetWork(func_020311B8(((struct Obj10121 *)p)->f2C, (void *)func_021ED724, 0x18, 1));
    t->v = BTL_POKEPARAM_GetMon(func_021B98AC(*(char *const * *)&((struct Obj10121 *)p)->f138,
                                              func_021B8ED8(*(u8 * *)&((struct Obj10121 *)p)->f134, k)));
    t->w = p;
    t->k = k;
    t->cnt = (u8 *)p + 0x40;
    t->f = a;
    t->c = 0;
    (*t->cnt)++;
}




u32 func_021ED714(u8 *p) { if (p[0x40] == 0) return 1; return 0; }




void func_021ED724(u32 x, struct S_021ED724 *t)
{
    switch (t->c) {
    case 0:
        if (t->f == 0)
            func_021F7D80(t->v, t->k);
        else
            func_021F7E38(t->v, t->k);
        t->c++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            (*t->cnt)--;
            TCBL_DeleteTask((struct TcblNode *)x);
        }
        break;
    }
}







void func_021ED76C(struct S_021ED76C *s, int a)
{
    s->a = a;
    s->state = 0;
    s->x4 = 0x1f000;
    s->x8 = 0x7000;
    func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
}







void func_021ED798(struct S_021ED76C *s)
{
    u8 st = s->state;
    if (st == 0 || st == 3) {
        s->x4 = 0x1f000;
        s->x8 = 0x7000;
        s->xc = -0x52aa;
        s->x10 = 0x1800;
        s->b15 = 6;
        s->state = 1;
    }
}








void func_021ED7C8(struct S_021ED7C8 *s, int keep)
{
    if ((u8)(s->state + 0xff) <= 1) {
        if (keep == 0) {
            BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)s->h)), 0xc);
            BMP_WIN_TransferChars((struct Descriptor *)s->h);
        }
        s->x = 0;
        s->y = 0x10000;
        s->dx = 0x52aa;
        s->dy = -0x1800;
        s->cnt = 6;
        s->state = 4;
    }
}








/*
 * Lever: the shared step block at 0x021ED84A is the same code written in
 * both arms (case 3 and case 1) with the same `if (cnt != 0)` polarity; the
 * compiler cross-jumps the second copy into `b 0x021ED84A`.  A goto into the
 * first copy, or `== 0` polarity, moves the branches.
 */
int func_021ED814(struct S_021ED7C8 *s)
{
    switch (s->state) {
    case 2:
        return 1;
    case 0:
        return 1;
    case 4:
        s->state = 3;
        return 0;
    case 3:
        if (s->cnt != 0) {
            s->x += s->dx;
            s->y += s->dy;
            s->cnt = s->cnt - 1;
        } else {
            s->x = 0x1f000;
            s->y = 0x7000;
            s->state = 0;
        }
        break;
    case 1:
        if (s->cnt != 0) {
            s->x += s->dx;
            s->y += s->dy;
            s->cnt = s->cnt - 1;
        } else {
            s->x = 0;
            s->y = 0x10000;
            s->state = 2;
        }
        break;
    }
    func_0207D63C((int)((void *)0x04000050), 2, 0x3d, (u8)(s->x >> 12), (u8)(s->y >> 12));
    return 0;
}






void func_021ED8AC(u8 *p)
{
    struct Q_021ED8AC *q;
    q = TCBL_GetWork(func_020311B8((u32)(((struct Obj21604 *)p)->f2C), (void *)func_021ED8E8, 0xc, 1));
    q->a = p;
    q->c = p + 0x40;
    q->b = 0;
    (*q->c)++;
}







/*
 * Untraced mid-stream entry point, same shape as func_021ED374 with the offset 0x40.
 */
u32 func_021ED8D8(u8 *p) { if (p[0x40] == 0) return 1; return 0; }







void func_021ED8E8(int a,struct Q_021ED8E8 *q)
{
    switch (q->f04) {
    case 0:
        func_021ED798((struct S_021ED76C *)((struct S *)(q->f00 + 0x154)));
        q->f04++;
        break;
    case 1:
        if (func_021ED814((struct S_021ED7C8 *)((struct S *)(q->f00 + 0x154))) != 0) {
            (*q->f08)--;
            TCBL_DeleteTask((struct TcblNode *)a);
        }
        break;
    }
}







void func_021ED930(char *s)
{
    u32 i;
    u32 n;

    for (i = 0; i <= 6; i++) {
        *(u8 *)(s + i * 12 + 0x53) = 0;
        *(int *)(s + i * 12 + 0x48) = 0;
    }
    if (BTL_MAIN_GetRule(((struct Obj10122 *)s)->f134) != 3) {
        n = BTL_MAIN_GetRuleSlotSpan(((struct Obj10122 *)s)->f134);
    } else {
        n = 5;
    }
    for (i = 0; i <= n; i++) {
        func_021ED9A4((struct E_021ED76C *)(s + 0x48 + i * 12), (u8 *)s, i);
    }
}






void func_021ED988(u8 *p)
{
    u32 i;
    for (i = 0; i < 6; i++)
        func_021ED9C8((struct E_021ED76C *)(p + 0x48 + i * 12));
}






void func_021ED9A4(struct E_021ED76C *e, u8 *o, u8 k)
{
    e->k8 = k;
    e->v9 = func_021B8E70(*(u8 * *)&((struct Obj10122 *)o)->f134, k);
    e->owner = o;
    e->fa = 0;
    e->fb = 1;
    e->a0 = 0;
}






void func_021ED9C8(struct E_021ED76C *e)
{
    if (e->fb != 0) {
        if (e->fa != 0) {
            func_021F80E4(e->v9);
            e->fa = 0;
        }
        e->a0 = 0;
        e->fb = 0;
    }
}






void func_021ED9EC(struct E_021ED76C *e)
{
    if (e->fa != 0) {
        func_021F80E4(e->v9);
        e->fa = 0;
    }
}





void func_021EDA04(struct E_021EDA04 *e)
{
    if (e->fb != 0) {
        e->a0 = func_021B98AC(*(char *const * *)&((struct Obj21607 *)(e->owner))->f138, e->k8);
        if (BTL_POKEPARAM_IsFainted(e->a0) == 0) {
            func_021F803C(((struct Obj21608 *)(e->owner))->f134, e->a0, e->v9);
            e->fa = 1;
        }
    }
}





/*
 * The 0/1 return uses enum constants: with int constants the compiler folds the two returns
 * into a boolean and lays the one first (bne). See
 * docs/idioms/a-flag-ternary-over-enum-constants-keeps-the-bne-to-one-polarity.md.
 */
Bool func_021EDA3C(u8 *p, u32 x)
{
    if (BTL_MAIN_IsLocalSide(p, func_021B9AE0(x)) != 0)
        return B_FALSE;
    return B_TRUE;
}





void func_021EDA5C(u8 *p, u8 a, int b)
{
    int r = func_021EDA3C(*(u8 * *)&((struct Obj21609 *)p)->f134, a);
    if (r == 0)
        func_021F8504(0, 0, 0);
    func_021F8B28();
    func_021EDC28((struct W_021ED76C *)(p + 0x90 + r * 0x24), a, b);
}





void func_021EDA94(u8 *p, u32 x)
{
    func_021EDCA8(p + 0x90 + func_021EDA3C(*(u8 * *)&((struct Obj21610 *)p)->f134, x) * 0x24);
}





void func_021EDAB0(u8 *p, u32 x)
{
    u8 k = func_021EDA3C(*(u8 * *)&((struct Obj21611 *)p)->f134, x);
    func_021EDF4C((struct W_021EDE54 *)((struct W_021ED76C *)(p + 0x90 + k * 0x24)));
    if (k == 0)
        func_021F8504(0, 1, 0);
}





void func_021EDAE0(u8 *p, u32 x)
{
    u8 k = func_021EDA3C(*(u8 * *)&((struct Obj21612 *)p)->f134, x);
    func_021EDF78(p + 0x90 + k * 0x24);
}





void func_021EDB00(u8 *p, u8 a)
{
    func_021EDF7C(p + 0x90 + func_021EDA3C(*(u8 * *)&((struct Obj21613 *)p)->f134, a) * 0x24, a);
}





void func_021EDB20(u8 *p, u32 x)
{
    func_021EDFC4(p + 0x90 + func_021EDA3C(*(u8 * *)&((struct Obj21614 *)p)->f134, x) * 0x24);
}





void func_021EDB3C(struct S *s, char *a1)
{
    u32 i;

    s->fd8 = (int)func_02049DB4(0xb, 0xd5, 0, (u32)(&s->fdc), s->f13c);
    for (i = 0; i < 2; i++) {
        s->e[i].f00 = s;
        s->e[i].f0a = i;
        s->e[i].f0b = (i == 0) ? 2 : 3;
        s->e[i].f10 = s->fdc->f14 + i * 0x900;
        s->e[i].f04 = (int)BMP_Create(0x12, 4, 0x20, s->f13c);
        s->e[i].f08 = 0;
        s->e[i].f0c = 0x1f;
        s->e[i].f1c = a1 + i * 0x48;
        s->e[i].f22_0 = 0;
    }
}





void func_021EDBE8(char *s)
{
    u32 i;

    for (i = 0; i < 2; i++) {
        if (*(int *)(s + i * 0x24 + 0x94) != 0) {
            BMP_Delete((struct Obj020437AC *)(*(int *)(s + i * 0x24 + 0x94)));
            *(int *)(s + i * 0x24 + 0x94) = 0;
        }
    }
    if (((struct Obj01044 *)s)->fD8 != 0) {
        func_020307B0((void *)(((struct Obj01044 *)s)->fD8));
        ((struct Obj01044 *)s)->fD8 = 0;
    }
}





/*
 * note:     a1 is a narrow (u8/u16, both give EXACT*) parameter: it pins the
 *           spill store to the front of the prologue; flag is int, cast (u8)
 *           at the bitfield store.
 */
void func_021EDC28(struct W_021ED76C *w, u8 a1, int flag)
{
    u8 *t;
    u16 h;
    u8 k;

    t = func_021B98AC(*(char *const **)(w->f00 + 0x138), a1);
    h = func_021D59B4(t, 0x10);
    k = BTL_POKEPARAM_GetPokeId(t);
    if (w->f22_0) {
        if (k == w->f0c) {
            return;
        }
        func_021EDF4C((struct W_021EDE54 *)w);
    }
    if (h != w->f08 || k != w->f0c) {
        w->f08 = h;
        w->f0c = k;
        func_021EDE54((u8 *)w);
    }
    w->f22_1 = (u8)flag;
    w->f0d = 0;
    func_021F8AE8(a1, h);
}




/*
 * volatile: 021EDDC6 rereads flags after setting bit 0.
 */
int func_021EDCA8(u8 *p)
{
    u32 i;
    u8 *src;
    u32 dst;
    void *pal;
    void *ctx;
    u16 mask;
    switch (p[0xd]) {
    case 0:
        func_02040B1C(p[0xb], ((struct Obj00341 *)p)->f10, 0x900, ((struct Obj00341 *)p)->f1C);
        p[0xd]++;
        break;
    case 1:
        p[0x20] = 8;
        if (p[0xa] == 0) {
            ((struct Obj00341 *)p)->f14 = 0x90000;
            ((struct Obj00341 *)p)->f18 = -0x12000;
        } else {
            ((struct Obj00341 *)p)->f14 = -0x90000;
            ((struct Obj00341 *)p)->f18 = 0x12000;
        }
        func_02040618(p[0xb], 0, ((struct Obj00341 *)p)->f14 >> 12);
        func_02040618(p[0xb], 3, 0);
        func_020061E4(0x573);
        p[0xd]++;
        break;
    case 2:
        if (p[0x20] != 0) {
            ((struct Obj00341 *)p)->f14 += ((struct Obj00341 *)p)->f18;
            func_02040618(p[0xb], 0, ((struct Obj00341 *)p)->f14 >> 12);
            p[0x20]--;
        } else {
            func_02040618(p[0xb], 0, 0);
            p[0x21] = 0;
            p[0xd]++;
        }
        break;
    case 3:
        if (p[0x21] < 17) {
            src = (u8 *)BMP_GetPixels(((struct Obj00341 *)p)->f4);
            dst = ((struct Obj00341 *)p)->f1C + p[0x21];
            src += p[0x21] * 32;
            for (i = 0; i < 4; i++) {
                func_02040B1C(p[0xb], src + i * 0x240, 32, dst + i * 18);
            }
            p[0x21]++;
        } else {
            ((struct Flags *)(p + 0x22))->shown = 1;
            if (((volatile struct Flags *)(p + 0x22))->close == 0) return 1;
            p[0xd]++;
        }
        break;
    case 4:
        pal = (void *)func_021F86E0();
        ctx = func_021F86D4();
        mask = 1 << (p[0xa] + 1);
        func_020061E4(0x54d);
        PALANM_RequestFade(pal, 1, mask, 0, 16, 0, 0x7fff, ctx);
        p[0xd]++;
        break;
    case 5:
        if (PALANM_GetFadeRequestBits((const char *)func_021F86E0()) == 0) p[0xd]++;
        break;
    case 6:
        if (GFL_USE_IsSeqPlaying(0x54d) == 0 && GFL_USE_IsSeqPlaying(0x573) == 0) return 1;
        break;
    }
    return 0;
}



void func_021EDE54(u8 *p)
{
    u8 *q;
    u32 size;
    void *pixels;
    u32 widths[2];
    int right;
    int left;
    int gap;
    int extra;
    int half;
    u32 edge;
    u32 width;
    u32 center;
    q = *(u8 * *)&((struct Obj02797 *)p)->f0;
    size = BMP_GetByteSize(((struct Obj02797 *)p)->f4);
    pixels = BMP_GetPixels(((struct Obj02797 *)p)->f4);
    func_02082A90(*(u8 * *)&((struct Obj21616 *)(*(u8 * *)&((struct Obj21615 *)(*(u8 * *)&((struct Obj02797 *)p)->f0))->fDC))->f14 + p[0xa] * 0x900, pixels, size);
    GF_FONT_SetTextColor(1, 2, 0);
    BTL_MSG_FormatArgs(*(u32 *)&((struct Obj01524 *)q)->f38, 0x67, 2, p[0xc], ((struct Obj02797 *)p)->f8);
    if ((u8)func_0201D33C(((struct Obj01524 *)q)->f38, ((struct Obj01524 *)q)->f28, 0, widths, 2) > 1) {
        width = widths[0];
        edge = width + 8;
        right = 0x84 - widths[1];
        gap = edge - right;
        if (gap < 12) {
            extra = 12 - gap;
            half = extra / 2;
            edge += half;
            extra -= half;
            right -= extra;
        }
        left = edge;
        left = left - width;
        if (left < 0) left = 0;
        if (right < 0) right = 0;
        func_0201D37C(((struct Obj01524 *)q)->f38, ((struct Obj01524 *)q)->f3C, 0);
        PRINTSYS_Print(((struct Obj02797 *)p)->f4, left, 7, ((struct Obj01524 *)q)->f3C, (void *)(((struct Obj01524 *)q)->f28));
        func_0201D37C(((struct Obj01524 *)q)->f38, ((struct Obj01524 *)q)->f3C, 1);
        PRINTSYS_Print(((struct Obj02797 *)p)->f4, right, 18, ((struct Obj01524 *)q)->f3C, (void *)(((struct Obj01524 *)q)->f28));
    } else {
        center = (0x88 - func_0201D304(((struct Obj01524 *)q)->f38, ((struct Obj01524 *)q)->f28, 0)) / 2;
        if ((int)center < 0) center = 0;
        PRINTSYS_Print(((struct Obj02797 *)p)->f4, center, 18, ((struct Obj01524 *)q)->f38, (void *)(((struct Obj01524 *)q)->f28));
    }
}



void func_021EDF4C(struct W_021EDE54 *w)
{
    if (w->fa == 0)
        func_02040618(w->fb, 0, 0x90);
    else
        func_02040618(w->fb, 0, -0x90);
    w->f22_0 = 0;
}




/* 021EDF78  movs r0,#1 */
/*
 * Returns the constant #1.
 */
int func_021EDF78(u8 *a0) { return 1; }




void func_021EDF7C(u8 *p, u8 b)
{
    u8 *r;
    u16 h;
    u8 t;

    r = (u8 *)func_021B98AC(*(char *const * *)&((struct Obj21617 *)(*(u8 * *)&((struct Obj05234 *)p)->f0))->f138, b);
    h = func_021D59B4(r, 0x10);
    t = BTL_POKEPARAM_GetPokeId(r);
    if (h != ((struct Obj05234 *)p)->f8 || t != p[0xc]) {
        p[0xc] = t;
        ((struct Obj05234 *)p)->f8 = h;
        func_021EDE54(p);
    }
    p[0xd] = 0;
    func_021F8AE8(b, h);
}



static inline void G2_BG2Mosaic(int enable)
{
    if (enable) *(volatile u16 *)0x0400000c |= 0x40;
    else *(volatile u16 *)0x0400000c &= ~0x40;
}



static inline void G2_BG3Mosaic(int enable)
{
    if (enable) *(volatile u16 *)0x0400000e |= 0x40;
    else *(volatile u16 *)0x0400000e &= ~0x40;
}



int func_021EDFC4(u8 *p)
{
    u8 a;
    switch (p[0xd]) {
    case 0:
        *(volatile u8 *)0x0400004c = 0;
        if (p[0xa] == 0) G2_BG2Mosaic(1);
        else G2_BG3Mosaic(1);
        p[0x20] = 0;
        p[0x21] = 0;
        func_020061E4(0x54e);
        p[0xd]++;
        break;
    case 1:
        p[0x20]++;
        if (*(volatile u8 *)&((struct Obj00623 *)p)->f20 > 1) {
            p[0x20] = 0;
            p[0x21]++;
            a = *(volatile u8 *)&((struct Obj00623 *)p)->f21;
            *(volatile u8 *)0x0400004c = a | (a << 4);
            if (*(volatile u8 *)&((struct Obj00623 *)p)->f21 >= 15) p[0xd]++;
        }
        break;
    case 2:
        func_02040B1C(p[0xb], BMP_GetPixels(((struct Obj00623 *)p)->f4), 0x900, ((struct Obj00623 *)p)->f1C);
        p[0xd]++;
        break;
    case 3:
        p[0x20]++;
        if (*(volatile u8 *)&((struct Obj00623 *)p)->f20 > 1) {
            p[0x20] = 0;
            p[0x21]--;
            a = *(volatile u8 *)&((struct Obj00623 *)p)->f21;
            *(volatile u8 *)0x0400004c = a | (a << 4);
            if (*(volatile u8 *)&((struct Obj00623 *)p)->f21 == 0) p[0xd]++;
        }
        break;
    case 4:
        if (p[0xa] == 0) G2_BG2Mosaic(0);
        else G2_BG3Mosaic(0);
        p[0xd]++;
        break;
    case 5:
        if (GFL_USE_IsSeqPlaying(0x54e) == 0) p[0xd]++;
        break;
    default:
        return 1;
    }
    return 0;
}
