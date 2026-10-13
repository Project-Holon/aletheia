/*
 * function: FLDMMDL_DRAW_ResetBlactAnime
 * address:  0x0219FE64
 * packet:   pkt_ov021_0219FE64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   FLDMMDL_GetBlActCont  0x0216D910  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   BILLBOARD_ACT_SetEntryCursor  0x0205085C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u16 FLDMMDL_GetObjCode(void *p);
extern int FLDMMDL_CallDrawGetProc(void *p, unsigned int v);
extern int FLDMMDL_GetBlActCont(int a0);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern void BILLBOARD_ACT_SetEntryCursor(void *p, int idx, u32 v);

void FLDMMDL_DRAW_ResetBlactAnime(u32 a)
{
    u16 v;
    u16 z;
    if (FLDMMDL_GetObjCode((void *)a) == 0x7B) {
        z = 0;
        v = FLDMMDL_CallDrawGetProc((void *)a, 0);
        if (v != 0xFFFF) {
            BILLBOARD_ACT_SetEntryCursor((void *)FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(a)), v, z);
        }
    }
}
