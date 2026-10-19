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
#include "sta_act_light_shared_types.h"
#include "sta_act_bg_shared_types.h"

struct Arg;

struct G3dOwner;

struct G3dRec;

struct G3dSys;

struct Rec;

/* The 64-byte G3D model part shared by the light unit and the sprite elem. */
typedef struct {
    u16 heap;            /* 0x00 */
    u16 pad_02;          /* 0x02 */
    u32 param;           /* 0x04 AllocElem parameter */
    u16 frame;           /* 0x08 SetModelFrame */
    u8 pad_0A[0x12];     /* 0x0A */
    u32 resourceArc;     /* 0x1C single resource arc, 0 until created */
    int arcs[3];         /* 0x20 three more resource arcs */
    int render;          /* 0x2C G3D render */
    int animes[3];       /* 0x30 G3D anime records */
    void *object;        /* 0x3C G3D object */
} LightModel;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *);
struct G3dObject;

extern int G3D_SYSTEM_LoopObjectAnimeFrame(struct G3dObject *obj, s32 anmIdx, s32 step);

extern void MTX_Identity33_(void *);
struct G3dObjectStatus;

extern void G3D_SYSTEM_DrawObject(struct G3dObject *obj, struct G3dObjectStatus *status);
struct G3dResource;

extern struct G3dResource *G3D_SYSTEM_CreateResourceArc(u32 arcId, u32 dataId);

extern int G3D_SYSTEM_TransVramTexture(struct G3dResource *res);
struct G3dRender;

extern struct G3dRender *G3D_SYSTEM_CreateRender(struct G3dResource *mdlRes, u32 mdlIdx, struct G3dResource *texRes);
struct G3dAnime;

extern struct G3dAnime *G3D_SYSTEM_CreateAnime(struct G3dRender *render, struct G3dResource *anmRes, u32 anmIdx);

extern struct G3dObject *G3D_SYSTEM_CreateObject(struct G3dRender *render, struct G3dAnime **anmTbl, s32 anmCount);

extern s32 G3D_SYSTEM_EnableObjectAnime(struct G3dObject *obj, u32 anmIdx);

extern void G3D_SYSTEM_DeleteObject(struct G3dObject *obj);

extern void G3D_SYSTEM_DeleteAnime(struct G3dAnime *anime);

extern void G3D_SYSTEM_DeleteRender(struct G3dRender *render);

extern void G3D_SYSTEM_DeleteResource(struct G3dResource *res);

extern int G3D_SYSTEM_FreeVramTexture(struct G3dResource *res);

u8 *STA_ACT_LIGHT_AllocElem(u32 heap,u32 v);

void STA_ACT_LIGHT_DeleteModel(u8 *p);

void STA_ACT_LIGHT_StepModelAnim(u8 *p);

void STA_ACT_LIGHT_DrawModel(u8 *p);

void STA_ACT_LIGHT_CreateModel(LightModel *p, char *q);

void STA_ACT_LIGHT_FreeModel(LightModel *p);

void STA_ACT_LIGHT_SetModelFrame(u8 *p, u16 v);

extern const char d_021F8454[];

extern u32 d_021F8430[];

extern struct Arg d_021F8418;

u8 *STA_ACT_LIGHT_AllocElem(u32 heap,u32 v) { u8 *p; p=GFL_HEAP_Alloc(heap,64,0,d_021F8454,81); ((LightModel *)p)->heap=heap; ((LightModel *)p)->param=v; ((LightModel *)p)->frame=0; ((LightModel *)p)->resourceArc=0; return p; }

/*
 * extent: two zero alignment bytes follow code.
 */
void STA_ACT_LIGHT_DeleteModel(u8 *p) { if(((LightModel *)p)->resourceArc) STA_ACT_LIGHT_FreeModel((LightModel *)p); GFL_HEAP_Free(p); }

void STA_ACT_LIGHT_StepModelAnim(u8 *p) { u8 i; if(((LightModel *)p)->resourceArc) { for(i=0;i<3;i++) G3D_SYSTEM_LoopObjectAnimeFrame(((LightModel *)p)->object,i,4096); } }

void STA_ACT_LIGHT_DrawModel(u8 *p) { if(((LightModel *)p)->resourceArc) { MTX_Identity33_(d_021F8430); G3D_SYSTEM_DrawObject(((LightModel *)p)->object,(struct G3dObjectStatus *)(&d_021F8418)); } }

/*
 * extent: two-byte zero padding before 021F7048.
 */
void STA_ACT_LIGHT_CreateModel(LightModel *p, char *q) {
    u8 i, j;
    if (p->resourceArc != 0) STA_ACT_LIGHT_FreeModel(p);
    p->resourceArc = (u32)G3D_SYSTEM_CreateResourceArc(0x2f, (u32)(q + 0x1e));
    p->arcs[0] = (int)G3D_SYSTEM_CreateResourceArc(0x2f, (u32)(q + 0x24));
    p->arcs[1] = (int)G3D_SYSTEM_CreateResourceArc(0x2f, (u32)(q + 0x2e));
    p->arcs[2] = (int)G3D_SYSTEM_CreateResourceArc(0x2f, (u32)(q + 0x29));
    if (G3D_SYSTEM_TransVramTexture((struct G3dResource *)p->resourceArc) != 0) {
        p->render = (int)G3D_SYSTEM_CreateRender((void *)p->resourceArc, 0, (void *)p->resourceArc);
        for (i = 0; i < 3; i++) p->animes[i] = (int)G3D_SYSTEM_CreateAnime((struct G3dRender *)p->render, (struct G3dResource *)p->arcs[i], 0);
        p->object = (void *)G3D_SYSTEM_CreateObject((struct G3dRender *)p->render, (struct G3dAnime **)p->animes, 3);
        for (j = 0; j < 3; j++) G3D_SYSTEM_EnableObjectAnime((struct G3dObject *)p->object, j);
    }
}

void STA_ACT_LIGHT_FreeModel(LightModel *p) {
    u8 i;
    G3D_SYSTEM_DeleteObject((struct G3dObject *)p->object);
    for (i = 0; i < 3; i++) G3D_SYSTEM_DeleteAnime((struct G3dAnime *)p->animes[i]);
    G3D_SYSTEM_DeleteRender((struct G3dRender *)p->render);
    for (i = 0; i < 3; i++) G3D_SYSTEM_DeleteResource((struct G3dResource *)p->arcs[i]);
    G3D_SYSTEM_FreeVramTexture((struct G3dResource *)p->resourceArc);
    G3D_SYSTEM_DeleteResource((struct G3dResource *)p->resourceArc);
    p->resourceArc = 0;
}

void STA_ACT_LIGHT_SetModelFrame(u8 *p, u16 v) { ((LightModel *)p)->frame = v; }
