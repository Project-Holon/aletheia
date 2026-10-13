/*
 * function: WEATHER_TASK_SetParticlePosWrapped
 * address:  0x021A2654
 * packet:   pkt_ov021_021A2654
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_GetParticleActorPtr  0x021A2C28  thumb  ov021
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   _s32_div_f     0x0209C0A4  arm
 */

typedef short Pt;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
struct Vec2;
u32 WEATHER_TASK_GetParticleActorPtr(u8 *p);
void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

void WEATHER_TASK_SetParticlePosWrapped(int obj, unsigned short *src)
{
    Pt pt[2];

    pt[0] = src[0];
    pt[1] = src[1];
    if (pt[0] > 320) {
        pt[0] = pt[0] % 320;
    } else if (pt[0] < -64) {
        pt[0] = pt[0] + 320;
    }
    if (pt[1] > 256) {
        Pt *py;
        py = &pt[1];
        *py = *py % 256;
    } else if (pt[1] < -64) {
        pt[1] = pt[1] + 256;
    }
    CLACT_AddActorSurfacePos((struct Obj *)WEATHER_TASK_GetParticleActorPtr((u8 *)obj), (const struct Vec2 *)pt, 0);
}
