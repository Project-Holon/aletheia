/*
 * function: func_021F2E10
 * address:  0x021F2E10
 * packet:   pkt_ov029_021F2E10
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */
#include "../include/Obj04309.h"

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
} S;

struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *a, unsigned int b);

void func_021F2E10(char *p, int *q)
{
    S s;

    s.a = 0;
    s.b = 0;
    s.c = 0x25;
    s.d = 0;
    s.e = 2;
    q[2] = (int)func_0204B294((void *)((struct Obj04309 *)p)->f34, ((struct Obj04309 *)p)->f2C, ((struct Obj04309 *)p)->f28,
                         ((struct Obj04309 *)p)->f30, &s, 0, ((struct Obj04309 *)p)->fC);
    func_0204B3DC((struct Obj *)q[2], 0);
    q[3] = ((struct Obj04309 *)p)->f210;
    q[4] = ((struct Obj04309 *)p)->f204;
}
