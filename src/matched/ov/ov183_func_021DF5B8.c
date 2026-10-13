/*
 * function: func_021DF5B8
 * address: 0x021DF5B8
 * packet: pkt_ov183_021DF5B8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021DF61E
 * lever: padded struct array members prevent caching the element cursor across calls.
 * symbols:
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj02522.h"
typedef unsigned short u16;
struct W { char pad[0x18]; u16 handles[5][6]; char gap[4]; void *objects[5][6]; };
extern void CLACT_ReleaseCellAnim(unsigned int);
extern void CLACT_ReleasePalette(unsigned int);
extern void CLACT_ReleaseCharacter(unsigned int);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void func_021DF5B8(char *p)
{
    int i, j;
    CLACT_ReleaseCellAnim(((struct Obj02522 *)p)->f16);
    CLACT_ReleasePalette(((struct Obj02522 *)p)->f14);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            if (((struct W *)p)->objects[i][j] != 0) {
                CLACT_ReleaseCharacter(((struct W *)p)->handles[i][j]);
                CLACT_DeleteActor(((struct W *)p)->objects[i][j]);
                ((struct W *)p)->objects[i][j] = 0;
            }
        }
    }
}
