/*
 * function: WEATHER_BLIZZARD_UpdateParticle
 * address:  0x021EED78
 * packet:   pkt_ov025_021EED78
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WEATHER_BLIZZARD_UpdateParticle 0x021EED78 thumb ov025
 *   WEATHER_TASK_GetParticleWork 0x021A2630 thumb ov021
 *   WEATHER_TASK_GetParticleActor 0x021A2638 thumb ov021
 *   WEATHER_TASK_RemoveParticle 0x021A21E0 thumb ov021
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */

typedef signed short s16;

typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern unsigned char *WEATHER_TASK_GetParticleWork(unsigned char *o);
extern unsigned int WEATHER_TASK_GetParticleActor(unsigned char *o);
extern void WEATHER_TASK_RemoveParticle(u32 *p);
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

void WEATHER_BLIZZARD_UpdateParticle(int a)
{
    int *p;
    int q;
    s16 v[2];

    p = (int *)WEATHER_TASK_GetParticleWork((unsigned char *)a);
    q = WEATHER_TASK_GetParticleActor((unsigned char *)a);
    CLACT_GetActorSurfacePos((struct Actor *)q, (struct PtS *)v, 0);
    switch (p[3]) {
    case 0:
        v[0] = v[0] + (s16)p[4];
        v[1] = v[1] + (s16)p[2];
        if (p[0]++ > p[1]) {
            p[3] = 1;
        }
        if (p[0] % 4 == 0) {
            p[4] = p[4] + p[5];
            if (p[2] > 1) {
                p[2] = p[2] - 1;
            }
        }
        CLACT_AddActorSurfacePos((struct Obj *)q, (const struct Vec2 *)v, 0);
        break;
    case 1:
        WEATHER_TASK_RemoveParticle((u32 *)a);
        break;
    }
}
