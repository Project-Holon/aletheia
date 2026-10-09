/*
 * file:     event_field_proclink_p05.c
 * unit:     yes
 * function: func_0215F52C, func_0215F608, func_0215F630, func_0215F64C, func_0215F6E8, func_0215F734, func_0215F8A8, func_0215F900, func_0215F920, func_0215F948, func_0215F9C4, func_0215F9DC, func_0215F9EC, func_0215FA00, func_0215FA1C, func_0215FA34, func_0215FA44, func_0215FA54, func_0215FBF4, func_0215FC40, func_0215FCE0, func_0215FD0C, func_0215FEC8, func_0215FED4, func_0215FEF0, func_0215FEF4, func_0215FF34, func_0215FF54, func_02160018, func_0216025C
 * address:  0x0215F52C
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 *   func_02159F80 0x02159F80 thumb ov010
 *   func_02012914 0x02012914 thumb
 *   func_02023F60  0x02023F60  thumb
 *   func_02012444  0x02012444  thumb
 *   d_021B9EC0     0x021B9EC0  data  a4
 *   ov_id_00CD     0x000000CD  data  a1
 *   func_0215FA1C  0x0215FA1C  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_02158780  0x02158780  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_0201213C  0x0201213C  thumb
 *   func_021666A4  0x021666A4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02012158  0x02012158  thumb
 *   func_02014554  0x02014554  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02026454  0x02026454  thumb
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_02158A20  0x02158A20  thumb  ov010
 *   func_02161B90  0x02161B90  thumb  ov010
 *   ov180_id       0x000000B4  data
 *   ov181_id       0x000000B5  data
 *   ov205_id       0x000000CD  data
 *   ov182_id       0x000000B6  data
 *   d_021B800C     0x021B800C  data  ov180
 *   d_021BAB24     0x021BAB24  data  ov181
 *   d_021B9E54     0x021B9E54  data  ov205
 *   d_021B9BA0     0x021B9BA0  data  ov182
 *   func_0215E580  0x0215E580  thumb  ov010
 *   func_02012934   0x02012934  thumb
 *   func_02012FCC   0x02012FCC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020083E4  0x020083E4  thumb
 *   func_020111E8  0x020111E8  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C3B8  0x0200C3B8  thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_02183B6C 0x02183B6C thumb ov020
 *   OS_SleepThread     0x02034ac4  arm
 *   DSP_SyncPipe       0x0218571c  thumb
 *   DSPiBlockingQueue  0x00000014  data
 *   abs_id_14      0x00000014  data
 *   sub_02034AC4   0x02034AC4  arm
 *   sub_02034A5C   0x02034A5C  arm
 *   func_020129B8  0x020129B8  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02005C44  0x02005C44  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021BE92C  0x021BE92C  thumb
 *   func_0217CE08  0x0217CE08  thumb
 *   func_0217CDBC  0x0217CDBC  thumb
 *   func_0217FA24  0x0217FA24  thumb
 *   ov122_id       0x0000007A  data
 *   ov172_id       0x000000AC  data
 *   d_021D5764     0x021D5764  data  ov122
 *   d_021C7240     0x021C7240  data
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_0201232C  0x0201232C  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A0EE4  0x021A0EE4  thumb  ov021
 *   func_020355D8  0x020355D8  arm
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_02013CE0 0x02013CE0 thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_021A0F94  0x021A0F94  thumb  ov021
 *   func_021A0FA8  0x021A0FA8  thumb  ov021
 *   func_021A12A4  0x021A12A4  thumb  ov021
 *   func_021945A4  0x021945A4  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0215E840  0x0215E840  thumb  ov010
 *   func_0215EA30  0x0215EA30  thumb  ov010
 *   func_0215EA38  0x0215EA38  thumb  ov010
 *   func_0216075C  0x0216075C  thumb  ov010
 *   func_021644F4  0x021644F4  thumb  ov010
 *   func_020124E4  0x020124E4  thumb
 *   func_020129D0  0x020129D0  thumb
 *   func_0201235C  0x0201235C  thumb
 *   d_021712AC     0x021712AC  data
 *   func_021A12BC   0x021A12BC  thumb
 *   func_0200C404   0x0200C404  thumb
 *   func_0200C468   0x0200C468  thumb
 *   func_02030734  0x02030734  arm
 *   d_02172960     0x02172960  data  a4
 *   func_02160668  0x02160668  thumb  ov010
 *   func_021606D0  0x021606D0  thumb  ov010
 *   func_021605C0  0x021605C0  thumb  ov010
 *   func_0216060C  0x0216060C  thumb  ov010
 *   func_02160564  0x02160564  thumb  ov010
 *   func_0216040C  0x0216040C  thumb  ov010
 *   func_02164480  0x02164480  thumb  ov010
 *   func_0216070C  0x0216070C  thumb  ov010
 *   func_021606DC  0x021606DC  thumb  ov010
 *   func_021C5224  0x021C5224  thumb  ov021
 *   func_021C5348  0x021C5348  thumb  ov021
 *   func_021C536C  0x021C536C  thumb  ov021
 *   func_021C5380  0x021C5380  thumb  ov021
 *   func_021C5394  0x021C5394  thumb  ov021
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02028754  0x02028754  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0200C464  0x0200C464  thumb
 *   ov020_id 0x14 data a1
 */
#include "../../matched/include/Obj17706.h"
#include "../../matched/include/Obj04132.h"
#include "../../matched/include/Obj04883.h"
#include "../../matched/include/Obj05853.h"
#include "../../matched/include/Obj17707.h"
#include "../../matched/include/Obj12045.h"
#include "../../matched/include/Obj17708.h"

struct BigObj;
struct Evt;
struct Obj;
struct Ctx_0215F52C;
struct Desc;
struct Big;
struct Comm;
struct IcaAnime;
struct Work_0215F52C;
struct Sub02008700Obj;
struct DSPPipe;
struct _OSThreadQueue;
struct S0201235C;
struct Owner;
struct Work;
struct Rec44;
struct SaveBlock;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

