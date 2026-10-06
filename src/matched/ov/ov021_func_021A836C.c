/*
 * function: func_021A836C
 * address:  0x021A836C
 * packet:   pkt_ov021_021A836C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDF94     0x021DDF94  data  ov021  a1
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_020355C4  0x020355C4  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_021A8D40  0x021A8D40  thumb  ov021
 *   func_0201C440  0x0201C440  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_021A8B18  0x021A8B18  thumb  ov021
 *   func_021A8874  0x021A8874  thumb  ov021
 *   func_021A8BB8  0x021A8BB8  thumb  ov021
 *   func_02049238  0x02049238  arm
 *   func_02040588  0x02040588  arm
 *   func_021A90E0  0x021A90E0  thumb  ov021
 *   func_021A8DD8  0x021A8DD8  thumb  ov021
 *   func_020129C4  0x020129C4  thumb
 *   func_021A8E20  0x021A8E20  thumb  ov021
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0203D34C  0x0203D34C  arm
 *
 * 0x021DDF94 is the "field_menu.c" file-name string; 0x134 is its line.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Item {
    int f00;
    void *f04;
    int f08;
    void *f0C;
    void *f10;
    int f14;
    void *f18;
} Item;

typedef struct Obj {
    u16 f00;
    u16 f02;
    void *f04;
    int f08;
    int f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u16 f1C;
    u8 f1E;
    u8 f1F;
    u8 f20;
    u8 f21;
    u8 pad22[2];
    int f24;
    int f28;
    int f2C;
    int f30;
    Item items[7];
    int fF8;
    u16 fFC;
    u8 padFE[2];
    int f100;
    u8 pad104[0x124 - 0x104];
    u32 f124;
    u32 f128;
    void *f12C;
    void *f130;
    u32 f134;
} Obj;

extern char d_021DDF94[];

struct W;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct BigObj;
struct Ctx;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
struct Ctx;
extern unsigned char *func_020120F8(const struct Ctx *p);
struct Rec44;
extern unsigned short func_02012AC8(const struct Rec44 *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern u32 func_02188C54(u8 *p);
extern u8 func_020355C4(void);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_021A8D40(void *unused, struct W *w);
extern u32 func_0201C440(void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_021A8B18(void *a, void *b, u32 c);
extern void func_021A8874(struct Obj *p, void *q, int r, u32 unused);
extern void func_021A8BB8(struct Obj *p, void *q, int r);
extern void func_02049238(void *q);
extern void func_02040588(u32 which, u32 enable);
extern void func_021A90E0(struct W *w);
extern void func_021A8DD8(Obj *p);
extern u8 func_020129C4(const struct BigObj *p);
extern void func_021A8E20(struct W *w, u32 v);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0203D34C(u32 a, u32 b);

Obj *func_021A836C(u16 heap, u16 a1, int a2, void *a3, int a4)
{
    Obj *p;
    u32 x;
    u32 y;
    void *q;
    u32 r;

    p = func_02030734(heap, 0x138, 0, d_021DDF94, 0x134);
    x = (u32)func_02188C80(a3);
    y = (u32)func_020120F4((const struct Ctx *)x);
    p->f00 = heap;
    p->f02 = a1;
    p->f04 = a3;
    p->f08 = a2;
    p->f0C = 1;
    p->f1C = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)x));
    p->f14 = func_0201296C((const struct BigObj *)y);
    p->f18 = (u32)func_02012944((void *)y);
    p->f10 = func_02188C54(a3);
    p->f1E = 0;
    p->f1F = 0;
    p->f24 = p->f2C = func_020355C4() ^ 1;
    p->fF8 = 0;
    p->f130 = func_020056A0(func_021A8D40, p, 0);
    p->f12C = (void *)func_0201C440((void *)p->f00);
    p->f100 = 0;
    p->fFC = 0;
    q = func_020490F4(0x47, p->f02);
    r = func_021A8B18((void *)y, (void *)p->f14, p->f1C);
    p->f21 = r;
    func_021A8874(p, q, r, p->f10);
    func_021A8BB8(p, q, r);
    func_02049238(q);
    func_02040588(1, 1);
    if (a4 == 1) {
        p->f1E = 0;
        p->f1F = 0;
        p->f24 = 1;
        func_021A90E0((struct W *)p);
        func_021A8DD8(p);
    } else {
        func_021A8E20((struct W *)p, func_020129C4((const struct BigObj *)y));
        p->f24 = 1;
        if (p->f2C != 0) {
            func_0204B3DC((struct Obj *)p->f124, 1);
        } else {
            func_0204B3DC((struct Obj *)p->f124, 0);
        }
    }
    func_0203D34C(0, p->f02);
    return p;
}
