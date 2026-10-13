/*
 * function: func_02205070
 * address:  0x02205070
 * packet:   pkt_02205070
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208C4C 0x02208C4C data a4
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02205A28 0x02205A28 thumb ov195
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
#include "../include/Obj01971.h"
#include "../include/Obj14528.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 d_02208C4C[];
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern int func_02205A28(char *a);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *, u32);

void func_02205070(int a, char *b)
{
    void *h;
    u8 i;
    int z;

    h = func_020490F4(0xb6, ((struct Obj01971 *)b)->f2);
    i = 0;
    ((struct Obj01971 *)b)->f40 = CLACT_RegisterPaletteEx(h, 3, 0, 0, i, 1, ((struct Obj01971 *)b)->f2);
    ((struct Obj01971 *)b)->f3C = CLACT_RegisterCharacter(h, 2, 0, 0, ((struct Obj01971 *)b)->f2);
    ((struct Obj01971 *)b)->f44 = CLACT_RegisterCellAnim(h, 1, 0, ((struct Obj01971 *)b)->f2);
    ARC_TOOL_DeleteHandle(h);
    for (z = i; i < 6; i++) {
        char *e = b + i * 4;
        ((struct Obj14528 *)e)->f48 = (u32)CLACT_CreateActor((void *)func_02205A28((char *)(((struct Obj01971 *)b)->f4)), ((struct Obj01971 *)b)->f3C, ((struct Obj01971 *)b)->f40,
                                           ((struct Obj01971 *)b)->f44, d_02208C4C + i * 8, z, ((struct Obj01971 *)b)->f2);
        CLACT_SetActorAutoAnim((struct Obj *)((struct Obj14528 *)e)->f48, z);
    }
    ((struct Obj01971 *)b)->f60 = 1;
}
