/*
 * function: PSEL_GRAPHIC_InitSelect
 * address: 0x021BBA78
 * packet: pkt_ov223_021BBA78
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   PSEL_SetupListAnime 0x021B9854 thumb ov223
 *   PSEL_InitBgLayers 0x021BAB78 thumb ov223
 *   PSEL_DeleteBgLayers 0x021BAC0C thumb ov223
 *   PSEL_ClearWin2 0x021BB2A4 thumb ov223
 *   func_0207D63C 0x0207D63C arm
 */
#include "../include/Obj06729.h"
extern void BG_SYS_LoadPlttEntry(unsigned, unsigned);
typedef unsigned short u16;
typedef unsigned char  u8;
extern void PSEL_SetupListAnime(u8 *p);
extern void PSEL_InitBgLayers(u16 *p);
extern void PSEL_DeleteBgLayers(unsigned short *);
extern void PSEL_ClearWin2(char *p);
extern void func_0207D63C(void *, unsigned, unsigned, unsigned, unsigned);
int PSEL_GRAPHIC_InitSelect(char *p)
{
    BG_SYS_LoadPlttEntry(0, 0x2F3B);
    BG_SYS_LoadPlttEntry(4, 0x2F3B);
    PSEL_SetupListAnime((u8 *)p);
    PSEL_InitBgLayers((u16 *)p);
    PSEL_DeleteBgLayers((unsigned short *)p);
    PSEL_ClearWin2(p);
    ((struct Obj06729 *)p)->f24 |= 2;
    ((struct Obj06729 *)p)->f268 = 0;
    func_0207D63C((void *)0x04000050, 5, 63,
                 ((struct Obj06729 *)p)->f268, 16 - ((struct Obj06729 *)p)->f268);
    ((struct Obj06729 *)p)->f10 = 0;
    return 3;
}
