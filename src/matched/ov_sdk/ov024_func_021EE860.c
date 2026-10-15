/*
 * function: WEATHER_CLEAR_EndFade
 * address:  0x021EE860
 * packet:   pkt_ov024_021EE860
 * region:   ov024
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 */

extern int WEATHER_TASK_IsFogIdle(unsigned int a);

int WEATHER_CLEAR_EndFade(void *frienddata)
{
    if (WEATHER_TASK_IsFogIdle((unsigned int)frienddata))
        return 1;
    return 0;
}
