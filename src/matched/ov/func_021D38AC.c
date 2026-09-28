/*
 * function: func_021D38AC
 * address:  0x021D38AC
 * packet:   pkt_021D377C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D38AC   0x021D38AC  thumb
 *   func_021B9934   0x021B9934  thumb
 *   func_021D5F08   0x021D5F08  thumb
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl func_021D5F08; movs r0, #1; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D38AC  shape F4: (u8) of a word arg, then func_021D5F08 */
int func_021D38AC(u8 *p, int b, u32 *q)
{
    func_021B9934(*(u32 *)(p + 4), (u8)*q);
    func_021D5F08();
    return 1;
}

