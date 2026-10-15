/*
 * function: BTL_REC_SEL_DeleteActor, BTL_REC_SEL_SetMode
 * unit: yes
 * address: 0x021BABA4
 * packet: pkt_ov214_021BABA4
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * function_starts: 0x021BABB8
 * note: Cleared BABB8 follower occupies 60 bytes through BABF4. The pools
 * at BABEC/BABF0 point to the two fields of the same byte-pair table.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 *   d_021BB4C4 0x021BB4C4 data a1
 */
#include "../include/Obj08422.h"
typedef unsigned char u8;
typedef struct {u8 a,b;} Pair;
extern const Pair d_021BB4C4[];
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void UI_SCENE_FreeActorGfx(unsigned int *p);
void BTL_REC_SEL_DeleteActor(void*p,void*actor)
{
    CLACT_DeleteActor(actor);
    UI_SCENE_FreeActorGfx(p);
}
void BTL_REC_SEL_SetMode(int unused,char*p)
{
    u8 i=((struct Obj08422 *)p)->f2B0;
    if(i>=0x29)i=0;
    ((struct Obj08422 *)p)->f2A4=d_021BB4C4[i].a;
    if(d_021BB4C4[i].b==0)((struct Obj08422 *)p)->f2A8=1;
    else ((struct Obj08422 *)p)->f2A8=0;
}
