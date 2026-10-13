/*
 * function: DWC_RAP_SetVchatEnabled
 * address:  0x02156BC4
 * packet:   pkt_ov009_02156BC4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: callee of the ov099 veneer func_021C0C7C +0008.
 * Coherent Thumb code only in ov009 (ov010 decodes to a pop with no push), so
 * the ov009 shard makes that site attest as `matched`.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int g_021A8264;

void DWC_RAP_SetVchatEnabled(int v)
{
    *(u16 *)((char *)(int *)g_021A8264 + 0x782) = v;
}
