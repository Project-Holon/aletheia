/*
 * function: HALL_OF_FAME_DeleteAllTextPlates
 * address:  0x021B77C4
 * packet:   pkt_021B77C4
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HALL_OF_FAME_DeleteTextPlate  0x021B7798  thumb  ov180
 */

extern void HALL_OF_FAME_DeleteTextPlate(int *, int);

void HALL_OF_FAME_DeleteAllTextPlates(int *p)
{
    unsigned int i;

    for (i = 0; i < 4; i++)
        HALL_OF_FAME_DeleteTextPlate(p, i);
}
