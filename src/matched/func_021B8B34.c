/*
 * function: func_021B8B34
 * address:  0x021B8B34
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * arm9 call whose result is the first argument of the second call.
 *
 * symbols:
 *   sub_020399A8  0x020399A8  arm
 *   sub_02039C68  0x02039C68  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 sub_020399A8(void);
extern void sub_02039C68(u32 a, u32 b, u32 c);

void func_021B8B34(void *p, u32 a, u32 b)
{
    sub_02039C68(sub_020399A8(), b, 0x20);
}
