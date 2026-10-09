/*
 * file:     net_state_p03.c
 * unit:     yes
 * function: func_02036B4C, func_02036B88, func_02036B98, func_02036BD4, func_02036CA8, func_02036D64, func_02036DC8, func_02036E74, func_02036E80, func_02036EC8, func_02036F04, func_02036F24, func_02036FD8, func_02037010, func_020370C8, func_020370F4, func_02037118, func_02037154, func_02037174, func_02037190, func_020371AC, func_020371D8, func_02037200, func_02037224, func_02037234, func_02037258, func_02037288, func_02037478
 * address:  0x02036B4C
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
 *   func_02030734   0x02030734  arm
 *   wm_icon_File    0x020A79F0  data
 *   g_021469C8      0x021469C8  data
 *   str_020A79F0  0x020A79F0  data
 *   str_020A79FC  0x020A79FC  data
 *   GX_GetBankForOBJ     0x02080C24  arm
 *   GX_GetBankForSubOBJ  0x02080C64  arm
 *   func_02034714        0x02034714  arm
 *   func_0200F168   0x0200F168  thumb
 *   func_0200F16C   0x0200F16C  thumb
 *   func_020490F4   0x020490F4  arm
 *   func_02049B68   0x02049B68  arm
 *   func_02049800   0x02049800  arm
 *   func_02049238   0x02049238  arm
 *   d_020A7A20   0x020A7A20  data  a1
 *   func_0203D788  0x0203D788  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203D680  0x0203D680  arm
 *   lbl_021469D0   0x021469D0  data
 *   str_020A7A24   0x020A7A24  data
 *   func_02036AF4  0x02036AF4  arm
 *   g_021469D0     0x021469D0  data
 *   str_020A7A20   0x020A7A20  data
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203640C  0x0203640C  arm
 */
#include "../../matched/include/Obj04065.h"
#include "../../matched/include/Obj15906.h"
#include "../../matched/include/Obj11350.h"
#include "../../matched/include/Obj15907.h"
#include "../../matched/include/Obj06937.h"
#include "../../matched/include/Obj05733.h"
#include "../../matched/include/Obj08828.h"

struct Sub0200F16CHdr;
struct Handler;
struct Icon;
struct Rec;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char  u8;

struct Handler {
    u32 unk00;      /* 0x00 */
    u16 unk04;      /* 0x04 */
    u16 unk06;      /* 0x06 */
    u8  pad08[4];   /* 0x08 */
    u8  unk0c;      /* 0x0c */
    u8  kind;       /* 0x0d */
    u8  busy;       /* 0x0e */
    u8  unk0f;      /* 0x0f */
    u32 unk10;      /* 0x10 */
};

struct Notifier {
    u16 unk00;                /* 0x00 */
    u16 unk02 : 14;           /* 0x02, bits 0-13 */
    u16 mode  : 2;            /* 0x02, bits 14-15 */
    struct Handler *handler;  /* 0x04 */
};

typedef int BOOL;

typedef struct {
    union {
        u32 attr01;
        struct { u16 attr0; u16 attr1; };
    };
    u16 attr2;
    u16 _3;
} GXOamAttr;

struct Icon {
    u32 f00;
    u16 f04;
    u16 f06;
    u8  pad08[7];
    u8  f0f;
    GXOamAttr *f10;
};

typedef volatile unsigned int vu32;

struct Pool_02036B4C {
    int f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    u8 pad14[4];
    void *f18;
    int f1C;
};

struct Net_02037288 {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    u8  pad1C[0x1ac - 0x1c];
    u32 f1AC;
    u8  pad1B0[0x1e0 - 0x1b0];
    u32 f1E0;
};

typedef signed int     s32;

struct Net_02037478 {
    u32  f00;
    u32 *f04;
    u8  *f08;
    u8  *f0C;
    u8  *f10;
    u8  *f14;
    u8   pad18[0x1b0 - 0x18];
    u32  f1B0;
    u32  f1B4[8];
    u8   pad1D4[0x1e0 - 0x1d4];
    u32  f1E0;
};

extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32  GX_GetBankForOBJ(void);
extern u32  GX_GetBankForSubOBJ(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02082BCC(void *dst, int val, u32 size);
extern u32 func_0200F168(void);
extern void func_0200F16C(struct Sub0200F16CHdr *hdr);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a0, u32 a1, void *a2, int a3, int a4, int a5);
extern void func_02049800(void *a0, u32 a1, int a2, int a3, int a4, int a5, int a6);
extern void func_02049238(void *a0);
extern void *func_0203D788(void);
extern u32  func_0203D6BC(void);
extern u32  func_0203D680(void);
extern void func_02036AF4(u8 *p, u32 n, u32 a, u32 b);
extern void func_0203640C(struct Rec *p, u32 a, int b);
int func_02036B4C(int a0);
void func_02036B88(void *a0);
int func_02036B98(char *p, int v);
struct Handler *func_02036BD4(u32 unused, u32 b, u32 c, u32 d, u32 e, struct Handler *h, u32 kind, u32 busy, u32 unk00);
void func_02036CA8(struct Icon *c);
u32 func_02036D64(u8 *p);
u32 func_02036DC8(u32 engine, u32 b);
struct Handler *func_02036E74(struct Handler *p, int v);
void func_02036E80(unsigned char *p);
void func_02036EC8(struct Handler *p, u32 a, u32 b);
int func_02036F04(int a0);
void func_02036F24(int a0, int b, int c);
int func_02036FD8(void);
void func_02037010(u32 a, u32 b, u32 c, u32 d);
void func_020370C8(void);
u32 func_020370F4(u32 a);
void func_02037118(u32 a, u32 b);
void func_02037154(void);
void func_02037174(void);
void func_02037190(void);
void func_020371AC(unsigned short a, unsigned short b);
void func_020371D8(u32 mode);
u32 func_02037200(void);
void func_02037224(u8 v, int b);
void func_02037234(u8 *p);
u32 func_02037258(void);
int func_02037288(u32 a0, u32 heap, u32 c);
void func_02037478(void);
extern struct Notifier g_021469C8;
extern const char wm_icon_File[];
extern const char str_020A79F0[];
extern const char str_020A79FC[];
extern u8 d_020A7A20;
extern struct Net_02037288 *lbl_021469D0;
extern char str_020A7A24[];
extern struct Net_02037478 *g_021469D0;
extern u8 str_020A7A20[];


int func_02036B4C(int a0)
{
    struct Pool_02036B4C *p = (struct Pool_02036B4C *)a0;
    void *t0 = func_02082BCC(p->f18, 0, p->f1C * 0x14);

    p->f00 = 0;
    p->f04 = 0;
    p->f08 = 0;
    p->f0C = 0;
    p->f10 = 0;
    return (int)t0;
}



void func_02036B88(void *a0){ func_020307B0((void *)((int)((struct Obj15906 *)((char *)(a0)))->f18)); }




/*
 * Scan the 0x14-stride records behind p's +0x18 pointer for one whose
 * halfword at +0x0E equals the argument; the count is p's word at +0x1C.  A
 * hit returns 1 from inside the loop (`moveq r0, #1` / `bxeq lr`), a miss
 * falls out to `mov r0, #0`.
 *
 * The three scratch registers are decided by declaration order alone: the
 * index declared first takes r2, the record cursor declared second takes r3
 * and the count declared last takes ip.  Any other order of the same three
 * declarations moves the count into r2 or the cursor into ip and misses by
 * seven instructions' worth of register names.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036B98.c \
 *       --func func_02036B98 --addr 0x02036B98 --cc 1.1p1 --arm
 */
