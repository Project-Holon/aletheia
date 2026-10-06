/*
 * function: func_021E80C0
 * address:  0x021E80C0
 * packet:   pkt_ov093_021E80C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021C815C(int *p);
extern void *func_021C7CF4(int *p, int i);
extern unsigned char func_021D69AC(unsigned char *base, int idx);
extern int func_021D76BC(int key, u32 val);

void func_021E80C0(int a, void *b, int c)
{
    u8 v, t;
    if (func_021C815C(b) != 0 && func_021C815C(b) != 3) {
        v = func_021D69AC(func_021C7CF4(b, c), 4);
        if (v == 0 || (u8)(v - 1) >= 0x18)
            t = 0x1f;
        else
            t = v - 1;
        if (t != 0x1f)
            func_021D76BC(4, t);
    }
}
