/*
 * file:     fld3d_ci_p10.c
 * unit:     yes
 * function: func_021C2F14, func_021C2F50, func_021C2F84, func_021C30B8, func_021C30D4, func_021C313C, func_021C3158, func_021C3198, func_021C31D4, func_021C31FC
 * address:  0x021C2F14
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
 *   func_021C2ECC  0x021C2ECC  thumb  ov021
 *   func_02048A0C  0x02048A0C  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201F4A0  0x0201F4A0  thumb
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02049F34  0x02049F34  arm
 *   func_0216FAB4  0x0216FAB4  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_021C1CB0  0x021C1CB0  thumb  ov021
 *   d_021DA720     0x021DA720  data  ov021
 *   d_021DA700     0x021DA700  data  ov021
 *   d_021DE458     0x021DE458  data  ov021
 */
#include "../../matched/include/Obj12922.h"
#include "../../matched/include/Obj01213.h"
#include "../../matched/include/Obj00576.h"

struct StrObj;
struct TexKey;
struct WordSet;
struct GfFont;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Node;
struct DispConfig;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 v[4]; } T;

typedef struct PlttData {
    u8 pad00[0xc];
    u16 *raw;
} PlttData;

typedef struct Obj {
    u8 pad00[0x10];
    u16 heap;
    u16 pad12;
    void *f14;
    u8 pad18[0x8c - 0x18];
    PlttData *pltt;
    void *canvas;
    void *chrRes;
    void *plttRes;
} Obj;

typedef struct {
    int se;
    u32 frame;
} Ent;

typedef struct {
    u16 heap;
    u16 pad;
    u32 a;
    u32 b;
    u16 n;
} R;

