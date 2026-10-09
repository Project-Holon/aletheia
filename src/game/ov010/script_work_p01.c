/*
 * file:     script_work_p01.c
 * unit:     yes
 * function: func_02157954, func_02157960, func_02157968, func_0215796C, func_02157980, func_02157998, func_021579A4, func_021579AC, func_021579B0, func_02157A30, func_02157A58, func_02157A78, func_02157AC8, func_02157AF0, func_02157B88, func_02157C48, func_02157D0C, func_02157D68, func_02157D98, func_02157DB8, func_02157DD8, func_02157E08, func_02157E34, func_02157E6C, func_02157E78, func_02157E8C, func_02157E9C, func_02158318, func_02158344, func_02158378, func_0215839C, func_021583CC, func_021583EC, func_0215840C, func_0215841C, func_02158428, func_02158434, func_0215843C, func_02158468, func_021584A4, func_021584F4, func_0215850C, func_02158570, func_02158590, func_021585BC, func_021585E0, func_02158614, func_02158630, func_02158678, func_021586C8, func_0215870C, func_0215874C, func_02158768, func_02158780, func_021587B0, func_021587E0, func_02158804, func_02158824, func_0215882C, func_0215886C, func_02158894, func_0215889C, func_021588A4, func_021588B0, func_021588C0
 * address:  0x02157954
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_0203F328  0x0203F328  arm
 *   func_02179D3C 0x02179D3C thumb ov015
 *   func_0203CEAC 0x0203CEAC arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D378  0x0203D378  arm
 *   func_0217998C  0x0217998C  thumb ov015
 *   func_02039C68 0x02039C68 arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_0203D0DC 0x0203D0DC arm
 *   func_02030734 0x02030734 arm
 *   d_02172878 0x02172878 data a1
 *   func_0203CBAC 0x0203CBAC arm
 *   d_02172868 0x02172868 data a1
 *   d_02172808 0x02172808 data a1
 *   func_020307B0  0x020307B0  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_020186C8  0x020186C8  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017FA8  0x02017FA8  thumb
 *   func_0201808C  0x0201808C  thumb
 *   func_020180F4  0x020180F4  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0202F2AC  0x0202F2AC  thumb
 *   func_02045A98  0x02045A98  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   d_02170068     0x02170068  data
 *   d_0209DF08     0x0209DF08  data  a1
 *   d_0209DF0C     0x0209DF0C  data  a1
 *   d_020A7370     0x020A7370  data
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02026478  0x02026478  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_020127B8   0x020127B8  thumb
 *   func_020127AC   0x020127AC  thumb
 *   func_02012950   0x02012950  thumb
 *   func_02012B80   0x02012B80  thumb
 *   func_0200855C 0x0200855C thumb
 *   func_02012984  0x02012984  thumb
 *   func_02012B98  0x02012B98  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201444C  0x0201444C  thumb
 *   d_021700AC 0x021700AC data a2
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   d_021700A8 0x021700A8 data a2
 *   func_02175B14  0x02175B14  thumb
 *   func_02176258  0x02176258  thumb
 *   func_02176230  0x02176230  thumb
 *   func_02008500  0x02008500  thumb
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_02158920  0x02158920  thumb  ov010
 *   func_020124E4 0x020124E4 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02012374 0x02012374 thumb
 *   func_0201235C  0x0201235C  thumb
 *   func_021589DC 0x021589DC thumb ov010
 *   d_02172888 0x02172888 data a1
 *   func_02011298  0x02011298  thumb
 *   func_02158CB4  0x02158CB4  thumb  ov010
 */
#include "../../matched/include/Obj18739.h"
#include "../../matched/include/Obj01335.h"
#include "../../matched/include/Obj02664.h"
#include "../../matched/include/Obj01831.h"
#include "../../matched/include/Obj04915.h"
#include "../../matched/include/Obj18743.h"
#include "../../matched/include/Obj18744.h"
#include "../../matched/include/Obj07276.h"
#include "../../matched/include/Obj18745.h"
#include "../../matched/include/Obj17623.h"
#include "../../matched/include/Obj00105.h"
#include "../../matched/include/Obj12028.h"
#include "../../matched/include/Obj09153.h"
#include "../../matched/include/Obj12029.h"
#include "../../matched/include/Obj17624.h"
#include "../../matched/include/Obj12271.h"
#include "../../matched/include/Obj17625.h"

struct Entry;
struct Link;
struct Object;
struct Req;
struct Mon;
struct MsgBank;
struct U16Vec;
struct Sub0200852CObj;
struct Ctx;
struct BigObj;
struct SaveBlock;
struct Rec44;
struct Sub24;
struct Sub02014444Obj;
struct Desc;
struct Obj;
struct Evt;
struct ScriptVm;
struct S0201235C;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32_0215796C;

typedef struct { u32 a; u16 b; } S;

typedef struct { u8 pad[0x668]; u32 a; u8 pad2[6]; u16 b; } D_0215796C;

typedef signed int s32_02157980;

typedef struct { u32 a, b; } V;

typedef struct { u8 pad[0x67c]; V v; } D_02157980;

typedef signed int s32_02157998;

typedef struct { u8 pad[0x66c]; u32 w; } D_02157998;

typedef signed int s32_021579A4;

typedef struct { int a; u16 b; } Loc;

typedef struct Object {
    u32 f00;
    u8 pad04[0x74];
    u32 n;
} Object;

typedef int s32_021579AC;

typedef unsigned long long u64;

