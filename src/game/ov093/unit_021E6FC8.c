/*
 * file:     unit_021E6FC8.c
 * function: func_021E6FC8, func_021E7000
 * address:  0x021E6FC8
 * packet:   pkt_ov093_021E6FC8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F2524     0x021F2524  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021D7704(int a, int b);

void func_021E6FC8(int x, int a, int c)
{
    int t = 4;

    if (c == func_021D775C(3)) {
        if (func_021D62C4(func_021C7CF4((int *)a, (u8)func_021D775C(4)), 5) != 0) {
            func_021D7704(0x31, t << 11);
        }
    }
}


extern int d_021F2524[];
int *func_021E7000(int *p);

int *func_021E7000(int *p)
{
    *p = 1;
    return d_021F2524;
}