extern int func_0206E62C(void *a, T *t);
extern int func_021C2ECC(u32 a, u32 b);
extern int func_0208CC78(const char *s);
extern u32 func_02048A0C(u8 *a0, int i);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_020457B0(u32 size, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201F4A0(void *dst, void *src);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D83C(void *ptr);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern int func_0216FAB4(void *file, const char *texName, void *extra, const char *plttName, u32 a4, u16 a5, u16 a6, u16 a7, u16 heap, struct TexKey *out);
extern u32 func_020307B0(void *p);
extern u32 func_02045C04(struct Rec *rec);
extern int func_021C1CB0(int a, char *b, int c);
extern int func_020808F4(void);
extern void func_0207FDCC(int);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void func_020061E4(u32 a);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02030EAC(struct Node *n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
int func_021C2F14(u8 *p, const char *name);
void func_021C2F50(char *dst, const char *src);
void func_021C2F84(int s, Obj *p, char *a1, char *a2, u32 c, u32 d);
int func_021C30B8(void *a, u8 *b, u32 c);
void func_021C30D4(u32 unused);
void func_021C313C(u32 a, u32 *p);
void func_021C3158(u8 *p);
void func_021C3198(void *p, u32 *done);
R *func_021C31D4(u32 heap, u32 a, u32 b);
void func_021C31FC(u32 a);
extern Ent *d_021DA720[];
extern const T d_021DA700;
extern char d_021DE458[];


int func_021C2F14(u8 *p, const char *name)
{
    T t;
    int r;

    func_021C2F50((char *)&t, name);
    if (p != 0 && ((struct Obj12922 *)p)->f34 != 0)
        r = func_0206E62C(p + ((struct Obj12922 *)p)->f34, &t);
    else
        r = 0;
    if (r == 0)
        return 0;
    return func_021C2ECC((u32)p, r);
}


/*
 * Copies a name into a zeroed 16-byte request block (EXACT*: pad).
 */
void func_021C2F50(char *dst, const char *src)
{
    int n = func_0208CC78(src);
    u8 i;

    for (i = 0; i < 4; i++)
        ((u32 *)dst)[i] = 0;
    for (i = 0; i < n; i++)
        dst[i] = src[i];
}


void func_021C2F84(int s, Obj *p, char *a1, char *a2, u32 c, u32 d)
{
    u8 buf[0x14];
    void *x;
    void *z;
    void *y;
    void *m;
    void *h;
    u16 heap;
    void *str;
    int w;
    u16 *pl;

    h = (void *)func_02048A0C(p->f14, 0);
    heap = p->heap;
    m = func_02045B38(0, 2, 0xb0, heap);
    if (c == 0) {
        x = func_0201EC64((u16)((heap & 0x7FFF) | 0x8000));
        str = func_020457B0(8, (heap & 0x7FFF) | 0x8000);
        y = func_02045EC0(m, c);
        func_0201F02C(x, 0, (void *)s);
        func_0201F250(x, str, y);
        func_02045808(y);
        func_0201ED04(x);
    } else {
        y = func_02045EC0(m, c);
        str = func_020457B0(0x10, (heap & 0x7FFF) | 0x8000);
        func_0201F4A0(str, y);
        func_02045808(y);
    }
    w = 0;
    if (d != 0) {
        z = func_0201D7EC(0x17, 0, 0, 0, heap);
        w = func_0201D304(str, (u32)z, 0);
        func_0201D83C(z);
        w = 0x3c - w;
        if (w < 0)
            w = 0;
    }
    p->plttRes = func_02049F34(0x17, 5, (u32)(&p->pltt), heap);
    pl = p->pltt->raw;
    pl[1] = 0x7FFF;
    pl[2] = 0;
    func_0216FAB4(h, a1, pl, a2, (u32)str, w, 0, 0x440, heap, (struct TexKey *)buf);
    func_020307B0(p->plttRes);
    func_020307B0(str);
    func_02045C04(m);
}


/*
 * Runs func_021C1CB0 with kind 0x11 and stores the argument at +0x9C (EXACT*: pad).
 */
int func_021C30B8(void *a, u8 *b, u32 c)
{
    int r = func_021C1CB0((int)a, (char *)b, 0x11);

    if (r == 0)
        return 0;
    *(u32 *)&((struct Obj01213 *)b)->f9C = c;
    return r;
}


/*
 * Halves every RGB555 colour in LCDC VRAM bank 0x06860000 (0xC000 halfwords)
 * to darken the captured screen. The parameter is unused (the caller passes
 * one). The channels are extracted into u8 locals (b, g, r, a), then halved
 * as separate `x = x >> 1` statements in b, g, r order; that keeps every
 * channel in its own register so the scheduler interleaves the four chains,
 * and the halving order picks which truncation is scheduled early. Casts
 * inline in the OR expression serialise the chains instead.
 */
void func_021C30D4(u32 unused)
{
    int old = func_020808F4();
    u16 *p = (u16 *)0x06860000;
    int i;

    for (i = 0; i < 0xC000; i++) {
        u16 c = *p;
        u8 b = (c >> 10) & 0x1F;
        u8 g = (c >> 5) & 0x1F;
        u8 r = c & 0x1F;
        u8 a = (c >> 15) & 1;

        b = b >> 1;
        g = g >> 1;
        r = r >> 1;
        *p = (a << 15) | (b << 10) | (g << 5) | r;
        p++;
    }
    func_0207FDCC(old);
}


/*
 * Clears a 0x40-byte record and stores its owner (EXACT*: pad).
 */
void func_021C313C(u32 a, u32 *p)
{
    func_02082BCC(p, 0, 0x40);
    p[0] = a;
    p[14] = 0;
    p[15] = 0;
}


/*
 * Plays the next sound effect of the current cue table when its frame is
 * reached.
 */
void func_021C3158(u8 *p)
{
    Ent *t = d_021DA720[((struct Obj00576 *)p)->f66];

    if (t[((struct Obj00576 *)p)->f136].se != -1 && ((struct Obj00576 *)p)->f134 == t[((struct Obj00576 *)p)->f136].frame) {
        func_020061E4(t[((struct Obj00576 *)p)->f136].se);
        (((struct Obj00576 *)p)->f136)++;
    }
}


/*
 * VBlank task: applies the saved display setup, ends itself, flags completion.
 */
void func_021C3198(void *p, u32 *done)
{
    T t;

    func_02040588(0, 1);
    t = d_021DA700;
    func_0203FC28((struct DispConfig *)(&t));
    func_02030EAC(p);
    if (done != 0)
        *done = 1;
}


/*
 * Allocates and initialises a 0x10-byte request record.
 */
R *func_021C31D4(u32 heap, u32 a, u32 b)
{
    R *r = func_02030734(heap, 0x10, 0, d_021DE458, 0x6A);

    r->heap = heap;
    r->a = a;
    r->b = b;
    r->n = 0;
    return r;
}


/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021C31FC(u32 a)
{
    func_020307B0((void *)a);
}
