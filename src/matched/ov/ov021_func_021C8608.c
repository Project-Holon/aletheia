/*
 * function: func_021C8608
 * address:  0x021C8608
 * packet:   pkt_ov021_021C8608
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   d_021DE534     0x021DE534  data  a4
 *   d_00000024     0x00000024  data  a4
 */

extern char d_021DE534;
extern char d_00000024[];

extern char *func_02030734(int a, int b, int c, void *d, int e);
extern void func_02034AC4(int a);
extern void func_02034A5C(int a);
extern void func_021F36C0(char *p);

char *func_021C8608(void)
{
    char *p = func_02030734(5, 0x1b8, 1, &d_021DE534, 0x31);

    *(int *)(p + 0) = 0;
    *(unsigned short *)(p + 4) = 0;
    *(int *)(p + 8) = 0;
    p[0x1b0] = 0;
    p[0x1b1] = 0;
    p[0x1b2] = 0;
    p[0x1b3] = 0;
    *(int *)(p + 0x1b4) = 0;
    func_02034AC4((int)d_00000024);
    func_021F36C0(p);
    func_02034A5C((int)d_00000024);
    return p;
}
