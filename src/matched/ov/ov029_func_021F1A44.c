/*
 * function: C_GEAR_SetTileMarkersVisible
 * address: 0x021F1A44
 * packet: pkt_ov029_021F1A44
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
void C_GEAR_SetTileMarkersVisible(char *p, int flag)
{
    int i;
    for (i = 0; i < 3; i++)
        CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x158), flag);
}
