/*
 * function: FLDMMDL_DRAW_DrawDirAnimeB
 * address:  0x0219F25C
 * packet:   pkt_ov021_0219F25C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf callees now filed; formerly MATCH. Leaf sources verified from a scratch
 * file (region arm9, --arm, dsi/1.1p1 -O4,p; typedefs u8/u16/u32):
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
 *   FLDMMDL_DRAW_UpdateDirAnime  0x0219FEB0  thumb  ov021
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
extern void FLDMMDL_ACMD_GetDrawPos(u8 *p, s32 *out);
extern void FLDMMDL_DRAW_AddHeightOffset(u32 a, u32 *p);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern void BILLBOARD_SetElemPos(u8 *a0, int i, struct Trip *src);
extern void FLDMMDL_DRAW_UpdateDirAnime(u8 *s, u32 a, u32 r, u16 id);

void FLDMMDL_DRAW_DrawDirAnimeB(u32 a)
{
    s32 buf[3];
    u16 *q;
    u32 r;
    q = FLDMMDL_GetDrawProcWork((void *)a);
    if (*q != 0xFFFF) {
        r = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_GetBlActCont(a));
        FLDMMDL_DRAW_UpdateDirAnime((u8 *)(q + 2), a, r, *q);
    FLDMMDL_ACMD_GetDrawPos((u8 *)a, buf);
    FLDMMDL_DRAW_AddHeightOffset(a, (u32 *)buf);
    r = BILLBOARD_ACT_GetBoard((u32 *)r);
    BILLBOARD_SetElemPos((u8 *)r, *q, (struct Trip *)buf);
    }
}
