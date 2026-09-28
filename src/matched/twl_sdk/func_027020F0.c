/*
 * function: func_027020F0
 * address:  0x027020F0
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
typedef signed short s16;
typedef signed int s32;

extern u16 data_04004202;

s32 func_027020F0(void)
{
    return (data_04004202 & 0x8000) >> 15;
}
