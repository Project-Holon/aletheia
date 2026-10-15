/*
 * unit: yes
 * function: BOX2_SEQ_StateFadeBox, BOX2_SEQ_StateCloseItemE
 * address: 0x021E8E24
 * packet: pkt_ov170_021E8E24
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   func_020056BC 0x020056BC thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   BOX2_MAIN_LoadBoxPalette 0x021DED58 thumb ov170
 *   func_02007838 0x02007838 thumb
 *   BOX2_UI_DrawSlot 0x021EDAB0 thumb ov170
 *   BOX2_SEQ_GotoBox2Ui 0x021E95CC thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23940.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
struct PalAnmSlot;
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern u32 func_020056BC(void);
extern int PALANM_RequestFade(void *, u16, u16, s16, u8, u8, u16, void *);
extern void BOX2_MAIN_LoadBoxPalette(char *, int);
extern void func_02007838(void *save, u32 box, u8 v);
extern void BOX2_UI_DrawSlot(char *, int);
extern int BOX2_SEQ_GotoBox2Ui(unsigned char *, unsigned char);
#define W (*(char **)(p + 0x2c))
#define S (*(int *)(W + 0xA194))
int BOX2_SEQ_StateFadeBox(char *p)
{
    switch (S) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        PALANM_CopyHwPaletteToSlot(*(void **)(W + 0x6c), 0, 0, 0x200);
        PALANM_RequestFade(*(void **)(W + 0x6c), 1, 0xc000, 0, 0, 16, 0x7fff, (void *)func_020056BC());
        ((struct Obj00000 *)p)->f28 = 0x66;
        S++;
        return 3;
    case 1:
        BOX2_MAIN_LoadBoxPalette(p, *(u8 *)(W + 0xA17B));
        func_02007838(((struct Obj23940 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f4, ((struct Obj00000 *)p)->f14, *(u8 *)(W + 0xA17B));
        BOX2_UI_DrawSlot(p, ((struct Obj00000 *)p)->f14);
        S++;
        break;
    case 2:
        PALANM_RequestFade(*(void **)(W + 0x6c), 1, 0xc000, 0, 16, 0, 0x7fff, (void *)func_020056BC());
        ((struct Obj00000 *)p)->f28 = 0x66;
        S++;
        return 3;
    case 3:
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        S = 0;
        return 0x65;
    }
    return 0x66;
}
int BOX2_SEQ_StateCloseItemE(unsigned char *p)
{
    return BOX2_SEQ_GotoBox2Ui(p, 2);
}
