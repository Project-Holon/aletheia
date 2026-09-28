/*
 * function: func_021C6804
 * address:  0x021C6804
 * packet:   pkt_ov111_021C6804
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C67E8  0x021C67E8  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x68];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
} Info;

extern void func_021C67E8(void *p, int v);

void func_021C6804(void *p, Info *info)
{
    int i;

    for (i = 0; i < 13; i++) {
        func_021C67E8(p, i);
    }
    if (info->b0) {
        func_021C67E8(p, 14);
        func_021C67E8(p, 13);
    }
    if (info->b1) {
        func_021C67E8(p, 15);
    }
    if (info->b2) {
        func_021C67E8(p, 16);
    }
    if (info->b3) {
        func_021C67E8(p, 17);
    }
    if (info->b4) {
        func_021C67E8(p, 18);
    }
}
