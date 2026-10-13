/*
 * function: WEATHER_TASK_GetParticlePos
 * address:  0x021A2640
 * packet:   pkt_021A2640
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   WEATHER_TASK_GetParticleActorPtr  0x021A2C28  thumb  ov021
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Actor;
struct PtS {
    s16 x;
    s16 y;
};
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern u32 WEATHER_TASK_GetParticleActorPtr(u8 *);

void WEATHER_TASK_GetParticlePos(u8 *a, struct PtS *b)
{
    CLACT_GetActorSurfacePos((struct Actor *)WEATHER_TASK_GetParticleActorPtr(a), b, 0);
}

