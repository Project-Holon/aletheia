/*
 * function: WEATHER_BLIZZARD_SpawnParticles
 * address:  0x021EEE04
 * packet:   pkt_ov025_021EEE04
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     idx is narrow (u16/s16/u8 all give EXACT; int puts its home store
 *           third instead of first): WEATHER_TASK_AddParticle only forwards it, so no
 *           callee fixes the exact width. const on the two tables lets the
 *           indexed loads hoist out of the loop past the stores through e.
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   func_0204B404  0x0204B404  arm
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_AddParticle  0x021A21C8  thumb  ov021
 *   WEATHER_TASK_GetParticleWork  0x021A2630  thumb  ov021
 *   WEATHER_TASK_GetParticleActor  0x021A2638  thumb  ov021
 *   gBlizzardWindSpeedY     0x021EF780  data   a4
 *   gBlizzardWindSpeedX     0x021EF770  data   a4
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

extern u32 func_020056EC(u32 v);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void *WEATHER_TASK_AddParticle(void *p, int a1);
extern unsigned char *WEATHER_TASK_GetParticleWork(unsigned char *o);
extern unsigned int WEATHER_TASK_GetParticleActor(unsigned char *o);
extern const int gBlizzardWindSpeedY[];
extern const int gBlizzardWindSpeedX[];

void WEATHER_BLIZZARD_SpawnParticles(int a, int n, u16 idx)
{
    int *q;
    int k;
    int i;
    int obj;
    int *e;
    int h;
    int m;
    Pt pt;

    q = WEATHER_TASK_GetWorkBuffer((int *)a);
    if (++q[1] >= 0x400) {
        q[1] = 0;
    }
    k = q[1] / 256;
    for (i = 0; i < n; i++) {
        obj = (int)WEATHER_TASK_AddParticle((void *)a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)WEATHER_TASK_GetParticleWork((unsigned char *)obj);
        h = WEATHER_TASK_GetParticleActor((unsigned char *)obj);
        e[0] = 0;
        e[1] = func_020056EC(3) + 9;
        m = func_020056EC(4);
        CLACT_SetActorAnimIndex(h, (u16)m);
        e[4] = (m + 1) * gBlizzardWindSpeedX[k];
        e[2] = gBlizzardWindSpeedY[k] * (m + 1);
        e[3] = 0;
        if (m == 3) {
            e[4] = e[4] + gBlizzardWindSpeedX[k];
            e[2] = e[2] + gBlizzardWindSpeedY[k];
        }
        e[5] = gBlizzardWindSpeedX[k];
        pt.x = -func_020056EC(0x18);
        pt.y = func_020056EC(0xA8) - 0x20;
        func_0204B404((struct Obj *)h, (const struct Vec2 *)(&pt), 0);
    }
}
