/*
 * unit: no
 * function: GSYNC_STATE_ChangeState
 * address: 0x021D6EE0
 * packet: pkt_ov123_021D6EE0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_SetNextState 0x021D6EDC thumb ov123
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern void GSYNC_STATE_SetNextState(u8 *,u32,int);
void GSYNC_STATE_ChangeState(u8 *p,u32 v,int unused){GSYNC_STATE_SetNextState(p,v,unused);}
