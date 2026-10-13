/*
 * function: GIMMICK41_TurnRingDirection
 * address:  0x021F3F70
 * packet:   pkt_ov041_021F3F70
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GIMMICK41_TurnRingDirection  0x021F3F70  thumb
 *   d_021F4080     0x021F4080  data  a1
 */

typedef unsigned char u8;

typedef struct {
    u8 b[4];
} T4;

extern T4 d_021F4080;

int GIMMICK41_TurnRingDirection(int a, int b)
{
    T4 t = d_021F4080;
    u8 i;
    u8 j;

    for (i = 0; i < 4; i++) {
        if (t.b[i] == a) {
            j = (i + b) % 4;
            return t.b[j];
        }
    }
    return a;
}
