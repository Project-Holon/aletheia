/*
 * function: STA_ACTING_RankScores
 * address: 0x021F95F0
 * packet: pkt_ov132_021F95F0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
void STA_ACTING_RankScores(u8 *p)
{
    u8 i, j;
    u16 score;
    for (i = 0; i < 4; i++) p[0xf3 + i] = 0;
    for (i = 0; i < 4; i++) {
        score = (u16)(*(u16 *)((*(u8 ***)(p + 0x30))[i + 1] + 0x4a) + p[0xf7 + i]);
        for (j = 0; j < 4; j++) {
            if (i != j) {
                if ((u16)(*(u16 *)((*(u8 ***)(p + 0x30))[j + 1] + 0x4a) + p[0xf7 + j]) > score) p[0xf3 + i]++;
            }
        }
    }
}
