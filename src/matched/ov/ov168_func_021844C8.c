/*
 * function: MICTEST_OnMicEvent
 * address: 0x021844C8
 * packet: pkt_ov168_021844C8
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MICTEST_GetMicLevel 0x0218449C thumb ov168
 *   MICTEST_LevelToAnim 0x021845AC thumb ov168
 *   MICTEST_AreAllSpritesIdle 0x021845E0 thumb ov168
 *   MICTEST_SpawnSprite 0x02184600 thumb ov168
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   d_02184A40 0x02184A40 data a4
 */
#include "../include/Obj01947.h"
#include "../include/Obj04544.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int MICTEST_GetMicLevel(void *);
extern int MICTEST_LevelToAnim(u8);
struct Obj;
extern int MICTEST_AreAllSpritesIdle(char *p);
extern int MICTEST_SpawnSprite(char *,int,u16,int,void *);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern unsigned d_02184A40;
void MICTEST_OnMicEvent(int event, char *p)
{
    char *q;
    int n,anim;
    if(event==0){
        q=p+0xf8;
        n=MICTEST_GetMicLevel(q);
        if(((struct Obj04544 *)q)->f20<n){
            anim=MICTEST_LevelToAnim(n);
            ((struct Obj04544 *)q)->f20=n;
            ((struct Obj04544 *)q)->f24=1;
        }else{
            anim=MICTEST_LevelToAnim(((struct Obj04544 *)q)->f20);
            ((struct Obj04544 *)q)->f20-=2;
        }
        if(anim!=0){
            if(((struct Obj04544 *)q)->f24!=0){
                CLACT_SetActorAnimSeq(((struct Obj01947 *)p)->f8,1);
                ((struct Obj04544 *)q)->f24=0;
            }
            if(MICTEST_AreAllSpritesIdle(p)){
                MICTEST_SpawnSprite(p,((struct Obj01947 *)p)->f14C,128,64,((struct Obj01947 *)p)->f144);
            }else{
                --((struct Obj01947 *)p)->fE0;
                if(((struct Obj01947 *)p)->fE0==0){
                    MICTEST_SpawnSprite(p,((struct Obj01947 *)p)->f14C,128,64,((struct Obj01947 *)p)->f144);
                    ((struct Obj01947 *)p)->fE0=10;
                }
            }
            CLACT_SetActorAnimSeq(((struct Obj01947 *)p)->f0,anim);
            CLACT_SetActorAnimSeq(((struct Obj01947 *)p)->f4,anim);
        }else if(anim==0){
            CLACT_SetActorAnimSeq(((struct Obj01947 *)p)->f8,0);
            CLACT_SetActorAnimSeq(((struct Obj01947 *)p)->f0,0);
            CLACT_SetActorAnimSeq(((struct Obj01947 *)p)->f4,0);
        }
        ++d_02184A40;
    }
}
