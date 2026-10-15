/*
 * function: WF2DMAP_SCENE_GetCellAnim
 * address: 0x021DA158
 * packet: pkt_ov129_021DA158
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: n+x gives the original adds operand order.
 */
int WF2DMAP_SCENE_GetCellAnim(int x,int flag) { int n; n=0; if(!flag) n=11; return n+x; }
