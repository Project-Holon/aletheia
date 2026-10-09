/*
 * file:     unit_021F0680.c
 * unit:     yes
 * function: func_021F0680, func_021F07AC, func_021F09A0, func_021F0A04, func_021F0AA0, func_021F0B98, func_021F0C34, func_021F0C60, func_021F0CEC, func_021F0D40, func_021F0D58, func_021F0D64, func_021F0DB0, func_021F0E64, func_021F0ED8, func_021F0EF4, func_021F0F40, func_021F0F68
 * address:  0x021F0680
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202DC98  0x0202DC98  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_021BBC2C  0x021BBC2C  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_020061E4  0x020061E4  thumb
 *   d_021F10D0     0x021F10D0  data  a4
 *   func_0204162C  0x0204162C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0202DCC4  0x0202DCC4  thumb
 *   func_0202DC9C  0x0202DC9C  thumb
 *   func_02043B5C  0x02043B5C  arm
 *   func_0202DC60  0x0202DC60  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045924  0x02045924  arm
 *   d_021F1040     0x021F1040  data  ov031  a4
 *   func_0202DD24  0x0202DD24  thumb
 *   func_02043814  0x02043814  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_0204B454  0x0204B454  arm
 *   func_02035C60  0x02035C60  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0209C2B0 0x0209C2B0 arm
 *   func_02035D20  0x02035D20  arm
 */
#include "../../matched/include/Obj20406.h"
#include "../../matched/include/Obj07626.h"
#include "../../matched/include/Obj01128.h"
#include "../../matched/include/Obj20409.h"
#include "../../matched/include/Obj20411.h"

struct Obj0202DC98;
struct PrintSys;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Obj0202DCC4;
struct Strbuf;
struct U16Vec;
struct Obj;
struct Bmp;
struct PmsDraw;
struct Actor;
struct PtS;
struct Vec2;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Slot {
    u32 h;
    u8  f;
    u8  pad[3];
};

typedef struct {
    char pad[0x43C];
    int a;
    int n;
    int m;
} B;

typedef signed short   s16;

typedef struct { int a, b; } Pair;

struct Obj_021F07AC {
    u32 w0;
    char pad0[0x40 - 4];
    u32 w40;
    u32 w44;
    u32 w48;
    u32 a[3];
    u32 b[3];
    struct Slot s[3];
    u32 w7c;
};

typedef enum { RowZero } RowOffset;

typedef struct B_021F0AA0 B_021F0AA0;

typedef struct {
    char pad[0x2C];
    int h;
    char pad2[0x43C - 0x30];
    int a;
    int n;
} B_021F0C60;

typedef struct {
    char pad[0x43C];
    int a;
    int n;
} B_021F0CEC;

typedef struct {
    char pad[0x43C];
    int a;
} B_021F0D40;

typedef struct {
    char pad[0x43C];
    int a;
    int n;
} B_021F0DB0;

typedef struct {
    u16 cnt;
    u8 idx;
    u8 pad;
} Slot;

typedef struct {
    char pad[0x34];
    Slot s[3];
} A_021F0CEC;

typedef struct {
    char pad[0x440];
    int n;
} B_021F0E64;

typedef struct A_021F0ED8 A_021F0ED8;

typedef struct {
    char pad[0x34];
    Slot s[3];
} A;

typedef struct {
    char pad[0x440];
    int n;
} B_021F0EF4;

