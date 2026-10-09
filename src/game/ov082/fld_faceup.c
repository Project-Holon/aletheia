/*
 * file:     fld_faceup.c
 * unit:     yes
 * function: func_021F5260, func_021F5338, func_021F53B4, func_021F5550, func_021F5578, func_021F558C, func_021F55A0, func_021F5648, func_021F56C0, func_021F56D8, func_021F56E4, func_021F56FC, func_021F5708, func_021F5748, func_021F57D8, func_021F5840
 * address:  0x021F5260
 * region:   ov082
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
 *   func_02030734  0x02030734  arm
 *   func_02189A60  0x02189A60  thumb  ov021
 *   func_021F58C0  0x021F58C0  thumb  ov082
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02008374  0x02008374  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030DA8  0x02030DA8  arm
 *   func_020056A0  0x020056A0  thumb
 *   d_021F5920     0x021F5920  data  a1
 *   func_020124E4  0x020124E4  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190378  0x02190378  thumb  ov021
 *   func_021904D0  0x021904D0  thumb  ov021
 *   func_020403F4  0x020403F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02048F60  0x02048F60  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_02062B30  0x02062B30  arm
 *   func_02062A98  0x02062A98  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_020409E0  0x020409E0  arm
 *   func_02040E78  0x02040E78  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   d_021F58F4     0x021F58F4  data  a4
 *   func_02030EAC  0x02030EAC  arm
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_020414AC  0x020414AC  arm
 *   func_021BC5D4  0x021BC5D4  thumb  ov021
 *   func_020416D4 0x020416D4 arm
 *   func_02043658  0x02043658  arm
 *   func_02043534  0x02043534  arm
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_021917C0  0x021917C0  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   d_021F58D0     0x021F58D0  data  a4
 *   d_021F58E0     0x021F58E0  data  a4
 */
#include "../../matched/include/Obj02424.h"
#include "../../matched/include/Obj06200.h"
#include "../../matched/include/Obj09918.h"
#include "../../matched/include/Obj13225.h"
#include "../../matched/include/Obj05164.h"
#include "../../matched/include/Obj02425.h"

#define reg_G2_BG3CNT  (*(volatile u16 *)0x0400000E)
#define reg_G2_BLDCNT  (*(volatile u16 *)0x04000050)
struct Big;
struct Ctx;
struct Desc;
struct Sub02008700Obj;
struct Obj;
struct BgTemplate;
struct NitroFileHeader;
struct Node;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef short s16;

typedef signed int     s32;

typedef struct {
    u32 w[8];
} BgTemplate;

typedef struct {
    u8 _0[0x10];
    u32 size;
    void *data;
} Chr;

typedef struct {
    u8 _0[8];
    u32 size;
    u8 data[4];
} Scr;

typedef struct {
    u8 _0[0xc];
    void *data;
} Plt;

typedef enum { GX_BG_SCRSIZE_TEXT_256x256 = 0 } GXBGScrSizeText;

typedef enum { GX_BG_COLORMODE_16 = 0, GX_BG_COLORMODE_256 = 1 } GXBGColorMode;

typedef enum { GX_BG_SCRBASE_0x0000 = 0, GX_BG_SCRBASE_0x1000 = 2 } GXBGScrBase;

typedef enum { GX_BG_CHARBASE_0x00000 = 0, GX_BG_CHARBASE_0x04000 = 1 } GXBGCharBase;

typedef struct {
    char pad[8];
    u16 b0 : 2;
    u16 a : 4;
    u16 b6 : 1;
    u16 c : 1;
    u16 b : 5;
    u16 b13 : 1;
    u16 d : 2;
} Cfg;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    char fC[0xC];
    char f18[0xC];
} Sub;

typedef struct { u16 value, pad; } Row;

typedef struct { int done, busy; u8 delay, reload; u16 index; u16 tiles[2][6]; } State;

