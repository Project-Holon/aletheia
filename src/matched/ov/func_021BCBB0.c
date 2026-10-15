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
 *   GFL_HEAP_Free  0x020307B0  arm
 *
 * Free-like guard: calls GFL_HEAP_Free only for a non-null pointer.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u32 GFL_HEAP_Free(void *p);

void WIFICLUB_FreeRegulation(void *p)
{
    if (p != 0) {
        GFL_HEAP_Free(p);
    }
}
