/*
 * function: func_0219B074
 * address:  0x0219B074
 * packet:   pkt_ov021_0219B074
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D7C4  0x0216D7C4  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned char  u8;
extern void *func_0216D67C(void *a0);
extern void *func_0216DEE0(void *a0);
extern u16 func_0216D7C4(u8 *p);

int func_0219B074(int a)
{
    int t;

    t = (int)func_0216DEE0(func_0216D67C((void *)a));
    if (t != 0) {
        switch (func_0216D7C4((u8 *)t)) {
        case 0x58:
        case 0x59:
        case 0x5a:
        case 0x5b:
        case 0xa3:
        case 0xa4:
        case 0xa5:
        case 0xa6:
            return 1;
        }
    }
    return 0;
}
