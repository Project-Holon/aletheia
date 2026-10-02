/*
 * function: func_021BA418
 * address:  0x021BA418
 * packet:   pkt_ov099_021BA418
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: the pad read is a named local (t) assigned before k = 2, so the
 * movs r7,#2 lands after the first blx.
 *
 * symbols:
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_0203630C  0x0203630C  arm
 *   func_021BA594  0x021BA594  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;

typedef struct {
    char pad00[0xc];
    int fc;
} W;

typedef struct {
    void *f0;
} S;

extern int func_021C49A4(void *p, int i);
extern unsigned int func_0203630C(void);
extern void func_021BA594(W *w, int a, int b, int c);

int func_021BA418(W *w, S *s)
{
    int a;
    int b;
    int k;
    int t;

    a = func_021C49A4(s->f0, 6);
    b = func_021C49A4(s->f0, 4);
    if (func_021C49A4(s->f0, 5) != 0) {
        return 0;
    }
    if (w->fc == 1) {
        return 0;
    }
    t = func_0203630C();
    k = 2;
    if (t & 2) {
        k = 3;
    }
    if (func_0203630C() & 0x40) {
        if (a == 0) {
            func_021BA594(w, k, a, b);
        } else {
            func_021BA594(w, 1, 0, b);
        }
    } else if (func_0203630C() & 0x80) {
        if (a == 1) {
            func_021BA594(w, k, a, b);
        } else {
            func_021BA594(w, 1, 1, b);
        }
    } else if (func_0203630C() & 0x20) {
        if (a == 2) {
            func_021BA594(w, k, a, b);
        } else {
            func_021BA594(w, 1, 2, b);
        }
    } else if (func_0203630C() & 0x10) {
        if (a == 3) {
            func_021BA594(w, k, a, b);
        } else {
            func_021BA594(w, 1, 3, b);
        }
    }
    return 0;
}
