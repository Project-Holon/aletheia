/*
 * function: CG_HELP_UpdatePageGraphics
 * address: 0x021D49C8
 * packet: pkt_ov124_021D49C8
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the two-halfword delta is a struct assignment; field stores differ by 13 bytes.
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_02030734 0x02030734 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 *   gCgHelpPageAnimSeq 0x021D4CF4 data a4
 *   gCgHelpPageCharOffset 0x021D4CA4 data a4
 *   gCgHelpFileName 0x021D4D4C data a1
 *   gCgHelpPageTileBase 0x021D4C04 data a4
 *   gCgHelpActorOffset 0x021D4BE0 data a2
 */
#include "../include/Obj00122.h"
#include "../include/Obj22993.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct { s16 x, y; } Vec;
extern const u32 gCgHelpPageAnimSeq[], gCgHelpPageCharOffset[], gCgHelpPageTileBase[];
extern const char gCgHelpFileName[];
extern const Vec gCgHelpActorOffset;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern int func_02061CA4(void *, u32, u32, int);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void BG_SYS_DrawTile(u32, u32, u32, u32, u8, u8);
extern u32 func_020307B0(void *p);
extern void BG_SYS_PushTile(u32);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
void CG_HELP_UpdatePageGraphics(char *p, u32 n)
{
    u16 *q;
    u8 i, j;
    Vec delta;
    CLACT_SetActorAnimSeq(((struct Obj00122 *)p)->f5C, gCgHelpPageAnimSeq[n]);
    CLACT_SetActorDrawEnable(((struct Obj00122 *)p)->f5C, 1);
    if (n <= 7) {
        func_02061CA4((void *)31, 320, (u32)(*(char * *)&((struct Obj22993 *)(*(char * *)&((struct Obj00122 *)p)->f48))->fC + gCgHelpPageCharOffset[n] * 32), 32);
        q = func_02030734(((struct Obj00122 *)p)->f0, 32, 1, gCgHelpFileName, 0x2ac);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                q[i * 4 + j] = j + gCgHelpPageTileBase[n] + i * 32 + 0xa000;
            }
        }
        BG_SYS_DrawTile(4, (u32)q, 2, 4, 4, 4);
        func_020307B0(q);
    } else {
        q = func_02030734(((struct Obj00122 *)p)->f0, 32, 1, gCgHelpFileName, 0x2bb);
        BG_SYS_DrawTile(4, (u32)q, 2, 4, 4, 4);
        func_020307B0(q);
    }
    BG_SYS_PushTile(4);
    delta = gCgHelpActorOffset;
    CLACT_AddActorSurfacePos(((struct Obj00122 *)p)->f5C, (const struct Vec2 *)(&delta), 1);
    if (n == 10) {
        CLACT_SetActorAutoAnim(((struct Obj00122 *)p)->f5C, 0);
        CLACT_SetActorAnimIndex((int)(((struct Obj00122 *)p)->f5C), 1);
    } else if (n == 11) {
        CLACT_SetActorAutoAnim(((struct Obj00122 *)p)->f5C, 0);
        CLACT_SetActorAnimIndex((int)(((struct Obj00122 *)p)->f5C), 0);
    } else {
        CLACT_SetActorAutoAnim(((struct Obj00122 *)p)->f5C, 1);
    }
}