int func_02036B98(char *p, int v)
{
    int   i;
    char *e = *(char * *)&((struct Obj11350 *)p)->f18;
    int   n = ((struct Obj11350 *)p)->f1C;

    for (i = 0; i < n; i++, e += 0x14) {
        if (((struct Obj15907 *)e)->fE == v)
            return 1;
    }
    return 0;
}




/*
 * TU: wm_icon.c.  The __FILE__ pointer at 0x020A79F0 reads "wm_icon.c"
 * (line 100 here), which names the whole 0x020366C0-0x020371AC block: the
 * wireless-connection icon.
 *
 * Nine parameters, four in registers and five on the stack, and the first
 * one is never read: every caller passes 0 there.  When the caller hands in
 * a null block, a fresh 0x14-byte one is allocated on the heap named by the
 * low 15 bits of the second argument with bit 15 forced on.  The two
 * halfwords at +0x04 / +0x06 take the caller's values unless the override
 * pair in the global at 0x021469C8 is armed, in which case the whole `if`
 * body is predicated rather than branched.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036BD4.c \
 *       --func func_02036BD4 --addr 0x02036BD4 --cc 1.1p1 --arm
 */
struct Handler *func_02036BD4(u32 unused, u32 b, u32 c, u32 d, u32 e,
                              struct Handler *h, u32 kind, u32 busy,
                              u32 unk00)
{
    if (h == 0)
        h = func_02030734((u16)(((u16)b & 0x7fff) | 0x8000), 0x14, 0,
                          wm_icon_File, 100);

    h->unk04 = c;
    h->unk06 = d;

    if (g_021469C8.unk00 != 0) {
        h->unk04 = g_021469C8.unk00;
        h->unk06 = g_021469C8.unk02;
    }

    h->unk00 = unk00;
    h->unk0c = e;
    h->busy  = busy;
    h->kind  = kind;
    h->unk0f = 0;
    h->unk10 = 0x7000000;

    func_02036F24(func_02036D64((u8 *)h), h->unk0c, (u16)b);
    return h;
}



