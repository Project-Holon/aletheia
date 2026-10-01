/*
 * function: func_021DBE2C
 * address: 0x021DBE2C
 * packet: pkt_ov131_021DBE2C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct Point { s16 x, y; };
extern void func_0204B404(void *, const struct Point *, u16);
void func_021DBE2C(u8 *p, s16 x, s16 y)
{
    struct Point pt;
    int i, j;
    for (i = 0; i < p[0x23]; i++) {
        for (j = 0; j < p[0x22]; j++) {
            pt.x = (s16)(x + (j << 6));
            pt.y = (s16)(y + (i << 5));
            func_0204B404(*(void **)(p + 4 + (j + i * p[0x22]) * 4), &pt, *(u16 *)(p + 0x20));
        }
    }
}
