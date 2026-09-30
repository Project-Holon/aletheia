/*
 * function: func_021E5B6C
 * address: 0x021E5B6C
 * packet: pkt_ov119_021E5B6C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: first y ternary is b == 0 ? 8 : 12 to retain branch polarity.
 * symbols:
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned short u16;
typedef struct { u16 x, y; } Pos;
extern int func_0204B404(int, void *, int);
void func_021E5B6C(int p, int b, int c)
{
    Pos pos;
    if (c) {
        pos.x = 96; pos.y = 12;
        func_0204B404(*(int *)(p + 0xf10), &pos, 1);
        pos.x = 160; pos.y = 12;
        func_0204B404(*(int *)(p + 0xf14), &pos, 1);
    } else {
        pos.x = 96; pos.y = b == 0 ? 8 : 12;
        func_0204B404(*(int *)(p + 0xf10), &pos, 1);
        pos.x = 160; pos.y = b ? 8 : 12;
        func_0204B404(*(int *)(p + 0xf14), &pos, 1);
    }
}