extern u32 func_0202DC98(struct Obj0202DC98 *o);
extern void *func_02045770(struct Descriptor *a);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *a);
extern void *func_021BBC2C(void *r, int i);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_020061E4(u32 se);
extern u32 func_0204162C(int channel);
extern void func_02082D44(const void *src, void *dst, int n);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern u32 func_0202DCC4(const struct Obj0202DCC4 *p, u32 i);
extern void func_0202DC9C(struct Obj0202DC98 *o, int i, u32 a1);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0202DC60(struct Obj_021F07AC *p, u32 a, void *w, u32 i, u32 e);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0202DD24(struct PmsDraw *p, u32 i, u32 j);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern int func_02035C60(void);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32 func_0209C2B0(u32 a, u32 b);
extern u32 func_02035D20(u32 *outA, u32 *outB);
void func_021F0680(struct Obj_021F07AC *p, B *b);
void func_021F07AC(struct Obj_021F07AC *p, const u8 *e, u8 k);
void func_021F09A0(void *a, char *b);
void func_021F0A04(struct Obj_021F07AC *o, u8 a, u8 b, void *c, int d);
void func_021F0AA0(void *a, char *b, int n);
int func_021F0B98(char *o);
void func_021F0C34(char *a, unsigned char *b);
void func_021F0C60(B_021F0C60 *o, B_021F0C60 *b);
void func_021F0CEC(char *o, B_021F0CEC *b);
int func_021F0D40(B_021F0D40 *p);
u32 func_021F0D58(void *unused, u32 d);
int func_021F0D64(char *p);
int func_021F0DB0(char *a0, void *a1, B_021F0DB0 *a2);
Slot *func_021F0E64(A_021F0CEC *p, B_021F0E64 *q, int idx);
int func_021F0ED8(A_021F0ED8 *a, B_021F0CEC *b, int idx);
void func_021F0EF4(A *p, B_021F0EF4 *q);
void func_021F0F40(A *p, int unused, int idx);
int func_021F0F68(void *unused, int idx, int flag);
extern const char d_021F10D0[];
extern const Pair d_021F1040;





/*
 * The 0/1 flag the loop tests (movs r0,#1 / movs r0,#0 / cmp r0,#0) is a
 * `!field` returned from an inline helper: the same test written in place,
 * as a ternary, an if/else local, or a helper returning `== 0` or a ternary,
 * all fold into a direct bne.
 */
static inline int slot_free(struct Obj_021F07AC *p, int i)
{
    u32 q = p->w40;
    if (p->s[i].f != 0) {
        if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)p->s[i].h))) == 0) {
            func_02045334((struct Descriptor *)p->s[i].h);
            p->s[i].f = 0;
        }
    }
    return !p->s[i].f;
}





void func_021F0680(struct Obj_021F07AC *p, B *b)
{
    int flag;
    int i;
    int d;
    void *e;

    flag = 0;
    if (b->m == b->n)
        return;
    if (func_0202DC98((struct Obj0202DC98 *)p->w7c) == 0)
        return;
    for (i = 0; i < 3; i++) {
        if (p->b[i] == 1) {
            if (slot_free(p, i) == 0)
                return;
        }
    }
    if (b->a < 3) {
        for (i = b->m; i <= b->n; i++) {
            if (i > -1) {
                e = func_021BBC2C(b, i);
                if (e == 0)
                    func_02034714(d_021F10D0, 0, d_021F10D0);
                func_021F07AC(p, e, i);
            }
        }
    } else {
        d = b->n - b->m;
        if (((d < 0) ? -d : d) >= 3 || b->m < 2)
            func_021F09A0(p, (char *)b);
        else
            func_021F0AA0(p, (char *)b, d);
        flag = 1;
    }
    if (flag == 1)
        func_020061E4(0x548);
    b->m = b->n;
}




static inline int paletteFlag(const u8 *e)
{
    if (e[0x20] == 0) return 0;
    return 2;
}





