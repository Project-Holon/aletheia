/*
 * function: CAMERA_GetBytesAtOnceCore
 * address:  0x0270234C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CAMERA_GetTransferLinesCore  0x027022E0  arm twl
 */

typedef unsigned int u32;
typedef unsigned short u16;

u32 CAMERA_GetBytesAtOnceCore(u32 a0) {
    return (a0 << 1) * CAMERA_GetTransferLinesCore();
}
