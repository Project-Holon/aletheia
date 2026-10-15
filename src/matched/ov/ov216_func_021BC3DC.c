/*
 * function: BEACON_DETAIL_GRA_UpdateTouchBar
 * address: 0x021BC3DC
 * packet: pkt_ov216_021BC3DC
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 */
typedef struct S S;
extern void TOUCHBAR_Update(struct S *p);
void BEACON_DETAIL_GRA_UpdateTouchBar(S *p){TOUCHBAR_Update(p);}
