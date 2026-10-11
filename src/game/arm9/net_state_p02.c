/*
 * file:     net_state_p02.c
 * unit:     yes
 * function: func_0203675C, func_020367C4, func_020368C0, func_020369C8, func_020369F8, func_02036A50, func_02036AF4, func_02036B4C, func_02036B88, func_02036B98, func_02036BD4, func_02036CA8, func_02036D64, func_02036DC8, func_02036E74, func_02036E80, func_02036EC8, func_02036F04, func_02036F24, func_02036FD8, func_02037010, func_020370C8, func_020370F4, func_02037118, func_02037154, func_02037174, func_02037190, func_020371AC, func_020371D8, func_02037200, func_02037224, func_02037234, func_02037258, func_02037288, func_02037478, func_02037680, func_02037700, func_0203778C, func_020377AC
 * address:  0x0203675C
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
 *   func_020364D4  0x020364D4  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02036670   0x02036670  arm
 *   func_0203660C   0x0203660C  arm
 *   func_02036428   0x02036428  arm
 *   func_0203666C   0x0203666C  arm
 *   func_02034714   0x02034714  arm
 *   g_020A79C4      0x020A79C4  data
 *   g_020A79D0      0x020A79D0  data
 *   g_020A79D4      0x020A79D4  data
 *   str_020A79C4  0x020A79C4  data
 *   str_020A79EC  0x020A79EC  data
 *   func_020366FC 0x020366FC  arm
 *   func_02082BCC   0x02082BCC  arm
 *   func_02030734 0x02030734  arm
 *   wm_icon_File    0x020A79F0  data
 *   g_021469C8      0x021469C8  data
 *   str_020A79F0  0x020A79F0  data
 *   str_020A79FC  0x020A79FC  data
 *   GX_GetBankForOBJ     0x02080C24  arm
 *   GX_GetBankForSubOBJ  0x02080C64  arm
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
 *   str_020A7A24   0x020A7A24  data
 *   g_021469D0     0x021469D0  data
 *   str_020A7A20   0x020A7A20  data
 *   func_0203640C  0x0203640C  arm
 *   str_020A7A34   0x020A7A34  data
 *   func_0203D798  0x0203D798  arm
 *   g_020387A0     0x020387A0  data
 *   func_020380E4  0x020380E4  arm
 */
#include "../../matched/include/Obj04748.h"
#include "../../matched/include/Obj11349.h"
#include "../../matched/include/Obj08825.h"
#include "../../matched/include/Obj08826.h"
#include "../../matched/include/Obj04065.h"
#include "../../matched/include/Obj15906.h"
#include "../../matched/include/Obj11350.h"
#include "../../matched/include/Obj15907.h"
#include "../../matched/include/Obj06937.h"
#include "../../matched/include/Obj05733.h"
#include "../../matched/include/Obj08828.h"
#include "../../matched/include/Obj15915.h"

struct Sub0200F16CHdr;
struct Handler;
struct Icon;
struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            BOOL;

typedef struct {
    u8  *src;       /* +0x00 */
    u32  pad4;
    u32  pad8;
    u16  rest;      /* +0x0C */
    u16  fE;
    u8   f10;
    u8   headerDone;/* +0x11 */
} NetSendItem;

typedef struct {
    u8  *ptr;       /* +0x00 */
    u16  len;       /* +0x04 */
} NetOutBuf;

typedef struct Node020368C0 {
    u32 f0;
    struct Node020368C0 *f4;
    struct Node020368C0 *f8;
    u16 fC;
    u16 fE;
    u8 f10;
    u8 f11;
} Node020368C0;

typedef struct Queue020368C0 {
    Node020368C0 *f0;
    Node020368C0 *f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
} Queue020368C0;

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

typedef signed int     s32;

struct NetRing {
    u8  pad00[8];
    u32 state;          /* 0x08 */
    u8  pad0C[4];
};

