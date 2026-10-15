/*
 * function: GTSNEGO_MSG_CreateCursorActor
 * address: 0x021D6E84
 * packet: pkt_ov120_021D6E84
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 0x021D6ED6.
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj01540.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Record { u16 x, y, z; u8 a, b; } Record;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void GTSNEGO_MSG_CreateCursorActor(u8 *p)
{
    Record r;
    r.x = 128; r.y = 200; r.z = 0; r.a = 1; r.b = 1;
    ((struct Obj01540 *)p)->f138 = CLACT_CreateActor((void *)((struct Obj01540 *)p)->f10, ((struct Obj01540 *)p)->f70, ((struct Obj01540 *)p)->f24, ((struct Obj01540 *)p)->fBC, &r, 1, ((struct Obj01540 *)p)->fF4);
    CLACT_SetActorAutoAnim(((struct Obj01540 *)p)->f138, 1);
    CLACT_SetActorDrawEnable(((struct Obj01540 *)p)->f138, 1);
}
