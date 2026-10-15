/*
 * function: MYSTERY_CreateOamSprite
 * address: 0x021D93F4
 * packet: pkt_ov121_021D93F4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D9486; next function starts 021D9488.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   MYSTERY_UTIL_CreateTaskEx 0x021DA8CC thumb ov121
 *   MYSTERY_UTIL_SetFlag 0x021DA9EC thumb ov121
 *   MYSTERY_UTIL_SetVec 0x021DA9F0 thumb ov121
 *   MYSTERY_UTIL_SetActorPairText 0x021DA994 thumb ov121
 *   MYSTERY_GetClactActor 0x021D6C58 thumb ov121
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj04492.h"
#include "../include/Obj22870.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x,y,z; u8 a,b; } Pos;
extern void MI_CpuFill8(void *,int,int);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern void *MYSTERY_UTIL_CreateTaskEx(const char *p, u16 a, u16 b, int c, u8 d, int e, void *f, void *g, u16 heap);
typedef unsigned int   u32;
struct Obj;
extern void MYSTERY_UTIL_SetFlag(u8 *p, int a);
extern void MYSTERY_UTIL_SetVec(u32 *p, u32 a, u32 b, u32 c);
extern void MYSTERY_UTIL_SetActorPairText(char *p, int a, int b, int c);
extern void *MYSTERY_GetClactActor(u8 *p, int i);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void MYSTERY_CreateOamSprite(u8 *p,const void *q,int n,int k,int x,int y,int z,u16 heap)
{
    Pos pos;
    MI_CpuFill8(p,0,12);
    *(const void * *)&((struct Obj04492 *)p)->f8=q;
    ((struct Obj04492 *)p)->f0=BMP_OAM_CreateSys(heap,(void *)n);
    MI_CpuFill8(&pos,0,8);
    pos.x=96; pos.y=169; pos.a=0; pos.b=0;
    ((struct Obj04492 *)p)->f4=MYSTERY_UTIL_CreateTaskEx((const char *)(&pos),8,2,(int)(*(void *const *)&((struct Obj22870 *)q)->f0),3,0,((struct Obj04492 *)p)->f0,(void *)k,heap);
    MYSTERY_UTIL_SetFlag(((struct Obj04492 *)p)->f4,1120);
    MYSTERY_UTIL_SetVec(((struct Obj04492 *)p)->f4,0,0,1);
    MYSTERY_UTIL_SetActorPairText(((struct Obj04492 *)p)->f4,x,y,z);
    CLACT_SetActorDrawEnable(MYSTERY_GetClactActor((u8 *)q,34),1);
}
