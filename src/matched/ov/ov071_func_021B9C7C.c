/*
 * function: func_021B9C7C
 * address:  0x021B9C7C
 * packet:   pkt_ov071_021B9C7C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * `touch = 0` in the key branch is what keeps r7 as the zero stored to
 * f2e0/f2dc and passed to func_020355D8; `p->f2e4 = ret` (not 0) reloads
 * the spilled result as in the image.
 *
 * symbols:
 *   func_02035CB8  0x02035CB8  arm
 *   func_0203630C  0x0203630C  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02035C60  0x02035C60  arm
 *   func_021B9F2C  0x021B9F2C  thumb  ov071
 *   func_021BA1DC  0x021BA1DC  thumb  ov071
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad000[0x1b4];
    int f1b4[(0x27c - 0x1b4) / 4];
    u8 f27c;
    u8 pad27d[0x2d8 - 0x27d];
    int f2d8;
    int f2dc;
    int f2e0;
    int f2e4;
    int f2e8;
    int f2ec;
    int f2f0;
    int f2f4;
} S;

extern int func_02035CB8(u32 *a, u32 *b);
extern u32 func_0203630C(void);
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern void func_020355D8(int v);
extern void func_020061E4(u32 se);
extern int func_02035C60(void);
extern int func_021B9F2C(S *p, int i, int v);
extern int func_021BA1DC(S *p, int y);

int func_021B9C7C(void *a, S *p)
{
    int ret;
    int sel;
    u32 x;
    u32 y;
    int touch;
    int t;
    int row;
    int rem;
    int d;
    int r;

    ret = 0;
    sel = 0xffff;
    p->f2e4 = ret;
    touch = func_02035CB8(&x, &y);
    if (p->f2dc == 0) {
        if (x < 0x18 || x > 0xe0) {
            touch = 0;
        }
    }
    if (func_0203630C() & 0xc3) {
        t = (p->f2d8 >> 8) + 0x18;
        row = t / 32;
        rem = t % 32;
        touch = 0;
        p->f2e0 = touch;
        p->f2dc = touch;
        if (p->f2f4 == 0xffff) {
            if (rem != 0) {
                row++;
            }
            if (row < 1) {
                row = 1;
            }
            if (row >= p->f27c - 2) {
                func_021B9F2C(p, p->f27c - 2, 1);
            } else {
                func_021B9F2C(p, row, 1);
            }
            func_020061E4(0x548);
            return 0;
        }
        if (func_020362DC() & 1) {
            func_021B9F2C(p, p->f2f4, 1);
            func_020355D8(0);
            if (p->f1b4[p->f2f4] == 0) {
                func_020061E4(0x54c);
            }
            return 1;
        }
        if (func_0203633C() & 0x40) {
            if (rem != 0) {
                row++;
            }
            if (func_021B9F2C(p, p->f2f4 - 1, 1) == 1) {
                func_020061E4(0x548);
            }
            if (p->f2f4 < row) {
                p->f2e4 = -0x2000;
            }
            return 0;
        }
        if (func_0203633C() & 0x80) {
            row = ((p->f2d8 >> 8) + 0xa8) / 32;
            if (func_021B9F2C(p, p->f2f4 + 1, 1) == 1) {
                func_020061E4(0x548);
            }
            if (p->f2f4 >= row) {
                p->f2e4 = 0x2000;
            }
            return 0;
        }
    }
    if (p->f2dc == 0) {
        if (touch == 1) {
            if (y > 0x18 && y < 0xa8) {
                p->f2dc = 1;
                p->f2e8 = y;
                p->f2ec = y;
                func_021B9F2C(p, 0xffff, 0);
            } else if (func_02035C60() == 1 && p->f2f4 != 0xffff
                       && x >= 0x10 && x <= 0x70 && y >= 0xac && y <= 0xbc) {
                ret = 1;
                sel = p->f2f4;
                func_020355D8(1);
            }
        } else if (p->f2e0 != 0) {
            if (p->f2e0 > 0) {
                p->f2e0 -= 0xc0;
                if (p->f2e0 < 0) {
                    p->f2e0 = 0;
                }
            } else {
                p->f2e0 += 0xc0;
                if (p->f2e0 > 0) {
                    p->f2e0 = 0;
                }
            }
        }
    } else if (touch == 0) {
        p->f2dc = 0;
        if (p->f2ec != 0xffff) {
            d = p->f2e8 - p->f2ec;
            if (d < 0) {
                d = -d;
            }
            if (d < 4) {
                r = func_021BA1DC(p, p->f2e8);
                if (r != 0xffff) {
                    ret = 1;
                    sel = r;
                    func_020061E4(0x548);
                }
            }
        }
    } else {
        p->f2e0 = (p->f2e8 - y) << 8;
        p->f2e8 = y;
        p->f2dc++;
        if (p->f2ec != 0xffff) {
            d = y - p->f2ec;
            if (d < 0) {
                d = -d;
            }
            if (d > 4) {
                p->f2ec = 0xffff;
            }
        }
    }
    if (ret == 1) {
        p->f2e0 = 0;
        func_021B9F2C(p, sel, 2);
    }
    return ret;
}
