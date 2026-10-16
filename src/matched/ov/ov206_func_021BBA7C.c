/*
 * function: ZUKAN_INFO_DeleteFormGfx
 * address: 0x021BBA7C
 * packet: pkt_ov206_021BBA7C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_INFO_DeleteActorPair 0x021BBBD8 thumb
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 */
#include "../include/Obj00173.h"
struct S;
extern void ZUKAN_INFO_DeleteActorPair(struct S *p, int i);
typedef unsigned int   u32;
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleasePalette(u32 i);
void ZUKAN_INFO_DeleteFormGfx(char *p)
{
    unsigned char i;
    for (i = 0; i < 2; i++) {
        ZUKAN_INFO_DeleteActorPair((struct S *)p, i);
    }
    CLACT_ReleaseCellAnim((u32)(((struct Obj00173 *)p)->f184));
    CLACT_ReleaseCellAnim((u32)(((struct Obj00173 *)p)->f180));
    CLACT_ReleasePalette((u32)(((struct Obj00173 *)p)->f17C));
}
