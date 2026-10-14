/*
 * function: CG_HELP_FreeWindows
 * address: 0x021D485C
 * packet: pkt_ov124_021D485C
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 */
#include "../include/Obj00991.h"
typedef unsigned char  u8;
struct Descriptor;
struct PrintSys;
struct Rec;
struct TaskMenuState;
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern unsigned int APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void func_0201DD68(void *);
void CG_HELP_FreeWindows(char *p)
{
    if (((struct Obj00991 *)p)->f3C) APP_TASKMENU_WIN_Delete(((struct Obj00991 *)p)->f3C);
    if (((struct Obj00991 *)p)->f38) APP_TASKMENU_WIN_Delete(((struct Obj00991 *)p)->f38);
    APP_TASKMENU_WIN_Delete(((struct Obj00991 *)p)->f40);
    APP_TASKMENU_RES_Delete(((struct Obj00991 *)p)->f34);
    PRINTSYS_QUE_Delete(((struct Obj00991 *)p)->f30);
    BMP_WIN_Delete(((struct Obj00991 *)p)->f20);
    BMP_WIN_Delete(((struct Obj00991 *)p)->f24);
    MSGDATA_Delete(((struct Obj00991 *)p)->f2C);
    func_0201DD68((void *)GF_FONT_Delete(((struct Obj00991 *)p)->f28));
}