/* The object g_021469D0 points at (0x1f0 bytes, allocated by func_02037288). */
struct Net {
    u8  *f00;           /* 0x00 */
    u8  *f04;
    u8  *f08;
    u8  *f0C;
    u8  *f10;
    u8  *f14;
    u8  *f18;
    struct NetRing f1C;
    struct NetRing f2C;
    struct NetRing f3C;
    struct NetRing f4C[8];
    u8  fCC[0x28];
    u8  fF4[0x28];
    u8  f11C[8][16];
    u8  f19C[16];
    u32 f1AC;
    int f1B0;
    int f1B4[8];
    u8  f1D4;
    u8  f1D5;
    u8  f1D6;
    u8  f1D7[8];
    u8  pad1DF;
    u32 f1E0;
    u16 f1E4;
    u8  pad1E6;
    u8  f1E7;
    u8  f1E8;
    u8  f1E9;
    u8  f1EA;
    u8  f1EB;
    u8  f1EC;
    u8  f1ED;
    u8  pad1EE[2];
};

struct Ctx {
    u8   pad00[0x64];
    u8   f64;          /* 0x64 */
    u8   pad65[0x6c - 0x65];
    u16  f6c;          /* 0x6c */
    u8   pad6e[0x340 - 0x6e];
    u32 *f340;         /* 0x340 */
    u32  pad344[2];    /* 0x344, 0x348 */
    u32  f34c;         /* 0x34c */
};

struct Oth {
    u8  pad0[0x56];
    u16 f56;           /* 0x56 */
};

