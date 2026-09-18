/*
 * function: func_02073A60
 * address:  0x02073A60
 * packet:   pkt_020738C0
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
    union {
        u32 w;
        struct { int b0 : 1; int b1 : 1; int hi : 30; } f;
    } u;
    u8  p30[0x10];
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
};

extern void func_020894B4(u32, u32, u32, u32);
extern void func_0208C808(void *);
extern void func_0208C828(void *);
void func_02073A60(struct A *a) {
    func_020894B4(a->f4c, 0, 1u << a->f48, 0);
    if (a->u.f.b1) return;
    func_0208C808((u8 *)a + 8);
    func_0208C828((u8 *)a + 0x18);
    a->u.w |= 2u;
}
