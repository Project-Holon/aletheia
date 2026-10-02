/*
 * function: func_0216B81C
 * address:  0x0216B81C
 * packet:   pkt_ov010_0216B81C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200C32C  0x0200C32C  thumb
 *   func_0216B8B8  0x0216B8B8  thumb  ov010
 *   func_0216B91C  0x0216B91C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5E4(int a0);
extern int func_02012EBC(int p);
extern int func_0200C0E8(int sys);
extern int func_02159B10();
extern int func_02159AE8();
extern int func_0200C32C();
extern void func_0216B8B8();
extern void func_0216B91C();

int func_0216B81C(int c, int vm)
{
    int r6;
    int t;
    int r5;
    int r4;

    r6 = func_02012EBC(func_0215A5E4(vm));
    t = func_0200C0E8(r6);
    r5 = (u8)func_02159B10(c, vm);
    r4 = func_02159AE8(c, vm);
    if (r5 == func_0200C32C(t)) {
        func_0216B8B8(r6, r4);
    } else {
        func_0216B91C(r6, r5, r4);
    }
    return 0;
}
