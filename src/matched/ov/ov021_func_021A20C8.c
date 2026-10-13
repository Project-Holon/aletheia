/*
 * function: WEATHER_TASK_ForceEnd
 * address:  0x021A20C8
 * packet:   pkt_ov021_021A20C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_CallStageFunc  0x021A2724  thumb  ov021
 *   WEATHER_TASK_FreeParticles  0x021A2924  thumb  ov021
 *   WEATHER_TASK_FreeBillboards  0x021A28A0  thumb  ov021
 *   WEATHER_TASK_UnloadResources  0x021A284C  thumb  ov021
 *   WEATHER_TASK_Reset  0x021A26D8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct O {
    u32 pad0[8];
    u32 *f20;
    u8  pad24[2];
    u8  f26;
} O;

extern void WEATHER_TASK_CallStageFunc(O *p, u32 v, int z);
extern void WEATHER_TASK_FreeParticles(O *p);
extern void WEATHER_TASK_FreeBillboards(O *p);
extern void WEATHER_TASK_UnloadResources(O *p);
extern void WEATHER_TASK_Reset(int *p);

void WEATHER_TASK_ForceEnd(O *p)
{
    if (p->f26 == 0) {
        return;
    }
    if (p->f26 <= 0xb) {
        WEATHER_TASK_CallStageFunc(p, p->f20[0x11], 0);
    }
    if (p->f26 <= 0xc) {
        WEATHER_TASK_FreeParticles(p);
        WEATHER_TASK_FreeBillboards(p);
        WEATHER_TASK_UnloadResources(p);
    }
    WEATHER_TASK_Reset((int *)p);
}
