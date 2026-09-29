/*
 * function: func_021E15E8
 * address:  0x021E15E8
 * packet:   pkt_ov093_021E15E8
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
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D59B4(void *p, int k);
extern u32 func_021D78AC(u32 range);
extern int func_021D76BC(int key, int val);

void func_021E15E8(int a, void *p, int id)
{
    u8 k;
    u16 w;
    u16 r;
    if (id == func_021D775C(3)) {
        k = func_021D59B4(func_021C7CF4(p, id), 15);
        w = func_021D78AC(101) + 50;
        r = (k * w) / 100;
        if (r == 0) r = 1;
        func_021D76BC(0x37, r);
    }
}
