/*
 * function: func_021F05D0
 * address:  0x021F05D0
 * packet:   pkt_ov029_021F05D0
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F05D0  0x021F05D0  thumb  ov029
 *   func_021F0CB8  0x021F0CB8  thumb  ov029
 *   func_021F0CDC  0x021F0CDC  thumb  ov029
 *   func_021F0CF0  0x021F0CF0  thumb  ov029
 *   func_021F0D10  0x021F0D10  thumb  ov029
 *   func_021F0390  0x021F0390  thumb  ov029
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct E {
    u8 b[10];
};

extern void func_021F0CB8(void *e);
extern int func_021F0CDC(void *e, int i);
extern void func_021F0CF0(void *e, int i);
extern void func_021F0D10(char *p, char v);
extern void func_021F0390(u8 *p, int i, int j, int k, int l);

void func_021F05D0(u8 *p)
{
    struct E *q2;
    struct E *q;
    int i;
    int j;
    int flag;

    flag = 0;
    for (i = 0; i < 5; i++) {
        q = (struct E *)(p + 0x418);
        func_021F0CB8(&q[i]);
        for (j = 0; j < 3; j++) {
            if (func_021F0CDC(&q[i], j) || p[0x460]) {
                func_021F0390(p, i, j, 0, p[0x461]);
                if (i == 0) {
                    flag = 1;
                }
                if (func_021F0CDC(&q[i], j)) {
                    func_021F0CF0(&q[i], j);
                }
            }
        }
    }
    if (flag) {
        q2 = (struct E *)(p + 0x418);
        for (i = 0; i < 5; i++) {
            if (i != 0) {
                func_021F0D10((char *)(&q2[i]), 1);
                for (j = 0; j < 3; j++) {
                    func_021F0390(p, i, j, 0, p[0x461]);
                }
            } else {
                func_021F0D10((char *)(&q2[i]), 0);
            }
        }
    }
    p[0x460] = 0;
}
