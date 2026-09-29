/*
 * function: func_021E0F74
 * address:  0x021E0F74
 * packet:   pkt_ov093_021E0F74
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *p, u8 k);
extern int func_021D59B4(void *p, int k);
extern int func_021D76BC(int key, u32 val);

void func_021E0F74(int unused, void *q, int id)
{
    void *m;
    int k;
    u8 t;

    if (id == func_021D775C(3)) {
        t = func_021D775C(4);
        m = func_021C7CF4(q, t);
        k = 0x11;
        if (func_021D59B4(m, 0x11) == 0x36 || func_021D59B4(m, k) == 0xf)
            func_021D76BC(0x40, 1);
    }
}
