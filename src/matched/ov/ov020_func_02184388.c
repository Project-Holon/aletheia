/*
 * function: func_02184388
 * address:  0x02184388
 * packet:   pkt_ov020_02184388
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218403C  0x0218403C  thumb  ov020
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0218409C  0x0218409C  thumb  ov020
 *   func_021BD648  0x021BD648  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02184360  0x02184360  thumb  ov020
 *   func_02184120  0x02184120  thumb  ov020
 *   func_021BD9BC  0x021BD9BC  thumb  ov021
 */

typedef unsigned char u8;

extern void func_0218403C(u8 *p);
extern void func_02188C7C(int a);
extern void func_0216D9A0(void);
extern void func_0218409C(u8 *p, int a);
extern int func_021BD648(u8 *p);
extern void func_02012374(int a, int b);
extern int func_02184360(u8 *p, int a);
extern void func_02184120(u8 *p, int a);
extern int func_021BD9BC(u8 *p);

int func_02184388(int a, int *state, u8 *p)
{
    int w = *(int *)(p + 8);

    switch (*state) {
    case 0:
        func_0218403C(p);
        func_02188C7C(w);
        func_0216D9A0();
        func_0218409C(p, a);
        func_02012374(a, func_021BD648(p + 0x4c));
        (*state)++;
        return 0x21;
    case 1:
        func_02012374(a, func_02184360(p, 0));
        (*state)++;
        break;
    case 2:
        func_02184120(p, a);
        func_02012374(a, func_021BD9BC(p + 0x4c));
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
