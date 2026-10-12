/*
 * file:     unit_021BA81C.c
 * unit:     yes
 * function: func_021BA81C, func_021BA828, func_021BA858, func_021BA874, func_021BA8BC, func_021BA8D4, func_021BA8EC, func_021BA928, func_021BA978, func_021BAAB8, func_021BAADC, func_021BAB04, func_021BABDC, func_021BAC24, func_021BAD50, func_021BAD74, func_021BAEDC, func_021BB050, func_021BB0B4, func_021BB1A8, func_021BB224, func_021BB2B0, func_021BB2F0, func_021BB374, func_021BB42C, func_021BB460, func_021BB4D0, func_021BB4EC, func_021BB528, func_021BB918
 * address:  0x021BA81C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_021C39E0  0x021C39E0  data  a4
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201FDA0 0x0201FDA0 thumb
 *   data_021C371A 0x021C371A data a2
 *   func_0201FEBC 0x0201FEBC thumb
 *   func_02009864  0x02009864  thumb
 *   func_020099E4  0x020099E4  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   sub_020452E8  0x020452E8  arm
 *   func_0202F038  0x0202F038  thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020286C4  0x020286C4  thumb
 *   func_02028484  0x02028484  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02028470  0x02028470  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02049B40 0x02049B40 arm
 *   func_020456F8 0x020456F8 arm
 *   func_02020D0C  0x02020D0C  thumb
 *   func_021C27E0  0x021C27E0  thumb  ov099
 *   func_02020268  0x02020268  thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   data_021C3B00  0x021C3B00  data
 *   data_021C3A50  0x021C3A50  data
 *   d_021C37A0 0x021C37A0 data a4
 *   d_021C3730 0x021C3730 data a4
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_02008730 0x02008730 thumb
 *   func_02008510 0x02008510 thumb
 *   func_02008550 0x02008550 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045808 0x02045808 arm
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021BE4BC 0x021BE4BC thumb ov099
 *   func_021BE3CC 0x021BE3CC thumb ov099
 *   func_020409B4 0x020409B4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_0201FEF4 0x0201FEF4 thumb
 *   sub_020457B0  0x020457B0  arm
 *   unit_0201C440  0x0201C440  thumb
 *   sub_0203101C  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02043598  0x02043598  arm
 *   func_02040AF0  0x02040AF0  arm
 *   func_020414AC  0x020414AC  arm
 *   d_021C37D4     0x021C37D4  data   ov099  a2
 *   func_02025C88  0x02025C88  thumb
 *   func_0202DA04  0x0202DA04  thumb
 *   func_0202DA48  0x0202DA48  thumb
 *   func_0202DA18  0x0202DA18  thumb
 *   func_0202DA6C  0x0202DA6C  thumb
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   sub_0204B3B4  0x0204B3B4  arm
 *   sub_0204A8D4  0x0204A8D4  arm
 *   sub_0204ADA4  0x0204ADA4  arm
 *   sub_0204AFD8  0x0204AFD8  arm
 *   d_021C388C     0x021C388C  data   ov099  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B62E0  0x021B62E0  thumb  ov067
 *   func_021B6578  0x021B6578  thumb  ov067
 *   func_021B639C  0x021B639C  thumb  ov067
 *   func_020490F4  0x020490F4  arm
 *   func_02049990  0x02049990  arm
 *   func_021C2370 0x021C2370 thumb ov099
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_021C285C 0x021C285C thumb ov099
 *   d_021C398C     0x021C398C  data   ov099
 */
#include "work_types.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj13684.h"
#include "../../matched/include/Obj22019.h"
#include "../../matched/include/Obj00976.h"
#include "../../matched/include/Obj01244.h"
#include "../../matched/include/Obj22020.h"

#define P(k) (*(void **)((u8 *)p+(k)))
#define PTR(off) (*(void **)(p+(off)))
struct WinDat;
struct BmpMenu;
struct Sub020097BCObj;
struct WordSet;
struct Descriptor;
struct PrintSys;
struct Rec3;
struct Ctx;
struct Blk;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Obj;
struct Slot;
struct Src;
struct W_021BA81C;
struct S;
struct Save;
struct Friends;
struct S_021BAEDC;
struct U16Vec;
struct Sub0200852CObj;
struct Tcbl;
struct S02031140;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BA81C;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned int u32_021BA828;

typedef unsigned int u32_021BA858;

typedef struct {
    int pad00;
    void *f4;               /* 0x04 */
    char pad08[0xd4];
    int fdc;                /* 0xdc */
    char pade0[0x10];
    int ff0;                /* 0xf0 */
} Work_021BA81C;

typedef unsigned int   u32_021BA874;

typedef unsigned long  u32_021BA8BC;

typedef struct {
    char pad[0x100];
    void *f100;
} S;

typedef unsigned int u32_021BA8EC;

typedef unsigned long  u32_021BA928;

typedef signed int     s32_021BA928;

typedef struct {
    char pad00[0x190];
    int f190;
    char pad194[0x28];
    void *f1bc;
    char pad1c0[0x26c - 0x1c0];
    char f26c[0x744];
    void *f9b0;
} W_021BA81C;

typedef unsigned int u32_021BA978;

typedef unsigned long  u32_021BAAB8;

typedef signed long    s32_021BAAB8;

typedef unsigned int u32_021BAB04;

typedef unsigned long  u32_021BABDC;

