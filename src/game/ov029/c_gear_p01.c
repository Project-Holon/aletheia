/*
 * file:     c_gear_p01.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFEE4, func_021EFEF8, func_021EFF00, func_021EFF58, func_021F0000, func_021F0064, func_021F009C, func_021F0194, func_021F020C, func_021F0298, func_021F0300, func_021F0370, func_021F0390, func_021F05B4, func_021F05D0, func_021F06B8, func_021F0728, func_021F07AC, func_021F07EC, func_021F0824, func_021F0858, func_021F088C, func_021F08BC, func_021F09B4, func_021F09DC, func_021F0A0C
 * address:  0x021EFEC0
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F0D14  0x021F0D14  thumb  ov029
 *   func_0204B878  0x0204B878  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_0204B49C  0x0204B49C  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B918  0x0204B918  arm
 *   func_0204B8F4  0x0204B8F4  arm
 *   func_0204B98C 0x0204B98C arm
 *   func_021F2B9C  0x021F2B9C  thumb  ov029
 *   d_021F333C     0x021F333C  data  a4
 *   d_021F334C     0x021F334C  data  a4
 *   func_021F0CA0  0x021F0CA0  thumb  ov029
 *   func_021F0D10  0x021F0D10  thumb  ov029
 *   d_021F31BC     0x021F31BC  data  ov029  a2
 *   d_021F31AB     0x021F31AB  data  ov029  a1
 *   d_021F31B0     0x021F31B0  data  ov029  a1
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_02158630  0x02158630  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021F31EC     0x021F31EC  data  ov029  a4
 *   d_021F31F8     0x021F31F8  data  ov029  a4
 *   func_021F0CB8  0x021F0CB8  thumb  ov029
 *   func_021F0CDC  0x021F0CDC  thumb  ov029
 *   func_021F0CF0  0x021F0CF0  thumb  ov029
 *   func_021F0D00  0x021F0D00  thumb  ov029
 *   func_021F0D08  0x021F0D08  thumb  ov029
 *   d_021F3255     0x021F3255  data  ov029  a1
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021F3292 0x021F3292 data ov029 a1
 *   d_021F3204 0x021F3204 data ov029 a1
 *   func_020215BC  0x020215BC  thumb
 *   d_021F31A8     0x021F31A8  data  ov029  a1
 *   func_021F0AC8 0x021F0AC8 thumb ov029
 */
#include "../../matched/include/Obj09784.h"
#include "../../matched/include/Obj05112.h"
#include "../../matched/include/Obj03631.h"

struct Owner;
struct Actor;
struct Obj;
struct W;
struct Ctx;
struct BigObj;
struct PalAnmSlot;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

struct Slot {
    void *obj;
    int a;
    int b;
};

struct Pt {
    s16 x;
    s16 y;
    u16 w;
    u8 z;
    u8 t;
};

struct Owner {
    unsigned char pad[0x3c];
    struct Slot s[20];
};

struct Pair {
    int a;
    int b;
};

struct E {
    u8 b[10];
};

struct W {
    u8 pad0[0x210];
    int unk_210;
    u8 pad1[0x1c];
    u16 unk_230[3][5];
    u16 unk_24E[3][5];
    u16 unk_26C[3];
    u16 unk_272[1][5];
};

