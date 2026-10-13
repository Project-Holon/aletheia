/*
 * function: C_GEAR_StopTileFlashes
 * address: 0x021F0AA0
 * packet: pkt_ov029_021F0AA0
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   C_GEAR_StopTileFlash 0x021F0B7C thumb ov029
 */
struct S021F0B7C { unsigned short f0:1; };
extern void C_GEAR_StopTileFlash(struct S021F0B7C *);
void C_GEAR_StopTileFlashes(char *p)
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            C_GEAR_StopTileFlash((struct S021F0B7C *)(p + 0x2d0 + i * 32 + j * 8));
        }
    }
}
