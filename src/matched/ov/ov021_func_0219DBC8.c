/*
 * function: func_0219DBC8
 * address:  0x0219DBC8
 * packet:   pkt_ov021_0219DBC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_02163F40  0x02163F40  thumb  ov010
 *   func_0216DC18  0x0216DC18  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0216DC34(void *a0);
typedef unsigned short u16;
extern int func_02163F40(int a, int dir);
extern int func_0216DC18(void *a0, int a1);
extern u16 func_021AB0F8(u32 attr);

void func_0219DBC8(void *a, u32 b, u32 c, u8 *d)
{
    int r;
    if (d[6] != 0 && func_0216DC34((void *)a) != 0) {
        r = func_02163F40((int)a, 1);
        if (r == -1) {
            func_0216DC18(a, 0);
            return;
        }
        if ((func_021AB0F8(r) & 0x40) == 0) {
            func_0216DC18(a, 0);
        }
    }
}
