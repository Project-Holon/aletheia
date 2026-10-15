/*
 * function: UN_SELECT_LoadActors
 * address: 0x021BA290
 * packet: pkt_ov218_021BA290
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: ABF0's legacy void return forwards AC18, whose matched full body returns its slot index; caller stores r0. 49238 visibly receives archive r0, preserved despite legacy void prototype.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj00243.h"
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
void UN_SELECT_LoadActors(char *ctx)
{
    unsigned short heap = ((struct Obj00243 *)ctx)->f0;
    void *archive;
    *(int *)&((struct Obj00243 *)ctx)->f2D0 = -1;
    *(int *)&((struct Obj00243 *)ctx)->f2D4 = -1;
    *(int *)&((struct Obj00243 *)ctx)->f2D8 = -1;
    archive = func_020490F4(193, heap);
    *(int *)&((struct Obj00243 *)ctx)->f2D0 = CLACT_RegisterCharacter((void *)((unsigned)archive), 10, 0, 2, heap);
    *(int *)&((struct Obj00243 *)ctx)->f2D4 = CLACT_RegisterPalette((void *)archive, 11, 2, 96, heap);
    *(int *)&((struct Obj00243 *)ctx)->f2D8 = CLACT_RegisterCellAnim((void *)((unsigned)archive), 9, 8, heap);
    ARC_TOOL_DeleteHandle(archive);
}
