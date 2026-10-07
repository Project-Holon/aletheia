/*
 * file:     trial_house_p14.c
 * unit:     yes
 * function: func_021D0328, func_021D034C, func_021D038C, func_021D03B0, func_021D03C4, func_021D0440, func_021D046C
 * address:  0x021D0328
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
 *   func_020478B8  0x020478B8  arm
 *   data_021DB8F0  0x021DB8F0  data  ov021  a4
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   d_021DE618     0x021DE618  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 *   data_021DB92C  0x021DB92C  data  ov021  a2
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   d_021DB93C     0x021DB93C  data  ov021  a4
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 */
#include "../../matched/include/Obj12997.h"
#include "../../matched/include/Obj09743.h"

struct Arg;
struct W;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct St021D0328 {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u32 f4;
    u32 f8;
    u32 fC;
} St021D0328;

typedef struct V {
    u32 w[15];
} V;

typedef signed int     s32;

typedef struct T {
    u16 a;
    u16 b;
} T;

typedef struct W {
    u16 h[2];
    u32 f4;
    u16 g[2];
} W;

typedef struct Arg021D046C {
    u32 h1;
    u32 h2;
    u32 b;
    u32 c;
} Arg021D046C;

extern int func_020478B8(void *a, int idx, int amount);
extern void func_0207ADC4(void *a);
extern void func_021AC1B8(u32 a, V *v);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE24(u8 *p);
extern u32 func_021ABE18(u8 *p);
extern void func_021C6AE0(u32 a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 *, u16);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern u16 func_021C6590(u32, u32, u32, u32);
extern void func_021C67D8(u32, u32, u32);
extern u32 func_021C6628(u32, u32);
extern void func_021C6580(u8 *p, int i);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(void *a, void *b, u32 c, u32 d, void *e, u32 f);
void func_021D0328(void *unused, St021D0328 *p);
void func_021D034C(u32 a, u8 *b);
void *func_021D038C(u32 v, u32 heap);
void func_021D03B0(u32 a, u8 *p);
void func_021D03C4(W *p);
void func_021D0440(u16 *p);
void func_021D046C(void *a, u32 b, u32 c);
extern const V data_021DB8F0;
extern char d_021DE618[];
extern const T data_021DB92C[];
extern char d_021DB93C[];


void func_021D0328(void *unused, St021D0328 *p)
{
    if (p->f2 != 4) {
        p->f3 = 0;
        if (func_020478B8((void *)p->fC, p->f2, 0x1000) == 0) {
            p->f3 = 1;
        }
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D034C(u32 a, u8 *b)
{
    V v;

    if (b[1] == 0) {
        v = data_021DB8F0;
        func_0207ADC4(&v.w[6]);
        func_021AC1B8(a, &v);
        func_02047AC8((void *)(((struct Obj12997 *)b)->fC), (struct Arg *)(&v));
    }
}


void *func_021D038C(u32 v, u32 heap)
{
    u32 *p = func_02030734(heap, 0xc, 1, d_021DE618, 0x6b);

    p[1] = v;
    func_021D03C4((struct W *)p);
    return p;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021D03B0(u32 a, u8 *p)
{
    func_021D0440((u16 *)p);
    func_020307B0(p);
}


void func_021D03C4(W *p)
{
    u32 buf[9];
    u32 k;
    u32 h;
    int i = 0;
    const T *t = data_021DB92C;
    u16 *hp = (u16 *)p;
    u16 *q;

    k = func_021ABE24((u8 *)p->f4);
    h = func_021ABE18((u8 *)p->f4);
    for (; i < 2; i++, t++) {
        func_021C6AE0((u32)buf);
        func_021C6AF0((u32)buf, k, t->a);
        func_021C6AF8((u32 *)buf, k);
        func_021C6AFC(buf, t->b);
        q = hp + i;
        hp[i] = func_021C6574(h, (u32)buf, 0);
        q[4] = func_021C6590(h, hp[i], 0, 0);
        func_021C67D8(h, q[4], 1);
    }
}


void func_021D0440(u16 *p)
{
    int i = 0;
    u32 h = func_021ABE18((u8 *)(((struct Obj09743 *)p)->f4));

    for (; i < 2; i++) {
        func_021C6628(h, p[4 + i]);
        func_021C6580((u8 *)h, p[i]);
    }
}


void func_021D046C(void *a, u32 b, u32 c)
{
    Arg021D046C arg;

    arg.h1 = func_021ABEA0((u32)a, 0xf);
    arg.h2 = func_021ABE18(a);
    arg.b = b;
    arg.c = c;
    func_021ABFA8(a, d_021DB93C, 0, 0, &arg, 0);
}
