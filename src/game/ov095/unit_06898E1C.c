/*
 * file:     unit_06898E1C.c
 * unit:     yes
 * function: func_06898E1C, func_06898E54
 * address:  0x06898E1C
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
 *   d_0689D6F0     0x0689D6F0  data   ov095  a4
 *   d_0689D710     0x0689D710  data   ov095  a4
 *   func_06898EA4  0x06898EA4  thumb  ov095
 *   func_06898EB4  0x06898EB4  thumb  ov095
 *   func_06898EC4  0x06898EC4  thumb  ov095
 *   func_06898ED4  0x06898ED4  thumb  ov095
 *   func_06898EE4  0x06898EE4  thumb  ov095
 *   func_06898EF4  0x06898EF4  thumb  ov095
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_06898EA4(int k);
extern int func_06898EB4(int k);
extern int func_06898EC4(int k);
extern int func_06898ED4(int k);
extern int func_06898EE4(int a);
extern void func_06898EF4(int k, int v);
u8 *func_06898E1C(u32 *p);
void func_06898E28(int a, int b, int c);
u8 *func_06898E38(u32 *p);
void func_06898E44(int a, int b, int c);
void func_06898E54(int a, int b, int c);
extern u8 d_0689D6F0[];
extern u8 d_0689D710[];


/*
 * Handed extent 0x06898E0C (72 bytes) opens with a 16-byte `bx pc` veneer
 * to 0x021D70A8 (ARM linker stub, not compilable); the four functions after
 * it (0x06898E1C..0x06898E54) are this unit. 0x06898E1C and 0x06898E38 are
 * entries of the {key, fn} tables at 0x0689D6F0 / 0x0689D710.
 */
u8 *func_06898E1C(u32 *p)
{
    *p = 1;
    return d_0689D6F0;
}


void func_06898E28(int a, int b, int c)
{
    func_06898E54(b, c, 1);
}


u8 *func_06898E38(u32 *p)
{
    *p = 1;
    return d_0689D710;
}


void func_06898E44(int a, int b, int c)
{
    func_06898E54(b, c, 2);
}


void func_06898E54(int a, int b, int c)
{
    u8 t = func_06898EA4(4);

    if (b == func_06898EB4(t) && c == func_06898EC4(0x1a) && func_06898ED4(0x45) == 0) {
        int r = func_06898EE4(a);

        func_06898EF4(0x35, (r == 0 || r == 3) ? 0x800 : 0xa8f);
    }
}
