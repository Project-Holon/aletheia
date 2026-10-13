/*
 * function: func_021F0194
 * address:  0x021F0194
 * packet:   pkt_ov029_021F0194
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0194  0x021F0194  thumb  ov029
 *   C_GEAR_GetCellKind  0x021F2B9C  thumb  ov029
 *   C_GEAR_StepRipple  0x021F009C  thumb  ov029
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern u32 C_GEAR_GetCellKind(u8 *p, int row, int col);
extern int C_GEAR_StepRipple(u8 *p);

void func_021F0194(u8 *p)
{
    int v;
    int j;
    int i;

    v = C_GEAR_GetCellKind(p, p[0x452], p[0x453]);
    p[0x414] = v;
    i = 0;
    p[0x415] = i;
    for (; i < 4; i++) {
        for (j = 0; j < 9; j++) {
            if (v == C_GEAR_GetCellKind(p, j, i)) {
                p[0x3f0 + j * 4 + i] = 1;
            }
        }
    }
    (p + p[0x452] * 4 + p[0x453])[0x3f0] = 2;
    C_GEAR_StepRipple(p);
}
