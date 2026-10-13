/*
 * function: FLDMMDL_DRAW_DrawMultiPattern
 * address:  0x0219FB5C
 * packet:   pkt_ov021_0219FB5C
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
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_GetDrawStatus  0x0216D678  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   FLDMMDL_ACMD_GetDrawPos  0x02197CCC  thumb  ov021
 *   FLDMMDL_DRAW_AddHeightOffset  0x0219FFBC  thumb  ov021
 *   FLDMMDL_DRAW_GetDirIndex  0x0219FFD4  thumb  ov021
 *   FLDMMDL_DRAW_UpdateBlactFlags  0x021A000C  thumb  ov021
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_SetElemPos  0x0204F638  arm
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01496.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Trip;
extern void *FLDMMDL_GetDrawProcWork(void *p);
extern int FLDMMDL_GetBlActCont(int a0);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern u16 FLDMMDL_GetObjCode(void *p);
extern u16 FLDMMDL_GetDrawStatus(void *p);
extern u32 FLDMMDL_DRAW_GetDirIndex(u32);
extern void FLDMMDL_ACMD_GetDrawPos(u8 *p, s32 *out);
extern void FLDMMDL_DRAW_AddHeightOffset(u32 a, u32 *p);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern void BILLBOARD_SetElemPos(u8 *a0, int i, struct Trip *src);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);
extern void FLDMMDL_DRAW_UpdateBlactFlags(u32, u32, u32, u32, u32);

void FLDMMDL_DRAW_DrawMultiPattern(u32 a)
{
    s32 buf[3];
    u32 flag;
    u32 r;
    u32 x;
    u8 *q;
    u32 t;
    u32 y;
    u32 m;

    flag = 0;
    q = (u8 *)FLDMMDL_GetDrawProcWork((void *)a);
    if (((struct Obj01496 *)q)->f0 == 0xFFFF)
        return;
    r = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(a));
    t = FLDMMDL_GetObjCode((void *)a);
    x = FLDMMDL_GetDrawStatus((void *)a);
    if (t == 0xd3 || t == 0xd5 || t == 0x79) {
        m = 0;
        if (x == q[5])
            goto tail;
        switch (x) {
        case 10:
            m = 1;
            break;
        case 11:
            m = 2;
            break;
        case 12:
            m = 3;
            break;
        }
        q[5] = x;
        BILLBOARD_ACT_SetEntryList((void *)r, ((struct Obj01496 *)q)->f0, m);
        flag = 1;
    } else if (t == 0xd4 || t == 0xd6) {
        y = FLDMMDL_DRAW_GetDirIndex(a);
        m = 0;
        if (x < 10) {
            if (y == q[4] && x == q[5])
                goto tail;
            if (y == 0)
                m = 0;
            else if (y == 1)
                m = 1;
            q[4] = y;
        } else {
            if (x == q[5])
                goto tail;
            switch (x) {
            case 10:
                m = 2;
                break;
            case 11:
                m = 3;
                break;
            }
        }
        q[5] = x;
        BILLBOARD_ACT_SetEntryList((void *)r, ((struct Obj01496 *)q)->f0, m);
        flag = 1;
    } else {
        if (x == q[5])
            goto tail;
        q[5] = x;
        BILLBOARD_ACT_SetEntryList((void *)r, ((struct Obj01496 *)q)->f0, flag);
        flag = 1;
    }
tail:
    FLDMMDL_DRAW_UpdateBlactFlags(a, r, ((struct Obj01496 *)q)->f0, flag, 1);
    FLDMMDL_ACMD_GetDrawPos((u8 *)a, buf);
    FLDMMDL_DRAW_AddHeightOffset(a, (u32 *)buf);
    BILLBOARD_SetElemPos((u8 *)BILLBOARD_ACT_GetBoard((u32 *)r), ((struct Obj01496 *)q)->f0, (struct Trip *)buf);
}