void func_021F07AC(struct Obj_021F07AC *p, const u8 *e, u8 k)
{
    u16 *pal;
    int c;
    Pair t;
    void *x;
    void *buf;
    u32 q;
    int off;

    pal = (u16 *)func_0204162C(6);
    off = (k * 0xE0) << 1;
    c = paletteFlag(e);
    func_02082D44(pal, (u8 *)pal + off, 0x1C0);
    func_020413B0(6, 0, k * 7, 0x20, 7, c);
    func_02041B6C(6);
    t = d_021F1040;
    if (p->b[k] == 0) {
        if (func_0202DCC4((const struct Obj0202DCC4 *)p->w7c, k) == 1)
            func_0202DC9C((struct Obj0202DC98 *)p->w7c, k, 1);
    } else if (p->b[k] == 1) {
        func_02043B5C(func_02045770((struct Descriptor *)p->a[k]), 0);
        func_02045334((struct Descriptor *)p->a[k]);
    }
    if (e[0x21] == 0) {
        func_0202DC60((struct Obj_021F07AC *)p->w7c, p->a[k], (void *)(e + 0x10), k, (u32)(&t));
        p->b[k] = 0;
    } else {
        switch (e[0x21]) {
        case 1:
            x = func_02045EC0((struct MsgBank *)p->w48, 6);
            break;
        case 2:
            x = func_02045EC0((struct MsgBank *)p->w48, 0);
            break;
        case 3:
            x = func_02045EC0((struct MsgBank *)p->w48, 1);
            break;
        case 4:
            x = func_02045EC0((struct MsgBank *)p->w48, 2);
            break;
        case 5:
            x = func_02045EC0((struct MsgBank *)p->w48, 3);
            break;
        case 0:
            return;
        default:
            return;
        }
        func_02045374((struct Cfg *)p->a[k]);
        func_02041B6C(func_02045730((struct Descriptor *)p->a[k]));
        q = p->w40;
        func_0201C724((void *)q, (u32)func_02045770((struct Descriptor *)p->s[k].h), (s16)0, (s16)t.b, (u32)x, p->w44, (u32)0x440);
        p->s[k].f = 1;
        func_02045808(x);
        p->b[k] = 1;
    }
    buf = func_020457B0(8, 0x15);
    func_02045924(buf, (const u16 *)e);
    func_0201C724((void *)p->w40, (u32)func_02045770((struct Descriptor *)p->a[k]), (s16)0, (s16)0, (u32)buf, p->w44, (u32)0x440);
    func_02045808(buf);
    if (e[0x22] != 0) {
        buf = func_02045EC0((struct MsgBank *)p->w48, (e[0x22] == 1) ? 4 : 5);
        func_0201C724((void *)p->w40, (u32)func_02045770((struct Descriptor *)p->a[k]), (s16)0x74, (s16)0, (u32)buf, p->w44, (u32)0x440);
        func_02045808(buf);
    }
}




void func_021F09A0(void *a, char *b)
{
    int k;
    int i = ((struct Obj20406 *)b)->f440;
    int lo = i - 3;
    void *e;

    if (lo < 0)
        lo = -1;
    k = i - lo - 1;
    for (; i > lo; i--, k--) {
        e = func_021BBC2C(b, i);
        if (e == 0)
            func_02034714(d_021F10D0, 0, d_021F10D0);
        if (k <= -1)
            func_02034714(d_021F10D0, 0, d_021F10D0);
        func_021F07AC(a, e, (u8)k);
    }
}



/*
 * lever: enum byte-offset locals, product by 0xE0 then separate <<= 1, recover sequential source/destination scaling and entry copies; integer offsets and enum halfword indexes do not.
 * extent: 154 instruction bytes followed by two zero alignment bytes; func_021F0AA0 is separately matched.
 */
void func_021F0A04(struct Obj_021F07AC *o, u8 a, u8 b, void *c, int d)
{
    u16 *base;
    u16 *dst;
    u16 *src;
    RowOffset destOffset;
    RowOffset sourceOffset;

    base = (u16 *)func_0204162C(6);
    destOffset = b * 0xE0;
    destOffset <<= 1;
    sourceOffset = a * 0xE0;
    sourceOffset <<= 1;
    dst = (u16 *)((u32)base + destOffset);
    src = (u16 *)((u32)base + sourceOffset);
    func_02082D44(src, dst, 0x1C0);
    func_02041B6C(6);
    if (o->b[a] == 0 && o->b[b] == 0) {
        func_0202DD24((struct PmsDraw *)o->w7c, a, b);
        return;
    }
    if (o->b[a] == 1 && o->b[b] == 1) {
        func_02043814((struct Bmp *)((u32)func_02045770((struct Descriptor *)o->a[a])), (const struct Bmp *)((u32)func_02045770((struct Descriptor *)o->a[b])));
        func_02045334((struct Descriptor *)o->a[b]);
        return;
    }
    func_021F07AC(o, func_021BBC2C(c, d - 2 + a), b);
}






