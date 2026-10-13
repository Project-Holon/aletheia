/*
 * function: CAMERA_SizeToHeightCore
 * address:  0x027023CC
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

u32 CAMERA_SizeToHeightCore(u32 v) {
    switch (v) {
    case 0: return 0x1e0;
    case 1: return 0xf0;
    case 2: return 0x78;
    case 3: return 0x120;
    case 4: return 0x90;
    case 5: return 0xc0;
    case 6: return 0x180;
    }
    return 0;
}
