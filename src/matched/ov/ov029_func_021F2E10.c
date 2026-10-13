/*
 * function: C_GEAR_CreateFadeFx
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
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
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
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorDrawEnable(struct Obj *a, unsigned int b);

void C_GEAR_CreateFadeFx(char *p, int *q)
{
    S s;

    s.a = 0;
    s.b = 0;
    s.c = 0x25;
    s.d = 0;
    s.e = 2;
    q[2] = (int)CLACT_CreateActor((void *)((struct Obj04309 *)p)->f34, ((struct Obj04309 *)p)->f2C, ((struct Obj04309 *)p)->f28,
                         ((struct Obj04309 *)p)->f30, &s, 0, ((struct Obj04309 *)p)->fC);
    CLACT_SetActorDrawEnable((struct Obj *)q[2], 0);
    q[3] = ((struct Obj04309 *)p)->f210;
    q[4] = ((struct Obj04309 *)p)->f204;
}
