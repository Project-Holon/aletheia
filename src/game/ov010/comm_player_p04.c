/*
 * file:     comm_player_p04.c
 * unit:     yes
 * function: func_02168F54, func_02169004, func_02169068, func_021690A4, func_021690B4, func_021690D0, func_021690E0, func_021690F0, func_02169100, func_02169110, func_02169120, func_02169138, func_02169148, func_0216928C, func_02169308
 * address:  0x02168F54
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
 *   func_02089004  0x02089004  arm
 *   func_02088F58  0x02088F58  arm
 *   _ll_sdiv       0x0209BE5C  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020143F0  0x020143F0  thumb
 *   func_0200D440  0x0200D440  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201B100  0x0201B100  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008E30  0x02008E30  thumb
 *   func_02009470  0x02009470  thumb
 *   func_0200952C  0x0200952C  thumb
 *   func_021862A8  0x021862A8  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_0200E518  0x0200E518  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   func_0200AB04  0x0200AB04  thumb
 *   func_0201AD0C 0x0201AD0C thumb
 *   func_02012984 0x02012984 thumb
 *   func_0216A2EC 0x0216A2EC thumb ov010
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C3C0 0x0200C3C0 thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_020113F0  0x020113F0  thumb
 *   func_0203F524 0x0203F524 arm
 *   func_02008BD0  0x02008BD0  thumb
 *   sub_02030734   0x02030734  arm
 *   func_02046C94  0x02046C94  arm
 *   func_0216990C  0x0216990C  thumb  ov010
 *   d_02172A40     0x02172A40  data
 *   g_020A8140     0x020A8140  data
 *   g_020A8148     0x020A8148  data
 *   func_021693A0  0x021693A0  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   d_020A814C     0x020A814C  data   a4
 *   d_020A8144     0x020A8144  data   a4
 */
#include "../../matched/include/Obj17735.h"
#include "../../matched/include/Obj17736.h"
#include "../../matched/include/Obj17737.h"
#include "../../matched/include/Obj17738.h"
#include "../../matched/include/Obj17739.h"
#include "../../matched/include/Obj17740.h"
#include "../../matched/include/Obj12384.h"
#include "../../matched/include/Obj04162.h"

struct RTCDate;
struct RTCTime;
struct BigObj;
struct Tally;
struct Big;
struct Rec0200AB04;
struct Sub02009470Obj;
struct Blk34;
struct Sub02008AECSession;
typedef unsigned int u32;

typedef long long s64;

typedef struct { u32 a, b, c, d; } Date;

typedef struct { u32 a, b, c; } Time;

typedef struct {
    int f0;
    Date date;
    Time time;
    int f20;
} A;

typedef signed int     s32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long long u64;

typedef struct Cfg {
    u32 size;           /* 0x00 */
    u32 texSize;        /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 f0c;            /* 0x0C */
    u32 f10;            /* 0x10 */
    u16 nA;             /* 0x14 */
    u16 nB;             /* 0x16 */
    u32 f18;            /* 0x18 */
    u32 f1c;            /* 0x1C */
} Cfg;

typedef struct Node {
    u32 f00;
    u32 f04;
} Node;

typedef struct Mgr {
    u8 pad00[0x10];
    u32 f10;            /* 0x10 */
    u8 pad14[0x1C - 0x14];
    u32 size;           /* 0x1C */
    u32 texSize;        /* 0x20 */
    u32 f24;            /* 0x24 */
    u32 f28;            /* 0x28 */
    Node *head;         /* 0x2C */
    Node node;          /* 0x30 */
    u8 pad38[0x84 - 0x38];
    void *f84;          /* 0x84 */
    void *f88;          /* 0x88 */
    u32 texKey;         /* 0x8C */
    u32 plttKey;        /* 0x90 */
    u32 f94;            /* 0x94 */
    u8 pad98[4];
    void *listA;        /* 0x9C */
    void *listB;        /* 0xA0 */
    u16 nA;             /* 0xA4 */
    u16 nB;             /* 0xA6 */
    u32 fA8;            /* 0xA8 */
    u32 fAC;            /* 0xAC */
    u8 padB0[0xD4 - 0xB0];
    void *buf;          /* 0xD4 */
    u32 fD8;            /* 0xD8 */
} Mgr;

typedef void (*Cb)(u8 *, u32);

