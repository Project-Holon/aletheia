/*
 * function: FLDMMDL_DRAW_SetBlactAnime
 * address:  0x0219F0B0
 * packet:   pkt_ov021_0219F0B0
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
 *
 * symbols:
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 *   FLDMMDL_GetBlActCont  0x0216D910  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   BILLBOARD_ACT_SetEntryCursor  0x0205085C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u8 *FLDMMDL_GetObjCodeParam(u32);
extern void *FLDMMDL_GetDrawProcWork(void *p);
extern int FLDMMDL_GetBlActCont(int a0);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);
extern void BILLBOARD_ACT_SetEntryCursor(void *p, int idx, u32 v);

void FLDMMDL_DRAW_SetBlactAnime(u32 a, u32 b, u32 c)
{
    u16 *q;
    u32 r;
    if (FLDMMDL_GetObjCodeParam(a)[2] == 1) {
        q = FLDMMDL_GetDrawProcWork((void *)a);
        if (*q != 0xFFFF) {
            r = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(a));
            BILLBOARD_ACT_SetEntryList((void *)r, *q, b);
            BILLBOARD_ACT_SetEntryCursor((void *)r, *q, c);
        }
    }
}
