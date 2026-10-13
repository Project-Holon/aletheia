/*
 * function: WIFICLUB_FreeRegulation
 * address:  0x021BCBB0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_020307B0  0x020307B0  arm
 *
 * Free-like guard: calls sub_020307B0 only for a non-null pointer.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u32 sub_020307B0(void *p);

void WIFICLUB_FreeRegulation(void *p)
{
    if (p != 0) {
        sub_020307B0(p);
    }
}
