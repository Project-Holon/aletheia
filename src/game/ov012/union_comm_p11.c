/*
 * file:     union_comm_p11.c
 * unit:     yes
 * function: func_02173934, func_02173940, func_0217394C, func_02173984, func_021739A8, func_021739CC, func_021739E0, func_02173A04, func_02173A24, func_02173A48, func_02173A68, func_02173A90, func_02173AC4, func_02173AFC, func_02173B1C, func_02173B4C, func_02173B78, func_02173BB0, func_02173BFC, func_02173C64, func_02173C8C, func_02173CB4
 * address:  0x02173934
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012138 0x02012138 thumb
 *   func_02026474 0x02026474 thumb
 *   func_02034714 0x02034714 arm
 *   d_02175624 0x02175624 data a1
 *   func_02172EDC 0x02172EDC thumb ov012
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02087C6C 0x02087C6C arm
 *   func_02012950 0x02012950 thumb
 *   func_02008494 0x02008494 thumb
 *   func_02008468 0x02008468 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_021CD624  0x021CD624  thumb  ov021
 */
#include "../../matched/include/Obj12445.h"
#include "../../matched/include/Obj19250.h"
#include "../../matched/include/Obj19251.h"
#include "../../matched/include/Obj19252.h"
#include "../../matched/include/Obj19253.h"
#include "../../matched/include/Obj12446.h"
#include "../../matched/include/Obj12447.h"
#include "../../matched/include/Obj19256.h"
#include "../../matched/include/Obj19258.h"
#include "../../matched/include/Obj19260.h"

struct Ctx;
struct Entry;
struct Link;
struct Sub24;
struct Rec44;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct { u8 pad[6]; u8 flag; u8 tail; } Packet;

typedef struct { u8 pad[0x5a]; u8 low:2; u8 mode:2; u8 high:4; } Sub_02173AC4;

typedef struct { u8 pad[0x5d]; u8 flag; } Sub_02173B78;

typedef struct { u8 pad[0x2830]; Sub_02173B78 sub; } Work;

