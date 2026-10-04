/*
 * function: func_0219BA2C
 * address:  0x0219BA2C
 * packet:   pkt_ov021_0219BA2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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

int func_0219BA2C(int a)
{
    int v;

    func_0216DEE0(func_0216D67C((void *)a));
    v = func_0216D7C4((u8 *)a);
    switch (v) {
    case 0x58:
        return 0x10;
    case 0x59:
        return 0x11;
    case 0x5a:
        return 0x12;
    case 0x5b:
        return 0x13;
    }
    return v;
}
