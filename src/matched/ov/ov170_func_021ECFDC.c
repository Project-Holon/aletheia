/*
 * function: BOX2_SEQ_ShowHandSlot
 * address: 0x021ECFDC
 * packet: pkt_ov170_021ECFDC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb ov170
 */
extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
void BOX2_SEQ_ShowHandSlot(char *p, int a, int b)
{
    int k = a + 0x1c;
    BOX2_SEQ_SetActorDrawEnable(p, k, 1);
    BOX2_SEQ_AddActorSurfacePos(p, k, 0x58, 0x38, 1);
    if (b != 0 && a != b) {
        k = b + 0x1c;
        BOX2_SEQ_SetActorDrawEnable(p, k, 1);
        BOX2_SEQ_AddActorSurfacePos(p, k, 0x7a, 0x38, 1);
    }
}
