/*
 * function: func_021C28CC
 * address:  0x021C28CC
 * packet:   pkt_021C28CC
 * region:   ov217
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  6 bytes differ, codegen only.  The original hoists both loads
 *   first (ldrh r3,[p+4]; ldrh r0,[p+8]) then does each arm's arithmetic and
 *   store; mwcc interleaves load/add/store/load/subs/store.  A `b_then_a`
 *   source reproduces the hoisted load order but stores b before a; the exact
 *   load/arith/store interleave is a scheduler shape no tried C spelling
 *   reaches.  Constants: p+4 -> *a = x+0x14, p+8 -> *b = y-8.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021C28CC(char *p, u16 *a, u16 *b)
{
    u16 x = *(u16 *)(p + 4);
    u16 y = *(u16 *)(p + 8);

    *b = y - 8;
    *a = x + 0x14;
}
