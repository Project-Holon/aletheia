/*
 * function: func_0218908C
 * address: 0x0218908C
 * packet: pkt_ov096_0218908C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * return: func_0218A378's r0 is consumed by original caller, overriding its void forwarder declaration.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0218A378 0x0218A378 thumb ov096
 *   func_0218A0F4 0x0218A0F4 thumb ov096
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern u32 func_0201134C(struct Cursor *);
extern int func_0218A378(int, int, int);
extern int func_0218A0F4(u8 *, int, int, int, int);
void func_0218908C(u8 *a, int b, int c)
{
    int t0, t1;
    t0 = func_0201134C((struct Cursor *)a);
    t1 = func_0201134C((struct Cursor *)a);
    func_0218A0F4(a, c, func_0218A378(b, *(u16 *)(b + 2), 28), t0, t1);
}
