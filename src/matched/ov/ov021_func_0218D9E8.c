/*
 * function: FIELD_G3D_MAPPER_QueryHits
 * address:  0x0218D9E8
 * packet:   pkt_ov021_0218D9E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3D_MAPPER_ClearHitList  0x0218D9C8  thumb ov021
 *   FIELD_G3D_MAP_IsVisible  0x021694FC  thumb ov010
 *   FIELD_G3D_MAP_GetPos  0x02169510  thumb ov010
 *   FIELD_G3D_MAP_QueryHits  0x02169800  thumb ov010
 *   FIELD_G3D_MAPPER_AppendHeightExHits  0x0218DDB4  thumb ov021
 */
#include "../include/Obj02370.h"

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    int d;
    int e;
} Ent;

typedef struct {
    Ent e[16];
    u32 count;
} Hits;

typedef struct {
    Ent e[16];
    u16 count;
} List;

extern void FIELD_G3D_MAPPER_ClearHitList(unsigned char *p);
typedef unsigned char  u8;
struct V3;
extern u16 FIELD_G3D_MAP_IsVisible(u8 *p);
extern void FIELD_G3D_MAP_GetPos(u8 *src, struct V3 *dst);
extern void FIELD_G3D_MAP_QueryHits(void *a, char *b, u32 c, u32 d);
extern void FIELD_G3D_MAPPER_AppendHeightExHits(const char *p, int *q, char *r);

int FIELD_G3D_MAPPER_QueryHits(char *p, int *pos, List *dst)
{
    int v[3];
    Hits buf;
    int h;
    int i;
    u32 n;

    if (((struct Obj02370 *)p)->f1C == 0)
        return 0;
    FIELD_G3D_MAPPER_ClearHitList((unsigned char *)dst);
    n = 0;
    h = ((struct Obj02370 *)p)->f4 >> 1;
    for (i = 0; i < ((struct Obj02370 *)p)->f2E; i++) {
        if (FIELD_G3D_MAP_IsVisible((u8 *)(*(int *)(*(char * *)&((struct Obj02370 *)p)->f24 + i * 0x28))) == 1) {
            int x;
            int z;
            int x0;
            int x1;
            int z0;
            int z1;
            FIELD_G3D_MAP_GetPos((u8 *)(*(int *)(*(char * *)&((struct Obj02370 *)p)->f24 + i * 0x28)), (struct V3 *)v);
            x = v[0];
            z = v[2];
            x0 = x - h;
            z0 = z - h;
            x1 = x + h;
            z1 = z + h;
            if (pos[0] >= x0 && pos[0] < x1 && pos[2] >= z0 && pos[2] < z1) {
                u32 j;
                FIELD_G3D_MAP_QueryHits(&buf, (char *)(*(int *)(*(char * *)&((struct Obj02370 *)p)->f24 + i * 0x28)), (u32)pos, ((struct Obj02370 *)p)->f4);
                if (buf.count != 0) {
                    if (n + buf.count >= 16)
                        break;
                    for (j = 0; j < buf.count; j++) {
                        dst->e[n + j].a = buf.e[j].a;
                        dst->e[n + j].b = buf.e[j].b;
                        dst->e[n + j].c = buf.e[j].c;
                        dst->e[n + j].d = buf.e[j].d;
                        dst->e[n + j].e = buf.e[j].e;
                    }
                    n += buf.count;
                }
            }
        }
    }
    dst->count = n;
    FIELD_G3D_MAPPER_AppendHeightExHits(p, pos, (char *)dst);
    if (dst->count != 0)
        return 1;
    return 0;
}
