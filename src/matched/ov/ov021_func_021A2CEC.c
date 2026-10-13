/*
 * function: WEATHER_TASK_ClearFogChange
 * address:  0x021A2CEC
 * packet:   pkt_021A2CEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void WEATHER_TASK_ClearFogChange(char *p)
{
    p[0x77c] = 0;
}
