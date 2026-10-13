/*
 * function: FLDMMDL_DRAW_DrawThreePattern
 * address:  0x0219FD94
 * packet:   pkt_ov021_0219FD94
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
 *   BILLBOARD_SetElemPos  0x0204F638  arm
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   FLDMMDL_GetDrawStatus  0x0216D678  thumb  ov010
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 *   FLDMMDL_GetBlActCont  0x0216D910  thumb  ov010
 *   FLDMMDL_ACMD_GetDrawPos  0x02197CCC  thumb  ov021
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   FLDMMDL_DRAW_AddHeightOffset  0x0219FFBC  thumb  ov021
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
extern u16 FLDMMDL_GetDrawStatus(void *p);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);

void FLDMMDL_DRAW_DrawThreePattern(u32 a)
{
    u16 *p;
    u32 buf[3];
    u32 h;
    u32 v;
    u32 flag;

    flag = 0;
    p = FLDMMDL_GetDrawProcWork((void *)a);
    if (*p != 0xFFFF) {
        h = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(a));
        v = FLDMMDL_GetDrawStatus((void *)a);
        if (v != ((u8 *)p)[5]) {
            switch (v) {
            case 10: flag = 1; break;
            case 11: flag = 2; break;
            case 12: flag = 3; break;
            }
            ((u8 *)p)[5] = v;
            BILLBOARD_ACT_SetEntryList((void *)h, *p, flag);
            flag = 1;
        }
        FLDMMDL_DRAW_UpdateBlactFlags(a, h, *p, flag, 0);
        FLDMMDL_ACMD_GetDrawPos((u8 *)a, (s32 *)buf);
        FLDMMDL_DRAW_AddHeightOffset(a, buf);
        BILLBOARD_SetElemPos((u8 *)BILLBOARD_ACT_GetBoard((u32 *)h), *p, (struct Trip *)buf);
    }
}
