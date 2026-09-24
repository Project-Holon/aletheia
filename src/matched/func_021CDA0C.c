/*
 * function: func_021CDA0C
 * address:  0x021CDA0C
 * packet:   pkt_021CC95C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CDA0C   0x021CDA0C  thumb
 *
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: str r1, [r0, #0x28]; movs r1, #0x6a; movs r2, #0; lsls r1, r1, #2; strb r2, [r0, r1]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021CDA0C  str r1,[r0,#0x28]; movs r1,#0x6a; movs r2,#0; lsls r1,#2;
 *           strb r2,[r0,r1] */
struct QE { u8 pad[0x28]; u32 v; u8 rest[0x1a8 - 0x2c]; u8 z; };
void func_021CDA0C(struct QE *p, u32 v)
{
    p->v = v;
    p->z = 0;
}

