/*
 * function: func_021CD3A4
 * address:  0x021CD3A4
 * packet:   pkt_ov021_021CD3A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   func_0200C1F8  0x0200C1F8  thumb
 *   func_02027198  0x02027198  thumb
 *   func_0200C210  0x0200C210  thumb
 *   func_020275C4  0x020275C4  thumb
 *   func_02045838  0x02045838  arm
 *   func_02165844  0x02165844  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void func_0200C1F8(int a, int b);
extern void func_02027198(void);
extern void func_0200C210(int a, int b);
extern int func_020275C4(int a);
extern void func_02045838(int a, int b);
extern void func_02165844(int a);

void func_021CD3A4(u8 *a, u8 *b)
{
    u16 *q = *(u16 **)(a + 0x18);

    if (q) {
        if (*(int *)(b + 0x1c) == 0)
            *q = 1;
        else
            *q = 0;
    }
    if (*(int *)(b + 0x1c) == 1)
        return;
    switch (*(int *)(a + 0x4c)) {
    case 5:
        func_0200C1F8(*(int *)(a + 8), *(int *)(b + 0x20));
        func_02027198();
        return;
    case 6:
        func_0200C210(*(int *)(a + 8), *(int *)(b + 0x20));
        return;
    case 7:
        func_02045838(func_020275C4(*(int *)(a + 0x14)), *(int *)(a + 0x3c));
        func_02165844(*(int *)(b + 0x20));
        return;
    }
}
