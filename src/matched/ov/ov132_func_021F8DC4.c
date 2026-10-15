/*
 * function: STA_ACTING_CreateActors
 * address: 0x021F8DC4
 * packet: pkt_ov132_021F8DC4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_CreateRenderObj 0x021F5164 thumb ov112
 *   MUSICAL_MCSS_SetRenderFieldA 0x021F5438 thumb ov112
 *   MUSICAL_MCSS_CreateActorPool 0x021F48C0 thumb ov112
 *   STA_ACT_LIGHT_AddBillboardImage 0x021F709C thumb ov112
 *   STA_ACT_LIGHT_AddPokemonElem 0x021F760C thumb ov112
 *   STA_ACT_LIGHT_ElemOpB 0x021F8054 thumb ov112
 *   d_021FDBE0 0x021FDBE0 data a4
 */
#include "../include/Obj01410.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Vec { int x, y, z; };
struct Slots { u8 pad[0x44]; void *slots[4]; };
extern const struct Vec d_021FDBE0;
extern void *MUSICAL_MCSS_CreateRenderObj(u32);
struct Object;
extern void MUSICAL_MCSS_SetRenderFieldA(void **p, int b);
extern struct Object *MUSICAL_MCSS_CreateActorPool(u32 owner, int count, u16 heap);
extern u8 *STA_ACT_LIGHT_AddBillboardImage(u16 heap, u32 b, u32 c, u32 d, u32 e);
extern void *STA_ACT_LIGHT_AddPokemonElem(void *,void *);
extern void STA_ACT_LIGHT_ElemOpB(void *unused, u32 *p, const u32 *q);
void STA_ACTING_CreateActors(u8 *p)
{
    struct Vec pos;
    u8 i;
    pos = d_021FDBE0;
    ((struct Obj01410 *)p)->f34=MUSICAL_MCSS_CreateRenderObj(((struct Obj01410 *)p)->f0);
    MUSICAL_MCSS_SetRenderFieldA(((struct Obj01410 *)p)->f34,0x20000);
    ((struct Obj01410 *)p)->f38=MUSICAL_MCSS_CreateActorPool(((struct Obj01410 *)p)->fAC,36,((struct Obj01410 *)p)->f0);
    ((struct Obj01410 *)p)->f40=STA_ACT_LIGHT_AddBillboardImage(((struct Obj01410 *)p)->f0,(u32)p,(u32)(((struct Obj01410 *)p)->f34),(u32)(((struct Obj01410 *)p)->f38),((struct Obj01410 *)p)->fAC);
    for (i=0;i<4;i++) *(u32 *)(p+0x44+i*4)=0;
    for (i=0;i<4;i++) {
        ((struct Slots *)p)->slots[i]=STA_ACT_LIGHT_AddPokemonElem(((struct Obj01410 *)p)->f40,*(void **)(*(u8 * *)&((struct Obj01410 *)p)->f30+4+i*4));
        STA_ACT_LIGHT_ElemOpB(((struct Obj01410 *)p)->f40,((struct Slots *)p)->slots[i],(const u32 *)(&pos));
        pos.z-=0x1e000;
    }
}
