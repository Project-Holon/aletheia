/*
 * file:     sta_act_bg.c
 * unit:     yes
 * function: STA_ACT_LIGHT_AllocElem, STA_ACT_LIGHT_DeleteModel, STA_ACT_LIGHT_StepModelAnim, STA_ACT_LIGHT_DrawModel, STA_ACT_LIGHT_CreateModel, STA_ACT_LIGHT_FreeModel, STA_ACT_LIGHT_SetModelFrame
 * address:  0x021F6F24
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from sta_act_light.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   d_021F8454 0x021F8454 data a1
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   d_021F8430 0x021F8430 data a4
 *   d_021F8418 0x021F8418 data a4
 *   G3D_SYSTEM_CreateResourceArc 0x02046DB8 arm
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_CreateRender 0x02047400 arm
 *   G3D_SYSTEM_CreateAnime 0x02047564 arm
 *   G3D_SYSTEM_CreateObject 0x0204767C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_DeleteObject 0x02047738 arm
 *   G3D_SYSTEM_DeleteAnime 0x0204762C arm
 *   G3D_SYSTEM_DeleteRender 0x02047504 arm
 *   G3D_SYSTEM_DeleteResource 0x02046EFC arm
 *   G3D_SYSTEM_FreeVramTexture 0x020470D0 arm
 */
#include "sta_act_types.h"
#include "sta_act_light_shared_types.h"
#include "sta_act_bg_shared_types.h"

struct Arg;

struct G3dOwner;

struct G3dRec;

struct G3dSys;

struct Rec;


#include "../arm9/gfl_heap_wrap.h"

struct G3dObject;

#include "../arm9/g3d_system.h"

#include "../arm9/fx_mtx33.h"
struct G3dObjectStatus;

struct G3dResource;


struct G3dRender;

struct G3dAnime;









u8 *STA_ACT_LIGHT_AllocElem(u32 heap,u32 v);

void STA_ACT_LIGHT_DeleteModel(u8 *p);

void STA_ACT_LIGHT_StepModelAnim(u8 *p);

void STA_ACT_LIGHT_DrawModel(u8 *p);

void STA_ACT_LIGHT_CreateModel(StaActLightModel *p, u32 id);

void STA_ACT_LIGHT_FreeModel(StaActLightModel *p);

void STA_ACT_LIGHT_SetModelFrame(u8 *p, u16 v);

extern const char d_021F8454[];

extern u32 d_021F8430[];

extern struct Arg d_021F8418;

u8 *STA_ACT_LIGHT_AllocElem(u32 heap,u32 v) { u8 *p; p=GFL_HEAP_Alloc(heap,64,0,d_021F8454,81); ((StaActLightModel *)p)->heap=heap; ((StaActLightModel *)p)->param=v; ((StaActLightModel *)p)->frame=0; ((StaActLightModel *)p)->resourceArc=0; return p; }

/*
 * extent: two zero alignment bytes follow code.
 */
void STA_ACT_LIGHT_DeleteModel(u8 *p) { if(((StaActLightModel *)p)->resourceArc) STA_ACT_LIGHT_FreeModel((StaActLightModel *)p); GFL_HEAP_Free(p); }

void STA_ACT_LIGHT_StepModelAnim(u8 *p) { u8 i; if(((StaActLightModel *)p)->resourceArc) { for(i=0;i<3;i++) G3D_SYSTEM_LoopObjectAnimeFrame((G3dObject *)(((StaActLightModel *)p)->object),i,4096); } }

void STA_ACT_LIGHT_DrawModel(u8 *p) { if(((StaActLightModel *)p)->resourceArc) { MTX_Identity33_((MtxFx33 *)d_021F8430); G3D_SYSTEM_DrawObject((G3dObject *)(((StaActLightModel *)p)->object),(G3dObjectStatus *)((struct G3dObjectStatus *)(&d_021F8418))); } }

/*
 * extent: two-byte zero padding before 021F7048.
 */
void STA_ACT_LIGHT_CreateModel(StaActLightModel *p, u32 id) {
    u8 i, j;
    if (p->resourceArc != 0) STA_ACT_LIGHT_FreeModel(p);
    p->resourceArc = (u32)G3D_SYSTEM_CreateResourceArc(0x2f, id + 0x1e);
    p->arcs[0] = (int)G3D_SYSTEM_CreateResourceArc(0x2f, id + 0x24);
    p->arcs[1] = (int)G3D_SYSTEM_CreateResourceArc(0x2f, id + 0x2e);
    p->arcs[2] = (int)G3D_SYSTEM_CreateResourceArc(0x2f, id + 0x29);
    if (G3D_SYSTEM_TransVramTexture((struct G3dResource *)p->resourceArc) != 0) {
        p->render = (int)G3D_SYSTEM_CreateRender((void *)p->resourceArc, 0, (void *)p->resourceArc);
        for (i = 0; i < 3; i++) p->animes[i] = (int)G3D_SYSTEM_CreateAnime((struct G3dRender *)p->render, (struct G3dResource *)p->arcs[i], 0);
        p->object = (void *)G3D_SYSTEM_CreateObject((struct G3dRender *)p->render, (struct G3dAnime **)p->animes, 3);
        for (j = 0; j < 3; j++) G3D_SYSTEM_EnableObjectAnime((struct G3dObject *)p->object, j);
    }
}

void STA_ACT_LIGHT_FreeModel(StaActLightModel *p) {
    u8 i;
    G3D_SYSTEM_DeleteObject((struct G3dObject *)p->object);
    for (i = 0; i < 3; i++) G3D_SYSTEM_DeleteAnime((struct G3dAnime *)p->animes[i]);
    G3D_SYSTEM_DeleteRender((struct G3dRender *)p->render);
    for (i = 0; i < 3; i++) G3D_SYSTEM_DeleteResource((struct G3dResource *)p->arcs[i]);
    G3D_SYSTEM_FreeVramTexture((struct G3dResource *)p->resourceArc);
    G3D_SYSTEM_DeleteResource((struct G3dResource *)p->resourceArc);
    p->resourceArc = 0;
}

void STA_ACT_LIGHT_SetModelFrame(u8 *p, u16 v) { ((StaActLightModel *)p)->frame = v; }
