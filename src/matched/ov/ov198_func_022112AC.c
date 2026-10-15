/*
 * function: B_PLIST_MAIN_ConfirmSwap
 * address: 0x022112AC
 * packet: pkt_ov198_022112AC
 * region: ov198
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   B_PLIST_MAIN_CheckCancel 0x02211958 thumb ov198
 *   B_PLIST_MAIN_HandleCursorInput 0x02210A4C thumb ov198
 *   B_PLIST_MAIN_PlaySe 0x02211970 thumb ov198
 *   B_PLIST_ANM_StartPaletteAnim 0x0220B760 thumb ov198
 *   B_PLIST_MAIN_PrintRowMessage 0x02211190 thumb ov198
 *   B_PLIST_MAIN_PushSelectionPair 0x022110F8 thumb ov198
 *   B_PLIST_MAIN_SetSelectionEntry 0x022110E0 thumb ov198
 *   B_PLIST_DRAW_ClearAndPrintStream 0x0220E13C thumb ov198
 */
#include "../include/Obj02536.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern unsigned B_PLIST_MAIN_CheckCancel(u8 **);
extern int B_PLIST_MAIN_HandleCursorInput(u8 *);
extern void B_PLIST_MAIN_PlaySe(u8 **, unsigned);
extern void B_PLIST_ANM_StartPaletteAnim(u8 *, unsigned);
extern int B_PLIST_MAIN_PrintRowMessage(u8 *);
extern void B_PLIST_MAIN_PushSelectionPair(u8 *p, int a, int b);
extern void B_PLIST_MAIN_SetSelectionEntry(u8 **, unsigned, unsigned);
extern void B_PLIST_DRAW_ClearAndPrintStream(u8 *);
int B_PLIST_MAIN_ConfirmSwap(u8 *p)
{
    if (PALANM_GetFadeRequestBits(((struct Obj02536 *)p)->f1D8) != 0) return 8;
    if (B_PLIST_MAIN_CheckCancel((u8 **)p) == 1) return 0x1f;
    if (B_PLIST_MAIN_HandleCursorInput(p) == 1) {
        if ((*(u8 **)p)[0x20] == 6) {
            B_PLIST_MAIN_PlaySe((u8 **)p, 0x552);
            B_PLIST_ANM_StartPaletteAnim(p, 6);
            (*(u8 **)p)[0x20] = p[0x2498];
            ((struct Obj02536 *)p)->f217C = 0xc;
            return 0x1d;
        }
        if ((*(u8 **)p)[0x20] == p[0x2498]) return 0xc;
        if (B_PLIST_MAIN_PrintRowMessage(p) == 1) {
            B_PLIST_MAIN_PushSelectionPair(p, (*(u8 **)p)[0x20], p[0x2498]);
            B_PLIST_MAIN_SetSelectionEntry((u8 **)p, (*(u8 **)p)[0x20], p[0x2498]);
            p[0x2499] = (*(u8 **)p)[0x20];
            p[0x249a] = p[0x2498];
            p[0x1e98] = 0;
            return 9;
        }
        B_PLIST_DRAW_ClearAndPrintStream(p);
        ((struct Obj02536 *)p)->f217C = 0xa;
        return 0x17;
    }
    return 8;
}
