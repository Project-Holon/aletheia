/*
 * function: func_021F21B0
 * address:  0x021F21B0
 * packet:   pkt_ov032_021F21B0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F21B0 0x021F21B0 thumb
 *   func_021F21F8 0x021F21F8 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj07637.h"
#include "../include/Obj20452.h"
#include "../include/Obj20453.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct S02030FB4;
extern void func_021F21F8(void *task, char *q);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_02082BCC(void *p, int v, int n);

void func_021F21B0(char *p, char *q, int *r)
{
    void *t;
    u8 *s;

    t = func_020311B8(((struct Obj20452 *)p)->fA0, (void *)func_021F21F8, 0x10, 0);
    s = func_02031290(t);
    func_02082BCC(s, 0, 0x10);
    *(char * *)&((struct Obj07637 *)s)->f8 = p;
    *(char * *)&((struct Obj07637 *)s)->f0 = q;
    *(char * *)&((struct Obj07637 *)s)->f4 = q + 0x18;
    ((struct Obj20453 *)q)->f2C = t;
    if (r != 0) {
        *(int * *)&((struct Obj07637 *)s)->fC = r;
        (*r)++;
    }
}