extern long long func_02089004(struct RTCDate *date, struct RTCTime *time);
extern s32 func_02088F58(struct RTCDate *date);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_020143F0(u8 *a);
extern void func_0200D440(void *sys);
extern void *func_02012934(const struct BigObj *p);
extern void func_0201B100(void *, int);
extern void *func_02012F2C(int *p);
extern void func_02008E30(void *a0);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern void func_0200952C(struct Sub02009470Obj *obj);
extern void func_021862A8(int, int, int);
extern void *func_0200E394(void *a0);
extern void func_0200E518(struct Tally *t);
extern void *func_0200A8A0(void *sys);
extern void func_0200AB04(struct Rec0200AB04 *o);
extern void *func_0201AD0C(void *sys);
extern u8 func_02012984(const struct BigObj *p);
extern int func_0216A2EC(int,int,int,int *,int);
extern void *func_0200C0F0(void *sys);
extern void func_0200C3C0(struct Blk34 *p, u16 v);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern int func_020113F0(int row, int col);
extern u64 func_0203F524(void);
extern int func_02008BD0(const struct Sub02008AECSession *s);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02046C94(void);
extern void func_0216990C(u8 *p);
extern void func_021693A0(int a0);
extern u32 func_020307B0(void *p);
int func_02168F54(A *a, Date *b, Time *c, int *d, int *e);
void func_02169004(int a, int b);
void func_02169068(int a,int b,int *c);
void *func_021690A4(int a0);
int func_021690B4(int a0);
int func_021690D0(int a0);
int func_021690E0(int a0);
int func_021690F0(int a0);
int func_02169100(int a0);
int func_02169110(int a0);
void func_02169120(void *p);
int func_02169138(int a0);
Mgr *func_02169148(const Cfg *cfg, u32 heap);
void func_0216928C(void *p);
void func_02169308(u8 *p);
extern const char d_02172A40[];



int func_02168F54(A *a, Date *b, Time *c, int *d, int *e)
{
    s64 sa = func_02089004((struct RTCDate *)(&a->date), (struct RTCTime *)(&a->time));
    s64 sb = func_02089004((struct RTCDate *)b, (struct RTCTime *)c);
    int day = func_02088F58((struct RTCDate *)b);
    int q;
    *d = 0;
    *e = 0;
    if (sb < sa) {
        a->date = *b;
        a->time = *c;
        a->f20 = day;
        return 0;
    }
    q = (int)((sb - sa) / 60);
    if (q > 0) {
        int dd;
        *e = q;
        a->date = *b;
        a->time = *c;
        dd = day - a->f20;
        if (dd != 0) {
            *d = dd;
            a->f20 = day;
        }
    }
    return 1;
}



/*
 * evidence: 0x0200E518 is an unlabelled ARM9 leaf ("push {r4, r5, r6, r7}",
 * no lr, right after the "pop {r4, pc}" at 0x0200E516) that the prologue
 * sweep misses.  The bl at +0x52 is its only reference in the image; its
 * start is seeded in layout/function_starts.txt, and the callee itself is
 * matched EXACT* (src/matched/arm9/func_0200E518.c), so +0x52 attests as
 * `matched`.
 */
void func_02169004(int a, int b)
{
    int x;
    func_02169138(a);
    x = (int)func_02012EBC((struct Big *)a);
    func_020143F0((u8 *)func_0201296C((const struct BigObj *)a));
    func_0200D440((void *)x);
    func_0201B100(func_02012934((void *)a), b);
    func_02008E30(func_02012F2C((int *)a));
    func_0200952C(func_02009470((void *)x));
    func_021862A8(a, b, 4);
    func_0200E518(func_0200E394((void *)x));
    func_0200AB04(func_0200A8A0((void *)x));
}


/*
 * extent: trailing two-byte alignment padding.
 * interface: final u16 argument follows the original lsls/lsrs #16 pair.
 */
void func_02169068(int a,int b,int *c) { int t=(int)func_0201AD0C(func_02012EBC((struct Big *)a)); func_0216A2EC(a,t,b,c,func_02012984((const struct BigObj *)a)); func_0200C3C0((struct Blk34 *)((int)func_0200C0F0(func_02012EBC((struct Big *)a))),b); }



void *func_021690A4(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690AA:
    s = func_02008B14(big);
loc_021690AE:
    return (char *)s + 4;}



int func_021690B4(int a0)
{
    int a1;
    struct Sub02008AECSession *t4;
    void *big;
    int t5;

t5 = a0 + 0;
    big = func_02012EBC((struct Big *)a0);
loc_021690BC:
    t4 = func_02008B14(big);
loc_021690C0:
a0 = t5 + 0;
    a0 = func_02012984((const struct BigObj *)a0);
loc_021690C8:
a1 = ((struct Obj17735 *)t4)->f14;
    a0 = func_020113F0(a0, a1);
loc_021690CE:
    return a0;}



