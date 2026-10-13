/*
 * function: BTL_SLOT_Add
 * address:  0x021B9B54
 * packet:   pkt_021B85A0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SLOT_Add   0x021B9B54  thumb
 *
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: ldrb r3, [r0, #0x18]; adds r2, r3, #1; strb r2, [r0, #0x18]; lsls r2, r3, #2; str r1, [r0, r2]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021B9B54  ldrb r3,[r0,#0x18]; adds r2,r3,#1; strb r2,[r0,#0x18];
 *           lsls r2,r3,#2; str r1,[r0,r2] */
struct Q1 { u32 items[6]; u8 count; };
void BTL_SLOT_Add(struct Q1 *p, u32 v)
{
    u8 n = p->count;
    p->count = n + 1;
    p->items[n] = v;
}

