/*
 * function: func_021E4A1C
 * address: 0x021E4A1C
 * packet: pkt_ov119_021E4A1C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B454 0x0204B454 arm
 */
extern int func_0204B3F4(int);
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *, struct PtS *, unsigned int);
void func_021E4A1C(char *p)
{
    short xy[2];
    int i, j;
    char *q, *r;
    for (i = 0; i < 5; i++) {
        q = p + i * 4;
        for (j = 0; j < 12; j++) {
            r = q + j * 20;
            if (func_0204B3F4(*(int *)(r + 0xbb0))) {
                func_0204B454((struct Actor *)*(int *)(r + 0xbb0), (struct PtS *)xy, 1);
                *(int *)(p + 0xf54) = xy[0];
                *(int *)(p + 0xf58) = xy[1];
            }
        }
    }
}
