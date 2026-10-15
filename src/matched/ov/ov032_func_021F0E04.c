/*
 * function: BEACON_VIEW_SetActorVisible
 * address: 0x021F0E04
 * packet: pkt_ov032_021F0E04
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void BEACON_VIEW_SetActorVisible(char *p, unsigned a) { int i; for(i=0;i<=3;i++) CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x2bc),a); }
