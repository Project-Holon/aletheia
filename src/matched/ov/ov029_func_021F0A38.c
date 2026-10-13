/*
 * function: C_GEAR_StepTiles
 * address: 0x021F0A38
 * packet: pkt_ov029_021F0A38
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   C_GEAR_StepTileFlash 0x021F0B88 thumb ov029
 */
extern void C_GEAR_StepTileFlash(void *p, void *q);
void C_GEAR_StepTiles(unsigned char *p)
{
    int i, j;
    unsigned char *base;
    i = 0;
    base = p + 0x2d0;
    for (; i < 9; i++) {
        for (j = 0; j < 4; j++) C_GEAR_StepTileFlash(base + i * 32 + j * 8, p);
    }
}
