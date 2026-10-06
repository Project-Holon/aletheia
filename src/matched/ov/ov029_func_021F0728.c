/*
 * function: func_021F0728
 * address:  0x021F0728
 * packet:   pkt_ov029_021F0728
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0728  0x021F0728  thumb  ov029
 *   func_021F07AC  0x021F07AC  thumb  ov029
 *   func_021F07EC  0x021F07EC  thumb  ov029
 *   func_021F0824  0x021F0824  thumb  ov029
 *   func_021F0858  0x021F0858  thumb  ov029
 *   func_021F088C  0x021F088C  thumb  ov029
 */

typedef unsigned char u8;

struct E {
    u8 b[10];
};

typedef unsigned short u16;
extern void func_021F07AC(u8 *p, int i, u16 *e);
extern void func_021F07EC(void *p, int i, unsigned short *q);
extern void func_021F0824(void *p, int i, unsigned short *q);
extern void func_021F0858(void *p, int i, unsigned short *q);
extern void func_021F088C(void *p, int i, unsigned short *q);

void func_021F0728(u8 *p)
{
    struct E *q = (struct E *)(p + 0x418);
    int i;

    for (i = 0; i < 3; i++) {
        u8 c = p[i + 0x44a];

        switch (c) {
        case 3:
            func_021F07AC(p, i, (u16 *)(&q[c]));
            break;
        case 1:
            func_021F07EC(p, i, (short unsigned int *)(&q[c]));
            break;
        case 2:
            func_021F0824(p, i, (short unsigned int *)(&q[c]));
            break;
        case 0:
            func_021F0858(p, i, (short unsigned int *)(&q[c]));
            break;
        case 4:
            func_021F088C(p, i, (short unsigned int *)(&q[c]));
            break;
        }
    }
}
