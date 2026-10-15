/*
 * function: ZKNSEARCH_MAIN_PlacePageActor
 * address: 0x021BFB8C
 * packet: pkt_ov210_021BFB8C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned long slot keeps updates in its home; enum y keeps the wide updated value and repeats s16 call truncation. int/short variants sank or cached updates (110–118 B); check3b EXACT 108 B.
 * symbols:
 *   ZKNSEARCH_MAIN_SetActorVisible 0x021BEDF0 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorSurfacePos 0x021BEE38 thumb ov210
 */
extern void ZKNSEARCH_MAIN_SetActorVisible(int p, int i, int v);
extern void ZKNSEARCH_MAIN_SetActorSurfacePos(char *p, int idx, int a, short b, unsigned short c);
typedef enum Y { YMin = -2147483647, YMax = 2147483647 } Y;
void ZKNSEARCH_MAIN_PlacePageActor(char *ctx, unsigned long slot, Y y, int flag)
{
    unsigned long second;
    if (flag == 1) {
        slot += 15;
        ZKNSEARCH_MAIN_SetActorVisible((int)ctx, (unsigned)slot, (unsigned)1);
        y += 20;
        ZKNSEARCH_MAIN_SetActorSurfacePos(ctx, (unsigned)slot, (unsigned short)204, y, 0);
    } else {
        second = slot + 29;
        ZKNSEARCH_MAIN_SetActorVisible((int)ctx, (unsigned)second, (unsigned)1);
        y += 20;
        ZKNSEARCH_MAIN_SetActorSurfacePos(ctx, (unsigned)second, (unsigned short)204, y, 1);
        slot += 43;
        ZKNSEARCH_MAIN_SetActorVisible((int)ctx, (unsigned)slot, (unsigned)1);
        ZKNSEARCH_MAIN_SetActorSurfacePos(ctx, (unsigned)slot, (unsigned short)204, y, 1);
    }
}
