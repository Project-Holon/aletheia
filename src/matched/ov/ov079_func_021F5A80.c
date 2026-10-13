/*
 * function: ENCEFF_BuildBlockFlip
 * address: 0x021F5A80
 * packet: pkt_ov079_021F5A80
 * region: ov079
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBlockFlipCameraPos 0x021F5B70 data a4
 *   FIELDMAP_GetEncEff 0x02189A08 thumb ov021
 *   ENCEFF_LoadOverlays4B4D 0x021CF580 thumb ov021
 *   ENCEFF_StartScreenTexEffectFlash 0x021F5260 thumb ov075
 *   ENCEFF_StartBlockFlip 0x021F5ABC thumb ov079
 *   ENCEFF_DrawCellGrid 0x021F582C thumb ov077
 */
typedef struct { int x,y,z; } Vec;
extern const Vec gBlockFlipCameraPos;
extern int FIELDMAP_GetEncEff(unsigned char *p);
extern void ENCEFF_LoadOverlays4B4D(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Vec;
extern void *ENCEFF_StartScreenTexEffectFlash(void *a, struct Vec *src, u32 b, u32 c);
extern void ENCEFF_StartBlockFlip(void *a);
extern void ENCEFF_DrawCellGrid(u8 *p);
void *ENCEFF_BuildBlockFlip(void *p, int b) {
    Vec v = gBlockFlipCameraPos;
    ENCEFF_LoadOverlays4B4D((void *)FIELDMAP_GetEncEff((unsigned char *)b));
    return ENCEFF_StartScreenTexEffectFlash(p, (struct Vec *)(&v), (u32)((void (*)(void))ENCEFF_StartBlockFlip), (u32)ENCEFF_DrawCellGrid);
}
