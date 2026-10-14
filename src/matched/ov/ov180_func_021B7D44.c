/*
 * function: HALL_OF_FAME_DeleteMonSceneObjects
 * address:  0x021B7D44
 * packet:   pkt_021B7D44
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HALL_OF_FAME_DeleteAllTextPlates  0x021B77C4  thumb  ov180
 *   HALL_OF_FAME_DeleteAllActors  0x021B7604  thumb  ov180
 *   HALL_OF_FAME_ReleaseAllResources  0x021B756C  thumb  ov180
 */

extern void HALL_OF_FAME_DeleteAllTextPlates(int *);
extern void HALL_OF_FAME_DeleteAllActors(int *);
extern void HALL_OF_FAME_ReleaseAllResources(char *p);

void HALL_OF_FAME_DeleteMonSceneObjects(int *p)
{
    HALL_OF_FAME_DeleteAllTextPlates(p);
    HALL_OF_FAME_DeleteAllActors(p);
    HALL_OF_FAME_ReleaseAllResources((char *)p);
}