extern int func_020364D4(char *p, unsigned char *dst, int len, int max);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern Node020368C0 *func_02036670(Queue020368C0 *q, u32 a1, u32 a2, u32 a3);
extern u32 func_0203660C(u32 h);
extern void func_02036428(u32 h, u32 a2, u32 a3);
extern void func_0203666C(u32 h);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020366FC(u32 *p);
extern void *func_02082BCC(void *dst, int val, u32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32  GX_GetBankForOBJ(void);
extern u32  GX_GetBankForSubOBJ(void);
extern u32 func_0200F168(void);
extern void func_0200F16C(struct Sub0200F16CHdr *hdr);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a0, u32 a1, void *a2, int a3, int a4, int a5);
extern void func_02049800(void *a0, u32 a1, int a2, int a3, int a4, int a5, int a6);
extern void func_02049238(void *a0);
extern void *func_0203D788(void);
extern u32  func_0203D6BC(void);
extern u32  func_0203D680(void);
extern void func_0203640C(struct Rec *p, u32 a, int b);
extern void *func_0203D798(void);
int func_0203675C(int a0, int a1);
int func_020367C4(NetSendItem *item, NetOutBuf *out, void *ring, BOOL needHeader);
int func_020368C0(Queue020368C0 *q, u16 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
u32 func_020369C8(u32 *p);
void func_020369F8(u8 *p);
int func_02036A50(u32 list, u16 *info);
void func_02036AF4(u8 *p, u32 n, u32 a, u32 b);
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
void func_02037680(int i);
int func_02037700(u32 a0, u32 a1);
u32 func_0203778C(u32 p);
extern u32 func_020380E4(u32 a0, u8 *rec, u32 len);
u32 func_020377AC(u32 a0, u8 *rec, u32 len);
extern char g_020A79C4[];
extern char g_020A79D0[];
extern char g_020A79D4[];
extern const u8 str_020A79C4[];
extern const u8 str_020A79EC[];
extern struct Notifier g_021469C8;
extern const char wm_icon_File[];
extern const char str_020A79F0[];
extern const char str_020A79FC[];
extern u8 d_020A7A20;
extern char str_020A7A24[];
extern struct Net *g_021469D0;
extern u8 str_020A7A20[];
extern const u8 str_020A7A34[];
extern u8   g_020387A0[];




int func_0203675C(int a0, int a1){ int t0, t1, t2, t3, t4; t0 = func_02036738((int)a1, (int)((((struct Obj04748 *)((char *)(a0)))->fE >> 8) & 0xff), (int)((struct Obj04748 *)((char *)(a0)))->fE); t1 = func_02036738((int)a1, (int)(((struct Obj04748 *)((char *)(a0)))->fE & 0xff)); t2 = func_02036738((int)a1, (int)((((struct Obj04748 *)((char *)(a0)))->fC >> 8) & 0xff)); t3 = func_02036738((int)a1, (int)(((struct Obj04748 *)((char *)(a0)))->fC & 0xff)); t4 = func_02036738((int)a1, (int)((struct Obj04748 *)((char *)(a0)))->f10); return 0; }





/*
 * Moves one queued send item into an output window: on first touch writes
 * the item's five-byte header (func_0203675C, refused with 0 when a header
 * is required and the window cannot hold rest + 5), then copies as much of
 * the payload as fits -- from the item's own source pointer with
 * MI_CpuCopy8, or out of the ring with func_020364D4 when it has none.  A
 * partial copy leaves the window marked full (0xFFFF) and the item's
 * header flag set; a complete one advances the window.  Exact on the first
 * compile from the image's field widths.
 */
int func_020367C4(NetSendItem *item, NetOutBuf *out, void *ring, BOOL needHeader)
{
    if (item->headerDone == 0) {
        if (needHeader != 0 && out->len < item->rest + 5) {
            return 0;
        }
        func_0203675C((int)item, (int)out);
    }
    if (out->len < item->rest) {
        if (item->src == 0) {
            func_020364D4(ring, out->ptr, out->len, out->len);
        } else {
            MI_CpuCopy8(item->src, out->ptr, out->len);
            item->src += out->len;
        }
        item->rest = item->rest - out->len;
        out->len = 0xffff;
        item->headerDone = 1;
        return 1;
    }
    if (item->src == 0) {
        func_020364D4(ring, out->ptr, item->rest, item->rest);
    } else {
        MI_CpuCopy8(item->src, out->ptr, item->rest);
    }
    out->ptr += item->rest;
    out->len = out->len - item->rest;
    return 1;
}





/*
 * blocked:  own-pool - the only pooled words naming g_020A79D0 (0x020A79D0 "0")
 *           and g_020A79D4 (0x020A79D4 "(u16)size < (0xffff/2)") sit inside this
 *           function's own pool at 0x020369BC/0x020369C4; every other witness is
 *           inside 0x020368C0..0x020369C8, so the two ABS32 fields stay wildcarded.
 *           g_020A79C4 ("net_queue.c") does have 10 outside witnesses (literal class).
 *           Verified byte-correct otherwise: 264/264, 0 concrete bytes differ.
 */
int func_020368C0(Queue020368C0 *q, u16 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6)
{
    Node020368C0 *n = func_02036670(q, a1, a2, a3);

    if (n == 0) {
        func_02034714(g_020A79C4, 0xdb, g_020A79D0);
        return 0;
    }
    if (!((u16)a3 < 0xffff / 2)) {
        func_02034714(g_020A79C4, 0xdf, g_020A79D4);
    }
    if (a5 != 0) {
        if (!((int)(a3 + 5) < (int)func_0203660C(q->f14))) {
            func_02034714(g_020A79C4, 0xe3, g_020A79D0);
            return 0;
        }
        func_02036428(q->f14, a2, a3);
        func_0203666C(q->f14);
        n->f0 = 0;
    } else {
        n->f0 = a2;
    }
    n->fC = a3;
    n->fE = a1;
    n->f10 = a6;
    n->f11 = 0;
    if (q->f4 == 0) {
        q->f4 = n;
        q->f0 = n;
    } else {
        q->f4->f8 = n;
        n->f4 = q->f4;
        q->f4 = n;
    }
    return 1;
}





/*
 * First non-null of three words of a queue owner: the word at +0x10, then the
 * word at +0, then the word at +8.  The first two arms load into r1 and only
 * move the answer into r0 on the taken path (`movne r0, r1`); the third arm
 * loads straight into r0, so its null case is the single `moveq r0, #0` that
 * the source's trailing `return 0;` produces.  Both taken arms branch on the
 * compare itself (`bxne lr`) instead of jumping to the shared epilogue.
 *
 * Written with three separate `if (...) return ...;` statements rather than a
 * chain of `?:`: the compiler rejects the GNU `?:` extension outright
 * (CCERR), and the merged `if` chain (`if (a) return a; if (b) return b;
 * return c;`) is 36 bytes and folds the third test away.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020369C8.c \
 *       --func func_020369C8 --addr 0x020369C8 --cc 1.1p1 --arm
 */
u32 func_020369C8(u32 *p)
{
    if (p[4] != 0)
        return p[4];
    if (p[0] != 0)
        return p[0];
    if (p[2] != 0)
        return p[2];
    return 0;
}





/*
 *           the file string at 0x020A79C4 is not NUL-terminated immediately
 *           before this message, so the `string` class refuses. Every concrete
 *           byte of the body reproduces.
 */
void func_020369F8(u8 *p)
{
    if (((struct Obj11349 *)p)->f10 != 0) {
        ((struct Obj11349 *)p)->f10 = 0;
        return;
    }
    if (func_020366FC((u32 *)p) != 0) {
        return;
    }
    if (func_020366FC((u32 *)(p + 8)) != 0) {
        return;
    }
    func_02034714((char *)((const char *)str_020A79C4), 0x12f, (char *)((const char *)str_020A79EC));
}





/*
 *           unlabelled work not in the slice and itself only called from here)
 *           and func_020367C4 (pkt_020367C4, not this lane's).  Filing
 *           func_020369F8 would still leave func_020367C4 unwitnessed, so the
 *           park is capped either way.
 *
 * Byte-identical at 164 bytes; only the two PC24 call fields at +0x40 and
 * +0x54 stay wildcarded (func_020369C8 resolves `matched`, func_02082BCC
 * resolves `label x566`).
 *
 * Spellings that mattered: every `return 1` must be a `goto` to one label at
 * the END of the function -- plain `return`s make mwcc predicate all three of
 * them inline (`moveq r0,#1; popeq`) and the frame shifts by 25 bytes.  And
 * `flag = 1;` sits BEFORE the 0xFFFF test, which is why the original shows
 * `mov r8,r6` between the `ldrh` and the `cmp`.
 */
int func_02036A50(u32 list, u16 *info)
{
    int flag = 0;

    if (info[2] == 0)
        goto done;
    while (1) {
        int slot = func_020369C8((u32 *)list);

        if (slot == 0)
            goto done;
        func_020369F8((u8 *)list);
        if (func_020367C4((NetSendItem *)slot, (NetOutBuf *)info, (void *)(((struct Obj08825 *)list)->f14), flag) == 0) {
            ((struct Obj08825 *)list)->f10 = slot;
            goto done;
        }
        flag = 1;
        if (info[2] == 0xffff) {
            ((struct Obj08825 *)list)->f10 = slot;
            return 0;
        }
        func_02082BCC((void *)slot, 0, 0x14);
        if (info[2] == 0)
            break;
    }
done:
    return 1;
}




void func_02036AF4(u8 *p, u32 n, u32 a, u32 b)
{
    func_02082BCC(p, 0, 0x28);
    ((struct Obj08826 *)p)->f18 = (u32)func_02030734(b, n * 0x14, 1, (const char *)str_020A79C4, 0x173);
    ((struct Obj08826 *)p)->f1C = n;
    ((struct Obj08826 *)p)->f14 = a;
}




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

    if (g_021469D0 == 0) {
        n = func_0203D680();
        m = func_02037258();
        g_021469D0 = func_02030734(heap, 0x1f0, 1, str_020A7A24, 0xdd);
        if (c != 0)
            g_021469D0->f1E0 = m + 0x40;
        else
            g_021469D0->f1E0 = a0 + 0x40;

        g_021469D0->f14 = func_02030734(heap, g_021469D0->f1E0 * 3, 1,
                                          str_020A7A24, 0xe6);
        g_021469D0->f18 = func_02030734(heap, g_021469D0->f1E0 * 2, 1,
                                          str_020A7A24, 0xe8);
        g_021469D0->f10 = func_02030734(heap, n * g_021469D0->f1E0, 1,
                                          str_020A7A24, 0xe9);
        g_021469D0->f00 = func_02030734(heap, func_0203D6BC(), 1,
                                          str_020A7A24, 0xec);
        g_021469D0->f04 = func_02030734(heap, func_0203D6BC() * 15, 1,
                                          str_020A7A24, 0xed);
        g_021469D0->f08 = func_02030734(heap, m, 1, str_020A7A24, 0xee);
        g_021469D0->f0C = func_02030734(heap, m * 2, 1, str_020A7A24, 0xef);
        func_02036AF4(g_021469D0->fCC, 0x64,
                      (u32)&g_021469D0->f1C, heap);
        func_02036AF4(g_021469D0->fF4, 0xb4,
                      (u32)&g_021469D0->f3C, heap);
        g_021469D0->f1AC = 1;
        func_02037478();
    }
    g_021469D0->f1E4 = 0;
    g_021469D0->f1E7 = 0;
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
        func_0203640C((struct Rec *)&g_021469D0->f4C[i],
              (u32)(g_021469D0->f10 + i * g_021469D0->f1E0), g_021469D0->f1E0);
        g_021469D0->f1D7[i] = 0;
    }

    func_02082BCC(g_021469D0->f0C, 0, n2 + n2);
    func_0203640C((struct Rec *)&g_021469D0->f3C, (u32)g_021469D0->f0C, (u32)n2 << 1);
    for (i = 0; i < n2; i++)
        g_021469D0->f08[i] = 0;

    func_02082BCC(g_021469D0->f04, 0, n3 * 16 - n3);
    func_0203640C((struct Rec *)&g_021469D0->f1C, (u32)g_021469D0->f04, ((u32)n3 << 4) - n3);
    *g_021469D0->f00 = 0xff;
    for (i = 1; i < n3; i++)
        g_021469D0->f00[i] = 0;

    func_02082BCC(g_021469D0->f14, 0, g_021469D0->f1E0 + g_021469D0->f1E0 * 2);
    func_0203640C((struct Rec *)&g_021469D0->f2C, (u32)g_021469D0->f14,
                  g_021469D0->f1E0 * 3);
    for (i = 0; i < 8; i++) {
        func_02037234(g_021469D0->f11C[i]);
        g_021469D0->f1B4[i] = 0;
    }
    g_021469D0->f1B0 = 0;
    func_02037234(g_021469D0->f19C);
    func_02037224(4, 0x13a);
    str_020A7A20[1] = 4;
    func_02036B4C((int)g_021469D0->fCC);
    func_02036B4C((int)g_021469D0->fF4);
    g_021469D0->f1E8 = 0;
    g_021469D0->f1EB = 1;
    g_021469D0->f1EA = 0;
    g_021469D0->f1ED = 0;
}




