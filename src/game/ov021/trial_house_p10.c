/*
 * file:     trial_house_p10.c
 * unit:     yes
 * function: func_021CFA88, func_021CFAC0, func_021CFB1C, func_021CFB68
 * address:  0x021CFA88
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
 *   func_02008854  0x02008854  thumb
 *   func_02008990  0x02008990  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   d_021DB834  0x021DB834  data  a4
 */
#include "../../matched/include/Obj12992.h"
#include "../../matched/include/Obj12993.h"
#include "../../matched/include/Obj20274.h"

struct Big;
struct Ctx;
struct Sub02008828Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef struct {
    s16 a0;
    s16 a2;
    s16 a4;
    u16 a6;
} Row;

typedef struct {
    u16 v[10];
} Slot;

typedef struct {
    u8   pad[0x10];
    Slot slot[20];
} Slots;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_02008990(const struct Sub02008828Obj *obj);
int func_021CFA88(void *a, void *b);
int func_021CFAC0(u8 *base, int a, int b, int c, int d);
void func_021CFB1C(Slots *base, int i, Slot *dst);
const Row *func_021CFB68(u8 *base, int *idx);
extern const Row d_021DB834[];


int func_021CFA88(void *a, void *b)
{
    void *h;
    u16 *q;

    func_0215A5F4(b);
    h = func_02008854(func_02012EBC(func_020120F4((void *)func_0215A5DC(b))));
    q = func_02159AE8(a, b);
    *q = func_02008990(h);
    return 0;
}


/*
 * Searches the 20 slots (stride 0x14, from +0x10) for one whose table row matches.
 *
 * Addresses are Black-image addresses.
 */
int func_021CFAC0(u8 *base, int a, int b, int c, int d)
{
    int i;
    u8 *p = base + 0x10;

    for (i = 0; i < 20; i++, p += 0x14) {
        const Row *r;
        if (((struct Obj12992 *)p)->f10 == 0) {
            return 0xff;
        }
        r = &d_021DB834[p[0x12]];
        if (r->a6 == a && r->a0 == b && r->a4 == d && r->a2 - 1 <= c && c <= r->a2 + 1) {
            return i;
        }
    }
    return 0xff;
}


/*
 * func_021CFB1C removes slot i (copies it out, shifts the later ones down).
 * func_021CFB68 (unlabelled, 0x021CFB68) walks to the next used slot.
 *
 * Addresses are Black-image addresses.
 */
void func_021CFB1C(Slots *base, int i, Slot *dst)
{
    *dst = base->slot[i];
    for (i++; i < 20; i++) {
        base->slot[i - 1] = base->slot[i];
    }
    ((struct Obj20274 *)base)->f19C = 0;
}


const Row *func_021CFB68(u8 *base, int *idx)
{
    int i = *idx;

    if (i < 20) {
        do {
            u8 *p = base + i * 0x14;
            if (((struct Obj12993 *)p)->f20 != 0) {
                const Row *r = &d_021DB834[p[0x22]];
                (*idx)++;
                return r;
            }
            i = ++*idx;
        } while (i < 20);
    }
    return 0;
}
