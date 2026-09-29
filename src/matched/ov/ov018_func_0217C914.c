/*
 * function: func_0217C914
 * address:  0x0217C914
 * packet:   pkt_ov018_0217C914
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217F3C4  0x0217F3C4  thumb  ov018
 *   func_02173A2C  0x02173A2C  thumb  ov011
 *   func_02175514  0x02175514  thumb  ov011
 *   func_0217F40C  0x0217F40C  thumb  ov018
 *   func_020362DC  0x020362DC  arm
 *   func_02173B9C  0x02173B9C  thumb  ov011
 *   func_021753B8  0x021753B8  thumb  ov011
 *   func_0217F420  0x0217F420  thumb  ov018
 *   func_02173AE0  0x02173AE0  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0217F3C4(u8 *, int);
extern int func_02173A2C(u8 *, u8, u8 *, u8);
extern int func_02175514(u8 *);
extern int func_0217F40C(u8 *);
extern u32 func_020362DC(void);
extern int func_02173B9C(u8, u8);
extern void func_021753B8(u8 *);
extern int func_0217F420(u8 *);
extern int func_02173AE0(u8 *, u8, int, u8);

int func_0217C914(u8 *v, u8 *w, u8 *state)
{
    switch (*state) {
    case 0:
        func_0217F3C4(w + 0x10, 0);
        (*state)++;
        break;
    case 1:
        if (func_02173A2C(v, v[0x154], w + 0x44, w[0x41]) == 1)
            (*state)++;
        break;
    case 2:
        switch (func_02175514(v)) {
        case 1:
            *state = 6;
            break;
        case 2:
        case 3:
            *state = 3;
            break;
        default:
            if (func_0217F40C(w + 0x10) == 1) {
                if ((func_020362DC() & 2) && func_02173B9C(v[0x154], v[0x158]) == 1) {
                    func_021753B8(v);
                    *state = 9;
                }
            }
            break;
        }
        break;
    case 3:
        if (func_0217F40C(w + 0x10) == 1) {
            func_0217F3C4(w + 0x10, 2);
            (*state)++;
        }
        break;
    case 4:
        if (func_0217F40C(w + 0x10) == 1)
            (*state)++;
        break;
    case 5:
        if (func_0217F420(v) == 1)
            *state = 8;
        break;
    case 6:
        if (func_02173AE0(v, v[0x154], 1, v[0x158]) == 1)
            *state = 7;
        break;
    case 7:
        if (func_0217F40C(w + 0x10) == 1)
            return 1;
        break;
    case 8:
        return 2;
    case 9:
        return 3;
    }
    return 0;
}
