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
 *   d_0689D748 0x0689D748 data a4
 *   func_06898F58  0x06898F58  thumb  ov095
 *   func_06898F68  0x06898F68  thumb  ov095
 *   func_06898F78  0x06898F78  thumb  ov095
 *   func_06898F88  0x06898F88  thumb  ov095
 *   func_06898F98  0x06898F98  thumb  ov095
 *   func_06898FA8  0x06898FA8  thumb  ov095
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern int func_06898F58(int k);
extern int func_06898F68(int k);
extern int func_06898F78(int k);
extern int func_06898F88(int k);
extern int func_06898F98(int x);
extern int func_06898FA8(int k, int v);
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
    u8 t = func_06898F58(4);
    int x;

    if (a == func_06898F68(t) && t != func_06898F78(3)) {
        x = func_06898F88(0x1d);
        if (func_06898F98(x) != 0 || x == 6 || x == 0xe)
            *out = func_06898FA8(0x41, 1);
    }
}
