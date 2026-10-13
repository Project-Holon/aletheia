/*
 * function: func_021E7464
 * address: 0x021E7464
 * packet: pkt_ov177_021E7464
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021E7CF0 0x021E7CF0 thumb ov177
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021E5978 0x021E5978 thumb ov177
 *   CLACT_CreateActor 0x0204B294 arm
 *   d_021E8CBE 0x021E8CBE data a1
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   CLACT_RegisterCharacter  0x0204A6C8  arm  arm9
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_RegisterCellAnim  0x0204AF28  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm  arm9
 */
#include "../include/Obj10710.h"
typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;
typedef unsigned short u16;

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
extern void *func_020490F4(u32 id, u32 heap);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern const unsigned char d_021E8CBE[];
void func_021E7464(char *p, char *desc, unsigned owner, void *table, unsigned heap)
{
    unsigned n, i, a, b, c;
    Request req;
    n = func_021E7CF0(((struct Obj10710 *)desc)->fC, ((struct Obj10710 *)desc)->f10, ((struct Obj10710 *)desc)->f12);
    MI_CpuFill8(&req, 0, 8);
    req.x = 0x100;
    req.y = 0x10;
    for (i = 0; i < n; i++) {
        req.x += 0x10;
        req.id = i + 2;
        a = func_021E5978(table, 3);
        b = func_021E5978(table, 1);
        c = func_021E5978(table, 5);
        *(void **)(p + i * 4 + 0x190) = CLACT_CreateActor(owner, a, b, c, &req, 1, heap);
    }
}
