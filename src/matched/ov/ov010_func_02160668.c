/*
 * function: func_02160668
 * address:  0x02160668
 * packet:   pkt_ov010_02160668
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C404  0x0200C404  thumb
 *   func_0200C468  0x0200C468  thumb
 *   func_021605C0  0x021605C0  thumb  ov010
 *   func_021C5334  0x021C5334  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_020120F4();
extern int func_02012EBC();
extern int func_0200C404();
extern int func_0200C468();
extern void func_021605C0();
extern int func_021C5334();

int func_02160668(int *a0, int *a1)
{
    int x;

    func_020120F4(a1[1]);
    func_02012EBC();
    x = func_0200C404();
    switch (a1[7]) {
    case 0:
        if (func_0200C468(x) == 0) {
            a1[6] = 1;
            a1[7] = 2;
        } else if ((u32)(a0[9] - 1) <= 2) {
            a1[7] = 2;
        } else {
            func_021605C0(1, a1);
            a1[7] = 1;
        }
        break;
    case 1:
        if (func_021C5334(a1[3]) != 0) {
            a1[7] = 2;
        }
        break;
    case 2:
        a1[7] = 0;
        return 1;
    }
    return 0;
}
