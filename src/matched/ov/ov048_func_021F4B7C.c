/*
 * function: func_021F4B7C
 * address:  0x021F4B7C
 * packet:   pkt_ov048_021F4B7C
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218768C  0x0218768C  thumb  ov020
 *   func_020478B8  0x020478B8  arm
 *   func_021F4BF0  0x021F4BF0  thumb  ov048
 *   func_021F4B54  0x021F4B54  thumb  ov048
 */

extern void func_0218768C(int a);
extern void func_020478B8(int a, int b, int c);
extern void func_021F4BF0(int *a);
extern void func_021F4B54(int *a);

void func_021F4B7C(int *a, int *b, int c)
{
    int t;

    if (b[1] == 1) {
        func_0218768C(b[3]);
        func_020478B8(b[4], *(unsigned short *)&b[5], c);
        t = b[6] + c;
        b[6] = t;
        if (b[7] < t) {
            if (b[2] != 1) {
                ((int *)a[3])[(*(unsigned char *)b + 1) % *((unsigned char *)a + 2)] = 1;
                b[2] = 1;
            }
        }
        if (b[8] < b[6]) {
            func_021F4BF0(b);
            return;
        }
    } else {
        if (((int *)a[3])[*(unsigned char *)b] == 1) {
            func_021F4B54(b);
            ((int *)a[3])[*(unsigned char *)b] = 0;
        }
    }
}