typedef struct GiftMon {
    u32 otId;           /* 0x00 */
    u32 f04;            /* 0x04 */
    u32 pid;            /* 0x08 */
    u16 ribbons;        /* 0x0C */
    u16 ball;           /* 0x0E */
    u16 item;           /* 0x10 */
    u16 moves[4];       /* 0x12 */
    u16 species;        /* 0x1A */
    u8 form;            /* 0x1C */
    u8 lang;            /* 0x1D */
    u16 nick[11];       /* 0x1E */
    u8 nature;          /* 0x34 */
    u8 gender;          /* 0x35 */
    u8 ability;         /* 0x36 */
    u8 pidType;         /* 0x37 */
    u16 eggLoc;         /* 0x38 */
    u16 metLoc;         /* 0x3A */
    u8 f3C;             /* 0x3C */
    u8 contest[6];      /* 0x3D */
    u8 hp;              /* 0x43 */
    u8 atk;             /* 0x44 */
    u8 def;             /* 0x45 */
    u8 spe;             /* 0x46 */
    u8 spa;             /* 0x47 */
    u8 spd;             /* 0x48 */
    u8 pad49;
    u16 otName[8];      /* 0x4A */
    u8 otGender;        /* 0x5A */
    u8 level;           /* 0x5B */
    u8 isEgg;           /* 0x5C */
    u8 pad5D[0xAC - 0x5D];
    s32_021579AC date;           /* 0xAC */
    u8 padB0[3];
    u8 fB3;             /* 0xB3 */
} GiftMon;

typedef struct IvMoves {
    u8 iv[6];
    u16 moves[4];
} IvMoves;

typedef struct { u8 a : 4; u8 f : 2; u8 b : 2; } Fl_0;

typedef struct Rec28 {
    u8 data[0x28];
} Rec28;

typedef struct RecHolder {
    u8 pad[0x1AC];
    Rec28 recs[1];      /* 0x1AC */
} RecHolder;

typedef struct { u16 f : 3; u16 g : 13; } Fh;

typedef struct { u8 low:2; u8 flag:1; u8 high:5; } Flag_021585E0;

typedef struct { u8 a : 5; u8 f : 1; u8 b : 2; } Fl_1;

typedef struct { u8 a : 6; u8 f : 1; u8 b : 1; } FlagsF8;

typedef struct { u8 low:2; u8 flag:2; u8 high:4; } Flag_0215874C;

