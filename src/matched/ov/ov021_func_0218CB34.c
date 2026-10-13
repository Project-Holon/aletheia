/*
 * function: FIELD_G3D_MAPPER_UpdateStep
 * address:  0x0218CB34
 * packet:   pkt_ov021_0218CB34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3D_MAPPER_ResetCell  0x0218DD70  thumb  ov021
 *   FIELD_G3D_MAPPER_LayoutLinear  0x0218D1D0  thumb  ov021
 *   FIELD_G3D_MAPPER_LayoutWindowClipped  0x0218D304  thumb  ov021
 *   FIELD_G3D_MAPPER_LayoutWindowWrapped  0x0218D444  thumb  ov021
 *   FIELD_G3D_MAPPER_LayoutLayers  0x0218D570  thumb  ov021
 *   FIELD_G3D_MAPPER_ApplyLayout  0x0218D7A8  thumb  ov021
 *   FIELD_G3D_MAPPER_BeginDrawOrder  0x0218DE78  thumb  ov021
 *   FIELD_G3D_MAP_GetActiveRef  0x02169520  thumb  ov010
 *   FIELD_G3D_MAP_Update  0x02169308  thumb  ov010
 *   FIELD_G3D_MAPPER_InsertDrawOrder  0x0218DEFC  thumb  ov021
 *   FIELD_G3D_MAPPER_CountFittingSlots  0x0218DF80  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   FIELD_BUILDMODEL_UpdateSeason  0x0218B83C  thumb  ov021
 *   FIELD_GROUND_ANIME_Update  0x021A73DC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00807.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern int FIELD_G3D_MAPPER_ResetCell(unsigned int a);
typedef unsigned int   u32;
struct Elem;
extern void FIELD_G3D_MAPPER_LayoutLinear(char *p, void *a, struct Elem *e);
struct Cam;
struct Cell;
struct Obj;
extern void FIELD_G3D_MAPPER_LayoutWindowClipped(char *p, int *v, struct Elem *e);
extern void FIELD_G3D_MAPPER_LayoutWindowWrapped(char *p, int *a, struct Elem *e);
extern void FIELD_G3D_MAPPER_LayoutLayers(struct Obj *p, struct Cam *cam, struct Cell *cells);
struct Cell;
struct Obj;
extern int FIELD_G3D_MAPPER_ApplyLayout(struct Obj *p, struct Cell *nc);
extern void FIELD_G3D_MAPPER_BeginDrawOrder(char *p);
extern int FIELD_G3D_MAP_GetActiveRef(int a0, int a1);
extern void FIELD_G3D_MAP_Update(u8 *p);
extern void FIELD_G3D_MAPPER_InsertDrawOrder(char *p, int o, int i);
extern void FIELD_G3D_MAPPER_CountFittingSlots(u8 *a);
extern u32 func_0207C768(u32 a, u32 b);
extern void FIELD_BUILDMODEL_UpdateSeason(char *p);
extern void FIELD_GROUND_ANIME_Update(u32 *s);

int FIELD_G3D_MAPPER_UpdateStep(char *p)
{
    int i;
    int r;
    int x;
    int y;
    u16 *h;

    if (((struct Obj00807 *)p)->f1C == 0)
        return 0;
    for (i = 0; i < ((struct Obj00807 *)p)->f2E; i++)
        FIELD_G3D_MAPPER_ResetCell((unsigned int)(*(char * *)&((struct Obj00807 *)p)->f28 + i * 16));
    switch (((struct Obj00807 *)p)->fC) {
    case 0:
        FIELD_G3D_MAPPER_LayoutLinear(p, p + 0x34, ((struct Obj00807 *)p)->f28);
        break;
    case 1:
    default:
        FIELD_G3D_MAPPER_LayoutWindowClipped(p, (int *)(p + 0x34), ((struct Obj00807 *)p)->f28);
        break;
    case 2:
        FIELD_G3D_MAPPER_LayoutWindowWrapped(p, (int *)(p + 0x34), ((struct Obj00807 *)p)->f28);
        break;
    case 3:
        FIELD_G3D_MAPPER_LayoutLayers((struct Obj *)p, (struct Cam *)(p + 0x34), ((struct Obj00807 *)p)->f28);
        break;
    }
    FIELD_G3D_MAPPER_ApplyLayout((struct Obj *)p, ((struct Obj00807 *)p)->f28);
    r = 0;
    FIELD_G3D_MAPPER_BeginDrawOrder(p);
    for (i = 0; i < ((struct Obj00807 *)p)->f2E; i++) {
        FIELD_G3D_MAP_GetActiveRef(*(int *)(*(char * *)&((struct Obj00807 *)p)->f24 + i * 0x28), (int)(&h));
        if (*h == 1)
            r = 1;
        FIELD_G3D_MAP_Update((u8 *)(*(int *)(*(char * *)&((struct Obj00807 *)p)->f24 + i * 0x28)));
        FIELD_G3D_MAPPER_InsertDrawOrder(p, *(int *)(*(char * *)&((struct Obj00807 *)p)->f24 + i * 0x28), i);
    }
    FIELD_G3D_MAPPER_CountFittingSlots((u8 *)p);
    x = func_0207C768(((struct Obj00807 *)p)->f34, ((struct Obj00807 *)p)->f4);
    y = func_0207C768(((struct Obj00807 *)p)->f3C, ((struct Obj00807 *)p)->f4);
    ((struct Obj00807 *)p)->f30 = (x >> 12) + (y >> 12) * ((struct Obj00807 *)p)->f14;
    FIELD_BUILDMODEL_UpdateSeason(((struct Obj00807 *)p)->f64);
    if (((struct Obj00807 *)p)->f68 != 0)
        FIELD_GROUND_ANIME_Update(((struct Obj00807 *)p)->f68);
    return r;
}
