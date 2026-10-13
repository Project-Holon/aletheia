/*
 * function: FLDMMDL_DRAW_DrawWalkAnimeB
 * address:  0x0219F3F0
 * packet:   pkt_ov021_0219F3F0
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
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 *   FLDMMDL_GetBlActCont  0x0216D910  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   FLDMMDL_ACMD_GetDrawPos  0x02197CCC  thumb  ov021
 *   FLDMMDL_DRAW_AddHeightOffset  0x0219FFBC  thumb  ov021
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_SetElemPos  0x0204F638  arm
 *   FLDMMDL_GetDrawStatus  0x0216D678  thumb  ov010
 *   FLDMMDL_DRAW_GetDirIndex  0x0219FFD4  thumb  ov021
 *   FLDMMDL_DRAW_UpdateDirAnime  0x0219FEB0  thumb  ov021
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   FLDMMDL_DRAW_UpdateBlactFlags  0x021A000C  thumb  ov021
 *   BILLBOARD_ACT_SetEntryCursor  0x0205085C  arm  arm9
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03121.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct Trip;
extern void *FLDMMDL_GetDrawProcWork(void *p);
extern int FLDMMDL_GetBlActCont(int a0);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern void FLDMMDL_ACMD_GetDrawPos(u8 *p, s32 *out);
extern void FLDMMDL_DRAW_AddHeightOffset(u32 a, u32 *p);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern void BILLBOARD_SetElemPos(u8 *a0, int i, struct Trip *src);
extern u16 FLDMMDL_GetDrawStatus(void *p);
extern u32 FLDMMDL_DRAW_GetDirIndex(u32);
extern void FLDMMDL_DRAW_UpdateDirAnime(u8 *s, u32 a, u32 r, u16 id);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);
extern void BILLBOARD_ACT_SetEntryCursor(void *p, int idx, u32 v);
extern void FLDMMDL_DRAW_UpdateBlactFlags(u32, u32, u32, u32, u32);

void FLDMMDL_DRAW_DrawWalkAnimeB(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 r;
    u32 x;
    u32 y;
    q = (u8 *)FLDMMDL_GetDrawProcWork((void *)a);
    if (((struct Obj03121 *)q)->f0 != 0xFFFF) {
        r = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(a));
        x = FLDMMDL_GetDrawStatus((void *)a);
        if (x >= 10) {
            y = FLDMMDL_DRAW_GetDirIndex(a);
            if (x != q[5]) {
                q[4] = y;
                q[5] = x;
                q[6] = 0;
                BILLBOARD_ACT_SetEntryList((void *)r, ((struct Obj03121 *)q)->f0, (u16)(x + 0x1e));
            }
            FLDMMDL_DRAW_UpdateBlactFlags(a, r, ((struct Obj03121 *)q)->f0, 1, 0);
        } else {
            FLDMMDL_DRAW_UpdateDirAnime((u8 *)((u16 *)(q + 4)), a, r, ((struct Obj03121 *)q)->f0);
        }
    FLDMMDL_ACMD_GetDrawPos((u8 *)a, buf);
    FLDMMDL_DRAW_AddHeightOffset(a, (u32 *)buf);
    r = BILLBOARD_ACT_GetBoard((u32 *)r);
    BILLBOARD_SetElemPos((u8 *)r, ((struct Obj03121 *)q)->f0, (struct Trip *)buf);
    }
}
