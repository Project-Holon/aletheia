/*
 * file:     field_msgbg_p10.c
 * unit:     yes
 * function: func_0218BA04, func_0218BA48, func_0218BA70, func_0218BA98, func_0218BACC, func_0218BB04, func_0218BB0C
 * address:  0x0218BA04
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
 *   func_0218BBD0  0x0218BBD0  thumb  ov021
 *   func_0218C4A0  0x0218C4A0  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   func_0204961C  0x0204961C  arm
 *   func_02049250  0x02049250  arm
 *   func_02049238  0x02049238  arm
 */
#include "../../matched/include/Obj00572.h"

struct ArcFile;
/*
 * The const on s is load-bearing: it settles the store order and keeps the
 * move of d into r3 next to the call.
 */
typedef struct {
    int x;
    int y;
    int z;
    unsigned short w;
    unsigned char hi;
    unsigned char lo;
} Src;

typedef struct {
    int k;
    int x;
    int y;
    int z;
    unsigned short w;
} Args;

typedef struct {
    unsigned char pad[0x1DC];
    void *arr[7];
} S;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

int func_0218BBD0(void *p, unsigned int i);
void func_0218C4A0(void *p, int a, Args *args, int d);
extern void *func_020490F4(u32 id, u32 heap);
extern u16 func_0204961C(void *obj);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void func_02049238(void *h);
void func_0218BA04(void *p, int a, const Src *s, int d);
void func_0218BA48(S *p, void *v);
void func_0218BA70(S *p, void *v);
void *func_0218BA98(S *p, int h);
unsigned short func_0218BACC(S *p, void *v);
u8 *func_0218BB04(u8 *p);
void func_0218BB0C(u8 *s, u16 a, u32 n);


static inline void Args_SetPos(Args *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}


void func_0218BA04(void *p, int a, const Src *s, int d)
{
    Args args;
    args.k = func_0218BBD0(p, (unsigned short)(s->lo + (s->hi << 8)));
    Args_SetPos(&args, s->x, s->y, -s->z);
    args.w = s->w;
    func_0218C4A0(p, a, &args, d);
}


void func_0218BA48(S *p, void *v)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (p->arr[i] == v) {
            p->arr[i] = 0;
            return;
        }
    }
}


void func_0218BA70(S *p, void *v)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (p->arr[i] == 0) {
            p->arr[i] = v;
            return;
        }
    }
}


void *func_0218BA98(S *p, int h)
{
    unsigned short idx = h & ~0xFFF0;
    if ((unsigned short)(h & 0xFFF0) != 0xFFF0)
        return 0;
    if (idx >= 7)
        return 0;
    return p->arr[idx];
}


unsigned short func_0218BACC(S *p, void *v)
{
    int i;
    if (v == 0)
        return 0;
    for (i = 0; i < 7; i++) {
        if (p->arr[i] == v)
            return 0xFFF0 | i;
    }
    return 0;
}


/*
 * Returns the object pointer advanced by 432 bytes.
 */
u8 *func_0218BB04(u8 *p)
{
    return p + 432;
}


void func_0218BB0C(u8 *s, u16 a, u32 n)
{
    void *h;
    u8 *r;

    h = func_020490F4(a, (u16)((((struct Obj00572 *)s)->f0 & 0x7fff) | 0x8000));
    if (func_0204961C(h) <= n)
        n = 0;
    r = func_02049250(h, n, ((struct Obj00572 *)s)->f0);
    *(u8 * *)&((struct Obj00572 *)s)->f18 = r;
    ((struct Obj00572 *)s)->f1AC = (u32)r[2] >> 1;
    if (((struct Obj00572 *)s)->f1AC > 0x190)
        ((struct Obj00572 *)s)->f1AC = 0x80;
    func_02049238(h);
}