extern int func_0203CD98(void);
extern void func_02082D44(void *, void *, u32);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_0203F328(u16 *p, u32 size, u32 seed);
extern int func_02179D3C(void);
extern int func_0203CEAC(int);
extern struct Entry *func_020399A8(void);
extern u32 func_02039CB4(struct Link *p, u32 lo, u32 hi);
extern u32 func_0203D378(void);
extern void func_0217998C(int);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_020056EC(u32 range);
extern int func_0203D1B4(void);
extern int func_0203D0DC(int a0);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020173F0(u16 species, u16 level, u64 id, int heap);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017FA8(void *p);
extern u32 func_0201808C(void *p, u32 move);
extern void func_020180F4(void *p, int move);
extern void func_02018A00(void *p, u32 a, u32 b);
extern void *func_020185F0(void *p);
extern void func_020185C4(void *p);
extern void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern u16 func_02045A98(void);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012B70(const struct BigObj *p);
extern u32 func_0202648C(void *obj);
extern u32 func_02026474(void *obj);
extern u32 func_0200FB24(void);
extern u32 func_02026454(void *obj);
extern u32 func_02026460(void *obj);
extern u32 func_02026478(void *obj);
extern u8 func_02012B58(const struct BigObj *p);
extern void *func_020127B8(void *p);
extern void *func_020127AC(struct SaveBlock *p, u32 idx);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u8 func_02012B80(const struct BigObj *p);
extern u8 func_0200855C(const struct Sub0200852CObj *obj);
extern u8 func_02012984(const struct BigObj *p);
extern u8 func_02012B98(const struct BigObj *p, u32 i);
extern void *func_02012B38(const struct BigObj *p);
extern u32 func_0201444C(struct Sub02014444Obj *o);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *, int);
extern int func_02175B14();
extern int func_02176258(int);
extern int func_02176230(void *, void *);
extern void func_02008500(void *a, void *b);
int func_0203CDBC(void);
extern struct Desc *func_02158920(int a, int b, int c, int d, int e);
extern void *func_020124E4(struct Obj *p);
extern void *func_020124E8(struct Obj *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_0201235C();
extern int func_021589DC(int a0);
extern int func_02011298(struct ScriptVm *vm);
extern int func_02158CB4(int a0);
void func_02157954(u8 *p, int v, int a2);
void func_02157960(int a, int b, int c);
void func_02157968(void);
void func_0215796C(int x, int y, S *s, D_0215796C *d);
void func_02157980(int x, int y, const V *s, D_02157980 *d);
void func_02157998(int x, int y, u32 *s, D_02157998 *d);
u8 *func_021579A4(int a, u8 *p);
void func_021579AC(void);
void func_021579B0(u8 *p);
void func_02157A30(int p);
void func_02157A58(int p);
void func_02157A78(u32 *p);
void func_02157AC8(int *p);
void func_02157AF0(int *p);
void func_02157B88(int *p);
void func_02157C48(Object *p);
void func_02157D0C(int *p);
void func_02157D68(int *p);
void func_02157D98(int p);
void func_02157DB8(int p);
void *func_02157DD8(u8 *p);
int func_02157E08(void *p);
int func_02157E34(void *p);
unsigned char func_02157E6C(char *p);
void func_02157E78(u8 *p);
int func_02157E8C(void *a0);
void *func_02157E9C(const GiftMon *g, int heap, void *save);
int func_02158318(int a0);
int func_02158344(int a0);
int func_02158378(void *p);
int func_0215839C(u8 *p, int m, int a2);
int func_021583CC(void *a0, int a1);
int func_021583EC(void *a0, int a1);
Rec28 *func_0215840C(RecHolder *h, int idx);
u8 func_0215841C(void *p);
u8 func_02158428(u8 *p);
void *func_02158434(char *p);
int func_0215843C(void *p);
int func_02158468(int a0);
int func_021584A4(int unused, int a, int mode);
int func_021584F4(int a0, int a1);
int func_0215850C(int a0, int a1);
int func_02158570(u16 value);
int func_02158590(void *p);
int func_021585BC(int a0);
int func_021585E0(int p);
void func_02158614(void *p);
int func_02158630(int a);
int func_02158678(void *p);
int func_021586C8(int a, int b);
int func_0215870C(void *p, int b);
void func_0215874C(void *p);
struct Desc *func_02158768(int a0, int a1, int a2, int a3);
int func_02158780(void *p, u16 b, int c, int d, u16 e);
int func_021587B0(int a0, int a1, int a2, int a3);
int func_021587E0(int a, int b);
void *func_02158804(u32 heap);
void func_02158824(void *a0, unsigned a1, unsigned a2, unsigned a3);
int func_0215882C(int a0);
int func_0215886C(int a0, int a1);
int func_02158894(int a0, int a1);
void func_0215889C(void *p, u32 *out);
void func_021588A4(void *p, int a);
int func_021588B0(int a0, int a1, int a2);
int func_021588C0(int a0);
extern const char d_02172878[];
extern u8 d_02172868[];
extern u8 d_02172808[];
extern u32 d_02170068[];
extern u8 d_0209DF08[];
extern u8 d_0209DF0C[];
extern void *d_020A7370;
extern const u16 d_021700AC[61];
extern const u16 d_021700A8[2];
extern const char d_02172888[];



/*
 * Unlabelled leaf setter (hidden in a .word run); filed as a helper because
 * its address is the witness for the tail-call thunk at 0x02157960.
 */
void func_02157954(u8 *p, int v, int a2)
{
    ((struct Obj18739 *)p)->f678 = v;
}



void func_02157960(int a, int b, int c)
{
    func_02157954((u8 *)a, b, c);
}


void func_02157968(void) {}

void func_0215796C(int x, int y, S *s, D_0215796C *d) { d->b = s->b; d->a = s->a; }

void func_02157980(int x, int y, const V *s, D_02157980 *d) { d->v = *s; }

void func_02157998(int x, int y, u32 *s, D_02157998 *d) { d->w = *s; }


u8 *func_021579A4(int a, u8 *p) { return p + 0x7c; }







/*
 * Unlabelled empty callback (bx lr) hidden in a .word run; witness for the
 * function pointer taken in func_021579B0.
 */
void func_021579AC(void)
{
}








void func_021579B0(u8 *p)
{
    if (func_0203CD98() != 0)
        return;
    if (p[0x675] == 0) {
        if (((struct Obj01335 *)p)->f66C == 1) {
            p[0x674] = 3;
        } else {
            p[0x674] = 1;
            func_02082D44(p + 0x7C, ((struct Obj01335 *)p)->fC, ((struct Obj01335 *)p)->f8);
            if (((struct Obj01335 *)p)->f672 != func_0203F1FC(*(const u8 * *)&((struct Obj01335 *)p)->fC, ((struct Obj01335 *)p)->f8))
                p[0x674] = 2;
            func_0203F328(((struct Obj01335 *)p)->fC, ((struct Obj01335 *)p)->f8, ((struct Obj01335 *)p)->f668);
        }
    } else {
        if (p[0x676] == 1)
            p[0x674] = 1;
        else
            p[0x674] = 3;
    }
    func_02157960((int)p, (int)func_021579AC, 0xF8);
}







void func_02157A30(int p) { if (func_02179D3C()) func_0203CEAC(0); func_02157960(p, (int)func_021579B0, 0x102); }







void func_02157A58(int p) { func_0203CEAC(0); func_02157960(p, (int)func_021579B0, 0x10a); }








void func_02157A78(u32 *p)
{
    int k = 0x23;
    void *h = func_020399A8();

    if (func_02039CB4(h, 0x23, (u8)*p) != 0) {
        if (func_0203D378() != 0) {
            k = 0x12C;
            func_0217998C(k);
            k -= 0x19;
            func_02157960((int)p, (int)func_02157A30, k);
            return;
        }
        k += 0xF3;
        func_02157960((int)p, (int)func_02157A58, k);
    }
}







void func_02157AC8(int *p) { int k = 0x23; func_02039C68((struct Link *)func_020399A8(), k, (u8)p[0]); func_02157960((int)p, (int)func_02157A78, k + 0xfc); }







void func_02157AF0(int *p)
{
    u8 *b = (u8 *)p;
    if (func_02039CB4((struct Link *)func_020399A8(), 0x18, (u8)p[0]) == 0)
        return;
    if (b[0x675] != 0) {
        if (b[0x676] == 1) {
            int *e = (int *)(b + 8 + b[0x677] * 16);
            int k = 0xFF;
            if (func_0203D3F8((u32)func_020399A8(), 0xFF, (unsigned)(p[0] << 24) >> 16, e[0], e[1], 0, 0, 1) == 0)
                return;
            func_02157960((int)p, (int)((void *)func_02157AC8), k + 0x2F);
            return;
        }
        func_02157960((int)p, (int)((void *)func_02157AC8), 0x133);
        return;
    }
    func_02157960((int)p, (int)((void *)func_02157AC8), 0x137);
}







void func_02157B88(int *p)
{
    u8 *b = (u8 *)p;
    if (b[0x676] == 1) {
        Loc l;
        int *s = *(int * *)&((struct Obj02664 *)b)->f664;
        l.b = func_0203F1FC((const u8 *)s[1], s[0]);
        l.a = ((struct Obj02664 *)b)->f668;
        if (func_0203D3A8(func_020399A8(), (u16)((p[0] << 8) + 1), (u16)8, (u32)(&l)) == 0)
            return;
        func_02039C68((struct Link *)func_020399A8(), 0x18, (u8)p[0]);
        ((struct Obj02664 *)b)->f670 = 0;
        func_02157960((int)p, (int)((void *)func_02157AF0), 0x152);
        return;
    }
    ((struct Obj02664 *)b)->f66C = 1;
    if (func_0203D3A8(func_020399A8(), (u16)((p[0] << 8) + 3), (u16)4, (u32)(b + 0x66C)) == 0)
        return;
    func_02039C68((struct Link *)func_020399A8(), 0x18, (u8)p[0]);
    ((struct Obj02664 *)b)->f670 = 0;
    func_02157960((int)p, (int)((void *)func_02157AF0), 0x162);
}







/*
 * levers: the RNG result is the third argument to func_0203F328, kept live
 *   in r2 across its preceding store. The bound is read as p->n in the for
 *   condition rather than through n; expanding that one use changes the
 *   hoisted bound/far-word allocation from r7/r6 to the original r6/r7.
 */
void func_02157C48(Object *p)
{
    u8 *b = (u8 *)p;
    int *e;
    u32 i;
    unsigned long n;
    if (func_02039CB4((struct Link *)func_020399A8(), 0x17, (u8)p->f00) == 0)
        return;
    if (b[0x675] != 0) {
        e = 0;
        b[0x676] = 0;
        n = p->n;
        for (i = 0; i < p->n; i++) {
            e = (int *)(b + 8 + i * 16);
            if (e[2] == ((struct Obj01831 *)b)->f67C && (e[3] & ((struct Obj01831 *)b)->f680)) {
                b[0x677] = i;
                b[0x676] = 1;
                break;
            }
        }
        func_02157960((int)p, (int)func_02157B88, 0x188);
        if (b[0x676] == 1) {
            u32 t = func_020056EC(0);
            ((struct Obj01831 *)b)->f668 = t;
            func_0203F328((u16 *)e[1], e[0], t);
            *(int * *)&((struct Obj01831 *)b)->f664 = e;
        }
        return;
    }
    func_02039C68((struct Link *)func_020399A8(), 0x18, (u8)p->f00);
    func_02157960((int)p, (int)func_02157AF0, 0x193);
}







void func_02157D0C(int *p)
{
    if (*((u8 *)p + 0x675) == 0) {
        ((struct Obj04915 *)p)->f67C = p[4];
        ((struct Obj04915 *)p)->f680 = p[5];
        if (func_0203D3A8(func_020399A8(), (u16)((p[0] << 8) + 2), (u16)8, (u32)((u8 *)p + 0x67C)) == 0)
            return;
        func_02157960((int)p, (int)((void *)func_02157C48), 0x1A2);
        return;
    }
    func_02157960((int)p, (int)((void *)func_02157C48), 0x1A6);
}






void func_02157D68(int *p) { if (func_0203D1B4() > 1) { func_02039C68((struct Link *)func_020399A8(), 0x17, (u8)p[0]); func_02157960((int)p, (int)func_02157D0C, 0x1af); } }






void func_02157D98(int p)
{
    func_0203D0DC(0);
    func_02157960(p, (int)func_02157D68, 0x1B7);
}






void func_02157DB8(int p)
{
    if (func_0203CD98() == 1)
        func_02157960(p, (int)func_02157D98, 0x1BE);
}






void *func_02157DD8(u8 *p)
{
    void *q = func_02030734(((struct Obj18743 *)p)->f6, 0x684, 1, d_02172878, 0x1CD);
    func_02082D44(p, q, 0x7C);
    return q;
}






int func_02157E08(void *p)
{
    if (func_0203CD98() != 0)
        return 0;
    d_02172868[7] = ((struct Obj18744 *)p)->f0;
    func_0203CBAC((struct Req *)d_02172808, 0, (u32)p);
    return 1;
}






int func_02157E34(void *p)
{
    int r = func_02157E08(p);
    *((u8 *)p + 0x675) = 0;
    *((u8 *)p + 0x676) = 0;
    *((u8 *)p + 0x677) = 0;
    ((struct Obj07276 *)p)->f66C = 0;
    func_02157960((int)p, (int)((void *)func_02157DB8), 0x231);
    return r;
}





/*
 * extent: Accessor ends at 02157E78, followed by labelled callback function.
 */
unsigned char func_02157E6C(char *p)
{
    return ((struct Obj18745 *)p)->f674;
}





void func_02157E78(u8 *p)
{
    void (*callback)(u8 *) = *(void (**)(u8 *))(p + 0x678);
    if (callback != 0)
        callback(p);
}






int func_02157E8C(void *a0)
{

    a0 = (void *)func_020307B0(a0);
loc_02157E92:
a0 = 0;
    a0 = (void *)func_0203CEAC((int)a0);
loc_02157E98:
    return (int)a0;}






/*
 * Wave 76 lever: gender is a u8 local, loaded from GiftMon.gender and
 * remapped from 0xFF to 2. With the form extern parameter u8, this restores
 * both personality-call setup schedules: 19 differing bytes become EXACT.
 * Signed 64-bit PID and ID were flat19; union PID worsened to38. The u8
 * form extern alone stayed19. Old seed7201 budget400 was not repeated.
 * checks: 1 own callees and forwarding bodies re-read, six personality inputs; 2 021684E8/ov121 DEFAC inspected; 3 byte form flat19, byte gender EXACT; 4 existing width/const idioms inspected; 5 current neighbours and idioms inspected before filing.
 * Wave 75 fresh pass: unsigned-long species, enum flag argument, enum slot, u16 form argument, and nonconst GiftMon each19/1148 B; retain original const best. All54 relocations resolved. Old seed7201 budget400 consumed; never rerun.
 * Prior recorded evidence (retained):
 * func_02157E9C (ov010, Thumb, 1148 bytes), tree_ov010_2, 2026-09-28
 *
 * Best source: src/pending/ov010_func_02157E9C.c (DIFF, size right, 54 of 54
 * relocations resolved, 10 instructions out). The residue is the argument
 * setup of the first and third func_020186C8 calls:
 *
 *   image  (pidType 0): ldr r1,[sp,#0x20]; str r0,[sp]; movs r0,#0; lsls r1;
 *                       ldrb r2,[r4,#0x1c]; str r0,[sp,#0x28]; str r0,[sp,#4]
 *   this C (pidType 0): str r0,[sp]; movs r0,#0; ldr r1,[sp,#0x20];
 *                       str r0,[sp,#4]; str r0,[sp,#0x28]; lsls r1; ldrb r2
 *   image  (pidType 2): ldr r1; ldrb r2; str r0,[sp,#4]; lsls r1
 *   this C (pidType 2): ldr r1; str r0,[sp,#4]; lsls r1; ldrb r2
 *
 * Measured:
 * - 288-shape grid (species u32/int/u16 x species arg plain/(u16) x callee
 *   a1 u16/int/u32 x form arg plain/(int) x slot u32/int x gender u32/int x
 *   if-chain/switch on pidType): flat at 10 or 11, never lower.
 * - pid as two u32 locals (the ov121 func_021DEFAC spelling, hi written
 *   before the call in pidType 0 and after in 1 and 2): 431 at every one of
 *   the 46 declaration positions (level leaves its stack slot for r7).
 * - pid as u32[2]: 432. Half writes through ((u32 *)&pid)[k]: 52 (pid moves
 *   to sp+0x34).
 * - permuter seed 7201, budget 400, focus 0x17E: no gain.
 *
 * The same function exists in ov121 (src/pending/func_021DEFAC.c, DIFF); a
 * lever found for one should be tried on the other.
 *
 * 2026-09-28, tree_ov010_3: not re-drafted (the lane's time went to the
 * open roots); the residue above is unchanged at 10 instructions.
 *
 * Builds a gift Pokemon from a mystery-gift record. 1148/1148 bytes, every
 * relocation resolved, 10 instructions out in two argument-setup schedules
 * of the func_020186C8 calls (pid types 0 and 2). See
 * docs/notes/pkt_ov010_02157E9C.c.txt.
 */
void *func_02157E9C(const GiftMon *g, int heap, void *save)
{
    u16 moves[4];
    u8 iv[6];
    u32 month;
    u32 ability;
    u8 gender;
    u64 pid;
    u32 species;
    u32 otId;
    u64 id;
    u16 level;
    u32 slot;
    void *ret;
    u32 ivs;
    int i;
    u32 k;
    u16 mv;
    void *pp;
    void *name;
    u32 v;
    u8 day;
    u16 year;
    u32 loc;

    level = g->level;
    otId = g->otId;
    species = g->species;
    gender = g->gender;
    ability = g->ability;
    iv[0] = g->hp;
    iv[1] = g->atk;
    iv[2] = g->def;
    iv[3] = g->spa;
    iv[4] = g->spd;
    iv[5] = g->spe;
    moves[0] = g->moves[0];
    moves[1] = g->moves[1];
    moves[2] = g->moves[2];
    moves[3] = g->moves[3];

    if (g->fB3 != 1) {
        ret = 0;
        goto out;
    }
    if (species > 649) {
        ret = 0;
        goto out;
    }
    if (species == 0) {
        ret = 0;
        goto out;
    }
    if (level > 100) {
        ret = 0;
        goto out;
    }
    if (g->item > 626) {
        ret = 0;
        goto out;
    }

    if (level == 0)
        level = func_020056EC(100) + 1;
    if (g->otId == 0)
        otId = func_02008530((const struct Sub0200852CObj *)func_02012944(save));
    if (gender == 0xFF)
        gender = 2;
    for (i = 0; i < 6; i++) {
        if (iv[i] == 0xFF)
            iv[i] = func_020056EC(32);
    }

    id = otId;
    pp = func_020173F0(species, level, id, heap);
    ivs = (iv[0] & 0x1F) | ((iv[1] & 0x1F) << 5) | ((iv[2] & 0x1F) << 10)
        | ((iv[3] & 0x1F) << 15) | ((iv[4] & 0x1F) << 20) | ((iv[5] & 0x1F) << 25);

    if (ability == 4)
        ability = (u8)func_020056EC(3);
    switch (ability) {
    case 0:
        slot = 0;
        break;
    case 1:
        slot = 1;
        break;
    case 2:
        slot = 0;
        break;
    case 3:
        slot = 2;
        break;
    default:
        ret = 0;
        goto out;
    }

    if (g->pid != 0) {
        pid = g->pid;
    } else if (g->pidType == 0) {
        pid = func_020186C8(otId, (u16)species, (u8)g->form, gender, slot, 0);
    } else if (g->pidType == 1) {
        pid = func_020186C8(otId, (u16)species, (u8)g->form, gender, slot, 2);
    } else if (g->pidType == 2) {
        pid = func_020186C8(otId, (u16)species, (u8)g->form, gender, slot, 1);
    }

    func_02017588(pp, g->species, level, id, ivs, pid);
    func_02017E40(pp, 6, g->item);
    func_02017FA8(pp);
    for (i = 0; i < 4; i++) {
        mv = moves[i];
        if (mv != 0 && mv < 0x230) {
            if (func_0201808C(pp, mv) == 0xFFFF)
                func_020180F4(pp, mv);
        }
    }
    if (g->pid == 0 && ability == 2)
        func_02018A00(pp, species, g->form);
    func_02017E40(pp, 0x6F, g->form);
    if (g->ball != 0 && g->ball <= 0x19)
        func_02017E40(pp, 0x98, g->ball);
    else
        func_02017E40(pp, 0x98, 4);
    if (g->f3C != 0)
        func_02017E40(pp, 0x99, g->f3C);
    func_02017E40(pp, 0x13, g->contest[0]);
    func_02017E40(pp, 0x14, g->contest[1]);
    func_02017E40(pp, 0x15, g->contest[2]);
    func_02017E40(pp, 0x16, g->contest[3]);
    func_02017E40(pp, 0x17, g->contest[4]);
    func_02017E40(pp, 0x18, g->contest[4]);
    for (k = 0; k < 15; k++) {
        if (g->ribbons & (1 << k))
            func_02017E40(pp, d_02170068[k], 1);
    }
    if (g->f04 == 0)
        func_02017E40(pp, 0x77, d_0209DF08[0]);
    else
        func_02017E40(pp, 0x77, g->f04);
    if (g->lang == 0)
        func_02017E40(pp, 0xC, d_0209DF0C[0]);
    else
        func_02017E40(pp, 0xC, g->lang);
    if (g->nick[0] == 0) {
        func_020307B0(pp);
        ret = 0;
        goto out;
    }
    if (g->nick[0] != func_02045A98())
        func_02017E40(pp, 0x74, (u32)g->nick);
    v = g->nature;
    if (v == 0xFF)
        v = (u8)func_020056EC(25);
    func_02017E40(pp, 0x70, v);
    func_02017E40(pp, 0x95, g->eggLoc);
    func_02017E40(pp, 0x96, g->metLoc);
    if (g->otName[0] == 0) {
        func_020307B0(pp);
        ret = 0;
        goto out;
    }
    if (g->otName[0] == func_02045A98())
        func_02017E40(pp, 0x8E, (u32)func_020084F4(func_02012944(save)));
    else
        func_02017E40(pp, 0x8E, (u32)g->otName);
    if (g->otGender <= 2)
        func_02017E40(pp, 0x9A, g->otGender);
    else
        func_02017E40(pp, 0x9A, func_02008550((const struct Sub0200852CObj *)func_02012944(save)));
    if (g->isEgg) {
        func_02017E40(pp, 0x4C, 1);
        name = func_02045EC0(d_020A7370, 0x28A);
        func_02017E40(pp, 0x73, (u32)name);
        func_02045808(name);
        func_02017E40(pp, 9, 10);
    }
    year = g->date >> 16;
    month = (u8)(g->date >> 8);
    day = g->date;
    loc = g->isEgg ? g->eggLoc : g->metLoc;
    func_0202F2AC(func_020185F0(pp), loc, year - 2000, month, day);
    func_020185C4(pp);
    ret = 0;
    if (func_02017E1C(pp, 3, 0) != 0)
        func_020307B0(pp);
    else
        ret = pp;
out:
    return ret;
}






int func_02158318(int a0)
{
    int t4;
    int t5;
    void *p;

t5 = a0 + 0;
    a0 = func_02012138((const struct Ctx *)a0);
loc_02158320:
t4 = a0 + 0;
a0 = t5 + 0;
    p = func_020120F4((const struct Ctx *)a0);
loc_02158328:
    a0 = func_02012B70(p);
loc_0215832C:
    if (a0 != 1) goto loc_0215833E;
loc_02158330:
a0 = t4 + 0;
    a0 = func_0202648C((void *)a0);
loc_02158336:
    if (a0 == 0) goto loc_0215833E;
loc_0215833A:
a0 = 0;
    return a0;
loc_0215833E:
a0 = 1;
    return a0;}






int func_02158344(int a0)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_02026474((void *)a0);
loc_0215834C:
t4 = a0 + 0;
    a0 = func_0200FB24();
loc_02158352:
    if (a0 != 0) goto loc_0215836E;
loc_02158356:
a0 = t5 + 0;
    a0 = func_02026454((void *)a0);
loc_0215835C:
    if (a0 != 2) goto loc_0215836E;
loc_02158360:
a0 = t5 + 0;
    a0 = func_02026460((void *)a0);
loc_02158366:
    if (a0 == 1) goto loc_0215836E;
loc_0215836A:
    if (t4 != 0) goto loc_02158372;
loc_0215836E:
a0 = 0;
    return a0;
loc_02158372:
a0 = t4 + 0;
    return a0;}






