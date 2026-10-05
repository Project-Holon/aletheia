/*
 * function: func_021D2750
 * address:  0x021D2750
 * packet:   pkt_ov021_021D2750
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spill slots follow declaration order (h, f, list, y, x, id, q, hdl, n from
 * the top down); the tail loops' counter and table pointer are block locals
 * declared j before t, which puts j in r4 and t in r5.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment (`q
 * = (Sub *)e;` before `q = &e->sub;`). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_02162744  0x02162744  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013C60  0x02013C60  thumb
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_0216E2E8  0x0216E2E8  thumb  ov010
 *   func_021A35FC  0x021A35FC  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A36BC  0x021A36BC  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0201296C  0x0201296C  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02162890  0x02162890  thumb  ov010
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_02186830  0x02186830  thumb  ov020
 *   func_02186844  0x02186844  thumb  ov020
 *   func_0218684C  0x0218684C  thumb  ov020
 *   func_0218683C  0x0218683C  thumb  ov020
 *   func_02186804  0x02186804  thumb  ov020
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V3;

typedef struct {
    u16 a;
    u16 b;
    s16 c;
} Sub;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad4[0x14];
    u32 kind;
    Sub sub;
    u16 pad22;
} Rec;

typedef struct {
    u8 pad[0xB];
    u8 w;
    u8 h;
    u8 pad2[0xF];
} Info;

typedef struct {
    u16 a;
    u16 f2;
    s16 c;
    u16 b;
    u16 f8;
} Loc;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Pos;

struct ArcFile;
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern Rec *func_02162740(u32 a);
extern u16 func_02162744(u8 *p);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C7C(unsigned char *p);
extern void *func_02188CB4(unsigned char *p);
extern u16 func_02188C9C(u8 *p);
extern int func_02013C60(u16 id);
extern int func_021A3098(void *a);
struct Record;
extern void func_0216E2E8(const char *a, u16 b, struct Record *c);
extern void func_021A35FC(void *o, s16 *z, s16 *y, s16 *x);
extern u32 func_02188CFC(u8 *p);
extern void func_021A36BC(void *o, Loc *l);
extern void *func_021A3074(unsigned char *p);
extern u32 func_0201296C(const struct BigObj *p);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void *func_02162890(u32 c, u32 a, V3 *v);
extern int *func_021867C4(int a, int id);
extern void *func_02186830(struct ArcFile **p, int b, unsigned int heap);
extern u8 *func_02186844(u8 *t, int i);
extern u8 *func_0218684C(u8 *t, int i);
extern void func_0218683C(void *p);
extern void func_02186804(void **p);

int func_021D2750(u32 a)
{
    Info info;
    V3 v;
    Loc loc;
    Pos pos;
    u32 h, f;
    Rec *list;
    void *y;
    void *x;
    void *o;
    u32 id;
    Rec *e;
    Sub *q;
    int hdl;
    int i;
    int n;
    u8 *p;
    u32 r5;
    void *r4;

    h = (u32)func_020120F4((const struct Ctx *)a);
    f = func_02012844((const struct BigObj *)h);
    list = func_02162740(f);
    n = func_02162744((u8 *)f);
    y = func_0201210C((void *)a);
    x = func_02188C7C((void *)y);
    o = func_02188CB4((void *)y);
    id = func_02188C9C(y);
    if (func_02013C60(id) == 0) {
        return 0;
    }
    if ((u32)(func_021A3098(o) - 2) <= 1) {
        return 0;
    }
    if ((list == 0 || n == 0) && id != 0 && id != 0x1A8) {
        return 1;
    }
    for (i = 0; i < n; i++) {
        e = &list[i];
        if (e->kind == 0) {
            q = &e->sub;
            func_0216E2E8(x, e->f2, (struct Record *)&info);
            func_021A35FC(o, &pos.z, &pos.y, &pos.x);
            if (e->sub.a <= pos.z && pos.z < e->sub.a + info.w) {
                if (q->b - info.h < pos.x && pos.x <= q->b) {
                    return 0;
                }
            }
        } else if (e->kind == 1) {
            q = &e->sub;
            if (func_02188CFC(y) == 1) {
                func_021A36BC(o, &loc);
                if (q->a == loc.a && q->b == loc.b && q->c == loc.c) {
                    return 0;
                }
            }
        }
    }
    if (func_02188CFC(y) == 0) {
        r4 = func_021A3074((void *)o);
        r5 = func_0201296C((const struct BigObj *)h);
        func_0216D88C(r4, (struct VecFx32 *)&v);
        if (func_02162890(f, r5, &v)) {
            return 0;
        }
    }
    if (id == 0 || id == 0x1A8) {
        int j;
        u8 *t;
        func_021A35FC(o, &pos.z, &pos.y, &pos.x);
        hdl = (int)func_021867C4(0, 0x8015);
        t = func_02186830((struct ArcFile **)hdl, id != 0, 0x8015);
        for (j = 0; j < 10; j++) {
            p = func_02186844(t, j);
            if (p[0] == pos.z && p[1] == pos.x) {
                func_0218683C(t);
                func_02186804((void **)hdl);
                return 0;
            }
        }
        for (j = 0; j < 10; j++) {
            p = func_0218684C(t, j);
            if (p[0] == pos.z && p[1] == pos.x) {
                func_0218683C(t);
                func_02186804((void **)hdl);
                return 0;
            }
        }
        func_0218683C(t);
        func_02186804((void **)hdl);
    }
    return 1;
}
