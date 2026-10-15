/*
 * function: FIELD_SUBSCREEN_ResumeField
 * address:  0x021A0FB4
 * packet:   pkt_ov021_021A0FB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetVReq  0x02188E30  thumb  ov021
 *   FLD_VREQ_SetMainBlendBrightnessExt  0x021D3270  thumb  ov021
 *   FIELD_MSGBG_SetBlendThunk  0x02193060  thumb  ov021
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   FIELD_MSGBG_LoadWindowGraphics  0x021902A4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u32 FIELDMAP_GetVReq(u8 *p);
extern void FLD_VREQ_SetMainBlendBrightnessExt(u32, u32, u32, u32, u32, u32);
extern void FIELD_MSGBG_SetBlendThunk(u32);
extern void BG_SYS_ClearSlot(u32 i);
extern void FIELD_MSGBG_LoadWindowGraphics(u32, u32);

void FIELD_SUBSCREEN_ResumeField(u32 *p, u32 a)
{
    FLD_VREQ_SetMainBlendBrightnessExt(FIELDMAP_GetVReq((u8 *)p[5]), 1, 0, 0, 0, 0);
    FIELD_MSGBG_SetBlendThunk(0);
    BG_SYS_ClearSlot(1);
    FIELD_MSGBG_LoadWindowGraphics(1, a);
}
