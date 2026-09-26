/*
 * function: func_02156860
 * address:  0x02156860
 * packet:   pkt_ov009_02156860
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: callee of the ov099 veneer func_021C23B8 +0004.
 * Coherent Thumb code only in ov009 (ov010 opens with adds r3,r7,#0 and an
 * immediate branch), so the ov009 shard makes that site attest as `matched`.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int g_021A8264;

int func_02156860(int i)
{
    return (int)((char *)(int *)g_021A8264 + 0x34C + (i << 5));
}
