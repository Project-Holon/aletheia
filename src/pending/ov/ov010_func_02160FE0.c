/*
 * function: func_02160FE0
 * address:  0x02160FE0
 * packet:   pkt_ov010_02160FE0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02160FB4  0x02160FB4  thumb  ov010
 *   func_0202E474  0x0202E474  thumb
 *   func_02008298  0x02008298  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_020120F4();
extern int func_02160FB4();
extern int *func_0202E474();
extern void func_02008298();

int *func_02160FE0(u8 *a0, int a1, int a2, int *a3)
{
    int h = func_020120F4(**(int **)(a0 + 0x18));
    int *r;
    int n;
    int c;

    switch (a2) {
    case 2:
        n = 4;
        r = func_0202E474(h, a0 + 0x34, func_02160FB4(**(int **)(a0 + 0x18)), n);
        if (a1 != n - 5) {
            func_02008298(r[3], (u16)a1);
        }
        break;
    case 0:
        if (a3[16] == 3) {
            c = 2;
            goto call;
        }
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    default:
        c = func_02160FB4(**(int **)(a0 + 0x18));
    call:
        r = func_0202E474(h, a0 + 0x34, c, 4);
        break;
    }
    return r;
}
