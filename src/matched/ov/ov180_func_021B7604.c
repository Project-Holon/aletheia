/*
 * function: HALL_OF_FAME_DeleteAllActors
 * address:  0x021B7604
 * packet:   pkt_021B7604
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HALL_OF_FAME_DeleteActor  0x021B75E8  thumb  ov180
 */

extern void HALL_OF_FAME_DeleteActor(char *p, int i);

void HALL_OF_FAME_DeleteAllActors(int *p)
{
    unsigned int i;

    for (i = 0; i < 0x21; i++)
        HALL_OF_FAME_DeleteActor((char *)p, i);
}