extern void func_021F0D14(int a, int b, int *x, int *y);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B49C(struct Actor *actor, s16 value, u32 space, u32 axis);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u16 func_0204B918(struct Obj *p);
extern u32 func_0204B8F4(struct Obj *p);
extern u32 func_0204B98C(struct Actor *a);
extern u32 func_021F2B9C(u8 *p, int row, int col);
extern void func_021F0CA0(void *e, u16 a, u8 b, u8 c);
extern void func_021F0D10(char *p, char v);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_0201058C(void *key);
extern int func_02158630(int);
extern void func_021F0CB8(unsigned char *p);
extern int func_021F0CDC(unsigned short *p, int i);
extern void func_021F0CF0(unsigned char *p, int i);
extern void func_021F0D00(unsigned short *p, int i);
extern unsigned short func_021F0D08(unsigned short *p, int i);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern void func_021F0AC8(unsigned char *p, int a, int b);
int func_021EFEC0(int a, int b);
void func_021EFEE4(unsigned char *p, unsigned int v);
void func_021EFEF8(char *p, void (*f)(void), int line);
void func_021EFF00(int x, int y, int *a, int *b);
void func_021EFF58(u8 *p, int a, int c);
struct Slot *func_021F0000(struct Owner *p);
int func_021F0064(unsigned char *p, int a, int b);
int func_021F009C(u8 *p);
void func_021F0194(u8 *p);
int func_021F020C(const void *p, int a, int b, int *c, int *d);
void func_021F0298(u8 *p);
void func_021F0300(u8 *p);
void func_021F0370(void *p);
void func_021F0390(u8 *p, int a, int b, int c, int e);
int func_021F05B4(unsigned char *p);
void func_021F05D0(u8 *p);
void func_021F06B8(u8 *p, int a, int b);
void func_021F0728(u8 *p);
void func_021F07AC(u8 *p, int i, u16 *e);
void func_021F07EC(void *p, int i, unsigned short *q);
void func_021F0824(void *p, int i, unsigned short *q);
void func_021F0858(void *p, int i, unsigned short *q);
void func_021F088C(void *p, int i, unsigned short *q);
void func_021F08BC(struct W *p, int i, int j, int k);
void func_021F09B4(unsigned char *p, unsigned char *q, int n);
int func_021F09DC(unsigned char *p, int i, int v, int a, int b, int j);
void func_021F0A0C(unsigned char *p);
extern struct Pair d_021F333C;
extern struct Pair d_021F334C;
extern u16 d_021F31BC[];
extern u8 d_021F31AB[];
extern u8 d_021F31B0[];
extern const u32 d_021F31EC[];
extern const int d_021F31F8[];
extern u8 d_021F3255[];
extern unsigned char d_021F3292[];
extern unsigned char d_021F3204[];
extern const u8 d_021F31A8[];

int func_021EFEC0(int a, int b)
{
    if (a % 2 == 0) {
        if (b < 3)
            return 1;
    } else {
        if (b < 4)
            return 1;
    }
    return 0;
}

void func_021EFEE4(unsigned char *p, unsigned int v)
{
    ((struct Obj09784 *)p)->f0 = v;
    p[0x456] = 0;
    p[0x455] = 0;
}


/*
 * evidence: func_021EFEE4 is ov029's own code (a store leaf ending in bx lr
 * after the bx lr at 0x021EFEE0), inside ov029's window, so only ov029 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov029's own listing.
 *
 * `line`: every caller loads r2 with a constant, but the callee never
 * reads it, so the thunk takes it and drops it.
 */
void func_021EFEF8(char *p, void (*f)(void), int line)
{
    func_021EFEE4((unsigned char *)p, (int)f);
}

void func_021EFF00(int x, int y, int *a, int *b)
{
    int m = x % 2;

    if (m == 0) {
        a[0] = x;
        b[0] = y - 1;
        a[1] = x;
        b[1] = y + 1;
        a[2] = x + 1;
        b[2] = y;
        a[3] = x + 1;
        b[3] = y - 1;
        a[4] = x - 1;
        b[4] = y;
        a[5] = x - 1;
        b[5] = y - 1;
    } else {
        a[0] = x;
        b[0] = y - 1;
        a[1] = x;
        b[1] = y + 1;
        a[2] = x + 1;
        b[2] = y;
        a[3] = x + 1;
        b[3] = y + 1;
        a[4] = x - 1;
        b[4] = y;
        a[5] = x - 1;
        b[5] = y + 1;
    }
}


void func_021EFF58(u8 *p, int a, int c)
{
    struct Pt s;
    int x;
    int y;
    struct Slot *sl;

    func_021F0D14(a, c, &x, &y);
    s.x = x * 8 + 16;
    s.y = y * 8 + 16;
    s.w = p[0x414] + 10;
    s.z = 0;
    s.t = 2;
    sl = func_021F0000((struct Owner *)p);
    if (sl->obj != 0) {
        func_0204B878(sl->obj, s.w);
        func_0204B9A0(sl->obj);
        func_0204B49C(sl->obj, s.x, 0, 0);
        func_0204B49C(sl->obj, s.y, 0, 1);
    } else {
        sl->obj = func_0204B294((void *)((struct Obj05112 *)p)->f34, ((struct Obj05112 *)p)->f2C, ((struct Obj05112 *)p)->f28, ((struct Obj05112 *)p)->f30, &s, 0, ((struct Obj05112 *)p)->fC);
        func_0204B92C(sl->obj, 1);
        func_0204B3DC(sl->obj, 1);
    }
    sl->a = a;
    sl->b = c;
}


struct Slot *func_021F0000(struct Owner *p)
{
    int best = -1;
    int bestSub = -1;
    int idx = 0;
    int i;
    int pri;
    int sub;

