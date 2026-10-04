/*
 * function: func_021F1418
 * address:  0x021F1418
 * packet:   pkt_ov032_021F1418
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F1418 0x021F1418 thumb
 *   func_021F0EA4 0x021F0EA4 thumb
 *   func_021F0ED0 0x021F0ED0 thumb
 *   func_021F150C 0x021F150C thumb
 *   func_021F1484 0x021F1484 thumb
 *   func_02031194 0x02031194 arm
 */
#include "../include/Obj01676.h"

typedef unsigned char u8;

struct TcblNode;
extern void func_021F0EA4(char *p, unsigned a);
extern void func_021F0ED0(char *p, int a);
extern void func_021F150C(u8 *this, u8 *p, void *s);
extern void func_021F1484(char *this, int a, u8 *b, u8 *c, void *s);
extern void func_02031194(struct TcblNode *n);

void func_021F1418(void *h, u8 *t)
{
    void *this;

    this = ((struct Obj01676 *)t)->fC;
    if (((struct Obj01676 *)t)->f10 > 0)
        return;
    if (t[0] == 0) {
        func_021F0EA4(((struct Obj01676 *)t)->f8, 1);
        if (((struct Obj01676 *)t)->f4 == 1) {
            func_021F150C(this, ((struct Obj01676 *)t)->f8, t + 0x10);
            func_021F0ED0(((struct Obj01676 *)t)->f8, 1);
        } else {
            func_021F1484(this, t[1], ((struct Obj01676 *)t)->f8, 0, t + 0x10);
        }
        t[0] = t[0] + 1;
        return;
    }
    if (*(int * *)&((struct Obj01676 *)t)->f14 != 0)
        *(*(int * *)&((struct Obj01676 *)t)->f14) = *(*(int * *)&((struct Obj01676 *)t)->f14) - 1;
    func_02031194(h);
}
