/*
 * function: func_0218DE78
 * address:  0x0218DE78
 * packet:   pkt_ov021_0218DE78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void func_02082BCC(void *p, int v, int n);

void func_0218DE78(char *p)
{
    int v;

    func_02082BCC(*(void **)(p + 0x44), 0xff, *(u16 *)(p + 0x2e));
    *(u8 *)(p + 0x41) = 0;
    *(u8 *)(p + 0x42) = *(u8 *)(p + 0x43);
    *(u8 *)(p + 0x43) = 0;
    *(u8 *)(p + 0x4c) = 0;
    if (*(volatile int *)0x02FFFC3C - *(int *)(p + 0x50) >= 2) {
        *(u8 *)(p + 0x4d) = 0xff;
        *(int *)(p + 0x48) = 0;
        return;
    }
    v = *(volatile u16 *)0x04000006;
    *(u8 *)(p + 0x4d) = v;
    if (v > 0xc0 || v <= 10) {
        *(int *)(p + 0x48) = 0xf000;
        return;
    }
    *(int *)(p + 0x48) = 0xf000 - ((v - 10) << 10);
}
