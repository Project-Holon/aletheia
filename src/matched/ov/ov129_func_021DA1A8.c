/*
 * function: WF2DMAP_SCENE_LayoutCells
 * address: 0x021DA1A8
 * packet: pkt_ov129_021DA1A8
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: declare i before y, initialise j after loading y, and keep the equality arm separate.
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
#include "../include/Obj02187.h"
#include "../include/Obj03283.h"
typedef short s16;
typedef unsigned char u8;
typedef struct { s16 x,y,z,w; } Position;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void WF2DMAP_SCENE_LayoutCells(char *p,int animate)
{
    Position s;
    int i,j;
    s16 y=*(s16 *)((unsigned)p+(unsigned)((struct Obj03283 *)p)->f240*2+0x214);
    unsigned q;
    j=0;
    for(i=0;i<((struct Obj03283 *)p)->f23C;i++) {
        if(i>=((struct Obj03283 *)p)->f248 && i<((struct Obj03283 *)p)->f24C) {
            if(i==((struct Obj03283 *)p)->f248) y+=20;
            else y+=32;
        } else {
            if(i==0) y+=20;
            else y+=8;
        }
        q=(unsigned)p+(unsigned)i*28;
        CLACT_GetActorSurfacePos((struct Actor *)((struct Obj02187 *)q)->fC,(struct PtS *)&s.z,0);
        if(animate==0) {
            s.z=y;
            CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj02187 *)q)->fC),(const struct Vec2 *)(&s.z),0);
        } else {
            ((struct Obj02187 *)q)->f14=(y-s.z)/4;
            ((struct Obj02187 *)q)->f16=0;
            ((struct Obj02187 *)q)->f18=4;
            ((struct Obj02187 *)q)->f19=0;
        }
        q=(unsigned)p+(unsigned)j*28;
        if(i==((struct Obj02187 *)q)->f150 && j!=2) {
            CLACT_GetActorSurfacePos((struct Actor *)((struct Obj02187 *)q)->f15C,(struct PtS *)&s,0);
            if(((struct Obj03283 *)p)->f248==((struct Obj03283 *)p)->f24C) y+=8;
            else {
                if(i>((struct Obj03283 *)p)->f248 && i<((struct Obj03283 *)p)->f24C) y+=20;
                else y+=8;
            }
            if(animate==0) {
                s.x=y;
                CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj02187 *)q)->f15C),(const struct Vec2 *)(&s),0);
            } else {
                ((struct Obj02187 *)q)->f164=(y-s.x)/4;
                ((struct Obj02187 *)q)->f166=0;
                ((struct Obj02187 *)q)->f168=4;
            }
            j++;
        }
    }
}
