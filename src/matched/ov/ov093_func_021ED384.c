/*
 * function: func_021ED384
 * address:  0x021ED384
 * packet:   pkt_ov093_021ED384
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F7A28  0x021F7A28  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021F80E4  0x021F80E4  thumb  ov094
 *   func_021F7F04  0x021F7F04  thumb  ov094
 *   func_02031194  0x02031194  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021F7A28(int a, u32 b);
extern int func_021F7EB4(void);
extern void func_021F80E4(u32 a);
extern void func_021F7F04(int a);
extern void func_02031194(u32 a);

void func_021ED384(u32 a, u8 *t)
{
    switch (*(u16 *)(t + 4)) {
    case 0:
        func_021F7A28(*(u16 *)(t + 6), *(u16 *)(t + 8));
        (*(u16 *)(t + 4))++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021F80E4(*(u16 *)(t + 6));
            func_021F7F04(*(u16 *)(t + 6));
            (*(u16 *)(t + 4))++;
        }
        break;
    case 2:
        (**(u8 **)(t + 0xc))--;
        func_02031194(a);
        break;
    }
}