int func_02158378(void *p)
{
    u8 *q = (u8 *)func_02158344((int)p);
    if (q == 0) {
        return func_02012B58((const struct BigObj *)func_02026478(p));
    }
    return q[0x911];
}






int func_0215839C(u8 *p, int m, int a2)
{
    Fl_0 *s = (Fl_0 *)(p + 0x93F);
    u8 t = s->f;
    if (m & t) {
        s->f ^= 1;
        return 1;
    }
    return 0;
}






/*
 * Dispatch on the record's key: an equal key goes to the
 * single-argument arm9 read, anything else to the pair form.
 */
int func_021583CC(void *a0, int a1)
{
    if (func_02012B58(a0) == a1)
        return (int)func_020127B8(a0);

    return (int)func_020127AC(a0, a1);
}






int func_021583EC(void *a0, int a1)
{
    if (func_02012B58(a0) == a1)
        return (int)func_02012944(a0);

    return (int)func_02012950(a0, a1);
}






/*
 * Address of the idx-th 0x28-byte record at +0x1AC.
 */
Rec28 *func_0215840C(RecHolder *h, int idx)
{
    return &h->recs[idx];
}






/*
 * Byte out of the arm9 reader, zero-extended.
 */
u8 func_0215841C(void *p)
{
    return (u8)(unsigned)func_02012B80(p);
}