typedef struct { u32_021BA81C a, b; } Pair_021BA81C;

typedef struct { u32_021BA81C w[13]; } Desc_021BA81C;

typedef unsigned long  u32_021BAD50;

typedef unsigned int u32;

typedef struct { u32 a, b; } Pair_021BAD74;

typedef struct {
    u32 w0, w4, w8, wc;
    u16 count, rows;
    u32 w14, w18, w1c, w20, w24, w28, w2c, w30;
} Desc_021BAD74;

typedef unsigned int u32_021BAEDC;

typedef unsigned long  u32_021BB050;

typedef struct {
    char pad00[0xe0];
    u32_021BB050 fe0;
    char pade4[4];
    u32_021BB050 fe8;
    char padec[0xc];
    u32_021BB050 ff8;
    char padfc[0x9c];
    void *f198;
} W_021BAEDC;

typedef unsigned int u32_021BB0B4;

typedef unsigned long  u32_021BB1A8;

typedef struct {
    char pad[0xF0];
    void *f0F0;
    void *f0F4;
    void *f0F8;
    void *f0FC;
    char pad2[0xB4];
    void *f1B4;
    void *f1B8;
    void *f1BC;
    void *f1C0;
} S_021BAEDC;

typedef unsigned int   u32_021BB2B0;

typedef struct {
    u16 v[4];
} T4;

typedef signed int     s32_021BAEDC;

typedef unsigned long  u32_021BB42C;

typedef struct {
    char pad[0x180];
    void *f180;
    void *f184;
    void *f188;
    void *f18C;
} S_021BB42C;

typedef unsigned int u32_021BB460;

typedef struct {
    int v[8];
} T8;

typedef struct {
    void *f0;
    u32_021BB460 f4;
    int f8;
    u32_021BB460 fC;
    u32_021BB460 f10;
    u32_021BB460 f14;
    int f18;
    int f1c;
} A;

typedef unsigned long  u32_021BB4D0;

typedef signed long    s32_021BB4D0;

typedef struct {
    char pad[0x9a8];
    int f9a8;               /* 0x9a8 */
} Work_021BAEDC;

typedef unsigned int   u32_021BB4EC;

typedef unsigned int   u32_021BB528;

typedef struct {
    int v[16];
} Tbl;

typedef unsigned int   u32_021BB918;

