/*
 * function: func_021F77EC
 * address:  0x021F77EC
 * packet:   pkt_ov112_021F77EC
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

void func_021F77EC(u32 unused, u8 *p, u32 v)
{
    if (v == 0xe8) { *(u32 *)(p + 0x24) = 0xfb3; return; }
    if (v == 0x184 || v == 0x1fc) { *(u32 *)(p + 0x24) = 0xfc0; return; }
    if (v == 0x4b || v == 0xcd || v == 0xf5) { *(u32 *)(p + 0x24) = 0xfcc; return; }
    if (v == 0x2d || v == 0x142) { *(u32 *)(p + 0x24) = 0x1040; return; }

    if (v == 9 || v == 0x21 || v == 0x3d || v == 0x41 || v == 0x4c ||
        v == 0x7a || v == 0x7b || v == 0x8d || v == 0xd6 || v == 0xeb ||
        v == 0xfd || v == 0x100 || v == 0x108 || v == 0x115 || v == 0x11e ||
        v == 0x13b || v == 0x15b || v == 0x1b2 || v == 0x1bc || v == 0x276) {
        *(u32 *)(p + 0x28) = 0xfcc;
        return;
    }
    if (v == 0x25 || v == 0xd7 || v == 0xdb || v == 0x16a || v == 0x250 ||
        v == 0x264) {
        *(u32 *)(p + 0x28) = 0xfd9;
        return;
    }
    if (v == 0x12 || v == 0x35 || v == 0x7e || v == 0x80 || v == 0x9c ||
        v == 0x9d || v == 0xb5 || v == 0xd0 || v == 0xf6 || v == 0xf8 ||
        v == 0x134 || v == 0x162 || v == 0x17a || v == 0x189 || v == 0x18e ||
        v == 0x1a3 || v == 0x1cc || v == 0x222 || v == 0x231 || v == 0x26f ||
        v == 0x283) {
        *(u32 *)(p + 0x28) = 0xfe6;
        return;
    }
    if (v == 0x26 || v == 0x120) { *(u32 *)(p + 0x28) = 0xff3; return; }

    if (v == 0x1c1) {
        *(u32 *)(p + 0x24) = 0x1040;
        *(u32 *)(p + 0x28) = 0xfcc;
        return;
    }
    if (v == 0x26e) {
        *(u32 *)(p + 0x24) = 0xfc0;
        *(u32 *)(p + 0x28) = 0xfcc;
        return;
    }
}
