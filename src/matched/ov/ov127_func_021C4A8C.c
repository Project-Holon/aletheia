/*
 * function: WF2DMAP_OBJ_GetTableByte
 * address:  0x021C4A8C
 * packet:   pkt_ov127_021C4A8C
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in a .word run:
 *   ldr r1,[pc,#4]; ldrb r0,[r1,r0]; bx lr; nop; .word 0x021C6010
 * Byte i of the table sWf2dmapDirectionTable.
 *
 * symbols:
 *   sWf2dmapDirectionTable  0x021C6010  data  a1
 */

extern unsigned char sWf2dmapDirectionTable[];

unsigned char WF2DMAP_OBJ_GetTableByte(int i)
{
    return sWf2dmapDirectionTable[i];
}
