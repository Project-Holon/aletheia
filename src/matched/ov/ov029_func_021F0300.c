/*
 * function: func_021F0300
 * address:  0x021F0300
 * packet:   pkt_ov029_021F0300
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0300  0x021F0300  thumb  ov029
 *   func_021F0CA0  0x021F0CA0  thumb  ov029
 *   func_021F0D10  0x021F0D10  thumb  ov029
 *   func_021F0390  0x021F0390  thumb  ov029
 *   d_021F31BC     0x021F31BC  data  ov029  a2
 *   d_021F31AB     0x021F31AB  data  ov029  a1
 *   d_021F31B0     0x021F31B0  data  ov029  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct E {
    u8 b[10];
};

extern void func_021F0CA0(void *e, u16 a, u8 b, u8 c);
extern void func_021F0D10(void *e, int v);
extern void func_021F0390(u8 *p, int i, int j, int k, int l);
extern u16 d_021F31BC[];
extern u8 d_021F31AB[];
extern u8 d_021F31B0[];

void func_021F0300(u8 *p)
{
    struct E *q = (struct E *)(p + 0x418);
    int i;
    int j;

    for (i = 0; i < 5; i++) {
        func_021F0CA0(&q[i], d_021F31BC[i], d_021F31AB[i], d_021F31B0[i]);
        if (i != 0) {
            func_021F0D10(&q[i], 0);
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            func_021F0390(p, i, j, 1, p[0x461]);
        }
    }
}