int func_021690D0(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690D6:
    s = func_02008B14(big);
loc_021690DA:
a0 = ((struct Obj17736 *)s)->f8;
    return a0;}




int func_021690E0(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690E6:
    s = func_02008B14(big);
loc_021690EA:
a0 = ((struct Obj17737 *)s)->fC;
    return a0;}




int func_021690F0(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690F6:
    s = func_02008B14(big);
loc_021690FA:
a0 = ((struct Obj17738 *)s)->f10;
    return a0;}




int func_02169100(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_02169106:
    s = func_02008B14(big);
loc_0216910A:
a0 = ((struct Obj17739 *)s)->f14;
    return a0;}




int func_02169110(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_02169116:
    s = func_02008B14(big);
loc_0216911A:
a0 = ((struct Obj17740 *)s)->f18;
    return a0;}



void func_02169120(void *p) { char *q = (char *)func_02008B14(func_02012EBC(p)); *(u64 *)(q + 0x2c) = func_0203F524(); }




int func_02169138(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_0216913E:
    s = func_02008B14(big);
loc_02169142:
    a0 = func_02008BD0(s);
loc_02169146:
    return a0;}



#define F(o) (*(u32 *)((char *)p + (o)))



extern u32 (*g_020A8140)(u32 size, u32 is4x4, u32 opt);



extern u32 (*g_020A8148)(u32 size, u32 is4pltt, u32 opt);




/*
 * Create the 0xDC-byte effect manager from its Cfg: two record lists,
 * work buffers, and texture/palette VRAM keys through the NNS default
 * allocator hooks. Levers: the buffer size from cfg (not the just-stored
 * copy), and the list terminator cleared through m->head.
 */
Mgr *func_02169148(const Cfg *cfg, u32 heap)
{
    Mgr *m;
    u32 sz;

    m = sub_02030734(heap, sizeof(Mgr), 1, d_02172A40, 0x6E);
    sz = func_02046C94();
    m->nA = cfg->nA;
    m->nB = cfg->nB;
    m->fA8 = cfg->f18;
    m->fAC = cfg->f1c;
    if (m->nA != 0)
        m->listA = sub_02030734(heap, cfg->nA * 20, 1, d_02172A40, 0x77);
    if (m->nB != 0)
        m->listB = sub_02030734(heap, cfg->nB * 20, 1, d_02172A40, 0x7A);
    func_0216990C((u8 *)m);
    m->f28 = cfg->f08;
    m->size = cfg->size;
    m->buf = sub_02030734(heap, cfg->size, 1, d_02172A40, 0x86);
    if (cfg->f10 == 0)
        m->f24 = 0x800;
    else
        m->f24 = cfg->f10;
    m->fD8 = cfg->f0c;
    m->head = &m->node;
    m->head->f04 = 0;
    m->f10 = 0;
    m->f84 = sub_02030734(heap, sz, 1, d_02172A40, 0x97);
    m->f88 = sub_02030734(heap, sz, 1, d_02172A40, 0x9A);
    m->f94 = 0;
    if (cfg->texSize != 0) {
        m->texSize = cfg->texSize;
        m->texKey = g_020A8140(cfg->texSize, 0, 0);
        m->plttKey = g_020A8148(0x200, 0, 0);
    } else {
        m->texSize = 0;
        m->texKey = 0;
        m->plttKey = 0;
    }
    return m;
}



extern void (*d_020A814C)(u32);



extern void (*d_020A8144)(u32);




void func_0216928C(void *p)
{
    func_021693A0((int)p);
    if (F(0x20) != 0) {
        d_020A814C(F(0x90));
        d_020A8144(F(0x8c));
    }
    func_020307B0((void *)F(0x88));
    func_020307B0((void *)F(0x84));
    func_020307B0((void *)F(0xd4));
    if (((struct Obj12384 *)p)->fA4 != 0)
        func_020307B0((void *)F(0x9c));
    if (((struct Obj12384 *)p)->fA6 != 0)
        func_020307B0((void *)F(0xa0));
    func_020307B0((void *)((u32)p));
}



/*
 * address arithmetic: unsigned 32-bit index scaling and base addition
 * preserve the original lsls/adds wraparound without an invented index bound.
 */
void func_02169308(u8 *p) { Cb cb; if (((struct Obj04162 *)p)->fB0) { cb = *(Cb *)(((struct Obj04162 *)p)->f28+((struct Obj04162 *)p)->f18*16u+4u); if(cb) cb(p,((struct Obj04162 *)p)->fD8); } }
