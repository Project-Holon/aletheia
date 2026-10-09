/*
 * function: func_021E7270, func_021E727C
 * address:  0x021E7270
 * packet:   pkt_ov093_021E727C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8130  0x021C8130  thumb  ov093
 *   func_021E72D4  0x021E72D4  thumb  ov093
 *   func_021E72E4  0x021E72E4  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F2624     0x021F2624  data   ov093  a4

 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u8 *func_021C8130(u8 *p);
extern int func_021E72D4(int a, int b);
extern int func_021E72E4(int a, int b, int c);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern void func_021D7704(int key, int m);

extern int d_021F2624[];
int *func_021E7270(int *p);

int *func_021E7270(int *p)
{
    *p = 1;
    return d_021F2624;
}

void func_021E727C(int a, int b, int c)
{
    int x;
    u32 n;
    u8 i;

    if (c == func_021D775C(3)) {
        x = (int)func_021C8130((u8 *)b);
        n = func_021E72D4(x, 1);
        for (i = 0; i < n; i++) {
            if (func_021B9A24(c, func_021E72E4(x, 1, i)) != 0) {
                func_021D7704(0x31, 0x2000);
                return;
            }
        }
    }
}
