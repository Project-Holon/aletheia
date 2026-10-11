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
 *   func_021B9A40  0x021B9A40  thumb
 *   func_021C815C  0x021C815C  thumb
 *   func_021D7704  0x021D7704  thumb
 *   func_021D775C  0x021D775C  thumb
 *   d_0689D6F0     0x0689D6F0  data   ov095  a4
 *   d_0689D710     0x0689D710  data   ov095  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int k);
extern int func_021B9A40(int k);
extern int func_021C815C(int a);
extern void func_021D7704(int k, int v);
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
    u8 t = func_021D775C(4);

    if (b == func_021B9A40(t) && c == func_021D775C(0x1a) && func_021D775C(0x45) == 0) {
        int r = func_021C815C(a);

        func_021D7704(0x35, (r == 0 || r == 3) ? 0x800 : 0xa8f);
    }
}
