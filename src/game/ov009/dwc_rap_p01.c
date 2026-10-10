/*
 * file:     dwc_rap_p01.c
 * unit:     yes
 * function: func_02155160, func_02155168, func_021551B0, func_021551DC, func_02155204, func_02155234, func_0215523C, func_02155244, func_02155264, func_02155280, func_0215528C, func_02155294, func_021552AC, func_021552DC, func_021552E8, func_02155330, func_02155338, func_0215536C, func_02155374, func_02155388, func_0215539C, func_021554A0, func_021554C8, func_02155648, func_02155664, func_02155674, func_02155678, func_0215568C, func_0215580C, func_02155904, func_0215592C, func_02155A80, func_02155B00, func_02155B14, func_02155B68, func_02155B98, func_02155BDC, func_02155C0C, func_02155C24, func_02155C28, func_02155C6C, func_02155C70, func_02155C8C, func_02155D2C, func_02155D3C, func_02155D7C, func_02155D80, func_02155DA4, func_02155DCC, func_02155E9C
 * address:  0x02155160
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02156DFC  0x02156DFC  thumb  ov009
 *   func_0203D798  0x0203D798  arm
 *   func_02157048  0x02157048  thumb  ov009
 *   func_02030734  0x02030734  arm
 *   d_021A8260     0x021A8260  data  ov009  a4
 *   d_021A1C4C     0x021A1C4C  data  ov009  a1
 *   func_0203D5EC 0x0203D5EC arm
 *   func_0203D610 0x0203D610 arm
 *   func_02156690  0x02156690  thumb  ov009
 *   func_02156730  0x02156730  thumb  ov009
 *   func_0215677C  0x0215677C  thumb  ov009
 *   func_020307B0  0x020307B0  arm
 *   func_021570B8  0x021570B8  thumb  ov009
 *   func_02156888  0x02156888  thumb  ov009
 *   func_021562EC  0x021562EC  thumb  ov009
 *   func_02156D84 0x02156D84 thumb ov009
 *   func_02156CAC 0x02156CAC thumb ov009
 *   func_0216B908 0x0216B908 arm ov009
 *   func_0205CCD8  0x0205CCD8  arm
 *   func_02059E38  0x02059E38  arm
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_02156DB0  0x02156DB0  thumb  ov009
 *   func_02156874 0x02156874 thumb ov009
 *   func_02156B70 0x02156B70 thumb ov009
 *   func_02156B8C 0x02156B8C thumb ov009
 *   func_02156D70 0x02156D70 thumb ov009
 *   func_02156CD0 0x02156CD0 thumb ov009
 *   g_021A1B80  0x021A1B80  data
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   d_021A1C60     0x021A1C60  data  ov009  a1
 *   func_0203D7C8  0x0203D7C8  arm
 *   func_02034714  0x02034714  arm
 *   func_020597C8  0x020597C8  arm
 *   func_02059760  0x02059760  arm
 *   func_02156C60 0x02156C60 thumb ov009
 *   func_0203D7FC 0x0203D7FC arm
 *   func_02059F18 0x02059F18 arm
 *   d_021A8264_obj 0x021A8264  data  ov009  a4
 *   d_021A1C6C     0x021A1C6C  data  ov009  a1
 *   func_0205C6AC  0x0205C6AC  arm
 *   func_0205C758  0x0205C758  arm
 *   func_0205C88C  0x0205C88C  arm
 *   func_0205CA20  0x0205CA20  arm
 *   func_0205C8E0  0x0205C8E0  arm
 *   func_0216AB20  0x0216AB20  arm
 *   func_02087C88  0x02087C88  arm
 *   func_0216B0E0  0x0216B0E0  arm
 *   func_0216AE88  0x0216AE88  arm
 *   func_0216B1E0  0x0216B1E0  arm
 *   func_02168994  0x02168994  arm
 *   func_02155F58  0x02155F58  thumb  ov009
 *   d_021A1C74     0x021A1C74  data  ov009  a1
 *   d_021A1974     0x021A1974  data  ov009  a1
 *   func_0216CA04  0x0216CA04  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02094530  0x02094530  arm
 *   func_0203F004  0x0203F004  arm
 *   func_02156C00  0x02156C00  thumb  ov009
 *   func_0203D650  0x0203D650  arm
 *   func_0216B284  0x0216B284  arm
 *   func_02177138  0x02177138  arm
 *   func_02177160  0x02177160  arm
 *   func_0216B634  0x0216B634  arm
 *   func_02177188  0x02177188  arm
 *   func_0216B65C  0x0216B65C  arm
 *   func_02156344  0x02156344  thumb  ov009
 *   func_021561C0  0x021561C0  thumb  ov009
 *   func_02082D44  0x02082D44  arm
 *   func_02176FD4  0x02176FD4  arm
 *   func_0216B838  0x0216B838  arm
 *   func_0205984C  0x0205984C  arm
 *   func_02059870  0x02059870  arm
 *   func_02177270  0x02177270  arm
 *   func_021AEF44  0x021AEF44  thumb  ov013
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_02156400  0x02156400  thumb  ov009
 *   func_0216B804  0x0216B804  arm  ov009
 *   func_0203A338  0x0203A338  arm
 */
