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
 *   data_02004200  0x02004200  data twl a2
 */

typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

extern u16 data_02004200;

s32 func_027020F0(void)
{
    return (data_02004200 & 0x8000) >> 15;
}
