/*
 * function: UNION_SUBDISP_ScrollChatLines
 * address:  0x021F0AA0
 * packet:   pkt_ov031_021F0AA0
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_SUBDISP_MoveChatLine  0x021F0A04  thumb  ov031
 *   UNION_CHAT_LOG_GetLine  0x021BBC2C  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   UNION_SUBDISP_DrawChatLine  0x021F07AC  thumb  ov031
 *   sUnionSubdispEmptyStr     0x021F10D0  data  a4
 *
 * `long i` keeps `i = n` from being copy-propagated into the first loop's
 * entry guard (with `int i` the guard tests a spare copy of n, +2 bytes);
 * `j++`/`j--` in the loop body rather than the for header gives i r7 and j r5
 * (the comma form swaps them in both first loops).
 */
#include "../include/Obj07626.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void UNION_SUBDISP_MoveChatLine(void *a, u8 i, u8 j, char *b, int d);
extern void *UNION_CHAT_LOG_GetLine(void *r, int i);
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Obj;
extern void UNION_SUBDISP_DrawChatLine(struct Obj *p, const u8 *e, u8 k);
extern const char sUnionSubdispEmptyStr[];

void UNION_SUBDISP_ScrollChatLines(void *a, char *b, int n)
{
    long i;
    int j;
    void *e;

    if (n > 0) {
        for (i = n, j = 0; i < 3; i++) {
            UNION_SUBDISP_MoveChatLine(a, i, j, b, ((struct Obj07626 *)b)->f440 - n);
            j++;
        }
        for (j = 3 - n; j < 3; j++) {
            e = UNION_CHAT_LOG_GetLine(b, ((struct Obj07626 *)b)->f440 - 2 + j);
            if (e == 0)
                func_02034714(sUnionSubdispEmptyStr, 0, sUnionSubdispEmptyStr);
            UNION_SUBDISP_DrawChatLine(a, e, (u8)j);
        }
    } else {
        for (i = n + 2, j = 2; i > -1; i--) {
            UNION_SUBDISP_MoveChatLine(a, i, j, b, ((struct Obj07626 *)b)->f440 - n);
            j--;
        }
        for (j = -1 - n; j > -1; j--) {
            e = UNION_CHAT_LOG_GetLine(b, ((struct Obj07626 *)b)->f440 - 2 + j);
            if (e == 0)
                func_02034714(sUnionSubdispEmptyStr, 0, sUnionSubdispEmptyStr);
            UNION_SUBDISP_DrawChatLine(a, e, (u8)j);
        }
    }
}
