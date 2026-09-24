/*
 * function: func_021E9728
 * address:  0x021E9728
 * packet:   pkt_021E8CFC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9728   0x021E9728  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: str r1, [r0, #0x14]; movs r1, #0; str r1, [r0, #0x18]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021E9728  str r1,[r0,#0x14]; movs r1,#0; str r1,[r0,#0x18] */
struct QU { u8 pad[0x14]; u32 a; u32 b; };
void func_021E9728(struct QU *p, u32 v)
{
    p->a = v;
    p->b = 0;
}

