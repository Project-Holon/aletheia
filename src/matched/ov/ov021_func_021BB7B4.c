/*
 * function: func_021BB7B4
 * address:  0x021BB7B4
 * packet:   pkt_ov021_021BB7B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   func_0207B51C  0x0207B51C  arm
 */

void func_02048AE8(int a, int *out);
void func_02048B0C(int a, int *out);
void func_02048B30(int a, int *out);
void func_0207BCA0(int *a, int *b, int *c, int *d);
void func_02082B60(int *a, int *b);
void func_0207B0A4(int *a, int *b);
void func_0207B51C(int a, int *b, int c);

void func_021BB7B4(int a, int b, int c)
{
    int v6c[3];
    int v60[3];
    int v54[3];
    int m24[12];
    int m0[9];

    func_02048AE8(a, v6c);
    func_02048B0C(a, v60);
    func_02048B30(a, v54);
    func_0207BCA0(v6c, v60, v54, m24);
    func_02082B60(m24, m0);
    func_0207B0A4(m0, m0);
    func_0207B51C(b, m0, c);
}
