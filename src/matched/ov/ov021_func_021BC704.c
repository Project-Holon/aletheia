/*
 * function: func_021BC704
 * address:  0x021BC704
 * packet:   pkt_ov021_021BC704
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef struct {
    char pad[0x28];
    int f28;
} Obj;

extern void func_0203FB44(int a, int b, int c);

void func_021BC704(Obj *p)
{
    if (p->f28 != -1) {
        func_0203FB44(3, p->f28, 0x20);
        p->f28 = -1;
    }
}
