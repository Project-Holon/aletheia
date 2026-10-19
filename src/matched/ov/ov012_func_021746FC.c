/*
 * function: UNION_SCENE_StepWarpToZone1A6
 * address:  0x021746FC
 * packet:   pkt_ov012_021746FC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_MAPCHANGE_CreateWarpEvent  0x02184D38  thumb  ov020
 */

typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} P;

typedef unsigned short u16;
extern void *EVENT_MAPCHANGE_CreateWarpEvent(void *p, int unused, int a, const int *q, u16 s, int t);

int UNION_SCENE_StepWarpToZone1A6(int a, int b, int c, int d, int e, int *out, u8 *cnt)
{
    P s;
    int z;

    if (*cnt == 0) {
        s.a = 0x2e << 14;
        z = 0;
        s.b = z;
        s.c = 0x3a << 14;
        *out = (int)EVENT_MAPCHANGE_CreateWarpEvent((void *)a, c, 0x1A6, (const int *)(&s), z, z);
    } else {
        return 1;
    }
    *cnt = *cnt + 1;
    return z;
}
