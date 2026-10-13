/*
 * function: WEATHER_TASK_GetWorkBuffer
 * address:  0x021A21B8
 * packet:   pkt_ov021_021A21B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled 4-byte leaf: returns field 0x3c (ldr r0,[r0,#0x3c]).
 */

int *WEATHER_TASK_GetWorkBuffer(int *p)
{
    return (int *)p[15];
}
