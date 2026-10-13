/*
 * function: FLDMMDL_DRAW_GetBlactAnimeTypeB
 * address:  0x0219FCC0
 * packet:   pkt_ov021_0219FCC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked at MATCH: BILLBOARD_ACT_GetEntryList (0x02050848), BILLBOARD_ACT_GetEntryCursor (0x02050880) is an unlabelled arm9 leaf
 * (the integrator's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u16 BILLBOARD_ACT_GetEntryList(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0xe); }  (EXACT, verified)
 *   u16 BILLBOARD_ACT_GetEntryCursor(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x10); }  (EXACT, verified)
 *
 * symbols:
 *   BILLBOARD_ACT_GetEntryList  0x02050848  arm
 *   BILLBOARD_ACT_GetEntryCursor  0x02050880  arm
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 *   FLDMMDL_GetBlActCont  0x0216D910  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u16 FLDMMDL_GetObjCode(void *p);
extern void *FLDMMDL_GetDrawProcWork(void *p);
extern int FLDMMDL_GetBlActCont(int a0);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern u16 BILLBOARD_ACT_GetEntryList(u8 *p, int i);
extern u16 BILLBOARD_ACT_GetEntryCursor(u8 *p, int i);

int FLDMMDL_DRAW_GetBlactAnimeTypeB(u32 a, u16 *o1, u16 *o2)
{
    u16 *p;
    u32 h;

    if ((u16)(FLDMMDL_GetObjCode((void *)a) + 0xFF23) <= 1) {
        p = FLDMMDL_GetDrawProcWork((void *)a);
        if (*p != 0xFFFF) {
            h = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(a));
            *o1 = BILLBOARD_ACT_GetEntryList((u8 *)h, *p);
            *o2 = BILLBOARD_ACT_GetEntryCursor((u8 *)h, *p);
            return 1;
        }
        return 0;
    }
    *o1 = 0;
    *o2 = 0;
    return 1;
}
