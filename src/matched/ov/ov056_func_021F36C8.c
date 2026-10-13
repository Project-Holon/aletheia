/*
 * function: FIELD_FK_DEMO_GetCameraSettingId
 * address:  0x021F36C8
 * packet:   pkt_ov056_021F36C8
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Word table lookup in gFkDemoCameraSettingId ({0x1C, 0x1D, 0x1E, 0x1F}), the table ov056
 * FIELD_FK_DEMO_InitCamera also indexes. Region ov056: of the 33 overlays mapped at this
 * address it is the only one with a function entry here (the bytes before are
 * the tail-call thunk at 0x021F36C0 and its pool word); ov036..ov065 except
 * ov056 are mid-function at 0x021F36C8, ov107 is ARM. Its ov021 caller
 * SCRCMD_PROC_FLD_SetOv056Slot passes a 1-based slot minus one (wave A1 witness).
 *
 * symbols:
 *   gFkDemoCameraSettingId  0x021F42B0  data
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern const u32 gFkDemoCameraSettingId[];

u32 FIELD_FK_DEMO_GetCameraSettingId(u32 idx)
{
    return gFkDemoCameraSettingId[idx];
}