extern u32 func_02012138(const struct Ctx *p);
extern u32 func_02026474(void *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02172EDC(u8 *p);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_0203D1A4(struct Link *p);
extern void func_02082D44(void *src, void *dst, u32 n);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02087C6C(void *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void func_02008494(void *src, void *dst);
extern int func_02008468(void);
extern u8 *func_02012944(void *p);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void *func_020120F4(const struct Ctx *p);
extern void func_021CD624(u8 *p, int i, u32 a, u32 b, void *c);
void func_02173934(u8 *p, int v);
u8 func_02173940(u8 *p);
int func_0217394C(const struct Ctx *p);
u8 *func_02173984(int a, u8 *b, int c);
void func_021739A8(int a, int b, void *c, u8 *p);
int func_021739CC(void);
void func_021739E0(u32 a, int b, u32 *c, u8 *p);
int func_02173A04(int a, int b, int c, int d);
void func_02173A24(u32 a, int b, u32 *c, u8 *p);
int func_02173A48(int a, int b, int c, int d);
void func_02173A68(u32 a, int b, void *c, u8 *p);
int func_02173A90(void);
void func_02173AC4(u32 a, int b, u32 *c, u8 *p);
int func_02173AFC(int v);
void func_02173B1C(u32 a, int b, void *c, u8 *p);
int func_02173B4C(u8 *p);
void func_02173B78(u32 a, u32 b, const void *c, u8 *p);
u32 func_02173BB0(unsigned char *p);
void func_02173BFC(int a, int x, u8 *b, u8 *p);
void func_02173C64(int a, int b, u32 *value, u8 *p);
void func_02173C8C(int a, int b, int c, u8 *p);
int func_02173CB4(void);
extern const char d_02175624[];


/*
 * Unlabelled leaf (no lr save) in the ov012 listing: stores the byte at
 * +0x2832. Callee of ov031 func_021F00D4 (a blocker of its MATCH).
 */
void func_02173934(u8 *p, int v)
{
    p[0x2832] = v;
}


/*
 * Unlabelled leaf (no lr save) in the ov012 listing: reads the byte at
 * +0x2832. Callee of ov031 func_021EFEC0 (a blocker of its MATCH).
 */
u8 func_02173940(u8 *p)
{
    return p[0x2832];
}

/*
 * 02012138 reads incoming r0; its u32 handle feeds 02026474(void *).
 */
int func_0217394C(const struct Ctx *p)
{
    u8 *w = (u8 *)func_02026474((void *)func_02012138(p));
    if (w == 0) return 0;
    if ((w[0x2831] == 0 || w[0x2831] == 0x2a) && w[0x3563] == 0) return 1;
    return 0;
}

u8 *func_02173984(int a, u8 *b, int c)
{
    if (c > 0x800) func_02034714(d_02175624, 0, d_02175624);
    return b + 4 + a * 0x800;
}

void func_021739A8(int a, int b, void *c, u8 *p)
{
    func_02172EDC(p);
    p[0x288e] |= (u8)(1 << a);
}

/*
 * Caller reads live r0 after 020399A8 and return from send wrapper.
 */
int func_021739CC(void)
{
    return func_0203D3A8(func_020399A8(), 0x1400, 0, 0);
}

void func_021739E0(u32 a, int b, u32 *c, u8 *p)
{
    u8 *q = p + 0x2830;
    if (a != func_0203D1A4((struct Link *)func_020399A8())) q[0x2d] = *c;
}


int func_02173A04(int a, int b, int c, int d)
{
    return func_0203D3A8(func_020399A8(), 0x1401, 4, (u32)(&a));
}

/*
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 * Extent reaches existing matched func_02173A48's initial push.
 */
void func_02173A24(u32 a, int b, u32 *c, u8 *p)
{
    u8 *q = p + 0x2830;
    if (a != func_0203D1A4((struct Link *)func_020399A8())) q[0x2e] = *c;
}


/*
 * Varargs function whose listing label (func_02173A4A) sits after the
 * push {r0-r3} home area; ov019 calls it at 0x02173A48.
 */
int func_02173A48(int a, int b, int c, int d)
{
    return func_0203D3A8(func_020399A8(), 0x1402, 4, (u32)(&a));
}

/*
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 */
void func_02173A68(u32 a, int b, void *c, u8 *p)
{
    u8 *q = p + 0x2830;
    if (a != func_0203D1A4((struct Link *)func_020399A8())) func_02082D44(c, q + 0x24, 8);
}

/*
 * 020399A8 leaves the used r0 payload live. Send forwards its pointer
 * unchanged as a full-word payload (matched send wrapper).
 */
int func_02173A90(void)
{
    Packet p;
    func_02082BCC(&p, 0, 8);
    func_02087C6C(&p);
    p.flag = 1;
    return func_0203D3A8(func_020399A8(), 0x1403, 8, (u32)&p);
}

/*
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 * Extent reaches existing matched func_02173AFC's initial push.
 */
void func_02173AC4(u32 a, int b, u32 *c, u8 *p)
{
    Sub_02173AC4 *q = (Sub_02173AC4 *)(p + 0x2830);
    if (a != func_0203D1A4((struct Link *)func_020399A8())) q->mode = (u8)*c;
}


/*
 * Opens with push {r0-r3} before the listing's func_02173AFE label: the
 * address of the register parameter is taken. Blocker of ov019
 * func_0217BE64's two calls.
 *
 * Addresses are Black-image addresses.
 */
int func_02173AFC(int v)
{
    return func_0203D3A8(func_020399A8(), 0x1404, 4, (u32)(&v));
}

void func_02173B1C(u32 a, int b, void *c, u8 *p)
{
    func_02008494(c, func_02012950(*(struct Sub24 * *)&((struct Obj19250 *)(*(u8 * *)&((struct Obj12445 *)p)->f0))->f8, a));
    p[0x288b] |= (u8)(1 << a);
}

/*
 * Live r0 return and narrowed third argument observed at send call;
 * matched wrapper copies fourth full-word payload unchanged.
 */
int func_02173B4C(u8 *p)
{
    u32 link;
    int n;
    link = (u32)func_020399A8();
    n = func_02008468();
    return func_0203D3A8((struct Entry *)link, (u16)0x1405, (u16)n, (u32)func_02012944(((struct Obj19252 *)(*(u8 * *)&((struct Obj19251 *)p)->f0))->f8));
}

/*
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 * Enum-typed local offset keeps 0x2830 and the +0x5d field add separate;
 * raw/nested pointer arithmetic and an inline setter folded to 0x288d.
 */
void func_02173B78(u32 a, u32 b, const void *c, u8 *p)
{
    if (a != func_0203D1A4((struct Link *)func_020399A8())) {
        enum { OFFSET = 0x2830 } off = OFFSET;
        Sub_02173B78 *q = (Sub_02173B78 *)(p + off);
        q->flag = 1;
        func_02082D44((void *)c, ((struct Obj19253 *)p)->f3544, b);
    }
}


u32 func_02173BB0(unsigned char *p)
{
    if (((struct Obj12446 *)p)->f3540 == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
    }
    return func_0203D3F8((u32)func_020399A8(), 0xff, 0x1406, 0x678, ((struct Obj12446 *)p)->f3540, 1, 0, 1);
}


void func_02173BFC(int a, int x, u8 *b, u8 *p)
{
    int *r4;
    int r7;
    int buf[2];

    r4 = *(int * *)&((struct Obj12447 *)p)->f355C;
    r7 = (int)func_020120F4((const struct Ctx *)(((struct Obj19256 *)(*(u8 * *)&((struct Obj12447 *)p)->f0))->fC));
    if (r4 == 0 || r4[0] == 0 || r4[0x5a] == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
        return;
    }
    func_02087C6C(buf);
    func_021CD624((u8 *)r4[0x5a], a, (int)func_02012944((void *)r7), b[0x27], buf);
}


void func_02173C64(int a, int b, u32 *value, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj19258 *)p)->f355C;
    if (q == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
        return;
    }
    q[0xDE] = *value;
}


void func_02173C8C(int a, int b, int c, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj19260 *)p)->f355C;
    if (q == 0) {
        func_02034714((void *)0x02175624, 0, (void *)0x02175624);
        return;
    }
    q[0xCA] = 1;
}


int func_02173CB4(void)
{
    return func_0203D3A8(func_020399A8(), 0x1409, 0, 0);
}
