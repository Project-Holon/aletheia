/*
 * function: FIELD_WFBC_ReloadSaveData
 * address:  0x02193904
 * packet:   pkt_ov021_02193904
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (saves nothing, so disasm.py prints it as .word data);
 * filed as the blocker of FIELD_WFBC_DATA_LOCAL_ScrCmdGetWfbcValue (ov020).
 *
 * symbols:
 *   FIELD_WFBC_LoadSaveData  0x02193EB4  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern int FIELD_WFBC_LoadSaveData(void *p);

int FIELD_WFBC_ReloadSaveData(void *p)
{
    return FIELD_WFBC_LoadSaveData(p);
}
