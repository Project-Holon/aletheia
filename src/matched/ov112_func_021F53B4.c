/*
 * function: func_021F53B4
 * address:  0x021F53B4
 * packet:   pkt_ov112_021F53B4
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021F6290  0x021F6290  thumb  ov112
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021F6290(int);

void func_021F53B4(int a) {
    func_021F6290(*(int *)(a + 0xc));
    if (*(int *)(a + 0x10) != 0) {
        func_021F6290(*(int *)(a + 0x10));
    }
}
