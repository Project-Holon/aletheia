/*
 * file:     unit_06898F04.c
 * unit:     yes
 * function: func_06898F04, func_06898F10
 * address:  0x06898F04
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
 *   func_021D7D6C  0x021D7D6C  thumb
 *   d_0689D748 0x0689D748 data a4
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern int func_021D775C(int k);
extern int func_021B9A40(int k);
extern int func_021D7D6C(int x);
extern int func_021D76BC(int k, int v);
u32 *func_06898F04(u32 *p);
void func_06898F10(int p0, int p1, int a, int *out);
extern u32 d_0689D748;

/*
 * note: Unlabelled follower after the 0x06898EF4 interworking veneer.
 */
u32 *func_06898F04(u32 *p)
{
    *p = 2;
    return &d_0689D748;
}


void func_06898F10(int p0, int p1, int a, int *out)
{
    u8 t = func_021D775C(4);
    int x;

    if (a == func_021B9A40(t) && t != func_021D775C(3)) {
        x = func_021D775C(0x1d);
        if (func_021D7D6C(x) != 0 || x == 6 || x == 0xe)
            *out = func_021D76BC(0x41, 1);
    }
}
