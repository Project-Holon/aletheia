/*
 * file:     event_field_proclink_p06.c
 * unit:     yes
 * function: func_0216040C, func_02160564, func_021605C0, func_0216060C, func_02160668, func_021606D0, func_021606DC, func_0216070C, func_0216075C, func_021607E0, func_02160A28, func_02160A4C, func_02160A64, func_02160A7C, func_02160A94, func_02160C88, func_02160D6C, func_02160DDC, func_02160E08, func_02160F88, func_02160FB4, func_02160FE0, func_02161070, func_0216117C
 * address:  0x0216040C
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
 *   func_02040588  0x02040588  arm
 *   func_02188C54  0x02188C54  thumb
 *   func_02190344  0x02190344  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012C0C  0x02012C0C  thumb
 *   func_021C4F7C  0x021C4F7C  thumb
 *   func_021C51A0  0x021C51A0  thumb  ov021
 *   func_02190398  0x02190398  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C404  0x0200C404  thumb
 *   func_0200C468  0x0200C468  thumb
 *   func_021C5334  0x021C5334  thumb  ov021
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201897C  0x0201897C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02164480  0x02164480  thumb  ov010
 *   func_0215E840  0x0215E840  thumb  ov010
 *   d_021712CC     0x021712CC  data
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188DA0  0x02188DA0  thumb  ov021
 *   func_02188DB0  0x02188DB0  thumb  ov021
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   func_0201292C  0x0201292C  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021C3E00  0x021C3E00  thumb  ov136
 *   ov136_id       0x00000088  data
 *   d_02172978     0x02172978  data  a1
 *   func_02082BCC  0x02082BCC  arm
 *   func_02012944  0x02012944  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02012134  0x02012134  thumb
 *   func_02029DBC  0x02029DBC  thumb
 *   func_02029DD8 0x02029DD8 thumb
 *   sub_02030734   0x02030734  arm
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020120F8 0x020120F8 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013CC8 0x02013CC8 thumb
 *   func_02013CE0 0x02013CE0 thumb
 *   func_0202E474  0x0202E474  thumb
 *   func_02008298  0x02008298  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_0216F7BC  0x0216F7BC  thumb  ov010
 */
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj12324.h"

struct Ctx;
struct BigObj;
struct Big;
struct Desc;
struct Hdr;
struct Obj;
struct Flags;
struct Info;
struct Rect;
struct IcaAnime;
struct Evt;
struct Sub02008F80Obj;
struct Blk37;
struct Sub02008700Obj;
struct Rec44;
struct MyItemSave;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Req {
    u8 pad[0xC];
    u32 kind;           /* 0x0C */
    u32 detail;         /* 0x10 */
    u8 pad14[0x14];
    u32 next;           /* 0x28 */
} Req;

typedef unsigned short u16;

typedef struct Work_0216040C {
    void *f00;
    void *f04;
} Work_0216040C;

typedef struct Owner_0216075C {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u32 f0c;            /* 0x0C */
    u8 pad10[4];
    u32 f14;            /* 0x14 */
    u32 f18;            /* 0x18 */
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
} Owner_0216075C;

typedef struct Task_0216075C {
    u16 id;             /* 0x00 */
    u8 pad02[2];
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 f0c;            /* 0x0C */
    u32 state;          /* 0x10 */
    void *handle;       /* 0x14 */
    Owner_0216075C *owner;       /* 0x18 */
    u8 pad1C[4];
    u8 rect[0x14];      /* 0x20 */
    u8 flags[0x18];     /* 0x34 */
    u8 info[0x14];      /* 0x4C */
    u8 f60;             /* 0x60 */
    u8 pad61;
    u16 f62;            /* 0x62 */
    u8 pad64[4];
    u32 f68;            /* 0x68 */
    u8 pad6C[8];
} Task_0216075C;

typedef struct Owner_021607E0 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 pad08[8];
    void *f10;          /* 0x10 */
    u8 pad14[0x10];
    u32 result;         /* 0x24 */
} Owner_021607E0;

typedef struct Callbacks_0216040C {
    void *fn[3];
    u32 arg;
    void *ctx;
} Callbacks_0216040C;

typedef struct Task_021607E0 {
    u16 id;             /* 0x00 */
    u8 pad02[2];
    u32 proc;           /* 0x04 */
    u32 prev;           /* 0x08 */
    u32 next;           /* 0x0C */
    u32 state;          /* 0x10 */
    void *handle;       /* 0x14 */
    Owner_021607E0 *owner;       /* 0x18 */
    void *work;         /* 0x1C */
    Callbacks_0216040C cb;       /* 0x20 */
} Task_021607E0;

typedef struct Proc {
    void *f00;                                      /* 0x00 */
    void *f04;                                      /* 0x04 */
    void *(*init)(Task_021607E0 *t, void *arg, u32 prev, void *work); /* 0x08 */
    u32 (*finish)(Task_021607E0 *t, void *work);             /* 0x0C */
    void (*start)(Task_021607E0 *t, void *arg);              /* 0x10 */
    void (*exit)(void *work);                       /* 0x14 */
} Proc;

