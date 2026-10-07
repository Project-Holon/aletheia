/*
 * file:     unit_02184D30_p02.c
 * unit:     yes
 * function: func_021852B4, func_021852F4, func_0218530C
 * address:  0x021852B4
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02186BEC  0x02186BEC  data  a2
 *   func_0204B878  0x0204B878  arm
 *   func_021850A0  0x021850A0  thumb  ov023
 *   func_02039338  0x02039338  arm
 *   func_02185F50  0x02185F50  thumb  ov023
 *   func_021860D0  0x021860D0  thumb  ov023
 *   func_02185EA0  0x02185EA0  thumb  ov023
 *   func_02185DE8  0x02185DE8  thumb  ov023
 */
#include "../../matched/include/Obj01221.h"

struct Obj;
struct P;
struct e6;
struct o4;
typedef unsigned short u16;

typedef unsigned int u32;

struct Ent {
    u16 a;
    u16 b;
    u16 c;
};

extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021850A0(char *p);
extern u16 func_02039338(void);
extern int func_02185F50(char *p);
extern void func_021860D0(char *p);
extern void func_02185EA0(struct P *p);
extern void func_02185DE8(char *p, struct e6 *e, struct o4 *o, int flag);
void func_021852B4(u32 *p, int n);
void func_021852F4(void *p, int flag);
int func_0218530C(char *p, int x);
extern struct Ent d_02186BEC[];


void func_021852B4(u32 *p, int n)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (i == n)
            func_0204B878((struct Obj *)p[i], (u16)(d_02186BEC[i].c + 1));
        else
            func_0204B878((struct Obj *)p[i], d_02186BEC[i].c);
    }
}

void func_021852F4(void *p, int flag)
{
    if (flag == 1)
        func_0204B878(p, 9);
    else
        func_0204B878(p, 1);
}


int func_0218530C(char *p, int x)
{
    func_021850A0(p);
    if (func_02039338() == 0) {
        if (func_02185F50(p) == 1) {
        } else {
            func_021860D0(p);
        }
    } else {
        func_021860D0(p);
    }
    func_02185EA0((struct P *)p);
    func_02185DE8((char *)(((struct Obj01221 *)p)->f118), (struct e6 *)(p + 0x4212), (struct o4 *)(p + 0x4230), 1);
    return x;
}
