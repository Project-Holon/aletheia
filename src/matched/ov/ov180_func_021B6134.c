/*
 * function: HALL_OF_FAME_ProcMain
 * address:  0x021B6134
 * packet:   pkt_021B6134
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HALL_OF_FAME_RunState  0x021B6A10  thumb  ov180
 */

extern int HALL_OF_FAME_RunState(char *p);

int HALL_OF_FAME_ProcMain(int a, int b, int c, int d)
{
    if (HALL_OF_FAME_RunState((char *)d))
        return 0;
    return 1;
}
