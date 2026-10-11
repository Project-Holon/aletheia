/*
 * function: func_0689D258
 * address:  0x0689D258
 * packet:   pkt_ov095_0689D258
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021B8E28  0x021B8E28  thumb
 *   func_021B9920  0x021B9920  thumb
 *   func_021D5440  0x021D5440  thumb
 *   func_021D5B68  0x021D5B68  thumb
 */

typedef unsigned char u8;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Rec;

typedef struct {
    Rec r[6];
    u8 idx[6];
} T;

extern void func_021B8E28(int, int, u8 *, u8 *);
extern int func_021B9920(int, int, int);
extern int func_021D5B68(int);
extern int func_021D5440(int);

void func_0689D258(T *a, int b, int c, u8 d)
{
    u8 o1;
    u8 o0;
    int x;
    int y;

    func_021B8E28(b, d, &o1, &o0);
    x = func_021B9920(c, o1, o0);
    if (x != 0 && func_021D5B68(x) == 0) {
        y = func_021D5440(x);
        a->r[d].c = y;
        a->idx[y] = d;
    } else {
        a->r[d].c = 0x1f;
    }
    a->r[d].b = o1;
    a->r[d].a = 1;
}
