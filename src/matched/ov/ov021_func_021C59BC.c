/*
 * function: func_021C59BC
 * address:  0x021C59BC
 * packet:   pkt_ov021_021C59BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Scroll step: slides the BG by 0xC0/4 per frame and flags the end after 4.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02040618(u32 layer, u32 a, u32 b);

void func_021C59BC(void *a, u8 *p)
{
    u16 n = *(u16 *)(p + 0x72);
    int v = n * 0xC0 / 4 - 0xC0;

    (*(u16 *)(p + 0x72))++;
    if (n >= 4) {
        v = 0;
        *(u32 *)(p + 0x80) = 1;
    }
    func_02040618(1, 3, v);
}