#include "../../matched/include/Obj12254.h"
#include "../../matched/include/Obj18649.h"

struct DWCstAccUserData;
struct OSOwnerInfo;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

typedef void (*RapRecvCb)(u32, u8 *, u16);

typedef struct DwcRapWork {
    union { int hdr; u8 b[4]; } pkt;    /* 0x000 */
    u8 pktdata[0xFC];                   /* 0x004 */
    u8 *friend_list;                    /* 0x100 */
    u8 pad104[4];
    void *userdata;                     /* 0x108 */
    u8 x10C[0x174 - 0x10C];             /* 0x10C */
    void *buf[2];                       /* 0x174 */
    int arr[32];                        /* 0x17C */
    int arr2[32];                       /* 0x1FC */
    RapRecvCb cb0;                      /* 0x27C */
    RapRecvCb cb1;                      /* 0x280 */
    void (*cb284)(u32, u32);            /* 0x284 */
    u32 arg288;                         /* 0x288 */
    int (*cb28C)(u32, u32, u32, int);   /* 0x28C */
    u32 arg290;                         /* 0x290 */
    int (*cb294)(u32, u32, u32, int);   /* 0x294 */
    u32 arg298;                         /* 0x298 */
    void (*cb29C)(int, int);            /* 0x29C */
    int arg2A0;                         /* 0x2A0 */
    int (*cb2A4)(int, u32);             /* 0x2A4 */
    void (*cb2A8)(void);                /* 0x2A8 */
    char name[0x80];                    /* 0x2AC */
    u8 bytes[32];                       /* 0x32C */
    u8 ent[32][0x20];                   /* 0x34C */
    u32 w74C;                           /* 0x74C */
    int w750;                           /* 0x750 */
    int state;                          /* 0x754 */
    int err;                            /* 0x758 */
    int mode;                           /* 0x75C */
    int f760;                           /* 0x760 */
    int n;                              /* 0x764 */
    int aid;                            /* 0x768 */
    int f76c;                           /* 0x76C */
    int idx;                            /* 0x770 */
    int f774;                           /* 0x774 */
    int f778;                           /* 0x778 */
    int w77C;                           /* 0x77C */
    short s780;                         /* 0x780 */
    short s782;                         /* 0x782 */
    int cnt[3];                         /* 0x784 */
    int f790;                           /* 0x790 */
    u16 h794;                           /* 0x794 */
    u16 h796;                           /* 0x796 */
    int f798;                           /* 0x798 */
    u8 seq;                             /* 0x79C */
    u8 b79d;
    u8 b79e;
    u8 b79f;
    u8 b7a0;
    u8 b7a1;
    u8 b7a2;
    u8 b7a3;
    u8 b7a4;
    u8 b7a5;
    u8 b7a6;
    u8 b7a7;
    u8 b7a8;
    u8 b7a9;
    u8 pad7AA[2];
} DwcRapWork;

typedef struct {
    char pad0[0x56];
    u16 heap;
    char pad58[0x60 - 0x58];
    u8 b60;
} Ctx;

typedef struct {
    u16 a;
    u16 b;
    char buf[0x54];
} Req;

typedef void (*Fn)(void);

typedef struct {
    u8 language, favoriteColor, month, day;
    u16 nickName[11], nickNameLength, comment[27], commentLength;
} OSOwnerInfo;

typedef signed int     s32_021554C8;

typedef int s32_02155648;

typedef int s32;

typedef void (*Cb)(u32, u8 *, u16);

typedef struct {
    char pad[0x27c];
    Cb cb0;
    Cb cb1;
    char pad2[0x79d - 0x284];
    u8 b79d;
    char pad3[0x7a6 - 0x79e];
    u8 b7a6;
    u8 b7a7;
    u8 b7a8;
} G;

