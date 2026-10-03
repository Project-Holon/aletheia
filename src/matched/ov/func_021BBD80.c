/*
 * function: func_021BBD80
 * address:  0x021BBD80
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *
 * Release loop over the twelve pointers at +0x150, each paired with the block
 * at +0x118, with the slot cleared whether or not it was set; then two single
 * releases at +0x148 and +0x14C, all under one guard on the first slot.
 *
 * Every walked address is written index-first (`s + i * 4 + 0x150`), which is
 * the spelling the image has: 1.1p1 computes `s + i * 4` into r5 once and
 * keeps the field constant in a register (`ldr r0, [r5, r0]`), and the
 * constant it materialises for +0x150 is then reused to derive +0x118 as
 * -0x38 and the pair at the end as -0x08/+0x04.  The constant-first spelling
 * (`s + 0x150 + i * 4`), which is what this function was parked with, pulls
 * the whole offset up into the loop head and is a different allocation.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(void *p);
extern void func_0204ADA4(void *p);
extern void func_0204AFD8(void *p);

void func_021BBD80(char *s)
{
    int i;

    if (*(void **)(s + 0x150) != 0) {
        for (i = 0; i < 12; i++) {
            if (*(void **)(s + i * 4 + 0x150) != 0) {
                func_0204B3B4(*(void **)(s + i * 4 + 0x150));
                func_0204A8D4(*(void **)(s + i * 4 + 0x118));
            }
            *(u32 *)(s + i * 4 + 0x150) = 0;
        }
        func_0204ADA4(*(void **)(s + 0x148));
        func_0204AFD8(*(void **)(s + 0x14C));
    }
}
