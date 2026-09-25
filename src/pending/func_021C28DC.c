/*
 * function: func_021C28DC
 * address:  0x021C28DC
 * packet:   pkt_021C28DC
 * region:   ov217
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  6 bytes differ; original hoists both field loads, mwcc interleaves. C shape not pinned.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021C28DC(char *p, u16 *a, u16 *b)
{
    u32 *q = (u32 *)p;

    *a = q[1] + 0xF;
    *b = q[2] - 8;
}
