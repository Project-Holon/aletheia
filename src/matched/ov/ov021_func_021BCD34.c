/*
 * function: func_021BCD34
 * address:  0x021BCD34
 * packet:   pkt_ov021_021BCD34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD0C0  0x021BD0C0  thumb  ov021
 *   func_021BCEB4  0x021BCEB4  thumb  ov021
 *   func_021BD0D0  0x021BD0D0  thumb  ov021
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 */

typedef unsigned short u16;

typedef struct {
    char pad[0x42];
    u16 h42;
} Obj;

extern int func_021BD0C0(Obj *p);
extern void func_021BCEB4(Obj *p);
extern void func_02040588(int a, int b);
extern void func_021BD0D0(Obj *p);
extern void func_021BCB9C(Obj *p, int b);

void func_021BCD34(Obj *p)
{
    switch (func_021BD0C0(p)) {
    case 0:
        func_021BCEB4(p);
        func_02040588(3, 1);
        func_021BD0D0(p);
        break;
    case 1:
        if (p->h42 > 10) {
            func_021BCB9C(p, 3);
        }
        break;
    }
}
