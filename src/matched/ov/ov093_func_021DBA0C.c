/*
 * function: func_021DBA0C
 * address:  0x021DBA0C
 * packet:   pkt_ov093_021DBA0C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021B9A24(u8 c, int k);
extern u32 func_021C7D00(int a, int b);
extern int func_021C7F68(int p, u16 b, u8 *out);
extern void *func_021C7CF4(int a, int b);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D76BC(int a, int b);

void func_021DBA0C(int a, int p, int x)
{
    u8 buf[4];
    u32 n;
    u8 i;

    if (func_021B9A24(func_021D775C(2), x) == 0) {
        n = func_021C7F68(p, func_021C7D00(p, x) | 0x100, buf);
        for (i = 0; i < n; i++) {
            if (func_021D59B4(func_021C7CF4(p, buf[i]), 0x11) == 0x17)
                return;
        }
        func_021D76BC(0x41, 1);
    }
}
