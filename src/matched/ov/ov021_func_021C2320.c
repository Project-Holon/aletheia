/*
 * function: func_021C2320
 * address:  0x021C2320
 * packet:   pkt_ov021_021C2320
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021C1A48  0x021C1A48  thumb  ov021
 *   func_021C24F0  0x021C24F0  thumb  ov021
 *   func_021C1C24  0x021C1C24  thumb  ov021
 *   func_021C1A98  0x021C1A98  thumb  ov021
 *   func_021C1AA8  0x021C1AA8  thumb  ov021
 *   func_020489F4  0x020489F4  arm
 *   func_02048A00  0x02048A00  arm
 *   func_02048A18  0x02048A18  arm
 *   func_0204779C  0x0204779C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02051B04  0x02051B04  arm
 *   func_020124E4  0x020124E4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02012374  0x02012374  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

int func_021C1A48(int a);
void func_021C24F0(char *q, int d, u16 e);
void func_021C1C24(char *p, char *q);
int func_021C1A98(int a, int b, int c);
void func_021C1AA8(int a, int b, int c, int d);
int func_020489F4(int a, u16 b);
int func_02048A00(int a, u16 b);
int func_02048A18(int a, u16 b);
int func_0204779C(int a);
void func_020477A4(int a, u8 b);
int func_02051B04(int a);
int func_020124E4(int a);
int func_020122C0(int a, int b, int c, int d);
void func_02012374(int a, int b);

void func_021C2320(int a, char *p, char *q, int d)
{
    int t;
    u8 i;
    int base;
    int cnt;
    u8 k;
    int h;
    int n;
    int r;

    *(int *)(p + 0x58) = func_021C1A48(*(int *)p);
    func_021C24F0(q, d, *(u16 *)(p + 0x10));
    func_021C1C24(p, q + 0x10);
    if (*(int *)(q + 0x28) != 0xFFFF) {
        t = func_021C1A98(*(int *)p, 0x73, *(int *)(q + 0x28));
        func_021C1AA8(*(int *)p, t, 1, 0);
    } else {
        t = 0;
    }
    base = func_020489F4(*(int *)(p + 0x14), *(int *)(p + 0x18));
    cnt = func_02048A00(*(int *)(p + 0x14), *(int *)(p + 0x18));
    for (i = 0; i < cnt; i++) {
        h = func_02048A18(*(int *)(p + 0x14), base + i);
        n = func_0204779C(h);
        for (k = 0; k < n; k++)
            func_020477A4(h, k);
    }
    *(u16 *)(p + 0x5c) = *(u16 *)(q + 0x20);
    *(u16 *)(p + 0x5e) = *(u16 *)(q + 0x22);
    *(u16 *)(p + 0x60) = *(u16 *)(q + 0x24);
    *(u16 *)(p + 0x62) = *(u16 *)(q + 0x26);
    if (t != 0)
        r = func_02051B04(t);
    else
        r = 0;
    if (r == 2) {
        *(int *)(p + 0x78) = 0;
        *(int *)(p + 0x7c) = 0;
    } else if (r == 1) {
        *(int *)(p + 0x78) = 0;
        *(int *)(p + 0x7c) = 1;
    } else {
        *(int *)(p + 0x78) = 1;
        *(int *)(p + 0x7c) = 1;
    }
    *(int *)(p + 0x80) = 0;
    *(int *)(p + 0x84) = 0;
    if (*(u8 *)(q + 0x2e) != 0)
        *(int *)(p + 0x80) = 1;
    if (*(u8 *)(q + 0x2f) != 0)
        *(int *)(p + 0x84) = 1;
    if (*(int *)(p + 0x128) != 0) {
        h = func_020124E4(a);
        func_02012374(a, func_020122C0(h, a, *(int *)(p + 0x128), 0));
    }
}
