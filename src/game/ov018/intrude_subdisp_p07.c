/*
 * file:     intrude_subdisp_p07.c
 * unit:     yes
 * function: func_0217EC7C, func_0217EEB4, func_0217EF44, func_0217EF70, func_0217EFCC, func_0217F008, func_0217F0C4, func_0217F0FC, func_0217F118, func_0217F174, func_0217F194, func_0217F1E8, func_0217F214, func_0217F240, func_0217F284, func_0217F2B4, func_0217F318, func_0217F36C, func_0217F390, func_0217F3A4, func_0217F3C4, func_0217F3E4, func_0217F40C, func_0217F420, func_0217F434, func_0217F45C, func_0217F470, func_0217F4A0, func_0217F4C4, func_0217F4D8, func_0217F508, func_0217F528, func_0217F574, func_0217F58C, func_0217F5A0, func_0217F5F0, func_0217F648, func_0217F67C, func_0217F6A0, func_0217F8A0, func_0217F8D0, func_0217F914, func_0217F938, func_0217F95C, func_0217FA1C, func_0217FA24, func_0217FA38, func_0217FAE0, func_0217FB2C, func_0217FB5C, func_0217FB94, func_0217FC08, func_0217FC6C, func_0217FCAC, func_0217FD34, func_0217FDA0, func_0217FE38, func_0217FE6C
 * address:  0x0217EC7C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02035D20  0x02035D20  arm
 *   func_021A0F94  0x021A0F94  thumb  ov021
 *   func_02012B58  0x02012B58  thumb
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0217BEA8  0x0217BEA8  thumb  ov018
 *   func_0217EC44  0x0217EC44  thumb  ov018
 *   func_0217EC5C  0x0217EC5C  thumb  ov018
 *   func_02013DD0  0x02013DD0  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_020257C4  0x020257C4  thumb
 *   d_02176AA0     0x02176AA0  data  a4
 *   func_0204989C  0x0204989C  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02080D24  0x02080D24  arm
 *   func_021758C8  0x021758C8  thumb  ov011
 *   func_02175B34  0x02175B34  thumb  ov011
 *   func_0217C070  0x0217C070  thumb  ov018
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02012B70 0x02012B70 thumb
 *   func_02041300 0x02041300 arm
 *   func_020410D0  0x020410D0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02158590 0x02158590 thumb ov010
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_0201EC74  0x0201EC74  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_02190EB8  0x02190EB8  thumb  ov021
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02034714  0x02034714  arm
 *   func_02190F7C  0x02190F7C  thumb  ov021
 *   d_02183B2C     0x02183B2C  data
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_020362DC 0x020362DC arm
 *   func_02190708 0x02190708 thumb ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_02190758 0x02190758 thumb ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_02190BE4 0x02190BE4 thumb ov021
 *   func_02190C78 0x02190C78 thumb ov021
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_02026478 0x02026478 thumb
 *   func_02012950 0x02012950 thumb
 *   func_02008550 0x02008550 thumb
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0215897C 0x0215897C thumb ov010
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012B80  0x02012B80  thumb
 *   func_021757A8  0x021757A8  thumb  ov011
 *   func_0217BF1C  0x0217BF1C  thumb  ov018
 *   func_021907A8  0x021907A8  thumb  ov021
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_02190740  0x02190740  thumb  ov021
 *   func_02045EC0  0x02045EC0  arm
 *   func_021583EC  0x021583EC  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02173D2C  0x02173D2C  thumb  ov011
 *   func_02175FB4  0x02175FB4  thumb  ov011
 *   func_02173C6C  0x02173C6C  thumb  ov011
 *   func_0217BF28  0x0217BF28  thumb  ov018
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02045C04  0x02045C04  arm
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_0217C458  0x0217C458  thumb  ov018
 *   func_0201235C  0x0201235C  thumb
 *   func_02176230  0x02176230  thumb  ov011
 *   func_0217CE08  0x0217CE08  thumb  ov018
 *   func_02012374  0x02012374  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   func_0200BF10 0x0200BF10 thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0217538C  0x0217538C  thumb  ov011
 *   func_02175368  0x02175368  thumb  ov011
 *   func_021803F0  0x021803F0  thumb  ov018
 *   func_0217545C  0x0217545C  thumb ov011
 *   func_02167A54  0x02167A54  thumb ov010
 *   func_021800A4  0x021800A4  thumb ov018
 *   func_02167A14 0x02167A14 thumb ov010
 *   func_02008494 0x02008494 thumb
 *   func_02175B14 0x02175B14 thumb ov011
 *   func_02082D44 0x02082D44 arm
 *   func_02174E14 0x02174E14 thumb ov011
 *   func_02175DCC  0x02175DCC  thumb  ov011
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02175BCC  0x02175BCC  thumb  ov011
 *   func_0217620C  0x0217620C  thumb  ov011
 *   func_02182A08  0x02182A08  thumb  ov018
 *   func_02182998  0x02182998  thumb  ov018
 *   func_02181BE8  0x02181BE8  thumb  ov018
 *   func_02182988  0x02182988  thumb  ov018
 *   func_02174258  0x02174258  thumb  ov011
 *   func_02175C40  0x02175C40  thumb  ov011
 *   func_0217C914  0x0217C914  thumb  ov018
 *   func_0217553C  0x0217553C  thumb  ov011
 *   func_02173C04  0x02173C04  thumb  ov011
 *   func_0217537C  0x0217537C  thumb  ov011
 *   func_021802A8  0x021802A8  thumb  ov018
 *   str_02183B30   0x02183B30  data   a1
 */
#include "../../matched/include/Obj03092.h"
#include "../../matched/include/Obj00399.h"
#include "../../matched/include/Obj12492.h"
#include "../../matched/include/Obj09396.h"
#include "../../matched/include/Obj00092.h"
#include "../../matched/include/Obj12494.h"
#include "../../matched/include/Obj19364.h"
#include "../../matched/include/Obj12499.h"
#include "../../matched/include/Obj07367.h"
#include "../../matched/include/Obj04178.h"
#include "../../matched/include/Obj00566.h"
#include "../../matched/include/Obj03562.h"

struct Actor;
struct BigObj;
struct Ctx;
struct Obj;
struct PtS;
struct Cfg;
struct U16Vec;
struct WordSet;
struct Rec;
struct Fx;
struct Obj2;
struct P;
struct MsgBank;
struct Handle;
struct Rec44;
struct Sub24;
struct Sub0200852CObj;
struct Desc;
struct S0201235C;
struct Evt;
struct Big;
struct Rec1B0;
struct Work;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct { u16 a, b; u8 x, y; } Ent_0217EC7C;