void func_021F0AA0(void *a, char *b, int n)
{
    long i;
    int j;
    void *e;

    if (n > 0) {
        for (i = n, j = 0; i < 3; i++) {
            func_021F0A04(a, i, j, b, ((struct Obj07626 *)b)->f440 - n);
            j++;
        }
        for (j = 3 - n; j < 3; j++) {
            e = func_021BBC2C(b, ((struct Obj07626 *)b)->f440 - 2 + j);
            if (e == 0)
                func_02034714(d_021F10D0, 0, d_021F10D0);
            func_021F07AC(a, e, (u8)j);
        }
    } else {
        for (i = n + 2, j = 2; i > -1; i--) {
            func_021F0A04(a, i, j, b, ((struct Obj07626 *)b)->f440 - n);
            j--;
        }
        for (j = -1 - n; j > -1; j--) {
            e = func_021BBC2C(b, ((struct Obj07626 *)b)->f440 - 2 + j);
            if (e == 0)
                func_02034714(d_021F10D0, 0, d_021F10D0);
            func_021F07AC(a, e, (u8)j);
        }
    }
}






int func_021F0B98(char *o)
{
    s16 buf[2];
    u32 x;
    u32 y;
    int r;

    if (func_02035CB8(&x, &y) == 0)
        return 0;
    r = 1;
    func_0204B454((struct Actor *)((struct Obj01128 *)o)->f2C, (struct PtS *)buf, 1);
    if (((struct Obj01128 *)o)->f31 == 0) {
        if (func_02035C60() == 0)
            return 0;
        if ((u32)(buf[0] - 0xB) <= x && (u32)(buf[0] + 0xB) >= x &&
            (u32)(buf[1] - 0xB) <= y && (u32)(buf[1] + 0xB) >= y)
            return r;
    } else {
        if (y < 0x1C)
            y = 0x1C;
        else if (y > 0x9C)
            y = 0x9C;
        buf[1] = y;
        func_0204B404((struct Obj *)(((struct Obj01128 *)o)->f2C), (const struct Vec2 *)buf, 1);
        return 1;
    }
    return 0;
}




void func_021F0C34(char *a, unsigned char *b)
{
    if (b[0x31] == 1)
        func_021F0C60((B_021F0C60 *)((B_021F0AA0 *)b), (B_021F0C60 *)((B_021F0AA0 *)(a + 0x30e0)));
    else
        func_021F0CEC((char *)b, (void *)((B_021F0AA0 *)(a + 0x30e0)));
}




/*
 * func_021F0D58 is filed as a 12-byte tail stub (r0 = 0x8000, r1 kept); the
 * call sites pass (b, n), so it is declared with two arguments here.
 */
void func_021F0C60(B_021F0C60 *o, B_021F0C60 *b)
{
    s16 buf[2];
    int k;
    int t;
    int c;
    int i;
    int j;

    func_0204B454((struct Actor *)o->h, (struct PtS *)buf, 1);
    t = (buf[1] - 0x1C) << 8;
    k = func_021F0D40((void *)((B_021F0C60 *)b));
    c = func_021F0D58(b, k);
    i = 0;
    t = t + (c >> 1);
    for (j = 0; j < k; j++) {
        if (t <= c * (i + 1))
            break;
        i++;
    }
    if (i >= k)
        i = k;
    b->n = i + (b->a - k);
    if (b->n < 3) {
        if (b->a < 3)
            b->n = b->a;
        else
            b->n = 2;
    }
    if (b->n < 0 || b->n > b->a)
        b->n = b->a;
}







void func_021F0CEC(char *o, B_021F0CEC *b)
{
    u16 t[2];
    int k;
    int c;

    k = func_021F0D40((B_021F0D40 *)b);
    c = func_021F0D58(b, k);
    if (b->a - b->n > 0x1B)
        b->n = b->a - 0x1B;
    t[1] = 0x9C - ((u32)((b->a - b->n) * c) >> 8);
    t[0] = 0xF4;
    func_0204B404((struct Obj *)(((struct Obj20409 *)o)->f2C), (const struct Vec2 *)t, 1);
}








/*
 * Unlabelled leaf (no lr push) sitting in a word run; filed as a blocker of
 * func_021F0C60 and func_021F0CEC.
 */
