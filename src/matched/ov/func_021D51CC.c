/*
 * function: BTL_POKEPARAM_ClearMoveUsedFlags
 * address:  0x021D51CC
 * packet:   pkt_021D51CC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_ClearMoveUsedFlags   0x021D51CC  thumb
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldrb r2, [r0, #0xb]; movs r1, #0xf; bics r2, r1; strb r2, [r0, #0xb]; ldrb r2, [r0, #5]; bics r2, r1; strb r2, [r0, #5]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D51CC  first round: `p[x] &= ~0xf` narrowed the mask to 0xf0 and used
 * ands; the image keeps a 32-bit intermediate and bics with 0xf. */
void BTL_POKEPARAM_ClearMoveUsedFlags(u8 *p)
{
    u32 v;
    v = p[0xb];
    v &= ~0xf;
    p[0xb] = v;
    v = p[5];
    v &= ~0xf;
    p[5] = v;
}

