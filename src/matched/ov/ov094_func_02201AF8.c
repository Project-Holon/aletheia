/*
 * function: BTLV_CLACT_LoadActorSimple
 * address:  0x02201AF8
 * packet:   pkt_ov094_02201AF8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CLACT_LoadActor  0x02201B20  thumb  ov094
 */
extern void BTLV_CLACT_LoadActor(int a, int b, int c, int c1, int c2, int c3, int d, short e, int f, int g);

void BTLV_CLACT_LoadActorSimple(int a, int b, int c, int d, short e, int f, int g)
{
    BTLV_CLACT_LoadActor(a, b, c, c + 1, c + 2, c + 3, d, e, f, g);
}
