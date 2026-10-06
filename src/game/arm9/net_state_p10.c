/*
 * file:     net_state_p10.c
 * unit:     yes
 * function: func_02036E80, func_02036EC8, func_02036F04, func_02036F24, func_02036FD8, func_02037010
 * address:  0x02036E80
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02036D64  0x02036D64  arm
 *   func_0200F168   0x0200F168  thumb
 *   func_0200F16C   0x0200F16C  thumb
 *   func_020490F4   0x020490F4  arm
 *   func_02049B68   0x02049B68  arm
 *   func_02049800   0x02049800  arm
 *   func_02049238   0x02049238  arm
 *   func_020370C8  0x020370C8  arm
 *   func_02036BD4  0x02036BD4  arm
 *   g_021469C8     0x021469C8  data
 */
#include "../../matched/include/Obj06937.h"

struct Sub0200F16CHdr;
typedef unsigned int  u32;

typedef unsigned short u16;

typedef unsigned char u8;

struct Handler_02036EC8 {
    u8 unk00[0x0c]; /* 0x00 */
    u8 unk0c;       /* 0x0c */
    u8 kind;        /* 0x0d */
    u8 busy;        /* 0x0e */
};

struct Handler_02037010 {
    u32 unk00;     /* 0x00 */
    u8  pad04[9];  /* 0x04 */
    u8  kind;      /* 0x0d */
    u8  busy;      /* 0x0e */
};

struct Notifier {
    u16 unk00;                /* 0x00 */
    u16 unk02 : 14;           /* 0x02, bits 0-13 */
    u16 mode  : 2;            /* 0x02, bits 14-15 */
    struct Handler_02037010 *handler;  /* 0x04 */
};

extern u32 func_020307B0(void *p);
extern u32 func_02036D64(u8 *p);
extern u32 func_0200F168(void);
extern void func_0200F16C(struct Sub0200F16CHdr *hdr);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a0, u32 a1, void *a2, int a3, int a4, int a5);
extern void func_02049800(void *a0, u32 a1, int a2, int a3, int a4, int a5, int a6);
extern void func_02049238(void *a0);
extern void func_020370C8(void);
extern struct Handler_02037010 *func_02036BD4(u32 a, u32 b, u32 c, u32 d, u32 e,
                                     struct Handler_02037010 *f, u32 g, u32 h, u32 i);
void func_02036E80(unsigned char *p);
int func_02036F04(int a0);
void func_02036F24(int a0, int b, int c);
int func_02036FD8(void);
void func_02037010(u32 a, u32 b, u32 c, u32 d);
extern struct Notifier g_021469C8;


/*
 * Program two four-field control blocks: the base one at 0x07000000 always,
 * the second at 0x07000400 only when the byte at +0xe of the record is set.
 * Each block writes the constant 0x40000200, a zero halfword, the same
 * constant, then another zero halfword, which the compiler emits as a
 * word/halfword/word/halfword run off one base register.  The record is then
 * released through the overruled SDK address 0x020307B0 (matched), attesting
 * the PC24 site.  This function was the last blocker for
 * src/matched/func_020370C8.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036E80.c \
 *       --func func_02036E80 --addr 0x02036E80 --arm --cc 1.1p1
 */
void func_02036E80(unsigned char *p)
{
    *(volatile u32 *)0x07000000 = 0x40000200;
    *(volatile u16 *)0x07000004 = 0;
    *(volatile u32 *)0x07000008 = 0x40000200;
    *(volatile u16 *)0x0700000c = 0;
    if (p[0xe] != 0) {
        volatile u32 *q = (volatile u32 *)(0x07000000 + 0x400);
        q[0] = 0x40000200;
        *(volatile u16 *)&((struct Obj06937 *)q)->f4 = 0;
        q[2] = 0x40000200;
        *(volatile u16 *)&((struct Obj06937 *)q)->fC = 0;
    }
    func_020307B0(p);
}


/*
 * Stamp the two status bytes at +0x0d / +0x0e of the handler block, then
 * feed the result of func_02036D64 straight into func_02036F24.  The `mov
 * r1, #1` is shared between the store to +0x0e and the second argument of
 * the first call, which is why the constant is not rematerialised.  The
 * byte at +0x0c is loaded after the first call, so it is an argument
 * expression of the second call, not a value cached before it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036EC8.c \
 *       --func func_02036EC8 --addr 0x02036EC8 --cc 1.1p1 --arm
 */
void func_02036EC8(struct Handler_02036EC8 *p, u32 a, u32 b)
{
    p->kind = (a != 0) ? 1 : 2;
    p->busy = 1;

    func_02036F24(func_02036D64((u8 *)p), p->unk0c, b);
}

int func_02036F04(int a0){ int t0, t1; if ((unsigned int)(a0) == (unsigned int)(1)) { t0 = func_02080C24(); } else { t1 = func_02080C64(); }  return 0; }


void func_02036F24(int a0, int b, int c)
{
    u32 t[3];
    int q;
    int p;
    void *v;
    int idx;
    int t2;

    v = func_020490F4(func_0200F168(), (u16)((c & 0x7fff) | 0x8000));
    func_0200F16C((struct Sub0200F16CHdr *)t);
    if (a0 == 1) {
        p = 1;
        q = 0;
    } else {
        p = 5;
        q = 1;
    }
    func_02049B68(v, t[2], (void *)p, 0x1c0, 0x20, c);
    idx = (b == 0) ? 1 : 0;
    t2 = func_02036F04(a0);
    func_02049800(v, t[idx], q, t2, 0, 0, c);
    func_02049238(v);
}

int func_02036FD8(void){ int t0 = func_0207E684((int)0x20A0810, (int)0, (int)0x20); int t1 = func_0207E708((int)0x20A0810, (int)0, (int)0x20); return t1; }


/*
 * Rebuild the handler block held at +0x04 of the global at 0x021469C8 with
 * a nine-argument call to func_02036BD4 (four in registers, five on the
 * stack, which is what the 0x14-byte frame is for).  The two arms differ
 * only in the last four arguments: when a block already exists its three
 * carried fields are read out first and the old block is released by
 * func_020370C8, otherwise the mode bitfield at +0x02 is passed instead and
 * the last two arguments are the constants 0 and 3.
 *
 * The re-read of +0x04 for the sixth argument lands after the call to
 * func_020370C8, so it is a fresh load of the global, not the `h` that was
 * tested.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037010.c \
 *       --func func_02037010 --addr 0x02037010 --cc 1.1p1 --arm
 */
void func_02037010(u32 a, u32 b, u32 c, u32 d)
{
    struct Handler_02037010 *h;

    func_02036FD8();

    h = g_021469C8.handler;

    if (h != 0) {
        u8  kind;
        u32 unk00;
        u8  busy;

        busy  = h->busy;
        kind  = h->kind;
        unk00 = h->unk00;

        func_020370C8();

        g_021469C8.handler = func_02036BD4(0, d, a, b, c,
                                           g_021469C8.handler,
                                           kind, busy, unk00);
    } else {
        g_021469C8.handler = func_02036BD4(0, d, a, b, c,
                                           h, g_021469C8.mode, 0, 3);
    }
}