typedef struct Work_0215F52C {
    void *sys;          /* 0x00 */
    void *f04;          /* 0x04 */
    u32 f08;            /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u8 f14[8];          /* 0x14 */
    u8 f1c[0x28 - 0x1C];/* 0x1C */
    u8 f28[8];          /* 0x28 */
    u8 f30[4];          /* 0x30 */
    u32 step;           /* 0x34 */
    u32 seq[16];        /* 0x38 */
    int timer;          /* 0x78 */
} Work_0215F52C;

typedef signed int     s32;

typedef struct Work_0215FA44 {
    void *sys;          /* 0x00 */
    u8 pad04[0x0C - 0x04];
    u8 f0c[0x1C - 0x0C];/* 0x0C */
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
    u32 f24;            /* 0x24 */
    u32 f28;            /* 0x28 */
} Work_0215FA44;

/* record behind the descriptor: owner, its context, the context's head */
struct Rec_0215FBF4 {
    int   owner;
    void *ctx;
    void *head;
};

/* the 0x5C-byte record behind the descriptor */
struct Rec_0215FC40 {
    u16          id;     /* 0x00 */
    struct Desc *desc;   /* 0x04 */
    int          owner;  /* 0x08 */
    int          field;  /* 0x0C */
    u32          f10;
    u32          f14;
    int          f18;
    int          owner2; /* 0x1C */
    int          field2; /* 0x20 */
    struct Desc *desc2;  /* 0x24 */
    u32          f28;
    int          f2C;
    void        *fn30;
    void        *fn34;
    void        *fn38;
    void        *self;   /* 0x3C */
    u8           pad40[0x5C - 0x40];
};

typedef struct Info {
    u16 id;
    u16 flags;
    u32 f04;
    u32 f08;
    void *obj;
    void *field;
} Info;

typedef struct Query {
    u16 a;
    u16 b;
    u32 c;
} Query;

typedef struct Ctx_0215F52C {
    u16 f00;            /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    void *field;        /* 0x0C */
    u32 f10;            /* 0x10 */
    u32 state;          /* 0x14 */
    u32 f18;            /* 0x18 */
    u8 req[0x28 - 0x1C];/* 0x1C */
    u32 f28;            /* 0x28 */
    u8 pad2C[0x40 - 0x2C];
    u32 f40;            /* 0x40 */
    u32 f44;            /* 0x44 */
    u32 f48;            /* 0x48 */
    u32 f4c;            /* 0x4C */
} Ctx_0215F52C;

/* the 0x40-byte block hung off the record */
struct Sub {
    int          owner;  /* 0x00 */
    int          field;  /* 0x04 */
    struct Desc *desc;   /* 0x08 */
    u32          f0C;
    u32          f10;
    void        *fn14;
    void        *fn18;
    u32          f1C;
    void        *rec;    /* 0x20 */
    u8           pad24[0x40 - 0x24];
};

/* the 0x20-byte record behind the descriptor */
struct Rec {
    struct Desc *desc;   /* 0x00 */
    int          owner;  /* 0x04 */
    int          field;  /* 0x08 */
    u32          f0C;
    struct Sub  *sub;    /* 0x10 */
    u16          id;     /* 0x14 */
    u16          f16;
    u32          f18;
    u32          f1C;
};

typedef struct Flags {
    u32 f00;
    u32 f04;
    u8 pad[0x10];
} Flags;

typedef struct Req_0215F52C {
    u8 pad00[0x24];
    u32 f24;            /* 0x24 */
    u32 f28;            /* 0x28 */
} Req_0215F52C;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    Req_0215F52C *f10;           /* 0x10 */
    u16 f14;            /* 0x14 */
    u8 pad16[2];
    u32 f18;            /* 0x18 */
} Work;

typedef struct Req_0216025C {
    u8 pad[0x24];
    u32 result;         /* 0x24 */
    u32 next;           /* 0x28 */
} Req_0216025C;

typedef struct Ctx_0216025C {
    u32 f00;
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u32 f0c;
    Req_0216025C *req;           /* 0x10 */
    u16 id;             /* 0x14 */
} Ctx_0216025C;

