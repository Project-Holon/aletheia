/*
 * function: func_021BB570
 * address:  0x021BB570
 * packet:   pkt_ov093_021BB570
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BBB60  0x021BBB60  thumb  ov093
 *   func_021BBC34  0x021BBC34  thumb  ov093
 *   func_021BBC44  0x021BBC44  thumb  ov093
 *   func_021BBD80  0x021BBD80  thumb  ov093
 *   func_021BBD8C  0x021BBD8C  thumb  ov093
 *   func_021BBD20  0x021BBD20  thumb  ov093
 *   func_021BBD2C  0x021BBD2C  thumb  ov093
 *   func_0203EFC8  0x0203EFC8  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021BBB60(u8 *);
extern void func_021BBC34(u8 *);
extern int func_021BBC44(u8 *, int);
extern void func_021BBD80(u8 *);
extern int func_021BBD8C(u8 *, int);
extern void func_021BBD20(u8 *);
extern int func_021BBD2C(u8 *, int);
extern int func_0203EFC8(const void *, const void *, u32);

int func_021BB570(u8 *p, int sel, void *data, u32 n)
{
    u32 *s = *(u32 **)(p + 0xcb0);

    s[0] = 0;
    s[1] = 0;
    switch (sel) {
    case 4:
        func_021BBB60(*(u8 **)(p + 0x44));
        break;
    case 1:
        func_021BBC34(*(u8 **)(p + 0x44));
        func_021BBC44(*(u8 **)(p + 0x44), (int)(p + 0xb4));
        break;
    case 2:
        func_021BBD80(*(u8 **)(p + 0x44));
        func_021BBD8C(*(u8 **)(p + 0x44), (int)(p + 0xb4));
        break;
    case 3:
        func_021BBD20(*(u8 **)(p + 0x44));
        func_021BBD2C(*(u8 **)(p + 0x44), (int)(p + 0xb4));
        break;
    }
    s = *(u32 **)(p + 0xcb0);
    if (s[0] == n && func_0203EFC8(s + 2, data, n) == 0)
        return 0;
    return 1;
}
