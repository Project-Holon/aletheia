/*
 * unit:     yes
 * function: func_021ED318, func_021ED374
 * address:  0x021ED318
 * packet:   pkt_ov093_021ED318
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F80E4  0x021F80E4  thumb  ov094
 *   func_021F7F04  0x021F7F04  thumb  ov094
 *   func_020311B8  0x020311B8  arm
 *   func_02031290  0x02031290  arm
 *   func_021ED384  0x021ED384  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021F80E4(u32 a);
extern void func_021F7F04(u32 a);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern u8 *func_02031290(void *node);
extern void func_021ED384(void);

void func_021ED318(char *p, u16 k, u16 a, int flag)
{
    u8 *t;

    if (flag != 0 || a == 0) {
        func_021F80E4(k);
        func_021F7F04(k);
        return;
    }
    t = func_02031290(func_020311B8(*(u32 *)(p + 0x2c), (void *)func_021ED384, 0x10, 1));
    *(u16 *)(t + 6) = k;
    *(char **)t = p + 0x48 + k * 0xc;
    *(char **)(t + 0xc) = p + 0x42;
    if (a == 0)
        a = 0x26c;
    *(u16 *)(t + 8) = a;
    *(u16 *)(t + 4) = 0;
    (**(u8 **)(t + 0xc))++;
}

int func_021ED374(char *p)
{
    if (*(u8 *)(p + 0x42) == 0)
        return 1;
    return 0;
}
