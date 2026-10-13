/*
 * function: NET_WHPIPE_GetEntryKind
 * address:  0x02178098
 * packet:   pkt_ov014_02178098
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Recursive MATCH unblocker: the unlabelled ov014 leaf that func_0201058C
 * calls at +005C.  Byte-identical to func_02177B80: read g_pWhPipeWork, test the
 * per-slot u16 flag at +0xC40 (stride 2), then return the slot's u8 state at
 * +0x5C of the 0xC0-byte record, or 0.
 *
 * symbols:
 *   g_pWhPipeWork   0x021797A4  data  ov014  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *g_pWhPipeWork;

u8 NET_WHPIPE_GetEntryKind(u8 i)
{
    u8 *base = g_pWhPipeWork;

    if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0)
        return *(u8 *)(base + 0x5C + i * 0xC0);
    return 0;
}