extern void func_02156DFC(int a);
void *func_0203D798(void);
void func_02157048(u32 a, u32 b);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0203D5EC(void);
extern u32 func_0203D610(void);
void func_0215677C(void);
u32 func_020307B0(void *p);
void func_021570B8(void);
int func_02156888(int a, int b, int c);
extern int func_021562EC(void);
extern int func_02156D84(void);
extern void func_02156DB0(u32 v);
extern int func_02156CAC(void);
extern int func_0216B908(void);
extern int func_0205CCD8(void);
int func_02059E38(int *a, int *b);
void func_0203C9AC(int a, u32 b, u32 c, u32 d);
u32 func_0203CA98(void);
extern unsigned char func_02156874(int);
extern s16 func_02156B70(void);
extern int func_02156B8C(void);
extern void func_02156D70(u32);
extern int func_02156CD0(void);
void *func_0203D7C8(u32 heap, u32 size, const char *file, u16 line);
void func_02034714(const char *expr, u32 line, const char *file);
int func_020597C8(struct DWCstAccUserData *userdata);
int func_02059760(struct DWCstAccUserData *userdata);
extern void func_02156C60(void);
extern void func_0203D7FC(void *);
extern void func_02059F18(void);
void func_0205C6AC(void *p, u16 a, u16 b, u16 c);
void func_0205C758(void);
int func_0205C88C(void);
int func_0205CA20(void);
void func_0205C8E0(void);
void func_0216AB20(void *a, int b, char *c, int d, int e, void *f, int g);
void func_02087C88(struct OSOwnerInfo *info);
int func_0216B0E0(u16 *ingamesn, int reserved, void (*callback)(int, int, void *), void *param);
void func_0216AE88(void);
int func_0216B1E0(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam);
int func_02168994(void (*callback)(int, void *), void *param);
int func_02155F58(void);
u8 func_0216CA04(u8 keyID, char *keyString, char *valueSrc);
void func_02082BCC(void *p, int v, int n);
u32 func_02094530(char *dst, u32 n, ...);
u32 func_0203F004(const u8 *s);
void func_02156C00(u32 a);
u32 func_0203D650(void);
int func_0216B284(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int func_02177138(int a, int b);
int func_02177160(int a, int b);
int func_0216B634(int a, int b);
int func_02177188(int a, int b);
int func_0216B65C(void);
void func_02156344(void *a);
int func_021561C0(void);
void func_02082D44(void *src, void *dst, int n);
unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size);
unsigned char func_0216B838(void);
int func_0205984C(void *userdata);
void func_02059870(int h);
int func_02177270(u8 a, int b);
int func_021AEF44(int a, int b, int c);
extern void func_02156400(void);
extern int func_0216B804(void);
extern void func_0203A338(u32);
void func_02155160(int a);
int func_02155168(int a, int b);
int func_021551B0(void (*cb)(int));
int func_021551D4(int a);
int func_021551DC(void *p);
int func_02155204(void (*cb)(int));
int func_02155234(void *a0, int n, int a2, int a3);
int func_0215523C(int a, int b, int c);
int func_02155244(int x);
int func_02155264(int a, int b, int c, void (*cb)(int));
int func_02155280(int a);
int func_0215528C(void);
int func_02155294(void);
int func_021552AC(void);
int func_021552C4(void);
int func_021552CC(void);
int func_021552D4(void);
int func_021552DC(void);
int func_021552E8(void);
void func_02155330(u32 v);
int func_02155338(int n);
s16 func_0215534C(void);
int func_02155354(void);
void func_0215535C(u32 v);
int func_02155364(void);
void *func_0215536C(void);
void func_02155374(int v);
int func_02155388(void);
int func_0215539C(int a0, int a1);
void func_021554A0(void);
int func_021554C8(void);
void func_02155648(s32_02155648 a, s32_02155648 b);
void func_02155664(void (*callback)(void));
void func_02155674(void);
u8 func_02155678(void);
int func_0215568C(void *a0, int n, int a2, int a3);
int func_0215580C(int a0, int n, int a2, int a3);
void func_02155904(void);
int func_0215592C(int a);
int func_02155A80(void *src, int len, int c);
int func_02155B00(int a, int b);
int func_02155B14(int a, int b);
void func_02155B68(void);
void func_02155B98(int a);
void func_02155BDC(unsigned int n);
void func_02155C0C(int a);
void func_02155C24(void);
void func_02155C28(s32 a, s32 b);
void func_02155C6C(void);
void func_02155C70(void);
void func_02155C8C(void);
void func_02155D2C(int e);
void func_02155D3C(int a, int b, int c, int d, int e);
int func_02155D7C(void);
void func_02155D80(int a, u32 i);
void func_02155DA4(unsigned int v);
void func_02155DCC(u32 a, u8 *p, int c);
void func_02155E9C(int a, int b, int c, u32 d);
extern int *d_021A8260;
extern char d_021A1C4C[];
extern DwcRapWork *d_021A8264;
extern char g_021A1B80[];
extern char d_021A1C5C[];
extern char d_021A1C60[];
extern char d_021A8264_obj[];
extern char d_021A1C6C[];
extern char d_021A1C74[];
extern char d_021A1974[];
extern u8 *g_021A8264;





















