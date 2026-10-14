/*
 * function: POKETRADE_2D_DeleteOfferWindowActors
 * address: 0x021E6DEC
 * packet: pkt_ov119_021E6DEC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_Delete 0x020437AC arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
#include "../include/Obj05338.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
struct Obj020437AC;
extern void BMP_Delete(struct Obj020437AC *p);
extern void CLACT_ReleaseCharacter(unsigned int);
extern void CLACT_ReleasePalette(unsigned int);
extern void CLACT_ReleaseCellAnim(unsigned int);
void POKETRADE_2D_DeleteOfferWindowActors(int p) {
    int i;
    for (i=0;i<8;i++) {
        if (*(int *)(p+i*4+0x10cc)) {
            CLACT_DeleteActor((struct Obj *)(*(int *)(p+i*4+0x10cc)));
            *(int *)(p+i*4+0x10cc)=0;
            BMP_Delete(*(void **)(p+i*4+0x10f4));
            *(int *)(p+i*4+0x10f4)=0;
            CLACT_ReleaseCharacter(*(int *)(p+i*4+0x1114));
            *(int *)(p+i*4+0x1114)=0;
        }
    }
    if (((struct Obj05338 *)p)->f10EC) {CLACT_ReleasePalette(((struct Obj05338 *)p)->f10EC);((struct Obj05338 *)p)->f10EC=0;}
    if (((struct Obj05338 *)p)->f10EC) {CLACT_ReleaseCellAnim(((struct Obj05338 *)p)->f111C);((struct Obj05338 *)p)->f10EC=0;}
}
