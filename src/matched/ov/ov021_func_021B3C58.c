/*
 * function: SCRCMD_PROC_FLD_ExitShopGraphics
 * address:  0x021B3C58
 * packet:   pkt_ov021_021B3C58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204047C  0x0204047C  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   FIELD_MSGBG_SetBlendThunk  0x02193060  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void BG_SYS_ClearSlot(u32);
extern void func_0204047C(int idx, unsigned short val);
extern void FIELD_MSGBG_SetBlendThunk(u32);

void SCRCMD_PROC_FLD_ExitShopGraphics(u8 *w)
{
    BG_SYS_ClearSlot(1);
    BG_SYS_ClearSlot(2);
    func_0204047C(2, 0);
    FIELD_MSGBG_SetBlendThunk(1);
}
