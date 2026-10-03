/*
 * function: func_021BD9F4
 * address: 0x021BD9F4
 * packet: pkt_ov099_021BD9F4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0203D378 0x0203D378 arm
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
typedef unsigned int u32;
extern void func_021C18C8(char *p, int kind, int value);
extern void func_0203D7B0(int);
extern int func_0203D7BC(int);
extern int func_0203D378(int);
extern void func_021BAAB8(char *, int, int);
int func_021BD9F4(char *p, int v)
{
    int zero;
    func_021C18C8(p, 1, 2);
    zero = 0;
    *(int *)(p + 0x135c) = zero;
    func_0203D7B0(0);
    if (func_0203D378(func_0203D7BC(0)) != 0) {
        func_021BAAB8(p, 0x73, zero);
    } else {
        func_021BAAB8(p, 0x7c, zero);
    }
    *(int *)(p + 0x1cc) = 0x8e;
    return v;
}
