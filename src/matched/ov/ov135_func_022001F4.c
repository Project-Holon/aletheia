/*
 * function: WORLDTRADE_TITLE_CreateActors
 * address: 0x022001F4
 * packet: pkt_ov135_022001F4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_020355C4 0x020355C4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   d_022038E0 0x022038E0 data a2
 */
#include "../include/Obj02862.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x, y, z; u8 pri, f7; } ObjPos;
typedef struct { u16 x, y; } Pair;
extern const Pair d_022038E0[];
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u8 func_020355C4(void);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
void WORLDTRADE_TITLE_CreateActors(u8 *p)
{
    ObjPos pos;
    pos.x = d_022038E0[*(u16 *)(p + 0xC0)].x;
    pos.y = d_022038E0[*(u16 *)(p + 0xC0)].y;
    pos.z = 0;
    pos.pri = 0;
    pos.f7 = 1;
    ((struct Obj02862 *)p)->fBF4 = CLACT_CreateActor(((struct Obj02862 *)p)->fBC0, (unsigned int)((struct Obj02862 *)p)->fBE8, (unsigned int)((struct Obj02862 *)p)->fBC8, (unsigned int)((struct Obj02862 *)p)->fBF0, &pos, 0, 0x48);
    CLACT_SetActorAutoAnim(((struct Obj02862 *)p)->fBF4, 1);
    CLACT_SetActorAnimSeq(((struct Obj02862 *)p)->fBF4, 0);
    if (func_020355C4() == 1) {
        CLACT_SetActorDrawEnable(((struct Obj02862 *)p)->fBF4, 0);
    } else {
        CLACT_SetActorAnimSeq(((struct Obj02862 *)p)->fBF4, 0);
        CLACT_SetActorDrawEnable(((struct Obj02862 *)p)->fBF4, 1);
    }
    GFL_NET_RestartWithDefaultTimeout(0, 0x48);
}
