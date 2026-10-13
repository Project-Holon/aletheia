/*
 * function: FLDMMDL_DRAW_DrawStatic
 * address:  0x0219F750
 * packet:   pkt_ov021_0219F750
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked at MATCH: BILLBOARD_ACT_GetBoard (0x02050080), BILLBOARD_ACT_SetEntryList (0x0205082C) is an unlabelled arm9 leaf
 * (the integrator's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u32 BILLBOARD_ACT_GetBoard(u32 *p) { return p[1]; }  (EXACT as arm9 leaf, verified)
 *   void BILLBOARD_ACT_SetEntryList(u8 *p, int i, u16 h): strh into the record at +0xE, then tail-calls BILLBOARD_ACT_ResetPlayback (bx ip, pool 0x020500A0); not compiled here
 *
 * symbols:
 *   BILLBOARD_SetElemPos  0x0204F638  arm
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   BILLBOARD_ACT_SetEntryCursor  0x0205085C  arm
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 *   FLDMMDL_GetBlActCont  0x0216D910  thumb  ov010
 *   FLDMMDL_ACMD_GetDrawPos  0x02197CCC  thumb  ov021
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   FLDMMDL_DRAW_AddHeightOffset  0x0219FFBC  thumb  ov021
 *   FLDMMDL_DRAW_GetDirIndex  0x0219FFD4  thumb  ov021
 *   FLDMMDL_DRAW_UpdateBlactFlags  0x021A000C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Trip;
extern void *FLDMMDL_GetDrawProcWork(void *p);
extern int FLDMMDL_GetBlActCont(int a0);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern void FLDMMDL_DRAW_AddHeightOffset(u32, u32 *);
extern void FLDMMDL_ACMD_GetDrawPos(u8 *p, s32 *out);
extern void FLDMMDL_DRAW_UpdateBlactFlags(u32, u32, u32, u32, u32);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern void BILLBOARD_SetElemPos(u8 *a0, int i, struct Trip *src);
extern u32 FLDMMDL_DRAW_GetDirIndex(u32);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);
extern void BILLBOARD_ACT_SetEntryCursor(void *p, int idx, u32 v);

void FLDMMDL_DRAW_DrawStatic(u32 a)
{
    u16 *p;
    u32 buf[3];
    u32 h;
    u32 v;

    p = FLDMMDL_GetDrawProcWork((void *)a);
    if (*p != 0xFFFF) {
        h = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(a));
        v = FLDMMDL_DRAW_GetDirIndex(a);
        if (((u8 *)p)[4] != v) {
            BILLBOARD_ACT_SetEntryList((void *)h, *p, v);
            BILLBOARD_ACT_SetEntryCursor((void *)h, *p, 0);
            ((u8 *)p)[4] = v;
        }
        FLDMMDL_DRAW_UpdateBlactFlags(a, h, *p, 0, 0);
        FLDMMDL_ACMD_GetDrawPos((u8 *)a, (s32 *)buf);
        FLDMMDL_DRAW_AddHeightOffset(a, buf);
        BILLBOARD_SetElemPos((u8 *)BILLBOARD_ACT_GetBoard((u32 *)h), *p, (struct Trip *)buf);
    }
}
