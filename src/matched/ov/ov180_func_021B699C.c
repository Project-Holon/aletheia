/*
 * function: HALL_OF_FAME_MoveMonSpriteX
 * address: 0x021B699C
 * packet: pkt_ov180_021B699C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: zero halfword alignment padding at 0x021B69E6.
 * symbols:
 *   MCSS_GetPosition 0x02015C30 thumb
 *   MCSS_SetPosition 0x02015C48 thumb
 *   _fflt 0x0209BDBC arm
 *   _fmul 0x0209C95C arm
 *   _fdiv 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj14402.h"
typedef struct { int x,y,z; } Vec;
typedef unsigned int   u32;
extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_SetPosition(void *p, u32 *src);
void HALL_OF_FAME_MoveMonSpriteX(char *p,int v) {
    Vec pos;
    float delta;
    MCSS_GetPosition((void *)(((struct Obj14402 *)p)->f1C),(u32 *)(&pos));
    if(v>0) delta=0.5f*(float)(v<<12);
    else delta=(float)(v<<12)/0.5f;
    pos.x=pos.x+(int)delta;
    MCSS_SetPosition((void *)(((struct Obj14402 *)p)->f1C),(u32 *)(&pos));
}