typedef struct Rect {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
    u32 tag;
} Rect;

typedef int (*Hook)(void *ctx, u32 arg);

typedef struct Callbacks_02160A28 {
    Hook fn0;           /* 0x00 */
    Hook fn1;           /* 0x04 */
    Hook fn2;           /* 0x08 */
    u32 arg;            /* 0x0C */
    void *ctx;          /* 0x10 */
} Callbacks_02160A28;

typedef struct Hdr20 {
    u32 w[5];
} Hdr20;

typedef struct Save_02160A94 {
    u8 pad00[0x2C];
    u32 f2c;            /* 0x2C */
} Save_02160A94;

typedef struct Ctx_02160A94 {
    u8 pad00[0x18];
    Save_02160A94 *f18;          /* 0x18 */
    u8 pad1c[0x4C - 0x1C];
    Hdr20 hdr;          /* 0x4C */
    u8 f60;             /* 0x60 */
    u8 pad61;
    u16 f62;            /* 0x62 */
    u32 f64;            /* 0x64 */
    u32 f68;            /* 0x68 */
    u32 f6c;            /* 0x6C */
} Ctx_02160A94;

typedef struct Src_0216040C {
    u8 pad00[0xD];
    u8 f0d;             /* 0x0D */
    u8 pad0e;
    u8 f0f;             /* 0x0F */
    u8 pad10;
    u8 f11;             /* 0x11 */
    u8 f12;             /* 0x12 */
    u8 pad13;
    u16 f14;            /* 0x14 */
    u8 pad16[0x2C - 0x16];
    u32 f2c;            /* 0x2C */
    u8 pad30[4];
    u32 f34;            /* 0x34 */
    u32 f38;            /* 0x38 */
} Src_0216040C;

typedef struct Req_02160A94 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0c[0x18 - 0x0C];
    void *f18;          /* 0x18 */
    Hdr20 hdr;          /* 0x1C */
    u16 f30;            /* 0x30 */
    u8 pad32[2];
    u32 f34;            /* 0x34 */
    u8 pad38[4];
    u32 f3c;            /* 0x3C */
    u8 pad40[4];
    u16 f44;            /* 0x44 */
    u16 f46;            /* 0x46 */
    u8 f48;             /* 0x48 */
    u8 pad49[0x50 - 0x49];
    u32 f50;            /* 0x50 */
    u8 pad54[0x5E - 0x54];
    u8 f5e;             /* 0x5E */
    u8 f5f;             /* 0x5F */
    u8 pad60[0x98 - 0x60];
} Req_02160A94;

typedef signed int     s32;

typedef signed char s8;

typedef short s16;

typedef struct Save_02160C88 {
    u8 pad00[0xC];
    u32 f0c;            /* 0x0C */
    u8 pad10[0x28 - 0x10];
    u32 f28;            /* 0x28 */
    u32 f2c;            /* 0x2C */
} Save_02160C88;

typedef struct Ctx_02160C88 {
    u8 pad00[0xC];
    u32 state;          /* 0x0C */
    u8 pad10[0x18 - 0x10];
    Save_02160C88 *f18;          /* 0x18 */
    u8 pad1c[0x60 - 0x1C];
    u8 f60;             /* 0x60 */
    u8 pad61;
    u16 f62;            /* 0x62 */
    u32 f64;            /* 0x64 */
    u32 f68;            /* 0x68 */
    u32 f6c;            /* 0x6C */
} Ctx_02160C88;

typedef struct Req_02160C88 {
    u8 pad00[0x34];
    u32 f34;            /* 0x34 */
    u8 pad38[4];
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u16 f44;            /* 0x44 */
    u8 pad46[0x50 - 0x46];
    u32 f50;            /* 0x50 */
} Req_02160C88;

typedef struct T { void *a; void *b; u8 *c; u16 h; } T;

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

typedef struct Setup {
    void *party;        /* 0x00 */
    void *f04;          /* 0x04 */
    void *sys;          /* 0x08 */
    u8 f0c;             /* 0x0C */
    u8 f0d;             /* 0x0D */
    u8 count;           /* 0x0E */
    u8 slot;            /* 0x0F */
    u8 kind;            /* 0x10 */
    u8 pad11[3];
    u16 f14;            /* 0x14 */
    u8 pad16[2];
    u32 f18;            /* 0x18 */
    u8 pad1C[4];
    u32 f20;            /* 0x20 */
    u32 f24;            /* 0x24 */
} Setup;

typedef struct Src_02160E08 {
    void *party;        /* 0x00 */
    u8 pad04[8];
    void *f0c;          /* 0x0C */
    u8 pad10[0x3C - 0x10];
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u16 pad44;
    u16 f46;            /* 0x46 */
} Src_02160E08;

typedef struct Holder {
    void *f00;
} Holder;

typedef struct Work_02160E08 {
    u8 pad00[0x18];
    Holder *f18;        /* 0x18 */
    u8 pad1C[0x68 - 0x1C];
    u32 f68;            /* 0x68 */
} Work_02160E08;

typedef struct Inner {
    u8 pad00[0xC];
    u32 f0c;            /* 0x0C */
} Inner;

