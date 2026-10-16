/*
 * function: ZUKAN_INFO_ReleaseGfx
 * address: 0x021BB214
 * packet: pkt_ov206_021BB214
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
#include "../include/Obj10887.h"
typedef unsigned int   u32;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
void ZUKAN_INFO_ReleaseGfx(char *p, int i)
{
    char *s = p + i * 4;
    CLACT_ReleasePalette((u32)(((struct Obj10887 *)s)->f9C));
    CLACT_ReleaseCharacter((u32)(((struct Obj10887 *)s)->f94));
    CLACT_ReleaseCellAnim((u32)(((struct Obj10887 *)s)->fA4));
}
