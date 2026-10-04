/*
 * function: func_021DE6EC
 * address: 0x021DE6EC
 * packet: pkt_ov137_021DE6EC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E1AF8 0x021E1AF8 data a1
 *   func_0207E51C 0x0207E51C arm
 *   func_02049E34 0x02049E34 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern const u8 d_021E1AF8[];
extern void func_0207E51C(void *, int, int);
typedef unsigned int   u32;
struct Sub0204A9D0;
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern void func_020307B0(void *);
void func_021DE6EC(u8 *p, u8 *q, int i, int j)
{
    void *r;
    int n;
    func_0207E51C(*(u8 **)(q + 12) + d_021E1AF8[j] * 32, i * 32, 32);
    r = func_02049E34(32, j + 1, 0, (u32)(&n), 114);
    func_0204A9D0((int)(*(void **)(p + (i + 5) * 4 + 0x6c)), (struct Sub0204A9D0 *)n);
    func_020307B0(r);
}
