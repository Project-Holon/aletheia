/*
 * function: func_021E7B68
 * address: 0x021E7B68
 * packet: pkt_ov177_021E7B68
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   d_021E8CBE 0x021E8CBE data a1
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 */
#include "../include/Obj03873.h"
typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern void *CLACT_CreateActor(unsigned, unsigned, unsigned, unsigned, const Request *, unsigned short, unsigned);
typedef signed int     s32;
typedef unsigned int   u32;
struct Obj;
extern int func_021E5978(int *p, int i);
extern unsigned func_021E7CF0(void *, unsigned short, unsigned short);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleaseCellAnim(unsigned);
extern void CLACT_ReleasePalette(unsigned);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern unsigned CLACT_RegisterPaletteEx(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern unsigned CLACT_RegisterCharacter(void *, unsigned, unsigned, unsigned, unsigned);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern const unsigned char d_021E8CBE[];
void func_021E7B68(char *p, unsigned idx, unsigned owner, unsigned heap)
{
    void *handle;
    Request req;
    handle = func_020490F4(0x20, heap);
    ((struct Obj03873 *)p)->f80 = CLACT_RegisterPaletteEx(handle, 0, 0, 0x140, d_021E8CBE[idx], 1, heap);
    ((struct Obj03873 *)p)->f82 = CLACT_RegisterCharacter(handle, idx + 0x31, 0, 0, heap);
    ((struct Obj03873 *)p)->f84 = CLACT_RegisterCellAnim(handle, 0x41, 0x42, heap);
    ARC_TOOL_DeleteHandle(handle);
    MI_CpuFill8(&req, 0, 8);
    req.x = 0x120;
    req.y = 0x2c;
    ((struct Obj03873 *)p)->f64 = CLACT_CreateActor(owner, ((struct Obj03873 *)p)->f82, ((struct Obj03873 *)p)->f80, ((struct Obj03873 *)p)->f84, &req, 0, heap);
    CLACT_SetActorPaletteOffset(((struct Obj03873 *)p)->f64, 0, 1);
}
