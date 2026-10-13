/*
 * function: TOWNMAP_GRH_SetLabelVisible
 * address: 0x021BB5B4
 * packet: pkt_ov072_021BB5B4
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   TOWNMAP_GRH_ClearTextBox 0x021BB49C thumb ov072
 */
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void TOWNMAP_GRH_ClearTextBox(void **p);
void TOWNMAP_GRH_SetLabelVisible(u32 *p,u32 v) { CLACT_SetActorDrawEnable((void *)p[4],v); if(v==0) { p[7]=0; p[6]=0; TOWNMAP_GRH_ClearTextBox((void **)p); } }
