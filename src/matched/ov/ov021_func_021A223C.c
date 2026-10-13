/*
 * function: WEATHER_TASK_StepSpawner
 * address:  0x021A223C
 * packet:   pkt_ov021_021A223C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed for the ov026 lane.
 *
 * symbols:
 *   WEATHER_TASK_StepSpawner 0x021A223C thumb ov021
 *   WEATHER_TASK_TickSpawner 0x021A2AB8 thumb ov021
 */

extern int WEATHER_TASK_TickSpawner(unsigned char *o, int arg);

int WEATHER_TASK_StepSpawner(unsigned char *o, int arg)
{
    return WEATHER_TASK_TickSpawner(o + 0x4C, arg);
}
