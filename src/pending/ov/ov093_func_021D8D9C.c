/*
 * function: func_021D8D9C
 * address:  0x021D8D9C
 * packet:   pkt_ov093_021D8D9C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021C8010(void *p, int k);
extern u32 func_021C7F68(void *p, u16 b, u8 *out);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D59B4(void *p, int k);

int func_021D8D9C(void *a, int k, u8 *buf, int v)
{
    int t;
    u32 n;
    u8 i;

    t = func_021C8010(a, k);
    if (t != 6) {
        n = func_021C7F68(a, (u16)((7 << 8) | t), buf);
        for (i = 0; i < n; i++) {
            if (k != buf[i]) {
                if (v == func_021D59B4(func_021C7CF4(a, buf[i]), 0x11))
                    return 1;
            }
        }
    }
    return 0;
}
