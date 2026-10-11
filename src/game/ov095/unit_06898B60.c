/*
 * file:     unit_06898B60.c
 * unit:     yes
 * function: func_06898B60, func_06898B6C
 * address:  0x06898B60
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
 *   func_021C8020  0x021C8020  thumb
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   func_021D7040  0x021D7040  thumb
 *   func_021D775C  0x021D775C  thumb
 *   d_0689D690 0x0689D690 data a4
 */
typedef unsigned int u32;

typedef unsigned char u8;

extern int func_021D775C(int k);
extern int func_021C8020(int b, int c);
extern u8 *func_021C88A4(int b, int k, int n);
extern void func_021C88C8(int b, void *p);
extern void func_021D7040(int a);
const u32 *func_06898B60(u32 *p);
void func_06898B6C(int a, int b, int c, u32 *d);
extern const u32 d_0689D690;

/*
 * note: Unlabelled follower after the non-C veneer at 0x06898B50.
 */
const u32 *func_06898B60(u32 *p)
{
    *p = 1;
    return &d_0689D690;
}

/*
 * The returned message pointer stays live in r1 for 06898BDC, whose veneer
 * reaches the two-argument func_021C88C8. A one-argument declaration loses
 * the pointer copy and leaves 18 differing bytes (62/64).
 */
void func_06898B6C(int a, int b, int c, u32 *d)
{
    u8 t = func_021D775C(2);
    u8 *p;
    if (t == func_021C8020(b, c)) {
        p = func_021C88A4(b, 0x2a, 0x1f);
        p[4] = *d;
        p[5] = t;
        func_021C88C8(b, p);
        func_021D7040(a);
    }
}
