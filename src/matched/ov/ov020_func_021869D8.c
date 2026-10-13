/*
 * function: FIELD_WFBC_DATA_LOCAL_ReadCounter
 * address:  0x021869D8
 * packet:   pkt_ov020_021869D8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (saves nothing, so disasm.py prints it as .word data);
 * filed as the blocker of FIELD_WFBC_DATA_LOCAL_ScrCmdGetWfbcValue (ov020).
 */

typedef unsigned char  u8;
typedef unsigned short u16;

u16 FIELD_WFBC_DATA_LOCAL_ReadCounter(u16 *p)
{
    return p[0];
}
