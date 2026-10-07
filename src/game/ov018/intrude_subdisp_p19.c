/*
 * file:     intrude_subdisp_p19.c
 * unit:     yes
 * function: func_0218034C, func_021803F0, func_021804F8
 * address:  0x0218034C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02034714  0x02034714  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_021829F8  0x021829F8  thumb ov018
 *   func_02180978  0x02180978  thumb ov018
 *   d_02183B30  0x02183B30  data ov018 a1
 *   d_02183B44  0x02183B44  data ov018 a1
 *   d_021837C4  0x021837C4  data ov018 a4
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02175DCC  0x02175DCC  thumb  ov011
 *   func_02175BCC  0x02175BCC  thumb  ov011
 *   func_02175B14  0x02175B14  thumb  ov011
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_0217620C  0x0217620C  thumb  ov011
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02188C84  0x02188C84  thumb ov021
 *   func_02180538  0x02180538  thumb ov018
 */
#include "../../matched/include/Obj12503.h"
#include "../../matched/include/Obj19375.h"
#include "../../matched/include/Obj12504.h"

struct Ctx;
struct BigObj;
struct Desc;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { u8 pad : 5; u8 f : 1; u8 rest : 2; } Bf;

void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u32 func_020307B0(void *p);
void func_02034714(const char *expr, u32 line, const char *file);
void MI_CpuCopy8(const void *src, void *dst, unsigned int n);
void func_021829F8(void *a, void *b);
void func_02180978(int x, void *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012B58(const struct BigObj *p);
extern int func_02175DCC(void *p);
extern u8 *func_02175BCC(u8 *p);
extern int func_02175B14(u8 *);
extern int func_02175B8C(u8 *);
extern int func_0217620C(u8 *, int);
void *func_0201210C(const struct Ctx *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void func_02082BCC(void *p, int v, int n);
u16 func_02188C84(u8 *p);
int func_02180538(void);
void func_0218034C(int x, u8 *y);
int func_021803F0(u8 *a, u8 *b);
void *func_021804F8(void *p, int a);
extern char d_02183B30[];
extern char d_02183B44[];

extern void (*d_021837C4[])(int, void *);


void func_0218034C(int x, u8 *y)
{
    void *p = func_02030734((u16)((((struct Obj12503 *)y)->f0 & 0x7fff) | 0x8000), 0x98, 1, d_02183B30, 0x354);
    unsigned int c;

    MI_CpuCopy8(y, p, 0x98);
    c = y[0x41];
    if (c == 0) {
        func_02180978(x, p);
    } else if (c == 1) {
        func_021829F8((void *)x, p);
    } else if (c == 2) {
        func_02180978(x, p);
    } else if (c >= 3) {
        if (d_021837C4[c - 8] == 0) {
            func_02034714(d_02183B44, 0, d_02183B44);
        }
        d_021837C4[y[0x41] - 8](x, p);
    } else {
        func_02180978(x, p);
    }
    func_020307B0(p);
}


static inline int state(u8 *a, u8 *b, u8 cur)
{
    if (func_02175BCC(b + 0x1AC) == 0 && func_02175B14(b + 0x1AC) == 1) {
        if (func_02175B8C(b + 0x1AC) == 1) {
            if (func_0217620C(b + 0x1AC, a[0x40]) == 1)
                return 3;
            if (((Bf *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
                return 4;
            return 5;
        }
        if (func_0217620C(b + 0x1AC, cur) == 1) {
            if (((Bf *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
                return 6;
            return 7;
        }
        if (((Bf *)(b + a[0x40] * 0x1C + 0xA6))->f == 1)
            return 1;
        if (func_0217620C(b + 0x1AC, a[0x40]) == 1)
            return 2;
        return 0;
    }
    return 0;
}


int func_021803F0(u8 *a, u8 *b)
{
    u8 cur;
    int kind;
    int r;

    cur = (int)func_02012B58((const struct BigObj *)((int)func_020120F4(func_02188C80(((struct Obj19375 *)a)->fC))));
    kind = func_02175DCC(b + 0x1AC);
    r = state(a, b, cur);
    if (r >= 3) {
        switch (kind) {
        case 0: r += 8; break;
        case 1: r += 13; break;
        case 2: r += 18; break;
        case 3: r += 23; break;
        case 4: r += 28; break;
        case 5: r += 33; break;
        }
        r -= 3;
    }
    return r;
}


void *func_021804F8(void *p, int a)
{
    void *v = func_0201210C(p);
    void *r = func_020122C0(p, 0, func_02180538, 0x138);
    u16 *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x138);
    *q = func_02188C84(v);
    ((struct Obj12504 *)q)->f34 = a;
    return r;
}