typedef struct {
    unsigned int lo : 20;
    unsigned int id : 10;
    unsigned int hi : 2;
} Mon;

typedef struct {
    int l, t, r, b;
} Rect;

typedef struct {
    u16 id;
    u8 pad02[0x1A];
} QEnt;

typedef struct {
    u8 pad00[0xA0];
    QEnt e[3];
} Q;

typedef struct {
    int f00;
    u8 pad04[0x8C - 0x04];
    int f8C[3];
    u8 pad98[0xC4 - 0x98];
    int fC4;
    u8 padC8[0xD8 - 0xC8];
    u8 fD8;
    u8 fD9;
    u8 padDA[0x106 - 0xDA];
    u8 f106;
    u8 f107;
    u8 pad108[0x110 - 0x108];
    u16 f110;
    u8 f112;
    u8 f113;
    u8 pad114[0x168 - 0x114];
    u8 f168;
    u8 f169;
} Obj;

typedef struct { u8 a, b, c, d; int e, f; } State;

typedef struct { u16 lo : 3; u16 hi : 13; } Bf;

typedef struct { u8 pad[0x28]; u8 idx; } T;

typedef struct {
    u8 a, b, c, d;
    int e;
    int f;
    T *g;
    u8 h, i, j;
} O;

typedef struct {
    u8 pad0[0x5C];
    void *tbl[9];
    u8 pad80[0x114 - 0x80];
    u8 f114;
    u8 pad115[3];
    u16 f118;
    u8 f11A;
    u8 f11B;
} Ov018Sel;

typedef struct {
    u8 pad0[0x9C];
    void *f9C;
    u8 padA0[0x116 - 0xA0];
    u8 f116;
    u8 f117;
} Ov018Blink;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    u8 f28;
} Ov018Obj_0217EC7C;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj_0217F318;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj_0217F3E4;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj_0217F40C;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj_0217F45C;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj_0217F4C4;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
} Ov018Obj_0217F528;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj_0217F58C;

typedef struct {
    u8 pad0[0x30];
    u16 f30;
} Rec;

typedef struct {
    u8 pad0[0x1A5];
    u8 lo1A5 : 2;
    u8 bit1A5 : 1;
} Ov018Obj_0217F5A0;

typedef struct {
    u8 pad0[0x18];
    u16 f18;
    u8 f1A : 4;
} Ent_0217F3E4;

typedef struct {
    u8 pad0[4];
    void *f04;
    u8 pad8[0x70 - 8];
    Ent_0217F3E4 cur;
    Ent_0217F3E4 arr[];
} Ov018Obj_0217F5F0;

typedef struct {
    int f0;
    int f4;
    int f8;
    u16 *fC;
} Ctx;

typedef struct {
    u8 pad0[0x93F];
    u8 lo93F : 3;
    u8 bit93F : 1;
} Sys;

typedef struct { int f0; int f4; int f8; u16 fC; } Req;

typedef struct {
    int w[13];
} S52;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

typedef struct {
    unsigned char pad00[0x10];
    Ov018Obj obj;
} Ov018Outer;

typedef struct {
    u16 f00;            /* 0x00 */
    u8 pad02[0x10 - 2];
    Ov018Obj obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 f41;             /* 0x41 */
    u8 pad42[0x98 - 0x42];
    u8 f98;             /* 0x98 */
    u8 f99;             /* 0x99 */
} Outer;

typedef struct {
    u16 lo : 9;
    u16 f9 : 6;
    u16 f15 : 1;
} Bits;

extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188CCC(u8 *p);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021A0F94(u32 a);
extern u8 func_02012B58(const struct BigObj *p);
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern Mon *func_0217BEA8(int a0);
extern void func_0217EC44(int x, int y, int w, int h, Rect *r);
extern int func_0217EC5C(u32 x, u32 y, Rect *r);
extern int func_02013DD0(int a0);
extern void func_020061E4(u32 a);
extern u32 func_02013D5C(u32 id);
extern int func_020257C4(const int *p);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02082BCC(void *, int, int);
extern int func_02080D24(unsigned int x);
extern int func_021758C8(u8 *o);
extern u8 *func_02175B34(u8 *p);
extern int func_0217C070(u8 *p);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern int func_02012B70(const struct BigObj *p);
extern void func_02041300(unsigned int, int, int, int, u8, u8, u8);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020409B4(u32 layer);
extern int func_02158590(void *);
extern u32 func_02188C54(u8 *p);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_021904B0(u32 a, u32 b);
int func_02190E40(u32 a);
u32 func_021904C8(struct Rec *a0);
void func_02045808(struct U16Vec *vec);
u32 func_0201ED04(struct WordSet *p);
struct Obj2 *func_02190F64(struct Fx *a, u32 b);
void func_02190EB8(struct P *p, u32 b, u16 c, u32 d);
void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_02034714(const char *expr, u32 line, const char *file);
void func_02190F7C(struct P *p);
u32 func_02190EF0(u32 *p);
extern unsigned int func_020362DC(void);
extern void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
int func_02190728(void *a);
extern int func_02190758(u32 a, u32 b, u32 c, u32 d);
int func_021909BC(void *a);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
int func_02175DA8(u8 *p);
unsigned int func_02026478(void *obj);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_0215A5F4(void *);
extern void *func_0215A5DC(void *);
extern u16 *func_02159AE8(void *, void *);
extern void func_0215897C(void *, void *);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
void *func_020124E4(struct Obj *p);
int func_02158344(int a0);
u32 func_0200FB24(void);
u8 func_02012B80(const struct BigObj *p);
void func_021757A8(u8 *p);
void func_0217BF1C(void *p);
int func_021907A8(void *a0, int a1);
struct WordSet *func_0201EC64(u32 heap);
u8 func_0215841C(void *p);
int func_02190740(u32 a, u32 b, u32 c, u32 d);
void *func_02045EC0(struct MsgBank *bank, u32 index);
int func_021583EC(void *a0, int a1);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
int func_0203D1B4(void);
int func_02173D2C(int a0, int a1);
int func_02175FB4(u8 *p);
int func_02173C6C(int a, int b);
u8 func_0217BF28(u8 *p);
int func_0219077C(u8 *p);
u32 func_02045C04(struct Rec *rec);
int func_02175B8C(u8 *p);
struct Desc *func_0217C458(void *a0, void *a1, u8 *a2, int a3);
void func_0201235C(struct S0201235C *o, u32 *out);
u8 func_02176230(u8 *p, u8 *q);
void *func_0217CE08(void *a, void *b, int c, int d);
void func_02012374(struct Evt *evt, struct Evt **out);
u8 *func_020120F8(const struct Ctx *p);
u16 func_02012AC8(const struct Rec44 *p);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *);
extern u8 func_0200BF10(struct Rec1B0 *p);
void *func_02188C7C(unsigned char *p);
void func_0216D9A0(void *x);
u32 *func_0216D9E4(void *c);
void func_0217538C(u8 *w, int a);
void func_02175368(char *p);
int func_021803F0(u8 *a, u8 *b);
void func_0217545C(u8 *p);
int func_02167A54(int *p, int i);
int func_021800A4(void);
u32 func_02167A14(struct Work *w, int i);
void func_02008494(void *src, void *dst);
int func_02175B14(u8 *a);
void func_02082D44(void *src, void *dst, int n);
void func_02174E14(u8 *a, int b);
int func_02175DCC(void *p);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u32 func_020307B0(void *p);
u8 *func_02175BCC(u8 *p);
int func_0217620C(u8 *, int);
void func_02182A08(void *, void *);
void func_02182998(void *, void *);
void func_02181BE8(void *, void *);
void func_02182988(void *, void *);
int func_02174258(char *a);
int func_02175C40(void *p);
int func_0217C914(u8 *v, u8 *w, u8 *state);
void func_0217553C(u8 *);
int func_02173C04(int, int);
u8 *func_0217537C(u8 *);
void func_021802A8(void *, Outer *, u8 *);
void func_0217EC7C(Q *q, Obj *p, int id);
void func_0217EEB4(int *p);
void func_0217EF44(u8 *p);
void func_0217EF70(int *p, int x);
void func_0217EFCC(char *p, char *q);
void func_0217F008(char *p, char *q);
void func_0217F0C4(u8 *p);
int func_0217F0FC(u8 *p);
void func_0217F118(Ov018Sel *p, int n);
void func_0217F174(u8 *p);
void func_0217F194(Ov018Blink *p);
int func_0217F1E8(u8 *p);
void func_0217F214(void);
void func_0217F240(u8 *p, int mode);
int func_0217F284(u8 *p);
void func_0217F2B4(Ov018Obj_0217EC7C *p, void *a);
void func_0217F318(Ov018Obj_0217F318 *p);
void func_0217F36C(Ov018Obj_0217F318 *p);
void func_0217F390(Ov018Obj_0217F318 *p);
void func_0217F3A4(Ov018Obj_0217F318 *p, void *a);
void func_0217F3C4(Ov018Obj_0217F318 *p, int a);
void func_0217F3E4(Ov018Obj_0217F3E4 *p);
int func_0217F40C(Ov018Obj_0217F40C *p);
int func_0217F420(void);
void func_0217F434(void **p);
void func_0217F45C(Ov018Obj_0217F45C *p);
void func_0217F470(void **p, void *bank, void *handle, unsigned int index, int a, int b);
void func_0217F4A0(void **p, unsigned int index, int a, int b);
void func_0217F4C4(Ov018Obj_0217F4C4 *p);
void func_0217F4D8(void **p, int a);
int func_0217F508(void **p);
void func_0217F528(Ov018Obj_0217F528 *p, int a, int b, int c, int d, int e);
void func_0217F574(void **p, unsigned int index, int a, int b);
void func_0217F58C(Ov018Obj_0217F58C *p);
int func_0217F5A0(Ov018Obj_0217F5A0 *p);
int func_0217F5F0(Ov018Obj_0217F5F0 *p, int idx);
int func_0217F648(void *a, void *vm);
void *func_0217F67C(void *owner, u16 *out);
int func_0217F6A0(void *a0, int *state, Ctx *c);
int func_0217F8A0(void *a, void *vm);
int func_0217F8D0(void *a0, int a);
int func_0217F914(void *unused, void *vm);
void *func_0217F938(void *owner);
int func_0217F95C(void *a0, int *state, void *a2);
void func_0217FA1C(void *p);
void *func_0217FA24(void *owner);
int func_0217FA38(void *a, int *state);
int func_0217FAE0(void *unused, int a);
int func_0217FB2C(void *a, void *vm);
void *func_0217FB5C(void *owner, int b, int unused, int d, int e, u16 f);
int func_0217FB94(int a, int *state, Req *req);
void *func_0217FC08(int a, int b, u8 *c, int d, int e, u16 f);
void *func_0217FC6C(void *p, int a, int b, int c, int d, u16 e);
int func_0217FCAC(int x, int *st, int *obj);
void *func_0217FD34(int a, int b, u8 *c, int d, int e, u16 f);
void func_0217FDA0(int a, u8 *b, u8 *c, int d, int e, int f, u16 g);
void func_0217FE38(void *v, Ov018Outer *c);
int func_0217FE6C(void *a, int *state, Outer *c);
extern const Ent_0217EC7C d_02176AA0[];
extern unsigned char d_02183B2C[];
extern char str_02183B30[];








/*
 *           witness: 0x02013DD0 is an unlabelled arm9 leaf inside
 *           func_02013D9C's listing extent, called only from here. Verified
 *           EXACT (match.py one --region arm9 --thumb) as:
 *             extern const int d_0209DFC0[];   (0x0209DFC0 data a4)
 *             int func_02013B10(int a0, const int *a1, int a2);
 *             int func_02013DD0(int a0)
 *             { return func_02013B10(a0, d_0209DFC0, 4); }
 *           Once that leaf is filed and in a shard, this file verifies EXACT.
 */
