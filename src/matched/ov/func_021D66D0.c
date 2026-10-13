/*
 * function: BTL_POKEPARAM_SetAbility
 * address:  0x021D66D0
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_SetAbility   0x021D66D0  thumb
 *
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r2, #0x4f; lsls r2, r2, #2; strh r1, [r0, r2]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D66D0  movs r2,#0x4f; lsls r2,#2; strh r1,[r0,r2] */
struct QJ { u8 pad[0x13c]; u16 v; };
void BTL_POKEPARAM_SetAbility(struct QJ *p, u32 v) { p->v = v; }

