/*
 * function: func_021BA078
 * address:  0x021BA078
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA150  0x021BA150  thumb  ov217
 *   func_021BA37C  0x021BA37C  thumb  ov217
 *   func_021BA384  0x021BA384  thumb  ov217
 *
 * Steps the record through func_021BA150 while the running count is below
 * func_021BA37C().
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BA150();
extern u32 func_021BA37C();
extern u32 func_021BA384(void *p);
void func_021BA078(u32 a0)
{
    u32 v1 = func_021BA384((void *)a0);
    if (v1 < func_021BA37C(a0)) {
    func_021BA150(a0);
    }
}
