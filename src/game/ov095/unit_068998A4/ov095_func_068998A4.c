/*
 * function: func_068998A4
 * address: 0x068998A4
 * packet: pkt_ov095_068998A4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Calls Thumb bx-pc veneers: 068998C4 -> 021D775C,
 * 068998D4 -> 021B9A40, 068998E4 -> 021D76BC.
 * symbols:
 *   func_068998C4 0x068998C4 thumb ov095
 *   func_068998D4 0x068998D4 thumb ov095
 *   func_068998E4 0x068998E4 thumb ov095
 */
typedef unsigned char u8;
extern int func_068998C4(int);
extern int func_068998D4(u8);
extern int func_068998E4(int, unsigned int);
void func_068998A4(int a, int b, int c)
{
    if (c == func_068998D4((u8)func_068998C4(3))) {
        func_068998E4(0x45, 1);
    }
}
