/*
 * function: func_021F7544
 * address:  0x021F7544
 * packet:   pkt_ov094_021F7544
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the two func_021F6B04 calls and the two f244 stores are written per arm;
 *           the compiler tail-merges them, which is what keeps the 0x194-based
 *           offsets and the reload of &d_0220AF20 seen in the listing.
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_020307B0  0x020307B0  arm
 *   d_0220AF20     0x0220AF20  data   a4
 *   d_0220AC90     0x0220AC90  data   a1
 *   func_021F93F4  0x021F93F4  thumb  ov094
 *   func_02021518  0x02021518  thumb
 *   func_02021EE4  0x02021EE4  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_021FEAC0  0x021FEAC0  thumb  ov094
 *   func_02048F60  0x02048F60  arm
 *   func_021F6560  0x021F6560  thumb  ov094
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   func_021F6B04  0x021F6B04  thumb  ov094
 *   func_0201493C  0x0201493C  thumb
 *   func_02046A94  0x02046A94  arm
 *   func_021F6E3C  0x021F6E3C  thumb  ov094
 *   func_02201A8C  0x02201A8C  thumb  ov094
 *   func_02206BC8  0x02206BC8  thumb  ov094
 *   func_02209224  0x02209224  thumb  ov094
 *   func_0220975C  0x0220975C  thumb  ov094
 *   func_021FF16C  0x021FF16C  thumb  ov094
 *   func_02050B80  0x02050B80  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02006674  0x02006674  thumb
 *   func_021F8B90  0x021F8B90  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    int f0;          /* 0x00 */
    int f4;          /* 0x04 */
    int f8;          /* 0x08 */
    int fc;          /* 0x0c */
    u8 f10;          /* 0x10 */
    u8 f11;          /* 0x11 */
    u16 f12;         /* 0x12 */
    u8 f14;          /* 0x14 */
    u8 f15;          /* 0x15 */
    char pad16[0x28 - 0x16];
    void *battle;    /* 0x28 */
} Param;

typedef struct {
    void *owner;     /* 0x000 */
    void *buf;       /* 0x004 */
    char pad08[0x188 - 8];
    void *h188;      /* 0x188 */
    int h18c;        /* 0x18c */
    void *h190;      /* 0x190 */
    void *h194;      /* 0x194 */
    void *h198;      /* 0x198 */
    void *h19c;      /* 0x19c */
    void *h1a0;      /* 0x1a0 */
    void *h1a4;      /* 0x1a4 */
    char pad1a8[8];
    void *h1b0;      /* 0x1b0 */
    void *h1b4;      /* 0x1b4 */
    void *h1b8;      /* 0x1b8 */
    Param param;     /* 0x1bc */
    int f1e8;        /* 0x1e8 */
    char pad1ec[4];
    u16 heap;        /* 0x1f0 */
    char pad1f2[6];
    int slots[8];    /* 0x1f8 */
    char pad218[0x244 - 0x218];
    int f244;        /* 0x244 */
    int f248;        /* 0x248 */
} Work;

typedef struct {
    u8 f0;
    u8 f1;
    u8 a2[0x13 - 2];
    u8 a13[0x24 - 0x13];
} Entry;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u16 w;
} Rect;

