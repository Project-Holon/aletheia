/*
 * file:     fld3d_ci_p04.c
 * unit:     yes
 * function: func_021C2CF4, func_021C2D68, func_021C2EBC, func_021C2ECC, func_021C2EDC, func_021C2F14, func_021C2F50, func_021C2F84, func_021C30B8, func_021C30D4, func_021C313C, func_021C3158, func_021C3198, func_021C31D4, func_021C31FC, func_021C3204
 * address:  0x021C2CF4
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
 *   func_020124E8  0x020124E8  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_020124F0  0x020124F0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02043678  0x02043678  arm
 *   func_021C2BE4  0x021C2BE4  thumb  ov021
 *   func_020437AC  0x020437AC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02008550  0x02008550  thumb
 *   func_02046BE0  0x02046BE0  arm
 *   d_021DE3E4     0x021DE3E4  data  ov021  a4
 *   d_021DE3F4     0x021DE3F4  data  ov021  a4
 *   d_021DE404     0x021DE404  data  ov021  a4
 *   d_021DE40C     0x021DE40C  data  ov021  a4
 *   d_021DE418     0x021DE418  data  ov021  a4
 *   d_021DE428     0x021DE428  data  ov021  a4
 *   d_021DE43C     0x021DE43C  data  ov021  a4
 *   d_021DE448     0x021DE448  data  ov021  a4
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
 *   func_02045C04  0x02045C04  arm
 *   func_021C1CB0  0x021C1CB0  thumb  ov021
 *   d_021DA720     0x021DA720  data  ov021
 *   d_021DA700     0x021DA700  data  ov021
 *   d_021DE458     0x021DE458  data  ov021
 *   func_0200BCB8  0x0200BCB8  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021C3248  0x021C3248  thumb  ov021
 *   func_021C3250  0x021C3250  thumb  ov021
 *   func_0200BC4C  0x0200BC4C  thumb
 *   func_0201A9C8  0x0201A9C8  thumb
 *   func_021C38DC  0x021C38DC  thumb  ov021
 */
#include "../../matched/include/Obj04276.h"
#include "../../matched/include/Obj00457.h"
#include "../../matched/include/Obj18295.h"
#include "../../matched/include/Obj18296.h"
#include "../../matched/include/Obj18297.h"
#include "../../matched/include/Obj18298.h"
#include "../../matched/include/Obj12922.h"
#include "../../matched/include/Obj01213.h"
#include "../../matched/include/Obj00576.h"

struct Ctx;
struct Obj;
struct Sub0200852CObj;
struct Bmp;
struct Obj020437AC;
struct StrObj;
struct TexKey;
struct WordSet;
struct GfFont;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Node;
struct DispConfig;
struct Party;
struct Payload;
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

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