void func_02155160(int a)
{
    func_02156DFC(a);
}





















int func_02155168(int a, int b)
{
    int p;

    if (d_021A8260 != 0)
        return 0;
    p = (int)func_0203D798();
    func_02157048(((struct Obj12254 *)p)->f58, ((struct Obj12254 *)p)->f48);
    d_021A8260 = func_02030734(a, 8, 1, d_021A1C4C, 0xba);
    *d_021A8260 = b;
    return 1;
}




















int func_021551B0(void (*cb)(int))
{
    u32 a;
    int r;
    a = func_0203D5EC();
    r = func_0215539C(a, func_0203D610());
    if (cb) cb(1);
    return r;
}




















int func_021551D4(int a)
{
    return func_0215592C(a);
}




















/*
 * Null-pointer guard through func_02156690, then either func_02156730 or func_0215592C.
 */
int func_021551DC(void *p)
{
    int func_02156690(int);
    int func_02156730(void);
    int func_0215592C(int a);
    int t;
    if (p == 0) t = 1;
    else t = 0;
    if (func_02156690(t)) {
        func_02156730();
        return 1;
    }
    func_0215592C((int)p);
    return 1;
}



















int func_02155204(void (*cb)(int))
{
    if (d_021A8260 != 0) {
        func_0215677C();
        if (cb != 0)
            cb(1);
        func_020307B0(d_021A8260);
        d_021A8260 = 0;
    }
    func_021570B8();
    return 1;
}




















int func_02155234(void *a0, int n, int a2, int a3)
{
    return func_0215568C(a0, n, a2, a3);
}



















int func_0215523C(int a, int b, int c)
{
    return func_02156888(a, b, c);
}




















int func_02155244(int x)
{
    int func_02156690(int);
    int func_02156730(void);
    int t;
    if (x == 0) t = 1;
    else t = 0;
    if (func_02156690(t)) {
        func_02156730();
        return 1;
    }
    return 0;
}



















int func_02155264(int a, int b, int c, void (*cb)(int))
{
    if (func_02155B14(a, b)) {
        if (cb) cb(1);
        return 1;
    }
    return 0;
}



















/*
 * Calls func_02155648 on the argument twice and returns 1.
 */
int func_02155280(int a)
{
    func_02155648(a, a);

    return 1;
}



















int func_0215528C(void)
{
    return func_02155388();
}


















/*
 * False when the word call returns -1.
 */
int func_02155294(void)
{
    if (func_021562EC() != -1) {
        return 1;
    }

    return 0;
}


















/*
 * Follower func_021552C4 resolves through the verified ov009 02156CAC leaf;
 * ov010's same-address allocator is a different function.
 */
int func_021552AC(void)
{
    int r;
    r = func_02156D84();
    if (!func_02155388()) r |= 1;
    return r;
}


















int func_021552C4(void)
{
    return func_02156CAC();
}


















int func_021552CC(void)
{
    return func_0216B908();
}


















int func_021552D4(void)
{
    return func_021562EC();
}



















/*
 * Returns three less the word the ARM tail-call function at 0x0205CCD8 returns.
 */
int func_021552DC(void)
{
    return 3 - func_0205CCD8();
}



















int func_021552E8(void)
{
    int a, b, r;

    r = func_02059E38(&a, &b);
    if (r != 0)
        func_0203C9AC(a, b, r, 0);
    if (r == 0)
        return 0;
    if (a == 0)
        return -10000;
    r = ((int *)func_0203CA98())[3];
    if (r == 0)
        r = a;
    return r;
}


















void func_02155330(u32 v)
{
    func_02156DB0(v);
}
















/*
 * Follower func_0215535C resolves through the verified existing 02156CF4
 * unit after its function inventory was corrected to include 02156D70.
 */
int func_02155338(int n)
{
    if (func_02156874(n) == 6) return 1;
    return 0;
}
















s16 func_0215534C(void)
{
    return func_02156B70();
}
