/*
 * Unlabelled leaf (no lr save, so disasm.py prints it inside the extent of
 * func_0215841C); sole blocker of ov018 func_0217D1C0. Followed by another
 * unlabelled leaf at 0x02158434.
 */
u8 func_02158428(u8 *p)
{
    return p[0x90C];
}





/*
 * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing),
 * called from ov020 func_021870C4.
 */
void *func_02158434(char *p)
{
    return p + 0x35C;
}





/*
 * extent: Two zero alignment bytes at 0x02158466 precede 0x02158468.
 * lever: A named u8 id truncates the result in r0 before preparing r1.
 */
int func_0215843C(void *p)
{
    void *q = (void *)func_02026478(p);
    u8 id;
    if (func_02012B70(q) == 0)
        return 21;
    id = (int)func_02012B80(q);
    return func_0200855C((const struct Sub0200852CObj *)func_021583EC(q, id));
}






int func_02158468(int a0)
{
    int a1;
    int t4;
    int t5;

    a0 = func_02026478((void *)a0);
loc_0215846E:
t5 = a0 + 0;
    a0 = func_02012B70((const struct BigObj *)a0);
loc_02158474:
    if (a0 != 0) goto loc_02158480;
loc_02158478:
a0 = t5 + 0;
    a0 = func_02012984((const struct BigObj *)a0);
loc_0215847E:
    return a0;
loc_02158480:
a0 = t5 + 0;
    a0 = func_0215841C((void *)a0);
loc_02158486:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02012B58((const struct BigObj *)a0);
loc_0215848E:
    if (t4 != a0) goto loc_0215849A;
loc_02158492:
a0 = t5 + 0;
    a0 = func_02012984((const struct BigObj *)a0);
loc_02158498:
    return a0;
loc_0215849A:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02012B98((const struct BigObj *)a0, a1);
loc_021584A2:
    return a0;}






