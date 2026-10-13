/*
 * function: WEATHER_TASK_StepSpawnTimer
 * address:  0x021A2248
 * packet:   pkt_ov021_021A2248
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed for lane S30 (callee of ov027 functions).
 *
 * symbols:
 *   WEATHER_TASK_StepSpawnTimer 0x021A2248 thumb ov021
 *   WEATHER_TASK_TickSpawnTimer 0x021A2B8C thumb ov021
 */

extern int WEATHER_TASK_TickSpawnTimer(unsigned char *o, int arg);

int WEATHER_TASK_StepSpawnTimer(unsigned char *o, int arg)
{
    return WEATHER_TASK_TickSpawnTimer(o + 0x4C, arg);
}
