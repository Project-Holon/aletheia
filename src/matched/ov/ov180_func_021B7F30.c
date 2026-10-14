/*
 * function: HALL_OF_FAME_DrawTrainerScene
 * address: 0x021B7F30
 * packet: pkt_ov180_021B7F30
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HALL_OF_FAME_UpdateActors 0x021B73B0 thumb ov180
 */
extern void HALL_OF_FAME_UpdateActors(char *p);
void HALL_OF_FAME_DrawTrainerScene(void *p) { HALL_OF_FAME_UpdateActors(p); }
