/*
 * function: func_021B6048
 * address:  0x021B6048
 * packet:   pkt_ov021_021B6048
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021B5FB8  0x021B5FB8  thumb  ov021
 *   func_021B5FB4  0x021B5FB4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5E4(void *a0);
extern void *func_02012934(void *p);
extern int func_0201AA18(u32 a);
extern u32 func_0201AB28(u32 a, int i);
extern u32 func_02017E1C(u32 a, u32 b, u32 c);
extern int func_021B5FB8(u32 a, u32 b);
extern int func_021B5FB4(u32 a);

int func_021B6048(u32 a, u32 b, u32 key, u8 *mask, u32 flag)
{
    void *lst;
    int n;
    int i;
    int found;
    int all;
    u32 item;

    lst = func_02012934(func_0215A5E4((void *)b));
    n = func_0201AA18(lst);
    found = 0;
    all = 0;
    *mask = found;
    for (i = 0; i < n; i++) {
        item = func_0201AB28(lst, i);
        if (func_02017E1C(item, 0x4c, 0) == 1)
            continue;
        if (func_021B5FB8(item, key) == 0)
            continue;
        found = 1;
        if (flag != 0) {
            item = func_02017E1C(item, 9, 0);
            if (item < func_021B5FB4(key))
                continue;
        }
        all = 1;
        *mask = *mask | (u8)(1 << i);
    }
    if (found == 0)
        return 1;
    if (all == 0)
        return 2;
    return 0;
}
