/*
 * function: BTLV_CORE_CloseMenu
 * address: 0x021E9954
 * packet: pkt_ov093_021E9954
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Indexed-dispatch thunk, sibling of BTLV_CORE_CloseMenuToReselect (same shape, other tail target).
 * Tail call T(p[6].f0) with the index materialised as a scaled immediate.
 * Unlabelled leaf filed as the witness for the call in BTL_CLIENT_StepSelectAction.
 * symbols:
 *   BTLV_CORE_CloseMenu 0x021E9954 thumb ov093
 *   BTLV_SCD_CloseInputIfOpen 0x06899D3C thumb ov095
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 f0; u8 pad[60]; } E64;
extern void BTLV_SCD_CloseInputIfOpen(u32);
void BTLV_CORE_CloseMenu(E64 *p) { BTLV_SCD_CloseInputIfOpen(p[0x6].f0); }