extern Work *d_0220AF20;
extern const char d_0220AC90[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern unsigned func_02030CB0(unsigned);
struct Ctx;
struct Res;
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_020307B0(void *);
extern void *func_021F93F4(void *a, u32 b);
struct Obj02021EE4;
struct PalAnmSlot;
extern void *func_02021518(u32 heap);
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void *func_021FEAC0(int mode, void *a1, u16 a2);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern void *func_021F6560(int, u8, u8, u16);
extern int func_021BA1A8(char **p, int m);
extern void *func_021F6B04(int unused, int group, u8 variant, u16 heap);
extern void func_0201493C(u32 id, u32 a1, u32 a2, u32 a3, u32 b0, u16 *b1, u16 heap);
extern void func_02046A94(u8, const Rect *);
extern void *func_021F6E3C(void *a, u16 b);
extern struct Res *func_02201A8C(void *owner, u16 heap);
extern void *func_02206BC8(int, u16);
extern void *func_02209224(u16 heap);
extern void *func_0220975C(void *a, u16 heap);
extern void func_021FF16C(void *);
extern void func_02050B80(u32);
extern void *func_020056A0(void (*cb)(void), void *ctx, int pri);
extern void func_02006674(int n, u32 heap);
extern void func_021F8B90(void);

void func_021F7544(Param *p, int arg, u16 heap)
{
    Work *w;
    Entry *tbl;
    u8 v;
    int i;
    Rect r;
    u16 out[10];

    w = sub_02030734(heap, sizeof(Work), 1, d_0220AC90, 0x116);
    d_0220AF20 = w;
    w->param = *p;
    w->heap = heap;
    d_0220AF20->buf = sub_02030734(heap, func_02030CB0(0x20), 1, d_0220AC90, 0x11c);
    d_0220AF20->owner = func_02030CBC(0x20, d_0220AF20->buf);
    d_0220AF20->h188 = func_021F93F4(d_0220AF20->owner, heap);
    d_0220AF20->h18c = (int)func_02021518(heap);
    func_02021EE4((struct Obj02021EE4 *)d_0220AF20->h18c, 1);
    func_0202155C((struct PalAnmSlot *)d_0220AF20->h18c, 0, 0x200, heap);
    func_0202155C((struct PalAnmSlot *)d_0220AF20->h18c, 1, 0x1e0, heap);
    func_0202155C((struct PalAnmSlot *)d_0220AF20->h18c, 2, 0x200, heap);
    func_0202155C((struct PalAnmSlot *)d_0220AF20->h18c, 3, 0x1e0, heap);
    v = 0;
    d_0220AF20->h190 = func_021FEAC0(p->f0, d_0220AF20->owner, heap);
    tbl = func_02048F60(0x98, 0, (u16)((d_0220AF20->heap & 0x7fff) | 0x8000));
    if (tbl[p->f8].f1 != 0) {
        v = p->f11;
    }
    d_0220AF20->h194 = func_021F6560(p->f0, tbl[p->f8].a13[p->fc], v, heap);
    if (d_0220AF20->param.battle != 0) {
        d_0220AF20->h198 = func_021F6B04(func_021BA1A8(d_0220AF20->param.battle, 0x400), tbl[p->f8].a2[p->fc], v, heap);
    } else {
        d_0220AF20->h198 = func_021F6B04(0, tbl[p->f8].a2[p->fc], v, heap);
    }
    if (tbl[p->f8].f0 != 0) {
        func_0201493C(p->f12, p->f14, p->f15, p->f10, p->f11, out, d_0220AF20->heap);
        r.w = out[0];
        r.x = 0;
        r.y = -0x1000;
        r.z = 0;
        func_02046A94(0, &r);
    }
    func_020307B0(tbl);
    d_0220AF20->h19c = func_021F6E3C(d_0220AF20->owner, heap);
    d_0220AF20->h1a0 = func_02201A8C(d_0220AF20->owner, heap);
    d_0220AF20->h1a4 = func_02206BC8(arg, heap);
    d_0220AF20->h1b0 = func_02209224(heap);
    d_0220AF20->h1b4 = func_0220975C(d_0220AF20->owner, heap);
    func_021FF16C(d_0220AF20->h190);
    func_02050B80(heap);
    for (i = 0; i < 8; i++) {
        d_0220AF20->slots[i] = -1;
    }
    if (d_0220AF20->param.battle != 0) {
        if (func_021BA1A8(d_0220AF20->param.battle, 0x800)) {
            d_0220AF20->f244 = 300;
        } else {
            d_0220AF20->f244 = 900;
        }
    }
    d_0220AF20->h1b8 = func_020056A0(func_021F8B90, 0, 1);
    func_02006674(2, d_0220AF20->heap);
}
