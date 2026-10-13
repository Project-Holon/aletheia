/*
 * function: func_021B7968
 * address: 0x021B7968
 * packet: pkt_ov173_021B7968
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`off = 0x114;` before `off = 0x1b8;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * symbols:
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 */
#include "../include/Obj03857.h"
#include "../include/Obj24182.h"
#include "../include/Obj24183.h"
#include "../include/Obj24184.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 WAZA_TOOL_GetParam(u16, u32);
void func_021B7968(char *p)
{
    u16 rect[2];
    u32 off;
    u32 i;
    u32 value;
    off = 0x1b8;
    for (i = 0; i < 4; i++) {
        rect[0] = 0x2f;
        rect[1] = i * 24 + 0x50;
        CLACT_AddActorSurfacePos(*(void **)(p + i * 4 + 0x114), (const struct Vec2 *)rect, 1);
        if (((struct Obj24182 *)(*(char * *)&((struct Obj03857 *)p)->f0))->f16 + i >= *(u8 *)(p + off)) {
            CLACT_SetActorDrawEnable(*(void **)(p + i * 4 + 0x114), 0);
        } else {
            value = WAZA_TOOL_GetParam(*(u16 *)(*(char * *)&((struct Obj24183 *)(*(char * *)&((struct Obj03857 *)p)->f0))->f10 + (((struct Obj24184 *)(*(char * *)&((struct Obj03857 *)p)->f0))->f16 + i) * 2), 0);
            CLACT_SetActorDrawEnable(*(void **)(p + i * 4 + 0x114), 1);
            CLACT_SetActorAnimSeq(*(void **)(p + i * 4 + 0x114), value);
        }
    }
}
