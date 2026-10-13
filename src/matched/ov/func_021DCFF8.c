/*
 * function: HAND_ITEM_GetParam
 * address:  0x021DCFF8
 * packet:   pkt_021DC604
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HAND_ITEM_GetParam   0x021DCFF8  thumb
 *   BTL_EVENT_GetFactorKey   0x021D70A8  thumb
 *   BTL_CALC_GetMonParamWithHeap   0x021D805C  thumb
 * Leaf with no calls and no pool; 6 instructions, 16 bytes: push {r4, lr}; adds r4, r1, #0; bl BTL_EVENT_GetFactorKey; adds r1, r4, #0; bl BTL_CALC_GetMonParamWithHeap; pop {r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);

/* 021DCFF8  pass-through: second callee takes the first one's result */
int HAND_ITEM_GetParam(int a, int b)
{
    return BTL_CALC_GetMonParamWithHeap((void *)BTL_EVENT_GetFactorKey((void *)a), b);
}