typedef struct Seq {
    u8 pad00[0xC];
    u32 state;          /* 0x0C */
    u8 pad10[8];
    Inner *f18;         /* 0x18 */
} Seq;

typedef struct Evt {
    u8 pad00[0x12];
    u8 kind;            /* 0x12 */
} Evt;

typedef struct MenuCtx {
    void *sys;          /* 0x00 */
    u8 pad04[0x24];
    u32 mode;           /* 0x28 */
    u32 slot;           /* 0x2C */
} MenuCtx;

typedef struct MenuWork {
    u8 pad00[0xC];
    u32 next;           /* 0x0C */
    u8 pad10[8];
    MenuCtx *ctx;       /* 0x18 */
    u8 pad1C[0x4C];
    u32 f68;            /* 0x68 */
} MenuWork;

typedef struct MenuSel {
    u8 pad00[0x2C];
    u32 f2c;            /* 0x2C */
    u8 pad30[4];
    u32 item;           /* 0x34 */
    u32 arg;            /* 0x38 */
} MenuSel;

extern int func_02040588();
extern int func_02188C54();
extern int func_02190344();
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012C0C(struct BigObj *p);
extern char *func_021C4F7C(void *a0, int mode, const unsigned short *a2, unsigned short a3, unsigned short heap);
extern int func_021C51A0();
extern int func_02190398();
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C404(void *sys);
extern u16 func_0200C468(const u8 *a);
extern int func_021C5334(u32 a);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern int func_021589D0(int a0);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *party);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *pp, u32 id, u32 v);
extern u32 func_0201897C(struct Hdr *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_02164480(struct Flags *f, void *a, void *b);
extern void func_0215E840(void *field, struct Info *out);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void *func_020145CC(void *a);
extern void *func_0201210C(const struct Ctx *p);
extern void func_02188DA0(void);
extern void func_02188DB0(u8 *a);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_0201292C(const struct BigObj *p);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *func_0200CA1C(void *sv);
extern u16 *func_020127A4(void *sv);
extern u8 func_02012984(const struct BigObj *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern u32 func_021C3E00(u32 *p);
extern void func_02082BCC();
extern u8 *func_02012944(void *p);
extern u32 func_02012A30(const struct BigObj *p);
extern u32 func_02012134(u32 *p);
extern void func_02029DBC(u8 *a, u32 b);
extern int func_02029DD8(int,int);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0200CA38(struct Blk37 *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u8 *func_020120F8(const struct Ctx *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013CC8(u32);
extern u32 func_02013CE0(u32);
extern void *func_0202E474(const struct BigObj *a0, int a1, int a2, int a3);
extern void func_02008298(struct MyItemSave *, u16);
extern u32 func_0202136C(u16 v);
extern int *func_0216F7BC();
int func_0216040C(Req *r, u32 code);
int func_02160564(u32 state, u32 *out, u32 *err);
void func_021605C0(int a0, int a1);
int func_0216060C(int a0, int a1);
int func_02160668(int *a0, int *a1);
void func_021606D0(int a, int b);
void *func_021606DC(void *p, u32 a);
int func_0216070C(Work_0216040C *w);
void *func_0216075C(Owner_0216075C *o, u16 id);
int func_021607E0(void *evt, u32 *state, Task_021607E0 *t);
void func_02160A28(Rect *r, u32 tag, u32 x, u32 y, u32 w, u32 h);
int func_02160A4C(Callbacks_02160A28 *c);
int func_02160A64(Callbacks_02160A28 *c);
int func_02160A7C(Callbacks_02160A28 *c);
Req_02160A94 *func_02160A94(Ctx_02160A94 *c, int kind, int mode, Src_0216040C *src);
int func_02160C88(Ctx_02160C88 *c, Req_02160C88 *r);
T *func_02160D6C(int *a0, int a1);
BOOL func_02160DDC(u32 *a, u8 *b);
Setup *func_02160E08(Work_02160E08 *w, int kind, int mode, Src_02160E08 *src);
int func_02160F88(Seq *s, Evt *e);
int func_02160FB4(void *p);
int *func_02160FE0(u8 *a0, int a1, int a2, const int *a3);
int func_02161070(MenuWork *w, MenuSel *sel);
void func_0216117C(int *a0, int a1);
extern Proc d_021712CC[];
extern u8 ov136_id[];
extern const char d_02172978[];






/*
 * Unlabelled (inside func_0216025C's listing extent): maps a 25-way status
 * code to (kind, detail) at +0xC/+0x10, or to a next state at +0x28
 * (returning 1 for those).
 */
int func_0216040C(Req *r, u32 code)
{
    switch (code) {
    case 0:
        r->next = 0;
        return 1;
    case 1:
        r->kind = 7;
        return 0;
    case 2:
        r->kind = 11;
        return 0;
    case 3:
        r->kind = 8;
        return 0;
    case 4:
        r->next = 4;
        return 1;
    case 5:
        r->next = 5;
        return 1;
    case 6:
        r->kind = 0;
        r->detail = 5;
        return 0;
    case 7:
        r->kind = 6;
        r->detail = 0;
        return 0;
    case 8:
        r->kind = 6;
        r->detail = 1;
        return 0;
    case 9:
        r->kind = 6;
        r->detail = 2;
        return 0;
    case 10:
        r->kind = 2;
        r->detail = 0;
        return 0;
    case 11:
        r->kind = 2;
        r->detail = 1;
        return 0;
    case 12:
        r->kind = 2;
        r->detail = 2;
        return 0;
    case 13:
        r->kind = 2;
        r->detail = 3;
        return 0;
    case 14:
        r->kind = 2;
        r->detail = 4;
        return 0;
    case 15:
        r->kind = 1;
        r->detail = 1;
        return 0;
    case 16:
        r->kind = 1;
        r->detail = 6;
        return 0;
    case 17:
        r->kind = 1;
        r->detail = 2;
        return 0;
    case 18:
        r->kind = 1;
        r->detail = 3;
        return 0;
    case 19:
        r->kind = 1;
        r->detail = 4;
        return 0;
    case 20:
        r->kind = 1;
        r->detail = 5;
        return 0;
    case 21:
        r->kind = 3;
        r->detail = 1;
        return 0;
    case 22:
        r->kind = 3;
        r->detail = 2;
        return 0;
    case 23:
        r->kind = 3;
        r->detail = 3;
        return 0;
    case 24:
        r->kind = 5;
        return 0;
    }
    r->kind = 1;
    return 0;
}






/*
 * Unlabelled (inside func_0216025C's listing extent): translates a
 * connection state into a menu index; *err is set for unknown states.
 */
int func_02160564(u32 state, u32 *out, u32 *err)
{
    *err = 0;
    switch (state) {
    case 0:
        *out = 0;
        return 1;
    case 1:
        *out = 1;
        return 1;
    case 2:
        *out = 6;
        return 1;
    case 3:
        *out = 2;
        return 1;
    case 4:
        *out = 5;
        return 1;
    case 5:
        *out = 9;
        return 1;
    case 6:
        return 0;
    }
    *err = 1;
    return 0;
}






void func_021605C0(int a0, int a1)
{
    int a2;
    int a3;
    unsigned char fr[4];
    int t4;
    int t5;
    void *t6;
    u8 *name;
    char *res;
    int o4;
t4 = a1 + 0;
t5 = a0 + 0;
a0 = *(int *)&((struct Obj00020 *)t4)->fC;
    if (a0 != 0) goto loc_02160608;
loc_021605CE:
a0 = ((struct Obj00020 *)t4)->f18;
    if (a0 != 0) goto loc_02160608;
loc_021605D4:
a0 = 1;
a1 = 0;
    a0 = func_02040588(a0, a1);
loc_021605DC:
a0 = *(int *)&((struct Obj00020 *)t4)->f8;
    a0 = func_02188C54(a0);
loc_021605E2:
    if (a0 == 0) goto loc_021605EA;
loc_021605E6:
    a0 = func_02190344(a0);
loc_021605EA:
a0 = *(int *)&((struct Obj00020 *)t4)->f4;
    t6 = func_020120F4((const struct Ctx *)a0);
loc_021605F0:
    name = func_02012C0C((struct BigObj *)t6);
loc_021605F6:
a0 = 0x15;
    o4 = a0;
a1 = t5 + 0;
a3 = 0x50;
    res = func_021C4F7C(t6, a1, (const unsigned short *)name, a3, o4);
loc_02160606:
*(char * *)&((struct Obj00020 *)t4)->fC = res;
loc_02160608:
    return;
}






/*
 * unblocked: func_021C51A0 is ov021's label across the co-resident
 *   ov010/ov021 pair; the `ov021` token resolves the site as `label`.
 *   Extent runs 92 bytes against 90 compiled: the unlabelled follower.
 */
int func_0216060C(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
a0 = ((struct Obj00020 *)t5)->f18;
    if (a0 != 0) goto loc_02160662;
loc_02160616:
a0 = *(int *)&((struct Obj00020 *)t5)->f1C;
    if (a0 == 0) goto loc_02160626;
loc_0216061C:
    if (a0 == 1) goto loc_0216064A;
loc_02160620:
    if (a0 == 2) goto loc_02160656;
loc_02160624:
    goto loc_0216065E;
loc_02160626:
a0 = *(int *)&((struct Obj00020 *)t5)->fC;
    if (a0 == 0) goto loc_02160644;
loc_0216062C:
a0 = 1;
a1 = 0;
t4 = 1;
t6 = 0;
    a0 = func_02040588(a0, a1);
loc_02160638:
a0 = *(int *)&((struct Obj00020 *)t5)->fC;
    a0 = func_021C51A0(a0);
loc_0216063E:
*(int *)&((struct Obj00020 *)t5)->fC = t6;
*(int *)&((struct Obj00020 *)t5)->f1C = t4;
    goto loc_0216065E;
loc_02160644:
a0 = 2;
*(int *)&((struct Obj00020 *)t5)->f1C = a0;
    goto loc_0216065E;
loc_0216064A:
a0 = *(int *)&((struct Obj00020 *)t5)->f8;
    a0 = func_02188C54(a0);
loc_02160650:
    a0 = func_02190398(a0);
loc_02160654:
    goto loc_02160644;
loc_02160656:
a0 = 0;
*(int *)&((struct Obj00020 *)t5)->f1C = a0;
a0 = 1;
    return a0;
loc_0216065E:
a0 = 0;
    return a0;
loc_02160662:
a0 = 1;
    return a0;}






int func_02160668(int *a0, int *a1)
{
    void *x;

    x = func_0200C404(func_02012EBC((struct Big *)func_020120F4((const struct Ctx *)a1[1])));
    switch (a1[7]) {
    case 0:
        if (func_0200C468(x) == 0) {
            a1[6] = 1;
            a1[7] = 2;
        } else if ((u32)(a0[9] - 1) <= 2) {
            a1[7] = 2;
        } else {
            func_021605C0(1, (int)a1);
            a1[7] = 1;
        }
        break;
    case 1:
        if (func_021C5334(a1[3]) != 0) {
            a1[7] = 2;
        }
        break;
    case 2:
        a1[7] = 0;
        return 1;
    }
    return 0;
}






/*
 * Unlabelled thunk: tail-calls func_0216060C with its second argument.
 */
void func_021606D0(int a, int b)
{
    func_0216060C(b, b);
}






void *func_021606DC(void *p, u32 a)
{
    void *h;

    h = func_02158768((int)p, 0x7D6, 0, 0x15);
    func_02159058(func_021589D0((int)h), a, 0, 0, 0);
    return h;
}






/*
 * TRUE when some party member has field 0xA9 set and passes func_0201897C.
 */
int func_0216070C(Work_0216040C *w)
{
    void *party;
    void *pp;
    int i;

    party = func_02012934(func_020120F4(w->f04));
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        pp = func_0201AB28(party, i);
        if (func_02017E1C(pp, 0xA9, 0) != 0 && func_0201897C(pp) != 0)
            return 1;
    }
    return 0;
}






/*
 * Creates the 0x74-byte task that runs func_021607E0 and initialises it
 * from the owner.
 */
void *func_0216075C(Owner_0216075C *o, u16 id)
{
    void *h;
    Task_0216075C *t;

    h = func_020122C0(o->f00, o->f08, func_021607E0, sizeof(Task_0216075C));
    t = func_020124E8(h);
    MI_CpuFill8(t, 0, sizeof(Task_0216075C));
    t->id = id;
    t->owner = o;
    t->state = 4;
    t->handle = h;
    t->f04 = o->f0c;
    t->f08 = o->f0c;
    t->f0c = o->f0c;
    t->f60 = 0;
    t->f62 = 0;
    t->f68 = 0;
    func_02160A28((Rect *)((struct Rect *)t->rect), (u32)t->owner, t->owner->f14, t->owner->f18, t->owner->f1c, t->owner->f20);
    func_02164480((struct Flags *)t->flags, t->owner->f00, t->owner->f04);
    func_0215E840(t->owner->f04, (struct Info *)t->info);
    return h;
}






/*
 * The fourteen-state task func_0216075C creates. The procedure table at
 * 0x021712CC has 24-byte records; each pool word is the table plus the
 * field offset.
 */
int func_021607E0(void *evt, u32 *state, Task_021607E0 *t)
{
    u32 v;
    void *work;

    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        v = t->state;
        if (v <= 1) {
            *state = 2;
        } else if (v == 4) {
            if (d_021712CC[t->proc].start == 0)
                *state = 6;
            else
                *state = 3;
        } else if (v == 3) {
            t->owner->result = 3;
            *state = 2;
        } else if (v == 2) {
            t->owner->result = 2;
            *state = 2;
        }
        break;
    case 2:
        v = t->state;
        if (v == 0)
            t->owner->result = 0;
        else if (v == 1)
            t->owner->result = 1;
        return 1;
    case 3:
        if (func_02160A64((Callbacks_02160A28 *)(&t->cb)) == 0)
            break;
        d_021712CC[t->proc].start(t, t->owner->f10);
        *state = 4;
        break;
    case 4:
        *state = 5;
        break;
    case 5:
        if (t->state == 0) {
            if (func_02160A4C((Callbacks_02160A28 *)(&t->cb)) == 0)
                break;
            *state = 1;
        } else {
            *state = 1;
        }
        break;
    case 6:
        func_02012374(evt, (struct Evt **)func_021BE8D4(t->owner->f00, (int)t->owner->f04, 0, 0));
        *state = 7;
        break;
    case 7:
        if (func_02160A64((Callbacks_02160A28 *)(&t->cb)) == 0)
            break;
        func_02012374(evt, (struct Evt **)func_020144DC((int)t->owner->f00, (int)t->owner->f04));
        *state = 11;
        break;
    case 8:
        func_02160A7C((Callbacks_02160A28 *)(&t->cb));
        func_02012374(evt, func_020145CC(t->owner->f00));
        *state = 9;
        break;
    case 9:
        work = func_0201210C(t->owner->f00);
        t->owner->f04 = work;
        func_02188DA0();
        func_02188DB0(t->owner->f04);
        *state = 10;
        break;
    case 10:
        if (func_02160A4C((Callbacks_02160A28 *)(&t->cb)) == 0)
            break;
        func_02012374(evt, (struct Evt **)func_021BE92C(t->owner->f00, (int)t->owner->f04, 0, 0, 0, 0, 0));
        *state = 1;
        break;
    case 11:
        work = d_021712CC[t->proc].init(t, t->owner->f10, t->prev, t->work);
        if (t->work != 0) {
            d_021712CC[t->prev].exit(t->work);
            t->work = 0;
        }
        t->work = work;
        if (d_021712CC[t->proc].f04 == 0)
            break;
        func_020120B4(t->owner->f00, (u32)d_021712CC[t->proc].f00, d_021712CC[t->proc].f04, work);
        *state = 12;
        break;
    case 12:
        if (func_020120F0(t->owner->f00) != 0)
            break;
        *state = 13;
        break;
    case 13:
        t->state = d_021712CC[t->proc].finish(t, t->work);
        v = t->state;
        if (v == 0)
            t->owner->result = 0;
        else if (v == 1)
            t->owner->result = 1;
        else if (v == 3)
            t->owner->result = 3;
        else if (v == 2)
            t->owner->result = 2;
        if (t->state == 4) {
            t->prev = t->proc;
            t->proc = t->next;
            *state = 11;
        } else {
            if (t->work != 0) {
                func_020307B0(t->work);
                t->work = 0;
            }
            *state = 8;
        }
        break;
    }
    return 0;
}






/*
 * Clears a 0x14-byte record and fills it from five arguments.
 */
void func_02160A28(Rect *r, u32 tag, u32 x, u32 y, u32 w, u32 h)
{
    MI_CpuFill8(r, 0, sizeof(Rect));
    r->x = x;
    r->w = w;
    r->y = y;
    r->h = h;
    r->tag = tag;
}






/*
 * Runs the fn0 hook of the callback record func_02160A28 fills, or
 * returns 1 when the hook is empty.
 */
int func_02160A4C(Callbacks_02160A28 *c)
{
    if (c->fn0 != 0)
        return c->fn0(c->ctx, c->arg);
    return 1;
}






/*
 * Runs the fn1 hook of the callback record func_02160A28 fills, or
 * returns 1 when the hook is empty.
 */
int func_02160A64(Callbacks_02160A28 *c)
{
    if (c->fn1 != 0)
        return c->fn1(c->ctx, c->arg);
    return 1;
}






int func_02160A7C(Callbacks_02160A28 *c)
{
    if (c->fn2 != 0)
        return c->fn2(c->ctx, c->arg);
    return 1;
}






/*
 * Allocate and fill the 0x98-byte request record for a link step: player
 * handles from the save, the 20-byte header copied out of the context, and
 * the next state (+0x34) chosen from the step kind and the peer's reply.
 */
Req_02160A94 *func_02160A94(Ctx_02160A94 *c, int kind, int mode, Src_0216040C *src)
{
    void *sv;
    Req_02160A94 *r;
    u32 v;

    sv = func_020120F4((const struct Ctx *)(*(void **)c->f18));
    r = func_02030734(4, 0x98, 1, d_02172978, 0x330);
    r->f00 = func_02012934(sv);
    r->hdr = c->hdr;
    r->f04 = func_0201292C(sv);
    r->f08 = func_02008FEC(sv);
    r->f18 = func_0200CA1C(sv);
    r->f34 = 0;
    r->f3c = c->f18->f2c;
    r->f46 = 0;
    v = 0xFF;
    r->f5e = v;
    r->f30 = *func_020127A4(sv);
    r->f5f = func_02012984(sv);
    if (kind == 5) {
        r->f3c = 0;
        r->f34 = 5;
        v += 0xD3;
        r->f44 = v;
        c->f6c = 1;
    } else if (mode == 0) {
        r->f3c = 0;
    } else if (mode == 2) {
        r->f44 = src->f38;
        if (src->f34 != 3 && src->f34 != 4 && src->f34 != 1 && src->f34 != 0x12)
            r->f3c = 0;
        switch (src->f34) {
        case 1:
            if (src->f2c == 2)
                r->f34 = 0;
            break;
        case 12:
            r->f34 = 0x10;
            break;
        case 2:
            r->f34 = 9;
            break;
        case 3:
        case 18:
            r->f34 = 10;
            break;
        case 4:
            r->f34 = 10;
            break;
        case 5:
            r->f34 = 5;
            break;
        case 6:
            r->f34 = 6;
            break;
        default:
            r->f34 = 9;
            break;
        }
    } else if (mode == 6) {
        switch (src->f12) {
        case 0:
        case 1:
            if (src->f0d == 2) {
                if (c->f68 == 6) {
                    r->f34 = 8;
                    r->f50 = c->f64;
                } else {
                    r->f34 = 7;
                }
                r->f44 = c->f62;
                r->f46 = src->f14;
                if (src->f12 == 0)
                    r->f48 = src->f11;
                else
                    r->f48 = 0xFF;
            } else {
                r->f34 = 0;
                r->f3c = src->f0f;
            }
            break;
        }
    } else if (mode == 9) {
        int res;

        func_02034AC4((u32)ov136_id);
        res = func_021C3E00((u32 *)src);
        func_02034A5C((u32)ov136_id);
        if (c->f68 == 0) {
            r->f34 = 0xB;
            r->f3c = c->f60;
            r->f44 = c->f62;
        } else if (c->f68 == 2) {
            if (res == 1) {
                r->f34 = 0xC;
                r->f3c = c->f60;
                r->f44 = c->f62;
            } else {
                r->f34 = 0;
                r->f3c = c->f60;
            }
        }
    } else if (mode == 10) {
        r->f34 = 5;
        r->f44 = c->f62;
    }
    return r;
}






/*
 * Unlabelled (the listing folds it into func_02160A94's extent). Consume a
 * reply record: copy its result into the context and pick the next state.
 */
int func_02160C88(Ctx_02160C88 *c, Req_02160C88 *r)
{
    c->f18->f2c = r->f3c;
    c->f60 = r->f3c;
    if (c->f6c == 1) {
        if (r->f3c == 8)
            return 1;
        return 0;
    }
    switch (r->f40) {
    case 0:
        if (r->f34 == 6 || c->f18->f0c == 2) {
            c->state = 2;
            return 4;
        }
        if (r->f3c == 8)
            return 1;
        return 0;
    case 1:
        c->state = 6;
        return 4;
    case 3:
        c->state = 2;
        return 4;
    case 10:
        c->state = 2;
        return 4;
    case 4:
    case 5:
        c->state = 6;
        c->f62 = r->f44;
        c->f64 = r->f50;
        return 4;
    case 6:
    case 7:
        c->state = 9;
        return 4;
    case 8:
    case 9:
        c->state = 10;
        c->f62 = r->f44;
        return 4;
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
        c->f18->f28 = r->f40 - 11;
        return 2;
    case 15:
        c->state = 7;
        return 4;
    }
    return 1;
}




T *func_02160D6C(int *a0, int a1)
{
    T *p;
    void *sys;
    int s;

    p = func_02030734(4, 0x10, 0, (const char *)d_02172978, 0x49b);
    func_02082BCC(p, 0, 0x10);
    sys = func_020120F4((const struct Ctx *)*(int *)a0[6]);
    p->a = sys;
    p->b = func_0200CA1C(sys);
    p->c = func_02012944(p->a);
    s = func_02012A30(p->a);
    func_02029DBC((u8 *)s, func_02012134((u32 *)(*(int *)a0[6])));
    if (a1 != -1) {
        p->h = a1;
    } else {
        p->h = 0;
    }
    return p;
}



BOOL func_02160DDC(u32 *a, u8 *b) { u32 s=func_02012A30(((struct Obj12324 *)b)->f0); func_02029DD8(s,func_02012134(*(u32 **)a[6])); if (((struct Obj12324 *)b)->fE==0) return FALSE; else return TRUE; }




/*
 * Allocate and fill the 0x28-byte battle setup for mode 0 (from the
 * caller's record) or mode 6 (from the save, picking the first party
 * slot that passes the kind's checks). Levers: both source words read
 * into locals before the two stores, the kind == -1 arm written as the
 * else so it lands at the tail, func_0201AA18 returning int.
 */
Setup *func_02160E08(Work_02160E08 *w, int kind, int mode, Src_02160E08 *src)
{
    Setup *s;
    void *sys;
    void *save;
    void *t;
    void *party;
    void *mon;
    void *link;
    int i;

    s = sub_02030734(4, sizeof(Setup), 1, d_02172978, 0x4DE);
    sys = func_020120F4(w->f18->f00);
    save = func_02012EBC(sys);
    t = func_0200CA1C(sys);
    s->f0c = 1;
    s->sys = sys;
    s->f24 = 0;
    s->f18 = func_0200CA38(t);
    if (mode == 0) {
        party = src->party;
        link = src->f0c;
        s->party = party;
        s->f04 = link;
        s->count = func_0201AA18(party);
        s->slot = src->f3c;
        switch (src->f40) {
        case 4:
            s->f14 = src->f46;
            s->f0d = 2;
            s->kind = 1;
            s->f20 = 0;
            w->f68 = 5;
            break;
        case 5:
            s->f14 = src->f46;
            s->f0d = 2;
            s->kind = 1;
            s->f20 = 0;
            w->f68 = 6;
            break;
        default:
            s->kind = 0;
            s->f0d = 0;
            s->f20 = 1;
            break;
        }
    } else if (mode == 6) {
        s->f04 = func_0200873C(save);
        s->party = func_02012934(sys);
        s->count = func_0201AA18(func_02012934(sys));
        s->slot = 0;
        s->f0d = 0;
        s->f20 = 1;
        if (kind != -1) {
            s->kind = kind;
            if (s->kind == 2) {
                party = func_02012934(sys);
                for (i = 0; i < (int)func_0201AA18(party); i++) {
                    mon = func_0201AB28(party, i);
                    if (func_02017E1C(mon, 0xA9, 0) && func_0201897C(mon) && func_02017E1C(mon, 0x4C, 0) == 0) {
                        s->slot = i;
                        break;
                    }
                }
            } else if (s->kind == 1) {
                party = func_02012934(sys);
                for (i = 0; i < (int)func_0201AA18(party); i++) {
                    mon = func_0201AB28(party, i);
                    if (func_02017E1C(mon, 0xA9, 0) && func_02017E1C(mon, 0x4C, 0) == 0) {
                        s->slot = i;
                        break;
                    }
                }
            }
        } else {
            s->kind = 0;
        }
    }
    return s;
}




/*
 * Leaf after func_02160E08's pool (0x02160F88, no func_ label in the
 * listing; reached through a pointer, not a bl).
 */
int func_02160F88(Seq *s, Evt *e)
{
    switch (e->kind) {
    case 0:
    case 1:
        if (s->f18->f0c == 6)
            return 0;
        s->state = 0;
        return 4;
    case 2:
        return 1;
    }
    return 1;
}



int func_02160FB4(void *p) { unsigned short id=func_02012AC8((const struct Rec44 *)func_020120F8(p)); if(func_02013CC8(id)==1) return 1; if(func_02013CE0(id)==1) return 3; return 0; }




/*
 * 2026-10-05 (wave P21): EXACT. Older note draft (60 B off) lacked the repeated
 * default body at the end of case 0 (the `b` to the next block at +0x72 is a cross-jumped
 * copy, see a-branch-to-the-next-case-block-is-a-repeated-case-body.md). Plain literals
 * (4, -1) match; the n local was not needed. Sets the dispatch table via explicit cases
 * 1 and 3..8 beside default.
 */
int *func_02160FE0(u8 *a0, int a1, int a2, const int *a3)
{
    int h = (int)func_020120F4((const struct Ctx *)**(int **)(a0 + 0x18));
    int *r;

    switch (a2) {
    case 2:
        r = func_0202E474((const struct BigObj *)h, (int)(a0 + 0x34), func_02160FB4((void *)**(int **)(a0 + 0x18)), 4);
        if (a1 != -1) {
            func_02008298((struct MyItemSave *)r[3], (u16)a1);
        }
        break;
    case 0:
        if (a3[16] == 3) {
            r = func_0202E474((const struct BigObj *)h, (int)(a0 + 0x34), 2, 4);
        } else {
            r = func_0202E474((const struct BigObj *)h, (int)(a0 + 0x34), func_02160FB4((void *)**(int **)(a0 + 0x18)), 4);
        }
        break;
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    default:
        r = func_0202E474((const struct BigObj *)h, (int)(a0 + 0x34), func_02160FB4((void *)**(int **)(a0 + 0x18)), 4);
        break;
    }
    return r;
}




/*
 * Menu selection dispatch: maps the chosen item (sel->item) to the next
 * state, either a sub-mode (w->ctx->mode, answer 3) or a follow-up
 * screen (w->next, answer 4).
 *
 * Levers (2026-09-28 tree_ov010_4): the arms in the image's block order
 * (not case order), and the party fetch in case 18 as its own statement
 * so w->ctx is reloaded after the calls.
 */
int func_02161070(MenuWork *w, MenuSel *sel)
{
    void *party;

    switch (sel->item) {
    case 0:
        return 1;
    case 1:
        if (sel->f2c == 2) {
            w->next = 0;
            return 4;
        }
        return 0;
    case 12:
        w->next = 0;
        return 4;
    case 10:
    case 11:
        w->ctx->mode = 0;
        return 3;
    case 13:
        w->ctx->mode = 1;
        return 3;
    case 15:
        w->ctx->mode = 3;
        return 3;
    case 16:
        w->ctx->mode = 4;
        return 3;
    case 14:
        w->ctx->mode = 2;
        return 3;
    case 8:
        w->next = 8;
        return 4;
    case 7:
        w->next = 7;
        return 4;
    case 17:
        w->next = 11;
        return 4;
    case 19:
        w->next = 9;
        return 4;
    case 18:
        party = func_02012934(func_020120F4(w->ctx->sys));
        if (func_02017E1C(func_0201AB28(party, w->ctx->slot), 6, 0) != 0)
            w->next = 0;
        else
            w->next = 9;
        w->f68 = 2;
        return 4;
    case 20:
        w->ctx->mode = 5;
        return 3;
    case 2:
        if (func_0202136C(sel->arg) == 1)
            w->f68 = 0;
        w->next = 0;
        return 4;
    }
    w->next = 0;
    return 4;
}




void func_0216117C(int *a0, int a1)
{
    void *h = func_020120F4((const struct Ctx *)*(int *)a0[6]);
    u32 v = *func_020127A4(h);
    int f = 1;
    int s;
    int *r;

    s = func_02012A30(h);
    func_02029DBC((u8 *)s, func_02012134((u32 *)(*(int *)a0[6])));
    if (func_02013CC8(v) != 0 || (int)func_02013CE0((u16)v) != 0) {
        f = 0;
    }
    r = func_0216F7BC(h, 4, f);
    if (a1 != -1) {
        r[5] = a1;
    }
}
