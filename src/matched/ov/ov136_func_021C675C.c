/*
 * function: MB_SEQ_RegisterSystemActorResources
 * address: 0x021C675C
 * packet: pkt_ov136_021C675C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02027698 0x02027698 thumb
 *   func_0202769C 0x0202769C thumb
 *   func_020276A0 0x020276A0 thumb
 *   func_0201BC3C 0x0201BC3C thumb
 */
#include "../include/Obj14192.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 func_020275E4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02027698(void);
extern int CLACT_RegisterCharacter(void *, u32, u32, u32, u16);
extern int func_0201BC3C(void);
extern int CLACT_RegisterPalette(void *, u32, u32, u32, u16);
extern u32 func_0202769C(u32);
extern u32 func_020276A0(u32);
extern int CLACT_RegisterCellAnim(void *, u32, u32, u32);
extern void ARC_TOOL_DeleteHandle(void *);
void MB_SEQ_RegisterSystemActorResources(u8 *p)
{
    void *arc;
    u32 i;
    u32 first;
    arc = func_020490F4(func_020275E4(), 102);
    for (i = 0; i <= 2; i++)
        *(u32 *)(p + 0x210 + i * 4) = CLACT_RegisterCharacter(arc, func_02027698(), 0, 1, 102);
    ((struct Obj14192 *)p)->f230 = CLACT_RegisterPalette(arc, func_0201BC3C(), 1, 0, 102);
    first = func_0202769C(0);
    ((struct Obj14192 *)p)->f250 = CLACT_RegisterCellAnim(arc, first, func_020276A0(0), 102);
    ARC_TOOL_DeleteHandle(arc);
}