void func_0217EC7C(Q *q, Obj *p, int id)
{
    Rect rect;
    u32 tx;
    u32 ty;
    s16 pt[2];
    int x;
    int sel;
    int h;
    int i;
    int w;
    int a;
    const Ent_0217EC7C *e;
    Mon *m;

    x = func_02188CCC(func_0201210C((const struct Ctx *)p->f00));
    func_02012138((const struct Ctx *)p->f00);
    h = (int)func_020120F4((const struct Ctx *)p->f00);
    if (p->f112 != 0 || p->f106 == 1 || !func_02035D20(&tx, &ty) || func_021A0F94(x) != 0) {
        return;
    }
    sel = func_02012B58((const struct BigObj *)h);
    for (i = 0; i < 3; i++) {
        if (i == sel) {
            continue;
        }
        if (!(p->fD9 & (1 << i))) {
            continue;
        }
        w = p->f8C[i];
        if (func_0204B3F4((struct Obj *)w) != 1) {
            continue;
        }
        func_0204B454((struct Actor *)w, (struct PtS *)pt, 0);
        if (tx - 12 > pt[0] || tx + 12 < pt[0]) {
            continue;
        }
        if (ty - 12 > pt[1] || ty + 12 < pt[1]) {
            continue;
        }
        if (q == 0) {
            continue;
        }
        if (func_0217BEA8(q->e[i].id) == 0) {
            continue;
        }
        p->f169 = i;
        return;
    }
    if (func_0217F284((u8 *)p) == 1) {
        return;
    }
    if (p->fD8 != func_02012B58((const struct BigObj *)h)) {
        for (i = 0; i < 8; i++) {
            e = &d_02176AA0[i];
            func_0217EC44(e->x, e->y, 0x10, 0x10, &rect);
            if (func_0217EC5C(tx, ty, &rect) != 1) {
                continue;
            }
            a = e->a;
            if (id == a || id == e->b || (func_02013DD0(id) == 1 && func_02013DD0(a) == 1)) {
                func_020061E4(0x557);
                return;
            }
            if (i == 7) {
                p->f106 = 1;
                p->f107 = 0;
            } else {
                m = func_0217BEA8(a);
                if (m == 0) {
                    continue;
                }
                p->f110 = m->id;
                p->f112 = 1;
            }
            p->f113 = i;
            return;
        }
    }
    if (p->fD8 != func_02012B58((const struct BigObj *)h)) {
        func_0217EC44(0x80, 0x5C, 0x10, 0x10, &rect);
        if (func_0217EC5C(tx, ty, &rect) == 1) {
            if (func_02013D5C(id) == 1) {
                func_020061E4(0x557);
                return;
            }
            p->f110 = 0x117;
            p->f112 = 1;
            p->f113 = 8;
            return;
        }
    }
    if (p->f168 == 0 && func_020257C4((const int *)p->fC4) == 1) {
        func_0217EC44(0xE0, 0x80, 0x1E, 0xC, &rect);
        if (func_0217EC5C(tx, ty, &rect) == 1) {
            p->f168 = 1;
        }
    }
}








void func_0217EEB4(int *p)
{
    int n;

    n = 0;
    if (*((u8 *)p + 0x11f) == 0) {
        if (*((u8 *)p + 0xda) > 1) {
            func_0204989C(0x24, 7, 6, 0, 0x800, 1, 0x15);
            *((u8 *)p + 0x11f) = 1;
            n++;
        }
    } else {
        if (*((u8 *)p + 0xda) <= 1) {
            func_0204989C(0x24, 6, 6, 0, 0x800, 1, 0x15);
            *((u8 *)p + 0x11f) = 0;
            n++;
        }
    }
    if (n != 0) {
        func_02045374((struct Cfg *)p[0x44 / 4]);
        func_02045374((struct Cfg *)p[0x4c / 4]);
        func_02041B6C(6);
        if (func_0217F1E8((u8 *)p) == 1) {
            func_0217F240((u8 *)p, 1);
        }
    }
}







/*
 * interface: r1 holds p[0xd8] at 0x0217EF64 and EF70 reads it.
 */
void func_0217EF44(u8 *p)
{
    func_020120F4(((struct Obj03092 *)p)->f0);
    func_02012138(((struct Obj03092 *)p)->f0);
    if (p[0xd8] != p[0x105]) func_0217EF70((int *)p, p[0xd8]);
}








void func_0217EF70(int *p, int x)
{
    func_020413B0(7, 0, 2, 0x20, 0x10, (u8)(x + 5));
    func_020413B0(6, 0, 2, 0x20, 0x10, (u8)(x + 1));
    if (p[0x44 / 4] != 0) {
        func_02045374((struct Cfg *)p[0x44 / 4]);
        func_02045374((struct Cfg *)p[0x4c / 4]);
    }
    func_02041B6C(7);
    func_02041B6C(6);
    *((u8 *)p + 0x105) = x;
}







/*
 * extent: two zero padding bytes at 0x0217F006.
 * lever: assign the shifted mask before the flag; its flag store schedules
 * ahead of the shift while retaining separate constant-one registers.
 */
void func_0217EFCC(char *p, char *q)
{
    State *s;
    void *h;
    s = (State *)(p + 0xd8);
    h = func_020120F4(((struct Obj00399 *)p)->f0);
    if (q == 0) {
        s->a = func_02012B58(h);
        s->b = 1 << s->a;
        s->c = 1;
        s->d = 0;
        s->e = 0;
        s->f = 0;
    } else {
        func_0217F008(p, q);
    }
}








void func_0217F008(char *p, char *q)
{
    O *o;
    int h;
    int n;
    int i;

    o = (O *)(p + 0xd8);
    h = (int)func_020120F4((const struct Ctx *)(*(int *)&((struct Obj00399 *)p)->f0));
    if (q == 0) {
        func_02082BCC(p + 0xd8, 0, 0x14);
        *(p + 0x11e) = 1;
        return;
    }
    n = func_02012B58((const struct BigObj *)h);
    o->a = ((Bf *)(q + 0x86))->lo;
    o->b = ((struct Obj12492 *)q)->f8FB;
    o->c = func_02080D24(o->b);
    o->d = ((struct Obj12492 *)q)->f910;
    o->e = func_0217F5A0((Ov018Obj_0217F5A0 *)(q + 0x1ac));
    o->f = func_021758C8((u8 *)(q + 0x1ac));
    o->g = (T *)func_02175B34((u8 *)(q + 0x1ac));
    if (o->g != 0) {
        o->h = ((Bf *)(q + o->g->idx * 0x1c + 0xa2))->lo;
    }
    o->i = func_0217C070((u8 *)q);
    o->j = 0;
    for (i = 0; i < 3; i++) {
        if (i != n && o->a == ((Bf *)(q + i * 0x1c + 0xa2))->lo) {
            o->j = 1;
            return;
        }
    }
}







