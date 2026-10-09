/*
 * file:     field_wfbc_p04.c
 * unit:     yes
 * function: func_02194354, func_02194384, func_021943EC, func_02194418, func_02194434
 * address:  0x02194354
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
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_02163C04  0x02163C04  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   d_021D3F68     0x021D3F68  data  ov021  a4
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_02194588  0x02194588  thumb  ov021
 *   func_021945A0  0x021945A0  thumb  ov021
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DC98  0x0216DC98  thumb  ov010
 *   func_0216DB80  0x0216DB80  thumb  ov010
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   func_0216DC64  0x0216DC64  thumb  ov010
 *   func_0216DCCC  0x0216DCCC  thumb  ov010
 */
#include "../../matched/include/Obj07448.h"
#include "../../matched/include/Obj12622.h"
#include "../../matched/include/Obj05859.h"
#include "../../matched/include/Obj19625.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_02194354;

typedef signed char    s8;

typedef struct { u32 key; u32 x4; u32 x8; } Item;

typedef struct { u16 n; u16 pad; u32 x4; Item *items; } List;

typedef short s16_02194384;

typedef struct Rec {
    u32 key;
    u32 f4;
    u32 val;
} Rec;

typedef struct Tbl {
    u16 n;
    u16 pad;
    u32 f4;
    Rec *recs;
} Tbl;

typedef signed short   s16;

typedef struct { unsigned w[9]; } T;

extern int func_0216D854(void *p);
extern int func_02163C04(int a, int x, int y, int flag);
extern u32 func_02082BCC(u32, u32, u32);
extern int func_0216CF2C(int a0, int a1);
extern void *func_0216CE60(void *a, void *b, int c);
extern void func_02194588(u32 a, u32 b, u32 c, u32 d, u32 e);
extern int func_021945A0(int x);
extern void func_0216E014(void *a, int *p, int b);
extern int func_0216DB4C(void *a0, int a1);
extern int func_0216DC98(void *a0, int a1);
extern void func_0216DB80(unsigned int *p, unsigned int v);
extern void func_0216DAE0(unsigned int *p, unsigned int v);
extern int func_0216DC64(void *a0, int a1);
extern int func_0216DCCC(void *a0, int a1);
void func_02194354(List *p, u32 key);
int func_02194384(u16 *a, s16_02194384 b, int c, s16_02194384 d, int *e, unsigned *f);
u32 func_021943EC(Tbl *t, u32 key);
int func_02194418(u32 a, int a1);
void *func_02194434(unsigned char *a, int x, u16 *q, int d, int e, int f);
extern T d_021D3F68;



/*
 * Addresses are Black-image addresses.
 */
void func_02194354(List *p, u32 key)
{
    Item *it;
    u16 i;

    it = p->items;
    for (i = 0; i < p->n; i++) {
        if (it->x8 != 0 && it->key == key) {
            func_02194418((u32)it, key);
            return;
        }
        it++;
    }
}



int func_02194384(u16 *a, s16_02194384 b, int c, s16_02194384 d, int *e, unsigned *f)
{
    unsigned n = *a;
    unsigned char *q;
    short dlt;

    if (*f < n) {
        q = *(unsigned char * *)&((struct Obj12622 *)a)->f8 + *f * 0xc;
        do {
            (*f)++;
            if (((struct Obj07448 *)q)->f8 != 0) {
                dlt = func_0216D854(((struct Obj07448 *)q)->f8) - c;
                if (dlt < 0)
                    dlt = -dlt;
                if (dlt < 1) {
                    if (func_02163C04((int)(((struct Obj07448 *)q)->f8), b, d, 1)) {
                        *e = ((struct Obj07448 *)q)->f0;
                        return 1;
                    }
                }
                q += 0xc;
            }
        } while (*f < n);
    }
    return 0;
}



/*
 * Unlabelled Thumb leaf (push {r4, r5} saves no lr): finds the record whose
 * key equals the argument among n 12-byte records and returns its +8 field,
 * or 0. Sole blocker of ov010 func_021679C4's callee relocation.
 */
u32 func_021943EC(Tbl *t, u32 key)
{
    u16 i;
    Rec *r;
    u16 n;

    n = t->n;
    i = 0;
    r = t->recs;
    for (; i < n; i++, r++) {
        if (r->val != 0 && r->key == key)
            return r->val;
    }
    return 0;
}



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02194418(u32 a, int a1)
{
if (((struct Obj05859 *)((u8 *)(a)))->f4 == 0) {
    func_0216CF2C(((struct Obj05859 *)((u8 *)(a)))->f8, a1);
}
return func_02082BCC(a, 0, 12);
}



void *func_02194434(unsigned char *a, int x, u16 *q, int d, int e, int f)
{
    void *m = ((struct Obj19625 *)a)->f4;
    T local = d_021D3F68;
    void *o;

    *(u16 *)((unsigned char *)&local + 2) = x;
    o = func_0216CE60(m, &local, 0);
    func_02194588((u32)o, (u32)q, d, e, f);
    func_0216E014(o, (int *)d, func_021945A0(*q));
    func_0216DB4C(o, 1);
    func_0216DC98(o, 1);
    func_0216DB80(o, 1);
    func_0216DAE0(o, 0);
    func_0216DC64(o, 1);
    func_0216DCCC(o, 1);
    return o;
}
