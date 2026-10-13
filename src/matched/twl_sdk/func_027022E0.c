/*
 * function: CAMERA_GetTransferLinesCore
 * address:  0x027022E0
 * packet:   twl_wifi
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_04004202  0x04004202  data twl a2
 */

typedef unsigned short u16;
typedef signed int s32;

extern u16 data_04004202;

s32 CAMERA_GetTransferLinesCore(void)
{
    return (data_04004202 & 0xf) + 1;
}