extern void func_0201DD68(void);
extern struct BmpMenu *func_0201FDA0(const struct WinDat *, u16, u8, u8, u16);
extern u32_021BA858 func_0201FEBC(u8 *);
extern u32_021BA874 func_02009864(const struct Sub020097BCObj *obj, u32_021BA874 i, u32_021BA874 field);
extern void func_020099E4(struct Sub020097BCObj *obj, int i, void *dest);
extern void func_0201EE0C(struct WordSet *p, u32_021BA874 i, const void *src, u32_021BA874 n, u32_021BA874 f, u32_021BA874 c);
extern void func_0201F7A8(void *desc, u32_021BA8BC kind);
extern u32_021BA8BC sub_020452E8(struct Descriptor *d);
extern void func_0202F038(u8 *p);
extern u32_021BA8EC func_0201C6B4(const struct PrintSys *);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201CE48(struct Rec3 *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern s32_021BA928 func_02028484(struct Blk *blk, void *h);
extern signed char func_02012FFC(void);
extern u32_021BA978 func_020450F0(u32_021BA978 layer, u32_021BA978 a, u32_021BA978 b, u32_021BA978 tiles, u8 c, u8 d, u8 slot);
extern void func_02045CAC(struct MsgBank *bank, u32_021BA978 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern u32_021BA978 func_0201CCE4(u32_021BA978 a, u32_021BA978 b, u32_021BA978 c, u32_021BA978 d, u32_021BA978 e, u32_021BA978 f, u32_021BA978 g, u32_021BA978 h, u32_021BA978 i, u32_021BA978 j);
extern void func_02028470(u8 *p, u32_021BA978 v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32_021BA978 a);
extern void func_02049B40(u32_021BAB04,u32_021BAB04,u32_021BAB04,u32_021BAB04,u32_021BAB04,u16);
extern void func_020456F8(struct Descriptor *);
extern u32_021BABDC func_02020D0C(u8 *p);
extern int func_021C27E0(void *a);
extern void func_02020268(struct Obj *obj, u8 a, u8 b, u8 c);
extern struct Slot *func_0201F81C(u32_021BA81C, u32_021BA81C);
extern void func_0201F878(struct Slot *, u32_021BA81C, u32_021BA81C, u32_021BA81C, u32_021BA81C);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32_021BA81C heap);
extern u32_021BA81C func_0201C4E4(struct PrintSys *);
extern void func_02020CF8(struct Obj *p, int heap);
extern u8 func_021B97F4(struct W_021BA81C *);
extern int func_021C23B8(int i);
extern u32 func_021BDD48(int, struct S *);
extern struct Sub0200852CObj *func_02008730(void *sys);
extern void *func_02008510(void *a, int tag);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_0201DD78(u32_021BAEDC, u32_021BAEDC, u32_021BAEDC);
extern void func_02045808(struct U16Vec *);
extern u8 func_021BDD54(int, struct S_021BAEDC *);
extern int func_02156A3C(void);
extern void func_021BE4BC(char *, int, int, int, int, unsigned int, int);
extern void func_021BE3CC(char *p, int a, u8 b, u8 c, u32_021BAEDC d, int e);
extern void func_020409B4(u32_021BAEDC);
extern u32_021BB0B4 func_020452E8(struct Descriptor *d);
extern void func_0202020C(struct Obj *, u16 *, u16 *);
extern u32_021BB0B4 func_0201F868(void *p);
extern void func_0201FEF4(u8 *);
extern struct U16Vec *sub_020457B0(u32_021BB1A8 capacity, u32_021BB1A8 heapId);
extern void *unit_0201C440(int tag);
extern struct Tcbl *sub_0203101C(u16 heap, u16 tag, u32_021BB1A8 count, u32_021BB1A8 workSize);
extern void *func_02028590(int a, int b, int c, int d);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02043598(u32_021BB2B0 mask, u32_021BB2B0 enable);
extern void func_02040AF0(u32 index, const void *src, u32 mode, u32 offset);
extern void func_020414AC(int a);
extern u32 func_02025C88(u32 x);
extern int func_0202DA04(int a0);
extern void *func_0202DA48(void *a, int b, int c, u16 d);
extern s32_021BAEDC func_0202DA18(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int func_0202DA6C(int a0, int a1, int a2, unsigned short a3);
extern void func_02049238(void *o);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void sub_0204B3B4(struct Obj *p);
extern void sub_0204A8D4(u32_021BB42C i);
extern void sub_0204ADA4(u32_021BB42C i);
extern void sub_0204AFD8(u32_021BB42C i);
extern void func_02082BCC(void *p, u32_021BB460 v, u32_021BB460 n);
extern void *func_021B62E0(A *a, int heap);
extern void func_021B6578(unsigned char *p, unsigned int id, int v);
extern void func_021B639C(u8 *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32_021BB4EC func_02049990(void *a0, u32_021BB4EC a1, u32_021BB4EC a2, u32_021BB4EC a3, u32_021BB4EC a4, u32_021BB4EC a5, u32_021BB4EC a6, u16 a7);
extern void func_021C2370(char *,int);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0201EFA4(struct WordSet *p, u32_021BB528 i, u32_021BB528 a, u32_021BB528 b, u32_021BB528 c, u32_021BB528 d);
extern int func_021C285C(void *);
u32_021BA81C func_021BA81C(int i);
void func_021BA828(char *p);
u32_021BA858 func_021BA858(char *p);
void func_021BA874(Work_021BA81C *w, int id);
int func_021BA8BC(void *p);
void func_021BA8D4(S *s);
void func_021BA8EC(char *p);
int func_021BA928(W_021BA81C *w);
void func_021BA978(char *p, int a1, int a2, int a3);
void func_021BAAB8(char *p, int a, int b);
void func_021BAADC(char *p, int a, int b);
void func_021BAB04(void *p, int message);
void func_021BABDC(void *obj, int k);
void func_021BAC24(char *p, Desc_021BA81C *out, Pair_021BA81C *items, int count, int kind, u32_021BA81C width);
void func_021BAD50(int a);
void func_021BAD74(char *p);
void func_021BAEDC(char *p);
void func_021BB050(W_021BAEDC *w);
void func_021BB0B4(char *p);
void func_021BB1A8(char *s);
void func_021BB224(char *p);
void func_021BB2B0(char *p, int v);
void func_021BB2F0(char *p, int v);
void func_021BB374(char *p, int a, int b);
void func_021BB42C(S_021BB42C *s);
void func_021BB460(char *p, int x);
void func_021BB4D0(char *p);
void func_021BB4EC(Work_021BAEDC *w);
void func_021BB528(char *p,int v);
int func_021BB918(void *w, unsigned int idx, int *unused);
extern u32_021BA81C data_021C39E0[];
extern const struct WinDat data_021C371A;
extern u8 data_021C3B00[];
extern Desc_021BAD74 d_021C37A0;
extern const Pair_021BAD74 d_021C3730[];
extern const T4 d_021C37D4;
extern const T8 d_021C388C;
extern const Tbl d_021C398C;











u32_021BA81C func_021BA81C(int i)
{
    return data_021C39E0[i];
}










void func_021BA828(char *p)
{
    func_0201DD68();
    ((Ov099Work *)p)->f108 = func_0201FDA0(&data_021C371A, ((Ov099Work *)p)->f1334, 14, 0, 0x21);
}










u32_021BA858 func_021BA858(char *p)
{
    u32_021BA858 r = func_0201FEBC((u8 *)((Ov099Work *)p)->f108);
    if (r != 0xFFFFFFFF)
        ((Ov099Work *)p)->f108 = 0;
    return r;
}











void func_021BA874(Work_021BA81C *w, int id)
{
    int r;

    if (id != -1) {
        r = func_02009864(w->f4, id, 9);
        func_020099E4(w->f4, id, (void *)w->ff0);
        func_0201EE0C((struct WordSet *)w->fdc, 0, (const void *)w->ff0, r, 1, 2);
    }
}











int func_021BA8BC(void *p)
{
    if (p != 0) {
        func_0201F7A8(p, 0);
        sub_020452E8(p);
    }

    return 0;
}









void func_021BA8D4(S *s)
{
    if (s->f100 != 0) {
        func_0202F038(s->f100);
        s->f100 = 0;
    }
}







void func_021BA8EC(char *p)
{
    func_021BA8D4((S *)p);
    if (func_0201C6B4(*(struct PrintSys * *)&((struct Obj00008 *)p)->f1B8) == 0)
        func_0201C6EC(*(struct PrintSys * *)&((struct Obj00008 *)p)->f1B8);
    if (((struct Obj00008 *)p)->f1BC != 0) {
        func_0201CE48(((struct Obj00008 *)p)->f1BC);
        *(int *)&((struct Obj00008 *)p)->f1BC = 0;
    }
    *(int *)&((struct Obj00008 *)p)->f190 = func_021BA8BC(((struct Obj00008 *)p)->f190);
}








int func_021BA928(W_021BA81C *w)
{
    int r = 1;
    if (w->f1bc != 0) {
        if (w->f190 != 0) {
            func_020286C4(w->f9b0, w->f1bc, (void *)w->f190);
        }
        r = func_02028484((struct Blk *)w->f26c, w->f1bc);
        if (r != 0 && w->f1bc != 0) {
            func_0201CE48(w->f1bc);
            w->f1bc = 0;
        }
    }
    return r;
}








void func_021BA978(char *p, int a1, int a2, int a3)
{
    int k, e;
    func_02012FFC();
    func_021BA8D4((S *)p);
    *(u32_021BA978 *)(p + 0x190) = (u32_021BA978)func_021BA8BC((void *)(*(u32_021BA978 *)(p + 0x190)));
    if ((int)func_0201C6B4((const struct PrintSys *)(*(u32_021BA978 *)(p + 0x1B8))) == 0)
        func_0201C6EC((struct PrintSys *)(*(u32_021BA978 *)(p + 0x1B8)));
    if (*(u32_021BA978 *)(p + 0x1BC) != 0) {
        func_0201CE48((struct Rec3 *)(*(u32_021BA978 *)(p + 0x1BC)));
        *(u32_021BA978 *)(p + 0x1BC) = 0;
    }
    *(u32_021BA978 *)(p + 0x190) = func_020450F0(2, 2, 0x13, 0x1B, (u32_021BA978)4, (u32_021BA978)0xF, (u32_021BA978)1);
    if (a2)
        func_02045CAC((struct MsgBank *)(*(u32_021BA978 *)(p + 0xE4)), a1, (void *)(*(u32_021BA978 *)(p + 0xF0)));
    else
        func_02045CAC((struct MsgBank *)(*(u32_021BA978 *)(p + 0xE0)), a1, (void *)(*(u32_021BA978 *)(p + 0xF0)));
    func_0201F250((struct WordSet *)(*(u32_021BA978 *)(p + 0xDC)), (void *)(*(u32_021BA978 *)(p + 0xF4)), (void *)(*(u32_021BA978 *)(p + 0xF0)));
    k = 0xFF;
    func_02043B5C(func_02045770((struct Descriptor *)(*(u32_021BA978 *)(p + 0x190))), (u32_021BA978)k);
    e = 0xE;
    func_0201F73C((void *)(*(u32_021BA978 *)(p + 0x190)), (u32_021BA978)1, (u16)(*(u32_021BA978 *)(p + 0x1334)), (u32_021BA978)e);
    if (a3 == 0) {
        func_0201C7A4(func_02045770((struct Descriptor *)(*(u32_021BA978 *)(p + 0x190))), (u32_021BA978)0, (u32_021BA978)0, (void *)(*(u32_021BA978 *)(p + 0xF4)), (void *)(*(u32_021BA978 *)(p + 0xE8)));
    } else {
        u32_021BA978 t = func_02012FFC();
        *(u32_021BA978 *)(p + (k + 0xBD)) = func_0201CCE4(*(u32_021BA978 *)(p + 0x190), 0, 0, *(u32_021BA978 *)(p + 0xF4), *(u32_021BA978 *)(p + 0xE8), t, *(u32_021BA978 *)(p + e * 0x20), 2, 0x21, 0xF);
        func_02028470((u8 *)(p + 0x26C), 2);
    }
    func_02045334((struct Descriptor *)(*(u32_021BA978 *)(p + 0x190)));
    func_02045374((struct Cfg *)(*(u32_021BA978 *)(p + 0x190)));
    func_02041B6C(2);
}








void func_021BAAB8(char *p, int a, int b)
{
    ((Ov099Work *)p)->f19C = (void *)func_021BA8BC(((Ov099Work *)p)->f19C);
    func_021BA978(p, a, b, 1);
}







/*
 * note: Two bytes of alignment padding follow at 0x021BAB02.
 */
void func_021BAADC(char *p, int a, int b)
{
    *(int *)&((struct Obj13684 *)p)->f19C = func_021BA8BC(((struct Obj13684 *)p)->f19C);
    func_0201DD68();
    func_021BA978(p, a, b, 0);
}






void func_021BAB04(void *p, int message)
{
    func_021BA8D4((S *)p);
    P(0x19c)=(void *)func_021BA8BC(P(0x19c));
    P(0x190)=(void *)func_021BA8BC(P(0x190));
    P(0x19c)=(void *)func_020450F0(2,4,4,23,16,15,1);
    func_02049B40(23,5,0,480,32,33);
    func_02043B5C(func_02045770(P(0x19c)),255);
    func_020456F8(P(0x19c));
    func_02045374(P(0x19c));
    func_0201F73C(P(0x19c),1,(u16)*(u32_021BAB04 *)((u8 *)p+0x1334),14);
    func_02045CAC(P(0xe4),message,P(0xf0));
    func_0201F250(P(0xdc),P(0xf4),P(0xf0));
    func_0201DD68();
    func_0201C7A4(func_02045770(P(0x19c)),4,4,P(0xf4),P(0xe8));
    func_02045334(P(0x19c));
}







void func_021BABDC(void *obj, int k)
{
    u8 *w = (u8 *)func_02020D0C(obj);

    if (func_021C27E0(((struct Obj22019 *)w)->f8) == 0) {
        switch (k) {
        case 4:
        case 5:
            func_02020268(obj, 2, 15, 2);
            break;
        default:
            func_02020268(obj, 1, 15, 2);
            break;
        }
    } else {
        func_02020268(obj, 1, 15, 2);
    }
}




void func_021BAC24(char *p, Desc_021BA81C *out, Pair_021BA81C *items, int count, int kind, u32_021BA81C width)
{
    int i;
    int y;
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj00976 *)p)->f1B4);
    func_0201DD68();
    *(struct Slot * *)&((struct Obj00976 *)p)->fB8 = func_0201F81C(count, 0x21);
    for (i = 0; i < count; i++)
        func_0201F878(*(struct Slot * *)&((struct Obj00976 *)p)->fB8, ((struct Obj00976 *)p)->fE0, items[i].a, items[i].b, 0x21);
    *(int *)&((struct Obj00976 *)p)->f1A4 = func_021BA8BC(((struct Obj00976 *)p)->f1A4);
    y = 5;
    if (kind == 5)
        y = 13;
    *(u32_021BA81C *)&((struct Obj00976 *)p)->f1A4 = func_020450F0(2, (u8)(31 - width), (u8)y, (u8)width, (u32_021BA81C)count * 2, 15, 1);
    func_02045374(*(struct Cfg * *)&((struct Obj00976 *)p)->f1A4);
    func_0201F73C(((struct Obj00976 *)p)->f1A4, 2, (u16)(((struct Obj00976 *)p)->f1330), 14);
    out->w[0] = *(u32_021BA81C *)&((struct Obj00976 *)p)->fB8;
    out->w[3] = *(u32_021BA81C *)&((struct Obj00976 *)p)->f1A4;
    out->w[11] = *(u32_021BA81C *)&((struct Obj00976 *)p)->f1B4;
    out->w[10] = (u32_021BA81C)(p + 0x1ac);
    out->w[12] = ((struct Obj00976 *)p)->fE8;
    out->w[7] = (u32_021BA81C)p;
    *(struct Obj * *)&((struct Obj00976 *)p)->fBC = func_0201FF30((struct Src *)out, 0, *(u16 *)(p + 0x234 + kind * 2), 0x21);
    if (func_0201C6B4(*(struct PrintSys * *)&((struct Obj00976 *)p)->f1B4) == 0) {
        do {
            func_0201C4E4(*(struct PrintSys * *)&((struct Obj00976 *)p)->f1B4);
        } while (func_0201C6B4(*(struct PrintSys * *)&((struct Obj00976 *)p)->f1B4) == 0);
    }
    func_02020CF8(*(struct Obj * *)&((struct Obj00976 *)p)->fBC, 0x21);
    func_02041B6C(2);
}