/*
 * Reset one net_system slot (docs/families/net_system.h).  The 8-byte
 * "colouring" residue of docs/notes/pkt_02037288_wave25.c.txt was a wrong
 * reading of the callee's argument list: func_0203640C here takes THREE
 * arguments, (header, buffer, length), and r2 at the call is the slot
 * stride f1E0 passed on purpose as the buffer length, not a leftover of
 * the mla.  The slot header is initialised to { f10 + i * f1E0, f1E0 }.
 */
void func_02037680(int i)
{
    if (i >= 8) {
        func_02034714((const char *)str_020A7A24, 0x155, (const char *)str_020A7A34);
    }
    g_021469D0->f1B4[i] = 0;
    func_0203640C((struct Rec *)&g_021469D0->f4C[i], (u32)(g_021469D0->f10 + i * g_021469D0->f1E0), g_021469D0->f1E0);
    g_021469D0->f1D7[i] = 0;
    func_02037234(g_021469D0->f11C[i]);
}




/*
 * Filed on lane 1 as the single-caller callee of src/pending/func_0203C864.c.
 * The 0x340 field is a table of function pointers reached through two
 * indirect calls; the third reaches a slot at +0x68 past two unread words at
 * +0x44 and +0x48, which is why the struct keeps them as padding.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037700.c \
 *       --func func_02037700 --addr 0x02037700 --cc 1.1p1 --arm
 */
