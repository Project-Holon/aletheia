/*
 * function: func_021B71E4
 * address:  0x021B71E4
 * packet:   pkt_ov101_021B71E4
 * region:   ov101
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202824C  0x0202824C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0202822C  0x0202822C  thumb
 *   func_02028230  0x02028230  thumb
 *   func_020282A4  0x020282A4  thumb
 *   func_02028218  0x02028218  thumb
 *   func_02028178  0x02028178  thumb
 */

extern int func_0202824C(int);
extern void func_020061E4(int);
extern void func_0202822C(int, int);
extern int func_02028230(int);
extern void func_020282A4(int);
extern void func_02028218(int, int);
extern void func_02028178(int);

void func_021B71E4(int a)
{
    if (*(int *)(a + 0x5c) != 0) {
        switch (*(int *)(a + 0x50)) {
        case 0:
            *(int *)(a + 0x44) = -1;
            if (func_0202824C(*(int *)(a + 0))) {
                func_020061E4(0x551);
                func_0202822C(*(int *)(a + 0), 1);
                *(int *)(a + 0x50) = 1;
            }
            break;
        case 1:
            if (func_02028230(*(int *)(a + 0))) {
                func_020282A4(*(int *)(a + 0));
                func_02028218(*(int *)(a + 0), 0);
                *(int *)(a + 0x50) = 2;
            }
            break;
        case 2:
            *(int *)(a + 0x44) = 1;
            break;
        }
        func_02028178(*(int *)(a + 0));
    }
}
