/*
 * file:     event_poke_status_p21.c
 * unit:     yes
 * function: func_0215A760, func_0215A77C, func_0215A7F0, func_0215A864, func_0215A920, func_0215A954, func_0215A990, func_0215A9C0, func_0215AA24, func_0215AA34, func_0215AA48, func_0215AA4C
 * address:  0x0215A760
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02190A20  0x02190A20  thumb  ov021
 *   func_0201F91C  0x0201F91C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045874  0x02045874  arm
 *   func_02190A64  0x02190A64  thumb  ov021
 *   func_0215A5FC  0x0215A5FC  thumb  ov010
 *   func_02190ACC  0x02190ACC  thumb  ov021
 *   func_02190AC4  0x02190AC4  thumb  ov021
 *   func_02190AEC  0x02190AEC  thumb  ov021
 *   func_02190B08  0x02190B08  thumb  ov021
 *   func_02190988  0x02190988  thumb  ov021
 *   d_02171140     0x02171140  data  ov010  a4
 *   func_021909BC  0x021909BC  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_02045808  0x02045808  arm
 *   func_021909E4 0x021909E4 thumb ov021
 *   func_020362DC 0x020362DC arm
 *   func_02020D0C  0x02020D0C  thumb
 *   func_020202EC  0x020202EC  thumb
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191164  0x02191164  thumb  ov021
 *   func_02191184  0x02191184  thumb  ov021
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215909C  0x0215909C  thumb  ov010
 *   func_021590D4  0x021590D4  thumb  ov010
 */
#include "../../matched/include/Obj05883.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj18799.h"
#include "../../matched/include/Obj18800.h"
#include "../../matched/include/Obj04148.h"
#include "../../matched/include/Obj12038.h"
#include "../../matched/include/Obj12286.h"
#include "../../matched/include/Obj17666.h"
#include "../../matched/include/Obj17667.h"

struct MsgBank;
struct Slot;
struct U16Vec;
struct WordSet;
struct Handle;
struct Obj;
struct P;
struct Q_0215A9C0;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int   u32;

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k[8];
} Q_0215A77C;

typedef struct {
    unsigned short id;
    unsigned short pad[15];
    int pad20;
} P;

typedef struct {
    unsigned short a;
    unsigned short pad[5];
    int g;
    int h;
    int i;
    int j;
    int pad1c;
    int k[32];
} Q_0215A7F0;

typedef struct {
    int a0;
    int a1;
    unsigned short a2;
    unsigned short f1 : 3;
    unsigned short f2 : 4;
    int c3;
    unsigned short h8;
    unsigned short h9;
    int d5;
    int d6;
    int d7;
} L32;

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
    int pad8;
    int padc;
    int pad10;
    int pad14;
    int j;
    int k;
} Q_0215A864;

typedef struct {
    char pad[0x20];
    int k[8];
} Q_0215A9C0;