int func_021584A4(int unused, int a, int mode)
{
    u8 *q = (u8 *)func_02158344(unused);
    int n;
    int cur;
    if (q == 0)
        return 1;
    cur = ((Fh *)(q + 0x86))->f;
    if (mode == 2) {
        n = cur - 1;
        if (n < 0)
            n = q[0x901];
    } else {
        n = cur + 1;
        if (n >= q[0x901] + 1)
            n = 0;
    }
    if (n == func_02012B58((const struct BigObj *)a))
        return 1;
    return 0;
}







int func_021584F4(int a0, int a1)
{

    if (a0 == 0x15) goto loc_0215850A;
loc_021584F8:
    if (a0 == 0x14) goto loc_0215850A;
loc_021584FC:
a0 = 1;
a0 = a0 << 0x10;
    if ((a0 & a1) == 0) goto loc_02158508;
loc_02158504:
a0 = 0x14;
    return a0;
loc_02158508:
a0 = 0x15;
loc_0215850A:
    return a0;}





int func_0215850C(int a0, int a1)
{
    int t4;
    int t5;
    void *p;
    struct Rec44 *rec;

t5 = a1 + 0;
    a0 = func_02158344(a0);
loc_02158514:
a0 = t5 + 0;
    p = func_02012B38((const struct BigObj *)a0);
loc_0215851A:
    a0 = func_0201444C(p);
loc_0215851E:
    if (a0 == 1) goto loc_02158526;
loc_02158522:
a0 = 0;
    return a0;
loc_02158526:
a0 = t5 + 0;
    a0 = func_0215841C((void *)a0);
loc_0215852C:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02012B58((const struct BigObj *)a0);
loc_02158534:
    if (t4 != a0) goto loc_0215853C;
loc_02158538:
a0 = 0;
    return a0;
loc_0215853C:
a0 = t5 + 0;
a1 = t4 + 0;
    rec = func_02012950((struct Sub24 *)a0, a1);
loc_02158544:
    a0 = func_0200855C((const struct Sub0200852CObj *)rec);
loc_0215854A:
t4 = a0 + 0;
    a0 = func_02008530((const struct Sub0200852CObj *)rec);
loc_02158552:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_021584F4(a0, a1);
loc_0215855A:
    if (a0 == 0x14) goto loc_02158564;
loc_0215855E:
    if (a0 == 0x15) goto loc_02158568;
loc_02158562:
    goto loc_0215856C;
loc_02158564:
a0 = 1;
    return a0;
loc_02158568:
a0 = 2;
    return a0;
loc_0215856C:
a0 = 3;
    return a0;}




