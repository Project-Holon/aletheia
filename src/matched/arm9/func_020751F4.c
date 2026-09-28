/*
 * function: func_020751F4
 * address:  0x020751F4
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern u32 func_020742E4(u32);
extern u32 func_0207466C(u32);
extern void func_02074694(u32, u32);
void func_020751F4(u32 a, u32 b, u32 c) {
    u32 t, s;
    if (b == 0) return;
    s = func_02087988();
    t = func_020742E4(b);
    if (func_0207466C(c) == a) func_02074694(c, 0);
    func_020742E4(t);
    func_0208799C(s);
}