void func_0217F0C4(u8 *p)
{
    int i;
    p[0x115] = 0;
    p[0x114] = 1;
    for (i = 0; i < 7; i++) func_0204B6F4(((void **)p)[23 + i], 6, 1);
    func_0204B6F4(((void **)p)[31], 6, 1);
}







int func_0217F0FC(u8 *p)
{
    if (p[0x114] == 1 && p[0x115] < 10) return 1;
    return 0;
}








void func_0217F118(Ov018Sel *p, int n)
{
    u8 c;

    c = p->f11B;
    if (c != n && p->f114 != 1) {
        if (c < 8) {
            func_0204B6F4(p->tbl[c], 6, 1);
        } else if (c == 8) {
            func_0204B6F4(p->tbl[8], 6, 1);
        }
        if (n < 8) {
            func_0204B6F4(p->tbl[n], 8, 1);
        } else if (n == 8) {
            func_0204B6F4(p->tbl[8], 8, 1);
        }
        p->f11B = n;
        p->f118 = 0;
        p->f11A = 0;
    }
}







void func_0217F174(u8 *p)
{
    p[0x117] = 0;
    p[0x116] = 1;
    func_0204B6F4(((struct Obj09396 *)p)->f9C, 6, 1);
}








void func_0217F194(Ov018Blink *p)
{
    int t;

    if (p->f116 != 0) {
        t = p->f117;
        if (t % 2 == 0) {
            func_0204B6F4(p->f9C, (u8)(((unsigned)t >> 1) & 1 ? 6 : 7), (int)1);
        }
        if (p->f117 < 10) {
            p->f117++;
        }
    }
}







/*
 * extent: Two bytes of alignment padding at 0x0217F212.
 */
int func_0217F1E8(u8 *p)
{
    if (func_02012B70(func_020120F4(((struct Obj00092 *)p)->f0)) == 1) {
        switch (((struct Obj00092 *)p)->fDC) {
        case 2: case 3: case 4: return 1;
        }
    }
    return 0;
}







void func_0217F214(void)
{
    func_02041300(6, 0x3001, 0x14, 0x16, 0xc, 2, 0x11);
    func_02041B6C(6);
}








void func_0217F240(u8 *p, int mode)
{
    func_020410D0(6, 0x14, 0x16, 0xC, 2, (u32)(p + 0x138), 0, 0, 0xC, 2);
    if (mode == 1) {
        func_02041B6C(6);
    } else {
        func_020409B4(6);
    }
}







/*
 * extent: Two bytes of alignment padding at 0x0217F2B2.
 */
int func_0217F284(u8 *p)
{
    void *q = func_020120F4(((struct Obj12494 *)p)->f0);
    if (((struct Obj12494 *)p)->fE4 == 0 && func_02012B58(q) == 0 && func_02158590(q) == 0) return 1;
    return 0;
}








void func_0217F2B4(Ov018Obj_0217EC7C *p, void *a)
{
    void *r;

    r = (void *)func_02188C54(func_0201210C(a));
    if (p->f00 == 0) {
        p->f00 = func_0201EC74(6, 0x20, 4);
        p->f04 = func_020457B0(0x1F0, 4);
        p->f08 = func_020457B0(0x1D0, 4);
        p->f0C = (void *)func_021904B0((u32)r, 0x44);
        p->f10 = (void *)func_021904B0((u32)r, 0x42);
        p->f14 = (void *)func_021904B0((u32)r, 0x43);
        p->f24 = r;
        p->f28 = 0;
    }
}







void func_0217F318(Ov018Obj_0217F318 *p)
{
    func_0217F390(p);
    func_0217F58C((Ov018Obj_0217F58C *)p);
    func_0217F45C((Ov018Obj_0217F45C *)p);
    if (p->f00 != 0) {
        if (p->f18 != 0) {
            func_02190E40((u32)p->f18);
            p->f18 = 0;
        }
        func_021904C8(p->f0C);
        func_021904C8(p->f10);
        func_021904C8(p->f14);
        func_02045808(p->f08);
        func_02045808(p->f04);
        func_0201ED04(p->f00);
        p->f00 = 0;
    }
}







void func_0217F36C(Ov018Obj_0217F318 *p)
{
    if (p->f18 != 0) {
        if (p->f28 == 1) {
            func_0217F3E4((Ov018Obj_0217F3E4 *)p);
        }
    } else {
        p->f18 = func_02190F64(p->f24, (u32)p->f0C);
    }
}







void func_0217F390(Ov018Obj_0217F318 *p)
{
    if (p->f18 != 0) {
        func_02190E40((u32)p->f18);
        p->f18 = 0;
    }
}







void func_0217F3A4(Ov018Obj_0217F318 *p, void *a)
{
    func_0217F36C(p);
    func_02190EB8(p->f18, 0, 0, (u32)a);
    p->f28 = 1;
}







void func_0217F3C4(Ov018Obj_0217F318 *p, int a)
{
    func_02045CAC(p->f0C, a, p->f08);
    func_0201F250(p->f00, p->f04, p->f08);
    func_0217F3A4(p, p->f04);
}







void func_0217F3E4(Ov018Obj_0217F3E4 *p)
{
    if (p->f18 == 0) {
        func_02034714((const char *)d_02183B2C, 0, (const char *)d_02183B2C);
    }
    func_02190F7C(p->f18);
    p->f28 = 0;
}







int func_0217F40C(Ov018Obj_0217F40C *p)
{
    if (p->f18 == 0) {
        return 1;
    }
    return func_02190EF0(p->f18);
}






int func_0217F420(void)
{
    if (func_020362DC() & 0xf3) return 1;
    return 0;
}






/*
 * extent: Two bytes of alignment padding at 0x0217F45A.
 */
void func_0217F434(void **p)
{
    if (p[7] == 0) p[7] = func_02190708(p[9], (u32)p[3], 1, 0x13, 0x1e, 4);
}







void func_0217F45C(Ov018Obj_0217F45C *p)
{
    if (p->f1C != 0) {
        func_02190728((void *)p->f1C);
        p->f1C = 0;
    }
}






void func_0217F470(void **p, void *bank, void *handle, unsigned int index, int a, int b)
{
    func_02045CAC(bank, index, p[2]);
    func_0201F250(p[0], p[1], p[2]);
    func_02190758((u32)handle, (u16)a, (u16)b, (u32)p[1]);
}






