/*
 * function: func_021D4954
 * address:  0x021D4954
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4954   0x021D4954  thumb ov093
 *   func_021F3B88   0x021F3B88  data
 *   func_021F3A98   0x021F3A98  data
 *   func_02030734   0x02030734  arm
 *
 * Read the 0x7fff-wide field at +4 of the structure the global pointer
 * 0x021F3B88 holds, set its top bit, and hand the (u16) of it to the ARM
 * helper 0x02030734 as (value, c, 1, 0x021F3A98, 0x031E).  The helper's
 * result is stored at +0x3b14 and read straight back out.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 *func_021F3B88;

u32 func_02030734(int v, int c, int one, int ptr, int n);

u32 func_021D4954(void *a, int b, int c)
{
    u32 v = (u16)(0x8000 | (*(u16 *)(func_021F3B88 + 4) & 0x7fff));
    u32 r = func_02030734(v, c, 1, 0x021f3a98, 0x31e);

    *(u32 *)(func_021F3B88 + 0x3b14) = r;
    return *(u32 *)(func_021F3B88 + 0x3b14);
}
