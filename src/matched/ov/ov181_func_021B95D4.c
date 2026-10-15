/*
 * function: STAFF_ROLL_Main
 * address:  0x021B95D4
 * packet:   pkt_ov181_021B95D4
 * region:   ov181
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STAFF_ROLL_RunState  0x021B95F8  thumb  ov181
 */

extern int STAFF_ROLL_RunState(char *p);

int STAFF_ROLL_Main(int a0, int a1, int a2, int a3)
{
    return STAFF_ROLL_RunState((char *)a3) == 0;
}
