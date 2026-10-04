/*
 * function: func_0216D28C
 * address:  0x0216D28C
 * packet:   pkt_0216D28C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The mask test picks between the overlay's own handler and the arm9
 * field setter.
 *
 * symbols:
 *   func_0216D55C   0x0216D55C  thumb  ov010
 *   func_02163028   0x02163028  thumb  ov010
 *   func_0219D6CC   0x0219D6CC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D55C(int a0, int a1);
extern void func_02163028(int a);
extern void func_0219D6CC(void *);

void func_0216D28C(void *a0)
{
    if (func_0216D55C((int)a0, 0x2000) == 0) {
        func_02163028((int)a0);
    } else {
        func_0219D6CC(a0);
    }
}
