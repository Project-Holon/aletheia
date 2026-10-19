/*
 * file:     demo3d_exp_c_cruiser.c
 * unit:     yes
 * function: DEMO3D_EXP_C_CRUISER_LoadTextures, DEMO3D_EXP_C_CRUISER_Create, DEMO3D_EXP_C_CRUISER_Update, DEMO3D_EXP_C_CRUISER_DeleteActorGfx
 * address:  0x021BF9D0
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   DEMO3D_ENGINE_GetFrame 0x021BE620 thumb ov203
 *   DEMO3D_GRAPHIC_GetUnit 0x021BDF30 thumb ov203
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021C3D5C 0x021C3D5C data a1
 *   d_021C3BD0 0x021C3BD0 data a2
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 */

struct Obj;
typedef unsigned short u16;

typedef unsigned int   u32;

struct Vec2 { short x, y; };

typedef struct Demo3dCruiserActorGfx { int id; int resource; int palette; int frame; } Demo3dCruiserActorGfx;

typedef struct Demo3dCruiserActorConfig {
    int mode;
    unsigned flags;
    int modelId;
    int size;
    int scaleX;
    int scaleY;
    int scaleZ;
    unsigned char alpha;
    unsigned char flip;
    unsigned char visible;
} Demo3dCruiserActorConfig;

typedef struct Demo3dCruiserWork {
    unsigned short heapId;
    unsigned char pad2[2];
    void *view;
    void *model;
    unsigned char padC[4];
    void *gfx;
} Demo3dCruiserWork;

typedef struct Demo3dCruiserGfx {
    unsigned char step;
    unsigned char pad1[3];
    Demo3dCruiserActorGfx actorGfx;
    struct Obj *actor;
} Demo3dCruiserGfx;

typedef unsigned char u8;

extern void *ARC_TOOL_CreateHandle(unsigned int archiveID, unsigned short heapID);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *, unsigned, unsigned, unsigned, unsigned, unsigned short);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned short);
extern void ARC_TOOL_DeleteHandle(void *);
extern void *GFL_HEAP_Alloc(unsigned, unsigned, int, const char *, unsigned short);
extern int DEMO3D_ENGINE_GetFrame(char *p);
struct Demo3dGraphic;
extern int DEMO3D_GRAPHIC_GetUnit(struct Demo3dGraphic *p);
extern void UI_SCENE_LoadActorGfx(Demo3dCruiserActorGfx *, Demo3dCruiserActorConfig *, int, unsigned short);
extern int UI_SCENE_CreateActor(Demo3dCruiserActorGfx *, int, unsigned char, unsigned char, unsigned char, unsigned short);
struct Actor;
extern void CLACT_SetActorDrawEnable(struct Actor *actor, unsigned int value);
extern void CLACT_SetActorAutoAnim(struct Actor *actor, unsigned int enable);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
extern void CLACT_AddActorSurfacePos(struct Obj *, const struct Vec2 *, unsigned);
extern void UI_SCENE_FreeActorGfx(void *);
extern u32 GFL_HEAP_Free(void *p);
void DEMO3D_EXP_C_CRUISER_LoadTextures(unsigned short heap);
void DEMO3D_EXP_C_CRUISER_Create(Demo3dCruiserWork *p);
void DEMO3D_EXP_C_CRUISER_Update(Demo3dCruiserWork *p);
void DEMO3D_EXP_C_CRUISER_DeleteActorGfx(Demo3dCruiserWork *work);
extern const char d_021C3D5C[];
extern const struct Vec2 d_021C3BD0[];


void DEMO3D_EXP_C_CRUISER_LoadTextures(unsigned short heap)
{
    void *h = ARC_TOOL_CreateHandle(85, heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 3, 4, 0, 0, heap);
    ARC_UTIL_UploadBgCharFromHandle(h, 9, 6, 0, 0, 0, heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 18, 6, 0, 0, 0, heap);
    ARC_TOOL_DeleteHandle(h);
}


/*
 * note: 2026-10-05 wave P13 lane B1: closed from the 6 B DIFF draft (movs r7,#0 sat after movs r1,#0x14 instead of before str r1,[sp,#0x1c]). The store `config.f4 = 0;` moves to between f10 and f14; the other constant stores keep the listing order. 4 compiles. Callee shapes follow the matched ov203 siblings (021BF9D0, 021BDF30, 021BE620, 021BFAE4). The d_021C3BD2 pool word is the .y field of d_021C3BD0 (struct Vec2 array), folded by the compiler. The volatile read at 021BFA50 rereads the byte just stored at 021BFA4E, the same form as matched sibling 021BFAE4 (volatile: 021BFB12). No constant locals. EXACT in c99 and c.
 */
void DEMO3D_EXP_C_CRUISER_Create(Demo3dCruiserWork *p)
{
    Demo3dCruiserGfx *a;
    int resource;
    Demo3dCruiserActorConfig config;
    a = (Demo3dCruiserGfx *)GFL_HEAP_Alloc(p->heapId, 24, 1, d_021C3D5C, 0xB3);
    p->gfx = a;
    DEMO3D_EXP_C_CRUISER_LoadTextures(p->heapId);
    a->step = (DEMO3D_ENGINE_GetFrame(p->model) >> 12) / 100;
    if (*(volatile unsigned char *)&a->step >= 54) a->step = 53;
    resource = DEMO3D_GRAPHIC_GetUnit(p->view);
    config.mode = 1;
    config.modelId = 85;
    config.size = 4;
    config.scaleX = 10;
    config.flags = 0;
    config.scaleY = 13;
    config.scaleZ = 20;
    config.alpha = 0;
    config.flip = 0;
    config.visible = 1;
    UI_SCENE_LoadActorGfx(&a->actorGfx, &config, resource, p->heapId);
    a->actor = (struct Obj *)UI_SCENE_CreateActor(&a->actorGfx, resource, d_021C3BD0[a->step].x, d_021C3BD0[a->step].y, 0, p->heapId);
    CLACT_SetActorDrawEnable((struct Actor *)a->actor, 1);
    CLACT_SetActorAutoAnim((struct Actor *)a->actor, 1);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}


void DEMO3D_EXP_C_CRUISER_Update(Demo3dCruiserWork *p)
{
    Demo3dCruiserGfx *a = p->gfx;
    int progress = DEMO3D_ENGINE_GetFrame(p->model) >> 12;
    if (a->step < 54 && a->step * 100 <= progress) {
        CLACT_AddActorSurfacePos(a->actor, d_021C3BD0 + a->step, 1);
        ++a->step;
        if (*(volatile unsigned char *)&a->step == 54)
            CLACT_SetActorDrawEnable((struct Actor *)a->actor, 0);
    }
}


#pragma thumb off

#pragma thumb on


void DEMO3D_EXP_C_CRUISER_DeleteActorGfx(Demo3dCruiserWork *work)
{
    UI_SCENE_FreeActorGfx(&((Demo3dCruiserGfx *)work->gfx)->actorGfx);
    GFL_HEAP_Free(work->gfx);
}
