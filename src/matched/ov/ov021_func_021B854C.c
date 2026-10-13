/*
 * function: FIELD_RAIL_WORK_TryEnterLine
 * address:  0x021B854C
 * packet:   pkt_ov021_021B854C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * closed 2026-09-27 (tree_ov018): the early exit is one guard,
 * if (arg4 < arg6 && arg4 >= 0) goto tail; ahead of a plain if/else for the
 * two row lookups, and arg6 is reassigned in place of a separate m local.
 * symbols:
 *   FIELD_RAIL_IsLocationInLine  0x021B95C0  thumb
 *   FIELD_RAIL_SETTING_GetPoint  0x021B87D8  thumb
 *   FIELD_RAIL_POINT_FindLine  0x021B8514  thumb
 *   FIELD_RAIL_KEY_Opposite  0x021B93D4  thumb
 *   FIELD_RAIL_LINE_GetLength  0x021B9278  thumb
 *   FIELD_RAIL_LINE_GetWidthAt  0x021B9280  thumb
 *   FIELD_RAIL_WORK_EnterLine  0x021B8658  thumb
 *   FIELD_RAIL_LINE_IsConsistent  0x021B963C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00010.h"
#include "../include/Obj02052.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int FIELD_RAIL_IsLocationInLine(u8 *p, u8 *q, int a3, int a4, u8 *sr, u32 a6);
u8 *FIELD_RAIL_SETTING_GetPoint(u8 *p, u32 idx);
u8 *FIELD_RAIL_POINT_FindLine(u8 *p, u32 v, u8 *q, u16 *r, int flag);
int FIELD_RAIL_KEY_Opposite(int dir);
int FIELD_RAIL_LINE_GetLength(u32 a, u32 b, u32 c);
int FIELD_RAIL_LINE_GetWidthAt(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
void FIELD_RAIL_WORK_EnterLine(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
int FIELD_RAIL_LINE_IsConsistent(u8 *a, u8 *b);

int FIELD_RAIL_WORK_TryEnterLine(u8 *p, u8 *a, u32 arg3, int arg4, int arg5, int arg6, int arg7)
{
    int res;

    if (FIELD_RAIL_IsLocationInLine(*(u8 * *)&((struct Obj00010 *)p)->f28, a, arg4, arg5,
                      *(u8 * *)&((struct Obj00010 *)p)->f24, *(u32 *)&((struct Obj00010 *)p)->f1C) == 0)
        return 0;
    if ((arg5 < 0 ? -arg5 : arg5) > arg7)
        return 0;
    if (arg4 < arg6 && arg4 >= 0)
        goto tail;
    if (arg4 >= arg6) {
        u8 *row = FIELD_RAIL_SETTING_GetPoint(*(u8 * *)&((struct Obj00010 *)p)->f24, ((struct Obj02052 *)a)->f4);
        res = (int)FIELD_RAIL_POINT_FindLine(row, ((struct Obj02052 *)a)->f8,
                                  *(u8 * *)&((struct Obj00010 *)p)->f24, *(u16 * *)&((struct Obj00010 *)p)->f28, 1);
    } else {
        u8 *row = FIELD_RAIL_SETTING_GetPoint(*(u8 * *)&((struct Obj00010 *)p)->f24, ((struct Obj02052 *)a)->f0);
        res = (int)FIELD_RAIL_POINT_FindLine(row, FIELD_RAIL_KEY_Opposite(((struct Obj02052 *)a)->f8),
                                  *(u8 * *)&((struct Obj00010 *)p)->f24, *(u16 * *)&((struct Obj00010 *)p)->f28, 1);
    }
    if (res == 0) {
        if (arg4 > arg6)
            return 0;
        goto tail;
    }
    a = (u8 *)res;
    if (arg4 >= arg6) {
        arg4 -= arg6;
        arg6 = FIELD_RAIL_LINE_GetLength(res, *(u32 *)&((struct Obj00010 *)p)->f1C, *(u32 *)&((struct Obj00010 *)p)->f24);
        arg7 = (u32)FIELD_RAIL_LINE_GetWidthAt((u8 *)res, arg4, arg6, *(u8 * *)&((struct Obj00010 *)p)->f24);
    } else if (arg4 < 0) {
        arg6 = FIELD_RAIL_LINE_GetLength(res, *(u32 *)&((struct Obj00010 *)p)->f1C, *(u32 *)&((struct Obj00010 *)p)->f24);
        arg4 += arg6;
        arg7 = (u32)FIELD_RAIL_LINE_GetWidthAt((u8 *)res, arg4, arg6, *(u8 * *)&((struct Obj00010 *)p)->f24);
    }
    if (arg4 >= arg6)
        return 0;
    if ((arg5 < 0 ? -arg5 : arg5) > (int)arg7)
        return 0;
tail:
    FIELD_RAIL_WORK_EnterLine(p, (u32)a, arg3, arg4, arg5, arg6, (int)arg7);
    FIELD_RAIL_LINE_IsConsistent(a, *(u8 * *)&((struct Obj00010 *)p)->f24);
    return arg3;
}
