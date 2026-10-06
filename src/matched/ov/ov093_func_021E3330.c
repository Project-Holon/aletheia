/*
 * function: func_021E3330
 * address:  0x021E3330
 * packet:   pkt_ov093_021E3330
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C824C  0x021C824C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021C824C(u8 *p, int v);
extern void *func_021C7CF4(int *p, int i);
struct QI;
extern u16 func_021D5B40(struct QI *p);
extern u32 func_021D805C(void *p, u32 n);
extern int func_021D76BC(int key, u32 val);

void func_021E3330(int u, void *p, int key)
{
    u16 x;
    int k;
    if (key == func_021D775C(2)) {
        if (func_021C824C(p, key) == 0) {
            func_021D76BC(0x22, 0x1a);
            return;
        }
        x = (u16)(int)func_021D5B40(func_021C7CF4(p, key));
        k = 11;
        func_021D805C((void *)x, k);
        if (x == 0 || func_021D805C((void *)x, k) == 0)
            func_021D76BC(0x22, 0x1a);
    }
}
