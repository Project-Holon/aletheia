/*
 * function: GTSNEGO_DISP_CreateCursorActor
 * address: 0x021D69A0
 * packet: pkt_ov120_021D69A0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 0x021D69F2.
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 */
#include "../include/Obj00987.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Record { u16 x, y, z; u8 a, b; } Record;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Actor;
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
void GTSNEGO_DISP_CreateCursorActor(u8 *p)
{
    Record r;
    r.x = 0; r.y = 0; r.z = 0; r.a = 0; r.b = 2;
    ((struct Obj00987 *)p)->f134 = CLACT_CreateActor((void *)*(u32 *)&((struct Obj00987 *)p)->f10, ((struct Obj00987 *)p)->f28, ((struct Obj00987 *)p)->f18, ((struct Obj00987 *)p)->f74, &r, 1, ((struct Obj00987 *)p)->fF4);
    CLACT_SetActorAutoAnim(((struct Obj00987 *)p)->f134, 1);
    CLACT_SetActorDrawEnable(((struct Obj00987 *)p)->f134, 0);
    CLACT_SetActorObjMode(((struct Obj00987 *)p)->f134, 1);
}
