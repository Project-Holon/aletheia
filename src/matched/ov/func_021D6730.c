/*
 * function: BTL_POKEPARAM_ConsumeHeldItem
 * address:  0x021D6730
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_ConsumeHeldItem   0x021D6730  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: strh r1, [r0, #0x14]; movs r1, #0; strh r1, [r0, #0x12]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D6730  strh r1,[r0,#0x14]; movs r1,#0; strh r1,[r0,#0x12] */
struct QK { u8 pad[0x12]; u16 a; u16 b; };
void BTL_POKEPARAM_ConsumeHeldItem(struct QK *p, u16 v)
{
    p->b = v;
    p->a = 0;
}

