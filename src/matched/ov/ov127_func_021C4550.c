/*
 * function: WIFI_2DCHAR_IsHandleValid
 * address:  0x021C4550
 * packet:   pkt_021C4550
 * region:   ov127
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int WIFI_2DCHAR_IsHandleValid(int *p)
{
    return *p != -1;
}