int func_021F0D40(B_021F0D40 *p)
{
    int v = p->a;

    if (v >= 0x1E)
        v = 0x1D;
    v -= 2;
    if (v < 0)
        v = 0;
    return v;
}








u32 func_021F0D58(void *unused, u32 d)
{
    return func_0209C2B0(0x8000, d);
}








int func_021F0D64(char *p)
{
    unsigned short t[2];
    u32 x;
    u32 y;

    if (func_02035D20(&x, &y) == 0)
        return 0;
    if (x >= 0xE9 && x <= 0xFF && y >= 0x1C && y <= 0x9C) {
        t[0] = 0xF4;
        t[1] = y;
        func_0204B404((struct Obj *)(((struct Obj20411 *)p)->f2C), (const struct Vec2 *)t, 1);
        return 1;
    }
    return 0;
}








int func_021F0DB0(char *a0, void *a1, B_021F0DB0 *a2)
{
    u32 x;
    u32 y;
    int i;
    int t;
    u8 *e;

    if (func_02035D20(&x, &y) == 0)
        return 0;
    if (x <= 0xE8) {
        for (i = 0; i < 3; i++) {
            if (y >= (u32)(i * 0x38) && y <= (u32)(i * 0x38 + 0x38))
                break;
        }
    }
    if (i >= 3 || i > a2->a)
        return 0;
    if (func_021F0F68(a1, i, 1) == 1) {
        t = i;
        i = a2->n;
        if (i >= 3)
            i = i - 2 + t;
        else
            i = t;
        func_021F0ED8((A_021F0ED8 *)a1, (B_021F0CEC *)a2, i);
        e = func_021BBC2C(a2, i);
        if (e != 0)
            func_02082D44(e + 0x1A, a0 + 0x28A4, 6);
        func_021F0F40((A *)a1, (int)a2, i);
        func_020061E4(0x54C);
        return 1;
    }
    return 0;
}






Slot *func_021F0E64(A_021F0CEC *p, B_021F0E64 *q, int idx)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (p->s[i].cnt != 0 && idx == p->s[i].idx)
            return &p->s[i];
    }
    for (i = 0; i < 3; i++) {
        if (p->s[i].cnt == 0)
            return &p->s[i];
    }
    for (i = 0; i < 3; i++) {
        int v = p->s[i].idx;
        if (v > q->n || v <= q->n - 3)
            return &p->s[i];
    }
    func_02034714((void *)0x021F10D0, 0, (void *)0x021F10D0);
    return 0;
}




int func_021F0ED8(A_021F0ED8 *a, B_021F0CEC *b, int idx)
{
    Slot *p;
    p = func_021F0E64((A_021F0CEC *)a, (B_021F0E64 *)b, idx);
    if (!p)
        return 0;
    p->cnt = 0x5a;
    p->idx = idx;
    return 1;
}





void func_021F0EF4(A *p, B_021F0EF4 *q)
{
    int i;
    int k;
    int n;

    for (i = 0; i < 3; i++) {
        if (p->s[i].cnt != 0) {
            p->s[i].cnt--;
            if (p->s[i].cnt == 0) {
                n = q->n;
                if (n < 3)
                    k = p->s[i].idx;
                else
                    k = p->s[i].idx + 2 - n;
                if (k >= 0 && k < 3)
                    func_021F0F68(p, k, 0);
            }
        }
    }
}




void func_021F0F40(A *p, int unused, int idx) { int i; for(i=0;i<3;i++) if(p->s[i].cnt!=0 && idx!=p->s[i].idx) p->s[i].cnt=1; }





int func_021F0F68(void *unused, int idx, int flag)
{
    u16 *map;
    int pal;

    map = (u16 *)func_0204162C(6);
    switch ((u16)(map[idx * 0xE0] >> 12)) {
    case 0:
    case 1:
        if (flag == 0)
            pal = 0;
        else
            pal = 1;
        break;
    case 2:
    case 3:
        if (flag == 0)
            pal = 2;
        else
            pal = 3;
        break;
    default:
        return 0;
    }
    func_020413B0(6, 0, idx * 7, 0x20, 7, pal);
    func_02041B6C(6);
    return 1;
}
