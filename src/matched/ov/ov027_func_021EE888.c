/*
 * function: WEATHER_SANDSTORM_Run
 * address:  0x021EE888
 * packet:   pkt_ov027_021EE888
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_StepSpawnTimer  0x021A2248  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 *   WEATHER_SANDSTORM_SpawnParticles  0x021EEA04  thumb  ov027
 *   WEATHER_SANDSTORM_ScrollBillboards  0x021EEAF4  thumb  ov027
 *   gSandstormGustSpeedX     0x021EEB48  data  ov027  a4
 */

int *WEATHER_TASK_GetWorkBuffer(int *p);
int WEATHER_TASK_StepSpawnTimer(unsigned char *o, int arg);
int func_0209C0A4(int a, int b);
void WEATHER_SANDSTORM_SpawnParticles(int a, int b, int c);
void WEATHER_SANDSTORM_ScrollBillboards(int a, int *p);
extern int gSandstormGustSpeedX[];

int WEATHER_SANDSTORM_Run(int a, int b, int c)
{
    int *p = WEATHER_TASK_GetWorkBuffer((int *)a);

    if (WEATHER_TASK_StepSpawnTimer((unsigned char *)a, c) != 0) {
        int v = gSandstormGustSpeedX[func_0209C0A4(p[1], 40)];
        p[3] = v;
        if (v <= -6)
            WEATHER_SANDSTORM_SpawnParticles(a, 1, c);
    }
    WEATHER_SANDSTORM_ScrollBillboards(a, p);
    return 0;
}
