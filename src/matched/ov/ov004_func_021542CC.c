/*
 * function: func_021542CC
 * address:  0x021542CC
 * packet:   pkt_ov004_021542CC
 * region:   ov004
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200AD6C  0x0200AD6C  thumb
 *   func_02008B08  0x02008B08  thumb
 *   func_0201AD0C  0x0201AD0C  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02008730  0x02008730  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_02009CC0  0x02009CC0  thumb
 *   func_02154390  0x02154390  thumb  ov004
 */

int func_020120F4(int p);
int func_020122C0(int p, int a, void (*cb)(void), int n);
int func_02012138(int p);
int func_02026454(int x);
void func_02026400(int x);
int *func_020124E8(int p);
void func_02082BCC(void *p, int v, int n);
int func_02012EBC(int p);
int func_0200AD6C(int p);
int func_02008B08(int p);
int func_0201AD0C(int p);
int func_0201293C(int p);
int func_0200CA1C(int p);
int func_0201283C(int p);
int func_02009470(int p);
int func_02008730(int p);
int func_0200873C(int p);
int func_02008C58(int p);
void *func_0201292C(int p);
int func_0200CA38(int p);
int func_02009CC0(int p);
void func_02154390(void);

int func_021542CC(int a, int b)
{
    int r6;
    int h;
    int *p;

    r6 = func_020120F4(a);
    h = func_020122C0(a, 0, func_02154390, 0x54);
    if (func_02026454(func_02012138(a)))
        func_02026400(func_02012138(a));
    p = func_020124E8(h);
    func_02082BCC(p, 0, 0x54);
    p[1] = a;
    p[2] = b;
    p[18] = func_02012EBC(r6);
    p[3] = func_0200AD6C(p[18]);
    p[4] = func_02008B08(p[18]);
    p[5] = func_0201AD0C(p[18]);
    p[6] = func_0201293C(r6);
    p[7] = func_0200CA1C(r6);
    p[8] = func_0201283C(r6);
    p[9] = func_02009470(p[18]);
    p[10] = func_02008730(p[18]);
    p[11] = func_0200873C(p[18]);
    p[12] = func_02008C58(p[18]);
    *(void **)&p[13] = func_0201292C(r6);
    p[19] = a;
    p[14] = func_0200CA38(p[7]);
    p[15] = func_02009CC0(p[8]);
    p[16] = 0;
    p[17] = 0;
    return h;
}
