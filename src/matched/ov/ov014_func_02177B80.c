/*
 * function: func_02177B80
 * address:  0x02177B80
 * packet:   pkt_ov014_02177B80
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Recursive MATCH unblocker: the unlabelled ov014 leaf that the arm9
 * wih_dwc.c pollers call (sub_020107FC +001E, func_0201058C +005C).  Reads
 * the per-slot u16 flag array at g_021797A4+0xC40 (stride 2) and returns the
 * slot's u8 state at +0x5C of the 0xC0-byte record, or 0 when the global or
 * the flag is clear.  func_02178098 is byte-identical.
 *
 * symbols:
 *   g_021797A4   0x021797A4  data  ov014  a4
 */


typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *g_021797A4;


u8 func_02177B80(int i)
{
    u8 *base = g_021797A4;

    if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0)
        return *(u8 *)(base + 0x5C + i * 0xC0);
    return 0;
}

