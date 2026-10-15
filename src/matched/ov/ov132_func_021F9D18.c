/*
 * function: STA_ACTING_PositionAnim
 * address: 0x021F9D18
 * packet: pkt_ov132_021F9D18
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACT_LIGHT_ElemOpA 0x021F8044 thumb ov112
 *   STA_ACT_EFFECT_StartEffect 0x021F9F74 thumb ov132
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj14088.h"
typedef unsigned char u8;
typedef struct { int x, y, z; } Vec;
extern void STA_ACT_LIGHT_ElemOpA(void *unused, unsigned int *p, unsigned int *q);
extern void STA_ACT_EFFECT_StartEffect(char *, unsigned, const int *);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void STA_ACTING_PositionAnim(char *p, unsigned i)
{
    Vec v;
    u8 j;
    STA_ACT_LIGHT_ElemOpA(((struct Obj14088 *)p)->f40, *(void **)(p + i * 4 + 0x44), (unsigned int *)(&v));
    v.x /= 16;
    v.y = (0xc0000 - (v.y - 0x20000)) / 16;
    v.z = 0xb4000;
    for (j = 0; j < 3; j++) STA_ACT_EFFECT_StartEffect(*(char * *)&((struct Obj14088 *)p)->fBC, j, &v.x);
    GFL_USE_PlaySeDefaultVolume(1961);
}