/*
 * lever: The ternary loop condition preserves the branch to the bottom test.
 */
int func_02158570(u16 value)
{
    unsigned int i;
    for (i = 0; (i < 61) ? 1 : 0; i++) {
        if (value == d_021700AC[i])
            return 1;
    }
    return 0;
}




int func_02158590(void *p)
{
    void *q = (void *)func_0201296C(p);
    unsigned int i;
    for (i = 0; i < 2; i++) {
        if (func_020142E8(q, d_021700A8[i]) == 0)
            return 0;
    }
    return 1;
}





int func_021585BC(int a0)
{
    int a1;

a1 = 0x25;
a1 = a1 << 6;
a1 = *(int *)((char *)a0 + a1);
a1 = (unsigned)a1 >> 0x1f;
    if (a1 == 0) goto loc_021585DA;
loc_021585C8:
a1 = 0x6b;
a1 = a1 << 2;
a0 = a0 + a1;
    a0 = func_02175B14(a0, a1);
loc_021585D2:
    if (a0 != 0) goto loc_021585DA;
loc_021585D6:
a0 = 1;
    return a0;
loc_021585DA:
a0 = 0;
    return a0;}




/*
 * Callee 02158344 consumes incoming r0; the flag extract reads bit 2.
 */
int func_021585E0(int p)
{
    u8 *q = (u8 *)func_02158344((int)((void *)p));
    if (q == 0)
        return 0;
    if (((Flag_021585E0 *)(q + 0x93F))->flag == 0) {
        if (func_02158630(p) == 3)
            return 2;
        return 1;
    }
    return 3;
}




/*
 * The callee reads its incoming r0; legacy void prototypes omit it.
 */
void func_02158614(void *p)
{
    u8 *q = (u8 *)func_02158344((int)p);
    if (q != 0)
        q[0x93F] |= 4;
}





int func_02158630(int a)
{
    int q = func_02158344(a);
    if (q == 0)
        return 0;
    if (func_02175B14(q + 0x1AC) == 1) {
        if (func_02176258(q) == 1)
            return 2;
        if (func_02158590((void *)func_02026478((void *)a)) == 0)
            return 1;
        return 3;
    }
    return 1;
}





int func_02158678(void *p)
{
    int n = 0;
    u8 i;
    u8 *q = (u8 *)func_02158344((int)p);
    if (q == 0)
        return n;
    if (func_02175B14(q + 0x1AC) == 0)
        return n;
    for (i = 0; i < 3; i++) {
        if (((Fl_1 *)(q + 0xA6 + i * 0x1C))->f == 1)
            n++;
    }
    if (n == 0)
        n = 1;
    return n;
}





int func_021586C8(int a, int b)
{
    char *q = (char *)func_02158344(a);
    int r = func_02026478((void *)a);
    if (q == 0 || func_02175B14(q + 0x1AC) == 0)
        return 0;
    func_02008500(func_02012950((struct Sub24 *)r, func_02176230(q, q + 0x1AC)), (void *)b);
    return 1;
}





/*
 * Three guards (state == 2, a non-null lookup, bit 6 of a far byte) then a
 * predicate whose one result is inverted.
 */
