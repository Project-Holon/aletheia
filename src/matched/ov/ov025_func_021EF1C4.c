/*
 * function: WEATHER_DOWNPOUR_UpdateParticle
 * address:  0x021EF1C4
 * packet:   pkt_ov025_021EF1C4
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WEATHER_TASK_GetParticleWork  0x021A2630  thumb  ov021
 *   WEATHER_TASK_GetParticleActor  0x021A2638  thumb  ov021
 *   WEATHER_TASK_GetParticlePos  0x021A2640  thumb  ov021
 *   WEATHER_TASK_SetParticlePosWrapped  0x021A2654  thumb  ov021
 *   WEATHER_TASK_SetParticlePos  0x021A26C4  thumb  ov021
 *   WEATHER_TASK_RemoveParticle  0x021A21E0  thumb  ov021
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   CLACT_GetActorAnimSeqCount  0x0204B918  arm
 */

typedef unsigned short u16;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

typedef unsigned int   u32;
extern unsigned char *WEATHER_TASK_GetParticleWork(unsigned char *o);
extern unsigned int WEATHER_TASK_GetParticleActor(unsigned char *o);
struct PtS;
extern void WEATHER_TASK_GetParticlePos(unsigned char *, struct PtS *);
extern void WEATHER_TASK_SetParticlePosWrapped(int obj, unsigned short *src);
extern int WEATHER_TASK_SetParticlePos(u32 a, u32 b);
extern void WEATHER_TASK_RemoveParticle(u32 *p);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
struct Obj;
extern u16 CLACT_GetActorAnimSeqCount(struct Obj *p);

void WEATHER_DOWNPOUR_UpdateParticle(int a)
{
    int *p;
    int h;
    Pt pt;

    p = (int *)WEATHER_TASK_GetParticleWork((unsigned char *)a);
    h = WEATHER_TASK_GetParticleActor((unsigned char *)a);
    WEATHER_TASK_GetParticlePos((unsigned char *)a, (struct PtS *)&pt);
    switch (p[3]) {
    case 0:
        if (++p[0] > p[1]) {
            p[3] = 1;
            p[0] = (p[6] % 4) * 2 + 8;
            p[4] = 2;
            p[2] = 2;
            CLACT_SetActorAnimIndex(h, (u16)(CLACT_GetActorAnimSeqCount((struct Obj *)h) + 3));
            return;
        }
        pt.x = pt.x + (s16)p[4];
        pt.y = pt.y + (s16)p[2];
        WEATHER_TASK_SetParticlePosWrapped(a, (short unsigned int *)(&pt));
        break;
    case 1:
        pt.x = pt.x + (s16)p[4];
        if (p[0] % 2 == 0) {
            pt.y = pt.y + (s16)p[2];
        } else {
            pt.y = pt.y - (s16)p[2];
        }
        if (p[0] % 4 == 0) {
            if (p[2] - 1 >= 0) {
                p[2] = p[2] - 1;
            }
            if (p[4] - 1 >= 0) {
                p[4] = p[4] - 1;
            }
        }
        WEATHER_TASK_SetParticlePos(a, (u32)(&pt));
        if (p[0]-- <= 0) {
            p[3] = 2;
        }
        break;
    case 2:
        WEATHER_TASK_RemoveParticle((u32 *)a);
        break;
    }
}
