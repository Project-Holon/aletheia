/*
 * file:     unit_0689C540.c
 * function: func_0689C540
 * address:  0x0689C540
 * packet:   pkt_ov095_0689C540
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0689C5CC   0x0689C5CC  thumb  ov095
 *   func_0689C5DC   0x0689C5DC  thumb  ov095
 *   func_0689C5EC   0x0689C5EC  thumb  ov095
 *   func_0689C5FC   0x0689C5FC  thumb  ov095
 *   func_0689C60C   0x0689C60C  thumb  ov095
 *   func_0689C61C   0x0689C61C  thumb  ov095
 *   func_0689C62C   0x0689C62C  thumb  ov095
 *   func_0689C63C   0x0689C63C  thumb  ov095
 *   func_0689C64C   0x0689C64C  thumb  ov095
 *   func_0689C65C   0x0689C65C  thumb  ov095
 *   func_0689C66C   0x0689C66C  thumb  ov095
 *   func_0689C67C   0x0689C67C  thumb  ov095
 */

typedef unsigned char u8;

extern int func_0689C5CC(void *, int);
typedef struct Word { int v; } Word;
extern Word func_0689C5DC(void *, int);
extern int func_0689C5EC(void);
extern int func_0689C5FC(int);
extern int func_0689C60C(int);
extern void func_0689C61C(int, int);
extern int func_0689C62C(void *, int);
extern int func_0689C63C(int);
extern void func_0689C64C(int, int);
extern int func_0689C65C(void *, int);
extern int func_0689C66C(int);
extern void func_0689C67C(int, int);

void func_0689C540(void *a, void *b)
{
    int k;
    int v;
    u8 x;

    k = 0x11;
    if (func_0689C5CC(b, k) != 0) {
        v = func_0689C5DC(b, k).v;
        x = func_0689C5EC();
        if (x == (u8)func_0689C5FC(0x15)) {
            func_0689C61C(func_0689C60C(v) == 0 ? 0x4b : 0x4c, 1);
        }
    }
    if (func_0689C62C(b, 0x15) != 0) {
        if (func_0689C63C(0x16) == 4)
            func_0689C64C(0x4b, 1);
    }
    if (func_0689C65C(b, 0x1f) != 0) {
        if (func_0689C66C(0x16) == 4)
            func_0689C67C(0x4b, 1);
    }
}
