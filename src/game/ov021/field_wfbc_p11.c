/*
 * file:     field_wfbc_p11.c
 * unit:     yes
 * function: func_02194354, func_02194384, func_021943EC
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
 *   func_02194418  0x02194418  thumb  ov021
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_02163C04  0x02163C04  thumb  ov010
 */
#include "../../matched/include/Obj07448.h"
#include "../../matched/include/Obj12622.h"

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

extern int func_02194418(u32 a, int a1);
extern int func_0216D854(void *p);
extern int func_02163C04(int a, int x, int y, int flag);
void func_02194354(List *p, u32 key);
int func_02194384(u16 *a, s16_02194384 b, int c, s16_02194384 d, int *e, unsigned *f);
u32 func_021943EC(Tbl *t, u32 key);


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
