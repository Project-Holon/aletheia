/*
 * function: func_021F2EEC
 * address:  0x021F2EEC
 * packet:   pkt_ov029_021F2EEC
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021F0194  0x021F0194  thumb  ov029
 *   func_021F2F60  0x021F2F60  thumb  ov029
 */

extern int func_020122C0(int a, int b, void (*c)(void), int d);
extern int *func_020124E8(int a);
extern void func_021F0194(int a);
extern void func_021F2F60(void);

int func_021F2EEC(char *p, int k)
{
    int r = func_020122C0(*(int *)(p + 0x1c), 0, func_021F2F60, 8);
    int *w = func_020124E8(r);

    w[0] = (int)p;
    w[1] = k;
    switch (k) {
    case 1:
    case 5:
    case 6:
        func_021F0194(w[0]);
        break;
    case 11:
        *(unsigned char *)(p + 0x416) = 4;
        break;
    case 7:
        *(unsigned char *)(p + 0x416) = 3;
        break;
    case 12:
        *(unsigned char *)(p + 0x416) = 8;
        break;
    case 13:
        *(unsigned char *)(p + 0x416) = 10;
        break;
    }
    return r;
}
