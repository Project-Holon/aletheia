/*
 * function: C_GEAR_StepRipple
 * address:  0x021F009C
 * packet:   pkt_ov029_021F009C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_IsTileActorIdle  0x021F0064  thumb  ov029
 *   C_GEAR_SpawnRippleActor  0x021EFF58  thumb  ov029
 *   C_GEAR_GetHexNeighbors  0x021EFF00  thumb  ov029
 */

typedef unsigned char u8;

extern int C_GEAR_IsTileActorIdle(u8 *p, int x, int y);
extern void C_GEAR_SpawnRippleActor(u8 *p, int a, int c);
extern void C_GEAR_GetHexNeighbors(int x, int y, int *a, int *b);

int C_GEAR_StepRipple(u8 *p)
{
    int y;
    int x;
    int k;
    u8 *q;
    int xs[6];
    int ys[6];

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 9; x++) {
            q = p + y + x * 4;
            if (q[0x3f0] == 4 && C_GEAR_IsTileActorIdle(p, x, y) != 0) {
                q[0x3f0] = 5;
            }
            if (q[0x3f0] == 2) {
                C_GEAR_SpawnRippleActor(p, x, y);
                q[0x3f0] = 3;
            }
        }
    }
    p[0x415]++;
    if (p[0x415] >= 16) {
        return 1;
    }
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 9; x++) {
            q = p + y + x * 4;
            if (q[0x3f0] == 3) {
                q[0x3f0] = 4;
                C_GEAR_GetHexNeighbors(x, y, xs, ys);
                for (k = 0; k < 6; k++) {
                    if (xs[k] >= 0 && xs[k] < 9 && ys[k] >= 0 && ys[k] < 4) {
                        q = p + xs[k] * 4 + ys[k];
                        if (q[0x3f0] == 1) {
                            q[0x3f0] = 2;
                        } else if (q[0x3f0] == 0) {
                            q[0x3f0] = 3;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
