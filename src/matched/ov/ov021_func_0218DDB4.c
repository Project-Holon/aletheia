/*
 * function: FIELD_G3D_MAPPER_AppendHeightExHits
 * address:  0x0218DDB4
 * packet:   pkt_ov021_0218DDB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gFieldG3dMapperDefaultHitHead     0x021D3DD4  data a2
 *   HEIGHT_EX_GetAreaCount  0x021C0688  thumb ov021
 *   HEIGHT_EX_IsPointInAreaAt  0x021C068C  thumb ov021
 *   HEIGHT_EX_GetAreaAttr  0x021C06B4  thumb ov021
 *   HEIGHT_EX_GetAreaHeight  0x021C06A8  thumb ov021
 */
#include "../include/Obj02370.h"
#include "../include/Obj03107.h"
#include "../include/Obj12588.h"

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct { u16 a; u16 b; u16 c; } S6;

extern S6 gFieldG3dMapperDefaultHitHead;
typedef unsigned int   u32;
extern u32 HEIGHT_EX_GetAreaCount(u8 *p);
extern int HEIGHT_EX_IsPointInAreaAt(int x, int z, int o, u8 i);
extern int HEIGHT_EX_GetAreaAttr(u8 i, int o);
extern int HEIGHT_EX_GetAreaHeight(u8 i, int o);

void FIELD_G3D_MAPPER_AppendHeightExHits(const char *p, int *q, char *r)
{
    S6 tmp = gFieldG3dMapperDefaultHitHead;
    int cnt = 0;
    int base = ((struct Obj03107 *)r)->f100;
    int n = HEIGHT_EX_GetAreaCount((u8 *)(((struct Obj02370 *)p)->f70));
    int z;
    int x;
    int i;

    x = q[0] / 0x10000;
    z = q[2] / 0x10000;
    for (i = 0; i < n; i++) {
        if (HEIGHT_EX_IsPointInAreaAt(x, z, ((struct Obj02370 *)p)->f70, i)) {
            int k = base + ++cnt - 1;
            char *e;
            if (k >= 0x10)
                break;
            e = r + k * 16;
            *(S6 *)e = tmp;
            ((struct Obj12588 *)e)->f8 = HEIGHT_EX_GetAreaAttr(i, ((struct Obj02370 *)p)->f70);
            ((struct Obj12588 *)e)->fC = HEIGHT_EX_GetAreaHeight(i, ((struct Obj02370 *)p)->f70);
        }
    }
    ((struct Obj03107 *)r)->f100 += (u16)cnt;
}
