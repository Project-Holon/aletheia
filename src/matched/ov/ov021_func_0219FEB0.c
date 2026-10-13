/*
 * function: FLDMMDL_DRAW_UpdateDirAnime
 * address:  0x0219FEB0
 * packet:   pkt_ov021_0219FEB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   FLDMMDL_GetDrawStatus  0x0216D678  thumb  ov010
 *   FLDMMDL_DRAW_GetDirIndex  0x0219FFD4  thumb  ov021
 *   FLDMMDL_DRAW_UpdateBlactFlags  0x021A000C  thumb  ov021
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   BILLBOARD_ACT_SetEntryCursor  0x0205085C  arm
 *   BILLBOARD_ACT_GetEntryCursor  0x02050880  arm
 *   gMmdlDrawRestFrames  0x021D8548  data  ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct { u8 b[4]; } U8x4;

extern const U8x4 gMmdlDrawRestFrames;

extern u16 FLDMMDL_GetDrawStatus(void *p);
extern u32 FLDMMDL_DRAW_GetDirIndex(u32);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);
extern void BILLBOARD_ACT_SetEntryCursor(void *p, int idx, u32 v);
extern u16 BILLBOARD_ACT_GetEntryCursor(u8 *p, int i);
extern void FLDMMDL_DRAW_UpdateBlactFlags(u32, u32, u32, u32, u32);

void FLDMMDL_DRAW_UpdateDirAnime(u8 *s, u32 a, u32 r, u16 id)
{
    U8x4 tbl;
    u32 flag;
    u16 k;
    u32 y;
    u32 x;

    flag = 0;
    y = FLDMMDL_DRAW_GetDirIndex(a);
    x = FLDMMDL_GetDrawStatus((void *)a);
    k = y + x * 4;
    if (s[3] != 0 && x == s[1])
        s[3] = flag;
    if (y != s[0]) {
        flag = 1;
        s[1] = x;
        s[0] = y;
        s[2] = 0;
        BILLBOARD_ACT_SetEntryList((void *)r, id, k);
    } else if (x != s[1]) {
        flag = 1;
        if (x == 0) {
            if (s[1] == 0) {
                BILLBOARD_ACT_SetEntryList((void *)r, id, k);
                s[1] = x;
                s[3] = 0;
            } else {
                if (s[3] == 0) {
                    s[3]++;
                    flag = 0;
                    goto tail;
                }
                tbl = gMmdlDrawRestFrames;
                s[2] = BILLBOARD_ACT_GetEntryCursor((u8 *)r, id);
                if (s[2] >= 4)
                    s[2] = 0;
                s[2] = tbl.b[s[2]];
                BILLBOARD_ACT_SetEntryList((void *)r, id, k);
                s[1] = x;
                s[3] = 0;
            }
        } else {
            if (s[1] != 0) {
                s[2] = BILLBOARD_ACT_GetEntryCursor((u8 *)r, id);
                s[2] = (s[2] >= 2) ? 0 : 2;
            }
            BILLBOARD_ACT_SetEntryList((void *)r, id, k);
            BILLBOARD_ACT_SetEntryCursor((void *)r, id, s[2]);
            s[1] = x;
            s[3] = 0;
        }
    }
tail:
    FLDMMDL_DRAW_UpdateBlactFlags(a, r, id, flag, 0);
}