int func_02037700(u32 a0, u32 a1)
{
    struct Oth *o = (struct Oth *)func_0203D798();
    struct Ctx *c = func_0203D788();
    u32 flag = 0;

    if (c->f64 != 0 && c->f6c != 0)
        flag = 1;
    func_02037288(a0, a1, flag);
    ((void (*)(u16, struct Ctx *, u32, u32))c->f340[1])(o->f56, c, 0, c->f34c);
    ((void (*)(u32))c->f340[2])(0);
    ((void (*)(u8 *))c->f340[0x68 / 4])(g_020387A0);
    return 1;
}




/*
 * 32-byte hook dispatcher: func_0203D788 returns the current context, whose
 * word at +0x340 names a vtable whose slot +0x90 is called with the incoming
 * argument.  The call is a real `blx r1` and not a tail call because r4 has to
 * be restored afterwards, which is what makes it `return f(p)` and not a
 * `bx`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203778C.c \
 *       --func func_0203778C --addr 0x0203778C --cc 1.1p1 --arm
 */
u32 func_0203778C(u32 p)
{
    char *c = func_0203D788();
    u32 (*f)(u32) = *(u32 (**)(u32))(*(char * *)&((struct Obj15915 *)c)->f340 + 0x90);

    return f(p);
}

u32 func_020377AC(u32 a0, u8 *rec, u32 len)
{
    return func_020380E4(a0, rec, len);
}
