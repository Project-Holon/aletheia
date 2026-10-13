/*
 * function: WIFICLUB_IsPeerAddrOfStatus
 * address:  0x021C27F8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203EFC8  0x0203EFC8  arm
 *
 * True when the arm9 comparison of the two blocks, 0x0E and 8 bytes in, answers 0.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);

BOOL WIFICLUB_IsPeerAddrOfStatus(char *p, char *q)
{
    if (func_0203EFC8((const u8 *)(p + 0xE), (const u8 *)(q + 8), 6) == 0) {
        return 1;
    }

    return 0;
}
