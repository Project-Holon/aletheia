/*
 * function: func_0689983C
 * address: 0x0689983C
 * packet: pkt_ov095_0689983C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Calls Thumb bx-pc veneers: 06899864/84 -> 021D775C,
 * 06899874 -> 021B9A40, 06899894 -> 021D76BC.
 * symbols:
 *   func_06899864 0x06899864 thumb ov095
 *   func_06899874 0x06899874 thumb ov095
 *   func_06899884 0x06899884 thumb ov095
 *   func_06899894 0x06899894 thumb ov095
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_06899864(int);
extern int func_06899874(u8);
extern int func_06899884(int);
extern int func_06899894(int, u16);
void func_0689983C(int a, int b, int c)
{
    u16 value;
    if (c == func_06899874((u8)func_06899864(3))) {
        value = func_06899884(0x26) * 2;
        func_06899894(0x26, value);
    }
}