extern u32 *func_020124E8(void *task);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void *func_020124F0(struct Obj *p);
extern void *func_020124E4(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void *func_0201210C(const struct Ctx *p);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_021C2BE4(struct Obj *p, u32 a1, u32 a2, u32 chrFile, u32 plttFile);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_020307B0(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02046BE0(u32 a, u32 b);
extern int func_0206E62C(void *a, T *t);
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
extern int func_0200BCB8(u32);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_021C3248(void);
extern void func_021C3250(void *mon);
extern void func_0200BC4C(struct Obj *p, s32 i, const struct Payload *src);
extern u32 func_0201A9C8(struct Party *p, s32 idx);
extern int func_021C38DC(u32 a, u32 b);
int func_021C2CF4(void *a, u8 *p);
int func_021C2D68(int a, int *b);
int func_021C2EBC(u32 a, u32 b);
int func_021C2ECC(u32 a, u32 b);
int func_021C2EDC(u8 *p, const char *name);
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
void func_021C3204(u32 *p, u32 b, u32 c);
extern char d_021DE3E4[];
extern char d_021DE3F4[];
extern char d_021DE404[];
extern char d_021DE40C[];
extern char d_021DE418[];
extern char d_021DE428[];
extern char d_021DE43C[];
extern char d_021DE448[];
extern Ent *d_021DA720[];
extern const T d_021DA700;
extern char d_021DE458[];


/*
 * func_020124E8 takes the task (the first parameter, still in r0 on the
 * path to the call): that is what keeps r0 live and puts the switch value
 * in r1.
 */
int func_021C2CF4(void *a, u8 *p)
{
    switch (((struct Obj04276 *)p)->f130) {
    case 0:
        if (((struct Obj04276 *)p)->f11C != 0 && ((struct Obj04276 *)p)->f120 != 0 && ((struct Obj04276 *)p)->f124 != 0)
            ((struct Obj04276 *)p)->f130 = ((struct Obj04276 *)p)->f130 + 1;
        break;
    case 1:
        func_0204E720(func_020124E8(a)[0xF] != 0 ? 0xC : 3, 0, 0x10, -1);
        ((struct Obj04276 *)p)->f130 += 1;
    case 2:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}





int func_021C2D68(int a, int *b)
{
    char **pp;
    int t;
    int s;
    char *p;
    u32 *q;
    u32 x;
    u32 y;

    pp = (void *)func_020124E8(func_020124F0((struct Obj *)a));
    t = (int)func_020124E4((struct Obj *)a);
    s = (int)func_02012944(func_020120F4((const struct Ctx *)t));
    p = *pp;
    func_0201210C((void *)t);
    q = (u32 *)(p + 0x9c);
    switch (*b) {
    case 0:
        ((struct Obj00457 *)p)->f90 = func_02043678(16, 16, 32, ((struct Obj00457 *)p)->f10);
        func_021C2BE4((struct Obj *)p, (u32)d_021DE3E4, (u32)d_021DE3F4, q[1], q[2]);
        (*b)++;
        break;
    case 1:
        func_020437AC(((struct Obj00457 *)p)->f90);
        func_020307B0(((struct Obj00457 *)p)->f94);
        func_020307B0(((struct Obj00457 *)p)->f98);
        func_021C2F84(s, (struct Obj *)p, d_021DE404, d_021DE40C, q[0], 0);
        (*b)++;
        break;
    case 2:
        if (q[3] == 0) {
            *b = 4;
            break;
        }
        ((struct Obj00457 *)p)->f90 = func_02043678(16, 16, 32, ((struct Obj00457 *)p)->f10);
        if (func_02008550((const struct Sub0200852CObj *)s) == 0) {
            x = 0;
            y = 0x16;
        } else {
            x = 1;
            y = 0x17;
        }
        func_021C2BE4((struct Obj *)p, (u32)d_021DE418, (u32)d_021DE428, x, y);
        (*b)++;
        break;
    case 3:
        func_020437AC(((struct Obj00457 *)p)->f90);
        func_020307B0(((struct Obj00457 *)p)->f94);
        func_020307B0(((struct Obj00457 *)p)->f98);
        func_021C2F84(s, (struct Obj *)p, d_021DE43C, d_021DE448, 0, q[4]);
        (*b)++;
        break;
    case 4:
        ((struct Obj00457 *)p)->f1C = 0;
        ((struct Obj00457 *)p)->f20 = 0;
        ((struct Obj00457 *)p)->f24 = 0xFFD44000;
        func_02046BE0(0, 0);
        return 1;
    }
    return 0;
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C2EBC(u32 a, u32 b)
{
return (((((struct Obj18296 *)((u8 *)(b)))->f0 << 16) >> 13) + ((((struct Obj18295 *)((u8 *)(a)))->f8 << 16) >> 13));
}






int func_021C2ECC(u32 a, u32 b)
{
return ((((struct Obj18298 *)((u8 *)(b)))->f0 << 3) + ((((struct Obj18297 *)((u8 *)(a)))->f2C << 16) >> 13));
}






/*
 * Builds a request block and dispatches func_021C2EBC on success (EXACT*: pad).
 */
int func_021C2EDC(u8 *p, const char *name)
{
    T t;
    int r;

    func_021C2F50((char *)&t, name);
    if (p != 0)
        r = func_0206E62C(p + 0x3C, &t);
    else
        r = 0;
    if (r == 0)
        return 0;
    return func_021C2EBC((u32)p, r);
}





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



void func_021C3204(u32 *p, u32 b, u32 c)
{
    int n = func_0200BCB8(p[2]);
    u32 m = (u32)func_0201AB28((void *)b, c);

    if (n < 2) {
        func_021C3248();
        func_021C3250((void *)m);
        func_0200BC4C((struct Obj *)p[2], n, (const struct Payload *)m);
        func_0201A9C8((struct Party *)b, c);
        func_021C38DC(p[1], b);
    }
}
