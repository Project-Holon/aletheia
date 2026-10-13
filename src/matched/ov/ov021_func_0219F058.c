/*
 * function: FLDMMDL_DRAW_GetBlactAnime
 * address:  0x0219F058
 * packet:   pkt_ov021_0219F058
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf callees now filed; formerly MATCH. Leaf sources verified from a scratch
 * file (region arm9, --arm, dsi/1.1p1 -O4,p; typedefs u8/u16/u32):
 *   BILLBOARD_ACT_GetEntryList:
 *   u16 BILLBOARD_ACT_GetEntryList(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0xe); }
 *   BILLBOARD_ACT_GetEntryCursor:
 *   u16 BILLBOARD_ACT_GetEntryCursor(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x10); }
 *
 * symbols:
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 *   FLDMMDL_GetBlActCont  0x0216D910  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   BILLBOARD_ACT_GetEntryList  0x02050848  arm
 *   BILLBOARD_ACT_GetEntryCursor  0x02050880  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u8 *FLDMMDL_GetObjCodeParam(u32);
extern void *FLDMMDL_GetDrawProcWork(void *p);
extern int FLDMMDL_GetBlActCont(int a0);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern u16 BILLBOARD_ACT_GetEntryList(u8 *p, int i);
extern u16 BILLBOARD_ACT_GetEntryCursor(u8 *p, int i);

void FLDMMDL_DRAW_GetBlactAnime(u32 a, u16 *o1, u16 *o2)
{
    u16 *q;
    u32 r;
    if (FLDMMDL_GetObjCodeParam(a)[2] == 1) {
        q = FLDMMDL_GetDrawProcWork((void *)a);
        if (*q != 0xFFFF) {
            r = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(a));
            *o1 = BILLBOARD_ACT_GetEntryList((u8 *)r, *q);
            *o2 = BILLBOARD_ACT_GetEntryCursor((u8 *)r, *q);
        } else {
            *o1 = 0;
            *o2 = 0;
        }
    } else {
        *o1 = 0;
        *o2 = 0;
    }
}
