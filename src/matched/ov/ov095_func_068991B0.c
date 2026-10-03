/*
 * function: func_068991B0
 * address: 0x068991B0
 * packet: pkt_ov095_068991B0
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding at 0x068991D2.
 * symbols:
 *   func_068991D4 0x068991D4 thumb ov095
 *   func_068991E4 0x068991E4 thumb ov095
 *   func_068991F4 0x068991F4 thumb ov095
 */
typedef unsigned char u8;
extern int func_068991D4(int);
extern int func_068991E4(u8);
extern void func_068991F4(int, int);
void func_068991B0(int a0, int a1, int value)
{
    int two;
    two = 2;
    if (value == func_068991E4(func_068991D4(two))) {
        func_068991F4(0x35, two << 12);
    }
}
