/*
 * function: BR_CODEIN_ProfileUpdateScrollAnim
 * address: 0x021E13FC
 * packet: pkt_ov183_021E13FC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   BR_CODEIN_ProfileGetActorIndex 0x021E0E40 thumb ov183
 *   BR_CODEIN_ProfileSetActorVisible 0x021E0CE8 thumb ov183
 *   BR_CODEIN_ProfileUpdateActorPos 0x021E1008 thumb ov183
 *   BR_CODEIN_ProfileFindActorIndex 0x021E1C14 thumb ov183
 *   BR_CODEIN_ProfileFindRecord 0x021E1C44 thumb ov183
 *   BR_CODEIN_ProfileSetActorPos 0x021E0D00 thumb ov183
 *   BR_CODEIN_ProfileClear 0x021E1C00 thumb ov183
 *   BR_CODEIN_ProfileSetAnimSeq 0x021E1374 thumb ov183
 *   d_021E3998 0x021E3998 data a4
 *   d_021E397C 0x021E397C data a4
 */
#include "../include/Obj00417.h"
#include "../include/Obj00478.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned long u32;
typedef struct {s16 a,b,x,y;} Coords;
typedef struct {u32 x,y;} Pair;
extern const int d_021E3998[],d_021E397C[];
struct Actor;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Pair;
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int BR_CODEIN_ProfileGetActorIndex(int,int);
extern void BR_CODEIN_ProfileSetActorVisible(char *p, int index, int a2);
extern void BR_CODEIN_ProfileUpdateActorPos(char *);
extern int BR_CODEIN_ProfileFindActorIndex(char *,int);
extern int BR_CODEIN_ProfileFindRecord(const char *p, int a);
extern void BR_CODEIN_ProfileSetActorPos(char *,int);
extern void BR_CODEIN_ProfileClear(char *);
extern void BR_CODEIN_ProfileSetAnimSeq(char *,int);
int BR_CODEIN_ProfileUpdateScrollAnim(char *p) {
    int i,factor,selected;
    char *record;
    Pair scale;
    Coords coords;
    switch(((struct Obj00478 *)p)->f234){
    case 0:
        BR_CODEIN_ProfileSetActorVisible(p,0,0);
        for(i=0;i<((struct Obj00478 *)p)->f23C;i++){
            record=(char *)((u32)p+i*28);
            if(((struct Obj00417 *)record)->f18!=0){
                CLACT_GetActorSurfacePos(((struct Obj00417 *)record)->fC,(struct PtS *)&coords.x,1);
                coords.x+=((struct Obj00417 *)record)->f14;
                coords.y+=((struct Obj00417 *)record)->f16;
                CLACT_AddActorSurfacePos(((struct Obj00417 *)record)->fC,(const struct Vec2 *)(&coords.x),1);
                --((struct Obj00417 *)record)->f18;
                if(i>=((struct Obj00478 *)p)->f248&&i<((struct Obj00478 *)p)->f24C){
                    factor=*(int *)((u32)d_021E3998+((struct Obj00417 *)record)->f19*4);
                    scale.x=factor;scale.y=factor;
                    CLACT_SetActorScale(((struct Obj00417 *)record)->fC,(struct Pair *)(&scale));
                    ++((struct Obj00417 *)record)->f19;
                }
                if(i>=((struct Obj00478 *)p)->f250&&i<((struct Obj00478 *)p)->f254){
                    factor=*(int *)((u32)d_021E397C+((struct Obj00417 *)record)->f19*4);
                    scale.x=factor;scale.y=factor;
                    CLACT_SetActorScale(((struct Obj00417 *)record)->fC,(struct Pair *)(&scale));
                    ++((struct Obj00417 *)record)->f19;
                }
            }
        }
        for(i=0;i<2;i++){
            record=(char *)((u32)p+i*28);
            if(((struct Obj00417 *)record)->f168!=0){
                CLACT_GetActorSurfacePos(((struct Obj00417 *)record)->f15C,(struct PtS *)&coords.a,1);
                coords.a+=((struct Obj00417 *)record)->f164;
                coords.b+=((struct Obj00417 *)record)->f166;
                CLACT_AddActorSurfacePos(((struct Obj00417 *)record)->f15C,(const struct Vec2 *)(&coords.a),1);
                --((struct Obj00417 *)record)->f168;
            }
        }
        if(((struct Obj00478 *)p)->f18==0){
            for(i=((struct Obj00478 *)p)->f248;i<((struct Obj00478 *)p)->f24C;i++){
                record=(char *)((u32)p+i*28);
                CLACT_SetActorAnimSeq(((struct Obj00417 *)record)->fC,BR_CODEIN_ProfileGetActorIndex(((struct Obj00417 *)record)->f0,((struct Obj00417 *)record)->f8));
            }
            for(i=((struct Obj00478 *)p)->f250;i<((struct Obj00478 *)p)->f254;i++){
                record=(char *)((u32)p+i*28);
                CLACT_SetActorAnimSeq(((struct Obj00417 *)record)->fC,BR_CODEIN_ProfileGetActorIndex(((struct Obj00417 *)record)->f0,((struct Obj00417 *)record)->f8));
            }
            ++((struct Obj00478 *)p)->f234;
        }
        ++((struct Obj00478 *)p)->f238;
        break;
    case 1:
        for(i=((struct Obj00478 *)p)->f248;i<((struct Obj00478 *)p)->f24C;i++){
            record=(char *)((u32)p+i*28);
            if(((struct Obj00417 *)record)->f19!=6){
                factor=*(int *)((u32)d_021E3998+((struct Obj00417 *)record)->f19*4);
                scale.x=factor;scale.y=factor;
                CLACT_SetActorScale(((struct Obj00417 *)record)->fC,(struct Pair *)(&scale));
                ++((struct Obj00417 *)record)->f19;
            }
        }
        for(i=((struct Obj00478 *)p)->f250;i<((struct Obj00478 *)p)->f254;i++){
            record=(char *)((u32)p+i*28);
            if(((struct Obj00417 *)record)->f19!=6){
                factor=*(int *)((u32)d_021E397C+((struct Obj00417 *)record)->f19*4);
                scale.x=factor;scale.y=factor;
                CLACT_SetActorScale(((struct Obj00417 *)record)->fC,(struct Pair *)(&scale));
                ++((struct Obj00417 *)record)->f19;
            }
        }
        if(++((struct Obj00478 *)p)->f238==6)++((struct Obj00478 *)p)->f234;
        break;
    default:
        BR_CODEIN_ProfileUpdateActorPos(p);
        if(((struct Obj00478 *)p)->f320==0)selected=BR_CODEIN_ProfileFindActorIndex(p,((struct Obj00478 *)p)->f31C);
        else selected=BR_CODEIN_ProfileFindRecord(p,((struct Obj00478 *)p)->f31C);
        BR_CODEIN_ProfileSetActorPos(p,selected);
        if(((struct Obj00478 *)p)->f240!=0)BR_CODEIN_ProfileSetActorVisible(p,0,1);
        BR_CODEIN_ProfileClear(p);
        BR_CODEIN_ProfileSetAnimSeq(p,1);
        break;
    }
    return 0;
}
