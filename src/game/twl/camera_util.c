/*
 * file:     camera_util.c
 * unit:     yes
 * function: CAMERA_SizeToWidthCore, CAMERA_SizeToHeightCore
 * address:  0x02702364
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libcamera.TWL.HYB.a camera_util.o
 */
typedef unsigned int u32;

u32 CAMERA_SizeToWidthCore(u32 v);
u32 CAMERA_SizeToHeightCore(u32 v);

u32 CAMERA_SizeToWidthCore(u32 size) {
    switch (size) {
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

u32 CAMERA_SizeToHeightCore(u32 size) {
    switch (size) {
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
