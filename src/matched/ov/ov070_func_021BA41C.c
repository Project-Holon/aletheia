/*
 * function: func_021BA41C
 * address:  0x021BA41C
 * packet:   pkt_ov070_021BA41C
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB398  0x021BB398  thumb  ov070
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_020355C4  0x020355C4  arm
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_0204B3DC  0x0204B3DC  arm
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 */
#include "../include/Obj01365.h"

typedef struct {
    unsigned short a, b;
} Pt;

typedef unsigned int   u32;
struct CodeIn;
extern void func_021BB398(int p, u32 val);
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
typedef unsigned char  u8;
extern u8 func_020355C4(void);
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);
extern int func_021B61C8(u8 *p);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void CLACT_SetActorAnimIndex(int, int);

void func_021BA41C(char *p)
{
    Pt pt;
    func_021BB398((int)p, 0);
    func_0204B454((struct Actor *)((struct Obj01365 *)p)->f6A4, (struct PtS *)&pt, 0xFFFF);
    pt.b = (((struct Obj01365 *)p)->f810 + 1) * 0x18;
    func_0204B404((struct Obj *)(((struct Obj01365 *)p)->f6A4), (const struct Vec2 *)(&pt), 0xFFFF);
    if (func_020355C4() == 0) {
        func_021BB398((int)p, 1);
    }
    BLINK_PALANM_ResetPhase((struct CodeIn *)(((struct Obj01365 *)p)->f850));
    func_0204B3DC((struct Obj *)((struct Obj01365 *)p)->f6A8, func_021B61C8((u8 *)p) >= 7);
    CLACT_SetActorAnimIndex(((struct Obj01365 *)p)->f6A4, 0);
    CLACT_SetActorAnimIndex(((struct Obj01365 *)p)->f6A8, 0);
}