extern void *func_0215A5F4(void *p);
extern u16 *func_02159AE8(void *c, void *vm);
extern u32 func_020056EC(u32 n);
extern int func_02159F80(void);
extern u16 func_02012914(const struct BigObj *p);
extern void func_02023F60(u32 a0, u32 a1, u32 mask);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern int func_0215FA1C();
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *func_020120F4(const struct Ctx_0215F52C *p);
u8 *func_02012944(void *p);
u8 *func_02012ED0(struct Big *p);
int func_0201213C(struct Ctx_0215F52C *p, u32 v);
void func_021666A4(int a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0201210C(const struct Ctx_0215F52C *p);
extern u32 func_02012138(const struct Ctx_0215F52C *p);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx_0215F52C *p);
extern void func_02012158(char *p, unsigned int v);
extern int func_02014554(int a0, int a1);
extern void func_02005E30(u32 v);
extern void func_02026400(struct Comm *p);
extern u32 func_02026454(void *obj);
extern void *func_021BE8D4(void *sys, void *proc, u32 a, u32 b);
extern void func_02158A20(int a, int v);
extern void *func_02161B90(void *p, void *a1, int kind, int sub, int flag);
void func_0215E580(void *a);
extern void *func_02012934(const struct BigObj *p);
extern int func_02012FCC(int p0);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_020083E4(unsigned short *p);
extern u32 func_020111E8(void);
extern void *func_02012F08(int *p);
extern int func_0200C3B8();
extern int func_02034AC4(s32 handle);
extern void func_02183B6C(int a, int *p);
void OS_SleepThread(struct _OSThreadQueue *queue);
void DSP_SyncPipe(struct DSPPipe *pipe);
extern int sub_02034AC4(int id);
extern void sub_02034A5C(int handle);
extern void func_020129B8(struct BigObj *p, u32 v);
extern int func_020144DC(int a0, int a1);
extern void *func_020145CC(void *sys);
extern u16 func_02005C44(void);
extern void func_02005D90(u32 h, u32 v);
extern void func_02005DF8(u32 v);
extern u32 func_02026460(void *obj);
extern int func_02158344(int a0);
extern void *func_021BE92C(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void *func_0217CE08(void *sys, void *proc, u32 a, u32 b);
extern void *func_0217CDBC(void *sys);
extern void *func_0217FA24(void *sys);
extern u32 func_02188CCC(u8 *p);
extern void func_0201232C(char *p, int a1, int a2);
extern void func_02082BCC();
extern u32 func_021A0F90(u8 *p);
extern int func_021A0EE4();
extern void func_020355D8(u8 v);
extern u16 func_02188C9C(u8 *p);
extern u32 func_02013CE0(u32);
extern void *func_02188C7C(u8 *p);
extern int func_021A0ED4(u32 a);
extern int func_021A0F30(u32 a, u32 b);
extern int func_021A0F94(u32 a);
extern void func_021A0FA8(int *p);
extern u32 func_021A12A4(void *link);
extern void *func_021945A4(void *a, u32 b, u32 c);
extern void func_0216D9A0(void *map);
extern u32 *func_0216D9E4(void *c);
extern void func_0215E840(void *field, Info *out);
extern void func_0215EA30(Query *q, u16 a, u16 b, u32 c);
extern int func_0215EA38(int a0, int a1, int a2);
extern void *func_0216075C(struct Owner *o, u16 id);
extern int func_021644F4(int i, void *a, void *p);
extern void *func_020124E4(struct Obj *p);
extern void func_020129D0(struct BigObj *p, u8 v);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern void func_021A12BC(void *, int);
extern void *func_0200C404(void *sys);
extern u16 func_0200C468(const u8 *a);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_02160668(int *a0, int *a1);
extern void func_021606D0(int a, int b);
extern void func_021605C0(int a0, int a1);
extern int func_0216060C(int a0, int a1);
extern int func_02160564(u32 state, u32 *out, u32 *err);
extern int func_0216040C(Req_0215F52C *r, u32 code);
extern void func_02164480(Flags *f, void *a, void *b);
extern int func_0216070C(Work *w);
extern void *func_021606DC(void *p, u32 a);
extern void func_021C5224(char *p);
extern void func_021C5348(u8 *p);
extern void func_021C536C(u8 *p);
extern int func_021C5380(u8 *p);
extern u32 func_021C5394(u8 *p, u32 *out);
extern void *func_020127A4(struct SaveBlock *p);
extern u32 func_02012B28(const struct Rec44 *p);
extern int func_02012B70(const struct BigObj *p);
extern u32 func_02028754(struct Obj *obj, u32 n);
extern u32 func_020307B0(void *p);
extern u8 func_0200C464(const u8 *a, u32 i);
int func_0215F52C(void *c, void *vm);
int func_0215F608(int a0, int a1, int a2, int a3);
BOOL func_0215F630(void *p);
int func_0215F64C(int a0, int *st, int *a2);
void *func_0215F6E8(void *p);
int func_0215F734(void *evt, u32 *i, Work_0215F52C *w);
void *func_0215F8A8(void *p, int a1);
void func_0215F900(void *a0);
int func_0215F920(int a0);
void func_0215F948(u8 *p);
int func_0215F9C4(void);
void func_0215F9DC(Work_0215F52C *w, u32 *i);
int func_0215F9EC(int a0);
void func_0215FA00(void *p, void *q);
void func_0215FA34(void);
void func_0215FA44(void);
int func_0215FA54(void *evt, u32 *state, Work_0215FA44 *w);
struct Desc *func_0215FBF4(int a0, int a1, struct Desc *a2, int a3);
struct Desc *func_0215FC40(int a0, int a1, u16 a2);
int func_0215FCE0(int a, int b, unsigned short c);
int func_0215FD0C(void *task, void *unused, Ctx_0215F52C *c);
u32 func_0215FEC8(u32 n);
int func_0215FED4(void *a0, void *a1);
int func_0215FEF0(void);
int func_0215FEF4(u32 *a0, u32 *a1);
int func_0215FF34(void *sys);
struct Desc *func_0215FF54(int a0, int a1, u16 a2);
int func_02160018(void *evt, u32 *state, Work *w);
int func_0216025C(void *evt, u32 *state, Ctx_0216025C *c);
extern u8 d_021B9EC0[];
extern u8 ov_id_00CD[];
extern u8 ov180_id[];
extern u8 ov181_id[];
extern u8 ov205_id[];
extern u8 ov182_id[];
extern u8 d_021B800C[];
extern u8 d_021BAB24[];
extern u8 d_021B9E54[];
extern u8 d_021B9BA0[];
extern unsigned char ov020_id[];
extern struct _OSThreadQueue DSPiBlockingQueue;
extern unsigned char abs_id_14[];
extern u8 ov122_id[];
extern u8 ov172_id[];
extern u8 d_021D5764[];
extern u8 d_021C7240[];
extern const u32 d_021712AC[];
extern u8 d_02172960[];







/*
 * Draws six distinct values from 0..0x33 (random pick among the ones not
 * yet taken) and writes each plus 0x37 to six script-variable slots.
 *
 * Keys: the work locals live in a nested block opened after the six
 * func_02159AE8 calls, so `u16 buf[6] = {0}` is emitted there (at function
 * scope the initializer lands above the calls) and its stores go through
 * the same `add r4, sp, #0x18` the search loops index. `u16 n = 0x34`
 * declared before buf schedules `movs r7, #0x34` ahead of the zero stores.
 * EXACT* only for the 2-byte pad after the function (218 of 220).
 */
int func_0215F52C(void *c, void *vm)
{
    u16 *p0, *p1, *p2, *p3, *p4, *p5;

    func_0215A5F4(vm);
    p0 = func_02159AE8(c, vm);
    p1 = func_02159AE8(c, vm);
    p2 = func_02159AE8(c, vm);
    p3 = func_02159AE8(c, vm);
    p4 = func_02159AE8(c, vm);
    p5 = func_02159AE8(c, vm);
    {
        u16 n = 0x34;
        u16 buf[6] = {0};
        int i, v, j;
        s16 r;

        for (i = 0; i < 6; i++) {
            r = func_020056EC(n);
            for (v = 0; v < 0x34; v++) {
                for (j = 0; j < i; j++) {
                    if (buf[j] == v)
                        break;
                }
                if (j == i) {
                    if (--r < 0) {
                        buf[i] = v;
                        break;
                    }
                }
            }
            n--;
        }
        *p0 = buf[0] + 0x37;
        *p1 = buf[1] + 0x37;
        *p2 = buf[2] + 0x37;
        *p3 = buf[3] + 0x37;
        *p4 = buf[4] + 0x37;
        *p5 = buf[5] + 0x37;
    }
    return 0;
}









int func_0215F608(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;

t5 = 0;
loc_0215F60C:
a3 = t5 << 3;
t4 = a0 + a3;
a3 = *(u16 *)((char *)a0 + a3);
    if (a1 != a3) goto loc_0215F622;
loc_0215F616:
a3 = ((struct Obj17706 *)t4)->f2;
    if (a2 != a3) goto loc_0215F622;
loc_0215F61C:
a0 = t5 + 0;
    return a0;
loc_0215F622:
t5 = t5 + 1;
    if (t5 < 0x6b) goto loc_0215F60C;
loc_0215F628:
a0 = 0;
    return a0;}






BOOL func_0215F630(void *p) { int a = func_02159F80(); if(a == func_02012914(p)) return FALSE; else return TRUE; }







/*
 * former blocker: ABS32 0x000000CD (ov_id_00CD) has no witness outside the function (literal pool word only)
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int func_0215F64C(int a0, int *st, int *a2)
{
    switch (*st) {
    case 0:
        func_02023F60(-16, 0x37, 1);
        func_02023F60(-16, 0x3f, 2);
        func_02012444((struct Obj *)a0, (u32)ov_id_00CD, (u32)d_021B9EC0, (u32)a2);
        (*st)++;
        break;
    case 1:
        func_02023F60(0, 0x3f, 3);
        func_02012374((struct Evt *)a0, (struct Evt **)func_0215FA1C(a2[0]));
        (*st)++;
        break;
    case 2:
        if (a2[1] == 0) {
            func_02158780((void *)a0, 3, 0, 0, 0x15);
        } else {
            func_02158780((void *)a0, 0x7d1, 0, 0, 0x15);
        }
        (*st)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}







/*
 * Allocator with callback, then two accessor stores and two teardown calls.
 */
void *func_0215F6E8(void *p)
{
    int r4 = (int)func_020120F4((const struct Ctx_0215F52C *)p);
    void *r7 = func_020122C0(p, 0, func_0215F64C, 0xc);
    int *r6 = func_020124E8(r7);

    r6[0] = (int)p;
    r6[1] = (int)func_0215F630((void *)r4);
    r6[2] = (int)func_02012944((void *)r4);
    func_021666A4((int)func_02012ED0((struct Big *)r4));
    func_0201213C((struct Ctx_0215F52C *)p, 0);
    return r7;
}







/*
 * Step machine of an ov010 sub-sequence: the step comes from w->seq[*i]
 * through func_0215F9DC, loading ov180/ov181 as procs and ov205/ov182 as
 * tasks. Byte-correct first draft.
 * Former blocker (MATCH): ov205_id and ov182_id reach r1 of func_02012444, which
 * is not in match.py's OVERLAY_ID_CONSUMERS; d_021B9BA0 then fails its
 * ov182 hint for want of that overlay_id site. Same blocker as
 * func_0215FA54.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int func_0215F734(void *evt, u32 *i, Work_0215F52C *w)
{
    void *sys = w->sys;
    void *save;
    void *proc;

    func_02012EBC(w->f04);
    proc = func_0201210C((const struct Ctx_0215F52C *)w->sys);
    save = (void *)func_02012138((const struct Ctx_0215F52C *)w->sys);
    switch (w->step) {
    case 0:
        if (w->f08 == 1)
            func_0215F9EC((int)w);
        func_02005E30(30);
        func_0215F9DC(w, i);
        break;
    case 1:
        func_02012374(evt, func_021BE8D4(sys, proc, 0, 0));
        func_0215F9DC(w, i);
        break;
    case 2:
        if (func_02026454(save))
            func_02026400(save);
        func_0215F9DC(w, i);
        break;
    case 3:
        if (func_02026454(save) == 0)
            func_0215F9DC(w, i);
        break;
    case 4:
        func_02012374(evt, (void *)func_02014554((int)sys, (int)proc));
        func_0215F9DC(w, i);
        break;
    case 5:
        func_020120B4(sys, (u32)ov180_id, d_021B800C, w->f1c);
        func_0215F9DC(w, i);
        break;
    case 6:
        if (func_020120F0((const struct Ctx_0215F52C *)sys) == 0)
            func_0215F9DC(w, i);
        break;
    case 7:
        func_020120B4(sys, (u32)ov181_id, d_021BAB24, w->f28);
        func_0215F9DC(w, i);
        break;
    case 8:
        if (func_020120F0((const struct Ctx_0215F52C *)sys) == 0)
            func_0215F9DC(w, i);
        break;
    case 9:
        func_02012374(evt, func_02161B90(sys, evt, func_0215F9C4(), 0, 0));
        func_0215F9DC(w, i);
        break;
    case 10:
        func_02158A20((int)sys, 4);
        func_0215F9DC(w, i);
        break;
    case 11:
        func_02012444(evt, (u32)ov205_id, (u32)d_021B9E54, (u32)w->f14);
        func_0215F9DC(w, i);
        break;
    case 12:
        if (w->timer > 60) {
            w->timer = 0;
            func_0215F9DC(w, i);
        }
        w->timer++;
        break;
    case 13:
        func_02012444(evt, (u32)ov182_id, (u32)d_021B9BA0, (u32)w->f30);
        func_02012158(sys, 0);
        func_0215F9DC(w, i);
        break;
    case 14:
        return 1;
    case 15:
        return 0;
    }
    return 0;
}







/*
 * Allocator with callback, three sub-init calls over the new node.
 */
void *func_0215F8A8(void *p, int a1)
{
    int r7 = (int)func_020120F4((const struct Ctx_0215F52C *)p);
    void *r0v = func_020122C0(p, 0, func_0215F734, 0x7C);
    char *r4 = func_020124E8(r0v);

    ((struct Obj04132 *)r4)->f0 = (int)p;
    ((struct Obj04132 *)r4)->f4 = r7;
    ((struct Obj04132 *)r4)->f8 = a1;
    ((struct Obj04132 *)r4)->f10 = (int)func_02012944((void *)r7);
    ((struct Obj04132 *)r4)->f78 = 0;
    ((struct Obj04132 *)r4)->f14 = (int)p;
    ((struct Obj04132 *)r4)->f18 = a1;
    func_0215E580((void *)r7);
    func_0215F900(r4);
    func_0215F920((int)r4);
    func_0215F948((u8 *)r4);
    return r0v;
}







/*
 * Three arm9 size reads on the record's handle, cached at three fields.
 */
void func_0215F900(void *a0)
{
    char *p = (char *)a0;

    ((struct Obj04883 *)p)->f1C = func_02012934(((struct Obj04883 *)p)->f4);
    ((struct Obj04883 *)p)->f20 = (int)func_02012944(((struct Obj04883 *)p)->f4);
    ((struct Obj04883 *)p)->f24 = func_02012FCC((int)(((struct Obj04883 *)p)->f4));
}







/*
 * blocked:  listing 40 compiled 38
 */
int func_0215F920(int a0)
{
    int t4;
    void *big;
    struct Sub02008700Obj *obj;

t4 = a0 + 0;
a0 = ((struct Obj05853 *)t4)->f8;
    if (a0 != 1) goto loc_0215F92E;
loc_0215F92A:
a0 = 1;
    goto loc_0215F930;
loc_0215F92E:
a0 = 0;
loc_0215F930:
((struct Obj05853 *)t4)->f28 = a0;
a0 = ((struct Obj05853 *)t4)->f4;
    big = func_02012EBC((struct Big *)a0);
loc_0215F938:
    obj = func_0200873C(big);
loc_0215F93C:
    a0 = func_020083E4((short unsigned int *)obj);
loc_0215F940:
((struct Obj05853 *)t4)->f2C = a0;
((struct Obj05853 *)t4)->f30 = a0;
    return a0;}







/*
 * Addresses are Black-image addresses.
 */
void func_0215F948(u8 *p)
{
    u32 *t = (u32 *)p;
    if (t[2] == 0 || t[2] != 1) {
        t[0x38 / 4] = 0;
        t[0x3c / 4] = 2;
        t[0x40 / 4] = 3;
        t[0x44 / 4] = 4;
        t[0x48 / 4] = 7;
        t[0x4c / 4] = 8;
        t[0x50 / 4] = 12;
        t[0x54 / 4] = 9;
        t[0x58 / 4] = 12;
        t[0x5c / 4] = 10;
        t[0x60 / 4] = 11;
        t[0x64 / 4] = 12;
        t[0x68 / 4] = 13;
        t[0x6c / 4] = 14;
    } else {
        t[0x38 / 4] = 0;
        t[0x3c / 4] = 2;
        t[0x40 / 4] = 1;
        t[0x44 / 4] = 3;
        t[0x48 / 4] = 4;
        t[0x4c / 4] = 5;
        t[0x50 / 4] = 6;
        t[0x54 / 4] = 10;
        t[0x58 / 4] = 11;
        t[0x5c / 4] = 7;
        t[0x60 / 4] = 8;
        t[0x64 / 4] = 13;
        t[0x68 / 4] = 14;
    }
    t[0x34 / 4] = t[0x38 / 4];
}







int func_0215F9C4(void)
{
    int a0;

    a0 = func_020111E8();
loc_0215F9CA:
    if (a0 == 0x14) goto loc_0215F9D2;
loc_0215F9CE:
    if (a0 == 0x15) goto loc_0215F9D6;
loc_0215F9D2:
a0 = 8;
    return a0;
loc_0215F9D6:
a0 = 7;
    return a0;}







/*
 * Advance the step counter and load the next step from the sequence.
 */
void func_0215F9DC(Work_0215F52C *w, u32 *i)
{
    (*i)++;
    w->step = w->seq[*i];
}







int func_0215F9EC(int a0)
{
    int a1;
    void *p;

a0 = ((struct Obj17707 *)a0)->f4;
    p = func_02012F08((int *)a0);
loc_0215F9F4:
a1 = 0x5a;
a1 = a1 << 4;
    a0 = func_0200C3B8(p, a1);
loc_0215F9FC:
    return a0;}






void func_0215FA00(void *p, void *q) { func_02034AC4((u32)ov020_id); func_02183B6C((int)p,q); }







static void DSPi_WaitForPipe(struct DSPPipe *pipe)
{
    OS_SleepThread(&DSPiBlockingQueue);
    DSP_SyncPipe(pipe);
}




/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           abs_id_14 (20) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * Thumb tail call into the ARM sub_02034AC4 with the id 0x14, which the
 * original loads from its own pool rather than as `movs r0, #0x14`: the
 * pooled small constant is an absolute linker symbol
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 * Unlabelled in the listing (no lr-saving prologue, callers only in arm9);
 * the pair with func_0215FA44 (same id, into sub_02034A5C).
 */
void func_0215FA34(void)
{
    sub_02034AC4((int)abs_id_14);
}






/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           abs_id_14 (20) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * Thumb tail call into the ARM sub_02034A5C with the id 0x14, which the
 * original loads from its own pool rather than as `movs r0, #0x14`: the
 * pooled small constant is an absolute linker symbol
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 * Unlabelled in the listing (no lr-saving prologue, callers only in arm9);
 * the pair with func_0215FA34 (same id, into sub_02034AC4).
 */
void func_0215FA44(void)
{
    sub_02034A5C((int)abs_id_14);
}






/*
 * Proc main of an ov010 sub-sequence: 11 states that push the child
 * tasks, load ov122 and ov172, and pick the closing screen from w->f28.
 * Byte-correct (first draft plus one lever: in state 9 the `f28 == 2`
 * test and the call share an else block ending in the one `*state = 10`
 * store, so that store is the copy the other arms cross-jump to).
 * Former blocker (MATCH): the pooled 0xAC is ov172_id passed in r1 to
 * func_02012444, which is not in match.py's OVERLAY_ID_CONSUMERS
 * (func_02012444 stores r1 in a task descriptor, src/matched/func_02012444.c),
 * so the ABS32 at +0x190 has no witness.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int func_0215FA54(void *evt, u32 *state, Work_0215FA44 *w)
{
    void *sys = w->sys;
    void *save = (void *)func_02012138((const struct Ctx_0215F52C *)sys);
    void *ctx = func_020120F4((const struct Ctx_0215F52C *)sys);
    void *proc = func_0201210C((const struct Ctx_0215F52C *)sys);

    switch (*state) {
    case 0:
        func_02012374(evt, func_021BE8D4(sys, proc, 0, 0));
        (*state)++;
        break;
    case 1:
        func_02012374(evt, (struct Evt **)func_020144DC((int)sys, (int)proc));
        *state = 2;
        break;
    case 2:
        (*state)++;
    case 3:
        func_020120B4(sys, (u32)ov122_id, d_021D5764, w);
        (*state)++;
        break;
    case 4:
        if (func_020120F0((const struct Ctx_0215F52C *)sys) != 0)
            break;
        switch (w->f20) {
        case 0:
            if (func_02158344((int)save) && w->f28 == 2)
                func_020129B8(ctx, 3);
            *state = 6;
            break;
        case 1:
            w->f24 = func_02005C44();
            func_02012444(evt, (u32)ov172_id, (u32)d_021C7240, (u32)w->f0c);
            *state = 5;
            break;
        default:
            *state = 6;
            break;
        }
        break;
    case 5:
        if (func_020120F0((const struct Ctx_0215F52C *)sys) != 0)
            break;
        func_02005D90(w->f24, 0xFFFF);
        func_02005DF8(60);
        *state = 6;
        break;
    case 6:
        w->f1c = 0;
        (*state)++;
        break;
    case 7:
        func_02012374(evt, func_020145CC(sys));
        (*state)++;
        break;
    case 8:
        func_02012374(evt, func_021BE92C(sys, proc, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 9:
        if (w->f20 == 0) {
            if (w->f28 == 0) {
                if (func_02026460(save))
                    break;
                if (func_02026454(save)) {
                    func_02026400(save);
                    break;
                }
                func_02012374(evt, func_0217CE08(sys, proc, 0x117, 0));
                *state = 10;
            } else if (w->f28 == 3) {
                func_02012374(evt, func_0217FA24(sys));
                *state = 10;
            } else {
                if (w->f28 != 2)
                    func_02012374(evt, func_0217CDBC(sys));
                *state = 10;
            }
        } else {
            *state = 10;
        }
        break;
    case 10:
        return 1;
    }
    return 0;
}






struct Desc *func_0215FBF4(int a0, int a1, struct Desc *a2, int a3)
{
    struct Rec_0215FBF4 *p;
    void *ctx;

    func_02188CCC((u8 *)a1);
    if (a3 != 0) {
        a2 = func_020122C0((void *)a0, 0, (void *)func_0215FA54, 0x34);
    } else {
        func_0201232C((char *)a2, (int)func_0215FA54, 0x34);
    }
    p = (struct Rec_0215FBF4 *)func_020124E8((struct Obj *)a2);
    ctx = func_020120F4((const struct Ctx_0215F52C *)a0);
    p->ctx = ctx;
    p->head = func_02012EBC((struct Big *)ctx);
    p->owner = a0;
    return a2;
}




struct Desc *func_0215FC40(int a0, int a1, u16 a2)
{
    int x;
    int sz = 0x5c;
    struct Desc *r7;
    struct Rec_0215FC40 *p;
    int r;

    x = func_02188CCC((u8 *)a1);
    r7 = func_020122C0((void *)a0, 0, (void *)func_0215FD0C, sz);
    p = (struct Rec_0215FC40 *)func_020124E8((struct Obj *)r7);
    func_02082BCC(p, 0, sz);
    p->owner = a0;
    p->desc = r7;
    p->field = a1;
    p->id = a2;
    p->f14 = 0;
    p->owner2 = a0;
    p->field2 = a1;
    p->desc2 = r7;
    p->fn30 = (void *)func_0215FED4;
    p->fn34 = (void *)func_0215FEF0;
    p->fn38 = (void *)func_0215FEF4;
    p->self = p;
    p->f2C = sz - 0x5d;
    r = func_021A0F90((u8 *)x);
    switch (r) {
    case 3:
        r = 3;
        break;
    case 4:
        r = 4;
        break;
    default:
        r = func_021A0EE4(func_02188CCC((u8 *)p->field), 0);
        break;
    }
    p->f18 = r;
    func_020355D8(1);
    return r7;
}




int func_0215FCE0(int a, int b, unsigned short c) { int task; u32 *p; task=(int)func_0215FC40(a,b,c); p=func_020124E8((struct Obj *)task); p[6]=func_02013CE0(func_02188C9C((void *)b)) == 1 ? 5 : 2; return task; }





/*
 * Nine-state link setup task of the ov010 field (the extent ends at
 * 0x0215FEC6; 0x0215FEC8 is its unlabelled table-lookup leaf). State 3
 * keeps the call arm inside the negated test so the `return 1` block
 * follows it.
 */
int func_0215FD0C(void *task, void *unused, Ctx_0215F52C *c)
{
    Query q;
    Info info;
    void *map;
    void *sys;
    void *next;
    u32 n;
    int r;

    switch (c->state) {
    case 0:
        if (func_021A0ED4(func_02188CCC(c->field)) == 1) {
            map = func_02188C7C(c->field);
            sys = func_020120F4((const struct Ctx_0215F52C *)(func_020124E4(task)));
            func_0216D9A0(map);
            func_020129D0(sys, 1);
            func_021A0F30(func_02188CCC(c->field), 1);
            c->state = 1;
        }
        break;
    case 1:
        r = func_021A0F94(func_02188CCC(c->field));
        if (r == 3) {
            c->state = 2;
            func_021A0FA8((int *)func_02188CCC(c->field));
        } else if (r == 4) {
            c->state = 3;
            func_021A0FA8((int *)func_02188CCC(c->field));
        }
        break;
    case 2:
        sys = func_020120F4((const struct Ctx_0215F52C *)(func_020124E4(task)));
        n = func_021A12A4((void *)func_02188CCC(c->field));
        func_020129D0(sys, n);
        c->f10 = func_021A12A4((void *)func_02188CCC(c->field));
        c->f28 = func_0215FEC8(n);
        c->state = 5;
        break;
    case 3:
        func_0216D9E4(func_02188C7C(c->field));
        if (c->f40 != 1 && c->f40 != 4) {
            func_0201235C(task, func_021945A4(func_020124E4(task), (u32)c->field, c->f18));
            return 0;
        }
        return 1;
    case 4:
        func_0216D9E4(func_02188C7C(c->field));
        func_0215E840(func_0201210C((const struct Ctx_0215F52C *)c->f08), &info);
        func_0215EA30(&q, c->f48, c->f44, c->f4c);
        next = (void *)func_0215EA38(c->f44, (int)(&q), (int)(&info));
        if (next == 0)
            return 1;
        func_0201235C(c->f04, next);
        break;
    case 5:
        func_02012374(task, func_0216075C((struct Owner *)c->req, c->f00));
        c->state = 6;
        break;
    case 6:
        if (c->f40 == 0)
            c->state = 1;
        else if (c->f40 == 1)
            c->state = 3;
        else if (c->f40 == 3)
            c->state = 7;
        else if (c->f40 == 2)
            c->state = 4;
        else if (c->f40 == 4)
            c->state = 3;
        break;
    case 7:
        func_0216D9E4(func_02188C7C(c->field));
        func_02012374(task, (struct Evt **)func_021644F4(c->f44, c->f08, c->field));
        c->state = 8;
        break;
    case 8:
        return 1;
    }
    return 0;
}






/*
 * Unlabelled leaf after func_0215FD0C (bl from 0x0215FDD0).
 */
u32 func_0215FEC8(u32 n)
{
    return d_021712AC[n];
}






/*
 * Conditional arm9 pair call on the record's second field; the first
 * call's result is the first operand either way.
 */
int func_0215FED4(void *a0, void *a1)
{
    void *v = (void *)func_02188CCC((u8 *)(((struct Obj12045 *)a1)->fC));

    if (((struct Obj17708 *)a0)->f24 == 0)
        func_021A12BC(v, ((struct Obj12045 *)a1)->f10);

    return 1;
}





/*
 * Unlabelled leaf: returns 1.
 */
int func_0215FEF0(void)
{
    return 1;
}






int func_0215FEF4(u32 *a0, u32 *a1)
{
    void *h = func_020120F4((const struct Ctx_0215F52C *)a1[2]);

    switch (a0[9]) {
    case 4:
        func_020129B8(h, 6);
        break;
    case 0:
        func_020129B8(h, 1);
        break;
    case 1:
    case 2:
    case 3:
        func_020129B8(h, (u8)a1[6]);
        break;
    default:
        break;
    }
    return 1;
}






/*
 * Three chained arm9 probes; a non-zero result from the last reads as
 * success.
 */
int func_0215FF34(void *sys)
{
    if (func_0200C468(func_0200C404(func_02012EBC(func_020120F4((const struct Ctx_0215F52C *)sys)))) != 0)
        return 1;

    return 0;
}






struct Desc *func_0215FF54(int a0, int a1, u16 a2)
{
    void *sp8;
    struct Desc *r5;
    struct Rec *p;

    sp8 = func_0200C404(func_02012EBC((struct Big *)func_020120F4((const struct Ctx_0215F52C *)a0)));
    if (func_0200C468(sp8) == 1) {
        r5 = func_020122C0((void *)a0, 0, (void *)func_0216025C, 0x20);
    } else {
        r5 = func_020122C0((void *)a0, 0, (void *)func_02160018, 0x20);
    }
    p = (struct Rec *)func_020124E8((struct Obj *)r5);
    func_02082BCC(p, 0, 0x20);
    p->owner = a0;
    p->desc = r5;
    p->field = a1;
    p->id = a2;
    p->f18 = 0;
    p->sub = (struct Sub *)func_02030734(4, 0x40, 0, (const char *)d_02172960, 0xc2);
    func_02082BCC(p->sub, 0, 0x40);
    p->sub->owner = p->owner;
    p->sub->field = p->field;
    p->sub->desc = r5;
    if (func_0200C468(sp8) != 1) {
        p->sub->fn14 = (void *)func_02160668;
        p->sub->fn18 = (void *)func_021606D0;
        p->sub->rec = p;
    }
    func_0216D9A0(func_02188C7C((unsigned char *)p->field));
    func_020355D8(0);
    return r5;
}




/*
 * Proc main of the ov010 link exchange: a 16-state machine that drives
 * the ov021 connection object at +0xC, classifies the received result
 * code, and hands off to the result screens before tearing down.
 *
 * The ov021 calls to 0x021C536C, 0x021C5380 and 0x021C5394 (once folded
 * into func_021C5348) resolve since seeds_2 labelled them. Levers: in state 4 `retry` declared first and `bad`
 * last (retry spills to sp+4, ok to sp+0, next stays in r7), the result
 * code dispatched as a switch and the case-10 value as an if chain with
 * the f18 != 0 arm first; in state 12 the tail call in a local written
 * as a nested if (i == 0, then the save test) with the call in all
 * three arms, which is what makes both w->f04 loads hoist above their
 * branches and lets state 11 cross-jump into the shared tail.
 */
int func_02160018(void *evt, u32 *state, Work *w)
{
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        func_021605C0(0, (int)w);
        *state = 2;
        break;
    case 2:
        func_021C5348(w->f0c);
        *state = 3;
        break;
    case 3:
        func_021C5224(w->f0c);
        if (func_021C5380(w->f0c) == 0)
            *state = 4;
        break;
    case 4: {
        u32 code;
        int r;

        func_021C5224(w->f0c);
        r = func_021C5394(w->f0c, &code);
        if (r == 1) {
            Flags fl;
            u32 n;
            u32 err;
            int retry = 0;
            int ok;
            int next;
            int bad = 0;

            ok = func_02160564(code, &n, &err);
            next = func_0216040C((Req_0215F52C *)w->f10, code);
            if (err == 0 && func_02012B70(func_020120F4((const struct Ctx_0215F52C *)w->f04)) == 1) {
                bad = 1;
            } else if (ok == 1) {
                func_02164480(&fl, w->f04, w->f08);
                if (func_02028754((struct Obj *)(&fl), n) == 0)
                    bad = 1;
            }
            if (code == 9 && func_0216070C(w) == 0)
                retry = 1;
            if (bad == 1) {
                *state = 12;
            } else if (retry == 1) {
                *state = 14;
            } else {
                switch (next) {
                case 0:
                    *state = 9;
                    break;
                case 1:
                    *state = 11;
                    break;
                }
            }
        } else if (r == 2) {
            *state = 5;
        }
        break;
    }
    case 5:
        func_021C536C(w->f0c);
        *state = 6;
        break;
    case 6:
        func_021C5224(w->f0c);
        if (func_021C5380(w->f0c) == 0)
            *state = 7;
        break;
    case 7:
        if (func_0216060C((int)w, (int)state) != 0) {
            func_020307B0(w->f10);
            func_0216D9E4(func_02188C7C(w->f08));
            return 1;
        }
        break;
    case 8:
        func_021605C0(1, (int)w);
        *state = 4;
        break;
    case 9:
        func_02012374(evt, func_0216075C((struct Owner *)w->f10, w->f14));
        *state = 10;
        break;
    case 10:
    {
        u32 v = w->f10->f24;

        if (v == 0) {
            if (w->f18 != 0)
                *state = 7;
            else
                *state = 8;
        } else if (v == 1) {
            *state = 7;
        } else if (v == 3) {
            *state = 11;
        }
        break;
    }
    case 11:
        if (func_0216060C((int)w, (int)state) != 0) {
            u32 i = w->f10->f28;

            func_020307B0(w->f10);
            w->f10 = 0;
            func_02012374(evt, (struct Evt **)func_021644F4(i, w->f04, w->f08));
            *state = 13;
        }
        break;
    case 12:
        if (func_0216060C((int)w, (int)state) != 0) {
            u32 i = w->f10->f28;

            func_020307B0(w->f10);
            w->f10 = 0;
            {
                void *t;

                if (i == 0) {
                    if (func_02012B28(func_020127A4(func_020120F4((const struct Ctx_0215F52C *)w->f04))) == 1)
                        t = func_021606DC(w->f04, 1);
                    else
                        t = func_021606DC(w->f04, 0);
                } else {
                    t = func_021606DC(w->f04, 0);
                }
                func_02012374(evt, t);
            }
            *state = 13;
        }
        break;
    case 13:
        func_0216D9E4(func_02188C7C(w->f08));
        return 1;
    case 14:
        if (func_0216060C((int)w, (int)state) != 0) {
            func_020307B0(w->f10);
            w->f10 = 0;
            func_02012374(evt, func_021606DC(w->f04, 2));
            *state = 15;
        }
        break;
    case 15:
        func_0216D9E4(func_02188C7C(w->f08));
        return 1;
    }
    return 0;
}


