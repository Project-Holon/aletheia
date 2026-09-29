/*
 * function: func_021BA01C
 * address:  0x021BA01C
 * packet:   pkt_ov071_021BA01C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9FEC  0x021B9FEC  thumb  ov071
 *   func_021B6C30  0x021B6C30  thumb  ov071
 *   func_021B6C48  0x021B6C48  thumb  ov071
 *   func_021B6BEC  0x021B6BEC  thumb  ov071
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char u8;

extern void func_021B9FEC(void *p, int a);
extern void func_021B6C30(void *p, int a, int b);
extern void func_021B6C48(void *p, int a);
extern void func_021B6BEC(void *p, int *tbl, int n, int sel, int c);
extern void func_02041B6C(int a);

void func_021BA01C(void *a, u8 *p)
{
    int v;
    int m;

    if (*(int *)(p + 0x304) == 1) {
        func_021B9FEC(p, *(int *)(p + 0x2f4));
        v = *(int *)(p + 0x2f4);
        if (v == 0xffff) {
            func_021B6C30(a, 0, 1);
        } else {
            m = *(int *)(p + 0x308);
            if ((m == 2 && v == *(int *)(p + 0x2fc)) || (m == 1 && v == *(int *)(p + 0x2f8))) {
                if (*(int *)(p + 0x1b4 + v * 4) == 0) {
                    *(int *)(p + 0x300) = v;
                    if (*(int *)(p + 0x308) == 1) {
                        func_021B6C48(a, 1);
                    } else {
                        func_021B6BEC(a, (int *)(p + 8), 1, 0, 3);
                    }
                } else if (m == 2) {
                    func_021B6C30(a, 1, 1);
                }
            } else {
                func_021B6C30(a, 1, 1);
            }
        }
        func_02041B6C(6);
        *(int *)(p + 0x304) = 0;
    }
}
