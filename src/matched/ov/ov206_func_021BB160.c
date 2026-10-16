/*
 * function: ZUKAN_INFO_ReleaseActor
 * address: 0x021BB160
 * packet: pkt_ov206_021BB160
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_INFO_DeleteActor 0x021BB2C4 thumb
 *   ZUKAN_INFO_ReleaseGfx 0x021BB214 thumb
 */
extern void ZUKAN_INFO_DeleteActor(char *, int);
extern void ZUKAN_INFO_ReleaseGfx(char *, int);
void ZUKAN_INFO_ReleaseActor(char *p, int i)
{
    void **slot = (void **)(p + 0xac) + i;
    if (*slot != 0) {
        ZUKAN_INFO_DeleteActor(p, i);
        ZUKAN_INFO_ReleaseGfx(p, i);
        *slot = 0;
    }
}
