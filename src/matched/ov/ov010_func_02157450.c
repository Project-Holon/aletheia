/*
 * function: func_02157450
 * address:  0x02157450
 * packet:   pkt_ov010_02157450
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Create the ov010 field-effect task: allocate it with func_0215739C as
 * its callback, pick the direction slot for effect kinds 4..23 (four kinds
 * per effect, the first matching case wins), start the effect object and
 * return the task.
 *
 * symbols:
 *   func_0215739C  0x0215739C  thumb  ov010
 *   func_02157650  0x02157650  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_02013790  0x02013790  thumb
 *   func_020137C0  0x020137C0  thumb
 *   func_02013864  0x02013864  thumb
 *   func_02013894  0x02013894  thumb
 *   func_020137F0  0x020137F0  thumb
 *   func_02013128  0x02013128  thumb
 *   func_02013160  0x02013160  thumb
 *   func_02013980  0x02013980  thumb
 *   func_02034714  0x02034714  arm
 *   d_0217277C     0x0217277C  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Sub {
    u8 pad00[0x48];
    int f48;            /* 0x48 */
    int f4c;            /* 0x4C */
} Sub;

typedef struct Rec {
    void *f00;          /* 0x00 */
    u8 pad04[0x0C];
    u16 f10;            /* 0x10 */
    u8 f12;             /* 0x12 */
    u8 pad13;
    void *f14;          /* 0x14 */
    Sub f18;            /* 0x18 */
} Rec;

typedef struct Obj {
    u8 pad00[0x18];
    u16 f18;            /* 0x18 */
} Obj;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    Obj f08;            /* 0x08 */
    u8 pad[0xF8 - 0x08 - sizeof(Obj)];
    Sub *fF8;           /* 0xF8 */
} Work;

extern u8 d_0217277C[];

extern void func_0215739C(void);
extern void func_02157650(int *p, int v);
struct Ctx;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_020399A8(void);
extern void func_02013790(Obj *o, void *sys, u32 a, u32 b, u16 c);
extern void func_020137C0(Obj *o, void *sys, u32 a, u32 b, u16 c);
extern void func_02013864(Obj *o, void *sys, u32 a, u32 b, u16 c);
extern void func_02013894(Obj *o, void *sys, u32 a, u32 b, u16 c);
extern void func_020137F0(Obj *o, void *sys, u32 a, u32 b, u8 d, u16 c);
extern void func_02013128(void *p, void *src, int i);
extern void func_02013160(Obj *o, void *a, u32 b);
extern void func_02013980(Obj *o, u32 heap);
extern void func_02034714(void *a, int b, void *c);

void *func_02157450(void *a0, void *a1, u32 kind, Rec *rec)
{
    int dir = 0x29;
    void *task = func_020122C0(a0, 0, func_0215739C, 0xFC);
    Work *w = func_020124E8(task);
    Obj *o;
    void *sys;

    w->f00 = a0;
    w->f04 = a1;
    w->fF8 = &rec->f18;
    o = &w->f08;
    switch (kind) {
    case 5:
        func_02157650(&dir, 0);
    case 4:
        func_02157650(&dir, 2);
    case 7:
        func_02157650(&dir, 1);
    case 6:
        func_02157650(&dir, 3);
        sys = func_020120F4(a0);
        func_02013790(o, sys, func_020399A8(), 1, 4);
        break;
    case 9:
        func_02157650(&dir, 4);
    case 8:
        func_02157650(&dir, 6);
    case 11:
        func_02157650(&dir, 5);
    case 10:
        func_02157650(&dir, 7);
        sys = func_020120F4(a0);
        func_020137C0(o, sys, func_020399A8(), 1, 4);
        break;
    case 13:
        func_02157650(&dir, 8);
    case 12:
        func_02157650(&dir, 10);
    case 15:
        func_02157650(&dir, 9);
    case 14:
        func_02157650(&dir, 11);
        sys = func_020120F4(a0);
        func_02013864(o, sys, func_020399A8(), 1, 4);
        break;
    case 17:
        func_02157650(&dir, 12);
    case 16:
        func_02157650(&dir, 14);
    case 19:
        func_02157650(&dir, 13);
    case 18:
        func_02157650(&dir, 15);
        sys = func_020120F4(a0);
        func_02013894(o, sys, func_020399A8(), 1, 4);
        break;
    case 21:
        func_02157650(&dir, 16);
    case 20:
        func_02157650(&dir, 18);
    case 23:
        func_02157650(&dir, 17);
    case 22:
        func_02157650(&dir, 19);
        sys = func_020120F4(a0);
        func_020137F0(o, sys, func_020399A8(), 1, rec->f12, 4);
        break;
    default:
        func_02034714(d_0217277C, 0, d_0217277C);
        return 0;
    }
    func_02013128(o, rec->f00, 0);
    func_02013160(o, rec->f14, 4);
    o->f18 = rec->f10;
    w->fF8->f48 = dir;
    w->fF8->f4c = 0;
    func_02013980(o, 1);
    return task;
}
