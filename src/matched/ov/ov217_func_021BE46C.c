/*
 * function: func_021BE46C
 * address:  0x021BE46C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C09C8  0x021C09C8  thumb  ov217
 *   func_021C09CC  0x021C09CC  thumb  ov217
 *
 * Classifies the record: 3 when the first query is busy and the second is
 * not, else 2.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C09C8(void *p);
extern u32 func_021C09CC(void *p);
u32 func_021BE46C(u8 *a0)
{
    u32 v = *(u32*)(a0);
    u32 a = func_021C09C8((void *)v);
    u32 b = func_021C09CC((void *)v);
    if (a != 0 && b == 0) {
    return 3;
    }
    return 2;
}
