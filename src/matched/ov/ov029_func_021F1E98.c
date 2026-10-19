/*
 * function: C_GEAR_DeleteActors
 * address:  0x021F1E98
 * packet:   pkt_ov029_021F1E98
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   C_GEAR_DeleteBarActors  0x021F1DB0  thumb  ov029
 *   C_GEAR_DeleteSplashActors  0x021F1BBC  thumb  ov029
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   BG_SYS_FreeTileRun  0x0203FB44  arm
 */
#include "../include/Obj02111.h"

typedef unsigned int   u32;
extern void C_GEAR_DeleteBarActors(char *p);
extern void C_GEAR_DeleteSplashActors(char *p);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);

void C_GEAR_DeleteActors(char *p)
{
    int i;
    int *q;
    unsigned int v;

    C_GEAR_DeleteBarActors(p);
    C_GEAR_DeleteSplashActors(p);
    for (i = 0; i < 11; i++) {
        q = (int *)(p + i * 4);
        if (q[0x4b] != 0) {
            CLACT_DeleteActor((struct Obj *)q[0x4b]);
            q[0x4b] = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        q = (int *)(p + i * 4);
        if (q[0x56] != 0) {
            CLACT_DeleteActor((struct Obj *)q[0x56]);
            q[0x56] = 0;
        }
    }
    for (i = 0; i < 20; i++) {
        q = (int *)(p + i * 12);
        if (q[0xf] != 0) {
            CLACT_DeleteActor((struct Obj *)q[0xf]);
            q[0xf] = 0;
        }
    }
    CLACT_ReleaseCellAnim(((struct Obj02111 *)p)->f30);
    CLACT_ReleaseCharacter(((struct Obj02111 *)p)->f2C);
    CLACT_ReleasePalette(((struct Obj02111 *)p)->f28);
    v = ((struct Obj02111 *)p)->f14;
    BG_SYS_FreeTileRun((int)6, (unsigned short)v, (unsigned short)(v >> 16));
}
