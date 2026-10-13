/*
 * function: C_GEAR_CreateSplashActors
 * address:  0x021F1B50
 * packet:   pkt_ov029_021F1B50
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   func_0204B92C  0x0204B92C  arm
 */
#include "../include/Obj06128.h"

typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned char a;
    unsigned char b;
} S13Rec;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *, unsigned int);
typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
extern void CLACT_RestartActorAnim(struct Actor *a);
struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);

void C_GEAR_CreateSplashActors(char *p)
{
    int i;
    S13Rec s;
    int *q;

    for (i = 0; i < 18; i++) {
        s.x = 0x80;
        s.y = 0x60;
        s.z = i + 0x12;
        s.a = 0;
        s.b = 2;
        q = (int *)(p + i * 4);
        q[0x5c] = (int)CLACT_CreateActor((void *)((struct Obj06128 *)p)->f34, ((struct Obj06128 *)p)->f2C, ((struct Obj06128 *)p)->f28,
                                ((struct Obj06128 *)p)->f30, &s, 0, ((struct Obj06128 *)p)->fC);
        func_0204B3DC((struct Obj *)q[0x5c], 0);
        CLACT_SetActorAutoAnimSpeed((struct Actor *)q[0x5c], 0x2000);
        CLACT_RestartActorAnim((struct Actor *)q[0x5c]);
        func_0204B92C((struct Obj *)q[0x5c], 1);
    }
}
