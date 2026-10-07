/*
 * file:     fldeff_ripple_p05.c
 * unit:     yes
 * function: func_021C3F60, func_021C3FC0, func_021C4018
 * address:  0x021C3F60
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
 *   func_02005728  0x02005728  thumb  ov021
 *   func_02017E1C  0x02017E1C  thumb
 *   d_021DA918     0x021DA918  data  ov021  a4
 *   func_02008530  0x02008530  thumb
 */
#include "../../matched/include/Obj20193.h"

struct Sub0200852CObj;
typedef unsigned int u32;

typedef unsigned char u8;

typedef struct { u32 v[6]; } T;

extern u32 func_02005728(u32 n);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
u32 func_02008530(const struct Sub0200852CObj *obj);
void func_021C3F60(int a, u32 *p);
void func_021C3FC0(u32 *a, u32 *b);
void func_021C4018(int a, char *p);
extern T d_021DA918;


void func_021C3F60(int a, u32 *p)
{
    while (p[0x22] < 3) {
        u32 r = func_02005728(6);

        if (func_02005728(2) == 0) {
            if (p[0x16 + r] == 0 && p[0x1c + r] == 0) {
                p[0x16 + r] = 1;
                p[0x22]++;
            }
        } else {
            if (p[0x16 + r] == 0 && p[0x1c + r] == 0) {
                p[0x1c + r] = 1;
                p[0x22]++;
            }
        }
    }
}


void func_021C3FC0(u32 *a, u32 *b)
{
    T t = d_021DA918;
    u32 *pt = t.v;
    int i;

    for (i = 0; i < 6; i++) {
        u32 *e = b + i;

        if (e[0x16] != 0)
            e[6] = func_02017E1C((void *)a[0], pt[i], 0);
        if (e[0x1c] != 0)
            e[6] = func_02017E1C((void *)a[1], pt[i], 0);
    }
}


void func_021C4018(int a, char *p)
{
    ((struct Obj20193 *)p)->f30 = func_02008530((const struct Sub0200852CObj *)a);
}