    for (i = 0; i < 20; i++) {
        if (p->s[i].obj == 0) {
            return &p->s[i];
        }
        pri = func_0204B918(p->s[i].obj);
        sub = func_0204B8F4(p->s[i].obj);
        if (pri > best || (pri == best && sub > bestSub)) {
            best = pri;
            bestSub = sub;
            idx = i;
        }
    }
    return &p->s[idx];
}

int func_021F0064(unsigned char *p, int a, int b)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (*(int *)(p + i * 12 + 0x3c) != 0 && *(int *)(p + i * 12 + 0x40) == a && *(int *)(p + i * 12 + 0x44) == b) {
            if (func_0204B98C((struct Actor *)(*(int *)(p + i * 12 + 0x3c))) != 0) return 0;
        }
    }
    return 1;
}


int func_021F009C(u8 *p)
{
    int y;
    int x;
    int k;
    u8 *q;
    int xs[6];
    int ys[6];

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 9; x++) {
            q = p + y + x * 4;
            if (q[0x3f0] == 4 && func_021F0064(p, x, y) != 0) {
                q[0x3f0] = 5;
            }
            if (q[0x3f0] == 2) {
                func_021EFF58(p, x, y);
                q[0x3f0] = 3;
            }
        }
    }
    p[0x415]++;
    if (p[0x415] >= 16) {
        return 1;
    }
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 9; x++) {
            q = p + y + x * 4;
            if (q[0x3f0] == 3) {
                q[0x3f0] = 4;
                func_021EFF00(x, y, xs, ys);
                for (k = 0; k < 6; k++) {
                    if (xs[k] >= 0 && xs[k] < 9 && ys[k] >= 0 && ys[k] < 4) {
                        q = p + xs[k] * 4 + ys[k];
                        if (q[0x3f0] == 1) {
                            q[0x3f0] = 2;
                        } else if (q[0x3f0] == 0) {
                            q[0x3f0] = 3;
                        }
                    }
                }
            }
        }
    }
    return 0;
}


void func_021F0194(u8 *p)
{
    int v;
    int j;
    int i;

    v = func_021F2B9C(p, p[0x452], p[0x453]);
    p[0x414] = v;
    i = 0;
    p[0x415] = i;
    for (; i < 4; i++) {
        for (j = 0; j < 9; j++) {
            if (v == func_021F2B9C(p, j, i)) {
                p[0x3f0 + j * 4 + i] = 1;
            }
        }
    }
    (p + p[0x452] * 4 + p[0x453])[0x3f0] = 2;
    func_021F009C(p);
}


/*
 * note 2026-10-05 (wD6 lane14): closed by reusing parameter a for x (the early
 * `adds r4,r1,#0` copy), b for the b/8 - lo[m] intermediate, and two 8-byte
 * struct copies of the tables (ldm r5,{r3,r5}).
 */
int func_021F020C(const void *p, int a, int b, int *c, int *d)
{
    int y;
    struct Pair lo;
    struct Pair hi;
    int ret = 5;
    int m;

    lo = d_021F333C;
    hi = d_021F334C;
    a = (a / 8 + 2) / 4;
    if (a < 0) {
        return 5;
    }
    m = a % 2;
    b = b / 8 - (&lo.a)[m];
    if (b < 0) {
        return 5;
    }
    y = b / 4;
    if (a < 9 && y < (&hi.a)[m]) {
        ret = func_021F2B9C((unsigned char *)p, a, y);
    }
    *c = a;
    *d = y;
    return ret;
}


void func_021F0298(u8 *p)
{
    struct E *q = (struct E *)(p + 0x418);
    int i;
    int j;

    for (i = 0; i < 5; i++) {
        func_021F0CA0(&q[i], d_021F31BC[i], d_021F31AB[i], d_021F31B0[i]);
        if (i == 0) {
            func_021F0D10((char *)(&q[i]), 0);
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            func_021F0390(p, i, j, 0, 0);
        }
    }
}


void func_021F0300(u8 *p)
{
    struct E *q = (struct E *)(p + 0x418);
    int i;
    int j;

    for (i = 0; i < 5; i++) {
        func_021F0CA0(&q[i], d_021F31BC[i], d_021F31AB[i], d_021F31B0[i]);
        if (i != 0) {
            func_021F0D10((char *)(&q[i]), 0);
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            func_021F0390(p, i, j, 1, p[0x461]);
        }
    }
}

void func_021F0370(void *p)
{
    int i;
    for (i = 0; i < 3; i++) func_021F08BC(p, i, 0, 31);
}


