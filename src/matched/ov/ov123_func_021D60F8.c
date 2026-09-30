/*
 * function: func_021D60F8
 * address: 0x021D60F8
 * packet: pkt_ov123_021D60F8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A648 0x0204A648 arm
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 */
typedef unsigned char u8;
extern void func_0204A648(void);
extern void func_0207E3D0(void *, unsigned int, unsigned int);
extern void func_0207E468(void *, unsigned int, unsigned int);
void func_021D60F8(void *a, u8 *p)
{
    int n;
    u8 *base;
    int off;
    func_0204A648();
    n = *(int *)(p + 0x4564) + 1;
    *(int *)(p + 0x4564) = n;
    if (n % 10 == 1) {
        base = *(u8 **)(*(u8 **)(p + 0x18) + 0xc);
        off = (n / 10 + 2) * 32;
        func_0207E3D0(base + off, 64, 32);
        func_0207E468(base + off, 64, 32);
    }
    if (*(int *)(p + 0x4564) >= 80) *(int *)(p + 0x4564) = 0;
}
