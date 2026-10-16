/*
 * function: STA_ACT_AUDIENCE_UpdateRecord
 * address: 0x021FA2A0
 * packet: pkt_ov132_021FA2A0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACTING_GetCameraTarget 0x021F9E04 thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   STA_ACTING_GetCharSystem 0x021F9DD4 thumb ov132
 *   STA_ACTING_GetCharSlot 0x021F9DDC thumb ov132
 *   STA_ACT_LIGHT_CopyActorPos 0x021F8044 thumb ov112
 *   STA_ACT_LIGHT_GetElemPos 0x021F6F04 thumb ov112
 *   STA_ACT_AUDIENCE_DrawRecord 0x021FA3A8 thumb ov132
 *   func_02005728 0x02005728 thumb
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _fdiv 0x0209CE10 arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj00995.h"
#include "../include/Obj04514.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {int x,y,z;} Vec;
extern u16 STA_ACTING_GetCameraTarget(u8 *p);
extern void *STA_ACTING_GetActorSystem(char *p);
extern void *STA_ACTING_GetActor(char *p, u32 i);
extern void *STA_ACTING_GetCharSystem(void *);
extern void *STA_ACTING_GetCharSlot(void *,u8);
extern void STA_ACT_LIGHT_CopyActorPos(void *unused, u32 *p, u32 *q);
extern void STA_ACT_LIGHT_GetElemPos(void *,void *,Vec *);
extern void STA_ACT_AUDIENCE_DrawRecord(char *,u8 *,unsigned);
extern unsigned func_02005728(unsigned);
void STA_ACT_AUDIENCE_UpdateRecord(char *p,u8 *rec)
{
    Vec v;
    void *a,*b;
    u16 x;
    s16 delta;
    if(rec[1]!=0) rec[1]--;
    if(rec[1]==0) {
        if(rec[0]==255 && ((struct Obj04514 *)p)->f1FC==255) {
            ((struct Obj00995 *)rec)->f4=65535;
            if(rec[6]<2) STA_ACT_AUDIENCE_DrawRecord(p,rec,3);
            else if(rec[6]<4) STA_ACT_AUDIENCE_DrawRecord(p,rec,2);
            else if(rec[6]<6) STA_ACT_AUDIENCE_DrawRecord(p,rec,1);
            else STA_ACT_AUDIENCE_DrawRecord(p,rec,0);
        } else {
            STA_ACTING_GetCameraTarget(((struct Obj04514 *)p)->f1E8);
            x=((rec[6]*32-64)*4)/3;
            if(rec[0]!=255) {
                a=STA_ACTING_GetActorSystem(((struct Obj04514 *)p)->f1E8);
                STA_ACT_LIGHT_CopyActorPos(a,STA_ACTING_GetActor(((struct Obj04514 *)p)->f1E8,rec[0]),(u32 *)(&v));
            } else {
                b=STA_ACTING_GetCharSystem(((struct Obj04514 *)p)->f1E8);
                STA_ACT_LIGHT_GetElemPos(b,STA_ACTING_GetCharSlot(((struct Obj04514 *)p)->f1E8,((struct Obj04514 *)p)->f1FC),&v);
            }
            delta=(float)v.x/4096.f-(float)(u32)x;
            if(delta < -64) STA_ACT_AUDIENCE_DrawRecord(p,rec,0);
            else if(delta >64) STA_ACT_AUDIENCE_DrawRecord(p,rec,3);
            else if(delta<0) STA_ACT_AUDIENCE_DrawRecord(p,rec,1);
            else STA_ACT_AUDIENCE_DrawRecord(p,rec,2);
        }
        rec[1]=func_02005728(60)+1;
    }
}