void func_021BAD50(int a)
{
    func_021BAC24((char *)a, (Desc_021BA81C *)data_021C3B00, (Pair_021BA81C *)((void *)0x021C3A50), 5, 4, 0x11);
}


/*
 * prototype-evidence: C23B8 forwards the visibly supplied index to ov009
 *   56860, whose full body returns the address consumed here; BDD48's
 *   result is explicitly narrowed to u16 here, so its extern is wide.
 *   F878/20CF8 retain visibly supplied unused trailing heap arguments.
 * layout-evidence: the template copy is 13 words; count/rows occupy +10/+12.
 */
void func_021BAD74(char *p)
{
    int n;
    Desc_021BAD74 desc;
    struct S *state;
    u16 kind;
    u32 i;
    n = 2;
    desc = d_021C37A0;
    state = (struct S *)func_021C23B8(func_021B97F4((struct W_021BA81C *)(p + 0x274)) - 1);
    kind = (u16)func_021BDD48((int)p, state);
    func_021C27E0(state);
    func_021C27E0(*(struct S * *)&((struct Obj01244 *)p)->f8);
    *(struct Slot * *)&((struct Obj01244 *)p)->fB8 = func_0201F81C(2, 33);
    for (i = 0; i < 2; i++) {
        if (i == 0 && kind != 2 && kind != 5 && kind != 1) {
            desc.rows--;
            desc.count--;
            n--;
        } else {
            func_0201F878(*(struct Slot * *)&((struct Obj01244 *)p)->fB8, ((struct Obj01244 *)p)->fE0, d_021C3730[i].a, d_021C3730[i].b, 33);
        }
    }
    *(u32 *)&((struct Obj01244 *)p)->f1A4 = func_020450F0(2, 16, (u8)((3 - n) * 2 + 11), 15, n * 2, 15, 1);
    func_0201F73C(((struct Obj01244 *)p)->f1A4, 2, (u16)(((struct Obj01244 *)p)->f1334), 14);
    desc.w0 = *(u32 *)&((struct Obj01244 *)p)->fB8;
    desc.wc = *(u32 *)&((struct Obj01244 *)p)->f1A4;
    desc.w2c = *(u32 *)&((struct Obj01244 *)p)->f1B4;
    desc.w28 = (u32)(p + 0x1ac);
    desc.w30 = ((struct Obj01244 *)p)->fE8;
    *(struct Obj * *)&((struct Obj01244 *)p)->fBC = func_0201FF30((struct Src *)(&desc), 0, 0, 33);
    if (func_0201C6B4(*(struct PrintSys * *)&((struct Obj01244 *)p)->f1B4) == 0) {
        do {
            func_0201C4E4(*(struct PrintSys * *)&((struct Obj01244 *)p)->f1B4);
        } while (func_0201C6B4(*(struct PrintSys * *)&((struct Obj01244 *)p)->f1B4) == 0);
    }
    func_02020CF8(*(struct Obj * *)&((struct Obj01244 *)p)->fBC, 33);
    func_02045374(*(struct Cfg * *)&((struct Obj01244 *)p)->f1A4);
    func_02041B6C(2);
}






