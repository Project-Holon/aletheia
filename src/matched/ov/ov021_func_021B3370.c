/*
 * function: func_021B3370
 * address:  0x021B3370
 * packet:   pkt_ov021_021B3370
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B3350  0x021B3350  thumb  ov021
 *   func_02007FB8  0x02007FB8  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   func_021B4714  0x021B4714  thumb  ov021
 *   func_021B4804  0x021B4804  thumb  ov021
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0200823C  0x0200823C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021B3350(char *w);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern u32 func_02007E3C(u8 *base, u16 id, u16 qty, u16 d);
extern void func_021B4714(char *w, u32 a, u32 b, u32 c);
extern void func_021B4804(char *w, u32 a);
extern u32 func_0200823C(u32 a);

void func_021B3370(char *w)
{
    u32 n;
    u32 k;
    u32 lim;

    n = func_021B3350(w);
    k = func_02007FB8((u8 *)(*(u32 *)(w + 0x10)), *(u16 *)(w + 0x1FC), *(u16 *)(w + 4));
    if (func_02007E3C((u8 *)(*(u32 *)(w + 0x10)), *(u16 *)(w + 0x1FC), 1, *(u16 *)(w + 4)) == 0) {
        func_021B4714(w, 10, *(u16 *)(w + 0x1FC), 0);
        w[0] = 10;
        w[1] = 4;
        return;
    }
    lim = *(u32 *)(w + 0x200);
    if (n < lim) {
        if (*(u8 *)(w + 0x163) == 0) {
            func_021B4714(w, 3, *(u16 *)(w + 0x1FC), 0);
        } else {
            func_021B4714(w, 0x10, *(u16 *)(w + 0x1FC), 0);
        }
        w[0] = 10;
        w[1] = 4;
    } else if (n >= lim && n < lim * 2) {
        func_021B4804(w, *(u8 *)(w + 0x162));
        w[0] = 10;
        w[1] = 5;
    } else if (*(u8 *)(w + 0x162) == 0) {
        func_021B4714(w, 4, *(u16 *)(w + 0x1FC), 0);
        w[0] = 10;
        w[1] = 2;
        *(u32 *)(w + 0x204) = n / *(u32 *)(w + 0x200);
        if (*(u32 *)(w + 0x204) > 99) {
            *(u32 *)(w + 0x204) = 99;
        }
        if (*(u32 *)(w + 0x204) + k > func_0200823C(*(u16 *)(w + 0x1FC))) {
            *(u32 *)(w + 0x204) = func_0200823C(*(u16 *)(w + 0x1FC)) - k;
        }
    } else {
        func_021B4804(w, *(u8 *)(w + 0x162));
        w[0] = 10;
        w[1] = 6;
    }
}
