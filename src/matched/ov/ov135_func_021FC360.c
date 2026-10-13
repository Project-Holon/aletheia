/*
 * function: func_021FC360
 * address: 0x021FC360
 * packet: pkt_ov135_021FC360
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 */
#include "../include/Obj03298.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x, y, z; u8 pri, f7; } ObjPos;
extern void MI_CpuFill8(void *, int, int);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorBgPriority(void *, int);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
void func_021FC360(char *p)
{
    ObjPos pos;
    MI_CpuFill8(&pos, 0, sizeof(pos));
    pos.x = 0xd0;
    pos.y = 0x3a;
    ((struct Obj03298 *)p)->fD08 = CLACT_CreateActor(((struct Obj03298 *)p)->fBC0, (unsigned int)((struct Obj03298 *)p)->fBC4, (unsigned int)((struct Obj03298 *)p)->fBC8, (unsigned int)((struct Obj03298 *)p)->fBCC, &pos, 0, 0x48);
    CLACT_SetActorAutoAnim(((struct Obj03298 *)p)->fD08, 1);
    CLACT_SetActorAnimSeq(((struct Obj03298 *)p)->fD08, 0x24);
    CLACT_SetActorBgPriority(((struct Obj03298 *)p)->fD08, 1);
    CLACT_SetActorDrawEnable(((struct Obj03298 *)p)->fD08, 1);
    GFL_NET_RestartWithDefaultTimeout(0, 0x48);
}
