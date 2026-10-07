/*
 * file:     btlv_effvm_p81.c
 * unit:     yes
 * function: func_02201934, func_022019F4, func_02201A20, func_02201A8C
 * address:  0x02201934
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02209FC8  0x02209FC8  data  ov094
 *   d_02209FD0  0x02209FD0  data  ov094
 *   d_0220A008  0x0220A008  data  ov094
 *   d_0220A020  0x0220A020  data  ov094
 *   d_0220A038  0x0220A038  data  ov094
 *   d_0220A1E8  0x0220A1E8  data  ov094
 *   d_0220A1EA  0x0220A1EA  data  ov094
 *   d_0220A1EC  0x0220A1EC  data  ov094
 *   d_0220A1EE  0x0220A1EE  data  ov094
 *   d_0220AE88  0x0220AE88  data  a4
 */
#include "../../matched/include/Obj12236.h"

struct Bank;
typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags;

typedef struct {
    char pad[0x510];
    Flags flags;
} Unit;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct {
    u16 key : 14;
    u16 flag : 1;
    u16 hi : 1;
} Ent;

typedef struct Res {
    void *owner;
    void *h;
    char pad[0x80 - 8];
    u16 heap;
} Res;

typedef unsigned char  u8;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
int func_02201934(Unit *u, int i, int mode);
int func_022019F4(char *p, int key);
int func_02201A20(int a, int b, int *o1, u16 *o2, int *o3);
Res *func_02201A8C(void *owner, u16 heap);
extern const int d_02209FC8[];
extern const int d_02209FD0[];
extern const int d_0220A008[];
extern const int d_0220A020[];
extern const int d_0220A038[];
extern const char d_0220A1E8[];
extern const char d_0220A1EA[];
extern const char d_0220A1EC[];
extern const char d_0220A1EE[];
extern const char d_0220AE88[];


int func_02201934(Unit *u, int i, int mode)
{
    if (mode == 0) {
        switch (i) {
        case 0:
        case 1:
            return d_02209FC8[i];
        case 2:
        case 3:
        case 4:
        case 5:
            if (u->flags.b1)
                return d_0220A008[i - 2];
            if (u->flags.b0)
                return d_0220A038[i - 2];
            return d_02209FD0[i - 2];
        case 6:
        case 7:
            if (u->flags.b1)
                return d_0220A008[i - 2];
            return d_0220A038[i - 2];
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            return d_0220A020[i - 8];
        }
    } else {
        if (i < 8) {
            if (i & 1)
                return 0x10000;
            return 0x20000;
        }
        return 0x10000;
    }
}


/*
 * lane O10 candidate
 */
int func_022019F4(char *p, int key)
{
    int i;

    for (i = 0; i < 14; i++) {
        char *e = p + i * 0x5c;

        if (((struct Obj12236 *)e)->f8 != 0 && key == ((struct Obj12236 *)e)->f50)
            return i;
    }
    return -1;
}


/*
 * lever: `(b & 1) == e->flag` written inline in the condition; a hoisted local `f = b & 1` costs a different register order.
 */
int func_02201A20(int a, int b, int *o1, u16 *o2, int *o3)
{
    int found = 0;
    unsigned i;

    for (i = 0; i < 0x30; i++) {
        const Ent *e = (const Ent *)(d_0220A1E8 + i * 8);
        unsigned o = i * 8;

        if (a == e->key && (b & 1) == e->flag) {
            o1[0] = *(const s16 *)(d_0220A1EA + o);
            o1[1] = 0;
            o1[2] = *(const s16 *)(d_0220A1EC + o);
            *o2 = *(const u16 *)(d_0220A1EE + o);
            *o3 = e->hi;
            found = 1;
            break;
        }
    }
    return found;
}


Res *func_02201A8C(void *owner, u16 heap)
{
    Res *r = func_02030734(heap, 0x84, 1, d_0220AE88, 0x4f);
    r->owner = owner;
    r->heap = heap;
    r->h = func_0204B100(7, 0, heap);
    return r;
}
