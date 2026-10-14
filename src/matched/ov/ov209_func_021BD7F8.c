/*
 * function: ZUKAN_LIST_InitActors
 * address: 0x021BD7F8
 * packet: pkt_ov209_021BD7F8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_LIST_InitActorSystem 0x021BD984 thumb ov209
 *   ZUKAN_LIST_LoadActorResources 0x021BD9B4 thumb ov209
 *   ZUKAN_LIST_CreateActors 0x021BDC08 thumb ov209
 *   ZUKAN_LIST_UpdateSpeciesActors 0x021BE010 thumb ov209
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct R;
extern void ZUKAN_LIST_InitActorSystem(char *);
extern void ZUKAN_LIST_LoadActorResources(struct R *p);
extern void ZUKAN_LIST_CreateActors(char *);
extern void ZUKAN_LIST_UpdateSpeciesActors(char *);extern void BG_SYS_SetMainPlaneVisible(u32,u32),BG_SYS_SetSubPlaneVisible(u32,u32);
void ZUKAN_LIST_InitActors(char *p) {ZUKAN_LIST_InitActorSystem(p);ZUKAN_LIST_LoadActorResources((struct R *)p);ZUKAN_LIST_CreateActors(p);ZUKAN_LIST_UpdateSpeciesActors(p);BG_SYS_SetMainPlaneVisible(16,1);BG_SYS_SetSubPlaneVisible(16,1);}
