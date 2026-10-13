/*
 * function: CAMERA_SizeToWidthCore
 * address:  0x02702364
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 */

typedef unsigned int u32;
typedef unsigned short u16;

u32 CAMERA_SizeToWidthCore(u32 v) {
    switch (v) {
    case 0: return 0x280;
    case 1: return 0x140;
    case 2: return 0xa0;
    case 3: return 0x160;
    case 4: return 0xb0;
    case 5: return 0x100;
    case 6: return 0x200;
    }
    return 0;
}
