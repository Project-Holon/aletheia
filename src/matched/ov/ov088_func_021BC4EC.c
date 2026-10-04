/*
 * function: func_021BC4EC
 * address:  0x021BC4EC
 * packet:   pkt_ov088_021BC4EC
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: inferred extent runs two bytes long; the follower is an unlabelled
 * padding pair.
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_021BC62C  0x021BC62C  thumb  ov088
 *   func_021BC75C  0x021BC75C  thumb  ov088
 */
#include "../include/Obj09923.h"

extern void func_0203064C(unsigned int, unsigned int, unsigned int);
extern char *func_0203159C(int, int, int);
extern void func_021BC62C(char *);
extern void func_021BC75C(char *);

int func_021BC4EC(int a, int b, int *c)
{
    char *r;
    func_0203064C(1, 0x39, 0x80000);
    r = func_0203159C(a, 0x1c, 0x39);
    if (*c == 0)
        ((struct Obj09923 *)r)->f4 = 0;
    else
        ((struct Obj09923 *)r)->f4 = 2;
    ((struct Obj09923 *)r)->f18 = 0;
    func_021BC62C(r);
    func_021BC75C(r);
    return 1;
}
