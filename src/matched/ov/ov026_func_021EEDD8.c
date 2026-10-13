/*
 * function: WEATHER_THUNDERSTORM_UpdateParticle
 * address:  0x021EEDD8
 * packet:   pkt_ov026_021EEDD8
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WEATHER_THUNDERSTORM_UpdateParticle 0x021EEDD8 thumb ov026
 *   WEATHER_TASK_GetParticleWork 0x021A2630 thumb ov021
 *   WEATHER_TASK_GetParticleActor 0x021A2638 thumb ov021
 *   WEATHER_TASK_GetParticlePos 0x021A2640 thumb ov021
 *   WEATHER_TASK_SetParticlePos 0x021A26C4 thumb ov021
 *   WEATHER_TASK_RemoveParticle 0x021A21E0 thumb ov021
 */

typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

typedef unsigned int   u32;
extern unsigned char *WEATHER_TASK_GetParticleWork(unsigned char *o);
extern unsigned int WEATHER_TASK_GetParticleActor(unsigned char *o);
struct PtS;
extern void WEATHER_TASK_GetParticlePos(unsigned char *, struct PtS *);
extern int WEATHER_TASK_SetParticlePos(u32 a, u32 b);
extern void WEATHER_TASK_RemoveParticle(u32 *p);

void WEATHER_THUNDERSTORM_UpdateParticle(int a)
{
    int *p;
    Pt pt;

    p = (int *)WEATHER_TASK_GetParticleWork((unsigned char *)a);
    WEATHER_TASK_GetParticleActor((unsigned char *)a);
    WEATHER_TASK_GetParticlePos((unsigned char *)a, (struct PtS *)&pt);
    switch (p[3]) {
    case 0:
        pt.x = pt.x + (s16)p[4];
        pt.y = pt.y + (s16)p[2];
        if (pt.y >= 0xC0) {
            p[3] = 1;
        }
        WEATHER_TASK_SetParticlePos(a, (u32)(&pt));
        break;
    case 1:
        WEATHER_TASK_RemoveParticle((u32 *)a);
        break;
    }
}
