/*
 * function: func_021D2278
 * address:  0x021D2278
 * packet:   pkt_ov021_021D2278
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C7858  0x021C7858  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02006148  0x02006148  thumb
 *   func_02006224  0x02006224  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A30A4  0x021A30A4  thumb  ov021
 *   func_021CD440  0x021CD440  thumb  ov021
 *   func_02184FD4  0x02184FD4  thumb  ov020
 *   func_02012374  0x02012374  thumb
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct { int x, y, z; } Vec;

extern u32 func_02188D38(u32 a);
extern int func_021C7858(int, int, Vec *);
extern void func_021C6DE0(u32 a, u32 b, u32 c);
extern void func_020061E4(u32 a);
extern void func_02006148(u32);
extern int func_02006224(void);
extern u32 func_02188CB4(u32 a);
extern u32 func_021A3074(u32 a);
extern void func_021A30A4(u32 a, u32 b);
extern int func_021CD440(u32 field, u16 *out);
extern u32 func_02184FD4(u32 a, u16 b);
extern void func_02012374(u32 a, u32 b);
extern void func_0216D410(u32 o, u32 v);
extern int func_0216D454(u32 o);

int func_021D2278(u32 a, int *seq, int *w)
{
    Vec v;
    u16 id;
    u32 s, o;

    switch (*seq) {
    case 0:
        s = func_02188D38(w[1]);
        v.x = 0;
        v.y = -0x40000;
        v.z = 0;
        func_021C6DE0(s, func_021C7858(w[1], 0x28, &v), 0);
        w[3] = 8;
        (*seq)++;
        break;
    case 1:
        w[3]--;
        if (w[3] > 0) {
            break;
        }
        func_020061E4(0x63C);
        (*seq)++;
        break;
    case 2:
        func_02006148(0x63C);
        if (func_02006224() != 0) {
            break;
        }
        o = func_02188CB4(w[1]);
        func_021A3074(o);
        func_021A30A4(o, 3);
        func_021CD440(w[1], &id);
        func_02012374(a, func_02184FD4(w[0], id));
        (*seq)++;
        break;
    case 3:
        func_0216D410(func_021A3074(func_02188CB4(w[1])), 8);
        (*seq)++;
        break;
    case 4:
        if (func_0216D454(func_021A3074(func_02188CB4(w[1])))) {
            return 1;
        }
        break;
    }
    return 0;
}