void func_021BAEDC(char *p)
{
    struct Save *a;
    struct U16Vec *temp;
    u32 kind;
    u8 other;
    int n;
    int unused;
    int v;
    int icon;
    a = (struct Save *)func_02008730(*(void **)(p + 0xc0));
    if (*(void **)(p + 0x194) == 0)
        return;
    func_0201DD68();
    temp = func_02008510(a, 33);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x194)), 255);
    if (func_02008550((const struct Sub0200852CObj *)a) == 0)
        func_0201DD78(5, 6, 0);
    else
        func_0201DD78(3, 4, 0);
    func_0201C7A4(func_02045770(*(struct Descriptor **)(p + 0x194)), 32, 0, temp, *(void **)(p + 0xe8));
    func_02045808(temp);
    kind = func_021BDD48((int)p, (struct S *)((struct S_021BAEDC *)(*(struct S_021BAEDC **)(p + 8))));
    other = func_021BDD54((int)p, (struct S_021BAEDC *)(*(struct S_021BAEDC **)(p + 8)));
    n = func_021BB918((void *)kind, other, &unused);
    if (other == 4 && kind == 4) {
        if (func_02156A3C() == -1) {
            func_02045CAC(*(struct MsgBank **)(p + 0xe0), n, *(void **)(p + 0xf0));
        } else {
            v = func_02009864((const struct Sub020097BCObj *)(*(struct Friends **)(p + 4)), func_02156A3C(), 9);
            if (v == 0)
                func_0201DD78(5, 6, 0);
            else if (v == 1)
                func_0201DD78(3, 4, 0);
            func_020099E4((struct Sub020097BCObj *)(*(struct Friends **)(p + 4)), func_02156A3C(), *(void **)(p + 0xf0));
        }
    } else {
        func_02045CAC(*(struct MsgBank **)(p + 0xe0), n, *(void **)(p + 0xf0));
    }
    func_0201C7A4(func_02045770(*(struct Descriptor **)(p + 0x194)), 102, 0, *(void **)(p + 0xf0), *(void **)(p + 0xe8));
    func_021BE4BC(p + 0x898, 1, 2, 1, kind, other, 48);
    if (func_021C27E0((struct S_021BAEDC *)(*(struct S_021BAEDC **)(p + 8)))) icon = 15;
    else icon = 11;
    func_021BE3CC(p + 0x898, 1, 26, 1, icon + 48, 0);
    func_020456F8(*(struct Descriptor **)(p + 0x194));
    func_02045374(*(struct Cfg **)(p + 0x194));
    func_02045334(*(struct Descriptor **)(p + 0x194));
    func_020409B4(3);
}







