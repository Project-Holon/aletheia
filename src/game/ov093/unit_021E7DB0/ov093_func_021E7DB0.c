/*
 * function: func_021E7DB0
 * address:  0x021E7DB0
 * packet:   pkt_ov093_021E7DB0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C812C  0x021C812C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C8138  0x021C8138  thumb  ov093
 *   func_021E7DF0  0x021E7DF0  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern u8 *func_021C812C(u8 *p);
struct Q7;
struct QQ;
extern u16 func_021D70A8(struct QQ *p);
extern u16 func_021C8138(struct Q7 *p);
extern u32 func_021E7DF0(int a, int b, int c);
extern void func_021E8860(int n);

void func_021E7DB0(void *a, void *b, int c)
{
    int x;
    u16 y;
    if (c == func_021D775C(3)) {
        x = (int)func_021C812C((u8 *)((int)b));
        y = func_021D70A8(a);
        if (func_021E7DF0(x, y, func_021C8138(b)) > 1)
            func_021E8860(2);
    }
}
