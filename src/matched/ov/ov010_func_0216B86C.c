/*
 * function: func_0216B86C
 * address:  0x0216B86C
 * packet:   pkt_ov010_0216B86C
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
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200C32C  0x0200C32C  thumb
 *   func_0216BB70  0x0216BB70  thumb  ov010
 *   func_0216BAE8  0x0216BAE8  thumb  ov010
 *   func_0216BA88  0x0216BA88  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5E4();
extern int func_02012EBC();
extern int func_0200C0E8();
extern int func_02159AE8();
extern int func_0200C32C();
extern int func_0216BB70();
extern int func_0216BAE8();
extern int func_0216BA88();

int func_0216B86C(int c, int vm)
{
    u16 *dst;
    int r6;
    int r7;
    int r5;
    u8 k;

    func_0215A5E4(vm);
    r6 = func_02012EBC();
    r7 = func_0200C0E8();
    dst = (u16 *)func_02159AE8(c, vm);
    k = func_0216BB70(func_0200C32C(r7));
    if (k != 0) {
        if (k == 1) {
            r5 = func_0216BAE8(r6);
        }
    } else {
        r5 = func_0216BA88(r6);
    }
    *dst = r5;
    return 0;
}
