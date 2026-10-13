/*
 * function: ENCEFF_BuildGridColumnFlip
 * address: 0x021F5A80
 * packet: pkt_ov080_021F5A80
 * region: ov080
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gEncEffGridColumnFlipCameraPos 0x021F5B64 data a4
 *   FIELDMAP_GetEncEff 0x02189A08 thumb ov021
 *   ENCEFF_LoadOverlays4B4D 0x021CF580 thumb ov021
 *   ENCEFF_StartScreenTexEffectFlash 0x021F5260 thumb ov075
 *   ENCEFF_StartGridColumnFlip 0x021F5ABC thumb ov080
 *   ENCEFF_DrawCellGrid 0x021F582C thumb ov077
 */
typedef struct { int x,y,z; } Vec;
extern const Vec gEncEffGridColumnFlipCameraPos;
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern void ENCEFF_LoadOverlays4B4D(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Vec;
extern void *ENCEFF_StartScreenTexEffectFlash(void *a, struct Vec *src, u32 b, u32 c);
extern void ENCEFF_StartGridColumnFlip(void *a);
extern void ENCEFF_DrawCellGrid(u8 *p);
void *ENCEFF_BuildGridColumnFlip(void *p, int b) {
    Vec v = gEncEffGridColumnFlipCameraPos;
    ENCEFF_LoadOverlays4B4D((void *)FIELDMAP_GetEncEff((unsigned char *)b));
    return ENCEFF_StartScreenTexEffectFlash(p, (struct Vec *)(&v), (u32)((void (*)(void))ENCEFF_StartGridColumnFlip), (u32)ENCEFF_DrawCellGrid);
}
