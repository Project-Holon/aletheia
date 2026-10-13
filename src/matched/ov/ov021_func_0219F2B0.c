/*
 * function: FLDMMDL_DRAW_DrawDirAnimeSized
 * address:  0x0219F2B0
 * packet:   pkt_ov021_0219F2B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf callees now filed; formerly MATCH. Leaf sources verified from a scratch
 * file (region arm9, --arm, dsi/1.1p1 -O4,p; typedefs u8/u16/u32):
 *   BILLBOARD_ACT_SetEntryList:
 *   void BILLBOARD_ACT_SetEntryList(u8 *p, int i, u16 v)
 *   {
 *       u8 *e = *(u8 **)(p + 0x18) + i * 40;
 *       *(u16 *)(e + 0xe) = v;
 *       BILLBOARD_ACT_ResetPlayback(e);   // 0x020500A0: extern void (u8 *), arm
 *   }
 *   BILLBOARD_ACT_GetBoard:
 *   u32 BILLBOARD_ACT_GetBoard(u8 *p) { return *(u32 *)(p + 4); }
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
 *   BILLBOARD_ACT_SetEntryCursor  0x0205085C  arm
 *   FLDMMDL_DRAW_UpdateBlactFlags  0x021A000C  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05015.h"

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
extern u16 FLDMMDL_GetObjCode(void *p);
extern u8 *FLDMMDL_GetObjCodeParam(u32);

void FLDMMDL_DRAW_DrawDirAnimeSized(u32 a)
{
    s32 buf[3];
    u8 *q;
    u32 flag;
    u32 r;
    u32 f;
    u32 x;
    u32 k;
    u32 w;
    flag = 0;
    f = 0;
    q = (u8 *)FLDMMDL_GetDrawProcWork((void *)a);
    if (((struct Obj05015 *)q)->f0 != 0xFFFF) {
        r = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(a));
        x = FLDMMDL_DRAW_GetDirIndex(a);
        if (FLDMMDL_GetObjCode((void *)a) == 0xCC) {
            f = 1;
        }
        k = FLDMMDL_GetObjCodeParam(a)[3];
        if (k == 0xF) {
            k = 4;
        } else if (k == 5) {
            k = 8;
        } else {
            k = 0x10;
        }
        w = (u16)(k + x);
        if (q[4] != x) {
            q[4] = x;
            BILLBOARD_ACT_SetEntryList((void *)r, ((struct Obj05015 *)q)->f0, w);
            flag = 1;
        }
        FLDMMDL_DRAW_UpdateBlactFlags(a, r, ((struct Obj05015 *)q)->f0, flag, f);
    FLDMMDL_ACMD_GetDrawPos((u8 *)a, buf);
    FLDMMDL_DRAW_AddHeightOffset(a, (u32 *)buf);
    r = BILLBOARD_ACT_GetBoard((u32 *)r);
    BILLBOARD_SetElemPos((u8 *)r, ((struct Obj05015 *)q)->f0, (struct Trip *)buf);
    }
}
