/*
 * function: FIELD_G3D_MAPPER_UpdateBlocking
 * address:  0x0218CA78
 * packet:   pkt_ov021_0218CA78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3D_MAPPER_ResetCell  0x0218DD70  thumb ov021
 *   FIELD_G3D_MAPPER_LayoutLinear  0x0218D1D0  thumb ov021
 *   FIELD_G3D_MAPPER_LayoutWindowClipped  0x0218D304  thumb ov021
 *   FIELD_G3D_MAPPER_LayoutWindowWrapped  0x0218D444  thumb ov021
 *   FIELD_G3D_MAPPER_LayoutLayers  0x0218D570  thumb ov021
 *   FIELD_G3D_MAPPER_ApplyLayout  0x0218D7A8  thumb ov021
 *   FIELD_G3D_MAP_WaitLoad  0x0216932C  thumb ov010
 *   FX_Div   0x0207C768  arm
 */
#include "../include/Obj00806.h"

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
extern int FIELD_G3D_MAP_WaitLoad(int a0);
extern u32 FX_Div(u32 a, u32 b);

void FIELD_G3D_MAPPER_UpdateBlocking(char *p)
{
    int i;
    int a;
    int b;

    if (((struct Obj00806 *)p)->f1C == 0)
        return;
    for (i = 0; i < ((struct Obj00806 *)p)->f2E; i++)
        FIELD_G3D_MAPPER_ResetCell((unsigned int)(*(char * *)&((struct Obj00806 *)p)->f28 + i * 16));
    switch (((struct Obj00806 *)p)->fC) {
    case 0:
        FIELD_G3D_MAPPER_LayoutLinear(p, p + 0x34, ((struct Obj00806 *)p)->f28);
        break;
    case 1:
    default:
        FIELD_G3D_MAPPER_LayoutWindowClipped(p, (int *)(p + 0x34), ((struct Obj00806 *)p)->f28);
        break;
    case 2:
        FIELD_G3D_MAPPER_LayoutWindowWrapped(p, (int *)(p + 0x34), ((struct Obj00806 *)p)->f28);
        break;
    case 3:
        FIELD_G3D_MAPPER_LayoutLayers((struct Obj *)p, (struct Cam *)(p + 0x34), ((struct Obj00806 *)p)->f28);
        break;
    }
    FIELD_G3D_MAPPER_ApplyLayout((struct Obj *)p, ((struct Obj00806 *)p)->f28);
    for (i = 0; i < ((struct Obj00806 *)p)->f2E; i++)
        FIELD_G3D_MAP_WaitLoad(*(int *)(*(char * *)&((struct Obj00806 *)p)->f24 + i * 0x28));
    a = FX_Div(((struct Obj00806 *)p)->f34, ((struct Obj00806 *)p)->f4);
    b = FX_Div(((struct Obj00806 *)p)->f3C, ((struct Obj00806 *)p)->f4);
    ((struct Obj00806 *)p)->f30 = (a >> 12) + (b >> 12) * ((struct Obj00806 *)p)->f14;
}