/*
 * `const` on the two key/row tables schedules the second table's pool load
 * above the `[sp]` stack-argument store in the cycle loop (14 bytes out
 * without it). The four-way reset is `s18 = s8 = sc = s14 = 0`: the chain
 * stores right to left.
 */
void func_021F0390(u8 *p, int a, int b, int c, int e)
{
    int sv;
    int flags;
    int one;
    int mode;
    int s18;
    int s14;
    int i;
    int sc;
    int s8;
    u32 keys;
    int idx;

    sv = func_02012138((const struct Ctx *)((struct Obj03631 *)p)->f1C);
    flags = 0;
    one = 1;
    s8 = 1;
    s18 = 4;
    s14 = 3;
    sc = 2;
    if (c != 0) {
        s18 = s8 = sc = s14 = 0;
    }
    keys = func_0201058C((void *)func_0201283C(func_020120F4((const struct Ctx *)(((struct Obj03631 *)p)->f1C))));
    mode = func_02158630(sv);
    if (e != 0) {
        if (mode == 3) {
            func_021F09DC(p, 2, 3, s14, a, b);
        } else if (keys & 8) {
            flags |= 4;
            func_021F09DC(p, 2, 2, s14, a, b);
        }
    }
    if (flags == 0) {
        one = 0;
        if (keys & 2) {
            flags |= 2;
        }
        if (keys & 0x3c) {
            flags |= 4;
        }
        if (keys & 0x3c0) {
            flags |= 8;
        }
        if (keys & 0x40) {
            func_021F09DC(p, 1, 3, sc, a, b);
        } else if (keys & 0x100) {
            func_021F09DC(p, 1, 0, sc, a, b);
        } else if (keys & 0x80) {
            func_021F09DC(p, 1, 1, sc, a, b);
        } else if (keys & 0x200) {
            func_021F09DC(p, 1, 0, sc, a, b);
        }
        if (mode != 0) {
            if (mode != 3) {
                func_021F09DC(p, 2, 3, sc, a, b);
            }
        } else {
            for (i = 0; i < 3; i++) {
                p[0x44d] = (p[0x44d] + 1) % 3;
                idx = p[0x44d];
                if ((d_021F31EC[idx] & keys) || (idx == 2 && p[0x450] != 0)) {
                    if (func_021F09DC(p, 2, d_021F31F8[idx], sc, a, b) != 0) {
                        if (p[0x44d] == 2) {
                            p[0x450] = 0;
                        }
                        break;
                    }
                }
            }
            if (i == 3) {
                func_021F09DC(p, 2, 8, s8, a, b);
            }
        }
    }
    if (one == 0) {
        func_021F09DC(p, 0, 6, s8, a, b);
        if (!(flags & 8)) {
            func_021F09DC(p, 1, 7, s8, a, b);
        }
        if (!(flags & 4)) {
            func_021F09DC(p, 2, 8, s8, a, b);
        }
    } else {
        func_021F09DC(p, 0, 5, s18, a, b);
        func_021F09DC(p, 1, 5, s18, a, b);
    }
}

int func_021F05B4(unsigned char *p)
{
    if (p[0x464] == 1 && p[0x461] == 1) return 1;
    return 0;
}


void func_021F05D0(u8 *p)
{
    struct E *q2;
    struct E *q;
    int i;
    int j;
    int flag;

    flag = 0;
    for (i = 0; i < 5; i++) {
        q = (struct E *)(p + 0x418);
        func_021F0CB8((unsigned char *)(&q[i]));
        for (j = 0; j < 3; j++) {
            if (func_021F0CDC((short unsigned int *)(&q[i]), j) || p[0x460]) {
                func_021F0390(p, i, j, 0, p[0x461]);
                if (i == 0) {
                    flag = 1;
                }
                if (func_021F0CDC((short unsigned int *)(&q[i]), j)) {
                    func_021F0CF0((unsigned char *)(&q[i]), j);
                }
            }
        }
    }
    if (flag) {
        q2 = (struct E *)(p + 0x418);
        for (i = 0; i < 5; i++) {
            if (i != 0) {
                func_021F0D10((char *)(&q2[i]), 1);
                for (j = 0; j < 3; j++) {
                    func_021F0390(p, i, j, 0, p[0x461]);
                }
            } else {
                func_021F0D10((char *)(&q2[i]), 0);
            }
        }
    }
    p[0x460] = 0;
}


