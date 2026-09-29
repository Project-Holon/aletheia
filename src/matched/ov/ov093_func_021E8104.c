/*
 * function: func_021E8104
 * address:  0x021E8104
 * packet:   pkt_ov093_021E8104
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
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021C814C  0x021C814C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern u8 func_021D69AC(void *a, int i);
extern int func_021C814C(void *a, int b);
extern int func_021D76BC(int a, int b);

void func_021E8104(int a, void *b, int c)
{
    u8 v, t;
    if (c == func_021D775C(2)) {
        v = func_021D69AC(func_021C7CF4(b, c), 4);
        if (v == 0 || (u8)(v - 1) >= 0x18)
            t = 0x1f;
        else
            t = v - 1;
        if (t != 0x1f && func_021C814C(b, t) == 0)
            func_021D76BC(0x22, 0x1a);
    }
}
