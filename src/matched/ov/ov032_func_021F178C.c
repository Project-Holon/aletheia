/*
 * function: func_021F178C
 * address:  0x021F178C
 * packet:   pkt_ov032_021F178C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F178C 0x021F178C thumb
 *   func_021F17D8 0x021F17D8 thumb
 *   func_020311B8 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj04311.h"
#include "../include/Obj20428.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct S02030FB4;
extern void func_021F17D8(void *task, u8 *q);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void func_02082BCC(void *p, int v, int n);

void func_021F178C(char *this, u8 a, int *p)
{
    u8 *r;
    int v;

    r = TCBL_GetWork(func_020311B8(((struct Obj20428 *)this)->fA0, (void *)func_021F17D8, 0xc, 0));
    func_02082BCC(r, 0, 0xc);
    r[0] = a;
    if (r[0] == 0) {
        r[3] = 0;
        v = 0x10;
    } else {
        v = 0x40;
        r[3] = v;
        v -= 0x50;
    }
    r[4] = v;
    r[1] = 4;
    *(int * *)&((struct Obj04311 *)r)->f8 = p;
    *p = *p + 1;
}
