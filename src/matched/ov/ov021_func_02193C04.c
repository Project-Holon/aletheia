/*
 * function: FIELD_WFBC_PEOPLE_GetPersonData
 * address:  0x02193C04
 * packet:   pkt_ov021_02193C04
 * region:   ov021
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

void *FIELD_WFBC_PEOPLE_GetPersonData(u8 *p)
{
    return p + 0x34;
}
