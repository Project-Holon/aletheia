/*
 * function: func_021BA4F8
 * address:  0x021BA4F8
 * packet:   pkt_ov091_021BA4F8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B90F8  0x021B90F8  thumb  ov091
 *   func_0201A59C  0x0201A59C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021B90F8(u8 *a);
extern int func_0201A59C(u8 *rules, int party, u8 *z);

void func_021BA4F8(u8 *a)
{
    u8 i;
    u8 j;
    u8 *rules;
    int st;

    if (*(int *)(a + 0x250) != 0)
        return;
    st = a[0xc];
    if (st == 0x13)
        return;
    if (st == 0x15)
        return;
    if (st == 0)
        return;
    if (st == 1)
        return;
    if (st == 6)
        func_021B90F8(a);
    *(int *)(a + 0x250) = 1;
    if (*(int *)(a + 0x278) == 1)
        a[0xc] = 0x11;
    else
        a[0xc] = 0x14;
    *(int *)(*(u8 **)(a + 0x280) + 0x3c) = 6;
    *(int *)(*(u8 **)(a + 0x280) + 0x40) = 0;
    if (*(int *)(a + 0x118) != 0)
        return;
    for (i = 0; i < 6; i++)
        (*(u8 **)(a + 0x280))[0x49 + i] = 0;
    rules = *(u8 **)(*(u8 **)(a + 0x280) + 0x14);
    if (func_0201A59C(rules, **(int **)(a + 0x280), *(u8 **)(a + 0x280) + 0x49) != 0)
        return;
    for (i = 0; i < 6; i++)
        (*(u8 **)(a + 0x280))[0x49 + i] = 0;
    for (j = 0; j < rules[2]; j++)
        (*(u8 **)(a + 0x280))[0x49 + j] = j + 1;
}