typedef signed short   s16;

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02082BCC(void *, int, int);
extern void func_02082A7C(int, void *, int);
extern int func_02190A20(int, int);
extern unsigned int func_0201F91C(struct Slot *s);
extern void func_02045CAC(struct MsgBank *bank, unsigned int index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern struct U16Vec *func_02045874(struct U16Vec *src, unsigned int heapId);
extern int func_02190A64(u32 a, u32 b, u32 c, u32 d);
extern int func_0215A5FC(int a0);
extern u32 func_02190ACC(u32 *obj, u32 *tab, u32 unused, u32 key);
extern unsigned func_02190AC4(void *p);
extern unsigned func_02190AEC(unsigned a, unsigned b, unsigned c, int d);
extern int func_02190B08(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 f);
extern struct Handle *func_02190988(u16 *a, const u8 *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w);
extern int func_021909BC();
extern int func_02045C04();
extern int func_02045808();
extern int func_021909E4(struct Handle *h);
extern u32 func_020362DC(void);
extern u32 func_02020D0C(u8 *p);
extern void func_020202EC(struct Obj *obj, u16 *out);
extern int func_02159190(int);
extern int func_0215A61C(int);
extern void func_02191164(struct P *p);
extern void func_02191184(struct Q_0215A9C0 *q, u32 b, int c, u32 d);
extern void *func_0215A5F4(void *p);
extern void *func_0215909C(u8 *a);
extern int func_021590D4();
void func_0215A760(u8 *a, unsigned b, unsigned c);
void func_0215A77C(unsigned short *p, unsigned short a, unsigned short b, unsigned short c, unsigned short d, int e, int f, int g, int h);
void func_0215A7F0(unsigned short *p, int a, int b, int c, struct U16Vec *s0, void *s1);
void func_0215A864(int *p);
int func_0215A920(int a0);
int func_0215A954(u8 *a);
int func_0215A990(u8 *a);
void func_0215A9C0(int a);
void *func_0215AA24(int a0);
int func_0215AA34(int a0);
void func_0215AA48(void *p, int v);
u8 func_0215AA4C(void *p);
extern L32 d_02171140;

/*
 * interface: original narrows r1/r2 by shift pairs; u16 extern preserves this.
 */
void func_0215A760(u8 *a, unsigned b, unsigned c) {
 ((struct Obj05883 *)a)->f14 = func_02045B38(0, (u16)b, (u16)c, ((struct Obj05883 *)a)->f0);
 ((struct Obj05883 *)a)->f18 = c;
}


void func_0215A77C(unsigned short *p, unsigned short a, unsigned short b,
                   unsigned short c, unsigned short d, int e, int f, int g,
                   int h)
{
    char *base = *(char * *)&((struct Obj00005 *)p)->f20;
    Q_0215A77C *q = (Q_0215A77C *)(base + 0x34);

    func_02082BCC(q, 0, 0xa0);
    ((struct Obj18799 *)base)->f34 = a;
    q->b = b;
    q->c = c;
    q->d = d;
    q->e = e;
    q->f = f;
    q->g = g;
    q->i = h;
    func_02082A7C(0, (char *)q + 0x20, 0x80);
    if (q->i == 0) {
        q->h = 1;
        q->i = (int)func_02045B38(0, 3, 0x80 + 0x86, *p);
    }
    q->j = func_02190A20(0x20, *p);
}


void func_0215A7F0(unsigned short *p, int a, int b, int c, struct U16Vec *s0, void *s1)
{
    Q_0215A7F0 *q = (Q_0215A7F0 *)(*(char * *)&((struct Obj00005 *)p)->f20 + 0x34);

    if (b != 0xffff) {
        unsigned i = func_0201F91C((struct Slot *)q->j);
        if (i >= 0x20) {
            return;
        }
        func_02045CAC((struct MsgBank *)q->i, b, s1);
        func_0201F250((struct WordSet *)q->g, (void *)s0, (void *)s1);
        q->k[i] = (int)func_02045874(s0, *p);
    }
    func_02045CAC((struct MsgBank *)q->i, a, s1);
    func_0201F250((struct WordSet *)q->g, (void *)s0, (void *)s1);
    func_02190A64(q->j, (u32)s0, c, *p);
}


/*
 * The ov021 leaves 0x02190AC4 and 0x02190AEC (unlabelled, formerly the
 * blockers) are matched in their own shards and attest as matched.
 */
void func_0215A864(int *p)
{
    int x;
    int y;
    Q_0215A864 *q = (Q_0215A864 *)(*(char * *)&((struct Obj18800 *)p)->f20 + 0x34);
    L32 l = d_02171140;
    int t = func_0215A5FC((int)p);
    unsigned m;
    unsigned n;

    x = func_02190ACC((u32 *)t, (u32 *)q->j, l.h8, l.f1);
    if (q->e == 1) {
        q->a = q->a - (unsigned short)x;
    }
    n = func_02190AC4((void *)q->j);
    m = 6;
    if (n <= 6) {
        m = n;
    }
    y = func_02190AEC(m, l.h9, l.f2, n > 6);
    func_02190B08((u32)(&l), (unsigned short)func_02190AC4((void *)q->j), (unsigned short)q->a, (unsigned short)q->b, (unsigned short)x, (unsigned short)y);
    q->k = (int)func_02190988((u16 *)t, (const u8 *)(&l), q->j, (u32)((void *)func_0215A9C0), (u32)p, 0, q->c, q->d);
}


int func_0215A920(int a0)
{
    int t4;
    int t5;
    int t6;
    int t7;

t6 = a0 + 0;
a0 = *(int *)&((struct Obj04148 *)t6)->f1C;
    a0 = func_021909BC(a0);
loc_0215A92A:
a0 = ((struct Obj04148 *)t6)->f10;
    if (a0 != 1) goto loc_0215A936;
loc_0215A930:
a0 = ((struct Obj04148 *)t6)->f14;
    a0 = func_02045C04(a0);
loc_0215A936:
t4 = 0;
t7 = t4 + 0;
loc_0215A93A:
a0 = t4 << 2;
t5 = t6 + a0;
a0 = ((struct Obj12038 *)t5)->f20;
    if (a0 == 0) goto loc_0215A94A;
loc_0215A944:
    a0 = func_02045808(a0);
loc_0215A948:
((struct Obj12038 *)t5)->f20 = t7;
loc_0215A94A:
t4 = t4 + 1;
    if (t4 < 0x20) goto loc_0215A93A;
loc_0215A950:
    return a0;}

int func_0215A954(u8 *a) {
 u8 *p;
 int v;
 p = *(u8 * *)&((struct Obj12286 *)a)->f20 + 52;
 v = func_021909E4(((struct Obj04148 *)p)->f1C);
 if (v == -1) return 0;
 func_0215A920((int)p);
 if (v != -2) **(u16 * *)&((struct Obj04148 *)p)->f8 = v;
 else **(u16 * *)&((struct Obj04148 *)p)->f8 = 65534;
 return 1;
}

/*
 * lever: result declared before pointer gives original r4/result, r5/base.
 */
int func_0215A990(u8 *a) {
 int v;
 u8 *p;
 p = *(u8 * *)&((struct Obj12286 *)a)->f20 + 52;
 v = func_0215A954(a);
 if (v == 0 && (func_020362DC() & 1024)) {
 func_0215A920((int)p);
 **(u16 * *)&((struct Obj04148 *)p)->f8 = 65533;
 v = 1;
 }
 return v;
}


void func_0215A9C0(int a)
{
    unsigned short h = 0;
    int r = func_02020D0C((u8 *)a);
    Q_0215A9C0 *q = (Q_0215A9C0 *)(*(char * *)&((struct Obj00005 *)r)->f20 + 0x34);

    func_020202EC((struct Obj *)a, &h);
    if (q->k[h] != 0) {
        if (func_02159190(1) != 0) {
            int t = func_0215A61C(r);
            func_02191164((struct P *)t);
            func_02191184((struct Q_0215A9C0 *)t, 0, 0, q->k[h]);
        } else if (func_02159190(2) == 0) {
            func_02159190(3);
        }
    }
}


void *func_0215AA24(int a0)
{
    int t4;
    void *p;
    void *v0;

t4 = a0 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215AA2C:
    p = func_0215909C((u8 *)v0);
loc_0215AA30:
((struct Obj00005 *)t4)->f1C = p;
    return p;}


int func_0215AA34(int a0)
{
    int a1;
    int t4;
    void *v0;

t4 = a0 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215AA3C:
a1 = *(int *)&((struct Obj00005 *)t4)->f1C;
    a0 = func_021590D4(v0, a1);
loc_0215AA42:
a0 = 0;
*(int *)&((struct Obj00005 *)t4)->f1C = a0;
    return a0;}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Byte-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215AA48.c \
 *       --func func_0215AA48 --addr 0x0215AA48 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0215AA48(void *p, int v) { ((struct Obj17666 *)p)->f1A = v; }


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Byte-field getter/setter, pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215AA4C.c \
 *       --func func_0215AA4C --addr 0x0215AA4C --region ov010 --cc dsi/1.1p1 --thumb
 */
u8 func_0215AA4C(void *p) { return ((struct Obj17667 *)p)->f1A; }
