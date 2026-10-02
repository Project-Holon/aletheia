/*
 * function: func_021E8270
 * address:  0x021E8270
 * packet:   pkt_ov093_021E8270
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021D76BC(int a, int b);
extern int func_021C8288(void *p);

void func_021E8270(int a, void *b, int c)
{
    int v;

    if (c == func_021D775C(3) && func_021C8288(b) == 1) {
        v = func_021D775C(0x20);
        if (v == 1)
            v++;
        func_021D76BC(0x20, v);
    }
}
