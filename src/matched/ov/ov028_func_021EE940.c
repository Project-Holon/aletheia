/*
 * function: func_021EE940
 * address:  0x021EE940
 * packet:   pkt_ov028_021EE940
 * region:   ov028
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A2148  0x021A2148  thumb  ov021
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   d_021EEA80     0x021EEA80  data  ov028  a1
 *   d_021EEAA4     0x021EEAA4  data  ov028  a4
 */

int func_021A2148(int a);
int *func_021A21B8(int a);
void func_021A22E0(int a, int b, int c, int d);
extern unsigned char d_021EEA80[];
extern int d_021EEAA4[];

int func_021EE940(int a, int b)
{
    int i = func_021A2148(a);
    int *p = func_021A21B8(a);

    p[1] = 0;
    p[0] = 14;
    p[11] = d_021EEA80[i];
    p[12] = d_021EEAA4[i];
    func_021A22E0(a, p[11], 0x7fdf, b);
    return 1;
}