void func_021BB050(W_021BAEDC *w)
{
    func_021BA8BC(w->f198);
    w->f198 = (void *)func_020450F0(3, 5, 1, 0x16, 2, 0xf, 1);
    func_02045374(w->f198);
    func_02045CAC((struct MsgBank *)w->fe0, 0x12, (void *)w->ff8);
    func_0201C7A4(func_02045770(w->f198), 0, 0, (void *)w->ff8, (void *)w->fe8);
    func_02045334(w->f198);
}






void func_021BB0B4(char *p)
{
    func_021BA8EC(p);
    if (((Ov099Work *)p)->f1A4) {
        func_020452E8((struct Descriptor *)((Ov099Work *)p)->f1A4);
        func_0202020C((struct Obj *)((Ov099Work *)p)->fBC, 0, 0);
        func_0201F868(((Ov099Work *)p)->fB8);
        ((Ov099Work *)p)->fB8 = 0;
    }
    if (((Ov099Work *)p)->f198) { func_020452E8((struct Descriptor *)((Ov099Work *)p)->f198); ((Ov099Work *)p)->f198 = 0; }
    if (((Ov099Work *)p)->f190) { func_020452E8((struct Descriptor *)((Ov099Work *)p)->f190); ((Ov099Work *)p)->f190 = 0; }
    if (((Ov099Work *)p)->f1A8) { func_020452E8((struct Descriptor *)((Ov099Work *)p)->f1A8); ((Ov099Work *)p)->f1A8 = 0; }
    if (((Ov099Work *)p)->f194) { func_020452E8((struct Descriptor *)((Ov099Work *)p)->f194); ((Ov099Work *)p)->f194 = 0; }
    if (((Ov099Work *)p)->f1A0) { func_020452E8((struct Descriptor *)((Ov099Work *)p)->f1A0); ((Ov099Work *)p)->f1A0 = 0; }
    if (((Ov099Work *)p)->f19C) {
        func_020456F8((struct Descriptor *)((Ov099Work *)p)->f19C);
        func_02041B6C(2);
        func_021BA8BC(((Ov099Work *)p)->f19C);
        ((Ov099Work *)p)->f19C = 0;
    }
    if (((Ov099Work *)p)->fB4) { func_0202020C((struct Obj *)((Ov099Work *)p)->fB4, 0, 0); ((Ov099Work *)p)->fB4 = 0; }
    if (((Ov099Work *)p)->fB0) { func_0201F868(((Ov099Work *)p)->fB0); ((Ov099Work *)p)->fB0 = 0; }
    if (((Ov099Work *)p)->f108) { func_0201FEF4((u8 *)((Ov099Work *)p)->f108); ((Ov099Work *)p)->f108 = 0; }
}







