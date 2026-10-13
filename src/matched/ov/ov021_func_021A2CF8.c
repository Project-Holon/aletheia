/*
 * function: WEATHER_TASK_HasFogChange
 * address:  0x021A2CF8
 * packet:   pkt_021A2CF8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

u8 WEATHER_TASK_HasFogChange(char *p)
{
    return p[0x77c];
}
