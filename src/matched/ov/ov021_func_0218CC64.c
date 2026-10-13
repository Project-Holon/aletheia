/*
 * function: FIELD_G3D_MAPPER_Draw
 * address:  0x0218CC64
 * packet:   pkt_ov021_0218CC64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3D_MAPPER_GetDrawSlot  0x0218DFE0  thumb ov021
 *   FIELD_G3D_MAP_GetPos  0x02169510  thumb ov010
 *   FIELD_G3D_MAP_SetPos  0x02169500  thumb ov010
 *   FIELD_G3D_MAP_DrawWithModels  0x02169354  thumb ov010
 *   FIELD_BUILDMODEL_DrawNodes  0x0218B88C  thumb ov021
 */
#include "../include/Obj02072.h"

typedef unsigned char  u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern int FIELD_G3D_MAPPER_GetDrawSlot(u8 *a, u32 idx, int flag, u32 *out);
struct V3;
extern void FIELD_G3D_MAP_GetPos(u8 *src, struct V3 *dst);
extern void FIELD_G3D_MAP_SetPos(u8 *p, u8 *q);
extern int FIELD_G3D_MAP_DrawWithModels(int o, int a);
extern void FIELD_BUILDMODEL_DrawNodes(unsigned char *p);

void FIELD_G3D_MAPPER_Draw(char *p, int a, int m)
{
    int w[3];
    int v[3];
    int idx;
    int i;
    u8 *c;

    if (m == 0 && ((struct Obj02072 *)p)->f40 == 0)
        return;
    for (i = 0; i < ((struct Obj02072 *)p)->f2E; i++) {
        if (FIELD_G3D_MAPPER_GetDrawSlot((u8 *)p, i, m, (u32 *)(&idx))) {
            int r;
            c = (u8 *)p + 0x43;
            FIELD_G3D_MAP_GetPos((u8 *)(*(int *)(*(char * *)&((struct Obj02072 *)p)->f24 + idx * 0x28)), (struct V3 *)w);
            v[0] = w[0] + ((struct Obj02072 *)p)->f54;
            v[1] = w[1] + ((struct Obj02072 *)p)->f58;
            v[2] = w[2] + ((struct Obj02072 *)p)->f5C;
            FIELD_G3D_MAP_SetPos((u8 *)(*(int *)(*(char * *)&((struct Obj02072 *)p)->f24 + idx * 0x28)), (u8 *)v);
            r = FIELD_G3D_MAP_DrawWithModels(*(int *)(*(char * *)&((struct Obj02072 *)p)->f24 + idx * 0x28), a);
            FIELD_G3D_MAP_SetPos((u8 *)(*(int *)(*(char * *)&((struct Obj02072 *)p)->f24 + idx * 0x28)), (u8 *)w);
            if (r != 0 && ((struct Obj02072 *)p)->f43 < ((struct Obj02072 *)p)->f2E)
                *c = *c + 1;
        }
    }
    if (m == 1)
        FIELD_BUILDMODEL_DrawNodes((unsigned char *)(((struct Obj02072 *)p)->f64));
}
