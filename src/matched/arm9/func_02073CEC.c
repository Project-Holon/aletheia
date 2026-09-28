/*
 * function: func_02073CEC
 * address:  0x02073CEC
 * packet:   pkt_02073BF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


struct A {
    u8  p00[0x2c];
    int b0 : 1;
    int b1 : 1;
    int hi : 30;
    u8  p30[0x10];
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
};

extern void func_02073BF0(struct A *, u32);
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern void func_020894B4(u32, u32, u32, u32);
void func_02073CEC(struct A *a) {
    u32 r;
    if (!a->b1) return;
    while (a->f40 != 0) {
        r = func_02087988();
        func_02073BF0(a, 1);
        func_0208799C(r);
    }
    func_020894B4(a->f4c, 0, 1u << a->f48, 0);
}
