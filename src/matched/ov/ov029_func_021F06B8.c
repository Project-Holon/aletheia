/*
 * function: func_021F06B8
 * address:  0x021F06B8
 * packet:   pkt_ov029_021F06B8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F06B8  0x021F06B8  thumb  ov029
 *   func_021F08BC  0x021F08BC  thumb  ov029
 *   func_021F0D00  0x021F0D00  thumb  ov029
 */

typedef unsigned char u8;

struct E {
    u8 b[10];
};

extern void func_021F08BC(u8 *p, int i, int j, int k);
extern void func_021F0D00(void *e, int i);

void func_021F06B8(u8 *p, int a, int b)
{
    struct E *q;
    int i;
    int j;
    int k;

    for (i = 0; i < 3; i++) {
        func_021F08BC(p, i, 0, 0x1f);
    }
    q = (struct E *)(p + 0x418);
    for (j = 0; j < 5; j++) {
        for (k = 0; k < 3; k++) {
            func_021F0D00(&q[j], k);
        }
    }
    p[0x461] = a;
    p[0x460] = 1;
    p[0x465] = 1;
    p[0x466] = 0;
    p[0x464] = b;
}
