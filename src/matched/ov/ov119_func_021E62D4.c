/*
 * function: func_021E62D4
 * address: 0x021E62D4
 * packet: pkt_ov119_021E62D4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 */
typedef struct {
    char pad[0x1008];
    int h[2][3];
    int w[2][3];
} Work;

extern void func_0204B3B4(int);
extern void func_0204A8D4(int);

void func_021E62D4(Work *p, int a, int b)
{
    if (p->h[a][b]) {
        func_0204B3B4(p->h[a][b]);
        p->h[a][b] = 0;
        func_0204A8D4(p->w[a][b]);
    }
}
