/*
 * function: func_021D4310
 * address: 0x021D4310
 * packet: pkt_ov115_021D4310
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4240 0x021D4240 thumb ov115
 *   func_021D5F7C 0x021D5F7C thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D4644 0x021D4644 thumb ov115
 *   func_021D4BB4 0x021D4BB4 thumb ov115
 *   func_021D4AB0 0x021D4AB0 thumb ov115
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D4240(u8 *);
extern void func_021D5F7C(int);
extern void func_021D5CCC(int, int);
extern void func_021D426C(u8 *, u32);
extern int func_021D4644(u8 *);
extern void func_021D4BB4(u8 *p);
extern void func_021D4AB0(int a);
void func_021D4310(u8 *p)
{
    if (func_021D4240(p)) {
        func_021D5F7C(*(int *)(p + 0x38));
        if (*(int *)(*(u8 **)(p + 0x40) + 4) == 0)
            func_021D5CCC(*(int *)(p + 0x38), 0x23);
        if (*(int *)(*(u8 **)(p + 0x40) + 0x10) != 0)
            func_021D426C(p, (u32)func_021D4BB4);
        else
            func_021D426C(p, (u32)func_021D4AB0);
    } else {
        func_021D4644(p);
    }
}
