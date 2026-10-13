/*
 * function: UNION_SUBDISP_DrawVisibleChatLines
 * address:  0x021F09A0
 * packet:   pkt_ov031_021F09A0
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_CHAT_LOG_GetLine  0x021BBC2C  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   UNION_SUBDISP_DrawChatLine  0x021F07AC  thumb  ov031
 *   sUnionSubdispEmptyStr     0x021F10D0  data  a4
 */
#include "../include/Obj20406.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *UNION_CHAT_LOG_GetLine(void *r, int i);
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Obj;
extern void UNION_SUBDISP_DrawChatLine(struct Obj *p, const u8 *e, u8 k);
extern const char sUnionSubdispEmptyStr[];

void UNION_SUBDISP_DrawVisibleChatLines(void *a, char *b)
{
    int k;
    int i = ((struct Obj20406 *)b)->f440;
    int lo = i - 3;
    void *e;

    if (lo < 0)
        lo = -1;
    k = i - lo - 1;
    for (; i > lo; i--, k--) {
        e = UNION_CHAT_LOG_GetLine(b, i);
        if (e == 0)
            func_02034714(sUnionSubdispEmptyStr, 0, sUnionSubdispEmptyStr);
        if (k <= -1)
            func_02034714(sUnionSubdispEmptyStr, 0, sUnionSubdispEmptyStr);
        UNION_SUBDISP_DrawChatLine(a, e, (u8)k);
    }
}
