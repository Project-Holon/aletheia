/*
 * function: func_021E1074
 * address:  0x021E1074
 * packet:   pkt_ov093_021E1074
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D76BC(int key, u32 val);

void func_021E1074(int unused, void *q, int id)
{
    void *a;
    void *b;
    u8 t;
    u8 x;
    u8 y;

    if (id == func_021D775C(3)) {
        t = func_021D775C(4);
        a = func_021C7CF4(q, t);
        b = func_021C7CF4(q, id);
        x = func_021D59B4(b, 0x12);
        y = func_021D59B4(a, 0x12);
        if (x == 2 || y == 2 || x == y)
            func_021D76BC(0x40, 1);
    }
}
