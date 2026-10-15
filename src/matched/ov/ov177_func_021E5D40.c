/*
 * function: WIFIBATTLEMATCH_VIEW_DeleteMainWindow
 * address: 0x021E5D40
 * packet: pkt_ov177_021E5D40
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_DeleteActorFromInfo  0x021E74FC  thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DeletePokeActor  0x021E73B8  thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DeleteWindow  0x021E6EFC  thumb ov177
 *   func_020307B0  0x020307B0  arm
 */
extern void WIFIBATTLEMATCH_VIEW_DeleteActorFromInfo(char *p);
extern void WIFIBATTLEMATCH_VIEW_DeletePokeActor(char *p);
extern void WIFIBATTLEMATCH_VIEW_DeleteWindow(unsigned *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void WIFIBATTLEMATCH_VIEW_DeleteMainWindow(void *p)
{
    *(unsigned short *)0x04001050 = 0;
    WIFIBATTLEMATCH_VIEW_DeleteActorFromInfo(p);
    WIFIBATTLEMATCH_VIEW_DeletePokeActor(p);
    WIFIBATTLEMATCH_VIEW_DeleteWindow(p);
    func_020307B0(p);
}
