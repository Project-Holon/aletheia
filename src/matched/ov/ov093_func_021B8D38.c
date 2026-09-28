/*
 * function: func_021B8D38
 * address:  0x021B8D38
 * packet:   pkt_ov093_021B8D38
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8778  0x021B8778  thumb  ov093
 *   func_021B98A4  0x021B98A4  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021B8778(void *p, int k, u8 *out);
extern int func_021B98A4(int a, u8 b);
extern int func_021D5B68(int m);
extern int func_021D5440(int m);

u8 func_021B8D38(void *p, int a, int k, u8 *out)
{
    u8 buf[8];
    u8 n;
    u8 cnt;
    u8 i;
    int m;

    n = func_021B8778(p, k, buf);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        m = func_021B98A4(a, buf[i]);
        if (m && !func_021D5B68(m)) {
            out[cnt++] = func_021D5440(m);
        }
    }
    return cnt;
}