extern void *func_0201210C(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 **func_02189A60(void *p);
extern void func_021F58C0(char *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern unsigned int func_02008374(int a0);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern u32 func_02188D30(u8 *p);
extern void *func_02030DA8(void *a0, void *callback, void *ctx, int a3);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void *func_020124E4(struct Obj *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern u32 func_02188C54(u8 *p);
extern int func_02190378(u8 *a);
extern void func_021904D0(u8 *p);
extern void func_020403F4(u32 i);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern int func_02062B30(void *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_020409E0(u32 index, const void *src, u32 mode, u32 offset);
extern void func_02040E78(u32 index, void *src, u32 size, u32 offset);
extern u32 func_020307B0(void *p);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02030EAC(struct Node *n);
extern u32 func_02188D20(u8 *p);
extern void func_020414AC(int a);
extern void func_021BC5D4(u8 *p);
extern u8 func_020416D4(u32 layer);
u32 func_02043658(void);
void func_02043534(u32 planes);
extern int  func_02159190(int a);
extern int  func_0215A61C(int a);
extern int func_021917C0(int *p);
extern u32 func_020056EC(u32 range);
void *func_021F5260(int a0, int a1, int a2, void *a3, int a4);
int func_021F5338(void *task, int *st);
void func_021F53B4(u8 *w, int p);
void *func_021F5550(void *p);
void func_021F5578(u8 *p);
void func_021F558C(u8 *p);
int func_021F55A0(void *a0, int *st);
void func_021F5648(int a0, Cfg *p);
void func_021F56C0(u8 *p);
void func_021F56D8(int *p);
void func_021F56E4(u8 *p);
void func_021F56FC(int *p);
int func_021F5708(char *p);
void func_021F5748(int a0, char *p);
void func_021F57D8(int a0, char *p);
void func_021F5840(Row *a, unsigned b, unsigned c, unsigned d, unsigned long e, State *f);
extern const char d_021F5920[];
extern const BgTemplate d_021F58F4;
extern char d_021F58D0[];
extern char d_021F58E0[];





void *func_021F5260(int a0, int a1, int a2, void *a3, int a4)
{
    u8 *w;
    void *obj;
    u32 mode;
    void *task;

    obj = func_0201210C(a3);
    w = func_02030734(0x50, 0x78, 1, d_021F5920, 0xa2);
    if (*func_02189A60(obj) != 0)
        return 0;
    *func_02189A60(obj) = w;
    ((struct Obj02424 *)w)->fC = a0;
    ((struct Obj02424 *)w)->f10 = a4;
    ((struct Obj02424 *)w)->f70 = a2;
    func_021F58C0((char *)(w + 0x28));
    func_021F58C0((char *)(w + 0x4c));
    mode = func_02008374((int)func_0200873C(func_02012EBC(func_020120F4(a3))));
    if (mode == 0)
        w[0x55] = 3;
    else if (mode == 1)
        w[0x55] = 2;
    else
        w[0x55] = 1;
    w[0x31] = 2;
    task = func_020122C0(a3, 0, (void *)func_021F5338, 0);
    ((struct Obj02424 *)w)->f14 = func_02030DA8((void *)func_02188D30(obj), (void *)func_021F5748, w, 0);
    ((struct Obj02424 *)w)->f18 = func_020056A0((void *)func_021F57D8, w, 1);
    ((struct Obj02424 *)w)->f1C = 0;
    ((struct Obj02424 *)w)->f74 = 1;
    return task;
}





int func_021F5338(void *task, int *st)
{
    void *p;
    u8 *w;

    p = func_0201210C(func_020124E4(task));
    w = *(u8 **)func_02189A60(p);
    switch (*st) {
    case 0:
        func_0204E720(1, 0, 0x10, 0);
        (*st)++;
        break;
    case 1:
        if (func_0204E804() == 0) {
            func_021F53B4(w, (int)p);
            func_0204E720(1, 0x10, 0, 0);
            (*st)++;
        }
        break;
    case 2:
        if (func_0204E804() == 0) {
            *(s16 *)&((struct Obj06200 *)w)->f24 = 0;
            (*st)++;
        }
        break;
    case 3:
        if (func_021F5708((char *)w) != 0)
            return 1;
        break;
    }
    return 0;
}





static inline void G2_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode,
                                        GXBGScrBase screenBase, GXBGCharBase charBase)
{
    reg_G2_BG3CNT = (u16)((reg_G2_BG3CNT & 0x43) | (screenSize << 14) |
                          (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}





void func_021F53B4(u8 *w, int p)
{
    BgTemplate tbl;
    Chr *chr1;
    Scr *scr1;
    Plt *plt;
    Chr *chr2;
    Scr *scr2;
    void *f;
    int obj;
    int a;
    int b;
    int c;

    func_021F56C0(w);
    func_021F56D8((int *)w);
    ((struct Obj09918 *)w)->f8 = reg_G2_BG3CNT;
    G2_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256,
                         GX_BG_SCRBASE_0x1000, GX_BG_CHARBASE_0x04000);
    func_0207D63C(0x04000050, 8, 4, 0, 16);
    obj = func_02188C54((u8 *)p);
    if (func_02190378((u8 *)obj) != 0)
        func_021904D0((u8 *)obj);
    else
        func_020403F4(2);
    tbl = d_021F58F4;
    func_0203FCA0(2, (const struct BgTemplate *)(&tbl), 0);
    if (((struct Obj09918 *)w)->fC == 0) {
        a = 4;
        b = 8;
        c = 0;
    } else if (((struct Obj09918 *)w)->fC == 1) {
        a = 5;
        b = 9;
        c = 1;
    } else {
        a = 6;
        b = 10;
        c = 2;
    }
    f = func_02048F60(0xbb, a, 0x8015);
    func_02062A4C(f, (void **)(&chr1));
    func_02040B1C(2, chr1->data, chr1->size, 0);
    func_020307B0(f);
    f = func_02048F60(0xbb, b, 0x8015);
    func_02062B30(f, (void **)(&scr1));
    func_020409E0(2, scr1->data, scr1->size, 0);
    func_020307B0(f);
    f = func_02048F60(0xbb, c, 0x8015);
    func_02062A98(f, (void **)(&plt));
    func_02040E78(2, plt->data, 0x140, 0);
    func_020307B0(f);
    f = func_02048F60(0xbb, 7, 0x8015);
    func_02062A4C(f, (void **)(&chr2));
    func_02040B1C(3, chr2->data, chr2->size, 0);
    func_020307B0(f);
    f = func_02048F60(0xbb, 11, 0x8015);
    func_02062B30(f, (void **)(&scr2));
    func_020409E0(3, scr2->data, scr2->size, 0);
    func_020307B0(f);
    func_0204047C(0, 3);
    func_0204047C(1, 0);
    func_0204047C(2, 2);
    func_0204047C(3, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
}




void *func_021F5550(void *p) { u8 *obj = func_0201210C(p); switch ((unsigned int)*(void **)func_02189A60(obj)) { case 0: return 0; default: return func_020122C0(p,0,(void *)func_021F55A0,0); } }




void func_021F5578(u8 *p) { void *w = *(void * *)func_02189A60(p); func_021F5648((int)p, (Cfg *)w); }




void func_021F558C(u8 *p) { u8 *w = *(void * *)func_02189A60(p); ((struct Obj13225 *)w)->f1C=0; ((struct Obj13225 *)w)->f74=1; }



int func_021F55A0(void *a0, int *st)
{
    void *obj;
    char *w;
    int t;

    obj = func_0201210C(func_020124E4(a0));
    w = *(char **)(u8 *)func_02189A60(obj);
    switch (*st) {
    case 0:
        if (((struct Obj05164 *)w)->f70 != 0)
            func_0204E720(3, 0, 0x10, -8);
        else
            func_0204E720(1, 0, 0x10, 0);
        (*st)++;
        break;
    case 1:
        if (func_0204E804() != 0)
            break;
        func_02030EAC((struct Node *)(((struct Obj05164 *)w)->f14));
        (*st)++;
        break;
    case 2:
        if (((struct Obj05164 *)w)->f2C != 0)
            break;
        if (((struct Obj05164 *)w)->f50 != 0)
            break;
        func_02030EAC((struct Node *)(((struct Obj05164 *)w)->f18));
        t = ((struct Obj05164 *)w)->f70;
        func_021F5648((int)obj, (Cfg *)w);
        if (t != 0)
            return 1;
        func_0204E720(1, 0x10, 0, 0);
        (*st)++;
        break;
    case 3:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}





/*
 * volatile: BG3CNT 0x0400000E read-modify-written by the SDK inline G2_SetBG3ControlText; BLDCNT 0x04000050 store
 */
void func_021F5648(int a0, Cfg *p)
{
    int t = func_02188D20((u8 *)a0);

    func_020414AC(2);
    G2_SetBG3ControlText(p->d, p->c, p->b, p->a);
    func_021BC5D4((u8 *)t);
    func_021904D0((u8 *)func_02188C54((u8 *)a0));
    reg_G2_BLDCNT = 0;
    func_021F56E4((u8 *)p);
    func_021F56FC((int *)p);
    func_020307B0(p);
    *func_02189A60((void *)a0) = 0;
}





void func_021F56C0(u8 *p) { int i; for(i=0;i<4;i++) p[i]=func_020416D4((u8)i); }






void func_021F56D8(int *p)
{
    p[1] = func_02043658();
}





void func_021F56E4(u8 *p) { int i; for(i=0;i<4;i++) func_0204047C((u8)i,p[i]); }






void func_021F56FC(int *p)
{
    func_02043534(p[1]);
}





int func_021F5708(char *p)
{
    int q;

    ((struct Obj06200 *)p)->f24 = ((struct Obj06200 *)p)->f24 + 1;
    q = (((struct Obj06200 *)p)->f24 << 4) / 30;
    func_0207D63C(0x04000050, 8, 4, q, 16 - q);
    if (((struct Obj06200 *)p)->f24 >= 30)
        return 1;
    return 0;
}





void func_021F5748(int a0, char *p)
{
    int t;
    int r;

    if (((struct Obj02425 *)p)->f1C == 0 && func_02159190(3) != 0) {
        t = func_0215A61C(((struct Obj02425 *)p)->f10);
        if (t != 0) {
            r = func_021917C0((int *)t);
            if (r == 0) {
                ((struct Obj02425 *)p)->f4C = 0;
                ((struct Obj02425 *)p)->f74 = 0;
            } else if (r == 2 && ((struct Obj02425 *)p)->f74 == 0) {
                ((struct Obj02425 *)p)->f1C = 1;
            }
        }
    }
    func_021F5840((Row *)d_021F58D0, 4, 0x184, 8, 4, (State *)(p + 0x4C));
    if (((struct Obj02425 *)p)->f26 == 0) {
        ((struct Obj02425 *)p)->f28 = 0;
        ((struct Obj02425 *)p)->f26 = func_020056EC(0x14) + 0x50;
    } else {
        ((struct Obj02425 *)p)->f26 = ((struct Obj02425 *)p)->f26 - 1;
    }
    func_021F5840((Row *)d_021F58E0, 5, 0x160, 0xC, 6, (State *)(p + 0x28));
}




void func_021F57D8(int a0, char *p)
{
    Sub *q = (Sub *)(p + 0x28);
    Sub *r;

    if (q->f4 != 0) {
        func_020409E0(3, q->fC, 0xC, 0x10D);
        func_020409E0(3, q->f18, 0xC, 0x12D);
        q->f4 = 0;
    }
    r = (Sub *)(p + 0x4C);
    if (r->f4 != 0) {
        func_020409E0(3, r->fC, 8, 0x16E);
        func_020409E0(3, r->f18, 8, 0x18E);
        r->f4 = 0;
    }
}




/*
 * lever: unsigned long fifth argument restores parameter homes; nested zero-delay guard and i*e operand order fix the multiply copy. Extent ends with two alignment bytes.
 */
void func_021F5840(Row *a, unsigned b, unsigned c, unsigned d, unsigned long e, State *f)
{
    int i;
    unsigned j;
    unsigned base;

    if (f->busy != 0)
        return;
    if (f->delay == 0) {
        if (f->index == 0 && f->done != 0)
            return;
        f->busy = 1;
        base = c + d * a[f->index].value;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < e; j++) {
                f->tiles[i][j] = (u16)(base + i * e + j);
            }
        }
        f->delay = f->reload;
        f->index++;
        if (f->index >= b) {
            f->index = 0;
            f->done = 1;
        }
    } else {
        f->delay--;
    }
}