void func_021F06B8(u8 *p, int a, int b)
{
    struct E *q;
    int i;
    int j;
    int k;

    for (i = 0; i < 3; i++) {
        func_021F08BC((struct W *)p, i, 0, 0x1f);
    }
    q = (struct E *)(p + 0x418);
    for (j = 0; j < 5; j++) {
        for (k = 0; k < 3; k++) {
            func_021F0D00((short unsigned int *)(&q[j]), k);
        }
    }
    p[0x461] = a;
    p[0x460] = 1;
    p[0x465] = 1;
    p[0x466] = 0;
    p[0x464] = b;
}


void func_021F0728(u8 *p)
{
    struct E *q = (struct E *)(p + 0x418);
    int i;

    for (i = 0; i < 3; i++) {
        u8 c = p[i + 0x44a];

        switch (c) {
        case 3:
            func_021F07AC(p, i, (u16 *)(&q[c]));
            break;
        case 1:
            func_021F07EC(p, i, (short unsigned int *)(&q[c]));
            break;
        case 2:
            func_021F0824(p, i, (short unsigned int *)(&q[c]));
            break;
        case 0:
            func_021F0858(p, i, (short unsigned int *)(&q[c]));
            break;
        case 4:
            func_021F088C(p, i, (short unsigned int *)(&q[c]));
            break;
        }
    }
}


void func_021F07AC(u8 *p, int i, u16 *e)
{
    unsigned int v = func_021F0D08(e, i);
    if (v > 0x24 || v < 4) return;
    v = (u16)(v - 4);
    v = (unsigned)(((int)v % 8) * 28) >> 3;
    v = d_021F3255[v];
    func_021F08BC((struct W *)p, i, v, 0x1f);
}

void func_021F07EC(void *p, int i, unsigned short *q)
{
    unsigned int v = func_021F0D08(q, i);
    if (v > 112 || v < 12) return;
    v = (unsigned)((unsigned short)(v - 12)) * 28 / 100;
    v = d_021F3255[v];
    func_021F08BC(p, i, v, 31);
}

void func_021F0824(void *p, int i, unsigned short *q)
{
    unsigned int v = func_021F0D08(q, i);
    if (v > 78 || v < 8) return;
    v = (unsigned)((unsigned short)(v - 8)) * 32 / 70;
    v = d_021F3292[v];
    func_021F08BC(p, i, v, 31);
}

void func_021F0858(void *p, int i, unsigned short *q)
{
    unsigned int v = func_021F0D08(q, i);
    if (v > 20) return;
    v = (unsigned)(((int)v % 10) * 28) / 10;
    v = d_021F3255[v];
    func_021F08BC(p, i, v, 31);
}

void func_021F088C(void *p, int i, unsigned short *q)
{
    unsigned int v = func_021F0D08(q, i);
    if (v > 15) return;
    v = (unsigned)(v * 12) / 15;
    v = d_021F3204[v];
    func_021F08BC(p, i, v, 31);
}


void func_021F08BC(struct W *p, int i, int j, int k)
{
    int n;
    int m;
    int a;
    int b;

    for (n = 0; n < 5; n++) {
        p->unk_24E[i][n] = 0;
        for (m = 0; m < 3; m++) {
            a = (p->unk_230[i][n] >> (m * 5)) & 0x1f;
            b = ((p->unk_272[p->unk_26C[i]][n] >> (m * 5)) & 0x1f) - a;
            p->unk_24E[i][n] |= ((a + b * j / k) & 0x1f) << (m * 5);
        }
        func_020215BC((struct PalAnmSlot *)p->unk_210, &p->unk_24E[i][n], 1, (u16)(d_021F31A8[i] + (n + 1) * 16), 2);
    }
}

void func_021F09B4(unsigned char *p, unsigned char *q, int n)
{
    int i;
    for (i = 0; i < 5; i++) *(unsigned short *)(p + n * 10 + i * 2 + 0x272) = *(unsigned short *)(q + n * 32 + i * 2 + 0x16);
}

int func_021F09DC(unsigned char *p, int i, int v, int a, int b, int j)
{
    if (a == b && i == j) {
        *(unsigned short *)(p + i * 2 + 0x26c) = v;
        *(p + i + 0x44a) = a;
        return 1;
    }
    return 0;
}

void func_021F0A0C(unsigned char *p)
{
    int i, j;
    unsigned char *base;
    i = 0;
    base = p + 0x2d0;
    for (; i < 9; i++) {
        for (j = 0; j < 4; j++) func_021F0AC8(base + i * 32 + j * 8, i, j);
    }
}
