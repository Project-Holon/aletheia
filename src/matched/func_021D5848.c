/*
 * function: func_021D5848
 * address:  0x021D5848
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5848   0x021D5848  thumb
 *
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: ldrb r2, [r0, #0x1b]; str r1, [r0, #4]; movs r1, #0x40; orrs r1, r2; strb r1, [r0, #0x1b]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D5848  ldrb r2,[r0,#0x1b]; str r1,[r0,#4]; movs r1,#0x40; orrs r1,r2;
 *           strb r1,[r0,#0x1b] */
struct QH { u8 pad[4]; u32 v; u8 pad2[0x1b - 8]; u8 flags; };
void func_021D5848(struct QH *p, u32 v)
{
    u8 f = p->flags;
    p->v = v;
    p->flags = f | 0x40;
}