void func_0217F4A0(void **p, unsigned int index, int a, int b)
{
    func_0217F434(p);
    func_0217F470(p, p[3], p[7], index, a, b);
}







void func_0217F4C4(Ov018Obj_0217F4C4 *p)
{
    if (p->f2C != 0) {
        func_021909BC((void *)p->f2C);
        p->f2C = 0;
    }
}






void func_0217F4D8(void **p, int a)
{
    func_0201210C((const struct Ctx *)a);
    if (p[11] != 0 || p[3] == 0) func_02034714((const char *)d_02183B2C, 0, (const char *)d_02183B2C);
    p[11] = func_02190BE4(p[9], 0);
}






int func_0217F508(void **p)
{
    if (p[11] == 0) func_02034714((const char *)d_02183B2C, 0, (const char *)d_02183B2C);
    return func_02190C78(p[11]);
}







void func_0217F528(Ov018Obj_0217F528 *p, int a, int b, int c, int d, int e)
{
    func_0201210C((void *)a);
    if (p->f20 != 0) {
        func_02034714((const char *)d_02183B2C, (int)0, (const char *)d_02183B2C);
    }
    p->f20 = func_02190708(p->f24, (u32)p->f0C, (u16)b, (u16)c, d, e);
}






void func_0217F574(void **p, unsigned int index, int a, int b)
{
    func_0217F470(p, p[5], p[8], index, a, b);
}







void func_0217F58C(Ov018Obj_0217F58C *p)
{
    if (p->f20 != 0) {
        func_02190728((void *)p->f20);
        p->f20 = 0;
    }
}







int func_0217F5A0(Ov018Obj_0217F5A0 *p)
{
    Rec *r;

    if (func_02175DA8((u8 *)p) == 1) {
        return 4;
    }
    r = (Rec *)func_02175B34((u8 *)p);
    if (r == 0) {
        return 0;
    }
    if (r->f30 == 0) {
        if (p->bit1A5 == 1) {
            return 3;
        }
        return 1;
    }
    if (p->bit1A5 == 1) {
        return 2;
    }
    return 1;
}







/*
 * lever: a switch with empty sentinel and default arms retains the dead
 * comparison before the shared bitfield return.
 */
int func_0217F5F0(Ov018Obj_0217F5F0 *p, int idx)
{
    Ent_0217F3E4 *e;
    enum Guard { ZERO, INVALID = 0xFFFF } h;

    void *sub;

    sub = (void *)func_02026478(p->f04);
    if (idx == func_02012B58(sub)) {
        e = &p->cur;
    } else {
        e = &p->arr[idx];
    }
    h = e->f18;
    switch (h) {
    case 0:
        if (func_02008550((const struct Sub0200852CObj *)func_02012950((struct Sub24 *)func_02026478(p->f04), idx)) == 0) {
            return 3;
        }
        return 4;
    case 0xFFFF:
        break;
    default:
        break;
    }
    return e->f1A;
}






/*
 * extent: Two bytes of alignment padding at 0x0217F67A.
 */
int func_0217F648(void *a, void *vm)
{
    void *owner = func_0215A5F4(vm);
    void *sys = func_0215A5DC(vm);
    func_0215897C(owner, func_0217F67C(sys, func_02159AE8(a, vm)));
    return 1;
}






void *func_0217F67C(void *owner, u16 *out)
{
    void *task;
    u8 *work;
    int zero;
    zero = 0;
    task = func_020122C0(owner, 0, func_0217F6A0, 0x10);
    work = func_020124E8(task);
    *(u16 * *)&((struct Obj19364 *)work)->fC = out;
    *out = zero;
    return task;
}







