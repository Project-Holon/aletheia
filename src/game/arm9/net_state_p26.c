/*
 * function: func_0203A574
 * address:  0x0203A574
 * packet:   pkt_0203A574
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469D8   0x021469D8  data
 */

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
} Ent;

extern Ent *g_021469D8;

void func_0203A574(u32 a, u32 b, u32 c, u32 d)
{
    Ent *p = g_021469D8;
    int i;

    if (p == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (p[i].fC == 0 || p[i].fC == a) {
            p[i].fC = a;
            g_021469D8[i].f0 = b;
            g_021469D8[i].f4 = c;
            g_021469D8[i].f8 = d;
            return;
        }
    }
}
