/*
 * function: OPTION_MENU_Exit
 * address:  0x021B9768
 * packet:   pkt_ov068_021B9768
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OPTION_MENU_ExitMessageBox  0x021BADFC  thumb
 *   OPTION_MENU_ExitTextBox  0x021BA254  thumb
 *   OPTION_MENU_ExitInput  0x021BA030  thumb
 *   OPTION_MENU_ExitList  0x021BA7B4  thumb
 *   OPTION_MENU_ExitButtons  0x021BA410  thumb
 *   OPTION_MENU_ExitRunner  0x021BB114  thumb
 *   OPTION_MENU_ExitSettings  0x021BAF9C  thumb
 *   OPTION_MENU_ExitScreen  0x021B98E0  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   ov067_id       0x00000043  data
 */
#include "../include/Obj05149.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct PrintSys;
struct Rec;
struct S02031140;
struct Proc;
struct TaskMenuState;
extern void OPTION_MENU_ExitMessageBox(u8 *p);
extern void OPTION_MENU_ExitTextBox(u8 *p);
extern void OPTION_MENU_ExitInput(void *p);
extern void OPTION_MENU_ExitList(void *p);
extern void OPTION_MENU_ExitButtons(u8 *p);
extern void OPTION_MENU_ExitRunner(void *p);
extern void OPTION_MENU_ExitSettings(void *p);
extern void OPTION_MENU_ExitScreen(u8 *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void func_02034A5C(int a);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern u8 ov067_id[];

int OPTION_MENU_Exit(void *a, u32 b, u32 c, u8 *w)
{
    OPTION_MENU_ExitMessageBox(w + 0x1d8);
    OPTION_MENU_ExitTextBox(w + 0x1a0);
    OPTION_MENU_ExitInput(w + 0xe4);
    OPTION_MENU_ExitList(w + 0x148);
    OPTION_MENU_ExitButtons(w + 0x104);
    OPTION_MENU_ExitRunner(w + 0xd4);
    OPTION_MENU_ExitSettings(w + 0x248);
    TCBL_Destroy(((struct Obj05149 *)w)->f268);
    MSGDATA_Delete(((struct Obj05149 *)w)->f25C);
    APP_TASKMENU_RES_Delete(((struct Obj05149 *)w)->f264);
    APP_TASKMENU_RES_Delete(((struct Obj05149 *)w)->f260);
    PRINTSYS_QUE_Delete(((struct Obj05149 *)w)->f258);
    GF_FONT_Delete(((struct Obj05149 *)w)->f254);
    OPTION_MENU_ExitScreen(w);
    func_020315D4(a);
    GFL_HEAP_DeleteChecked(0x1c);
    func_02034A5C((int)ov067_id);
    return 1;
}
