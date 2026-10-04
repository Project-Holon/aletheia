/*
 * function: func_021C295C
 * address:  0x021C295C
 * packet:   pkt_021C295C
 * region:   ov217
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B294 0x0204B294 arm
 */
#include "../include/Obj08446.h"
#include "../include/Obj14767.h"

struct arg_021C295C {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
};

struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);

void func_021C295C(unsigned char *p)
{
    struct arg_021C295C s;
    int *q = (int *)(p + 0x20);
    int i;

    s.a = 0;
    s.b = 0;
    s.c = 0;
    s.d = 0;
    s.e = 0;
    for (i = 0; i < 4; i++) {
        *(int *)(p + 0x10 + i * 4) =
            (int)func_0204B294((void *)((struct Obj14767 *)p)->fC, q[0], q[1], q[2], &s,
                          ((struct Obj08446 *)q)->fC,
                          ((struct Obj14767 *)p)->f0);
    }
}
