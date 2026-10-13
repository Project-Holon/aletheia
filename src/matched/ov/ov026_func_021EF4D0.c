/*
 * function: WEATHER_STORM_UpdateFastSideStreak
 * address:  0x021EF4D0
 * packet:   pkt_ov026_021EF4D0
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note: 2026-10-05 (wD8 lane04): closed. b is a const pointer (the struct is for readability; a
 *   const char * with casts gives the same bytes, a non-const one does not): the c[1] store then does
 *   not kill the CSE of c[3] + b->vy, so c[5] reuses the kept sum. Both sums are written inline
 *   (c[0] + (s16)(c[2] + vx)) and repeated for c[4]/c[5].
 *   EXACT* = 186 bytes compiled vs a 188-byte listing extent (2 bytes of padding).
 *
 * symbols:
 *   WEATHER_TASK_GetParticlePos  0x021A2640  thumb  ov021
 *   WEATHER_TASK_RemoveParticle  0x021A21E0  thumb  ov021
 *   WEATHER_TASK_SetParticlePos  0x021A26C4  thumb  ov021
 */

typedef short s16;
struct PtS { s16 x; s16 y; };
struct B { char pad[0x16]; s16 vx; s16 vy; };
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void WEATHER_TASK_GetParticlePos(u8 *a, struct PtS *b);
extern void WEATHER_TASK_RemoveParticle(u32 *p);
extern int WEATHER_TASK_SetParticlePos(u32 a, u32 b);
void WEATHER_STORM_UpdateFastSideStreak(void *a, const struct B *b, s16 *c)
{
    struct PtS pt;
    s16 vx;
    WEATHER_TASK_GetParticlePos(a, &pt);
    vx = b->vx;
    if (vx != 0) {
        c[0] = c[0] + (s16)(c[2] + vx);
        c[1] = c[1] + (s16)(c[3] + b->vy);
        pt.x = c[0] / 8;
        pt.y = c[1] / 8;
        c[4] = c[2] + vx;
        c[5] = c[3] + b->vy;
    } else {
        c[0] = c[0] + c[4];
        c[1] = c[1] + c[5];
        pt.x = c[0] / 8;
        pt.y = c[1] / 8;
    }
    if (pt.x >= 0x100 || pt.y >= 0xc0) {
        WEATHER_TASK_RemoveParticle(a);
    } else {
        WEATHER_TASK_SetParticlePos((u32)a, (u32)(&pt));
    }
}