/*
 * Allocates eight objects and homes them in the block: four buffers of 0x17C,
 * 0x17C, 0x17C and 0xB4 bytes at +0xF4, +0xFC, +0xF0, +0xF8, two objects from
 * one factory at +0x1B8 and +0x1B4, one four-argument object at +0x1C0 and one
 * at +0x9B0.  The offsets are spelled per access, which is why the listing
 * re-materialises 0x17C as `movs #0x5f; lsls #2` and adds small deltas to it.
 */
void func_021BB1A8(char *s)
{
    ((Ov099Work *)s)->fF4 = sub_020457B0(0x17C, 0x21);
    ((Ov099Work *)s)->fFC = sub_020457B0(0x17C, 0x21);
    ((Ov099Work *)s)->fF0 = sub_020457B0(0x17C, 0x21);
    ((Ov099Work *)s)->fF8 = sub_020457B0(0xB4, 0x21);
    ((Ov099Work *)s)->f1B8 = unit_0201C440(0x21);
    ((Ov099Work *)s)->f1B4 = unit_0201C440(0x21);
    ((Ov099Work *)s)->f1C0 = sub_0203101C(0x21, 0x21, 2, 0);
    ((Ov099Work *)s)->f9B0 = func_02028590(0xF, 1, 0, 0x21);
}







void func_021BB224(char *p)
{
    func_021BB4D0(p);
    func_021BB42C((S_021BB42C *)p);
    func_02028604((int)(((Ov099Work *)p)->f9B0));
    func_02045808(((Ov099Work *)p)->fF8);
    func_02045808(((Ov099Work *)p)->fF4);
    func_02045808(((Ov099Work *)p)->fFC);
    if (((Ov099Work *)p)->f1BC != 0) {
        func_0201CE48(((Ov099Work *)p)->f1BC);
        ((Ov099Work *)p)->f1BC = 0;
    }
    func_02045808(((Ov099Work *)p)->fF0);
    func_02031140(((Ov099Work *)p)->f1C0);
    func_0201C6EC(((Ov099Work *)p)->f1B8);
    func_0201C6EC(((Ov099Work *)p)->f1B4);
    func_0201C4C0(((Ov099Work *)p)->f1B8);
    func_0201C4C0(((Ov099Work *)p)->f1B4);
    ((Ov099Work *)p)->f1B8 = 0;
}







void func_021BB2B0(char *p, int v)
{
    func_02009864(((Ov099Work *)p)->f4, ((Ov099Work *)p)->f8ED - 1, 9);
    func_02043B5C(func_02045770(((Ov099Work *)p)->f958), 0);
    func_021BB528(p, v);
    func_02043598(2, 0);
    func_02043598(8, 1);
}






void func_021BB2F0(char *p, int v)
{
    char *q;

    func_02009864(((Ov099Work *)p)->f4, ((Ov099Work *)p)->f8ED - 1, 9);
    q = (char *)((Ov099Work *)p)->f8C0;
    func_02040AF0(6, q + 0xC, (u32)(((struct Obj22020 *)q)->f8), 0);
    func_020414AC(7);
    func_02043B5C(func_02045770(((Ov099Work *)p)->f95C), 0);
    func_02043B5C(func_02045770(((Ov099Work *)p)->f958), 0);
    func_021BB528(p, v);
    func_02041B6C(7);
    func_02045334(((Ov099Work *)p)->f95C);
    func_02045334(((Ov099Work *)p)->f958);
    func_02043598(2, 0);
    func_02043598(8, 1);
}






void func_021BB374(char *p, int a, int b)
{
    T4 t;
    int r;
    void *o;

    t = d_021C37D4;
    if (((Ov099Work *)p)->f180 != 0)
        func_021BB42C((S_021BB42C *)p);
    r = func_02009864(((Ov099Work *)p)->f4, a, 8);
    r = func_02025C88(r);
    o = (void *)func_0202DA04((u16)b);
    ((Ov099Work *)p)->f184 = func_0202DA48(o, r, 1, b);
    ((Ov099Work *)p)->f188 = (void *)func_0202DA18((u32)o, r, 1, 0, b);
    ((Ov099Work *)p)->f18C = (void *)func_0202DA6C(r, 2, 1, b);
    func_02049238(o);
    ((Ov099Work *)p)->f180 = func_0204B294(((Ov099Work *)p)->f110, (unsigned int)((Ov099Work *)p)->f184, (unsigned int)((Ov099Work *)p)->f188, (unsigned int)((Ov099Work *)p)->f18C, &t, 1, b);
}





