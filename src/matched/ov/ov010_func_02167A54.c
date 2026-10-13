/*
 * function: COMM_PLAYER_CheckActive
 * address:  0x02167A54
 * packet:   pkt_ov010_02167A54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (sole blocker of ov018 EVENT_COMM_COMMON_TalkedStartEventMain).
 *
 * symbols:
 */

typedef struct {
    unsigned char b0 : 1;
} Flag;

int COMM_PLAYER_CheckActive(int *p, int i)
{
    if (p == 0 || p[1] == 0 || !((Flag *)((char *)p + i * 0x1c + 0x1c))->b0) {
        return 0;
    }
    return 1;
}
