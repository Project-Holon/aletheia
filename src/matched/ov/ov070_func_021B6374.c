/*
 * function: func_021B6374
 * address:  0x021B6374
 * packet:   pkt_ov070_021B6374
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

typedef struct Obj {
    unsigned char pad000[0x810];
    int a;
    int b;
} Obj;

int func_021B6374(Obj *o, int n, int k)
{
    int a, b, v;

    if (n == 0)
        return 0;
    a = o->a;
    b = o->b;
    if (a == 0 && b != -1) {
        o->b = o->b - 1;
    } else if (a != 0) {
        o->a = o->a - 1;
    } else if (k == 1) {
        v = n - 7;
        o->b = v;
        if (v < -1)
            o->b = -1;
        if ((o->a = 5) >= n)
            o->a = n - 1;
    }
    return a != o->a || b != o->b;
}