static inline void G2_SetOBJAttr(GXOamAttr *oam, int x, int y, int priority,
                                 int mode, BOOL mosaic, int effect, int shape,
                                 int color, int charName, int cParam, int rsParam)
{
    oam->attr01 = (u32)(((y & 0xff) << 0) |
                        (mode << 10) |
                        (mosaic << 12) |
                        effect |
                        (color << 13) |
                        shape |
                        ((x & 0x1ff) << 16) |
                        (rsParam << 25));
    oam->attr2 = (u16)((charName << 0) | (priority << 10) | (cParam << 12));
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036CA8.c  *       --func func_02036CA8 --addr 0x02036CA8 --cc 1.1p1 --arm
 *
 * wm_icon.c: write the wireless icon's two 16x16 OAM entries into main
 * (0x07000000) or sub (0x07000400) OAM, and hide the pair at the previous
 * location when the engine changed.  Every store is the NitroSDK
 * G2_SetOBJAttr inline (attr01 = y | mode<<10 | mosaic<<12 | effect |
 * color<<13 | shape | x<<16 | rs<<25, attr2 = name | prio<<10 | cparam<<12):
 * entry 0 is an OBJ-window sprite (mode 2) or a NODISPLAY blank (effect
 * 0x200), entry 1 the normal sprite, palette 14.  Written through the
 * inline, the shift scheduling of docs/notes/pkt_02036CA8.c.txt (31 bytes,
 * hand-expanded) disappears.
 */
void func_02036CA8(struct Icon *c)
{
    u32 mode;
    u32 name;
    GXOamAttr *oam;

    mode = func_02036D64((u8 *)c);
    name = func_02036DC8(mode, c->f00);
    if (mode == 1) {
        oam = (GXOamAttr *)0x07000000;
    } else {
        oam = (GXOamAttr *)0x07000400;
    }
    if (c->f0f == 1) {
        G2_SetOBJAttr(&oam[0], c->f04, c->f06, 0, 2, 0, 0, 0x40000000, 0, name, 14, 0);
    } else {
        G2_SetOBJAttr(&oam[0], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
    }
    G2_SetOBJAttr(&oam[1], c->f04, c->f06, 0, 0, 0, 0, 0x40000000, 0, name, 14, 0);
    if (oam != c->f10) {
        G2_SetOBJAttr(&c->f10[0], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
        G2_SetOBJAttr(&c->f10[1], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
        c->f10 = oam;
    }
}



u32 func_02036D64(u8 *p)
{
    switch (p[0xd]) {
    case 1:
        return ((*(u16 *)0x04000304 & 0x8000) >> 15) == 1 ? 1 : 2;
    case 2:
        return ((*(u16 *)0x04000304 & 0x8000) >> 15) == 1 ? 2 : 1;
    }
    return 1;
}



/*
 * Maps the display control word of the requested engine onto the icon
 * render scale: the OBJ bank bits (20-21) and the OBJ-character mapping
 * bit (4) together pick 4x, 2x or 1x, and anything else is a fatal
 * configuration error.  The mask 0x00300010 is shared by both arms, so
 * the compiler hoists it out of the if and the DISPCNT read happens
 * inside; the switch then binary-searches the three sparse case values
 * with 0x00100010 as the middle.
 *
 * Wave 14: the balanced tree needs a FOURTH case label.  The switch is
 * over the SDK's GXOBJVRamModeChar values (1D_32K 0x10, 1D_64K 0x00100010,
 * 1D_128K 0x00200010, 1D_256K 0x00300010); 256K shares the default's
 * fatal arm, and with four labels mwcc switches from a linear chain to the
 * binary search the image has (docs/notes/pkt_02036DC8.c.txt measured
 * three labels only).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036DC8.c  *       --func func_02036DC8 --addr 0x02036DC8 --cc 1.1p1 --arm
 */
u32 func_02036DC8(u32 engine, u32 b)
{
    int m;

    if (engine == 1) {
        GX_GetBankForOBJ();
        m = *(vu32 *)0x04000000 & 0x00300010;
    } else {
        GX_GetBankForSubOBJ();
        m = *(vu32 *)0x04001000 & 0x00300010;
    }

    switch (m) {
    case 0x10:
        return b * 4;
    case 0x00100010:
        return b * 2;
    case 0x00200010:
        return b;
    case 0x00300010:
    default:
        func_02034714(str_020A79F0, 0xfb, str_020A79FC);
        return b;
    }
}


struct Handler *func_02036E74(struct Handler *p, int v)
{
    if (v < 4)
        p->unk00 = v;
    return p;
}



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
void func_02036EC8(struct Handler *p, u32 a, u32 b)
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
    struct Handler *h;

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



/*
 * Two-stage shutdown guarded on a global word: always run func_02036FD8,
 * then, only when g_021469C8.handler is set, run func_02036E80 and clear the flag.
 * func_02036E80 was the sole blocker for this file; it was matched in the
 * same wave, so its PC24 site now attests on the `matched` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020370C8.c \
 *       --func func_020370C8 --addr 0x020370C8 --arm --cc 1.1p1
 */
void func_020370C8(void)
{
    func_02036FD8();
    if (g_021469C8.handler == 0)
        return;
    func_02036E80((unsigned char *)g_021469C8.handler);
    g_021469C8.handler = 0;
}



/*
 * Forwards the argument to the handler held in the second word of the global
 * at 0x021469C8, but only when that handler is armed; an unarmed handler is
 * the `popeq` that returns 0 without touching r0.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020370F4.c \
 *       --func func_020370F4 --addr 0x020370F4 --cc 1.1p1 --arm
 */
u32 func_020370F4(u32 a)
{
    struct Handler *h;

    h = g_021469C8.handler;
    if (h == 0)
        return (u32)h;
    return (u32)func_02036E74(h, a);
}


/*
 * Notifier fan-out.  The first call is told which of two kinds of event
 * this is by testing the first argument (`movs r5, r0` sets the flags and
 * saves the argument in one instruction, which is why the ternary costs
 * nothing), and the second call only happens when the handler slot at
 * +0x04 of the global at 0x021469C8 is populated; both of this function's
 * own arguments are forwarded to it, which is what spends r5 and r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037118.c \
 *       --func func_02037118 --addr 0x02037118 --cc 1.1p1 --arm
 */
void func_02037118(u32 a, u32 b)
{
    func_020371D8(a != 0 ? 1 : 2);

    if (g_021469C8.handler != 0)
        func_02036EC8(g_021469C8.handler, a, b);
}



/*
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * `bl` to 0x02036CA8, which has no outside witness.  0x02036CA8 carries no
 * `func_` label in the listing, so the `label` class cannot reach it, and the
 * only branch to it anywhere in the image is the one inside this function, so
 * there is no second caller to attest it either.  It closes the day
 * 0x02036CA8 is matched itself (its manifest entry would then be the witness)
 * or a second caller turns up.
 *
 * Flush hook: does nothing while the handler in the second word of the global
 * at 0x021469C8 is unarmed, otherwise hands it to func_02036CA8.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02037154.c \
 *       --func func_02037154 --addr 0x02037154 --cc 1.1p1 --arm
 */
void func_02037154(void)
{
    if (g_021469C8.handler == 0)
        return;
    func_02036CA8((struct Icon *)g_021469C8.handler);
}



/*
 * Sets the flag byte at +0x0F of the armed handler, and does nothing at all
 * when the handler is not armed - the `movne`/`strbne` pair is the whole body.
 * src/matched/func_02037190.c is the same function clearing the same byte.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037174.c \
 *       --func func_02037174 --addr 0x02037174 --cc 1.1p1 --arm
 */
void func_02037174(void)
{
    u8 *q;

    q = (u8 *)g_021469C8.handler;
    if (q != 0)
        q[0x0F] = 1;
}



/*
 * Clears the flag byte at +0x0F of the armed handler; the only difference from
 * src/matched/func_02037174.c is the `movne r0, #0` instead of `#1`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037190.c \
 *       --func func_02037190 --addr 0x02037190 --cc 1.1p1 --arm
 */
void func_02037190(void)
{
    u8 *q;

    q = (u8 *)g_021469C8.handler;
    if (q != 0)
        q[0x0F] = 0;
}

void func_020371AC(unsigned short a, unsigned short b)
{
    g_021469C8.unk00 = a;
    g_021469C8.unk02 = b;
}



/*
 * Setter for the two-bit mode field in the top of the halfword at +0x02 of
 * the global at 0x021469C8.  The `lsl #0x1e` plus the `lsr #16` shifter
 * operand on the `orr` is the bitfield insert, and the `bic` of 0xc000 is
 * the field's own mask.  The `lsl #0x10 / lsr #0x10` pair above it is an
 * explicit `(u16)` cast on the stored value: declaring the parameter `u16`
 * instead drops the pair entirely (the insert already masks), so the cast
 * has to be written out.  See
 * docs/idioms/an-explicit-narrowing-cast-into-a-bitfield-is-not-folded.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020371D8.c \
 *       --func func_020371D8 --addr 0x020371D8 --cc 1.1p1 --arm
 */
void func_020371D8(u32 mode)
{
    g_021469C8.mode = (u16)mode;
}




u32 func_02037200(void)
{
    if (g_021469C8.handler == 0) {
        return 1;
    }
    return func_02036D64((u8 *)g_021469C8.handler);
}




void func_02037224(u8 v, int b)
{
    d_020A7A20 = v;
}




/*
 * Resets a sixteen-byte record: both halfwords at +8 and +0x0A become 0xFFFF
 * (the "no value" sentinel) and the words at +0 and +4 and the halfword at
 * +0x0C are cleared.  The sentinel cannot be encoded as an ARM immediate, so it
 * comes out of the function's own literal pool; the stores then run in the
 * order the source writes them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037234.c \
 *       --func func_02037234 --addr 0x02037234 --cc 1.1p1 --arm
 */
void func_02037234(u8 *p)
{
    ((struct Obj05733 *)p)->fC = 0;
    ((struct Obj05733 *)p)->f8 = 0xFFFF;
    ((struct Obj05733 *)p)->fA = 0xFFFF;
    ((struct Obj05733 *)p)->f4 = 0;
    ((struct Obj05733 *)p)->f0 = 0;
}




/*
 * The current capacity, or the measured one: when the state object's byte at
 * +0x64 is set and its halfword at +0x6C is non-zero, that halfword is the
 * answer; otherwise the two measurement calls are multiplied.
 *
 * The conjunction is the reason both loads after the first comparison are
 * conditional (`ldrhne`, `cmpne`) and the early return is a bare `popne`:
 * written as one `&&` in a single `if`, mwcc keeps the whole guard inside the
 * flags.  The product is a plain `mul`, so the function returns a 32-bit
 * value, not a narrowed one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037258.c \
 *       --func func_02037258 --addr 0x02037258 --cc 1.1p1 --arm
 */
u32 func_02037258(void)
{
    u8 *p;

    p = func_0203D788();
    if (p[0x64] != 0 && ((struct Obj08828 *)p)->f6C != 0)
        return ((struct Obj08828 *)p)->f6C;
    return func_0203D6BC() * func_0203D680();
}




/*
 * Closes the 4-byte residue docs/notes/pkt_02037288_wave25.c.txt records
 * (the `mov r3, r4` / `lsl r1, r1, #1` pair at +0x00B0).  The lever is the
 * ALLOCATION RESULT TYPE, not the size spelling: the seven pointer fields
 * are declared `void *` so each func_02030734 result is stored without an
 * integer conversion.  With them declared `u32` the file does not even
 * compile; with a cast at each site the argument scheduling shifts and the
 * 0xE8 call's size is finished before r3 is written.  The size arguments
 * themselves must stay as in-place expressions re-reading ->f1E0, never
 * bound to a local.
 *
 * The note's other two findings are confirmed and kept: the prototype
 * returns int (the tail `mov r0,#1` is a `return 1`), and the +0x1E0 store
 * is two separate `+ 0x40` adds in the two arms, not one factored add.
 */
int func_02037288(u32 a0, u32 heap, u32 c)
{
    u32 n;
    u32 m;

    if (lbl_021469D0 == 0) {
        n = func_0203D680();
        m = func_02037258();
        lbl_021469D0 = func_02030734(heap, 0x1f0, 1, str_020A7A24, 0xdd);
        if (c != 0)
            lbl_021469D0->f1E0 = m + 0x40;
        else
            lbl_021469D0->f1E0 = a0 + 0x40;

        lbl_021469D0->f14 = func_02030734(heap, lbl_021469D0->f1E0 * 3, 1,
                                          str_020A7A24, 0xe6);
        lbl_021469D0->f18 = func_02030734(heap, lbl_021469D0->f1E0 * 2, 1,
                                          str_020A7A24, 0xe8);
        lbl_021469D0->f10 = func_02030734(heap, n * lbl_021469D0->f1E0, 1,
                                          str_020A7A24, 0xe9);
        lbl_021469D0->f00 = func_02030734(heap, func_0203D6BC(), 1,
                                          str_020A7A24, 0xec);
        lbl_021469D0->f04 = func_02030734(heap, func_0203D6BC() * 15, 1,
                                          str_020A7A24, 0xed);
        lbl_021469D0->f08 = func_02030734(heap, m, 1, str_020A7A24, 0xee);
        lbl_021469D0->f0C = func_02030734(heap, m * 2, 1, str_020A7A24, 0xef);
        func_02036AF4((u8 *)lbl_021469D0 + 0xcc, 0x64,
                      (u32)((u8 *)lbl_021469D0 + 0x1c), heap);
        func_02036AF4((u8 *)lbl_021469D0 + 0xf4, 0xb4,
                      (u32)((u8 *)lbl_021469D0 + 0x3c), heap);
        lbl_021469D0->f1AC = 1;
        func_02037478();
    }
    *(u16 *)((u8 *)lbl_021469D0 + 0x100 + 0xe4) = 0;
    *((u8 *)lbl_021469D0 + 0x1e7) = 0;
    return 1;
}




/*
 * Second half of net_system init: wipe and re-seed every buffer
 * func_02037288 allocated (docs/families/net_system.h).  Closed from the
 * 520-byte / 135-out source of docs/notes/pkt_02037288_wave25.c.txt with two
 * changes:
 *   1. func_0203640C is a THREE-argument call at every site.  The first
 *      loop's "leftover" r2 is the slot stride f1E0 passed as the header's
 *      length (same finding as func_02037680); with it the file is 12 out.
 *   2. the loop index is declared FIRST, before the three counts.  With
 *      the counts first, n1 and i swap r7/r8 (the last 12 bytes).
 * The three product pairs stay spelled differently per site (n2 + n2 vs
 * n2 << 1, etc.) so the compiler rematerialises instead of CSEing them.
 */
void func_02037478(void)
{
    s32 i;
    s32 n1;
    s32 n2;
    s32 n3;

    n1 = func_0203D680();
    n2 = func_02037258();
    n3 = func_0203D6BC();

    func_02082BCC(g_021469D0->f10, 0, g_021469D0->f1E0 * n1);
    for (i = 0; i < n1; i++) {
        func_0203640C((struct Rec *)((u8 *)g_021469D0 + 0x4c + i * 16),
              (u32)(g_021469D0->f10 + i * g_021469D0->f1E0), g_021469D0->f1E0);
        ((u8 *)g_021469D0)[0x1d7 + i] = 0;
    }

    func_02082BCC(g_021469D0->f0C, 0, n2 + n2);
    func_0203640C((struct Rec *)((u8 *)g_021469D0 + 0x3c), (u32)g_021469D0->f0C, (u32)n2 << 1);
    for (i = 0; i < n2; i++)
        g_021469D0->f08[i] = 0;

    func_02082BCC((u8 *)g_021469D0->f04, 0, n3 * 16 - n3);
    func_0203640C((struct Rec *)((u8 *)g_021469D0 + 0x1c), (u32)((u8 *)g_021469D0->f04), ((u32)n3 << 4) - n3);
    *(u8 *)g_021469D0->f00 = 0xff;
    for (i = 1; i < n3; i++)
        ((u8 *)g_021469D0->f00)[i] = 0;

    func_02082BCC(g_021469D0->f14, 0, g_021469D0->f1E0 + g_021469D0->f1E0 * 2);
    func_0203640C((struct Rec *)((u8 *)g_021469D0 + 0x2c), (u32)g_021469D0->f14,
                  g_021469D0->f1E0 * 3);
    for (i = 0; i < 8; i++) {
        func_02037234((u8 *)g_021469D0 + 0x11c + i * 16);
        g_021469D0->f1B4[i] = 0;
    }
    g_021469D0->f1B0 = 0;
    func_02037234((u8 *)g_021469D0 + 0x19c);
    func_02037224(4, 0x13a);
    str_020A7A20[1] = 4;
    func_02036B4C((int)((u8 *)g_021469D0 + 0xcc));
    func_02036B4C((int)((u8 *)g_021469D0 + 0xf4));
    ((u8 *)g_021469D0)[0x1e8] = 0;
    ((u8 *)g_021469D0)[0x1eb] = 1;
    ((u8 *)g_021469D0)[0x1ea] = 0;
    ((u8 *)g_021469D0)[0x1ed] = 0;
}
