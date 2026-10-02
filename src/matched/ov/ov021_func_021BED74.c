/*
 * function: func_021BED74
 * address:  0x021BED74
 * packet:   pkt_ov021_021BED74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BF2E0  0x021BF2E0  thumb  ov021
 *   func_021BEA6C  0x021BEA6C  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Ent;

void func_021BF2E0(void);
int func_020122C0(int a, int b, void (*fn)(void), int c);
Ent *func_020124E8(int h);
int func_021BEA6C(int a);

int func_021BED74(int a, int b)
{
    int h = func_020122C0(a, 0, func_021BF2E0, 0x2c);
    Ent *e = func_020124E8(h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = 8;
    e->fC = func_021BEA6C(8);
    return h;
}