int func_0215870C(void *p, int b)
{
    u8 *q;

    if (func_02026454((void *)((int)p)) != 2)
        return 0;
    q = (u8 *)func_02026474((void *)((int)p));
    if (q == 0)
        return 0;
    if (((FlagsF8 *)(q + 0x8f8))->f == 0)
        return 0;
    if (func_0203CDBC() == 1)
        return 0;
    return 1;
}




void func_0215874C(void *p)
{
    u8 *q = (u8 *)func_02158344((int)p);
    if (q != 0)
        ((Flag_0215874C *)(q + 0x904))->flag = 0;
}





struct Desc *func_02158768(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int o4;
    struct Desc *r;
t5 = a1 + 0;
t4 = a2 + 0;
a1 = 0;
    o4 = a1;
a1 = a3 + 0;
a2 = t5 + 0;
a3 = t4 + 0;
    r = func_02158920(a0, a1, a2, a3, o4);
loc_0215877C:
    return r;
}




int func_02158780(void *p, u16 b, int c, int d, u16 e)
{
    struct Desc *h = func_02158920((int)func_020124E4(p), e, b, c, d);
    int *q = func_020124E8((void *)h);
    func_02012374(p, (struct Evt **)((void **)h));
    return *q;
}





int func_021587B0(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int t6;
    int t7;
    int o4;
    void *p;
    void *q;
    struct Desc *v0;
t7 = a0 + 0;
t5 = a1 + 0;
t4 = a2 + 0;
t6 = a3 + 0;
    p = func_020124E4((struct Obj *)a0);
loc_021587BE:
a1 = 0;
    o4 = a1;
a1 = t6 + 0;
a2 = t5 + 0;
a3 = t4 + 0;
    v0 = func_02158920((int)p, a1, a2, a3, o4);
loc_021587CC:
    q = func_020124E8((struct Obj *)v0);
loc_021587D2:
a0 = t7 + 0;
    a0 = func_0201235C(a0, v0);
loc_021587DC:
a0 = ((struct Obj17623 *)q)->f0;
    return a0;
}




/*
 * Extent ends in two alignment padding bytes.
 */
int func_021587E0(int a, int b) {
    void *p = (void *)func_021589DC(a);
    if (!p) return 0;
    if (func_02158894((int)p, b)) return 1;
    return 0;
}




/*
 * Allocates 0x18 bytes and initializes the leading heap halfword.
 */
void *func_02158804(u32 heap) {
    u16 *p = func_02030734(heap, 0x18, 1, d_02172888, 0xef);
    *p = heap;
    return p;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_020307B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02158824.c \
 *       --func func_02158824 --addr 0x02158824 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02158824(void *a0, unsigned a1, unsigned a2, unsigned a3)
{

    func_020307B0(a0);
}




int func_0215882C(int a0)
{
    int t4;
    int t5;
    int t6;
    int t7;

t5 = a0 + 0;
t4 = 0;
loc_02158832:
a0 = t4 << 2;
t7 = t5 + a0;
t6 = ((struct Obj12028 *)t7)->f4;
    if (t6 == 0) goto loc_02158856;
loc_0215883C:
a0 = t6 + 0;
    a0 = func_02011298((struct ScriptVm *)a0);
loc_02158842:
    if (a0 != 0) goto loc_02158856;
loc_02158846:
a0 = 0;
((struct Obj12028 *)t7)->f4 = a0;
a0 = ((struct Obj00105 *)t5)->f2;
a0 = a0 - 1;
((struct Obj00105 *)t5)->f2 = a0;
a0 = t6 + 0;
    a0 = func_02158CB4(a0);
loc_02158856:
t4 = t4 + 1;
    if (t4 < 3) goto loc_02158832;
loc_0215885C:
a0 = ((struct Obj00105 *)t5)->f2;
    if (a0 == 0) goto loc_02158866;
loc_02158862:
a0 = 1;
    return a0;
loc_02158866:
a0 = 0;
    return a0;}






int func_0215886C(int a0, int a1)
{
    int a2;
    int a3;
    int t4;

t4 = 0;
loc_02158870:
a2 = t4 << 2;
a3 = a0 + a2;
a2 = ((struct Obj12029 *)a3)->f4;
    if (a2 != 0) goto loc_02158888;
loc_0215887A:
((struct Obj12029 *)a3)->f4 = a1;
a1 = ((struct Obj09153 *)a0)->f2;
a1 = a1 + 1;
((struct Obj09153 *)a0)->f2 = a1;
a0 = t4 + 0;
    return a0;
loc_02158888:
t4 = t4 + 1;
    if (t4 < 3) goto loc_02158870;
loc_0215888E:
a0 = 3;
    return a0;}






int func_02158894(int a0, int a1)
{

a1 = a1 << 2;
a0 = a0 + a1;
a0 = ((struct Obj17624 *)a0)->f4;
    return a0;}



/*
 * extent: 8-byte tail stub; existing labelled func_021588A4 follows.
 */
void func_0215889C(void *p, u32 *out)
{
    func_0201235C(p, out);
}



/*
 * lever: Callback-field assignment before argument-field assignment hoists
 *        the callback pool load before both stores, preserving argument first.
 */
void func_021588A4(void *p, int a)
{
    void (*callback)(void *, u32 *) = func_0215889C;
    *(void (**)(void *, u32 *))((u32)p + 0x10) = callback;
    ((struct Obj12271 *)((u32)p))->f14 = a;
}






int func_021588B0(int a0, int a1, int a2)
{

a2 = a0 + 0;
a0 = a1 + 0;
a1 = *(int *)&((struct Obj00105 *)a2)->f14;
a2 = *(int *)&((struct Obj00105 *)a2)->f10;
    a0 = ((int (*)())a2)(a0, a1, a2);
loc_021588BC:
    return a0;}






int func_021588C0(int a0)
{

a0 = ((struct Obj17625 *)a0)->f10;
    if (a0 == 0) goto loc_021588CA;
loc_021588C6:
a0 = 1;
    return a0;
loc_021588CA:
a0 = 0;
    return a0;}
