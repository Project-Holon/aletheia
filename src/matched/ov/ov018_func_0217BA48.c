/*
 * function: INTRUDE_FIELD_StartCommAfterExit
 * address:  0x0217BA48
 * packet:   pkt_0217BA48
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   INTRUDE_FIELD_StartComm  0x0217BA54  thumb
 */

void INTRUDE_FIELD_StartComm(void *a);

void INTRUDE_FIELD_StartCommAfterExit(int a, int b)
{
    if (b == 0)
        INTRUDE_FIELD_StartComm((void *)a);
}