int func_02155354(void)
{
    return func_02156B8C();
}
















void func_0215535C(u32 v)
{
    func_02156D70(v);
}
















int func_02155364(void)
{
    return func_02156CD0();
}

















/*
 * Address of the module state object.
 */
void *func_0215536C(void)
{
    return g_021A1B80;
}

















/*
 * Stores a word at +0x754 of the block the pointer holds.
 */
void func_02155374(int v)
{
    d_021A8264->state = v;
}

















/*
 * True when the block pointer is set.
 */
int func_02155388(void)
{
    return ((char *)d_021A8264) != 0;
}

















/*
 * Allocates the 0x7AC-byte ov009 work block into d_021A8264 (asserting it
 * was empty) and initialises it.  func_0203D7C8's last two arguments look
 * like a file/line pair (d_021A1C60, 302).
 */
int func_0215539C(int a0, int a1)
{
    Ctx *ctx;
    int i;

    ctx = func_0203D798();
    if (d_021A8264 != 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    d_021A8264 = func_0203D7C8(ctx->heap, sizeof(DwcRapWork), d_021A1C60, 302);
    for (i = 0; i < 32; i++)
        d_021A8264->arr[i] = -1;
    func_02155374(0);
    d_021A8264->w77C = 0;
    d_021A8264->idx = -1;
    d_021A8264->n = ctx->b60;
    d_021A8264->f774 = -1;
    d_021A8264->s782 = 0;
    d_021A8264->b79e = 0;
    d_021A8264->h794 = 1;
    d_021A8264->f790 = 1;
    d_021A8264->h796 = 1;
    d_021A8264->userdata = (void *)a0;
    d_021A8264->friend_list = (u8 *)a1;
    d_021A8264->b7a1 = 1;
    for (i = 0; i < 32; i++)
        d_021A8264->bytes[i] = 0;
    if (func_020597C8((struct DWCstAccUserData *)d_021A8264->userdata) == 0)
        return 1;
    if (func_02059760((struct DWCstAccUserData *)d_021A8264->userdata) == 0)
        return 2;
    return 0;
}
















/*
 * func_02156C60 receives the preceding call's live r0 result; its older
 * source declares no arguments. This caller preserves that register payload.
 */
void func_021554A0(void)
{
    if (d_021A8264) {
        func_0203D798();
        func_02156C60();
        func_0203D7FC(d_021A8264);
        d_021A8264 = 0;
    }
    func_02059F18();
}
















/*
 * checks: 1 SDK bodies confirm arities and payloads, case6 returns observed r0=0x3EF; 2 ov009 neighbours no complete twin; 3 u16/u8 flag both unchanged DIFF10; 4 block-local u16 name[2]={0,0} fixes address lifetime, MATCH384; 5 fresh idioms/neighbours and stack-storage idiom reread.
 * EXACT after verified ov009 leaves02155C24/02155C6C attest +170/+178. TU suggest-split diagnostic completed before leaf shards: MATCH, no viable cut. Prior once300 consumed, never repeated.
 * Fresh retry: 10 one runs plus TU; assignment-return85, constant local return10, raw name/pair/union and flag widths10; initializer closes concrete bytes. No volatile or input-domain restriction.
 */
int func_021554C8(void)
{
    OSOwnerInfo info;
    void *m;
    int flag;
    int ret;

    switch (d_021A8264->state) {
    case 0:
        func_0203D798();
        func_0205C6AC(d_021A8264->x10C, 2, 1, 0x14);
        func_0205C758();
        func_02155374(1);
        d_021A8264->f76c = 0;
    case 1:
        if (func_0205C88C() != 0) {
            if (func_0205CA20() == 4)
                func_02155374(2);
            else
                func_02155374(14);
        } else {
            func_0205C8E0();
            break;
        }
    case 2:
        ret = func_02155F58();
        if (ret != 0)
            return ret;
        flag = 0;
        m = d_021A8264->friend_list;
        if (m != 0)
            flag = 0x20;
        func_0216AB20(d_021A8264->userdata, 0x2FC6, d_021A1C6C, 0, 0, m, flag);
        d_021A8264->b7a9 = 1;
        { u16 name[2] = {0, 0};
        func_02087C88((struct OSOwnerInfo *)(&info));
        func_0216B0E0(name, 0, (void (*)(int,  int,  void *))((Fn)func_02155B98), 0);
        }
        func_02155374(3);
    case 3:
        func_0216AE88();
        break;
    case 4:
        if (d_021A8264->friend_list != 0) {
            if (func_0216B1E0(0, func_02155C0C, d_021A8264->userdata,
                              func_02155C24, d_021A8264_obj, func_02155C28,
                              d_021A8264_obj) == 0) {
                func_0203C9AC(0, 0, 0, 0x3EE);
            } else {
                func_02168994((void (*)(int,  void *))func_02155C6C, 0);
                func_0216AE88();
            }
        }
        func_02155374(5);
        break;
    case 5:
        func_0216AE88();
        if (d_021A8264->friend_list == 0)
            func_02155374(6);
        break;
    case 6:
        func_0216AE88();
        { int code = 0x3EF; d_021A8264->err = code; return code; }
    }
    return func_02155F58();
}
















/*
 * Stores two words at +0x27C and +0x280 of the block the module pointer holds.
 */
void func_02155648(s32_02155648 a, s32_02155648 b)
{
    d_021A8264->cb0 = (RapRecvCb)a;
    d_021A8264->cb1 = (RapRecvCb)b;
}















/*
 * evidence: caller ov099021BEEC4 BL targets this word-run start; full
 *   Thumb decode stores the original callback R0 at global +0x2a4 and returns.
 */
void func_02155664(void (*callback)(void))
{
    d_021A8264->cb2A4 = (int (*)(int, u32))callback;
}














/*
 * Unlabelled leaf (no lr save, so disasm.py never labels it); its address
 * is taken as a callback by func_0215568C / func_0215580C.
 */
void func_02155674(void)
{
}















/*
 * Unlabelled leaf (no lr save, so disasm.py prints it as .word data); its
 * address is taken as a callback by func_02156888 / func_0215568C.
 */
u8 func_02155678(void)
{
    return d_021A8264->b7a5;
}















/*
 * Sibling of func_0215580C: in state 6, formats a 0x80-byte name at +0x2AC,
 * resets n slots, enters state 7 and hands func_0216B284 (mode 2) and three
 * registrars the ov009 callbacks.
 *
 * The four callback leaves it passes were unlabelled; their own EXACT
 * shards (wave 2) witness them.
 */
int func_0215568C(void *a0, int n, int a2, int a3)
{
    int i;

    if (d_021A8264 == 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (d_021A8264->state != 6)
        return 0;
    func_02156C60();
    if (func_0216CA04(0, d_021A1C74, a0) == 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    func_02082BCC(d_021A8264->name, 0, 0x80);
    func_02094530(d_021A8264->name, (u32)d_021A1974, d_021A1C74, a0);
    if ((int)func_0203F004((const u8 *)d_021A8264->name) >= 0x80)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (a2)
        func_0216CA04(1, d_021A8264->name, d_021A8264->name);
    for (i = 0; i < n; i++)
        func_02156C00(i);
    func_02155374(7);
    d_021A8264->n = n;
    if (func_0216B284(2, n, d_021A8264->name, (Fn)func_02155D3C,
                      (void *)func_0203D650(), func_02155674,
                      (void *)func_0203D650(), (Fn)func_02155D7C,
                      (void *)func_0203D650(), (Fn)func_02155678,
                      &d_021A8264->w750, (void *)func_0203D650()) == 0)
        return 0;
    d_021A8264->mode = 0;
    func_02177138((int)((Fn)func_02155D80), 0);
    func_02177160((int)((Fn)func_02155DCC), 0);
    func_0216B634((int)((Fn)func_02155E9C), 0);
    func_02177188((int)((Fn)func_02155BDC), 0);
    d_021A8264->f760 = 0;
    d_021A8264->b7a1 = 1;
    return 1;
}















/*
 * In state 6 of the ov009 work block: resets n slots, enters state 7 and
 * hands func_0216B284 and three registrars the ov009 callbacks.
 *
 * The two callback leaves it passes were unlabelled; their own EXACT
 * shards (wave 2) witness them.
 */
int func_0215580C(int a0, int n, int a2, int a3)
{
    int i;

    if (d_021A8264 == 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (d_021A8264->state != 6)
        return 0;
    func_02156C60();
    for (i = 0; i < n; i++)
        func_02156C00(i);
    func_02155374(7);
    d_021A8264->n = n;
    if (func_0216B284(1, n, (char *)a0, (Fn)func_02155D3C, 0, func_02155674, 0, (void *)a2, (void *)a3,
                      0, 0, 0) == 0)
        return 0;
    d_021A8264->mode = 0;
    func_02177138((int)((Fn)func_02155D80), 0);
    func_02177160((int)((Fn)func_02155DCC), 0);
    func_0216B634((int)((Fn)func_02155E9C), 0);
    func_02177188((int)((Fn)func_02155BDC), 0);
    d_021A8264->f760 = 0;
    d_021A8264->b7a1 = 1;
    d_021A8264->err = 0x3EF;
    return 1;
}














/*
 * Sets 0xd through func_02155374 when the word at +0x754 is 0xc, else 0xb.
 */
void func_02155904(void)
{
        void func_02155374(int v);
    if (d_021A8264->state == 0xc) {
        func_02155374(0xd);
        return;
    }
    func_02155374(0xb);
}












static inline int SetErr(int e)
{
    d_021A8264->err = e;
    return e;
}












int func_0215592C(int a)
{
    func_02155B68();
    switch (d_021A8264->state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return func_021554C8();
    case 7:
        if (a != 0)
            func_02155374(8);
        if (d_021A8264->mode == 2 && d_021A8264->idx >= 0
            && d_021A8264->bytes[d_021A8264->idx] != 6)
            func_02155374(12);
        break;
    case 8:
    case 12:
        func_0216B65C();
        func_02155904();
        break;
    case 9: {
        u8 *p = func_0203D798();
        if (d_021A8264->s782 != 0)
            func_02156344((void *)(((struct Obj18649 *)p)->f56));
        d_021A8264->h794 = 0;
        func_02155374(10);
        return SetErr(1000);
    }
    case 11:
        func_02155374(6);
        d_021A8264->f760 = 0;
        d_021A8264->f774 = -1;
        return SetErr(0x3e9);
    case 13:
        func_02155374(6);
        d_021A8264->f760 = 0;
        d_021A8264->f774 = -1;
        return SetErr(0x3ea);
    case 14:
        return func_02155F58();
    case 18:
        if (d_021A8264->f76c == 0) {
            func_0216B65C();
            func_02155374(0x13);
            break;
        }
    case 6: {
        int r = func_021561C0();
        if (r == 0)
            return SetErr(0x3ef);
        return r;
    }
    }
    return func_021561C0();
}












int func_02155A80(void *src, int len, int c)
{
    int r;

    if (len >= 0x100)
        return 0;
    if (d_021A8264->f760 != 0)
        return 0;
    d_021A8264->pkt.hdr = c | (d_021A8264->h794 << 8);
    d_021A8264->seq = d_021A8264->seq + 1;
    d_021A8264->pkt.b[2] = d_021A8264->seq;
    func_02082D44(src, d_021A8264->pktdata, len);
    d_021A8264->f760 = 1;
    r = (u16)func_0216B908();
    if (r != func_02176FD4(r, d_021A8264, len + 4)) {
        d_021A8264->f760 = 0;
        return 0;
    }
    return 1;
}












/*
 * Flag test on the three-argument call.
 */
int func_02155B00(int a, int b)
{
    if (func_02155A80((void *)a, b, 3) != 0) {
        return 1;
    }

    return 0;
}










int func_02155B14(int a, int b)
{
    if (d_021A8264->b7a6 == 0)
        return 0;
    if (func_02155A80((void *)a, b, 1) == 0)
        return 0;
    d_021A8264->b7a6 = 0;
    if (d_021A8264->cb1 != 0) {
        int r = func_0216B838();
        d_021A8264->cb1(r, (u8 *)a, (u16)b);
    }
    return 1;
}








void func_02155B68(void)
{
    int value;
    if (d_021A8264->b7a7) {
        value = 0;
        if (func_02155B00((int)&value, 4))
            d_021A8264->b7a7 = 0;
    }
}








void func_02155B98(int a)
{
    if (func_0205984C((void *)d_021A8264->userdata) != 0) {
        func_02059870((int)d_021A8264->userdata);
        d_021A8264->b7a2 = 1;
    }
    if (a == 0)
        func_02155374(4);
    else
        func_02155374(14);
}








void func_02155BDC(unsigned int n)
{
    if (n < 2 && d_021A8264->b7a8) {
        func_0216B65C();
        d_021A8264->f774 = -1;
        func_02155374(20);
    }
}









void func_02155C0C(int a)
{
    if (a == 0) {
        func_02155374(6);
        return;
    }

    func_02155374(0xe);
}








/*
 * Unlabelled empty callback leaf for func_021554C8. Reads no arguments.
 */
void func_02155C24(void)
{
}









/*
 * Stores a and b into every one of 0x20 slots at +0x17C and +0x1FC whose first word is -1.
 */
void func_02155C28(s32 a, s32 b)
{
    s32 i;

    func_0203D798();
    for (i = 0; i < 0x20; i++) {
        if (d_021A8264->arr[i] == -1) {
            d_021A8264->arr[i] = a;
            d_021A8264->arr2[i] = b;
        }
    }
}








void func_02155C6C(void)
{
}







/*
 * Clears the eight bytes at +0x784 of the block the module pointer holds.
 */
void func_02155C70(void)
{
    func_02082BCC(((char *)d_021A8264) + 0x784, 0, 8);
}







void func_02155C8C(void)
{
    int i, j;

    for (i = 0; i < 2; i++)
        func_02177270(i, 0);
    if (func_0216B838() == 0) {
        for (j = 0; j < d_021A8264->n; j++) {
            if (j != func_0216B838() && (func_0216B908() & (1 << j)) != 0) {
                if (func_02177270(j, 10000) == 0)
                    func_02034714(d_021A1C5C, 0, d_021A1C5C);
            }
        }
    } else {
        if (func_02177270(0, 10000) == 0)
            func_02034714(d_021A1C5C, 0, d_021A1C5C);
    }
    d_021A8264->b7a8 = 1;
    func_02155C70();
}







/*
 * Enables slot 9 then calls the wakeup.
 */
void func_02155D2C(int e)
{
    func_02155374(9);
    func_02155C8C();
}





void func_02155D3C(int a, int b, int c, int d, int e)
{
    DwcRapWork *g;

    if (a == 0) {
        if (b == 0)
            func_02155D2C(e);
        else
            func_02155904();
    } else {
        func_02155374(14);
    }
    g = d_021A8264;
    if (g->cb29C != 0) {
        int r = func_0216B838();
        d_021A8264->cb29C(r, g->arg2A0);
    }
}




/*
 * Unlabelled leaf (no lr save, so disasm.py never labels it); its address
 * is taken as a callback by func_0215568C / func_0215580C.
 */
int func_02155D7C(void)
{
    return 1;
}





/*
 * Unlabelled leaf (no lr save, so disasm.py prints it as .word data); its
 * address is taken as a callback by func_02156888 / func_0215568C.
 */
void func_02155D80(int a, u32 i)
{
    if (i < 2) {
        d_021A8264->f760 = 0;
        d_021A8264->cnt[i] = 0;
    }
}


void func_02155DA4(unsigned int v)
{
    if (v & 0x100) {
        d_021A8264->f790 = 1;
    } else {
        d_021A8264->f790 = 0;
    }
}



void func_02155DCC(u32 a, u8 *p, int c)
{
    u32 x = p[0] | ((p[3] << 24) | (p[2] << 16) | (p[1] << 8));

    if (a >= 2)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (a < 2) {
        d_021A8264->b7a8 = 1;
        if ((u8)x == 1) {
            func_02155DA4(x);
            d_021A8264->b79d = p[2];
            d_021A8264->b7a7 = 1;
        } else if ((u8)x == 3) {
            d_021A8264->b7a6 = 1;
            return;
        } else {
            if (func_021AEF44(a, (int)p, c) == 0)
                return;
            return;
        }
        if (func_0216B838() == 0) {
            if (d_021A8264->cb0 != 0)
                d_021A8264->cb0(a, p + 4, (u16)(c - 4));
        } else {
            if (d_021A8264->cb1 != 0)
                d_021A8264->cb1(a, p + 4, (u16)(c - 4));
        }
    }
}



void func_02155E9C(int a, int b, int c, u32 d)
{
    if (d < 2) {
        *(u32 *)(g_021A8264 + 0x760) = 0;
        *(u32 *)(g_021A8264 + 0x78c) = 0;
        *(u32 *)(g_021A8264 + 0x778) = 0;
        if (a == 0) {
            if (g_021A8264[0x7a1] == 1 && func_0216B804() == 1) {
                if (*(u32 *)(g_021A8264 + 0x754) != 8) {
                    func_02155374(0x12);
                }
                if (*(u32 *)(g_021A8264 + 0x76c) != 0) {
                    func_02156400();
                }
            }
            if (b == 0) {
                func_02155374(0x12);
            }
        }
        if (g_021A8264[0x7a3] != 0) {
            u32 *q = (u32 *)func_0203CA98();
            if (q[3] == 0) {
                func_0203C9AC(q[0], q[1], q[2], 0x3f1);
            }
        }
        func_0203A338(d);
        {
            void (*cb)(u32, u32) = *(void (**)(u32, u32))(g_021A8264 + 0x284);
            if (cb != 0) {
                cb(d, *(u32 *)(g_021A8264 + 0x288));
            }
        }
    }
}
