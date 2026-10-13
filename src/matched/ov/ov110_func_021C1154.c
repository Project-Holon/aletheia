/*
 * function: PMS_SELECT_GRAPHIC_FlushRowWindows
 * address: 0x021C1154
 * packet: pkt_ov110_021C1154
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: byte-pointer address arithmetic restores the r5 object/r6 state-base allocation; unsigned-integer address sums swap those registers.
 * symbols:
 *   PMS_SELECT_GRAPHIC_FlushRowWindow 0x021C1174 thumb ov110
 */
extern int PMS_SELECT_GRAPHIC_FlushRowWindow(unsigned, void *, int *);
void PMS_SELECT_GRAPHIC_FlushRowWindows(char *p)
{
    int i;
    for (i=0; i<4; i++)
        PMS_SELECT_GRAPHIC_FlushRowWindow(*(unsigned *)(p+0x5c), *(void **)(p+i*4+0x6c), (int *)(p+0x7c+i*4));
}
