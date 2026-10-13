/*
 * function: func_021D6600
 * address:  0x021D6600
 * packet:   pkt_021D6600
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   CLACT_RestartActorAnim  0x0204B9A0  arm  arm9
 */
#include "../include/Obj03255.h"
#include "../include/Obj22682.h"
#include "../include/Obj22683.h"
#include "../include/Obj22684.h"
#include "../include/Obj22685.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Actor;
extern void CLACT_RestartActorAnim(struct Actor *a);

void func_021D6600(void *p)
{
    u32 v = ((struct Obj22682 *)((char *)((struct Obj03255 *)p)->fC))->fB0;
    if (v == 0) {
        Local s;
        s.a = 0x80;
        s.b = 0x63;
        s.c = 0;
        s.d = 0;
        s.e = 0;
        ((struct Obj22683 *)((char *)((struct Obj03255 *)p)->fC))->fB0 =
            (u32)CLACT_CreateActor((void *)((struct Obj03255 *)p)->f9C4,
                          ((struct Obj03255 *)p)->f8A8,
                          ((struct Obj03255 *)p)->f88C,
                          ((struct Obj03255 *)p)->f8BC,
                          &s, 0, ((struct Obj03255 *)p)->f5F4);
        func_0204B92C((struct Obj *)((struct Obj22684 *)((char *)((struct Obj03255 *)p)->fC))->fB0, 1);
        func_0204B3DC((struct Obj *)((struct Obj22685 *)((char *)((struct Obj03255 *)p)->fC))->fB0, 1);
    } else {
        CLACT_RestartActorAnim((struct Actor *)v);
    }
}
