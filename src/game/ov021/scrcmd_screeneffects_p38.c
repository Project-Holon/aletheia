/*
 * file:     scrcmd_screeneffects_p38.c
 * unit:     yes
 * function: func_021B1E80, func_021B1F60, func_021B1FB8, func_021B2040, func_021B2070
 * address:  0x021B1E80
 * region:   ov021
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
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021627C8  0x021627C8  thumb  ov010
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021618A0  0x021618A0  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   d_021D93FC     0x021D93FC  data   a2
 *   d_021D9404     0x021D9404  data   a4
 *   d_021D940C     0x021D940C  data   a4
 *   d_021D9414     0x021D9414  data   a4
 *   d_021D941C     0x021D941C  data   a4
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02161AC0  0x02161AC0  thumb  ov010
 *   func_021A3238  0x021A3238  thumb  ov021
 *   func_021B1E74  0x021B1E74  thumb  ov021
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_021B83FC  0x021B83FC  thumb  ov021
 */
struct BigObj;
struct Obj00020;
struct VecFx32;
struct Ctx;
struct Rec;
struct Tri;
struct Actor;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } V;

typedef struct { u16 v[4]; } Ids;

extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern void *func_0215A5E4(void *a0);
extern void *func_0215A5DC(void *a0);
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *, struct VecFx32 *);
extern struct Rec *func_021627C8(struct Ctx *c, void *a, int key, int mode);
extern u16 func_021A3050(u8 *p);
extern void *func_021618A0(void *p, int a1, int a2, int a3);
extern void func_0215897C(void *, void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_021A3098(u8 *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_0215A5EC(void *p);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void *func_02161AC0(void *p, void *a1, struct Tri *t, void *a3);
extern int func_021A3238(u8 *p);
extern int func_021B1E74(u32 a);
extern void *func_0219E348(void *a);
extern void func_021B83FC(struct Obj *o, u16 *out0, u16 *out1, u16 *out2);
int func_021B1E80(void *a, u32 b);
int func_021B1F60(u32 a, u32 b);
int func_021B1FB8(u32 a, u32 b);
int func_021B2040(u32 a, u32 b);
int func_021B2070(u32 a, u32 b);
extern Ids d_021D93FC;
extern u8 d_021D9404[];
extern u8 d_021D940C[];
extern u8 d_021D9414[];
extern u8 d_021D941C[];


int func_021B1E80(void *a, u32 b)
{
    void *o;
    int q;
    void *e;
    void *d;
    Ids ids;
    int i;
    u32 h, f;
    void *m;
    V pos;
    int id;
    int found;
    int k;
    u8 *tbl;

    o = func_0215A5F4((void *)b);
    q = ((int *)func_02158F58((int)o))[1];
    e = func_0215A5E4((void *)b);
    d = func_0215A5DC((void *)b);
    ids = d_021D93FC;
    h = func_02012844(e);
    f = func_0201296C(e);
    m = func_02188CB4((void *)q);
    func_021A3038(m, (struct VecFx32 *)&pos);
    for (i = 0; i < 4; i++) {
        id = ids.v[i];
        if (func_021627C8((struct Ctx *)h, (void *)f, (int)(&pos), id) != 0) {
            found = id;
            break;
        }
    }
    k = func_021A3050(m);
    if (k != found) {
        if (found == 0) {
            tbl = d_021D941C;
        } else if (found == 1) {
            tbl = d_021D9414;
        } else if (found == 2) {
            tbl = d_021D940C;
        } else if (found == 3) {
            tbl = d_021D9404;
        } else {
            return 0;
        }
        func_0215897C(o, func_021618A0(d, q, 0xff, (int)tbl));
        return 1;
    }
    return 0;
}


/*
 * Each arm stores its constant through o itself; cross-jumping merges the
 * stores, leaving cases 2 and 3 branching onto case 1's branch.
 */
int func_021B1F60(u32 a, u32 b)
{
    void *x = func_02188CB4((struct Obj00020 *)((u32 *)func_02158F58((int)func_0215A5F4((void *)b)))[1]);
    u16 *o = func_02159AE8((void *)a, (void *)b);

    switch (func_021A3098(x)) {
    case 0:
        *o = 0;
        break;
    case 1:
        *o = 1;
        break;
    case 2:
        *o = 2;
        break;
    case 3:
        *o = 3;
        break;
    default:
        *o = 0;
        break;
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021B1FB8(u32 a, u32 b)
{
    int buf[3];
    int vec[3];
    void *t;
    int i;
    int x;
    int y;
    int z;
    u32 m;
    void *w;
    u32 o;

    t = func_0215A5F4((void *)b);
    i = func_02159B10((void *)a, (void *)b);
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    m = (u32)func_0215A5EC((void *)b);
    w = func_0215A5DC((void *)b);
    o = (u32)func_0216DE94((void *)m, i);
    func_0216D88C((const struct Actor *)o, (struct VecFx32 *)buf);
    vec[0] = (x << 16) + 0x8000;
    vec[1] = y << 16;
    vec[2] = (z << 16) + 0x8000;
    func_0215897C(t, func_02161AC0(w, (void *)o, (struct Tri *)buf, vec));
    return 1;
}


int func_021B2040(u32 a, u32 b)
{
    void *x = func_02188CB4((struct Obj00020 *)(((u32 *)func_02158F58((int)func_0215A5F4((void *)b)))[1]));
    u16 *o = func_02159AE8((void *)a, (void *)b);

    *o = func_021A3238(x);
    return 0;
}


int func_021B2070(u32 a, u32 b)
{
    u32 h;
    unsigned short *x;
    unsigned short *y;
    unsigned short *z;

    h = func_021B1E74(b);
    x = func_02159AE8((void *)a, (void *)b);
    y = func_02159AE8((void *)a, (void *)b);
    z = func_02159AE8((void *)a, (void *)b);
    func_021B83FC(func_0219E348((void *)h), x, y, z);
    return 0;
}
