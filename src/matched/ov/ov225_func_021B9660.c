/*
 * function: MANUAL_GRAPHIC_Exit
 * address: 0x021B9660
 * packet: pkt_ov225_021B9660
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BB308 0x021BB308 thumb ov225
 *   MANUAL_CATEGORY_DeleteList 0x021BB7F4 thumb ov225
 *   MANUAL_CATEGORY_DeleteDetailList 0x021BBA14 thumb ov225
 *   MANUAL_CATEGORY_DeleteOption 0x021BBAE8 thumb ov225
 *   func_021B9DEC 0x021B9DEC thumb ov225
 *   func_02030EAC 0x02030EAC arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj04649.h"
struct Node;
struct S020315D4;
extern void func_021BB308(char *p);
extern void MANUAL_CATEGORY_DeleteList(char *p);
extern void MANUAL_CATEGORY_DeleteDetailList(char *p);
extern void MANUAL_CATEGORY_DeleteOption(char *p);
extern void func_021B9DEC(char *p);
extern void func_02030EAC(struct Node *n);
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int MANUAL_GRAPHIC_Exit(void *proc, void *a, void *b, char *work)
{
    switch (((struct Obj04649 *)work)->f10) {
    case 0: func_021BB308(((struct Obj04649 *)work)->f1C); break;
    case 1: MANUAL_CATEGORY_DeleteList(((struct Obj04649 *)work)->f2C); break;
    case 2: MANUAL_CATEGORY_DeleteDetailList(((struct Obj04649 *)work)->f44); break;
    case 3: MANUAL_CATEGORY_DeleteOption(((struct Obj04649 *)work)->f74); break;
    }
    func_02030EAC(((struct Obj04649 *)work)->fC);
    func_021B9DEC(((struct Obj04649 *)work)->f8);
    func_020315D4(proc);
    GFL_HEAP_DeleteChecked(0x90);
    return 1;
}