int func_0217F6A0(void *a0, int *state, Ctx *c)
{
    void *h;
    void *s;
    u32 k;
    u8 *w;
    void *t;
    int flag;

    h = func_020124E4(a0);
    s = func_020120F4(h);
    k = func_02012138(h);
    t = func_0201210C(h);
    flag = 0;
    w = (u8 *)func_02158344(k);
    if (w == 0 && *state > 0 && *state < 5) {
        *state = 5;
    }
    switch (*state) {
    case 0: {
        void *g;
        int a;
        int b;

        if (func_0200FB24() != 0 || (w == 0 && func_02012B80(s) != func_02012B58(s))) {
            *state = 7;
            break;
        }
        if (w != 0) {
            func_021757A8(w + 0x1AC);
            func_0217BF1C(w + 0x914);
        }
        g = (void *)func_02188C54(t);
        c->f0 = func_021904B0((int)g, 0x2D);
        c->f4 = func_021907A8(g, c->f0);
        c->f8 = (int)func_0201EC64(4);
        func_020061E4(0x547);
        if (w == 0 || func_0215841C(s) == func_02012B58(s)) {
            func_02190740(c->f4, 0, 0, 0x49);
            flag = 1;
        } else {
            a = (int)func_020457B0(0x100, 0x15);
            b = (int)func_02045EC0((struct MsgBank *)c->f0, 0x4A);
            func_0201F02C((struct WordSet *)c->f8, 0, (void *)func_021583EC(s, func_0215841C(s)));
            func_0201F250((struct WordSet *)c->f8, (void *)a, (void *)b);
            func_02190758(c->f4, 0, 0, a);
            func_02045808((struct U16Vec *)b);
            func_02045808((struct U16Vec *)a);
        }
        if (func_0203D1B4() <= 1) {
            if (flag == 0) {
                *c->fC = 0;
            } else {
                *c->fC = 1;
            }
            *state = 5;
            break;
        }
        (*state)++;
    }
    case 1:
        if (func_02173D2C((int)w, func_0215841C(s)) == 1) {
            (*state)++;
        }
        break;
    case 2:
        if (func_02175FB4(w + 0x1AC + func_0215841C(s) * 0x28) == 1) {
            (*state)++;
        }
        break;
    case 3:
        if (func_02173C6C((int)w, func_0215841C(s)) == 1) {
            (*state)++;
        }
        break;
    case 4:
        if (func_0217BF28(w + 0x914) == 1) {
            *c->fC = 1;
            *state = 5;
        }
        break;
    case 5:
        if (func_0219077C((u8 *)c->f4) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (func_020362DC() & 0xF3) {
            func_0201ED04((struct WordSet *)c->f8);
            func_02190728((void *)c->f4);
            func_02045C04((struct Rec *)c->f0);
            (*state)++;
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}






/*
 * extent: two bytes of zero alignment padding follow at 0x0217F8CE.
 * lever: stores in both arms keep the branch to the shared store.
 */
int func_0217F8A0(void *a, void *vm)
{
    u16 *out;
    u8 *p;
    int v;
    out = func_02159AE8(a, vm);
    p = (u8 *)func_02158344((int)((void *)func_02012138(func_0215A5DC(vm))));
    if (p == 0 || ((struct Obj12499 *)p)->f88 == 0) {
        *out = 0;
    } else {
        *out = ((struct Obj12499 *)p)->f88;
    }
    return 0;
}







int func_0217F8D0(void *a0, int a)
{
    u16 *out;
    Sys *s;
    int v;

    out = func_02159AE8(a0, (void *)a);
    s = (Sys *)func_02158344(func_02012138(func_0215A5DC((void *)a)));
    if (s != 0 && s->bit93F == 0 && func_02175B8C((u8 *)s + 0x1AC) == 1) {
        v = 1;
    } else {
        v = 0;
    }
    *out = v;
    return 0;
}






int func_0217F914(void *unused, void *vm)
{
    void *owner;
    owner = func_0215A5F4(vm);
    func_0215897C(owner, func_0217F938(func_0215A5DC(vm)));
    return 1;
}





void *func_0217F938(void *owner)
{
    void *task;
    task = func_020122C0(owner, 0, func_0217F95C, 0x30);
    func_02082BCC(func_020124E8(task), 0, 0x30);
    return task;
}






int func_0217F95C(void *a0, int *state, void *a2)
{
    void *h;
    u8 *w;
    struct Desc *r;

    h = func_020124E4(a0);
    w = (u8 *)func_02158344(func_02012138(h));
    if (w == 0 && *state < 3) {
        *state = 3;
    }
    switch (*state) {
    case 0:
        w[0x93F] |= 8;
        func_0217F2B4((Ov018Obj_0217EC7C *)a2, h);
        if (func_0217F5A0((Ov018Obj_0217F5A0 *)(w + 0x1AC)) == 3) {
            *state = 2;
        } else {
            func_0217F4A0(a2, 0x1A, 0, 0);
            (*state)++;
        }
        break;
    case 1:
        switch (func_0217F5A0((Ov018Obj_0217F5A0 *)(w + 0x1AC))) {
        case 2:
            break;
        case 3:
        default:
            (*state)++;
            break;
        }
        break;
    case 2:
        r = func_0217C458(h, func_0201210C(h), w, 0x15);
        func_0217FA1C(a2);
        func_0201235C(a0, (u32 *)r);
        return 0;
    case 3:
        func_0217FA1C(a2);
        return 1;
    }
    return 0;
}






void func_0217FA1C(void *p)
{
    func_0217F318((Ov018Obj_0217F318 *)p);
}





void *func_0217FA24(void *owner)
{
    return func_020122C0(owner, 0, func_0217FA38, 0);
}






int func_0217FA38(void *a, int *state)
{
    void *s;
    u32 h;
    void *p2;
    void *p3;
    u8 *w;
    void *r;

    s = func_020124E4(a);
    h = func_02012138(s);
    p2 = func_020120F4(s);
    p3 = func_0201210C(s);
    w = (u8 *)func_02158344(h);
    switch (*state) {
    case 0:
        if (w == 0) {
            func_02012B58(p2);
        } else {
            func_02176230(w, w + 0x1AC);
        }
        r = func_0217CE08(s, p3, 0x117, 1);
        if (r == 0) {
            return 1;
        }
        func_02012374(a, r);
        (*state)++;
        break;
    case 1:
        if (func_02013D5C(func_02012AC8((const struct Rec44 *)func_020120F8(s))) == 1) {
            func_02012374(a, func_0217F938(s));
        }
        (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}






/*
 * What closed it: the store through `out` is written in each arm of the
 * if/else (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md)
 * rather than once after it through a shared `v`; the single store made
 * `v` live across the join and coloured out/q/temp as r6/r4/r5 instead of
 * r5/r6/r4 (docs/notes/pkt_ov018_0217FAE0.c.txt has the earlier miss).
 */
int func_0217FAE0(void *unused, int a)
{
    u16 *out;
    void *t;
    void *q;
    int v;

    out = func_02159AE8(unused, (void *)a);
    t = func_0215A5DC((void *)a);
    func_02012138(t);
    q = func_020120F4(t);
    if (func_0215841C(q) == func_02012B58(q)) {
        *out = 0;
    } else {
        v = func_0215841C(q) - func_02012B58(q);
        if (v < 0) {
            v += 3;
        }
        *out = v;
    }
    return 0;
}





int func_0217FB2C(void *a, void *vm)
{
    u16 *out;
    int v;
    out = func_02159AE8(a, vm);
    if (func_0200BF10((struct Rec1B0 *)func_0200BE48(func_02012EBC(func_020120F4(func_0215A5DC(vm))))) != 0x30) {
        v = 1;
    } else {
        v = 0;
    }
    *out = v;
    return 0;
}





void *func_0217FB5C(void *owner, int b, int unused, int d, int e, u16 f)
{
    Req *work;
    void *task;
    task = func_020122C0(owner, 0, func_0217FB94, 0x10);
    work = func_020124E8(task);
    func_02082BCC(work, 0, 0x10);
    work->f0 = b;
    work->f4 = d;
    work->f8 = e;
    work->fC = f;
    return task;
}






int func_0217FB94(int a, int *state, Req *req)
{
    int s;
    u8 *w;

    s = (int)func_020124E4((struct Obj *)a);
    w = (u8 *)func_02158344(func_02012138((const struct Ctx *)s));
    switch (*state) {
    case 0:
        if (w == 0) {
            return 1;
        }
        func_0216D9A0(func_02188C7C((u8 *)req->f0));
        func_02012374((struct Evt *)a, func_0217FC08(s, req->f0, w, req->f4, req->f8, req->fC));
        (*state)++;
        break;
    case 1:
        func_0216D9E4(func_02188C7C((u8 *)req->f0));
        return 1;
    }
    return 0;
}






void *func_0217FC08(int a, int b, u8 *c, int d, int e, u16 f)
{
    void *r = func_020122C0((void *)a, 0, func_0217FE6C, 0x9c);
    u8 *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x9c);
    func_0217FDA0(a, (u8 *)((int *)c), q, b, d, e, f);
    func_0217538C(c, e);
    func_02175368((char *)c);
    q[0x41] = func_021803F0(q, c);
    return r;
}






void *func_0217FC6C(void *p, int a, int b, int c, int d, u16 e)
{
    void *r = func_020122C0(p, 0, func_0217FCAC, 0x10);
    int *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x10);
    q[0] = a;
    q[1] = c;
    q[2] = d;
    ((struct Obj07367 *)q)->fC = e;
    func_0217545C((u8 *)b);
    return r;
}






int func_0217FCAC(int x, int *st, int *obj)
{
    int v = (int)func_020124E4((struct Obj *)x);
    int *m;

    m = (int *)func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        if (m == 0) {
            return 1;
        }
        if (func_02167A54((int *)m[2], obj[2]) == 0) {
            return 1;
        }
        func_0216D9A0(func_02188C7C((unsigned char *)obj[0]));
        func_02012374((struct Evt *)x, func_0217FD34(v, obj[0], (u8 *)m, obj[1], obj[2], ((struct Obj04178 *)obj)->fC));
        *st = *st + 1;
        break;
    case 1:
        func_0216D9E4(func_02188C7C((unsigned char *)obj[0]));
        return 1;
    }
    return 0;
}






void *func_0217FD34(int a, int b, u8 *c, int d, int e, u16 f)
{
    void *r = func_020122C0((void *)a, 0, func_021800A4, 0x9c);
    u8 *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x9c);
    func_0217FDA0(a, (u8 *)((int *)c), q, b, d, e, f);
    q[0x41] = c[0x11c];
    *(S52 *)(q + 0x44) = *(S52 *)(c + 0x120);
    return r;
}




void func_0217FDA0(int a, u8 *b, u8 *c, int d, int e, int f, u16 g)
{
    enum Local { LOCAL_ZERO } loc;

    ((struct Obj03562 *)c)->f0 = g;
    ((struct Obj03562 *)c)->f4 = e;
    loc = f;
    ((struct Obj03562 *)c)->f8 = func_02167A14((struct Work *)(((struct Obj00566 *)b)->f8), loc);
    ((struct Obj03562 *)c)->fC = d;
    c[0x40] = (u8)f;
    c[0x42] = func_0217F5F0((Ov018Obj_0217F5F0 *)b, (u8)f);
    func_02008494((void *)func_021583EC(func_020120F4((const struct Ctx *)a), loc), c + 0x78);
    if (func_02175B14(b + 0x1ac) == 1) {
        func_02082D44(func_02175B34(b + 0x1ac), c + 0x44, 0x34);
    }
    func_0217F2B4((Ov018Obj_0217EC7C *)(c + 0x10), (void *)a);
    func_02174E14(b, 1);
    func_02175368((char *)b);
    b[0x93f] = b[0x93f] & ~0x30;
}




void func_0217FE38(void *v, Ov018Outer *c)
{
    func_0217F4C4((Ov018Obj_0217F4C4 *)(&c->obj));
    func_0217F318((Ov018Obj_0217F318 *)(&c->obj));
    if (v != 0) {
        func_02174E14(v, 0);
        func_0217538C(v, 4);
        func_02175368(v);
    }
}


/*
 * Task callback in the shape of func_02182AA4: a 10-state sequence; state 0
 * copies the 0x98-byte work block into a temporary allocation (lines 493
 * and 517 of the file string at 0x02183B30) and hands it to one of the
 * follow-up task starters.
 */
int func_0217FE6C(void *a, int *state, Outer *c)
{
    u8 *v;
    u8 *p;
    void *t;
    int kind;
    Bits *b;

    v = (u8 *)func_02158344((int)((void *)func_02012138(func_020124E4(a))));
    if (v == 0) {
        if (func_0217F40C((Ov018Obj_0217F40C *)(&c->obj)) == 0) {
            return 0;
        }
        if (*state <= 6) {
            func_0217F3C4((Ov018Obj_0217F318 *)(&c->obj), 4);
            *state = 8;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        kind = func_02175DCC(v + 0x1AC);
        b = (Bits *)(v + 0xA2 + c->f40 * 0x1C);
        if (b->f15 == 1) {
            t = func_02030734((u16)((c->f00 & 0x7FFF) | 0x8000), 0x98, 1, str_02183B30, 493);
            func_02082D44(c, t, 0x98);
            if (func_02175BCC(v + 0x1AC) == 0 && func_02175B14(v + 0x1AC) == 1
                && func_02175B8C(v + 0x1AC) == 1 && func_0217620C(v + 0x1AC, c->f40) == 1) {
                func_02182A08(a, t);
            } else {
                func_02182998(a, t);
            }
            func_020307B0(t);
        } else if (b->f9 != 0) {
            t = func_02030734((u16)((c->f00 & 0x7FFF) | 0x8000), 0x98, 1, str_02183B30, 517);
            func_02082D44(c, t, 0x98);
            if (((Bits *)(v + c->f40 * 0x1C + 0xA2))->f9 == 2) {
                if (kind == 5) {
                    func_02181BE8(a, t);
                } else {
                    func_02182988(a, t);
                }
            } else {
                func_02182998(a, t);
            }
            func_020307B0(t);
        } else {
            (*state)++;
        }
        break;
    case 1:
        if (func_02174258((char *)v) == 1) {
            (*state)++;
        }
        break;
    case 2:
        switch (func_02175C40(v + 0x1AC)) {
        case 1:
            c->f99 = 1;
            (*state)++;
            break;
        case 2:
            (*state)++;
            break;
        }
        break;
    case 3:
        switch (func_0217C914(v, (u8 *)c, &c->f98)) {
        case 1:
            func_0217553C(v);
            *state = 4;
            break;
        case 2:
            *state = 9;
            break;
        case 3:
            *state = 7;
            break;
        }
        break;
    case 4:
        if (func_02173C04(c->f40, c->f99) == 1) {
            (*state)++;
        }
        break;
    case 5:
        p = func_0217537C(v);
        if (p != 0) {
            if (p[1] != c->f99 || c->f99 == 1) {
                c->f41 = 0;
            }
            (*state)++;
        }
        break;
    case 6:
        func_021802A8(a, c, v);
        return 0;
    case 7:
        *state = 9;
        break;
    case 8:
        if (func_0217F420() == 1) {
            *state = 9;
        }
        break;
    case 9:
        func_0217FE38(v, (Ov018Outer *)c);
        return 1;
    }
    return 0;
}
