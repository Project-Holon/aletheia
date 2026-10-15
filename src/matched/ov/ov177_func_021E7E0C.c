/*
 * function: WIFIBATTLEMATCH_VIEW_SetActorVisible
 * address: 0x021E7E0C
 * packet: pkt_ov177_021E7E0C
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   GFL_USE_StopSeSlot  0x020061F8  thumb  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 */
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
typedef unsigned int   u32;
struct Obj;
extern void GFL_USE_StopSeSlot(int i);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void WIFIBATTLEMATCH_VIEW_SetActorVisible(void **p, int on)
{
    if (on == 1) {
        GFL_USE_PlaySeDefaultVolume(0x80D);
    } else {
        GFL_USE_StopSeSlot(2);
    }
    CLACT_SetActorDrawEnable(p[0], on);
    CLACT_SetActorDrawEnable(p[1], on);
}
