/*
 * function: FIELD_G3D_MAPPER_QueryNearestHit
 * address:  0x0218DAEC
 * packet:   pkt_ov021_0218DAEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_G3D_MAPPER_ClearHit  0x0218D9B8  thumb ov021
 *   FIELD_G3D_MAPPER_QueryHits  0x0218D9E8  thumb ov021
 *   MAP_ATTR_IsPresent  0x021AB100  thumb ov021
 *   _ll_mul        0x0209C054  arm
 */
#include "../include/Obj04201.h"

typedef unsigned short u16;

typedef struct { u16 a; u16 b; u16 c; u16 d; int p; int q; } E;
typedef struct { E e[16]; u16 n; } B;

extern int FIELD_G3D_MAPPER_ClearHit(unsigned int a);
extern int FIELD_G3D_MAPPER_QueryHits(void *p, void *q, B *b);
typedef unsigned int   u32;
extern int MAP_ATTR_IsPresent(u32 attr);

int FIELD_G3D_MAPPER_QueryNearestHit(char *p, char *q, E *out)
{
    B b;
    int i;
    int best;
    int mn;

    FIELD_G3D_MAPPER_ClearHit((unsigned int)out);
    if (FIELD_G3D_MAPPER_QueryHits(p, q, &b) == 0)
        return 0;
    if (b.n == 1) {
        *out = b.e[0];
        return 1;
    }
    best = 0;
    mn = 0x00FFF000;
    for (i = 0; i < b.n; i++) {
        if (MAP_ATTR_IsPresent(b.e[i].p)) {
            int d = b.e[i].q - ((struct Obj04201 *)q)->f4;
            if (d < 0)
                d = (int)(((long long)d * -4096LL + 0x800LL) >> 12);
            if (d < mn) {
                best = i;
                mn = d;
            }
        }
    }
    *out = b.e[best];
    return 1;
}
