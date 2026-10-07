/*
 * unit:     yes
 * function: func_021D919C, func_021D91D8
 * address:  0x021D919C
 * packet:   pkt_ov093_021D919C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F06A8     0x021F06A8  data   ov093  a4
 */

typedef unsigned char u8;

extern int func_021D775C(int);
typedef signed int     s32;
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern void func_021D7704(int key, s32 m);
extern int d_021F06A8[];

void func_021D919C(int a, void *b, int c)
{
    if (c == func_021D775C(4)) {
        if (func_021D62A8(func_021C7CF4(b, c))) {
            func_021D775C(0x12);
            if (func_021D775C(0x1a) == 1)
                func_021D7704(0x35, 0x1800);
        }
    }
}

int *func_021D91D8(int *p)
{
    *p = 1;
    return d_021F06A8;
}
