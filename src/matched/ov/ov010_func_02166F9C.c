/*
 * function: func_02166F9C
 * address:  0x02166F9C
 * packet:   pkt_ov010_02166F9C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020120B4  0x020120B4  thumb
 *   ov_id_D9  0x000000D9  data
 *   d_021C3FE0  0x021C3FE0  data  ov217
 *   func_020145CC  0x020145CC  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

extern int func_021BE8D4(int a, int b, int c, int d);
extern void func_02012374(void *a, int b);
extern int func_020144DC(void);
extern void func_020120B4(int a, void *b, void *c, int d);
extern int func_020145CC(void);
extern int func_021BE92C(int a, int b, int c, int d, int e, int f, int g);
extern void func_020307B0(int a);
extern char ov_id_D9[];
extern char d_021C3FE0[];

int func_02166F9C(void *a, int *st, int *p)
{
    int p0 = p[0];
    int p1 = p[1];
    switch (*st) {
    case 0:
        func_02012374(a, func_021BE8D4(p0, p1, 0, 0));
        *st = 1;
        break;
    case 1:
        func_02012374(a, func_020144DC());
        *st = 2;
        break;
    case 2:
        func_020120B4(p0, ov_id_D9, d_021C3FE0, p[2]);
        *st = 3;
        break;
    case 3:
        func_02012374(a, func_020145CC());
        *st = 4;
        break;
    case 4:
        func_02012374(a, func_021BE92C(p0, p1, 0, 0, 1, 0, 0));
        *st = 5;
        break;
    case 5:
        func_020307B0(p[2]);
        return 1;
    }
    return 0;
}