/*
 * Nine-state connection sequence; returns 1 when the sequence has ended.
 * EXACT* because the listing extent runs over the unlabelled followers
 * 0x0216040C, 0x02160564 and 0x021605C0. Levers: the case-3 test is an
 * else-if chain with the `*state = 1` arm written twice (the first copy is
 * cross-jumped into `b`), and cases 4 and 5 hand one local `h` to
 * func_02012374, which is what lets case 4 cross-jump into case 5's call.
 */
int func_0216025C(void *evt, u32 *state, Ctx_0216025C *c)
{
    Flags flags;
    u32 idx;
    u32 err;
    u32 code;
    int r;
    int ok;
    int failed;
    int busy;
    u32 next;
    void *h;

    switch (*state) {
    case 0:
        code = func_0200C464(func_0200C404(func_02012EBC(func_020120F4((const struct Ctx_0215F52C *)c->f04))), 0);
        failed = 0;
        r = func_0216040C((Req_0215F52C *)c->req, code);
        busy = 0;
        ok = func_02160564(code, &idx, &err);
        if (err == 0 && func_02012B70(func_020120F4((const struct Ctx_0215F52C *)c->f04)) == 1) {
            failed = 1;
        } else if (ok == 1) {
            func_02164480(&flags, c->f04, c->f08);
            if (func_02028754((struct Obj *)(&flags), idx) == 0)
                failed = 1;
        }
        if (code == 9 && func_0216070C((Work *)((struct Work *)c)) == 0)
            busy = 1;
        if (failed == 1) {
            *state = 5;
        } else if (busy == 1) {
            *state = 7;
        } else {
            switch (r) {
            case 0:
                *state = 2;
                break;
            case 1:
                *state = 4;
                break;
            }
        }
        break;
    case 1:
        func_020307B0(c->req);
        func_0216D9E4(func_02188C7C(c->f08));
        return 1;
    case 2:
        if (func_0216060C((int)c, (int)state) != 0) {
            func_02012374(evt, func_0216075C((struct Owner *)c->req, c->id));
            *state = 3;
        }
        break;
    case 3:
        r = c->req->result;
        if (r == 0) {
            *state = 1;
        } else if (r == 1) {
            *state = 1;
        } else if (r == 3) {
            *state = 4;
        }
        break;
    case 4:
        next = c->req->next;
        func_020307B0(c->req);
        c->req = 0;
        h = (void *)func_021644F4(next, c->f04, c->f08);
        func_02012374(evt, h);
        *state = 6;
        break;
    case 5:
        next = c->req->next;
        func_020307B0(c->req);
        c->req = 0;
        if (next == 0) {
            if (func_02012B28(func_020127A4(func_020120F4((const struct Ctx_0215F52C *)c->f04))) == 1)
                h = func_021606DC(c->f04, 1);
            else
                h = func_021606DC(c->f04, 0);
        } else {
            h = func_021606DC(c->f04, 0);
        }
        func_02012374(evt, h);
        *state = 6;
        break;
    case 6:
        func_0216D9E4(func_02188C7C(c->f08));
        return 1;
    case 7:
        func_020307B0(c->req);
        c->req = 0;
        func_02012374(evt, func_021606DC(c->f04, 2));
        *state = 8;
        break;
    case 8:
        func_0216D9E4(func_02188C7C(c->f08));
        return 1;
    }
    return 0;
}
