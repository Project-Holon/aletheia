/*
 * function: func_021A2D30
 * address:  0x021A2D30
 * packet:   pkt_ov021_021A2D30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207C768  0x0207C768  arm
 */

typedef struct {
    int f0;
    int pad4[4];
    int f14;
} Obj;

int func_0207C768(int a, int b);

void func_021A2D30(Obj *o, int v, int *out2, int *out1)
{
    *out1 = (int)(((long long)func_0207C768(v, o->f14) * 0x2000 + 0x800) >> 12);
    *out2 = (int)(((long long)func_0207C768(v, o->f0) * 0x2000 + 0x800) >> 12);
}
