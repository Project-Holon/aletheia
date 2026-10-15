/*
 * function: MANUAL_CATEGORY_CreateOption
 * address: 0x021BBA74
 * packet: pkt_ov225_021BBA74
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BBC44 retains original visible r0 context although its fixed tail ignores it.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   gManualCategoryOptionAllocFile 0x021BC06C data a1
 *   MANUAL_CATEGORY_LoadOptionAssets 0x021BBBF4 thumb ov225
 *   MANUAL_CATEGORY_SetOptionBgMode 0x021BBC44 thumb ov225
 *   MANUAL_CATEGORY_CreateOptionSlots 0x021BBC54 thumb ov225
 *   MANUAL_CATEGORY_OptionTaskNoop 0x021BBBF0 thumb ov225
 *   func_020056A0 0x020056A0 thumb
 *   func_021BA068 0x021BA068 thumb ov225
 *   func_021BA0F0 0x021BA0F0 thumb ov225
 *   MANUAL_CATEGORY_DrawOption 0x021BBD74 thumb ov225
 */
#include "../include/Obj02563.h"
#include "../include/Obj26303.h"
#include "../include/Obj26304.h"
#include "../include/Obj26305.h"
#include "../include/Obj26306.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const char gManualCategoryOptionAllocFile[];
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void MANUAL_CATEGORY_LoadOptionAssets(char *);
extern void MANUAL_CATEGORY_SetOptionBgMode(char *);
extern void MANUAL_CATEGORY_CreateOptionSlots(u8 *);
extern void MANUAL_CATEGORY_OptionTaskNoop(void *);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern void func_021BA068(char *, unsigned);
extern void func_021BA0F0(char *, unsigned, unsigned);
extern void MANUAL_CATEGORY_DrawOption(char *);
char *MANUAL_CATEGORY_CreateOption(char *p, char *data)
{
    char *q;
    q = func_02030734(((struct Obj26303 *)data)->f4, 64, 1, gManualCategoryOptionAllocFile, 156);
    *(char * *)&((struct Obj02563 *)q)->f0 = p;
    ((struct Obj26304 *)p)->f28 = 0;
    *(char * *)&((struct Obj02563 *)q)->f4 = data;
    q[8] = 0;
    ((struct Obj02563 *)q)->fC = 0;
    MANUAL_CATEGORY_LoadOptionAssets(q);
    MANUAL_CATEGORY_SetOptionBgMode(q);
    MANUAL_CATEGORY_CreateOptionSlots((u8 *)q);
    ((struct Obj02563 *)q)->f34 = func_020056A0((unsigned)MANUAL_CATEGORY_OptionTaskNoop, (unsigned)q, 1);
    ((struct Obj02563 *)q)->f38 = 0;
    q[0x3c] = -1;
    func_021BA068(*(char * *)&((struct Obj26305 *)(*(char * *)&((struct Obj02563 *)q)->f4))->f34, 3);
    func_021BA0F0(*(char * *)&((struct Obj26306 *)(*(char * *)&((struct Obj02563 *)q)->f4))->f34, *(u8 *)*(char * *)&((struct Obj02563 *)q)->f0, ((struct Obj02563 *)q)->f8);
    MANUAL_CATEGORY_DrawOption(q);
    return q;
}
