/*
 * function: ITEMMENU_MoveCursorDown
 * address:  0x021B6300
 * packet:   pkt_ov070_021B6300
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

int ITEMMENU_MoveCursorDown(Obj *o, int n, int k)
{
    int a, b;

    if (n == 0)
        return 0;
    a = o->a;
    b = o->b;
    if (a == 5 && b + 7 < n) {
        o->b = o->b + 1;
    } else if (a != 5 && a + 1 < n) {
        o->a = o->a + 1;
    } else if (k == 1) {
        o->b = -1;
        o->a = 0;
    }
    return a != o->a || b != o->b;
}
