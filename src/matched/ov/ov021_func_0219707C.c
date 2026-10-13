/*
 * function: IRCBATTLEMENU_CreateTopMenuActors
 * address:  0x0219707C
 * packet:   pkt_ov021_0219707C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   IRCBATTLEMENU_DeleteMenuActors  0x02197058  thumb  ov021
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   sTopMenuActorPosX     0x021D3FC8  data  ov021  a1
 *   sTopMenuActorPosY     0x021D3FB0  data  ov021  a1
 *   sTopMenuActorAnim     0x021D3FA8  data  ov021  a1
 */
#include "../include/Obj00093.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u8 v[5]; } B5;
typedef struct { u16 x; u16 y; u16 z; u8 a; u8 b; } Pos;

extern void IRCBATTLEMENU_DeleteMenuActors(u8 *p);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
extern void CLACT_SetActorDrawEnable(struct Obj *obj, unsigned int on);
struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern B5 sTopMenuActorPosX;
extern B5 sTopMenuActorPosY;
extern B5 sTopMenuActorAnim;

void IRCBATTLEMENU_CreateTopMenuActors(u8 *p)
{
    B5 xs = sTopMenuActorPosX;
    B5 ys = sTopMenuActorPosY;
    B5 zs = sTopMenuActorAnim;
    Pos pos;
    int i;

    IRCBATTLEMENU_DeleteMenuActors(p);
    for (i = 0; i < 5; i++) {
        pos.x = xs.v[i];
        pos.y = ys.v[i];
        pos.z = zs.v[i];
        pos.a = 0;
        pos.b = 1;
        *(u32 *)(p + i * 4 + 0x294) = (u32)CLACT_CreateActor((void *)*(u32 *)&((struct Obj00093 *)p)->f26C, *(u32 *)&((struct Obj00093 *)p)->f27C,
            *(u32 *)&((struct Obj00093 *)p)->f274, *(u32 *)&((struct Obj00093 *)p)->f284, &pos, 1, ((struct Obj00093 *)p)->f10);
        CLACT_SetActorAutoAnim((struct Obj *)*(u32 *)(p + i * 4 + 0x294), 0);
        CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p + i * 4 + 0x294), 1);
        CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + i * 4 + 0x294)), 1);
    }
}
