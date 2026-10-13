/*
 * function: WEATHER_DIAMOND_DUST_SpawnParticles
 * address:  0x021EF634
 * packet:   pkt_ov025_021EF634
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     Remainder of handed extent is rodata after return at 021EF75A.
 *           Caller explicitly supplies idx in r1 to WEATHER_TASK_AddParticle.
 * symbols:
 *   func_020056EC 0x020056EC thumb
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_AddParticle 0x021A21C8 thumb ov021
 *   WEATHER_TASK_GetParticleWork 0x021A2630 thumb ov021
 *   WEATHER_TASK_GetParticleActor 0x021A2638 thumb ov021
 *   WEATHER_TASK_SetParticlePosWrapped 0x021A2654 thumb ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

extern u32 func_020056EC(u32);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
extern int *WEATHER_TASK_GetWorkBuffer(int *);
extern void *WEATHER_TASK_AddParticle(void *p, int a1);
extern unsigned char *WEATHER_TASK_GetParticleWork(unsigned char *);
extern u32 WEATHER_TASK_GetParticleActor(unsigned char *);
extern void WEATHER_TASK_SetParticlePosWrapped(int, unsigned short *);

void WEATHER_DIAMOND_DUST_SpawnParticles(int *a, int n, int idx)
{
    int i;
    unsigned char *obj;
    int r;
    int *e;
    int h;
    int s;
    int m;
    int x;
    int d;
    int y;
    s16 pt[2];

    WEATHER_TASK_GetWorkBuffer(a);
    for (i = 0; i < n; i++) {
        obj = WEATHER_TASK_AddParticle(a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)WEATHER_TASK_GetParticleWork(obj);
        h = WEATHER_TASK_GetParticleActor(obj);
        r = func_020056EC(0);
        s = func_020056EC(0);
        e[0] = 0;
        e[1] = r % 5 + 7;
        if (r % 2 == 0) {
            e[2] = 1;
        } else {
            e[2] = -1;
        }
        e[3] = 1;
        e[4] = r % 6 + 3;
        e[5] = s % 5 + 4;
        m = r % 20;
        pt[0] = r % 384 - 64;
        pt[1] = s % 256 - 8;
        WEATHER_TASK_SetParticlePosWrapped((int)obj, (u16 *)pt);
        x = 50 - pt[0] / 3;
        d = 206 - pt[0] / 3;
        if (d < 0) {
            y = x - s % -d;
        } else {
            y = x + s % d;
        }
        if (x <= pt[1] && y >= pt[1]) {
            e[1] *= 2;
        } else {
            m = r % 4;
        }
        CLACT_SetActorAnimIndex(h, (u16)m);
    }
}
