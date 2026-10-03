/*
 * function: func_021BC3B8
 * address:  0x021BC3B8
 * packet:   pkt_ov088_021BC3B8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203159C  0x0203159C  arm
 *   func_020070A4  0x020070A4  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 */

typedef unsigned int u32;

extern void *func_0203159C(int a, int size, int heap);
struct Sub02007084Ctrl;
extern struct Sub02007084Ctrl *func_020070A4(void);
extern u32 func_0200873C(void *);
extern u32 func_0200C0F0(void *);

int func_021BC3B8(int a0)
{
    u32 *q = func_0203159C(a0, 0x5c, 1);

    q[0] = 1;
    q[1] = func_0200873C(func_020070A4());
    q[3] = func_0200C0F0(func_020070A4());
    q[2] = 0;
    return 1;
}
