/*
 * function: ENCEFF_UpdateCellGrid
 * address: 0x021F57F8
 * packet: pkt_ov077_021F57F8
 * region: ov077
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05: EXACT now that ov021 ENCEFF_GetEffect is filed; no source change.
 * symbols:
 *   ENCEFF_GetEffect 0x021CF51C thumb ov021
 *   ENCEFF_GetWork 0x021CF560 thumb ov021
 *   G3X_SetClearColor 0x0207DD24 arm
 *   ENCEFF_DrawScreenTexEffect 0x021F52D8 thumb ov075
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 ENCEFF_GetEffect(u32 *p);
extern u32 ENCEFF_GetWork(u32 *);
extern void G3X_SetClearColor(u16,int,int,int,int);
extern void ENCEFF_DrawScreenTexEffect(u32 *);
void ENCEFF_UpdateCellGrid(u32 *p) {
    u32 h = ENCEFF_GetEffect(p);
    u32 w = ENCEFF_GetWork(p);
    G3X_SetClearColor(*(u32 *)(w+0x3078),31,0x7FFF,0,0);
    ENCEFF_DrawScreenTexEffect((u32 *)h);
}
