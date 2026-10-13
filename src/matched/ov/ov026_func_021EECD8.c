/*
 * function: WEATHER_THUNDERSTORM_Run
 * address: 0x021EECD8
 * packet: pkt_ov026_021EECD8
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_StepSpawnTimer 0x021A2248 thumb ov021
 *   WEATHER_LIGHTNING_Update 0x021EF9D8 thumb ov026
 *   WEATHER_THUNDERSTORM_ScrollLayers 0x021EEF0C thumb ov026
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int *WEATHER_TASK_GetWorkBuffer(int *);
extern int WEATHER_TASK_StepSpawnTimer(u8 *, int);
extern void WEATHER_LIGHTNING_Update(void *, int);
extern void WEATHER_THUNDERSTORM_ScrollLayers(int, int *);

int WEATHER_THUNDERSTORM_Run(u8 *a, int b, int c)
{
    int *p;
    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    p[2] = (p[2] + 1) % 300;
    WEATHER_TASK_StepSpawnTimer(a, c);
    WEATHER_LIGHTNING_Update(p + 3, (int)a);
    WEATHER_THUNDERSTORM_ScrollLayers((int)a, p);
    return 0;
}
