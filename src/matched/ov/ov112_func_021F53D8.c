/*
 * function: func_021F53D8
 * address:  0x021F53D8
 * packet:   pkt_ov112_021F53D8
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021F62FC  0x021F62FC  thumb  ov112
 *   func_021F62DC  0x021F62DC  thumb  ov112
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021F62FC(int, int);
extern void func_021F62DC(int);

void func_021F53D8(int a) {
    if (*(int *)(a + 4) == 1) {
        func_021F62FC(*(int *)(a + 0xc), *(int *)(a + 0x10));
        *(int *)(a + 8) = *(int *)(a + 0x10);
        *(int *)(a + 4) = 0;
        func_021F62DC(*(int *)(a + 0xc));
    } else {
        func_021F62FC(*(int *)(a + 0x10), *(int *)(a + 0xc));
        *(int *)(a + 8) = *(int *)(a + 0xc);
        *(int *)(a + 4) = 1;
        func_021F62DC(*(int *)(a + 0x10));
    }
}
