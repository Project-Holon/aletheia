/*
 * function: func_021BD2B4
 * address:  0x021BD2B4
 * packet:   pkt_ov093_021BD2B4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB878  0x021BB878  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 *func_021BB878(u8 *p, u32 i);
extern u8 *func_021B9C00(void *p, u32 i);
extern int func_021D5B68(void *p);

void func_021BD2B4(u8 *p, u8 **q)
{
    u8 i = 0;
    u8 *m;
    u8 j;
    u8 *x;
    int f;
    p[0] = i;
    p[1] = i;
    p[2] = 1;
    p[3] = i;
    for (; i < 4; i++) {
        m = func_021BB878(*q, i);
        if (m == 0) continue;
        for (j = 0; j < m[9]; j++) {
            x = func_021B9C00(*(u8 **)(m + 4), j);
            if (x) f = func_021D5B68(x) == 0;
            else f = 0;
            if (f) {
                p[0] = i;
                p[2] = 0;
                p[1] = j;
                return;
            }
        }
    }
}