void func_021BB42C(S_021BB42C *s)
{
    if (s->f180 != 0) {
        sub_0204B3B4(s->f180);
        sub_0204A8D4((u32_021BB42C)s->f184);
        sub_0204ADA4((u32_021BB42C)s->f188);
        sub_0204AFD8((u32_021BB42C)s->f18C);
        s->f180 = 0;
    }
}





void func_021BB460(char *p, int x)
{
    T8 t;
    A a;
    void *r;

    t = d_021C388C;
    if (((Ov099Work *)p)->f9AC == 0) {
        func_02082BCC(&a, 0, 0x20);
        a.f0 = &t;
        a.f4 = 1;
        a.f8 = (int)((Ov099Work *)p)->f110;
        a.f1c = 0;
        a.fC = 4;
        a.f10 = 0xC;
        a.f14 = 0xC;
        a.f18 = 2;
        r = func_021B62E0(&a, x);
        ((Ov099Work *)p)->f9AC = r;
        func_021B6578(r, 1, 0);
    }
}




void func_021BB4D0(char *p)
{
    void *q = ((Ov099Work *)p)->f9AC;

    if (q != 0) {
        func_021B639C(q);
        ((Ov099Work *)p)->f9AC = 0;
    }
}




void func_021BB4EC(Work_021BAEDC *w)
{
    void *o = func_020490F4(0x21, 0x21);

    func_02049990(o, 0x16, 4, 0, (unsigned short)w->f9a8, 0, 0, 0x21);
    func_02049238(o);
}



void func_021BB528(char *p,int v)
{
    int index;
    void *mon;
    unsigned kind,form;
    int unused;
    int message;
    func_0201DD68();
    index=((Ov099Work *)p)->f8ED-1;
    func_02009864(PTR(4),index,9);
    func_0201DD78(15,2,0);
    func_021C2370(p,index);
    func_02045CAC(PTR(0xe0),33,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    func_0201C7A4(func_02045770(PTR(0x958)),25,0,PTR(0xf8),PTR(0xe8));
    mon=(void *)func_021C23B8(index);
    kind=func_021BDD48((int)p, (struct S *)((struct S_021BAEDC *)mon));
    form=func_021BDD54((int)p, (struct S_021BAEDC *)mon);
    message=func_021BB918((void *)kind,form,&unused);
    if(message>=141 && message<=144)message-=81;
    func_02045CAC(PTR(0xe0),message,PTR(0xf0));
    func_0201C7D0(func_02045770(PTR(0x958)),96,0,PTR(0xf0),PTR(0xe8),0x3c40);
    func_02045CAC(PTR(0xe0),35,PTR(0xf8));
    func_0201C7D0(func_02045770(PTR(0x95c)),104,0,PTR(0xf8),PTR(0xe8),0x3c40);
    func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,2),4,1,1);
    func_02045CAC(PTR(0xe0),36,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    func_0201C7D0(func_02045770(PTR(0x95c)),176,24,PTR(0xf8),PTR(0xe8),0x3c40);
    func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,3),4,1,1);
    func_02045CAC(PTR(0xe0),37,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    func_0201C7D0(func_02045770(PTR(0x95c)),176,40,PTR(0xf8),PTR(0xe8),0x3c40);
    func_02045CAC(PTR(0xe0),38,PTR(0xf8));
    func_0201C7D0(func_02045770(PTR(0x95c)),104,64,PTR(0xf8),PTR(0xe8),0x3c40);
    func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,4),4,1,1);
    func_02045CAC(PTR(0xe0),39,PTR(0xf0));
    func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
    func_0201C7D0(func_02045770(PTR(0x95c)),188,64,PTR(0xf8),PTR(0xe8),0x3c40);
    func_02045CAC(PTR(0xe0),42,PTR(0xf8));
    func_0201C7D0(func_02045770(PTR(0x95c)),8,96,PTR(0xf8),PTR(0xe8),0x3c40);
    message=func_02009864(PTR(4),index,7);
    if(message){
        func_0201EFA4(PTR(0x8b0),2,message,2,0,1);
        func_0201EFA4(PTR(0x8b0),0,func_02009864(PTR(4),index,5),4,1,1);
        func_0201EFA4(PTR(0x8b0),1,func_02009864(PTR(4),index,6),2,0,1);
        func_02045CAC(PTR(0xe0),44,PTR(0xf0));
        func_0201F250(PTR(0x8b0),PTR(0xf8),PTR(0xf0));
        func_0201C7D0(func_02045770(PTR(0x95c)),152,96,PTR(0xf8),PTR(0xe8),0x3c40);
    }
    func_02045374(PTR(0x95c));
    func_02045334(PTR(0x95c));
    func_02045374(PTR(0x958));
    func_02045334(PTR(0x958));
    func_02041B6C(7);
    func_021BE4BC(p+0x898,6,2,1,kind,form,32);
    func_021BE3CC(p+0x898,6,28,1,func_021C285C(mon)?47:43,0);
    func_021BB374(p,index,v);
    func_021BB460(p,(u16)v);
    func_02043598(16,1);
}




int func_021BB918(void *w, unsigned int idx, int *unused)
{
    Tbl t;

    func_0201DD78(1, 2, 0);
    func_0201DD78(1, 2, 0);
    t = d_021C398C;
    if (idx > 15)
        idx = 15;
    return t.v[idx];
}
