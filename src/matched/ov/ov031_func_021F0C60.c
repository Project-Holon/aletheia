/*
 * function: func_021F0C60
 * address:  0x021F0C60
 * packet:   pkt_ov031_021F0C60
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021F0D58 is filed as a 12-byte tail stub (r0 = 0x8000, r1 kept); the
 * call sites pass (b, n), so it is declared with two arguments here.
 *
 * symbols:
 *   func_021F0C60  0x021F0C60  thumb
 *   func_021F0D40  0x021F0D40  thumb  ov031
 *   func_021F0D58  0x021F0D58  thumb  ov031
 *   func_0204B454  0x0204B454  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    char pad[0x2C];
    int h;
    char pad2[0x43C - 0x30];
    int a;
    int n;
} B;

extern int func_021F0D40(B *);
extern int func_021F0D58(B *, int);
extern void func_0204B454(int, void *, int);

void func_021F0C60(B *o, B *b)
{
    s16 buf[2];
    int k;
    int t;
    int c;
    int i;
    int j;

    func_0204B454(o->h, buf, 1);
    t = (buf[1] - 0x1C) << 8;
    k = func_021F0D40(b);
    c = func_021F0D58(b, k);
    i = 0;
    t = t + (c >> 1);
    for (j = 0; j < k; j++) {
        if (t <= c * (i + 1))
            break;
        i++;
    }
    if (i >= k)
        i = k;
    b->n = i + (b->a - k);
    if (b->n < 3) {
        if (b->a < 3)
            b->n = b->a;
        else
            b->n = 2;
    }
    if (b->n < 0 || b->n > b->a)
        b->n = b->a;
}
