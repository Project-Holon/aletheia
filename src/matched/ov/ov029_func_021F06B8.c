/*
 * function: C_GEAR_SetTabMode
 * address:  0x021F06B8
 * packet:   pkt_ov029_021F06B8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_SetTabMode  0x021F06B8  thumb  ov029
 *   C_GEAR_BlendTabPalette  0x021F08BC  thumb  ov029
 *   C_GEAR_ClearTabTimerCount  0x021F0D00  thumb  ov029
 */

typedef unsigned char u8;

struct E {
    u8 b[10];
};

struct W;
extern void C_GEAR_BlendTabPalette(struct W *p, int i, int j, int k);
extern void C_GEAR_ClearTabTimerCount(unsigned short *p, int i);

void C_GEAR_SetTabMode(u8 *p, int a, int b)
{
    struct E *q;
    int i;
    int j;
    int k;

    for (i = 0; i < 3; i++) {
        C_GEAR_BlendTabPalette((struct W *)p, i, 0, 0x1f);
    }
    q = (struct E *)(p + 0x418);
    for (j = 0; j < 5; j++) {
        for (k = 0; k < 3; k++) {
            C_GEAR_ClearTabTimerCount((short unsigned int *)(&q[j]), k);
        }
    }
    p[0x461] = a;
    p[0x460] = 1;
    p[0x465] = 1;
    p[0x466] = 0;
    p[0x464] = b;
}
