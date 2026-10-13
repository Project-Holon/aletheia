/*
 * function: WEATHER_TASK_CreateParticleActor
 * address:  0x021A2BD4
 * packet:   pkt_ov021_021A2BD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorVisible  0x0204BA20  arm
 *   gWeatherParticlePosition  0x021D88E0  data  a4
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 gWeatherParticlePosition[];

struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
void CLACT_SetActorDrawEnable(struct Obj *h, unsigned int v);
struct Actor;
void CLACT_SetActorVisible(struct Actor *a, u32 v);

typedef struct { u16 id; u16 x, y, z; } Q;
void WEATHER_TASK_CreateParticleActor(u32 *p, u32 a, const Q *q, int b, u16 e)
{
    p[0] = a;
    p[1] = (u32)CLACT_CreateActor((void *)b, q->x, q->y, q->z, gWeatherParticlePosition, 0, e);
    CLACT_SetActorDrawEnable((struct Obj *)p[1], 0);
    CLACT_SetActorVisible((struct Actor *)p[1], 0);
}
