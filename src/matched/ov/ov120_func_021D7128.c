/*
 * function: func_021D7128
 * address: 0x021D7128
 * packet: pkt_ov120_021D7128
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj10396.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Record { u16 x, y, z; u8 a, b; } Record;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void func_021D7128(u8 *p, int n, int k)
{
    Record r;
    if (*(void **)(p + 0x14c + n * 4)) CLACT_DeleteActor(*(void **)(p + 0x14c + n * 4));
    r.x = 0; r.y = 0; r.z = 1; r.a = 10; r.b = 2;
    *(void **)(p + 0x14c + n * 4) = CLACT_CreateActor((void *)((struct Obj10396 *)p)->f10, *(u32 *)(p + (k + 6) * 4 + 0x18), ((struct Obj10396 *)p)->f20, *(u32 *)(p + (k + 25) * 4 + 0x18), &r, 1, ((struct Obj10396 *)p)->fF4);
    CLACT_SetActorAutoAnim(*(void **)(p + 0x14c + n * 4), 1);
    CLACT_SetActorDrawEnable(*(void **)(p + 0x14c + n * 4), 0);
}
