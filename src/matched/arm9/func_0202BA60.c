/*
 * function: func_0202BA60
 * address:  0x0202BA60
 * packet:   pkt_0202BA60
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf, filed as a relocation witness for ov021
 * func_021C4D14 (wave A1, lane 13).
 */

typedef struct { int f0; int f4[3]; int f10; int f14; int f18; } E;
typedef struct { char pad[0x24]; E e[1]; } M;

void func_0202BA60(M *m, int i, int a, int b)
{
    E *e = &m->e[i];
    if (e->f0 != 1) {
        e->f0 = 1;
        e->f10 = a;
        e->f14 = b;
    }
}
