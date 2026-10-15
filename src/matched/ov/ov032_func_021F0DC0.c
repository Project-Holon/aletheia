/*
 * function: BEACON_VIEW_GetActionVariant
 * address: 0x021F0DC0
 * packet: pkt_ov032_021F0DC0
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GAME_BEACON_ACCESSOR_GetActionNo 0x02165E24 thumb ov010
 */
extern int GAME_BEACON_ACCESSOR_GetActionNo(int a0);
int BEACON_VIEW_GetActionVariant(void *p) { int a; a=GAME_BEACON_ACCESSOR_GetActionNo((int)p); if(a==0 || a>=0x33) return 0x12; return a+0x11; }
