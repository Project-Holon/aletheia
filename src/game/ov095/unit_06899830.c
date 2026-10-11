/*
 * file:     unit_06899830.c
 * unit:     yes
 * function: func_06899830, func_0689983C
 * address:  0x06899830
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9A40  0x021B9A40  thumb
 *   func_021D76BC  0x021D76BC  thumb
 *   func_021D775C  0x021D775C  thumb
 *   d_0689D768 0x0689D768 data ov095 a4
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern int func_021D775C(int);
extern int func_021B9A40(u8);
extern int func_021D76BC(int, u16);
unsigned char *func_06899830(u32 *p);
void func_0689983C(int a, int b, int c);
extern unsigned char d_0689D768[];

/*
 * Follower after the 06899820 linker veneer; ends at 0689983C.
 */
unsigned char *func_06899830(u32 *p)
{
    *p = 3;
    return d_0689D768;
}

/*
 * Calls Thumb bx-pc veneers: 06899864/84 -> 021D775C,
 * 06899874 -> 021B9A40, 06899894 -> 021D76BC.
 */
void func_0689983C(int a, int b, int c)
{
    u16 value;
    if (c == func_021B9A40((u8)func_021D775C(3))) {
        value = func_021D775C(0x26) * 2;
        func_021D76BC(0x26, value);
    }
}
