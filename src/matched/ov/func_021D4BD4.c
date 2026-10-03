/*
 * function: func_021D4BD4
 * address:  0x021D4BD4
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4BD4   0x021D4BD4  thumb ov093
 *   func_021D4394   0x021D4394  thumb ov093
 *   func_021F3B88   0x021F3B88  data
 *
 * Index a 0xBBC-stride table hanging off the pointer global at 0x021F3B88
 * plus 0xBF4, return the element's +0xBB8 halfword through *q.  The image
 * reaches 0xBBC and 0xBB8 by subtracting 0x38 and 0x3c from the 0xBF4 it
 * already has in r2 (mwcc's constant reuse), which the same expression here
 * reproduces.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 *func_021F3B88;

u8 func_021D4394(u32 a);

u16 func_021D4BD4(int a, u8 **q)
{
    u8 *p = func_021F3B88 + 0xbf4 + func_021D4394(a) * 0xbbc;
    *q = p;
    return *(u16 *)(p + 0xbb8);
}
